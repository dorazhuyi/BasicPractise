#include <iostream>
#include <vector>
#include "AdjList.h"

using namespace std;

void constraction(vector<Vertex> V, vector<Edge> E)
{
	while(V.size() > 2)
	{

	}

}

int main()
{
	/* Create Graph */
	vector<Vertex> V;
	vector<Edge> E;

	for(int i=0;i<4;i++)
		V.push_back(Vertex(i)); 

	E.push_back(Edge(&V[0],&V[1]));
	E.push_back(Edge(&V[0],&V[3]));
	E.push_back(Edge(&V[1],&V[2]));
	E.push_back(Edge(&V[1],&V[3]));
	E.push_back(Edge(&V[2],&V[3]));

	/* Check */
	for(int i=0;i<4;i++)
		cout << "Vertex: " << V.at(i).Vertex_id() << " Edges: " << V.at(i).Edge_num() << endl;



	return 0;
}
