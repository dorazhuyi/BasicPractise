#include <iostream>
#include "AdjList.h"

using namespace std;

Vertex::Vertex()
{
	vid = -1;
	/*pe = NULL;
	nedge = 0;*/
}

Vertex::Vertex(int i)
{
	vid = i;
	/*pe = NULL;
	nedge = 0;*/
	cout << "Vertex " << i << " created." << endl;
}

void Vertex::set_id(int i)
{
	vid = i;
}

/*void Vertex::set_Edge_num(int n)
{
	pe = new Edge*[n];
}

void Vertex::set_Edge(Edge* e)
{
	pe[nedge] = e;
	nedge++;
}*/

void Vertex::set_Edge(Edge* e)
{
	pe.push_back(e);
}

int Vertex::Edge_num()
{
	//return nedge;
	return pe.size();
}

int Vertex::Vertex_id()
{
	return vid;
}

Edge::Edge()
{
	tail = NULL;
	head = NULL;
}

Edge::Edge(Vertex* t, Vertex* h)
{
	tail = t;
	head = h;
	cout << "Edge created. Head: " << h->Vertex_id() << " Tail: " << t->Vertex_id() << endl;
}

void Edge::set_tail(Vertex* t)
{
	tail = t;
}

void Edge::set_head(Vertex* h)
{
	head = h;
}

