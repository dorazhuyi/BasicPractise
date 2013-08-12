#include <iostream>
#include "BTnode.h"

using namespace std;

BTnode::BTnode()
{
	value = -1;
	left = NULL;
	right = NULL;
}

BTnode::BTnode(int v)
{
	value = v;
	left = NULL;
	right = NULL;
}

void set_value(int v)
{
	value = v;
}

void set_left(BTnode* l)
{
	left = l;
}

void set_right(BTnode* r)
{
	right = r;
}
