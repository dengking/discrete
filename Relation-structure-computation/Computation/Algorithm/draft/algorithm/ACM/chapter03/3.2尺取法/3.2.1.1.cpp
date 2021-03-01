//输入
int n,S;
int a[MAX_N];

void solve(){
	int res=n+1;//res即result，所记录的是最优值
	int s=0,t=0,sum=0;//s记录的是子序列的起始下标，t记录的是子序列的终止下标，sum记录的是子序列的和
	for(;;){
		while(t<n&&sum<S)//首先计算出比S要大的一个子串，这表示向右前进
			sum+=a[t++];
		if(sum<S)break;
		res=min(res,t-s);//t-s表示子序列的长度
		sum-=a[s++];//将sum-a[s],然后s自加，这表示左边缩进
	}
	if(res>n)//解不存在
	    res=0;
	printf("%d\n",res);
}
/*
尺取法的名字非常的形象，在数组上，使用s和t来标识尺子，按照一定的规则来动态地变化尺子的长度，从而尝试得到不同的解，这是一个小的技巧
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;
int a[200000];
int main()
{
//	freopen("in.txt","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(false);
	int n,max,sum,T;

	while(cin>>T)
	{
		while(T--)
		{
			cin>>n>>max;
			for(int i = 0 ; i < n ; i++)
				cin>>a[i];
			int i = 0,j = 0,sum = 0,ans = n+1;
			while(1)
			{
				while(j < n && sum <= max)
					sum += a[j++];
				
				if(sum < max)	break;
					ans = min(j-i,ans);
					sum -= a[i++];
			}
			if(ans > n)
				ans = 0;
			printf("%d\n",ans);
		}
	}
	return 0;
}