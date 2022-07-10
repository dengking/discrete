# Floyd–Warshall algorithm

素材:

1、wikipedia [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm)

2、geeksforgeeks [Floyd Warshall Algorithm | DP-16](https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/) 



## Computation complexity

Floyd–Warshall algorithm的思想非常简单: 穷举，对于包含N个节点的graph，显然穷举/遍历需要 $O(N^3)$ 。



## wikipedia [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), the **Floyd–Warshall algorithm** (also known as **Floyd's algorithm**, the **Roy–Warshall algorithm**, the **Roy–Floyd algorithm**, or the **WFI algorithm**) ...

> NOTE: 
>
> 一、要理解上面这段话，其实是需要了解"History and naming"节的内容，从这个算法的命名来看，它其实就涉及多位计算机科学家，下面是一个简单的梳理
>
> | 时间 | 计算机科学家                                                 | application        |
> | ---- | ------------------------------------------------------------ | ------------------ |
> | 1959 | [Bernard Roy](https://en.wikipedia.org/wiki/Bernard_Roy)     |                    |
> | 1962 | [Robert Floyd](https://en.wikipedia.org/wiki/Robert_Floyd)   | shortest-path      |
> | 1962 | [Stephen Warshall](https://en.wikipedia.org/wiki/Stephen_Warshall) | transitive closure |
>
> 不过，一般采用如下叫法:
>
> | application                                                  | 叫法                 |
> | ------------------------------------------------------------ | -------------------- |
> | Shortest paths in directed graphs                            | Floyd's algorithm    |
> | [Transitive closure](https://en.wikipedia.org/wiki/Transitive_closure) of directed graphs | Warshall's algorithm |
> |                                                              |                      |
>
> 二、

### History and naming



The Floyd–Warshall algorithm is an example of [dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming), and was published in its currently recognized form by [Robert Floyd](https://en.wikipedia.org/wiki/Robert_Floyd) in 1962.[[3\]](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm#cite_note-3) However, it is essentially the same as algorithms previously published by [Bernard Roy](https://en.wikipedia.org/wiki/Bernard_Roy) in 1959[[4\]](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm#cite_note-4) and also by [Stephen Warshall](https://en.wikipedia.org/wiki/Stephen_Warshall) in 1962[[5\]](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm#cite_note-5) for finding the **transitive closure** of a graph,[[6\]](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm#cite_note-6) and is closely related to [Kleene's algorithm](https://en.wikipedia.org/wiki/Kleene's_algorithm) (published in 1956) for converting a [deterministic finite automaton](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) into a [regular expression](https://en.wikipedia.org/wiki/Regular_expression).[[7\]](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm#cite_note-7) The modern formulation of the algorithm as three nested for-loops was first described by Peter Ingerman, also in 1962.[[8\]](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm#cite_note-8)



### Applications and generalizations



## Implementation

```C++
for ( int i = 0; i < 节点个数; ++i )// 我们要求的是从i到j的最短路径，k代表的是i和j之间的中间结点
{
	for ( int j = 0; j < 节点个数; ++j )
	{
		for ( int k = 0; k < 节点个数; ++k )
		{
			if ( Dis[i][k] + Dis[k][j] < Dis[i][j] )
			{
				// 找到更短路径
				Dis[i][j] = Dis[i][k] + Dis[k][j];
			}
		}
	}
}

```

但是这里我们要注意循环的嵌套顺序，如果把检查所有节点X放在最内层，那么结果将是不正确的，为什么呢？因为这样便过早的把i到j的最短路径确定下来了，而当后面存在更短的路径时，已经不再会更新了。现分析如下：

![](./example-graph.png)

如果我们在最内层检查所有节点X（结点x代表A和B之间的中间结点），那么对于A->B，我们只能发现一条路径（而实际上不止这一条路径，还存在A->D->C->B这条路径，显然上述的循环嵌套次序会造成与实际不符的结果），就是A->B，路径距离为9。而这显然是不正确的，真实的最短路径是A->D->C->B，路径距离为6。造成错误的原因就是我们把检查所有节点X放在最内层，造成过早的把A到B的最短路径确定下来了，当确定A->B的最短路径时Dis(AC)尚未被计算。

所以，我们需要改写循环顺序，如下：

```c++
for ( int k = 0; k < 节点个数; ++k )// k代表的是i和j之间的中间结点
{
	for ( int i = 0; i < 节点个数; ++i )
	{
		for ( int j = 0; j < 节点个数; ++j )
		{
			if ( Dis[i][k] + Dis[k][j] < Dis[i][j] )
			{
				// 找到更短路径
				Dis[i][j] = Dis[i][k] + Dis[k][j];
			}
		}
	}
}
```

注意此种写法的优点：对于每一个节点X，我们都会把所有的i到j处理完毕后才继续检查下一个节点。

那么接下来的问题就是，我们如何找出最短路径呢？这里需要借助一个辅助数组Path，它是这样使用的：Path(AB)的值如果为P，则表示A节点到B节点的最短路径是A->...->P->B（表示A到B的最短距离所必须经过的结点）。这样一来，假设我们要找A->B的最短路径，那么就依次查找，假设Path(AB)的值为P，那么接着查找Path(AP)，假设Path(AP)的值为L，那么接着查找Path(AL)，假设Path(AL)的值为A，则查找结束，最短路径为A->L->P->B。

 

如何填充Path的值呢？很简单，当我们发现Dis(AX) + Dis(XB) < Dis(AB)成立时，就要把最短路径改为A->...->X->...->B，而此时，Path(XB)的值是已知的，所以，Path(AB) = Path(XB)。



### [LeetCode-743. 网络延迟时间-中等](https://leetcode.cn/problems/network-delay-time/) 

#### 写法一: 正确

```c++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>

using namespace std;

class Solution
{
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 2)); // 节点的标号是从1开始的，所以使用n+1
    for (auto &it : times)
      dp[it[0]][it[1]] = it[2];
    for (int i = 1; i <= n; i++)
      dp[i][i] = 0;              //自己到自己为0
    for (int k = 1; k <= n; k++) // 中转节点
    {
      for (int i = 1; i <= n; i++) // 节点的标号是从1开始的
      {
        for (int j = 1; j <= n; j++)
        {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++)
      ret = max(ret, dp[k][i]);
    return ret == INT_MAX / 2 ? -1 : ret;
  }
};

// Driver code
int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



```c++
k=1: // 经过1中转
dp[1][1]=min(dp[1][1], dp[1][1]+dp[1][1])
dp[1][2]=min(dp[1][2], dp[1][1]+dp[1][2])
dp[1][3]=min(dp[1][3], dp[1][1]+dp[1][3])

dp[2][1]=min(dp[2][1], dp[2][1]+dp[1][1])
dp[2][2]=min(dp[2][2], dp[2][1]+dp[1][2])
dp[2][3]=min(dp[2][3], dp[2][1]+dp[1][3])

dp[3][1]=min(dp[3][1], dp[3][1]+dp[1][1])
dp[3][2]=min(dp[3][2], dp[3][1]+dp[1][2])
dp[3][3]=min(dp[3][3], dp[3][1]+dp[1][3])

k=2: // 经过2中转
dp[1][1]=min(dp[1][1], dp[1][2]+dp[2][1])
dp[1][2]=min(dp[1][2], dp[1][2]+dp[2][2])
dp[1][3]=min(dp[1][3], dp[1][2]+dp[2][3])

dp[2][1]=min(dp[2][1], dp[2][2]+dp[2][1])
dp[2][2]=min(dp[2][2], dp[2][2]+dp[2][2])
dp[2][3]=min(dp[2][3], dp[2][2]+dp[2][3])

dp[3][1]=min(dp[3][1], dp[3][2]+dp[2][1])
dp[3][2]=min(dp[3][2], dp[3][2]+dp[2][2])
dp[3][3]=min(dp[3][3], dp[3][2]+dp[2][3])

k=3: // 经过3中转
dp[1][1]=min(dp[1][1], dp[1][3]+dp[3][1])
dp[1][2]=min(dp[1][2], dp[1][3]+dp[3][2])
dp[1][3]=min(dp[1][3], dp[1][3]+dp[3][3])

dp[2][1]=min(dp[2][1], dp[2][3]+dp[3][1])
dp[2][2]=min(dp[2][2], dp[2][3]+dp[3][2])
dp[2][3]=min(dp[2][3], dp[2][3]+dp[3][3])

dp[3][1]=min(dp[3][1], dp[3][3]+dp[3][1])
dp[3][2]=min(dp[3][2], dp[3][3]+dp[3][2])
dp[3][3]=min(dp[3][3], dp[3][3]+dp[3][3])

```

上述代码能够正常工作，它的计算过程是不断地进行更新。



#### 写法二: 错误

下面代码则无法正常工作:

```c++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>

using namespace std;

class Solution
{
public:
  int networkDelayTime(vector<vector<int>> &times, int n, int k)
  {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX / 2)); // 节点的标号是从1开始的，所以使用n+1
    for (auto &it : times)
      dp[it[0]][it[1]] = it[2];
    for (int i = 1; i <= n; i++)
      dp[i][i] = 0; //自己到自己为0

    for (int i = 1; i <= n; i++) // 节点的标号是从1开始的
    {
      for (int j = 1; j <= n; j++)
      {
        for (int k = 1; k <= n; k++) // 中转节点
        {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
      }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++)
      ret = max(ret, dp[k][i]);
    return ret == INT_MAX / 2 ? -1 : ret;
  }
};

// Driver code
int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



```C++
#
dp[1][1]=min(dp[1][1], dp[1][1]+dp[1][1])
dp[1][1]=min(dp[1][1], dp[1][2]+dp[2][1])
dp[1][1]=min(dp[1][1], dp[1][3]+dp[3][1])
#
dp[1][2]=min(dp[1][2], dp[1][1]+dp[1][2])
dp[1][2]=min(dp[1][2], dp[1][2]+dp[2][2])
dp[1][2]=min(dp[1][2], dp[1][3]+dp[3][2])
#
dp[1][3]=min(dp[1][3], dp[1][1]+dp[1][3])
dp[1][3]=min(dp[1][3], dp[1][2]+dp[2][3])
dp[1][3]=min(dp[1][3], dp[1][3]+dp[3][3])
#
dp[2][1]=min(dp[2][1], dp[2][1]+dp[1][1])
dp[2][1]=min(dp[2][1], dp[2][2]+dp[2][1])
dp[2][1]=min(dp[2][1], dp[2][3]+dp[3][1])
#
dp[2][2]=min(dp[2][2], dp[2][1]+dp[1][2])
dp[2][2]=min(dp[2][2], dp[2][2]+dp[2][2])
dp[2][2]=min(dp[2][2], dp[2][3]+dp[3][2])
#
dp[2][3]=min(dp[2][3], dp[2][1]+dp[1][3])
dp[2][3]=min(dp[2][3], dp[2][2]+dp[2][3])
dp[2][3]=min(dp[2][3], dp[2][3]+dp[3][3])
#
dp[3][1]=min(dp[3][1], dp[3][1]+dp[1][1])
dp[3][1]=min(dp[3][1], dp[3][2]+dp[2][1])
dp[3][1]=min(dp[3][1], dp[3][3]+dp[3][1])
#
dp[3][2]=min(dp[3][2], dp[3][1]+dp[1][2])
dp[3][2]=min(dp[3][2], dp[3][2]+dp[2][2])
dp[3][2]=min(dp[3][2], dp[3][3]+dp[3][2])
#
dp[3][3]=min(dp[3][3], dp[3][1]+dp[1][3])
dp[3][3]=min(dp[3][3], dp[3][2]+dp[2][3])
dp[3][3]=min(dp[3][3], dp[3][3]+dp[3][3])


```

可以看到，上述计算过程并没有不断地进行更新而是在原地踏步。

#### 总结

两者写法，填值顺序完全不同。

### Graph representation and DP table

[Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm) 的精妙之处在于它graph representation就是DP table，它的graph representation是adjacency matrix，显然这是正好可以作为DP table的，这其实是这个算法简单的来源。