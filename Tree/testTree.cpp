#include <iostream>
#include "TNode.h"

using namespace std;

void InOrderWalk(TNode* root)
{
	if(root != NULL)
	{
		InOrderWalk(root->nodeLeft());
		cout << root->nodeValue() << endl;
		InOrderWalk(root->nodeRight());
	}
}

int main()
{
	TNode* root = new TNode(3);
	root->setLeft(new TNode(5));
	root->setRight(new TNode(7));
	TNode* x = root->nodeLeft();
	x->setLeft(new TNode(11));
	x->setRight(new TNode(13));

	InOrderWalk(root);
}


