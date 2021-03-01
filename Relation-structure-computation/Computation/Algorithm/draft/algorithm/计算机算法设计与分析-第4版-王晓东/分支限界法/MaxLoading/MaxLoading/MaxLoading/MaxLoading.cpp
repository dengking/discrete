
template<class Type>
class QNode{
	friend EnQueue(Queue<QNode<Type> *>&Q, Type wt, int i, int n, Type bestw, QNode<Type> *E, QNode<Type> *&bestE, int bestx[], bool ch);
	/*对上述函数的参数解释：
	1.Q即为活结点队列
	2.wt表示当前载重量，注意它是累加值
	3.i表示该结点所处的层次，n表示问题的规模,当i==n时，则求得了问题的完整解
	4.bestw表示当前最优解
	5.E表示当前结点的父结点
	6.bestE是最优解路径上的最后一个结点
	7.bestx就是最优解，其中元素的取值为0或1
	8.ch表示当前结点是左子结点还是右子结点，如果为左子结点则取值为1，否则为0
	*/
	friend MaxLoading(Type w[], Type c, int n, int bestX[]);
	/*参数解释如下：
	1.w[]是物品的重量数组
	2.c是第一艘货船的载重量
	3.n是货物的总数
	4.bestX[]为最终解
	*/
private:
	QNode *parent;//指向父结点的指针
	bool LChild;//左儿子标志
	Type weight;//结点相应的载重量

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
	if (i == n){//已经搜索到叶子结点，即已经得到问题的完整解了，注意搜索的层次是从1开始的
		if (wt == bestw){
			bestE = E;//注意就得到了完整解路径的尾结点，相当于头指针
			bestx[n] = ch;//此处已经把完整解的最后一个元素记录了
			return;
		}
	}
	//这种情况的话，表示这个结点是非叶子结点，
	QNode<Type> *b;//动态的构造一个结点
	b = new QNode<Type>;
	b->weight = wt;//权重
	b->parent = E;//parent记录父母结点
	b->LChild = ch;
	Q.Add(b);//把b结点b插入到活结点队列Q中

}

template<class Type>
Type MaxLoading(Type w[], Type c, int n, int bestx[]){
	Queue<QNode<Type>*> Q;//活结点队列
	Q.Add(0);//同层结点尾部标志，这个标志非常重要
	int i = 0;//根结点所在的层
	Type Ew = 0,//扩展结点所相应的载重量，wt是累计值,注意两者之间的联系：每个活结点都有一个Ew值，当这个活结点成为扩展结点时，那么由它扩展生成的左子结点的Ew值为当前扩展结点的Ew值加上当前结点的重量，右子结点的Ew值和父母结点的Ew值相等
		bestw = 0,//当前最优载重量
		r = 0;//剩余集装箱重量
	for (int j = 2; j <= n; j++){
		r += w[j];//初始化r，因为当前扩展结点为根结点，所以剩余集装箱的重量不包括w[1]
	}
	QNode *E = 0,//表示当前扩展结点
		*bestE = 0;//当前最优扩展结点
	while (true){
		//检查左儿子结点
		Type wt = Ew + w[i];
		if (wt < c){//提前更新bestw的值
			if (wt>bestw)
				bestw = wt;
			EnQueue(Q, wt, i, n, bestw, E, bestE, bestx, true);
		}
		//检查右子结点，注意加了限制条件进行剪枝
		if (Ew + r > bestw)
			EnQueue(Q, Ew, i, n, bestw, E, bestE, bestx, false);
		Q.Delete(E);//取下一个扩展结点
		if (!E){//检查是否到达同层结点尾部
			if (Q.IsEmpty())break;//如果队列为空，则已经求得问题的完整解，可以退出了
			Q.Add(0);//添加同层尾部标识
			Q.Delete(E);//取下一个扩展结点
			i++;//进入下一层
			r -= w[i];
		}
		Ew = E->weight;//新扩展结点所相应的载重量
	}
	//构造当前最优解
	for (int j = n - 1; j > 0; j--){
		bestx[j] = bestE->LChild;//LChild是bool类型的，0表示该结点是右儿子，1表示该结点是左儿子，这正好和最终解中某个元素选择或不选择对应，非常简洁
		bestE = bestE->parent;
	}
	return bestw;
}
