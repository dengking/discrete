#include<iostream>
using namespace std;

void MergeSort(int a[],int n);//a是待排序数组，n是数组a的长度
void Merge(int a[],int b[],int left,int m,int right);
void MergePass(int a[],int b[],int s,int n);//a是待排序数组，n是数组a的长度,s是子段的长度，此函数把部分有序的序列放到了数组b中










void MergeSort(int a[],int n)//a是待排序数组，n是数组a的长度
{
	int *b=new int[n];
	int s=1;//s定义的是子段的长度，初始时，子段长度为1，则自然有序
	while(s<n){
		MergePass(a,b,s,n);//合并到数组b中
		s+=s;
		MergePass(b,a,s,n);
		s+=s;
	}
}


void MergePass(int a[],int b[],int s,int n)//a是待排序数组，n是数组a的长度,s是子段的长度，此函数把部分有序的序列放到了数组b中
{
	int i=0;
	while(i<=n-2*s){//此循环能够使循环次数k满足k*（2*s）<=n的k取到最大值。
		//它实现这个控制的思路是按照逆向思维方式：n-2*s标识的是使数组剩余2*s长度的起始下标，显然一旦i超过了这个值，则while中按照2*s为单位进行排序就是不合法的，所以要跳出循环
		Merge(a,b,i,i+s-1,i+2*s-1);//注意对于这个过程的理解请参考文档
		i=i+2*s;
	}//只有当i>n-2*s才弹出循环
	if(i+s<n){//也就是剩余的子段的长度比s要大
		Merge(a,b,i,i+s-1,n-1);//注意对于这个过程的理解请参考文档
	}
	else
	{
		for(int k=i;i<n;i++){
			b[k++]=a[i];
		}
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
