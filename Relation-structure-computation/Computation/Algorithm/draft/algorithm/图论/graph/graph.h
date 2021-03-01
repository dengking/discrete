#if !defined GRAPH_H
#define GRAPH_H

//using namespace std;

//const graph_size=10;
typedef int Vertex;

template<int graph_size,class Weight>
class Digraph
{
	public:
		Digraph(){count=0;}//
		//Digraph(Weight **adj);
		void read();
		void write();
		void add_edge(Vertex v, Vertex w, Weight x);
		void Dijkstra(Vertex source,Weight dist[], Vertex prev[])const; //dist[]用来保存最终的结果，
		                                                //prev[]用来记录每个结点的直接前驱，Dijkstra算法是用来求出从源点到每个结点的最短距离
		void Floyd(int arrDis[][graph_size], Vertex arrPath[][graph_size])const;//arrDis[][]用来存储问题的解，即图中，任意两个结点之间的最短距离。使用邻接矩阵weight_adjacency对它进行初始化
		                                                //arrPath存储的是中间结点，arrPath[i][j]表示从结点i到结点j的最短路径需要经过的中间结点
		                                               //同样，此方法是用来寻找最短路径的，因此在对邻接矩阵进行初始化的时候，把没有连接的两个结点之间的邻接矩阵初始化为正无穷大
		void Prim(Vertex source, Digraph<graph_size, Weight>& tree);//Prim算法是以MST性质作为基石的。Prim算法和Kruskal算法是用来求MST的
		void Kruskal(Vertex source, Digraph<graph_size, Weight>& tree);

		void depth_first_traverse(void(*visite)(Vertex &))const;//本函数中遍历树丛0号结点开始的
		void breadth_first_travese(void(*visite)(Vertex &))const;
	private:
		bool adjacency[graph_size][graph_size];
    protected:
		Weight weight_adjacency[graph_size][graph_size];//存储节点间的距离
		int count;//实际的结点数
		const Weight infinity = numeric_limits<int>::max();
		void traverse(Vertex v, bool visited[], void(*visite)(Vertex &))const;
};


#endif
