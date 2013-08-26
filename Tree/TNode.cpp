#include <iostream>
#include "TNode.h"

using namespace std;

TNode::TNode()
{
	key = -1;
	left = NULL;
	right = NULL;
	parent = NULL;
}

TNode::TNode(int k)
{ 
	key = k; 
	left = NULL; 
	right = NULL;
	parent = NULL;
}

void TNode::setKey(int k)
{ 
	key = k; 
}

void TNode::setLeft(TNode* l)
{
	left = l;
	l->setParent(this);	
}
		
void TNode::setRight(TNode* r)
{ 
	right = r;
	r->setParent(this);
}

void TNode::setParent(TNode* p)
{
	parent = p;
}

int TNode::nodeValue()
{ 
	return key; 
}

TNode* TNode::nodeLeft()
{ 
	return left; 
}

TNode* TNode::nodeRight()
{ 
	return right; 
}

TNode* TNode::nodeParent()
{
	return parent;
}
