#include<iostream>
#include "clique.h"
using namespace std;

class clique{
	friend void MaxClique(int **a, int v[], int n);//ע�⺯��������һ����������
public:
	clique();
private:
	void Backtrack(int i);
	int **a;//ͼG���ڽӾ���
	int n;//G�ж���ĸ���
	int  *x;//��ǰ��
	int *bestx;//��ǰ���Ž�
	int cn;//��ǰ�������
	int bestcn;//��ǰ��󶥵����
};


clique::clique(){

}

void clique::Backtrack(int i){//ע������㷨�Ǵ�0��ʼִ�е�
	if (i >= n){//�����еĽ��ı����0��1��2.....(n-1)
		for (int j = 0; j < n; j++){
			bestx[j] = x[j];
		}
		bestcn = cn;//�����Ƶ�����˼�룺ֻҪ
		return;
	}
	int OK = 1;
	for (int j = 0; j < i; j++){//���м�⣺��ǰ�����Ѿ�ѡ�뵽���еĽ���Ƿ�����
		if (x[j] && a[i][j] == 0){//��ǰ���i���Ѿ�ѡ��Ľ��jû������
			OK = 0;
			break;//����forѭ��
		}
	}
	if (OK){//��ǰ�����Ѿ�ѡ�����е�ÿ����㶼�����ӣ������ѡ��ý��
		x[i] = 1;//ѡ��ý��
		cn++;//��������һ
		Backtrack(i + 1);//���ݵ���һ��
		x[i] = 0;
		cn--;
	}
	if ((cn + n - i - 1)>bestcn){//��ǰ��㲻ѡ�뵽���У��˴������˼�֦������������ʽ������
		x[i] = 0;
		Backtrack(i + 1);
	}
}
