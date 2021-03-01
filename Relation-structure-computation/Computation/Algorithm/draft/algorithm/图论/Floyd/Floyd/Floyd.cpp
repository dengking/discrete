#include<iostream>
using namespace std;


const int MAX_VERTEX_COUNT=20;
int INFINITE;
#define INFINITE 1000			// 最大值
//#define MAX_VERTEX_COUNT 20	　　// 最大顶点个数

struct Graph
{
	int	arrArcs[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT];	// 邻接矩阵
	int	nVertexCount;// 顶点数量
	int	nArcCount;// 边的数量

};


//同样，此方法是用来寻找最短路径的，因此在对邻接矩阵进行初始化的时候，把没有连接的两个结点之间的邻接矩阵初始化为正无穷大
void floyd(int _arrDis[][MAX_VERTEX_COUNT], int _arrPath[][MAX_VERTEX_COUNT], int _nVertexCount)
{
	//_arrDis[][MAX_VERTEX_COUNT]原来存储问题的解，即图中，任意两个结点之间的距离。使用邻接矩阵arrArcs对它进行初始化
	//_arrPath[i][j]表示从结点i到结点j的最短路径需要经过的中间结点
	// 先初始化_arrPath
	for (int i = 0; i < _nVertexCount; ++i)
	{
		for (int j = 0; j < _nVertexCount; ++j)
		{
			_arrPath[i][j] = i;
		}
	}
	

	for (int k = 0; k < _nVertexCount; ++k)
	{
		for (int i = 0; i < _nVertexCount; ++i)
		{
			for (int j = 0; j < _nVertexCount; ++j)
			{
				if (_arrDis[i][k] + _arrDis[k][j] < _arrDis[i][j])
				{
					// 找到更短路径
					_arrDis[i][j] = _arrDis[i][k] + _arrDis[k][j];

					_arrPath[i][j] = _arrPath[k][j];
				}
			}
		}
	}
}
