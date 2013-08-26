#include <iostream>

using namespace std;

class BSTnode
{
	public:
		BSTnode()
		{ 
			key = -1;
			left = NULL;
			right = NULL;
			parent = NULL;
		}
		BSTnode(int k)
		{ 
			key = k; 
			left = NULL; 
			right = NULL;
			parent = NULL;
		}
		void setKey(int k)
		{ 
			key = k; 
		}
		void setLeft(BSTnode* l)
		{ 
			left = l; 
		} 
		void setRight(BSTnode* r)
		{ 
			right = r; 
		}
		void setParent(BSTnode* p)
		{
			parent = p;
		}
		int nodeValue()
		{ 
			return key; 
		}
		BSTnode* nodeLeft()
		{ 
			return left; 
		}
		BSTnode* nodeRight()
		{ 
			return right; 
		}
		BSTnode* nodeParent()
		{
			return parent;
		}
	private:
		int key;
		BSTnode* left;
		BSTnode* right;
		BSTnode* parent;
};

void TreeInsert(BSTnode* root, BSTnode* z)
{
	BSTnode* y = NULL;
 	BSTnode* x = root;
	while (x != NULL)
	{
		y = x;
		if (z->nodeValue() <= x->nodeValue())
			x = x->nodeLeft();
		else
			x = x->nodeRight();
	}
	z->setParent(y);
	if ( y == NULL) //Empty Tree
	{
		cout << "Empty Tree." << endl;
	}
	else
	{ 
		if (z->nodeValue() <= y->nodeValue())
			y->setLeft(z);
		else
			y->setRight(z);
	}
}

void InorderWalk(BSTnode* x)
{
	if(x != NULL)
	{
		InorderWalk(x->nodeLeft());
		cout << x->nodeValue() << endl;
		InorderWalk(x->nodeRight());
	}
}

int main()
{
	BSTnode* root = new BSTnode(3);
	TreeInsert(root, new BSTnode(5));	
	TreeInsert(root, new BSTnode(7));
	
	InorderWalk(root);

	return 0;
}	
