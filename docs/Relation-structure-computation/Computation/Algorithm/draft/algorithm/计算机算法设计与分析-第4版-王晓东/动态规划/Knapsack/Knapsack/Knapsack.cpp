#include<iostream>
using namespace std;

void Knapsack(int v[], int w[], int c, int n, int **m);//����v��¼������Ʒ�ļ�ֵ������w��¼������Ʒ��������c��¼���Ǳ�����������n��¼������Ʒ���ܼ�����m�Ƕ�ά����
void Traceback(int **m, int w[], int v[], int n, int x[]);//�˺��������������Ž⣬����x�������




void Knapsack(int v[], int w[], int c, int n, int **m)//����v��¼������Ʒ�ļ�ֵ������w��¼������Ʒ��������c��¼���Ǳ�����������n��¼������Ʒ���ܼ�����m�Ƕ�ά����
{
	int i = 0,j=0;
	int jMax = min(w[n] - 1, c);//����������С�ڻ����jMaxʱ����ǰ��Ʒn���޷��Ž�ȥ��
	for (i = 0; i <= jMax; i++)m[n][i] = 0;//��ΪĿǰֻ���ǵ�n����Ʒ�����������n����Ʒ�޷��Ž����������ֵ��ȻΪ0
	for (i = jMax + 1; i <= c; i++)m[n][i] = v[n];//��ʾ�ܹ����µ�n����Ʒ
	for (i = n - 1; i > 1; i++){//�˴�i��ʶ������Ʒ
		int jMax = min(w[i] - 1, c);//����������С�ڻ����jMaxʱ����ǰ��Ʒi���޷��Ž�ȥ��
		for (j = 0; j <= jMax; j++)m[i][j] = m[i+1][j];//��ǰ��Ʒ�޷��Ž�ȥ�����Կ��Ǵӵ�i+1�ֵ���n����Ʒ�����
		for (j = w[i]; j <= c; j++)
			m[i][j] = max{ m[i + 1][j], m[i + 1][j - w[i]] + v[i] };
	}
	m[1][c] = m[2][c];
	if (c >= w[1])m[1][c] = max{m[1][c], m[2][c - w[1]] + v[1] };

}