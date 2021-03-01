/*
#include<stdio.h>
#include<iostream.h>
int k[10]={0,1,2,3,4,5,6,7,8,9};
int n=10;

bool binary_searchs(int x){
	//x的存在范围是k[l],k[l+1],.....,k[r-1]
	int l=0,r=n;
	//反复操作，直到存在范围为空
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
*/


