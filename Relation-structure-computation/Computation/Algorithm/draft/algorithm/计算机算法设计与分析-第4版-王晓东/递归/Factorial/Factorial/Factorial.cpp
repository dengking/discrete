// Factorial.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
int Factorial(int n);




int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Please enter an interge ";
	int n;
	cin >> n;
	Factorial(n);
	return 0;
}
int Factorial(int n)
{
	if (n <= 0)return 1;
	return n*Factorial(n - 1);
}

