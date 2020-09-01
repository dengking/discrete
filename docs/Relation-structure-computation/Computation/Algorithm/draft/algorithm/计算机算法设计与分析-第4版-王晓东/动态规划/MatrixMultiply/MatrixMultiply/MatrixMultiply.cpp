
#include <iostream>
using namespace std;

const int L = 7;

int LookupChain(int i, int j, int **m, int **s, int *p);//计算从矩阵i到矩阵j的最小乘法次数
int MemoizedMatrixChain(int n, int **m, int **s, int *p);//调用LookupChain

void Traceback(int i, int j, int **s);//构造最优解  

int main()
{
	int p[L] = { 30, 35, 15, 5, 10, 20, 25 };

	int **s = new int *[L];
	int **m = new int *[L];
	for (int i = 0; i < L; i++)
	{
		s[i] = new int[L];
		m[i] = new int[L];
	}

	cout << "矩阵的最少计算次数为：" << MemoizedMatrixChain(6, m, s, p) << endl;
	cout << "矩阵最优计算次序为：" << endl;
	Traceback(1, 6, s);
	return 0;
}

int MemoizedMatrixChain(int n, int **m, int **s, int *p)
{
	for (int i = 1; i <= n; i++)//首先对m数组进行初始化，这是在使用动态规划算法时为了安全起见的重要的一步
	{
		for (int j = 1; j <= n; j++)
		{
			m[i][j] = 0;
		}
	}
	return LookupChain(1, n, m, s, p);
}

int LookupChain(int i, int j, int **m, int **s, int *p)
{
	if (m[i][j] > 0)//说明m[i][j]已经计算出来了，递归调用时首先进行的是查表操作，而不是往下递归，这就避免了重复问题的计算
	{
		return m[i][j];
	}
	if (i == j)//情况一
	{
		return 0;
	}

	int u = LookupChain(i, i, m, s, p) + LookupChain(i + 1, j, m, s, p) + p[i - 1] * p[i] * p[j];
	s[i][j] = i;
	for (int k = i + 1; k < j; k++)
	{
		int t = LookupChain(i, k, m, s, p) + LookupChain(k + 1, j, m, s, p) + p[i - 1] * p[k] * p[j];
		if (t < u)
		{
			u = t;
			s[i][j] = k;
		}
	}
	m[i][j] = u;//填表，把计算结果记录下来，以便今后使用
	return u;
}

void Traceback(int i, int j, int **s)
{
	if (i == j) return;
	Traceback(i, s[i][j], s);
	Traceback(s[i][j] + 1, j, s);
	cout << "Multiply A" << i << "," << s[i][j];
	cout << " and A" << (s[i][j] + 1) << "," << j << endl;
}
