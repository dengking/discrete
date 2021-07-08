#include<iostream.h>
#include<queue> 
#include<utility>
using namespace std;
const int INF=100000000;

//状态
typedef pair<int,int> P;
//输入

const int N=10,M=10;

//表示迷宫的字符串的数组
char maze[N][M+1]={
	"#S######.#",
	"......#..#",	
	".#.##.##.#",	
	".#........",	
	"##.##.####",	
	"....#....#",	
	".#######.#",	
	"....#.....",	
	".####.###.",
	"....#...G#"
};

int sx=0,sy=1;//起点的坐标
int gx=9,gy=8;//终点的坐标
int d[N][M];//到各个位置的最短距离数组

//4个方向移动的向量
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

//求从(sx,sy)到(gx,gy)的最短距离
//如果无法到达则是INF
int bfs(){
	queue<P> que;
	//把所有的位置都初始化为INF
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			d[i][j]=INF;
		que.push(P(sx,sy));
		d[sx][sy]=0;
		//不断循环，直到队列的长度为0
		while(que.size()){
			//从队列的最前端取出元素
			P p=que.front();
			que.pop();
			//如果取出的状态已经是终点，则结束搜索
			if(p.first==gx&&p.second==gy)break;
			//四个方向的循环
			for(int i=0;i<4;i++){
				//移动之后的位置标记为(nx,ny)
				int nx=p.first+dx[i];
				int ny=p.second+dy[i];
				//判断是否可以移动到，是否已经访问过（d[nx][ny]!=INF就表示已经访问过了）
				if(0<=nx&&nx<N&&0<=ny&&ny<M&&maze[nx][ny]!='#'&&d[nx][ny]==INF){
					//可以移动的话，就加入到队列中，并且到该位置的距离确定为到p的距离+1
					que.push(P(nx,ny));
					d[nx][ny]=d[p.first][p.second]+1;
				}
			}
		}
		return d[gx][gy];
}
void solve(){
	int res=bfs();
	printf("%d\n",res);
}

int main(){
	solve();
	return 0;
}