#include<iostream.h>
#include<queue> 
#include<utility>
using namespace std;
const int INF=100000000;

//״̬
typedef pair<int,int> P;
//����

const int N=10,M=10;

//��ʾ�Թ����ַ���������
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

int sx=0,sy=1;//��������
int gx=9,gy=8;//�յ������
int d[N][M];//������λ�õ���̾�������

//4�������ƶ�������
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

//���(sx,sy)��(gx,gy)����̾���
//����޷���������INF
int bfs(){
	queue<P> que;
	//�����е�λ�ö���ʼ��ΪINF
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			d[i][j]=INF;
		que.push(P(sx,sy));
		d[sx][sy]=0;
		//����ѭ����ֱ�����еĳ���Ϊ0
		while(que.size()){
			//�Ӷ��е���ǰ��ȡ��Ԫ��
			P p=que.front();
			que.pop();
			//���ȡ����״̬�Ѿ����յ㣬���������
			if(p.first==gx&&p.second==gy)break;
			//�ĸ������ѭ��
			for(int i=0;i<4;i++){
				//�ƶ�֮���λ�ñ��Ϊ(nx,ny)
				int nx=p.first+dx[i];
				int ny=p.second+dy[i];
				//�ж��Ƿ�����ƶ������Ƿ��Ѿ����ʹ���d[nx][ny]!=INF�ͱ�ʾ�Ѿ����ʹ��ˣ�
				if(0<=nx&&nx<N&&0<=ny&&ny<M&&maze[nx][ny]!='#'&&d[nx][ny]==INF){
					//�����ƶ��Ļ����ͼ��뵽�����У����ҵ���λ�õľ���ȷ��Ϊ��p�ľ���+1
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