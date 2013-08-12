#ifndef __BTNODE_H
#define __BTNODE_H

class BTnode
{
	public:
		BTnode();
		BTnode(int);
		void set_value(int);
		void set_left(BTnode*);
		void set_right(BTnode*);
	private:
		int value;
		BTnode* left;
		BTnode* right;
};

#endif
