// HanoiTower.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <iostream>
using namespace std;
void Hanoi(int n, int a, int b, int c);//�˺�������������ǣ��ѷ���a�������n�����ӣ�ͨ��b�ƶ���c����


int main()
{
	Hanoi(3, 1, 2, 3);
	return 0;
}
void Hanoi(int n, int a, int b, int c)//�˺�������������ǣ��ѷ���a�������n�����ӣ�ͨ��b�ƶ���c����
{
//	if (n > 0){
		Hanoi(n - 1, a, c, b);
		cout << "Move " << n << " from " << a << " to " << c << endl;
		Hanoi(n - 1, b, a, c);
//	}
}


