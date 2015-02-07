#ifndef TREE_H
#define TREE_H

#include "TNode.h"
#include "TreeException.h"

class Tree
{
	typedef DLList<TNode*>::Iterator ListIterator;

public:
	Tree();
	Tree(const Tree &);
	Tree& operator=(const Tree &);
	~Tree();

public:
	void setRoot();
	void insert(const std::string &, File *);
	void remove(const std::string &);
	TNode* getNode(const std::string &);

public:
	void DFS() const;
	void DFSR(TNode *) const;
	void serialize(std::ostream &) const;
	void deserialize(std::istream &, int);

private:
	TNode* root;
	void getNodeAt(const std::string &, TNode *&, TNode *&);
	void serializeRecursive(std::ostream &, TNode *) const;
	void deserializeRecursive(std::istream &, TNode *&);

private:
	void deleteTree(TNode *&);
	void copyTree(const TNode *, TNode *&);
};


#endif // TREE_H