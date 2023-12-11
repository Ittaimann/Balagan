#pragma once
#include <Array.h>
#include <Pair.h>
#include <String.h>
// Ideas on how to parse xml
// parse the file into a tree
// tree has leafs and branches
// branch:
//		new child node
// leaf:
//		array of string pairs
//		array of attributes

namespace BAL
{

using dataNode = Pair<String, String>;

struct treeNode
{
	Array<treeNode*> m_childrenNodes;
	Array<dataNode> m_valueNodes;
	Array<dataNode> m_attributeNodes;
};

class XmlParser
{
public:
	XmlParser();
	virtual ~XmlParser();

	treeNode* getRootNode();
	Array<treeNode*> getChildrenNodes() const { return m_root.m_childrenNodes; };
	Array<dataNode> getValueNodes() const { return m_root.m_valueNodes; };
	Array<dataNode> getAttributeNodes() { return m_root.m_attributeNodes; };

private:
	treeNode m_root;
};

} // namespace BAL
