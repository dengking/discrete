#include<iostream>
using namespace std;
const int MAX=100;
int main()
{
	int n;
	cout<<"Please input n:"<<' ';
	cin>>n;
	int *a=new int[n];
	for(int l=0;l<n;l++)
		a[l]=1;
	int *b=new int[n];
	for(int ll=0;ll<n;ll++)
		b[ll]=0;
	int u[MAX][MAX]={0};
	int c[MAX][MAX]={0};
	int v[MAX][MAX]={0};
	cout<<"Please input 0 or 1 to array u:\n";
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
			cin>>u[i][j];
	}
	cout<<"We get 图:\n";
	for(int h=0;h<n;h++)
	{
		for(int k=h+1;k<n;k++)
		{
			if(u[h][k]==1)
			cout<<'X'<<h<<"--"<<'X'<<k<<endl;
		}
	}
	cout<<"Please input 权:\n";
    for(int ii=0;ii<n;ii++)
	{
		for(int jj=ii+1;jj<n;jj++)
			if(u[ii][jj]==1)
			cin>>c[ii][jj];
	}
	cout<<"Now we begin:\n";
	int m;
	cout<<"请输入第一个顶点:\n";
	cin>>m;
	b[m]=1;
	int e=1;
	int counter=0;
	int flag[MAX][MAX]={0};
	int min;
	int f;
	for(e=1;e<n;e++)
	{
		f=0;
		for(int p=0;p<n;p++)
		{
			for(int q=0;q<n;q++)
			{
				if(u[p][q]==1&&b[p]==1&&a[q]==1)
				{
					min=c[p][q];
					flag[p][q]=++counter;
					f=1;
				}
			}
				if(f==1)
					break;
			
		}
		for(int pp=0;pp<n;pp++)
		{
			for(int qq=0;qq<n;qq++)
			{
				if(u[pp][qq]==1&&b[pp]==1&&a[qq]==1&&c[pp][qq]<min)
				{
					min=c[pp][qq];
				    flag[pp][qq]=++counter;
				}
			}
		}
		for(int s=0;s<n;s++)
		{
			for(int t=0;t<n;t++)
			{
				if(flag[s][t]==counter)
				{
					a[t]=0;
			        b[t]=1;
			        v[s][t]=1;
			        u[s][t]=0;
				}
			}
		}
	}
	int count=0;
	for(int s=0;s<n;s++)
	{
		if(b[s]==1)
			count++;
	}
	if(count==n)
	{
		cout<<"we get 最小权生成树:\n";
		int total=0;
	    for(int x=0;x<n;x++)
		{
			for(int y=x+1;y<n;y++)
			{
				if(v[x][y]==1)
				{
					cout<<'X'<<x<<"--"<<'X'<<y<<endl;
					total+=c[x][y];
				}
			}
		}
		cout<<"最小权和为:\n";
		cout<<total<<endl;
	}
	else
		cout<<"Sorry,最小权生成树不存在."<<endl;
		return 0;
}


