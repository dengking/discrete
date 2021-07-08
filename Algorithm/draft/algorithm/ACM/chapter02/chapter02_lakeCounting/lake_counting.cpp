#include<iostream.h>
//using namespace std;

const int N = 10;
const int M = 12;

//+����W,*����.
char garden[N][M+1] = {
	"+********++*",
		"*+++*****+++",
		"****++***++*",
		"*********++*",
		"*********+**",
		"**+******+**",
		"*+*+*****++*",
		"+*+*+*****+*",
		"*+*+******+*",
		"**+*******+*"
};

void dfs(int x, int y);

void solve() {
	int count = 0;
	for(int j=0; j<N; j++) {
		for(int i=0; i<M; i++){
			if(garden[j][i] == '+') {
				dfs(j, i);
				count ++;
			}
		}
	}
	cout << count << endl;
}

//��ǰ��λ����[y,x]
void dfs(int y, int x) {
	//���Ƚ���ǰ����Ľ��ı����Ϊ*����һ���Ƿǳ���Ҫ�ģ�����������ݹ��ʱ���ظ�����
	garden[y][x] = '*';
	//ѭ�������ƶ���8�����򣬿��������ڵĵ��Ƿ�Ҳ��+���ƶ��󵽴�(dy,dx)��
	for(int dy=y-1; dy<=y+1; dy++) {
		for(int dx=x-1; dx<=x+1; dx++) {
			if(dx >=0 && dy >= 0 && dx < M && dy < N && garden[dy][dx] == '+') {
				dfs(dy, dx);
			}
		}
	}
}

int main() {
	solve();
	return 0;
}