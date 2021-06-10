# 3.10 0-1背包问题

> NOTE: 
>
> 对0-1背包问题进行了比较好的形式化分析

![](./1.jpg)

## 1、最优子结构



## 2、递归关系/状态转移方程



![](./2.jpg)

### 二元

需要注意的是，上述"递归关系/状态转移方程"是二元的，因此，可想而知，对应的实现是一个嵌套for循环。



### Base case

需要注意，上述
$$
m(n, j)={\begin{cases} v_n ,\qquad j \geq w_n \\ 0 \qquad 0 \leq j \lt w_n \end{cases}}
$$
是base case，即是可以直接求出值的；

$j$表示的是背包容量；

需要注意的是，背包容量是有上限的，它是由题目给出的，是$c$，这在上面公式中没有体现；

上述这些分析内容是理解下面代码中对DP table进行初始化的流程的关键，后面会进行专门的说明。



## 3、算法描述/代码

![](./3.jpg)

上述程序是存在错误的，下面是正确的写法:

```C++
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 *
 * @tparam Type
 * @param v
 * @param w 数组，表示物品重量
 * @param c 背包容量
 * @param n 物品个数
 * @param m
 */
template<typename Type>
void Knapsack(Type v, int *w, int c, int n, Type **m)
{
	/**
	 * base case: 只有第n个物品，它的重量为w[n]
	 * 下面这段代码对应的是上面m(n, j)
	 */
	int jMax = min(w[n] - 1, c); // jMax表示一个分界值；
	for (int j = 0; j <= jMax; ++j) // j表示的是背包的容量，显然，此时它无法装下第n个物品，所以全部都初始化为0
	{
		m[n][j] = 0;
	}
	for (int j = w[n]; j <= c; j++) // j表示的是背包的容量，显然，此时可以装下第n个物品
	{
		m[n][j] = v[n];
	}
	for (int i = n - 1; i > 1; ++i)
	{
		jMax = min(w[i] - 1, c);
		for (int j = 0; i <= jMax; ++i)
		{
			m[i][j] = m[i + 1][j];
		}
		for (int j = w[i]; j <= c; ++j)
		{
			m[i][j] = max(m[i + 1][j], m[i + 1][j - w[i]] + v[i]);
		}
	}
	m[1][c] = m[2][c];
	if (c >= w[1])
	{
		m[1][c] = max(m[1][c], m[2][c - w[1]] + v[2]);
	}
}
/**
 * @brief
 *
 * @tparam Type
 * @param m
 * @param w
 * @param c
 * @param n
 * @param x solution
 */
template<typename Type>
void Trackback(Type **m, int w, int c, int n, int *x)
{
	for (int i = 1; i < n; ++i)
	{
		if (m[i][c] == m[i + 1][c])
		{
			x[i] = 0;
		}
		else
		{
			x[i] = 1;
			c -= w[i];
		}
	}
	x[n] = (m[n][c]) ? 1 : 0;
}
int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

### Base case

```C++
/**
 * @brief
 *
 * @tparam Type
 * @param v
 * @param w 数组，表示物品重量
 * @param c 背包容量
 * @param n 物品个数
 * @param m
 */
template<typename Type>
void Knapsack(Type v, int *w, int c, int n, Type **m)
{
	/**
	 * base case: 只有第n个物品，它的重量为w[n]
	 * 下面这段代码对应的是上面m(n, j)
	 */
	int jMax = min(w[n] - 1, c); // jMax表示一个分界值；
	for (int j = 0; j <= jMax; ++j) // j表示的是背包的容量，显然，此时它无法装下第n个物品，所以全部都初始化为0
	{
		m[n][j] = 0;
	}
	for (int j = w[n]; j <= c; j++) // j表示的是背包的容量，显然，此时可以装下第n个物品
	{
		m[n][j] = v[n];
	}

}
```

`w[n] - 1` 和 `c`

1、`c` $\gt$ `w[n] - 1`

`jMax` 取值为 `w[n] - 1`

2、`c` $\lt$ `w[n] - 1`

`jMax` 取值为 `c`

## 4、计算复杂性分析

![](./4.jpg)

### 代码

![](./5.jpg)

![](./6.jpg)