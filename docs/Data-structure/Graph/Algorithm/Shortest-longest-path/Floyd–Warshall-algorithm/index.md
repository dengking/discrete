# Floyd–Warshall algorithm

素材:

1、wikipedia [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm)

2、geeksforgeeks [Floyd Warshall Algorithm | DP-16](https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/)



## wikipedia [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm)



The Floyd–Warshall algorithm is an example of [dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming), and was published in its currently recognized form by [Robert Floyd](https://en.wikipedia.org/wiki/Robert_Floyd) in 1962.[[3\]](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm#cite_note-3) However, it is essentially the same as algorithms previously published by [Bernard Roy](https://en.wikipedia.org/wiki/Bernard_Roy) in 1959[[4\]](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm#cite_note-4) and also by [Stephen Warshall](https://en.wikipedia.org/wiki/Stephen_Warshall) in 1962[[5\]](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm#cite_note-5) for finding the **transitive closure** of a graph,[[6\]](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm#cite_note-6) and is closely related to [Kleene's algorithm](https://en.wikipedia.org/wiki/Kleene's_algorithm) (published in 1956) for converting a [deterministic finite automaton](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) into a [regular expression](https://en.wikipedia.org/wiki/Regular_expression).[[7\]](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm#cite_note-7) The modern formulation of the algorithm as three nested for-loops was first described by Peter Ingerman, also in 1962.[[8\]](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm#cite_note-8)



## LeetCode

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

