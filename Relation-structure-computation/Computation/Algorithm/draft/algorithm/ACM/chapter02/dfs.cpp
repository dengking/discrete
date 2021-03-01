int n,k;
int a[MAX_N]
bool dfs(int i,int sum){
	if(i==n)return sum==k;
	if(dfs(i+1,sum)return true;
	if(dfs(i+1,sum+a[i]))return true;
	return false;
}

void solve(){
	if(dfs(0,0)printf("Yes\n");
	else printf("No\n");
}