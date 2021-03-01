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
		void Dijkstra(Vertex source,Weight dist[], Vertex prev[])const; //dist[]�����������յĽ����
		                                                //prev[]������¼ÿ������ֱ��ǰ����Dijkstra�㷨�����������Դ�㵽ÿ��������̾���
		void Floyd(int arrDis[][graph_size], Vertex arrPath[][graph_size])const;//arrDis[][]�����洢����Ľ⣬��ͼ�У������������֮�����̾��롣ʹ���ڽӾ���weight_adjacency�������г�ʼ��
		                                                //arrPath�洢�����м��㣬arrPath[i][j]��ʾ�ӽ��i�����j�����·����Ҫ�������м���
		                                               //ͬ�����˷���������Ѱ�����·���ģ�����ڶ��ڽӾ�����г�ʼ����ʱ�򣬰�û�����ӵ��������֮����ڽӾ����ʼ��Ϊ�������
		void Prim(Vertex source, Digraph<graph_size, Weight>& tree);//Prim�㷨����MST������Ϊ��ʯ�ġ�Prim�㷨��Kruskal�㷨��������MST��
		void Kruskal(Vertex source, Digraph<graph_size, Weight>& tree);

		void depth_first_traverse(void(*visite)(Vertex &))const;//�������б�������0�Ž�㿪ʼ��
		void breadth_first_travese(void(*visite)(Vertex &))const;
	private:
		bool adjacency[graph_size][graph_size];
    protected:
		Weight weight_adjacency[graph_size][graph_size];//�洢�ڵ��ľ���
		int count;//ʵ�ʵĽ����
		const Weight infinity = numeric_limits<int>::max();
		void traverse(Vertex v, bool visited[], void(*visite)(Vertex &))const;
};


#endif
