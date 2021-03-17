#if defined KNAP
#define KNAP


//此类的数据成员用来记录解空间树中的结点信息
template<class Typew,class Typev>
class Knap{
	friend Typev Knapsack(Typew *,Typev *,Typew,int);//此函数首先进行初始化，然后调用函数Backtrack，计算最优值，然后把最优值返回
private:
	Typep Bound(int i);//此函数用来计算当前结点及其子树的价值上界
	void Backtrack(int i);//回溯函数用来求最优解
	Typew c;//背包容量；
	int n;//物品数
	Typew *w;//物品重量数组
	Typev *v;//物品价值数组
	Typew cw;//当前重量
	Typev cv;//当前价值
	Typev bestv;//当前最优价值
};
#endif
