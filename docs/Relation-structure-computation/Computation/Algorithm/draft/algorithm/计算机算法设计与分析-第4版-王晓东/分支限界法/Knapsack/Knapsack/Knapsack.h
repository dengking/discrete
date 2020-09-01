#if defined KNAPSACK
#define KNAPSACK

class Object//此类用来记录商品信息
{
public:
	int operator<=(Object &x)const
	{
		return d <= x.d;
	}

private:
	int ID;//商品Id
	float d;//单位重量的价值
};

#endif