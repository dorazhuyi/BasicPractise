#ifndef __ADJLIST_H_INCLUDED
#define __ADJLIST_H_INCLUDED

#include <vector>

class Vertex;
class Edge;

class Vertex
{
	public:
		Vertex();
		Vertex(int);
		void set_id(int);
		//void set_Edge_num(int);
		void add_Edge(Edge*);
		int Vertex_id();
		int Edge_num();
	private:
		int vid;
		/*int nedge;
		Edge** pe;*/
		std::vector<Edge*> pe;
};

class Edge
{
	public:
		Edge();
		Edge(Vertex*, Vertex*);
		void set_tail(Vertex*);
		void set_head(Vertex*);
		Vertex* Vhead();
		Vertex* Vtail();
	private:
		Vertex* tail;
		Vertex* head;
};

#endif
