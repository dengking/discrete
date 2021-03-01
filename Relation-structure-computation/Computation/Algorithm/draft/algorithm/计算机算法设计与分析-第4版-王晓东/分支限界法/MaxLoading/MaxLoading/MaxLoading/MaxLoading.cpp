
template<class Type>
class QNode{
	friend EnQueue(Queue<QNode<Type> *>&Q, Type wt, int i, int n, Type bestw, QNode<Type> *E, QNode<Type> *&bestE, int bestx[], bool ch);
	/*�����������Ĳ������ͣ�
	1.Q��Ϊ�������
	2.wt��ʾ��ǰ��������ע�������ۼ�ֵ
	3.i��ʾ�ý�������Ĳ�Σ�n��ʾ����Ĺ�ģ,��i==nʱ��������������������
	4.bestw��ʾ��ǰ���Ž�
	5.E��ʾ��ǰ���ĸ����
	6.bestE�����Ž�·���ϵ����һ�����
	7.bestx�������Ž⣬����Ԫ�ص�ȡֵΪ0��1
	8.ch��ʾ��ǰ��������ӽ�㻹�����ӽ�㣬���Ϊ���ӽ����ȡֵΪ1������Ϊ0
	*/
	friend MaxLoading(Type w[], Type c, int n, int bestX[]);
	/*�����������£�
	1.w[]����Ʒ����������
	2.c�ǵ�һ�һ�����������
	3.n�ǻ��������
	4.bestX[]Ϊ���ս�
	*/
private:
	QNode *parent;//ָ�򸸽���ָ��
	bool LChild;//����ӱ�־
	Type weight;//�����Ӧ��������

};

template<class Type>
void EnQueue(Queue<QNode<Type> *>&Q,
	Type wt,
	int i,
	int n,
	Type bestw,
	QNode<Type> *E,
	QNode<Type> *&bestE,
	int bestx[],
	bool ch){
	if (i == n){//�Ѿ�������Ҷ�ӽ�㣬���Ѿ��õ�������������ˣ�ע�������Ĳ���Ǵ�1��ʼ��
		if (wt == bestw){
			bestE = E;//ע��͵õ���������·����β��㣬�൱��ͷָ��
			bestx[n] = ch;//�˴��Ѿ�������������һ��Ԫ�ؼ�¼��
			return;
		}
	}
	//��������Ļ�����ʾ�������Ƿ�Ҷ�ӽ�㣬
	QNode<Type> *b;//��̬�Ĺ���һ�����
	b = new QNode<Type>;
	b->weight = wt;//Ȩ��
	b->parent = E;//parent��¼��ĸ���
	b->LChild = ch;
	Q.Add(b);//��b���b���뵽�������Q��

}

template<class Type>
Type MaxLoading(Type w[], Type c, int n, int bestx[]){
	Queue<QNode<Type>*> Q;//�������
	Q.Add(0);//ͬ����β����־�������־�ǳ���Ҫ
	int i = 0;//��������ڵĲ�
	Type Ew = 0,//��չ�������Ӧ����������wt���ۼ�ֵ,ע������֮�����ϵ��ÿ�����㶼��һ��Ewֵ������������Ϊ��չ���ʱ����ô������չ���ɵ����ӽ���EwֵΪ��ǰ��չ����Ewֵ���ϵ�ǰ�������������ӽ���Ewֵ�͸�ĸ����Ewֵ���
		bestw = 0,//��ǰ����������
		r = 0;//ʣ�༯װ������
	for (int j = 2; j <= n; j++){
		r += w[j];//��ʼ��r����Ϊ��ǰ��չ���Ϊ����㣬����ʣ�༯װ�������������w[1]
	}
	QNode *E = 0,//��ʾ��ǰ��չ���
		*bestE = 0;//��ǰ������չ���
	while (true){
		//�������ӽ��
		Type wt = Ew + w[i];
		if (wt < c){//��ǰ����bestw��ֵ
			if (wt>bestw)
				bestw = wt;
			EnQueue(Q, wt, i, n, bestw, E, bestE, bestx, true);
		}
		//������ӽ�㣬ע����������������м�֦
		if (Ew + r > bestw)
			EnQueue(Q, Ew, i, n, bestw, E, bestE, bestx, false);
		Q.Delete(E);//ȡ��һ����չ���
		if (!E){//����Ƿ񵽴�ͬ����β��
			if (Q.IsEmpty())break;//�������Ϊ�գ����Ѿ��������������⣬�����˳���
			Q.Add(0);//���ͬ��β����ʶ
			Q.Delete(E);//ȡ��һ����չ���
			i++;//������һ��
			r -= w[i];
		}
		Ew = E->weight;//����չ�������Ӧ��������
	}
	//���쵱ǰ���Ž�
	for (int j = n - 1; j > 0; j--){
		bestx[j] = bestE->LChild;//LChild��bool���͵ģ�0��ʾ�ý�����Ҷ��ӣ�1��ʾ�ý��������ӣ������ú����ս���ĳ��Ԫ��ѡ���ѡ���Ӧ���ǳ����
		bestE = bestE->parent;
	}
	return bestw;
}
