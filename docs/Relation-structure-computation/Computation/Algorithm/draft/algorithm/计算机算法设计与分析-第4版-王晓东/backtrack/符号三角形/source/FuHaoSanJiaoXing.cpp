class Triangle{
	friend int Compute(int);
private:
	void Backtrack(int t);
	int n,//��һ�з��Ÿ���
		half,//half=n*��n+1��/2�������ս���С�+���ĸ���
		count,//��ǰ��+���ĸ���
		**p;//���������ξ���
	long sum;//�Ѿ��ҵ��ķ��������������εĸ���
};

void Triangle::Backtrack(int t){
	if (count > half || t*(t - 1) / 2 - count > half)return;//������Ѿ�ȷ����t-1���������У���+����-���ĸ�������half������Ȼ�����ܰ������н⣬����ֱ�Ӽ���
	if (t > n)sum++;//���԰����ս�������
	else{
		for (int i = 0; i < 2; i++){//ÿ����ǰ��չ������ȡ����ֵ0��1ȡ0��ʾ��-����ȡ1��ʾ��+��
			p[1][t] = i;//�Ե�һ�н��и�ֵ
			count += i;
			for (int j = 2; j <= t; j++){//����б�߷����������½�����ֵ
				p[j][t - j + 1] = p[j - 1][t - j + 1] * p[j - 1][t - j + 2];
				count += p[j][t - j + 1];
			}
			Backtrack(t + 1);
			for (int j = 2; j <= t; j++){//��������лع�
				count -= p[j][t - j + 1];
			}
			count -= i;
		}
	}
    
}