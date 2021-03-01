#include "graph.h"
#include<iostream>
#include"queue.h"
using  namespace std;

//typedef int ertex;



template <int graph_size,class Weight>
void Digraph<graph_size,Weight>::read()//�˺�������ͼ���ڽӾ���
/*
Post: A user specified Digraph has been read from the terminal
*/
{
	cout << "How many vertices are in the digraph "
		<< "(answer between 1 and " << graph_size << ")? " << flush;
	cin >> count;
	cout << "For each vertex, give the vertices to which it points."
		<< endl;
	cout << "Type the numbers (terminated by a : for each vertex), "
		<< "separate numbers by blanks." << endl;
	for (Vertex v = 0; v < count; v++) {
		for (Vertex w = 0; w < count; w++)
		{
			adjacency[v][w] = false;
			weight_adjacency[v][w] = infinity;
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
				if (0 <= w && w < count) adjacency[v][w] = true;
			}
		} while (c != ':');    //ע���do��whileѭ������������ÿ�������ָ��Ľ���
		for (Vertex w = 0; w < count; w++)//��forѭ�����������do-whileѭ���������ñߵ�Ȩֵ
		{
			if (adjacency[v][w])
			{
				cout << v<<w << "=";
				cin >> weight_adjacency[v][w];
			}
		}

	}
}

template <int graph_size,class Weight>
void Digraph<graph_size,Weight>::write()
/*
Post: The Digraph has been printed to the terminal
*/
{
	for (Vertex v = 0; v < count; v++) 
	{
		cout << "Vertex " << v << " has succesors: ";
		for (Vertex w = 0; w < count; w++)
		{
			if (adjacency[v][w])
				cout << w << ' ';
			cout<<endl;// " and "<<"edge"<<v<<w<<"="<<weight_adjacency[v][w]<<endl;
		}
	}
}


template <int graph_size, class Weight>
void Digraph<graph_size, Weight>::Dijkstra(Vertex source, Weight dist[], Vertex prev[])const
{
	Vertex v, w;
	bool visited[graph_size];
	for (v = 0; v< count; v++){
		visited[v] = false;
		prev[v] = source;
	}
	for (v = 0; v < count; v++){
		for (w = 0; w < count; w++){
			dist[v] = weight_adjacency[v][w];
		}
	}
	visited[source] = true;
	dist[source] = 0;
	for (int i = 1; i < count; i++){//����Դ���⻹��count-1������Ҫ����Դ�㵽���ľ��룬���ѭ����Ҫִ��count-1��
		Weight min = infinity;
		for (w = 0; w < count; w++){//��forѭ�����õ����ķ������dist�����е���Сֵ
			if (!visited[w]){
				if (dist[w] < min){
					min = dist[w];
					v = w;         //��v����¼������С�Ľ��
				}
			}
		}
		visited[v] = true;
		for (w = 0; w < count; w++){   //����
			if (!visited[w]){
				if (dist[v] + weight_adjacency[v][w] < dist[w]){
					dist[w] = dist[v] + weight_adjacency[v][w];
					prev[w] = v;
				}
			}
		}
	}
}

