#include<iostream>
#include "clique.h"
using namespace std;

class clique{
	friend void MaxClique(int **a, int v[], int n);//注意函数的类型一定不能忘记
public:
	clique();
private:
	void Backtrack(int i);
	int **a;//图G的邻接矩阵
	int n;//G中顶点的个数
	int  *x;//当前解
	int *bestx;//当前最优解
	int cn;//当前顶点个数
	int bestcn;//当前最大顶点个数
};


clique::clique(){

}

void clique::Backtrack(int i){//注意回溯算法是从0开始执行的
	if (i >= n){//问题中的结点的编号是0，1，2.....(n-1)
		for (int j = 0; j < n; j++){
			bestx[j] = x[j];
		}
		bestcn = cn;//这类似迭代的思想：只要
		return;
	}
	int OK = 1;
	for (int j = 0; j < i; j++){//进行检测：当前结点和已经选入到团中的结点是否都连接
		if (x[j] && a[i][j] == 0){//当前结点i和已经选入的结点j没有连接
			OK = 0;
			break;//跳出for循环
		}
	}
	if (OK){//当前结点和已经选入团中的每个结点都有连接，则可以选入该结点
		x[i] = 1;//选入该结点
		cn++;//结点个数加一
		Backtrack(i + 1);//回溯到下一层
		x[i] = 0;
		cn--;
	}
	if ((cn + n - i - 1)>bestcn){//当前结点不选入到团中，此处进行了剪枝，进行了启发式的搜索
		x[i] = 0;
		Backtrack(i + 1);
	}
}
