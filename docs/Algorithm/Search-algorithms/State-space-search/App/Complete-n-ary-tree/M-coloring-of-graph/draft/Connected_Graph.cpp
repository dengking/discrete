#include "Connected_Graph.h"
#include<iostream>
using namespace std;


template<int graph_size>
void Connected_Graph<graph_size>::read()
{
	cout << "How many vertices are in the connected undirected graph "
		<< "(answer between 1 and " << graph_size << ")? " << flush;
	cin >> count;
	cout << "For each vertex, give the vertices to which it connect."
		<< endl;
	cout << "Type the numbers (terminated by a : for each vertex), "
		<< "separate numbers by blanks." << endl;
	for (Vertex v = 0; v < count; v++) {
		for (Vertex w = 0; w < count; w++)
		{
			adjacency[v][w] = false;
			//weight_adjacency[v][w] = infinity;
		}
		char c;
		cout << "Vertex " << v << " : " << flush;
		do {
			Vertex w;
			c = cin.get();
			if ('0' <= c && c <= '9') {
				w = c - '0';
				while ((c = cin.get()) >= '0' && c <= '9')
					w = 10 * w + c - '0';
				if (0 <= w && w < count) adjacency[v][w] = adjacency[w][v]= true;
			}
		} while (c != ':');    //ע���do��whileѭ������������ÿ�������ָ��Ľ���
		/*for (Vertex w = 0; w < count; w++)//��forѭ�����������do-whileѭ���������ñߵ�Ȩֵ
		{
			if (adjacency[v][w])
			{
				cout << v << w << "=";
				cin >> weight_adjacency[v][w];
			}
		}
		*/

	}
}

template<int graph_size>
void Connected_Graph<graph_size>::write()
{
	for (Vertex v = 0; v < count; v++)
	{
		cout << "Vertex " << v << " connects to : ";
		for (Vertex w = v+1; w < count; w++)
		{
			if (adjacency[v][w])
				cout << w << ' ';
			cout << endl;// " and "<<"edge"<<v<<w<<"="<<weight_adjacency[v][w]<<endl;
		}
	}
}

template<int graph_size>
int Connected_Graph<graph_size>::mColoring(int m)//���ǵ�һ�㺯�����������õڶ���ĵݹ麯��
{
	int x[graph_size];
	colors = m;   //��ɫ��
	int sum = 0;  //ͳ�����е���ɫ����
	BackTrack(0, sum,x);
	return sum;
}

template<int graph_size>
void Connected_Graph<graph_size>::BackTrack(int t, int& sum,int x[])//sum�������ô��ݵ��ڶ��㺯���еģ�����������Ϊ�ڵڶ��㺯���л��sum�����޸ģ��������ô����ܹ�ʹ��һ�㺯����ʱ��ͬ��sum�ĸı�
{
	if (t>=count){
		sum++;  //��ʾ����·���ܹ��ߵ�ͨ����ô�����һ���Ϸ��Ľ⣬sum���Լ�1
		for (int i = 0; i < count; i++)
			cout << x[i] << ' ';   //�������·��
		cout << endl;
	}
	else{
		for (int i = 1; i <= count; i++){
			x[t] = i;  //������ɫ
			if (Ok(t,x))  //���
				BackTrack(t + 1,sum,x); //����Ѿ���x[count-1]�����˸�ֵ��˵���Ѿ���ͼ�е�ĳ�������ɫ�ˣ���������һ��������ɫ�ǺϷ��ģ���ô�ݹ齫���е���һ�㣨ͬʱҲ�����һ�㣩����ʱ����Backtrack��count������Ȼ��ʱt=count����ô���ݺ��������
			x[t] = 0;//���ݻ���ʱ��ʾ��ǰ·�����ǺϷ��⣬��ô��Ҫ����֮ǰ�ĸ�ֵ
		}
	}
}

template<int graph_size>
bool Connected_Graph<graph_size>::Ok(int t,int x[]){
	for (Vertex v = 0; v < count; v++){
		if (adjacency[v][t] && (x[t] == x[v]))
			return false;
	}
	return true;

}