#pragma once
#include <Array.h>
#include <Pair.h>
#include <String.h>

// TODO:
// comment skipping
// better handling of the version
// includes?
// build out a better api
namespace BAL
{

using attributeData = Pair<String, String>;

struct treeNode
{
	treeNode()
	{
		m_name = "";
		m_value = "";
	}

	String m_name;
	String m_value; // may be empty if there is children nodes
	Array<treeNode*> m_childrenNodes;
	Array<attributeData> m_attributeNodes;
};

enum ReturnCodes : uint32
{
	ERROR_NO_VERSION_TEXT,
	ERROR_MALFORMED_CLOSING_BRACKET,
	SUCCESS
};

struct runningState
{
	uint m_index;
	ReturnCodes m_status;
};

class XmlParser
{
public:
	XmlParser();
	virtual ~XmlParser();

	void clearTree(treeNode* i_root);
	void parseData(const Array<char>& i_data);
	attributeData handleAttribute(const Array<char>& i_data, uint& io_lookAhead);
	const treeNode* getRootNode() const { return m_root; };
	Array<treeNode*> getChildrenNodes() const { return m_root->m_childrenNodes; };

private:
	treeNode* parseNodes(treeNode* i_currentNode, const Array<char>& i_data, runningState& io_state);
	runningState skipVersion(const Array<char>& i_data);

	treeNode* m_root;
};

} // namespace BAL
