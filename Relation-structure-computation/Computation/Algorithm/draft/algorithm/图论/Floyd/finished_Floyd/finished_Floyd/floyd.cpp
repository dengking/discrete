#include "graph.h"
#include<iostream>
//	#include"queue.h"
using  namespace std;

template <int graph_size, class Weight>
void Digraph<graph_size, Weight>::read()//�˺�������ͼ���ڽӾ���
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
				cout << v << w << "=";
				cin >> weight_adjacency[v][w];
			}
		}

	}
}


template <int graph_size, class Weight>//ע�������ο���Floyd�㷨�ǽ������ͼ��
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
		for (v = 0; v < count; v++){
			for (w = 0; w < count; w++){
				if (arrDis[v][k] + arrDis[k][w] < arrDis[v][w]){// �ҵ��˸���·��
					arrDis[v][w] = arrDis[v][k] + arrDis[k][w];
					arrPath[v][w] = arrPath[k][w];
				}
			}
		}
	}

}