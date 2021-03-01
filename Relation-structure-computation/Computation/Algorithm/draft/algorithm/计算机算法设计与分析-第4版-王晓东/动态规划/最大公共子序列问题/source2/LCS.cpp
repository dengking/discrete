#include<iostream>
//#include
using namespace std;
const int L = 7;
void LCSLength(int m, int n, char* x, char* y, int** c, int** b);

void main()
{
	
	int **optimal = new int *[L];
	int **optimal_structure = new int *[L];
	for (int i = 0; i<L; i++)
	{
		optimal[i] = new int[L];
		optimal_structure[i] = new int[L];
	}
	char a[] = { 'A', 'B', 'C', 'C', 'E','F' };
	char b[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
	LCSLength(7, 7, a, b, optimal, optimal_structure);
	for (int i = 0; i < 7; i++)
	for (int j = 0; j < 7; j++)
	{
		cout << optimal[i][j];
		
	}

}

void LCSLength(int m, int n, char* x, char* y, int** c, int** b)
{
	int i, j;
	for (i = 0; i < m; i++)
		c[i][0] = 0;
	for (j = 0; j < n; j++)
		c[0][j] = 0;
	for (i = 1; i < m;i++)
	for (j = 1; j < n;j++)
	if (x[i] == y[j])
	{
		c[i][j] = c[i - 1][j - 1] + 1;
		b[i][j] = 1;
	}
	else
	{
		if (c[i][j - 1] >= c[i - 1][j])
		{
			c[i][j] = c[i][j - 1];
			b[i][j] = 2;
		}
		else
		{
			c[i][j] = c[i - 1][j];
			b[i][i] = 3;
		}
	}



}