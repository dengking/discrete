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
	//arrDis[][]�����洢����Ľ⣬��ͼ�������������֮�����̾��롣ʹ���ڽӾ���weight_adjacency�������г�ʼ��
	//arrPath�洢�����м��㣬arrPath[i][j]��ʾ�ӽ��i�����j�����·����Ҫ�������м���
	//ͬ�����˷���������Ѱ�����·���ģ�����ڶ��ڽӾ�����г�ʼ����ʱ�򣬰�û�����ӵ��������֮����ڽӾ����ʼ��Ϊ�������
private:
	bool adjacency[graph_size][graph_size];
protected:
	Weight weight_adjacency[graph_size][graph_size];//�洢�ڵ��ľ���
	int count;//ʵ�ʵĽ����
	const Weight infinity = numeric_limits<int>::max();
};
#endif
