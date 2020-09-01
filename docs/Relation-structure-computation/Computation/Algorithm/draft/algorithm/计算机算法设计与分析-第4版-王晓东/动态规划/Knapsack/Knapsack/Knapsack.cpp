#include<iostream>
using namespace std;

void Knapsack(int v[], int w[], int c, int n, int **m);//数组v记录的是物品的价值，数组w记录的是物品的重量，c记录的是背包的容量，n记录的是物品的总件数，m是二维数组
void Traceback(int **m, int w[], int v[], int n, int x[]);//此函数用来构造最优解，并用x数组带回




void Knapsack(int v[], int w[], int c, int n, int **m)//数组v记录的是物品的价值，数组w记录的是物品的重量，c记录的是背包的容量，n记录的是物品的总件数，m是二维数组
{
	int i = 0,j=0;
	int jMax = min(w[n] - 1, c);//当背包容量小于或等于jMax时，当前商品n是无法放进去的
	for (i = 0; i <= jMax; i++)m[n][i] = 0;//因为目前只考虑第n个商品，所以如果第n个商品无法放进背包，则价值显然为0
	for (i = jMax + 1; i <= c; i++)m[n][i] = v[n];//表示能够放下第n种物品
	for (i = n - 1; i > 1; i++){//此处i标识的是物品
		int jMax = min(w[i] - 1, c);//当背包容量小于或等于jMax时，当前商品i是无法放进去的
		for (j = 0; j <= jMax; j++)m[i][j] = m[i+1][j];//当前商品无法放进去，可以考虑从第i+1种到第n种物品的情况
		for (j = w[i]; j <= c; j++)
			m[i][j] = max{ m[i + 1][j], m[i + 1][j - w[i]] + v[i] };
	}
	m[1][c] = m[2][c];
	if (c >= w[1])m[1][c] = max{m[1][c], m[2][c - w[1]] + v[1] };

}