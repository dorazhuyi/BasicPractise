#include <iostream>

using namespace std;

class Vertex;
class Edge;

class Vertex
{
	public:
		Vertex();
		Vertex(int);
		void set_id(int);
		void set_Edge_num(int);
		void set_Edge(Edge*);
		int Vertex_id();
		int Edge_num();
	private:
		int vid;
		int nedge;
		Edge** pe;
};

class Edge
{
	public:
		Edge();
		Edge(Vertex*, Vertex*);
		void set_tail(Vertex*);
		void set_head(Vertex*);

	private:
		Vertex* tail;
		Vertex* head;
};

Vertex::Vertex()
{
	vid = -1;
	pe = NULL;
	nedge = 0;
}

Vertex::Vertex(int i)
{
	vid = i;
	pe = NULL;
	nedge = 0;
	cout << "Vertex " << i << " created." << endl;
}

void Vertex::set_id(int i)
{
	vid = i;
}

void Vertex::set_Edge_num(int n)
{
	pe = new Edge*[n];
}

void Vertex::set_Edge(Edge* e)
{
	pe[nedge] = e;
	nedge++;
}

int Vertex::Edge_num()
{
	return nedge;
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

int main()
{
	Vertex V[4];
	Edge E[5];

	for(int i=0;i<4;i++)
		V[i] = Vertex(i);

	E[0] = Edge(&V[0],&V[1]);
	E[1] = Edge(&V[0],&V[3]);
	E[2] = Edge(&V[1],&V[2]);
	E[3] = Edge(&V[1],&V[2]);
	E[4] = Edge(&V[2],&V[3]);

	V[0].set_Edge_num(2);
	V[1].set_Edge_num(3);
	V[2].set_Edge_num(2);
	V[3].set_Edge_num(3);
	
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
