#if !defined GRAPH_H
#define GRAPH_H

typedef int Vertex;

template<int graph_size, class Weight>
class Digraph
{
public:
	Digraph(){ count = 0; }
	
	void read();
	void Floyd(int arrDis[][graph_size], Vertex arrPath[][graph_size])const;
	//arrDis[][]用来存储问题的解，即图中任意两个结点之间的最短距离。使用邻接矩阵weight_adjacency对它进行初始化
	//arrPath存储的是中间结点，arrPath[i][j]表示从结点i到结点j的最短路径需要经过的中间结点
	//同样，此方法是用来寻找最短路径的，因此在对邻接矩阵进行初始化的时候，把没有连接的两个结点之间的邻接矩阵初始化为正无穷大
private:
	bool adjacency[graph_size][graph_size];
protected:
	Weight weight_adjacency[graph_size][graph_size];//存储节点间的距离
	int count;//实际的结点数
	const Weight infinity = numeric_limits<int>::max();
};
#endif
