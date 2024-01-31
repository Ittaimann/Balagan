#include "XmlParser.h"
#include <Array.h>
#include <String.h>
#include <iostream>

namespace BAL
{

XmlParser::XmlParser() { m_root = new treeNode(); }
XmlParser::~XmlParser() { clearTree(m_root); }
void XmlParser::clearTree(treeNode* i_root)
{
	for (uint i = 0; i < i_root->m_childrenNodes.size(); i++)
	{
		clearTree(i_root->m_childrenNodes[i]);
	}
	delete i_root;
}

void XmlParser::parseData(const Array<char>& i_data)
{
	runningState state;

	state = skipVersion(i_data);
	state.m_index += 1; // TODO: remove this
	if (state.m_status != SUCCESS)
	{
		// TODO: assert here
		return;
	}

	m_root = parseNodes(m_root, i_data, state);
	if (state.m_status != SUCCESS)
	{
		// TODO: assert here
		return;
	}
}

treeNode* XmlParser::parseNodes(treeNode* i_currentNode, const Array<char>& i_data, runningState& io_state)
{
	// loop through the text until you find something interesting
	String value("");
	while (true)
	{
		// Closing
		if (i_data[io_state.m_index] == '<' && i_data[io_state.m_index + 1] == '/')
		{
			uint lookAhead = io_state.m_index + 2;
			String closingName("");
			while (i_data[lookAhead] != '>')
			{
				closingName += i_data[lookAhead];
				lookAhead += 1;
			}

			io_state.m_index = lookAhead;
			i_currentNode->m_value = value;

			if (i_currentNode->m_name == closingName)
			{
				return i_currentNode;
			}
			else
			{
				io_state.m_status = ERROR_MALFORMED_CLOSING_BRACKET;
				return nullptr;
			}
		}

		// opening
		if (i_data[io_state.m_index] == '<' && i_data[io_state.m_index + 1] != '/')
		{

			if (i_currentNode != nullptr && i_currentNode->m_name == "")
			{
				value = "";
				uint lookAhead = io_state.m_index + 1;
				while (i_data[lookAhead] != '>')
				{
					i_currentNode->m_name += i_data[lookAhead];
					lookAhead += 1;
				}
				io_state.m_index = lookAhead + 1;
			}
			else
			{
				// new child node
				treeNode* child = new treeNode();
				child = parseNodes(child, i_data, io_state);
				i_currentNode->m_childrenNodes.push_back(child);
			}
		}
		value += i_data[io_state.m_index];
		io_state.m_index += 1;
	}
	return i_currentNode;
}

runningState XmlParser::skipVersion(const Array<char>& i_data)
{
	runningState start{0, SUCCESS};
	while (true)
	{
		if (i_data[start.m_index] == '?' && i_data[start.m_index + 1] == '>')
		{
			start.m_index += 2;
			return start;
		}
		start.m_index += 1;
		if (start.m_index == i_data.size())
		{
			start.m_status = ERROR_NO_VERSION_TEXT;
			return start;
		}
	}
}

} // namespace BAL
