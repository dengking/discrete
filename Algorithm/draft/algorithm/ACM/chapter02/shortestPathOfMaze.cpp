/*
�ݹ��ϵ��d[nx][ny]=min(d[nx]d[ny],d[x][y]+1)
����ʹ������������������������
1.BFS 	
2.DFS 
*/

/***************BFS*********************/
const int INF 100000000;

//ʹ��pare����ʾ״̬
typedef pair<int,int> P;

//����
char maze[MAX_N][MAX_N+1];//��ʾ�Թ����ַ�������
int N,M;                  //�Թ���С
int sx,xy;                //�������
int gx,gy;                //�յ�����
int d[MAX_N][MAX_N];      //������λ�õ���̾���

//�ĸ������ƶ�������
int dx[4]={1,0,-1,1},dy[4]={0,1,0,-1};

//��ӣ�sx��sy������gx��gy������̾���
int bfs(){
	//��ʼ��d[MAX_N][MAX_N]
	for(int x=0;x<N;x++)
		for(int y=0;y<M;y++)
			d[x][y]=INF;
		queue<P> que;
	//����sx��sy����Ϊ��ʼ״̬���뵽queue��
	que.push(P(sx,sy));
	d[sx][sy]=0;
	//��������
	//����ѭ��ֱ�����г���Ϊ0
	while(que.size()){
		//�Ӷ��е����׶�ȡ��Ԫ��
		P p=que.front();
		que.pop();
		if(p.first==gx&&p.second==gy)
			break;
		//�ĸ������ѭ��
		for(int i=0;i<4;i++){
			int nx=p.first+dx[i];
			int ny=p.second+dy[i];
			//�жϣ�nx��ny���Ƿ�Ϊ������ĵ��Լ���nx��ny���Ƿ��Ѿ�����������ж�d[nx][ny]?=INF
			if(0<=nx&&nx<=N&&0<=ny&&ny<M&&d[nx][ny]==INF){
				//�����ƶ��Ļ�������뵽���У����ҵ���λ�õľ���ȷ��Ϊp�ľ����1
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

