#include<iostream>
using namespace std; 

void  QuickSort(int a[], int start, int end);//���㷨���õ��Ƿ��β��ԣ�divide����a�ֳ�����a[start]< a[start],<a[start];,conquer: �ݹ���������ֶ�
int Pation(int a[], int start, int end);//��a���л��֣���a[start]��Ϊ��׼�����л��ֺ�a[start]��ߵ�Ԫ�ض�����С���ұߵ�Ԫ�ض�������
void Swap(int &x, int &y);


void  QuickSort(int a[], int start, int end){
	if (start < end){
		int j = Pation(a, start, end);//j�ǻ�׼Ԫ�ص����±�
		QuickSort(a, start, j - 1);
		QuickSort(a, j+1, end);
	}
}

int Pation(int a[], int start, int end){
	int i = start, j = end + 1;//iָ������ͷ��jָ������β
	int x = a[start];//x�ǻ�׼
	while (true){
		while (a[++i] < x&&i < end);//ֱ��a[i]��=x������ѭ������ʱ������Ҫ�����û���
		while (a[--j]>x);//ֱ��a[j]��=x������ѭ������ʱ������Ҫ�����û���
		if (i >= j)break;//���Ǳ�ѭ���˳���Ψһ;����ѭ���˳�ʱ��iָ������Ҷεĵ�һ��Ԫ�أ�jָ�������ε����һ��Ԫ�أ���Ȼ��x����Ҫ����������Ԫ��֮��
		Swap(a[i], a[j]);//ע�����䰲�ŵ�˳���Լ��������ŵ�ԭ��ֻ�е�һ��while�͵ڶ���while���˳���ʱ�򣬲ſ��ܽ����û�
	}
	a[start] = a[j];//
	a[j] = x;//�ѻ�׼������ȷ��λ��
	return j;
}

void Swap(int &x, int &y){
	int z = x;
	x = y;
	y = z;
}

