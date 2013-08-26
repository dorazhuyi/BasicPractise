#ifndef __TNODE_H_
#define __TNODE_H_

class TNode
{
	public:
		TNode();	
		TNode(int);
		void setKey(int);
		void setLeft(TNode*);
		void setRight(TNode*);
		void setParent(TNode*);
		int nodeValue();
		TNode* nodeLeft();
		TNode* nodeRight();
		TNode* nodeParent();
	private:
		int key;
		TNode* left;
		TNode* right;
		TNode* parent;
};

#endif
