#if !defined GRAPH_H
#define GRAPH_H

//using namespace std;

//const graph_size=10;
typedef int Vertex;

template<int graph_size>
class Connected_Graph
{
public:
	const int infinity = numeric_limits<int>::max();
	Connected_Graph(){ count = 0; colors = 0; }
	void read();
	void write();
	int mColoring(int m);//m代表的是颜色的个数
private:
	void BackTrack(int t, int& sum,int x[]);//回溯法求图的m着色
	bool Ok(int t,int x[]);   //检查颜色可用性
	bool adjacency[graph_size][graph_size];
	int count;//实际的结点数
	int colors;
};

#endif