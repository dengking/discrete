#include<stdio.h>
#include<iostream.h>
int k[10]={1,3,5};
int n=3;
int m=10;

bool binary_search(int x){
	//x�Ĵ��ڷ�Χ��k[l],k[l+1],.....,k[r-1]
	int l=0,r=n;
	//����������ֱ�����ڷ�ΧΪ��
	int i=1;
	while(r-l>=1){
		cout<<"-----iteration:"<<i<<"-----"<<endl;
		int d=r-l;
		int middle=(r+l)/2;
		cout<<"left"<<l<<endl;
		cout<<"right="<<r<<endl;
		cout<<"middle="<<middle<<endl;
		cout<<"k["<<middle<<"]="<<k[middle]<<endl;
		if(k[middle]==x){
			return true;
		}
		else if(k[middle]<x)l=middle+1;
		else r=middle;
		cout<<"-----iteration:"<<i++<<"-----"<<endl;

	}
	return false;
}


void solve(){
	//Ϊ��ִ�ж��ֲ�����Ҫ������
//	sort(k,k+n);
	bool f=false;
	for(int a=0;a<n;a++)
		for(int b=0;b<n;b++)
			for(int c=0;c<n;c++){
				if(binary_search(m-k[a]-k[b]-k[c]))
					f=true;
			}
	if(f)puts("Yse\n");
	else puts("No\n");
}

int main(){
	solve();
	return 0;
}
