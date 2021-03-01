#include<iostream>
using namespace std;


const int MAX_VERTEX_COUNT=20;
int INFINITE;
#define INFINITE 1000			// ���ֵ
//#define MAX_VERTEX_COUNT 20	����// ��󶥵����

struct Graph
{
	int	arrArcs[MAX_VERTEX_COUNT][MAX_VERTEX_COUNT];	// �ڽӾ���
	int	nVertexCount;// ��������
	int	nArcCount;// �ߵ�����

};


//ͬ�����˷���������Ѱ�����·���ģ�����ڶ��ڽӾ�����г�ʼ����ʱ�򣬰�û�����ӵ��������֮����ڽӾ����ʼ��Ϊ�������
void floyd(int _arrDis[][MAX_VERTEX_COUNT], int _arrPath[][MAX_VERTEX_COUNT], int _nVertexCount)
{
	//_arrDis[][MAX_VERTEX_COUNT]ԭ���洢����Ľ⣬��ͼ�У������������֮��ľ��롣ʹ���ڽӾ���arrArcs�������г�ʼ��
	//_arrPath[i][j]��ʾ�ӽ��i�����j�����·����Ҫ�������м���
	// �ȳ�ʼ��_arrPath
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
					// �ҵ�����·��
					_arrDis[i][j] = _arrDis[i][k] + _arrDis[k][j];

					_arrPath[i][j] = _arrPath[k][j];
				}
			}
		}
	}
}
