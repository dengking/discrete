# 集合划分问题

## 2-7

![](1.jpg)

## 2-8

![](2.jpg)

## 2-7 解题

1、divide-and-conquer，

### cnblogs [集合划分问题](https://www.cnblogs.com/dolphin0520/archive/2011/07/12/2103917.html)

思路：对于n个元素的集合，可以划分成由m(1<=m<=n)个子集构成的子集，如 {{1}，{2}，{3}，{4}}就是由4个子集构成的非空子集。假设f(n,m)表示将n个元素的集合划分成由m个子集构成的集合的个数，那么可以这样来看：

   1)若$m==1$，则$f(n,m)=1$;

   2)若$n==m$，则$f(n,m)=1$;

   3)若非以上两种情况，$f(n,m)$可以由下面两种情况构成

​    a.向n-1个元素划分成的m个集合里面添加一个新的元素，则有$m*f(n-1,m)$种方法；

​    b.向n-1个元素划分成的m-1个集合里添加一个由一个元素形成的独立的集合，则有$f(n-1,m-1)$种方法。

因此：

​       $1   (m==1||n==m)$

$f(n,m)=f(n-1,m-1)+m*f(n-1,m)    (m<n \&\&m!=1)$

#### 递归实现

```c++
#include<stdio.h>
/**
 * @brief 将元素个数为n的结合，划分为包含m个子集的
 *
 * @param n 元素个数
 * @param m 子集个数
 * @return
 */
int f(int n, int m)
{
	if (m == 1 || n == m)
		return 1;
	else
		return f(n - 1, m - 1) + f(n - 1, m) * m;
}

int main(void)
{
	int n;
	while (scanf("%d", &n) == 1 && n >= 1)
	{
		int i;
		int sum = 0;
		for (i = 1; i <= n; i++)
		{
			sum += f(n, i);
		}
		printf("%d\n", sum);
	}
	return 0;
}
// gcc test.cpp



```



### DP实现





## TODO

csdn [集合划分问题——算法](https://blog.csdn.net/paxliever/article/details/68070618)	

csdn [集合划分问题](https://littlede.blog.csdn.net/article/details/105167906)