template <int graph_size, class Weight>
void Digraph<graph_size, Weight>::Prim(Vertex source, Digraph<graph_size, Weight>& tree)
{
	Vertex v,w;
	Weight lowcost[graph_size];  //lowcost[v]������¼weight_adjacency[v][closest[v]]
	Vertex closest[graph_size];  //closest[v]������¼�ڼ���v-s�о�����v����Ľ��
	bool s[graph_size];
	s[source] = true;        //��ʼʱ����s����ֻ��Դ�㣬�����ĳ�������������v-s�еĽ�㰴��MST����½�����뵽s����
	for (v=0; v < count��v!=source; v++){
		closest[v] = source;                //ע��closest����ĳ���Ϊcount-1��
		lowcost[v] = weight_adjacency[source][v];//ע��lowcost����ĳ���Ϊcount-1����Ϊ��n��������ֻ��n-1����
		s[v] = false;
	}
	for (int i = 1; i < count; i++){
		Weight min = infinity;
		for (v = 0; v < count; v++){   //���õ������ҳ�closest[v]��������Сֵ
			if (!s[v] && lowcost[v] < min){
				min = lowcost[v];
				w = v;
			}
		}
		if (min < infinity){//�����������˵������ͨ��
			s[w] = true;
			tree.add_edge(w, closest[v], min);
			for (v = 0; v < count; v++){
				if (!s[v] && lowcost[v] > weight_adjacency[w][v]){//ע����С������ǿ�����ǰ����н�㶼�������������һ����s��������˽��w����Ҫ�Ƚϴӽ��w��wֱ�������ĵ��Ȩֵ�Ƿ��֮ǰ�洢��ҪС��
					lowcost[v] = weight_adjacency[w][v];
					closest[v] = w;
				}
			}
		}
		else
		{
			cout << "The graph is not connected.";
			break;                   //����forѭ��
		}
	}
}

template <int graph_size, class Weight>                //ע��ͼ��������㷨һ��д���������ʽ���ڶ�����һ���ݹ麯������һ�����������ݹ飬�ݹ�һ���������������ŵ����һ��һֱ������ȥֱ���յ�
void Digraph<graph_size, Weight>::depth_first_traverse(void(*visite)(Vertex &))const
{
	bool visited[graph_size];
	for (Vertex v = 0; v < graph_size; v++){
		visited[v] = false;
	}
	for (v = 0; v < count; v++){                    //һ��Vertex 0�ǵ�һ���������Ľ��
		if (!visited[v])
			traverse(v, visisted, visit);//visit�ǶԺ������������á�
	}
}


template <int graph_size, class Weight>
void Digraph<graph_size, Weight>::traverse(Vertex v, bool visited[], void(*visite)(Vertex &))const
{
	visited[v] = true;
	(*visite)(v);        //������ǰ��������ƣ�һ��������㣬�����ȷ��ʸý��
	for (Vertex w = 0; w < count; w++){
		if ((adjacency[v][w] != false )&& (!visited[w]))
			traverse(w, visisted, visit);
	}
}


template <int graph_size, class Weight>
void Digraph<graph_size, Weight>::Floyd(int arrDis[][graph_size], Vertex arrPath[][graph_size])const
{ 
	Vertex w, v;
	for (v = 0; v < count; v++){//ʹ���ڽӾ���weight_adjacency��arrDis���г�ʼ��
		for (w = 0; w < count; w++){
			arrDis[v][w] = weight_adjacency[v][w];
			arrPath[v][w] = v;
		}
	}
	for (Vertex k = 0; k < count; k++){
		for (v= 0; v < count; v++){
			for (w= 0; w < count; w++){
				if (arrDis[v][k] + arrDis[k][w] < arrDis[v][w]){// �ҵ��˸���·��
					arrDis[v][w] = arrDis[v][k] + arrDis[k][w];
					arrPath[v][w] = arrPath[k][w];
				}
			}
		}
	}

}


template <int graph_size, class Weight>
void Digraph<graph_size, Weight>::breadth_first_travese(void(*visite)(Vertex &))const
{
	Vertex v, w,x;
	bool visited[graph_size];
	for (Vertex v = 0; v < graph_size; v++){//��ʼʱ�����Խ�㶼û�б�����
		visited[v] = false;
	}
	queue<Vertex> myqueue;//�����ǵĴ����Ƚ��ȳ����Ƚ��ȴ���
	for (v = 0; v < count; v++){                    //һ��Vertex 0�ǵ�һ���������Ľ��
		if (!visited[v])
			myqueue.append(v);
		while (!myqueue.empty()){//whlileѭ�����÷��ʲ����Զ�����
			myqueue.retrieve(w);Դ
			if (!visited[w]){
				visited[w] = true;
				(*visite)(x);
				for (x = 0; x < count; x++){
					if ((adjacency[v][x] != false) && (!visited[x]))
						myqueue.append(x);
				}
			}
			myqueue.serve();
		}
	}
}

