#if !defined GRAPH_H
#define GRAPH_H
#include "graph.h"

template<int graph_size, class Weight>
class Network public: Digraph<graph_size, Weight>
{
	public;
	void Prim();//Prim算法和Kruskal算法是用来求MST的
	void Kruskal(Vertex source, Network<graph_size, Weight>& tree);

}
#endif