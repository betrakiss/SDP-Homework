#ifndef TREE_H
#define TREE_H

#include "TNode.h"
#include "TreeException.h"
#include <iostream>
#include <string>

class Tree
{
public:
	Tree();
	~Tree();

	typedef std::pair<std::string, std::string> string_pair;
	typedef DLList<TNode*>::Iterator ListIterator;
	typedef void(Tree::*attributeFunction)(const Attribute &, const ListIterator &, const char *);

public:
	void insertTag(const Tag &, std::string &);
	void removeTag(std::string &, bool = false);
	void changeTag(const Tag &, std::string &);

	void send(std::ostream &, bool) const;

	void addAttribute(const Attribute &, std::string &);
	void changeAttribute(std::string &, const Attribute &, std::string &);
	void removeAttribute(const Attribute &, std::string &);

private:
	Tree(const Tree &);
	Tree& operator=(const Tree &);

private:
	void manipulateAttribute(const Attribute &, std::string &, attributeFunction, const char* = NULL);
	void addAttributeInIterator(const Attribute &, const ListIterator &, const char*);
	void changeAttributeInIterator(const Attribute &, const ListIterator &, const char*);
	void removeAttributeInIterator(const Attribute &, const ListIterator &, const char*);

	void getLastNode(const char *, TNode *&, DLList<TNode*> &);
	string_pair getParentPath(std::string &);

private:
	TNode* root;
	void deleteTree(TNode *&);
};

#endif // TREE_H