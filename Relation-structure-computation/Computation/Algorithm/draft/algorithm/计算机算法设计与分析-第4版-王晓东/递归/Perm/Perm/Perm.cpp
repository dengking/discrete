// Perm.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
using namespace std;

template<class Type>
void Perm(vector<Type>, int k, int n);//k��n�ֱ��ʾ���е���ʼλ�ú���ֹλ��

template<class Type>
void swap(Type &a, Type &b);

//ע�⣺�Գ������⣬��ο�visioͼ

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
void Perm(vector<Type> myvector, int k, int m)//k��n�ֱ��ʾ���е���ʼλ�ú���ֹλ��
{
	if (k == m){//listֻʣ��һ��Ԫ�أ�����ǰn-1���Ѿ��ź����ˣ������������£������Ѿ������
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


