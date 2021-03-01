#include<iostream>
#include<stdlib.h>
using namespace std;


int bs(int a[],int n,const int& x,int &i,int&j);

void main()
{
	int a[8]={1,2,3,4,6,7,8,9};
	int left,right;
	int i=bs(a,8,10,left,right);
	cout<<i<<' '<<left<<' '<<right<<endl;
	i=bs(a,8,6,left,right);
	cout<<i<<' '<<left<<' '<<right<<endl;
}


int bs(int a[],int n,const int& x,int &i,int&j)
{
	int middle;
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		middle=(left+right)/2;
		if(a[middle]==x)
		{
			i=j=middle;
			return 1;
		}
		if(a[middle]<x)
			left=middle+1;
		else
			right=middle-1;
	}
	i=right;
	j=left;
	return 0;
}