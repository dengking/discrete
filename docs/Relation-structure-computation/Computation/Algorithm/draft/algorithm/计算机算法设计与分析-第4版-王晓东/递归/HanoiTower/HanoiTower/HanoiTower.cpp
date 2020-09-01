// HanoiTower.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
using namespace std;
void Hanoi(int n, int a, int b, int c);//此函数解决的问题是：把放在a柱上面的n个盘子，通过b移动到c柱。


int _tmain(int argc, _TCHAR* argv[])
{
	Hanoi(2, 1, 2, 3);
	return 0;
}
void Hanoi(int n, int a, int b, int c)//此函数解决的问题是：把放在a柱上面的n个盘子，通过b移动到c柱。
{
	if (n > 0){
		Hanoi(n - 1, a, c, b);
		cout << "Move " << n << " from " << a << " to " << c << endl;
		Hanoi(n - 1, b, a, c);
	}
}


