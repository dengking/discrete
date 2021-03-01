template<class Type>
class bbnode{
	friend void AddLiveNode(MaxHeap<HeapNode<int>> &H, bbnode *E, Type wt, bool ch, int lev);//�˺����Ĺ�������ǰ���EnQueue����
	/*�Ըú����Ĳ����������£�
	1.H�����ѣ����ǻ������ȶ��У�����ÿ��Ԫ�ص�������HeapNode���͵�
	2.bbnode�������еĽ�㣬���ǵ�ǰ����ĸ�ĸ���
	3.wt�ĺ�����ڶ���ʽ�еĺ����ǲ���ͬ�ģ�wt�����Զѽ���uweight����и�ֵ����������ѽ������ȼ�
	4.ch������ʶ���Һ��ӽ��
	5.lev��ʾ��ǰ������ڵĲ��
	*/
	friend int MaxLoading(int w[], int c, int n, int bestx[]);
	/*�����������£�
	1.w[]��ʾ�������������
	2.c��ʾ��һ�һ�����������
	3.n��ʾһ����n������
	4.bestx[]��ʾ���Ž�
	*/
private:
	bbnode *parent;//ָ�򸸽���ָ��
	bool LChilde;//��ʶ�˽���Ƿ�Ϊ����
};	

template<class Type>
class HeapNode{
	friend void AddLiveNode(MaxHeap<HeapNode<Type>> &H, bbnode *E, Type wt, bool ch, int lev);//�˺����Ĺ�������ǰ���EnQueue����
	friend int MaxLoading(int w[], int c, int n, int bestx[]);
public:
	operator Type()const{ return uweight; }
private:
	bbnode *ptr;//ָ��������Ӽ�������Ӧ����ָ�룬ͨ�����ָ���һ��HeapNode��bbnode��ϵ������
	Type uweight;//�������ȼ�
	int level;//�������Ӽ����������Ĳ����
};


template<class Type>
void AddLiveNode(MaxHeap<HeapNode<Type>> &H, bbnode *E, Type wt, bool ch, int lev){
	/*�˺����Ĺ���:
	1.�����²����Ļ���
	2.������½����뵽�������ȶ�����*/
	bbnode *b = new bbnode;
	b->parent = E;
	b->LChild = ch;
	HeapNode<Type> N;
	N.uweight = wt;
	N.level = lev;
	N.ptr = b;//��һ��HeapNode��bbnode��ϵ������
	H.insert(N);
}

template<class Type>
int MaxLoading(int w[], int c, int n, int bestx[]){
	MaxHeap<HeapNode<Type>> H(1000);
	//����ʣ��������������
	Type *r = new Type[n + 1];
	r[n] = 0;
	for (int j = n - 1; j > 0; j--){//�����󷨺Ͷ�̬�滮��˼���Ƿǳ����ϵ�
		r[j] = r[j + 1] + w[j + 1];
	}
	//��ʼ��
	int i = 1;//��ǰ����չ����Ǹ��ڵ㣬���ڵ�һ��
	bbnode *E = 0;
	Type Ew = 0;//��ǰ��չ�������Ӧ��������
	//�����ӿռ���
	while (i != n + 1){
		//��鵱ǰ��չ���Ķ��ӽ��
		if (Ew + w[i] <= c){//����ӽ��Ϊ���н��
			AddLiveNode(H, E, Ew + w[i] + r[i], true, i + 1);
		}
		//�Ҷ��ӽ��
		AddLiveNode(H, E, Ew + r[i], false, i + 1);
		HeapNode<Type> N;
		H.DeleteMax(N);//ȡ��һ����չ���
		i = N.level;
		E = N.ptr;//ע����һ����չ����ǴӶѽ����ȡ������
		Ew = N.uweight - r[i - 1];//������һ����չ�������ȼ�
	}
	//���쵱ǰ���Ž�
	for (int j = n, j > 0; j--){
		bestx[j] = E->LChild;
		E = E->parent;
	}
}
