#include<iostream>
#include<stdlib.h>
using namespace std;
int LIS(int b[],int a[],int n);
int binary(int a[],int b[],int i,int k);

void main()
{
	int a[]={1,2,7,3,4,5,6,7,8,3,4};
	int b[11];
	int i=LIS(b,a,11);
	cout<<i;
}


int LIS(int b[],int a[],int n)
{
	b[1]=a[0];
	for(int i=1,k=1;i<n;i++)
	{
		if(a[i]>=b[k])
			b[++k]=a[i];
		else
			b[binary(a,b,i,k)]=a[i];
	}
	return k;
}

int binary(int a[],int b[],int i,int k)
{
	if(a[i]<b[1])
		return 1;
	for(int h=1,j=k;h!=j-1;)
	{
		if(b[k=(h+j)/2]<=a[i])
			h=k;
		else
			j=k;
	}
	return j;
}
