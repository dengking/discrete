#include<iostream>
using namespace std;
void LCSLength(int m, int n, char *x, char *y, int **c, int **b);
/*�����������£�
  1.m��ʾ����x�ĳ���
  2.n��ʾ����y�ĳ���
  3.c�Ƕ�̬�滮�����ı�
  4.b������������մ�
  */

void LCS(int i, int j, char *x, int **b);
/*�����������£�
  1.i��j�ֱ��ʾ����x������y�ĳ��ȣ���Ȼx��yͬʱ��ʾb���к���
  2.x��ʾ����x����Ϊ���ս��������������
  3.b���¼�����ս����Դ*/


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