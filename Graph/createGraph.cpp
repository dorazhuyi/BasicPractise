#include <iostream>
#include "AdjList.h"

using namespace std;

int main()
{
	/* Create Graph */
	Vertex V[4];
	Edge E[5];

	for(int i=0;i<4;i++)
		V[i] = Vertex(i);

	E[0] = Edge(&V[0],&V[1]);
	E[1] = Edge(&V[0],&V[3]);
	E[2] = Edge(&V[1],&V[2]);
	E[3] = Edge(&V[1],&V[2]);
	E[4] = Edge(&V[2],&V[3]);
	/*
	V[0].set_Edge_num(2);
	V[1].set_Edge_num(3);
	V[2].set_Edge_num(2);
	V[3].set_Edge_num(3);
	*/
	V[0].set_Edge(&E[0]);
	V[1].set_Edge(&E[0]);
	
	V[0].set_Edge(&E[1]);
	V[3].set_Edge(&E[1]);

	V[1].set_Edge(&E[2]);
	V[2].set_Edge(&E[2]);

	V[1].set_Edge(&E[3]);
	V[2].set_Edge(&E[3]);

	V[2].set_Edge(&E[4]);
	V[3].set_Edge(&E[4]);


	return 0;
}
