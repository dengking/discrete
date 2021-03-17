/*
递归关系：d[nx][ny]=min(d[nx]d[ny],d[x][y]+1)
尝试使用两种搜索策略来进行搜索
1.BFS 	
2.DFS 
*/

/***************BFS*********************/
const int INF 100000000;

//使用pare来表示状态
typedef pair<int,int> P;

//输入
char maze[MAX_N][MAX_N+1];//表示迷宫的字符串数组
int N,M;                  //迷宫大小
int sx,xy;                //起点坐标
int gx,gy;                //终点坐标
int d[MAX_N][MAX_N];      //到各个位置的最短距离

//四个方向移动的向量
int dx[4]={1,0,-1,1},dy[4]={0,1,0,-1};

//求从（sx，sy）到（gx，gy）的最短距离
int bfs(){
	//初始化d[MAX_N][MAX_N]
	for(int x=0;x<N;x++)
		for(int y=0;y<M;y++)
			d[x][y]=INF;
		queue<P> que;
	//将（sx，sy）作为初始状态加入到queue中
	que.push(P(sx,sy));
	d[sx][sy]=0;
	//进行搜索
	//不断循环直到队列长度为0
	while(que.size()){
		//从队列的最首端取出元素
		P p=que.front();
		que.pop();
		if(p.first==gx&&p.second==gy)
			break;
		//四个方向的循环
		for(int i=0;i<4;i++){
			int nx=p.first+dx[i];
			int ny=p.second+dy[i];
			//判断（nx，ny）是否为可扩充的点以及（nx，ny）是否已经扩充过（即判断d[nx][ny]?=INF
			if(0<=nx&&nx<=N&&0<=ny&&ny<M&&d[nx][ny]==INF){
				//可以移动的话，则加入到队列，并且到该位置的距离确定为p的距离加1
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

