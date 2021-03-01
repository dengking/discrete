#include<iostream>
#include<stdlib.h>
using namespace std;
int LISdyn(int b[],int a[],int n);
int maxL(int n,int b[]);

void main()
{
	int a[]={1,2,7,3,4,5,6,7,8,3,4};
	int b[11];
	int i=LISdyn(b,a,11);
	cout<<i;
}


int LISdyn(int b[],int a[],int n)
{
	int i,j,k;
	for(i=1,b[0]=1;i<n;i++)
	{
		for(j=0,k=0;j<i;j++)
		{
		  if(a[i]>=a[j]&&k<b[j])
			k=b[j];
		}
	   	 
	    b[i]=k+1;
	}
	return maxL(n,b);
}

int maxL(int n,int b[])
{
	for(int i=0,tmp=0;i<n;i++)
	{
		if(b[i]>tmp)
		  tmp=b[i];
	}
	return tmp;
}
