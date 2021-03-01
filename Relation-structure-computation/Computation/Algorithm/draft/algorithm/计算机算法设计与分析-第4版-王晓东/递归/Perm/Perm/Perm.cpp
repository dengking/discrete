// Perm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;

template<class Type>
void Perm(vector<Type>, int k, int n);//k和n分别表示排列的起始位置和终止位置

template<class Type>
void swap(Type &a, Type &b);

//注意：对程序的理解，请参考visio图

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> myvector;
	cout << "Please input an interger ";
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		myvector.push_back(i);
	}
	Perm(myvector, 0, n - 1);
	return 0;
}

template<class Type>
void Perm(vector<Type> myvector, int k, int m)//k和n分别表示排列的起始位置和终止位置
{
	if (k == m){//list只剩下一个元素，由于前n-1个已经排好序了，因此这种情况下，排序已经完成了
		for (int i = 0; i <= m; i++){
			cout << myvector.at(i);
			cout << endl;
		}
	}
	else{
		for (int i = k; i <= m; i++){
			swap(myvector[i], myvector[k]);
			Perm(myvector, k + 1, m);
			swap(myvector[i], myvector[k]);
			//swap(myvector.at(i), myvector.at(k));
		}
	}
}

template<class Type>
void swap(Type &a, Type &b)
{
	Type temp = a;
	a = b;
	b=temp;
}


