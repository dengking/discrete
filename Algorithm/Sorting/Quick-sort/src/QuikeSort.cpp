#include<iostream>
using namespace std; 

void  QuickSort(int a[], int start, int end);//此算法采用的是分治策略，divide：将a分成三段a[start]< a[start],<a[start];,conquer: 递归地求解各个字段
int Pation(int a[], int start, int end);//对a进行划分，以a[start]作为基准，进行划分后a[start]左边的元素都比它小，右边的元素都比它大
void Swap(int &x, int &y);


void  QuickSort(int a[], int start, int end){
	if (start < end){
		int j = Pation(a, start, end);//j是基准元素的新下标
		QuickSort(a, start, j - 1);
		QuickSort(a, j+1, end);
	}
}

int Pation(int a[], int start, int end){
	int i = start, j = end + 1;//i指向数组头，j指向数组尾
	int x = a[start];//x是基准
	while (true){
		while (a[++i] < x&&i < end);//直到a[i]〉=x才跳出循环，这时候是需要进行置换的
		while (a[--j]>x);//直到a[j]〈=x才跳出循环，这时候是需要进行置换的
		if (i >= j)break;//这是本循环退出的唯一途径，循环退出时，i指向的是右段的第一个元素，j指向的是左段的最后一个元素，显然，x最终要插在这两个元素之间
		Swap(a[i], a[j]);//注意此语句安排的顺序以及这样安排的原因：只有第一个while和第二个while都退出的时候，才可能进行置换
	}
	a[start] = a[j];//
	a[j] = x;//把基准插在正确的位置
	return j;
}

void Swap(int &x, int &y){
	int z = x;
	x = y;
	y = z;
}

