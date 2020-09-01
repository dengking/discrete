#include<iostream>
using namespace std;

int RandomizedSelect(int a[], int p, int r, int k);//元素选择问题：查找序列a中第k大的元素，p是起始下标，r是终止下标
int RandomizedPartition(int a[], int p, int r);



int RandomizedSelect(int a[], int p, int r, int k){
	if (p == r)return a[p];//如果仅有一个元素，则第k大的元素就是这个元素
	int i = RandomizedPartition(a, p, r);//首先随机地对a中元素进行分组，返回基准的下标
	int j = i - p + 1;//从a[p]到a[i]的长度，表示有多少个元素比a[i]小
	if (k <= j)return RandomizedSelect(a, p, i, k);//如果k比j要小，则k肯定出现在i的左半段。注意此处千万要和快速排序的函数区分开来：此处i必须为i，切记写成i-1.因为需要求的是第k小的元素，前面的判断条件是k〈=j，如果k=j，那么a[i]即为所求
	else return RandomizedSelect(a, i, k, k-j);
}

int RandomizedPartition(int a[], int p, int r){
	int i = Random(p, r);
	swap(a[i], a[p]);
	return Patiton(a, p, r);
}

