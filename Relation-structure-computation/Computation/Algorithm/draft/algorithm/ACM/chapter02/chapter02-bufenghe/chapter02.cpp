#include<stdio.h>
#include<iostream.h>
#define MAX_N 100
//int a[MAX_N];
int a[4]={1,2,4,7};
int n,k;
//已经从前i项得到了和sum，然后对于i项之后的进行分支
bool dfs(int i,int sum){
	//如果前n项都计算过了，则返回sum是否和k相等
	if(i==n)return sum==k;//如果if条件成立，则函数就会执行return语句，下面的语句就不会被执行，它就会返回上一层的递归函数
	if(sum==k)return true;
	//不加上a[i]的情况
	if(dfs(i+1,sum))return true;//如果在这个分支中找到了解，则函数就会退出而不执行下面的语句
	//加上a[i]的情况
	if(dfs(i+1,sum+a[i]))return true;
	//无论是否加上a[i]都不能够凑成k就返回false
	return false;
}
void solve(){
	if(dfs(0,0))printf("Yes\n");
	else printf("No\n");
}

int main(){
	n=4;
	k=15;
	solve();
	return 0;
}
