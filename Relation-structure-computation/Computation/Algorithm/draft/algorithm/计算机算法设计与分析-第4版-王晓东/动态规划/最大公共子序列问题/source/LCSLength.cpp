#include<iostream>
using namespace std;
void LCSLength(int m, int n, char *x, char *y, int **c, int **b);
/*参数解释如下：
  1.m表示序列x的长度
  2.n表示序列y的长度
  3.c是动态规划操作的表
  4.b则用来获得最终答案
  */

void LCS(int i, int j, char *x, int **b);
/*参数解释如下：
  1.i和j分别表示序列x和序列y的长度，显然x，y同时表示b的行和列
  2.x表示序列x，因为最终结果是它的子序列
  3.b表记录了最终解的来源*/


void LCSLength(int m, int n, char *x, char *y, int **c, int **b){
	int i, j;
	for (i = 1; i <= m; i++)c[i][0] = 0;
	for (i = 1; i <= n; i++)c[0][i] = 0;
	for (i = 1; i < m; i++){
		for (j = 1; j < n; j++){
			if (x[i] = y[j]){
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else {
				if (c[i - 1][j] >= c[i][j - 1]){
					c[i][j] = c[i - 1][j];
					b[i][j] = 2;
				}

				else{
					c[i][j] = c[i][j-1];
					b[i][j] = 3;
				}
			}

		}
	}
	
}

void LCS(int i, int j, char *x, int **b){
	if (i == j)return;
	if (b[i][j] = 1){
		LCS(i - 1, j - 1, x, b);
		cout << x[i];
	}
	else{
		if (b[i][j] == 2)LCS(i - 1, j, x, b);
		else LCS(i, j - 1, x, b);
	}
}