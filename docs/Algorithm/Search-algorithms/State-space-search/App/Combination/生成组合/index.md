# 生成组合数C(n,k)

## 1.  回溯法之二叉子集树

这是比较笨的一种方法，在最原始的n层二叉集树中，共有2的n次方个叶节点，也就是有2的n次方种可能性，在这2的n次方种可能性中包含了C(n,0),C(n,1),C(n,2)…..C(n,k) (0<=k<=n)这n种组合的所有情况[[KD1\]](#_msocom_1) 。因此当我使用回溯法来生成C(n,k)的时候，其实是一个对这n层二叉树的一个剪枝过程，我只选取C(n,k)的组合数，我现在的实现思路是设置一个countK计数器来记录已经选取的元素的个数，一旦元素的个数达到k的话，就停止进一步的递归。

> NOTE: 
>
>  [[KD1\]](#_msoanchor_1)这是范德蒙等式

这种算法是非常不好的，因为n层二叉树中包含很多我根本不需要的组合的情况，这样的成本太大。

## 2.  枚举法

```Java
#include<iostream>
#include<cstdio>
int main()
{
	int n = 5;
	int m = 0;
	for (int i = 1; i <= n - m + 1; i++)
	{
		for (int j = i + 1; j <= n - m; j++)
		{
			for (int k = j + 1; k <= n; k++)
			{
				printf("%d%d%d\n", x, y, z);
			}
		}
	}
	return 0;
}

```

这样它就生成了

1、所有以1打头的组合

2、 所有以2打头的组合

3、所有以3打头的组合

点评：这种方法是非常不灵活的，因为它只能够计算C(n,3),因为只有三层循环，所以它是不灵活的。下面的回溯法就非常地灵活，它通过k来控制递归的层次，只有就可以求任意C(n,k)了，显然下面的算法是对这个算法的一个提升。

## 3.  递归法

设函数comb(int n,k)是从n个数中取k个数的组合，每个组合的第一个数可以是{n,n-1,n-2….k}[[KD1\]](#_msocom_1) 中的一个，当组合的第一个数选定后，其后的数字就是从余下的n-1个数中选取k-1个数，这样就将问题转换为了comb(n-1,k-1)[[KD2\]](#_msocom_2) 。使用一个全局数组a来存放生成的组合。需要特别注意的是：每个组合的第一个数可以是{n,n-1,n-2….k}中的一个。函数确定了组合的一个数字后，如果还没有确定组合的其余元素，则继续递归。

> NOTE: 
>
>  [[KD1\]](#_msoanchor_1)剩余k-1个数，显然每一层可选的数的范围是固定的，
>
>  [[KD2\]](#_msoanchor_2)这描述的是递归关系，不要把它和组合的第一个数的确定方法搞混淆了，此处的n是从上一层传递下来的，而不是一个固定的值



程序如下：

```C++
#include<iostream>
#include<cstdio>
using namespace std;
const int MAX = 10;
int a[MAX];
void comb(int n, int k)
{
	int i;
	int j;
	for (int i = n; i >= k; i--)
	{ //每个组合的第一个数可以是 n,n-1,n-2….,k
		a[k] = i;
		if (k > 1)
		{
			comb(n - 1, k - 1);
			++j;
		}
		else
		{
			for (int j = a[0]; j > 0; j--)
				printf("%d", a[j]);
			printf("\n");
		}
	}
}

```





## TO READ

stackoverflow [Algorithm to return all combinations of k elements from n](https://stackoverflow.com/questions/127704/algorithm-to-return-all-combinations-of-k-elements-from-n)



researchgate [The coolest way to generate combinations](https://www.researchgate.net/publication/222401233_The_coolest_way_to_generate_combinations)



dev [Algorithms: Generating Combinations #100DaysOfCode](https://dev.to/rrampage/algorithms-generating-combinations-100daysofcode-4o0a)



topcoder [GENERATING COMBINATIONS](https://www.topcoder.com/generating-combinations/)

