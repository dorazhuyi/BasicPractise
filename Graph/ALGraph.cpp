#include <iostream>
#include <limits>
#include <string>
#include <map>
#include <list>
#include <queue>

using namespace std;

class vertex
{
	public:
		vertex():dst(numeric_limits<int>::max()), vst(false) {}
		vertex(string s):name(s), dst(numeric_limits<int>::max()), vst(false) {}
		void setDST(int d) { dst = d; }
		void setVST() { vst = true; }
		string vname() const { return name; }
		int distance() const { return dst; }
		bool isVisited() const { return vst; }
		bool operator< (const vertex& v) const {return name < v.vname();}
	private:
		string name;
		int dst;
		bool vst;
};

class ALUGraph
{
	public:
		ALUGraph(){};
		~ALUGraph();
		void addVertex(const vertex& v);
		void addEdge(const vertex& v, const vertex& u);
		void bfs(vertex* s);
	private:
		map<vertex, list<vertex>* > gmap;
};

ALUGraph::~ALUGraph()
{
	map<vertex, list<vertex>* >::iterator it;
	for(it=gmap.begin();it!=gmap.end();++it)
		delete it->second;
}

void ALUGraph::addVertex(const vertex& v)
{
	list<vertex>* vlist;
	if(gmap.find(v) == gmap.end())
	{
		vlist = new list<vertex>;
		gmap[v] = vlist;
		//vlist->push_front(v);
		cout << "Vertex [" << v.vname() << "] is created." << endl;
	}
   /*	else {
		cout << "Vertex [" << v.vname()  << "] exists." << endl;
	}*/
}

void ALUGraph::addEdge(const vertex& v, const vertex& u)
{
	list<vertex>* vlist;
	addVertex(v);
	vlist = gmap.find(v)->second;
	if( vlist->empty() || vlist->front().vname() != u.vname())
	{
		vlist->push_front(u);
		cout << "Vertex [" << u.vname() << "] is added to vertex ["<< v.vname() << "]." << endl;
		addEdge(u,v);
	}
}

void ALUGraph::bfs(vertex* s)
{
	vertex* u;
	list<vertex>* vlist;
	list<vertex>::iterator lit;
	queue<vertex*> VQ;

	u = s;
	u->setDST(0);
	VQ.push(u);
	while( !VQ.empty() ){
	   	u = VQ.front();
		VQ.pop();
		cout << "current: " << u->vname() << " visited: " << u->isVisited() << endl;
	 	vlist = gmap.find(*u)->second;
		for(lit = vlist->begin(); lit != vlist->end(); ++lit  )
		{
			cout << " lit: " << lit->vname() << " visited: " << lit->isVisited()  << endl;
			if( !(lit->isVisited()) )
			{
				lit->setDST(u->distance()+1);
				VQ.push(&(*lit));
			}
		}
		u->setVST();
		cout << " set: " << u->vname() << " " << u->isVisited() << endl;
	}
}

int main()
{
	ALUGraph testgraph;
	
	vertex a("a");
	vertex b("b");
	/*testgraph.addVertex(a);
	testgraph.addVertex(a);*/
	testgraph.addEdge(a,b);

	testgraph.bfs(&a);

	return 0;
}
