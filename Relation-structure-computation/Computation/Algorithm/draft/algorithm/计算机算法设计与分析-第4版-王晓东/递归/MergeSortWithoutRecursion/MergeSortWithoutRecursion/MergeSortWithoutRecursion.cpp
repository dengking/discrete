#include<iostream>
using namespace std;

void MergeSort(int a[],int n);//a�Ǵ��������飬n������a�ĳ���
void Merge(int a[],int b[],int left,int m,int right);
void MergePass(int a[],int b[],int s,int n);//a�Ǵ��������飬n������a�ĳ���,s���Ӷεĳ��ȣ��˺����Ѳ�����������зŵ�������b��










void MergeSort(int a[],int n)//a�Ǵ��������飬n������a�ĳ���
{
	int *b=new int[n];
	int s=1;//s��������Ӷεĳ��ȣ���ʼʱ���Ӷγ���Ϊ1������Ȼ����
	while(s<n){
		MergePass(a,b,s,n);//�ϲ�������b��
		s+=s;
		MergePass(b,a,s,n);
		s+=s;
	}
}


void MergePass(int a[],int b[],int s,int n)//a�Ǵ��������飬n������a�ĳ���,s���Ӷεĳ��ȣ��˺����Ѳ�����������зŵ�������b��
{
	int i=0;
	while(i<=n-2*s){//��ѭ���ܹ�ʹѭ������k����k*��2*s��<=n��kȡ�����ֵ��
		//��ʵ��������Ƶ�˼·�ǰ�������˼ά��ʽ��n-2*s��ʶ����ʹ����ʣ��2*s���ȵ���ʼ�±꣬��Ȼһ��i���������ֵ����while�а���2*sΪ��λ����������ǲ��Ϸ��ģ�����Ҫ����ѭ��
		Merge(a,b,i,i+s-1,i+2*s-1);//ע�����������̵������ο��ĵ�
		i=i+2*s;
	}//ֻ�е�i>n-2*s�ŵ���ѭ��
	if(i+s<n){//Ҳ����ʣ����Ӷεĳ��ȱ�sҪ��
		Merge(a,b,i,i+s-1,n-1);//ע�����������̵������ο��ĵ�
	}
	else
	{
		for(int k=i;i<n;i++){
			b[k++]=a[i];
		}
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
