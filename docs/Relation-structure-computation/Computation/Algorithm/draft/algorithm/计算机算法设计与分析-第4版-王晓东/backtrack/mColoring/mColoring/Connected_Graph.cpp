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
		} while (c != ':');    //注意此do—while循环是用来读入每个结点所指向的结点的
		/*for (Vertex w = 0; w < count; w++)//次for循环根据上面的do-while循环再来设置边的权值
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
int Connected_Graph<graph_size>::mColoring(int m)//这是第一层函数，用来调用第二层的递归函数
{
	int x[graph_size];
	colors = m;   //颜色数
	int sum = 0;  //统计所有的着色方案
	BackTrack(0, sum,x);
	return sum;
}

template<int graph_size>
void Connected_Graph<graph_size>::BackTrack(int t, int& sum,int x[])//sum是用引用传递到第二层函数中的，这样做是因为在第二层函数中会对sum进行修改，按照引用传参能够使第一层函数及时地同步sum的改变
{
	if (t>=count){
		sum++;  //表示这条路径能够走得通，那么这就是一个合法的解，sum就自加1
		for (int i = 0; i < count; i++)
			cout << x[i] << ' ';   //输出这条路径
		cout << endl;
	}
	else{
		for (int i = 1; i <= count; i++){
			x[t] = i;  //进行着色
			if (Ok(t,x))  //检查
				BackTrack(t + 1,sum,x); //如果已经对x[count-1]进行了赋值，说明已经对图中的某个结点着色了，如果对最后一个结点的着色是合法的，那么递归将进行到下一层（同时也是最后一层），此时调用Backtrack（count），显然此时t=count，那么回溯函数输出解
			x[t] = 0;//回溯回来时表示当前路径不是合法解，那么就要撤销之前的赋值
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