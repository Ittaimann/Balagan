#include "XmlParser.h"
#include <Array.h>
#include <String.h>

namespace BAL
{

XmlParser::XmlParser()
{
	m_root->m_name = "";
	m_root->m_childrenNodes.clear();
	m_root->m_value = "";
}
XmlParser::~XmlParser() {}

// Probably want to do this recursively lmao
// new node < search for > record name
// everything inside that until <!nodename> is either a
// value,
// 	if no < its not a new node so just record that value
// child node
// 	found another < so do the tree node check again
// or attribute node
//	attributes are weird syntactically
//

void XmlParser::parseData(const Array<char>& i_data)
{
	// ok how doest his work, search for the < stuff >
	// record the input name, if there is more < between it its a new node
	// record the name of the tree and search for the closer?

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

treeNode addNode(); // new node, so do the search for children or value
					// continue doing it until we have a </ of our name?
String addValue();	// as long as no </ we append the string

treeNode* XmlParser::parseNodes(treeNode* i_currentNode, const Array<char>& i_data, runningState i_state)
{
	// loop through the text until you find something interesting
	bool foundElement = false;
	String value = "";
	while (!foundElement)
	{
		// Closing
		if (i_data[i_state.m_index] == '<' && i_data[i_state.m_index + 1] == '/')
		{
			uint lookAhead = i_state.m_index + 2;
			String closingName = "";
			while (i_data[lookAhead] != '>')
			{
				closingName += i_data[lookAhead];
				lookAhead += 1;
			}

			i_state.m_index = lookAhead;

			if (i_currentNode->m_name == closingName)
			{
				return i_currentNode;
			}
			else
			{
				i_state.m_status = ERROR_MALFORMED_CLOSING_BRACKET;
				return nullptr;
			}
		}
		// opening
		if (i_data[i_state.m_index] == '<' && i_data[i_state.m_index + 1] != '/')
		{
			if (i_currentNode != nullptr && i_currentNode->m_name == "")
			{
				value = "";
				uint lookAhead = i_state.m_index + 1;
				while (i_data[lookAhead] != '>')
				{
					i_currentNode->m_name += i_data[lookAhead];
					lookAhead += 1;
				}
				i_state.m_index = lookAhead;
			}
			else
			{
				// new child node
				treeNode* child = new treeNode();
				i_currentNode->m_childrenNodes.push_back(child);
				child = parseNodes(child, i_data, i_state);
			}
		}
		value += i_data[i_state.m_index];
		i_state.m_index += 1;
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
