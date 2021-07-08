#include<iostream.h>
//using namespace std;

const int N = 10;
const int M = 12;

//+代表W,*代表.
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

//当前的位置是[y,x]
void dfs(int y, int x) {
	//首先将当前处理的结点的编号置为*，这一步是非常重要的，它避免后续递归的时候重复处理
	garden[y][x] = '*';
	//循环遍历移动的8个方向，看与它相邻的点是否也是+，移动后到达(dy,dx)处
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