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
	int mColoring(int m);//m���������ɫ�ĸ���
private:
	void BackTrack(int t, int& sum,int x[]);//���ݷ���ͼ��m��ɫ
	bool Ok(int t,int x[]);   //�����ɫ������
	bool adjacency[graph_size][graph_size];
	int count;//ʵ�ʵĽ����
	int colors;
};

#endif