vector<int> G[MAX_N]
define MAX_N 1000
int N;//the number of node
int color[MAX_N];

//this function attemp to color the vetex v with the color c
//it will check whethe c is the same as all the color of the vetex that is adjacent to v 
//
bool dfs(int v,int c){
	color[v]=c;
	for(int i=0;i<G[v].size();i++){
		if(color(G[v][i])==c)return false;
		if(color(G[v][i])==0&&!dfs(G[v][i],-c))//attach -c color for the node that is adjacent to v,because this is recursion call,so this is deepth first search
			return false;
	}
	return true;
}

void solve(){
	for(int i=0;i<N;i++){
		if(color[i]==0)
			if(!dfs(i,1)){
				printf("No\n");
				return;
			}
	}
	printf("Yes\n");
}