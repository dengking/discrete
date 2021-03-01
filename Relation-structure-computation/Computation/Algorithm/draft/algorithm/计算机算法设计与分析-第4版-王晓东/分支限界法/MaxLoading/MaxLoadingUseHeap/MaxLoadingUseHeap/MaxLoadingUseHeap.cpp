template<class Type>
class bbnode{
	friend void AddLiveNode(MaxHeap<HeapNode<int>> &H, bbnode *E, Type wt, bool ch, int lev);//此函数的功能类似前面的EnQueue函数
	/*对该函数的参数解释如下：
	1.H是最大堆，它是活结点优先队列，堆中每个元素的类型是HeapNode类型的
	2.bbnode搜索树中的结点，它是当前活结点的父母结点
	3.wt的含义和在队列式中的含义是不相同的，wt用来对堆结点的uweight域进行赋值，用来定义堆结点的优先级
	4.ch用来标识左右孩子结点
	5.lev表示当前结点所在的层次
	*/
	friend int MaxLoading(int w[], int c, int n, int bestx[]);
	/*参数解释如下：
	1.w[]表示货物的重量数组
	2.c表示第一艘货船的载重量
	3.n表示一共有n个货物
	4.bestx[]表示最优解
	*/
private:
	bbnode *parent;//指向父结点的指针
	bool LChilde;//标识此结点是否为左孩子
};	

template<class Type>
class HeapNode{
	friend void AddLiveNode(MaxHeap<HeapNode<Type>> &H, bbnode *E, Type wt, bool ch, int lev);//此函数的功能类似前面的EnQueue函数
	friend int MaxLoading(int w[], int c, int n, int bestx[]);
public:
	operator Type()const{ return uweight; }
private:
	bbnode *ptr;//指向活结点在子集树中相应结点的指针，通过这个指针把一对HeapNode和bbnode联系起来了
	Type uweight;//活结点优先级
	int level;//活结点在子集树中所处的层序号
};


template<class Type>
void AddLiveNode(MaxHeap<HeapNode<Type>> &H, bbnode *E, Type wt, bool ch, int lev){
	/*此函数的功能:
	1.生成新产生的活结点
	2.将这个新结点插入到活结点优先队列中*/
	bbnode *b = new bbnode;
	b->parent = E;
	b->LChild = ch;
	HeapNode<Type> N;
	N.uweight = wt;
	N.level = lev;
	N.ptr = b;//把一对HeapNode和bbnode联系起来了
	H.insert(N);
}

template<class Type>
int MaxLoading(int w[], int c, int n, int bestx[]){
	MaxHeap<HeapNode<Type>> H(1000);
	//定义剩余重量重量数组
	Type *r = new Type[n + 1];
	r[n] = 0;
	for (int j = n - 1; j > 0; j--){//这种求法和动态规划的思想是非常契合的
		r[j] = r[j + 1] + w[j + 1];
	}
	//初始化
	int i = 1;//当前的扩展结点是根节点，处在第一层
	bbnode *E = 0;
	Type Ew = 0;//当前扩展结点所相应的载重量
	//搜索子空间树
	while (i != n + 1){
		//检查当前扩展结点的儿子结点
		if (Ew + w[i] <= c){//左儿子结点为可行结点
			AddLiveNode(H, E, Ew + w[i] + r[i], true, i + 1);
		}
		//右儿子结点
		AddLiveNode(H, E, Ew + r[i], false, i + 1);
		HeapNode<Type> N;
		H.DeleteMax(N);//取下一个扩展结点
		i = N.level;
		E = N.ptr;//注意下一个扩展结点是从堆结点中取出来的
		Ew = N.uweight - r[i - 1];//计算下一个扩展结点的优先级
	}
	//构造当前最优解
	for (int j = n, j > 0; j--){
		bestx[j] = E->LChild;
		E = E->parent;
	}
}
