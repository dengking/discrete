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

void MergeSort(int a[],int left,int right)//���õ��Ƿ����㷨������Ĺ��̷����ں���Merge�У�����ֻ���ṩһ�ֻ���
{//�㷨�ĵݹ����ֻ�ǽ�a[]һ��Ϊ����ֱ��������ļ�����ֻ��һ��Ԫ��Ϊֹ��Ȼ�󲻶Ϻϲ��ź���������
	if(left<right){//��left=rightʱ�����������������ֻ��һ��Ԫ�ص�ʱ�򣬾Ͳ������µݹ��ˣ�
		int i=(left+right)/2;
		MergeSort(a,left,i);
		MergeSort(a,i+1,right);
		Merge(a,b,left,i,right);//���й鲢
		Copy(a,b,left,right);
	}
}

void Merge(int a[],int b[],int left,int m,int right)
{//�ϲ�a[left:i]��a[m+1:right]��b[left��right]
	int i=left,j=m+1,int k=left;//i��ָ���һ�ε�ָ�룬j��ָ��ڶ��ε�ָ�룬kԭ����Ϊ����b���±�
	while((i<=m)&&(j<=right)){//���whileѭ��ԭ����a[left:i]��a[m+1:right]�е����ݰ���Ž�����b��
		if(a[i]<a[j]){         //ע��ѭ���Ŀ��������������������Ȼ���Ծ��ǣ�ֻҪ����������һ�η����ˣ���ô����һ��������ģ�����Ƚ�ֱ�ӿ��ԷŽ�����b��
			b[k++]=a[i++];
		}
		else
		{
			b[k++]=a[j++];
		}
	}
	if(i<=m){//i<=m˵����������whileѭ����ԭ����j>right�����ڶ����Ѿ���ȫ�ŵ�b����
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



		



