//�����Сֵ����С�����ֵ
int M;//M��ţ����Ŀ
int N;//N��ţ�����Ŀ
int X[MAX_N];//ţ���λ��

//����̰���㷨���ж��ܷ����е�Mͷţ���ŵ�ţ���У����ұ�֤������ͷţ֮��ļ���ǲ�С��d��
bool C(int d){
	int last=0;//ǰһͷţ
	for(int i=1;i<M;i++){
		int crt=last+1;//�ڶ�ͷţ
		while(crt<N&&x[crt]-x[last]<d)//Ϊ��crtͷţ����ţ��
			crt++;
		if(crt==N)return false;//ѭ���˳���ԭ����crt<N,��ʾ���������е�ţ�ᣬ��û���ҵ�����������ţ��
		last=crt;//���е���
	}
	return true;
}

void solve(){
	sort(x,x+N);
	//��ʼ����Ĵ��ڷ�Χ
	while(ub-lb>1){
		int mid=(ub+lb)/2;
		if(C(mid))lb=mid;
		else ub=mid;
	}
	printf("%d\n",lb);
}
