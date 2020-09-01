//3d1-2 �������� ��̬�滮����ʵ��  
//A1 30*35 A2 35*15 A3 15*5 A4 5*10 A5 10*20 A6 20*25  ��˴洢ʱֻ�洢30��35��15��5��10
//p[0-6]={30,35,15,5,10,20,25}  
//#include "stdafx.h"  

#include <iostream>
using namespace std;

const int L = 7;

int MatrixChain(int n, int **m, int **s, int *p);//��̬�滮�㷨
void Traceback(int i, int j, int **s);//�������Ž�

int main()
{
	int p[L] = { 30, 35, 15, 5, 10, 20, 25 };//p[i]��p[i+1]��ʾ��i��������к���

	int **s = new int *[L];
	int **m = new int *[L];
	for (int i = 0; i < L; i++)
	{
		s[i] = new int[L];
		m[i] = new int[L];
	}

	cout << "��������ټ������Ϊ��" << MatrixChain(6, m, s, p) << endl;
	cout << "�������ż������Ϊ��" << endl;
	Traceback(1, 6, s);
	return 0;
}

int MatrixChain(int n, int **m, int **s, int *p)
{
	for (int i = 1; i <= n; i++)
	{
		m[i][i] = 0;
	}
	for (int r = 2; r <= n; r++) //rΪ��ǰ������������������ģ��
	{
		for (int i = 1; i <= n - r + 1; i++)//n-r+1Ϊ���һ��r����ǰ�߽�
		{
			int j = i + r - 1;//����ǰ�߽�Ϊr������Ϊr�����ĺ�߽�

			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];//����ij����ΪA(i) * ( A[i+1:j] )��i����1��ʱ��m[2][2]=0

			s[i][j] = i;

			for (int k = i + 1; k < j; k++)//�Ͽ�λ�ÿ�����i+1��j-1
			{
				//����ij����Ϊ( A[i:k] )* (A[k+1:j])
				int t = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (t < m[i][j])
				{
					m[i][j] = t;
					s[i][j] = k;
				}
			}
		}
	}
	return m[1][L - 1];
}

void Traceback(int i, int j, int **s)
{
	if (i == j) return;
	Traceback(i, s[i][j], s);
	Traceback(s[i][j] + 1, j, s);
	cout << "Multiply A" << i << "," << s[i][j];
	cout << " and A" << (s[i][j] + 1) << "," << j << endl;
}

//�Դ˺���MatrixChain(int n, int **m, int **s, int *p)�ĽӿڵĶ�����иı�����Ǵ˺�������ͨ���ԣ�
// LookupChain(int i, int j, int **m, int **s, int *p);����Ӿ���i������j�������ǽ��������ڴӴӾ���1��n