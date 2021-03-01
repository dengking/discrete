#include<iostream>
using namespace std;

const int max_size=6;
void MergeSort(int a[],int left,int right);
void Merge(int a[],int b[],int left,int m,int right);
void Copy(int a[],int b[],int left,int right);
int b[max_size];//=new int[max_size];


int main()
{
	int a[]={2,1,5,3,4,67,9};
	MergeSort(a,0,6);
    for(int i=0;i<=max_size;i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}

void MergeSort(int a[],int left,int right)//采用的是分治算法，排序的过程发生在函数Merge中，当归只是提供一种机制
{//算法的递归过程只是将a[]一分为二，直到待排序的集合中只有一个元素为止，然后不断合并排好序的数组段
	if(left<right){//当left=right时，即待排序的数组中只有一个元素的时候，就不用往下递归了，
		int i=(left+right)/2;
		MergeSort(a,left,i);
		MergeSort(a,i+1,right);
		Merge(a,b,left,i,right);//进行归并
		Copy(a,b,left,right);
	}
}

void Merge(int a[],int b[],int left,int m,int right)
{//合并a[left:i]和a[m+1:right]到b[left，right]
	int i=left,j=m+1,int k=left;//i是指向第一段的指针，j是指向第二段的指针，k原来作为数组b的下标
	while((i<=m)&&(j<=right)){//这个while循环原来把a[left:i]和a[m+1:right]中的数据按序放进数组b中
		if(a[i]<a[j]){         //注意循环的控制条件，把它翻译成自然语言就是：只要两段数组有一段放完了，那么另外一段是有序的，无需比较直接可以放进数组b中
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	if(i<=m){//i<=m说明导致跳出while循环的原因是j>right，即第二段已经完全放到b中了
		for(i;i<=m;i++)
			b[k++]=a[i];
	}
	else
	{
		for(j;j<=right;j++)
			b[k++]=a[j];
	}
}

void Copy(int a[],int b[],int left,int right){
	int i=left,k=left;
	while(i<=right){
		a[k++]=b[i++];
	}
}



		



