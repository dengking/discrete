#include<iostream>
using namespace std;

int RandomizedSelect(int a[], int p, int r, int k);//Ԫ��ѡ�����⣺��������a�е�k���Ԫ�أ�p����ʼ�±꣬r����ֹ�±�
int RandomizedPartition(int a[], int p, int r);



int RandomizedSelect(int a[], int p, int r, int k){
	if (p == r)return a[p];//�������һ��Ԫ�أ����k���Ԫ�ؾ������Ԫ��
	int i = RandomizedPartition(a, p, r);//��������ض�a��Ԫ�ؽ��з��飬���ػ�׼���±�
	int j = i - p + 1;//��a[p]��a[i]�ĳ��ȣ���ʾ�ж��ٸ�Ԫ�ر�a[i]С
	if (k <= j)return RandomizedSelect(a, p, i, k);//���k��jҪС����k�϶�������i�����Ρ�ע��˴�ǧ��Ҫ�Ϳ�������ĺ������ֿ������˴�i����Ϊi���м�д��i-1.��Ϊ��Ҫ����ǵ�kС��Ԫ�أ�ǰ����ж�������k��=j�����k=j����ôa[i]��Ϊ����
	else return RandomizedSelect(a, i, k, k-j);
}

int RandomizedPartition(int a[], int p, int r){
	int i = Random(p, r);
	swap(a[i], a[p]);
	return Patiton(a, p, r);
}

