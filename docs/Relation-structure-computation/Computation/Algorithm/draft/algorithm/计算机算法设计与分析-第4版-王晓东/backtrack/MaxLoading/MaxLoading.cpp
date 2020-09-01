#include<iostream>

class Loading{
public:
	Loading();
	friend int MaxLoading(int[], int, int);
private:
	void BackTrack(int i);
	int n;//
	int *w;////��װ�����������
	int *x;//��¼��
	int *bestx;//��¼���Ž�
	int c;//��һ�Ҵ���������
	int cw;//��¼��ǰֵ
	int bestw;//��¼��ǰ����ֵ
	int r=0;//��¼ʣ�༯װ�������
};


Loading::Loading(){
	for (int j = 0; j<n; j++){//ʣ��������ʼ��Ϊ��װ��������
		r += w[j];
	}
	bestw=cw = 0;
}

void Loading::BackTrack(int i){//�ڱ������У�i�Ǵ�0��ʼ��
	if (i >=n){
		if (cw > bestw){
			for (int j = 0; j < n; j++){
				bestx[j] = x[j];
				bestw = cw;
			}
		}
	}
	r -= w[i];
	if (cw + w[i] <= c){//����������
		x[i] = 1;
		cw += w[i];
		BackTrack(i + 1);
		x[i] = 1;
		cw -= w[i];
	}
	if (cw + r > bestw){//�˴�Ҳʹ���˼�֦��ֻ�е���֦��ʣ������ֵ�ȵ�ǰ����ֵ��ʱ�ŵ���֦ȥ����
		x[i] = 0;
		BackTrack(i + 1);
	}
	r += w[i];

}
