//����
int n,S;
int a[MAX_N];

void solve(){
	int res=n+1;//res��result������¼��������ֵ
	int s=0,t=0,sum=0;//s��¼���������е���ʼ�±꣬t��¼���������е���ֹ�±꣬sum��¼���������еĺ�
	for(;;){
		while(t<n&&sum<S)//���ȼ������SҪ���һ���Ӵ������ʾ����ǰ��
			sum+=a[t++];
		if(sum<S)break;
		res=min(res,t-s);//t-s��ʾ�����еĳ���
		sum-=a[s++];//��sum-a[s],Ȼ��s�Լӣ����ʾ�������
	}
	if(res>n)//�ⲻ����
	    res=0;
	printf("%d\n",res);
}
/*
��ȡ�������ַǳ��������������ϣ�ʹ��s��t����ʶ���ӣ�����һ���Ĺ�������̬�ر仯���ӵĳ��ȣ��Ӷ����Եõ���ͬ�Ľ⣬����һ��С�ļ���
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