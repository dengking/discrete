#include "graph.h"
#include<iostream>
#include"queue.h"
using  namespace std;

//typedef int ertex;



template <int graph_size,class Weight>
void Digraph<graph_size,Weight>::read()//此函数设置图的邻接矩阵
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
	for (int i = 1; i < count; i++){//除了源点外还有count-1个点需要计算源点到它的距离，因此循环需要执行count-1次
		Weight min = infinity;
		for (w = 0; w < count; w++){//此for循环运用迭代的方法求出dist数组中的最小值
			if (!visited[w]){
				if (dist[w] < min){
					min = dist[w];
					v = w;         //用v来记录距离最小的结点
				}
			}
		}
		visited[v] = true;
		for (w = 0; w < count; w++){   //更新
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
	Weight lowcost[graph_size];  //lowcost[v]用来记录weight_adjacency[v][closest[v]]
	Vertex closest[graph_size];  //closest[v]用来记录在集和v-s中距离结点v最近的结点
	bool s[graph_size];
	s[source] = true;        //初始时，在s集中只有源点，后续的程序用来将集和v-s中的结点按照MST性质陆续加入到s集中
	for (v=0; v < count，v!=source; v++){
		closest[v] = source;                //注意closest数组的长度为count-1，
		lowcost[v] = weight_adjacency[source][v];//注意lowcost数组的长度为count-1，因为有n个结点的树只有n-1条边
		s[v] = false;
	}
	for (int i = 1; i < count; i++){
		Weight min = infinity;
		for (v = 0; v < count; v++){   //运用迭代法找出closest[v]数组中最小值
			if (!s[v] && lowcost[v] < min){
				min = lowcost[v];
				w = v;
			}
		}
		if (min < infinity){//满足此条件，说明是连通的
			s[w] = true;
			tree.add_edge(w, closest[v], min);
			for (v = 0; v < count; v++){
				if (!s[v] && lowcost[v] > weight_adjacency[w][v]){//注意最小生成树强调的是把所有结点都连接起来，因此一旦在s集中添加了结点w，就要比较从结点w到w直接相连的点的权值是否比之前存储的要小。
					lowcost[v] = weight_adjacency[w][v];
					closest[v] = w;
				}
			}
		}
		else
		{
			cout << "The graph is not connected.";
			break;                   //跳出for循环
		}
	}
}

template <int graph_size, class Weight>                //注意图深度优先算法一般写出两层的形式，第二层是一个递归函数，第一层则负责启动递归，递归一旦启动，就像多米诺骨牌一般一直运行下去直到终点
void Digraph<graph_size, Weight>::depth_first_traverse(void(*visite)(Vertex &))const
{
	bool visited[graph_size];
	for (Vertex v = 0; v < graph_size; v++){
		visited[v] = false;
	}
	for (v = 0; v < count; v++){                    //一般Vertex 0是第一个遍历到的结点
		if (!visited[v])
			traverse(v, visisted, visit);//visit是对函数参数的引用。
	}
}


template <int graph_size, class Weight>
void Digraph<graph_size, Weight>::traverse(Vertex v, bool visited[], void(*visite)(Vertex &))const
{
	visited[v] = true;
	(*visite)(v);        //和树的前序遍历类似，一旦遇到结点，就首先访问该结点
	for (Vertex w = 0; w < count; w++){
		if ((adjacency[v][w] != false )&& (!visited[w]))
			traverse(w, visisted, visit);
	}
}


template <int graph_size, class Weight>
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
		for (v= 0; v < count; v++){
			for (w= 0; w < count; w++){
				if (arrDis[v][k] + arrDis[k][w] < arrDis[v][w]){// 找到了更短路径
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
	for (Vertex v = 0; v < graph_size; v++){//初始时，所以结点都没有被访问
		visited[v] = false;
	}
	queue<Vertex> myqueue;//队列是的处理，先进先出，先进先处理
	for (v = 0; v < count; v++){                    //一般Vertex 0是第一个遍历到的结点
		if (!visited[v])
			myqueue.append(v);
		while (!myqueue.empty()){//whlile循环，让访问操作自动进行
			myqueue.retrieve(w);源
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

