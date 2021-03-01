// Fibonacci.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
int Fibonacci(int n);


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Please input an integer ";
	int n;
	cin >> n;
	cout << Fibonacci(n);

	return 0;
}


int Fibonacci(int n)
{
	if (n <= 0)return 0;
	if (n==1)return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

