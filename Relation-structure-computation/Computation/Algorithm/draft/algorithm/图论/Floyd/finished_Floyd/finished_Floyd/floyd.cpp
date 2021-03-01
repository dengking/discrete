#include "graph.h"
#include<iostream>
//	#include"queue.h"
using  namespace std;

template <int graph_size, class Weight>
void Digraph<graph_size, Weight>::read()//此函数设置图的邻接矩阵
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
		} while (c != ':');    //注意此do—while循环是用来读入每个结点所指向的结点的
		for (Vertex w = 0; w < count; w++)//次for循环根据上面的do-while循环再来设置边的权值
		{
			if (adjacency[v][w])
			{
				cout << v << w << "=";
				cin >> weight_adjacency[v][w];
			}
		}

	}
}


template <int graph_size, class Weight>//注意我所参考的Floyd算法是解决有向图的
void Digraph<graph_size, Weight>::Floyd(int arrDis[][graph_size], Vertex arrPath[][graph_size])const
{
	Vertex w, v;
	for (v = 0; v < count; v++){//使用邻接矩阵weight_adjacency对arrDis进行初始化
		for (w = 0; w < count; w++){
			arrDis[v][w] = weight_adjacency[v][w];
			arrPath[v][w] = v;
		}
	}
	for (Vertex k = 0; k < count; k++){
		for (v = 0; v < count; v++){
			for (w = 0; w < count; w++){
				if (arrDis[v][k] + arrDis[k][w] < arrDis[v][w]){// 找到了更短路径
					arrDis[v][w] = arrDis[v][k] + arrDis[k][w];
					arrPath[v][w] = arrPath[k][w];
				}
			}
		}
	}

}