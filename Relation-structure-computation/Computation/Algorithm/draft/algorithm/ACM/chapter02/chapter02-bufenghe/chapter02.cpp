#include<stdio.h>
#include<iostream.h>
#define MAX_N 100
//int a[MAX_N];
int a[4]={1,2,4,7};
int n,k;
//�Ѿ���ǰi��õ��˺�sum��Ȼ�����i��֮��Ľ��з�֧
bool dfs(int i,int sum){
	//���ǰn�������ˣ��򷵻�sum�Ƿ��k���
	if(i==n)return sum==k;//���if���������������ͻ�ִ��return��䣬��������Ͳ��ᱻִ�У����ͻ᷵����һ��ĵݹ麯��
	if(sum==k)return true;
	//������a[i]�����
	if(dfs(i+1,sum))return true;//����������֧���ҵ��˽⣬�����ͻ��˳�����ִ����������
	//����a[i]�����
	if(dfs(i+1,sum+a[i]))return true;
	//�����Ƿ����a[i]�����ܹ��ճ�k�ͷ���false
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
