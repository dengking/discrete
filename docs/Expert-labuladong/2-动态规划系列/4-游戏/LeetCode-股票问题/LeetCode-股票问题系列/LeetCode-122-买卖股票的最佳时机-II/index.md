# leetcode [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)



## 动态规划非压缩版

```c++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
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
  /**
   * @brief

   * @param prices
   * @return int
   */
  int maxProfit(vector<int> &prices)
  {
    int len = prices.size();
    vector<vector<int>> dp(len, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];
    for (int i = 1; i < len; ++i)
    {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
    }
    return dp[len - 1][0];
  }
};

// Driver code
int main()
{

  Solution solu;
  vector<int> prices{7, 1, 5, 3, 6, 4};
  solu.maxProfit(prices);
  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```





## 动态规划版

按照 labuladong [团灭 LeetCode 股票买卖问题](https://mp.weixin.qq.com/s/lQEj_K1lUY83QtIzqTikGA) 中给出的动态规划算法来解题。

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	/**
	 * @brief
	 * dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
	 * dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])
	 *
	 * @param prices
	 * @return
	 */
	int maxProfit(vector<int> &prices)
	{
		int dp_i_0 = 0, dp_i_1 = numeric_limits<int>::min();
		for (int i = 0; i < prices.size(); ++i)
		{
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, dp_i_0 - prices[i]);
		}
		return dp_i_0;
	}
};
int main()
{
	vector<int> price { 7, 1, 5, 3, 6, 4 };
	Solution s;
	cout << s.maxProfit(price) << endl;

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



## 为什么上述算法能够求解出最优值？

```
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); // 以更低的价格买入
      dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); // 以更高的价格卖出
```

对于 `dp[i][1]`，它有两个选择：

1、rest

2、buy

只有当当前持有的利润扣除买入的成本比rest要更好的时候，才会选择buy

对于 `dp[i][0]`，它有两个选择：

1、rest

2、sell

只有当当前持有的利润扣除买入的成本比rest要更好的时候，才会选择sell





### Example

```
7,1,2,3,2,3,4
```



| index | `prices[i]` | `dp[i][0]` |                                                              | `dp[i][1]` |                                                              |
| ----- | ----------- | ---------- | ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| 0     | 7           | 0          |                                                              | -7         |                                                              |
| 1     | 1           | 0          | `max(dp[0][0], dp[0][1] + prices[1])`<br>`max(0, -7 + 1)`    | -1         | `max(dp[0][1], dp[0][0] - prices[1])`<br/>`max(-7, 0 - 1)=-1` # 选择以1买入 |
| 2     | 2           | 1          | `max(dp[1][0], dp[1][1] + prices[2])`<br/>`max(0, -1 + 2)=1` # 以1买入以2卖出 | -1         | `max(dp[1][1], dp[1][0] - prices[2])`<br/>`max(-1, 0 - 2)=-1` # rest |
| 3     | 3           | 2          | `max(dp[2][0], dp[2][1] + prices[3])`<br/>`max(1, -1 + 3)=2` # 以1买入以3卖出 | -1         | `max(dp[2][1], dp[2][0] - prices[3])`<br/>`max(-1, 1 - 3)=-1`# rest |
| 4     | 2           | 7          | `max(dp[3][0], dp[3][1] + prices[4])`<br/>`max(2, -1 + 2)=7` # rest | 0          | `max(dp[3][1], dp[3][0] - prices[4])`<br/>`max(-1, 2 - 2)=0` # 选择买入2 |
| 5     | 3           | 7          | `max(dp[4][0], dp[4][1] + prices[5])`<br/>`max(7, 1 + 4)=7` # 以3买入以4买出 | 1          | `max(dp[4][1], dp[4][0] - prices[5])`<br/>`max(1, 7 - 4)=1`  |
| 6     | 4           |            |                                                              |            |                                                              |
|       |             |            |                                                              |            |                                                              |
|       |             |            |                                                              |            |                                                              |



对于

### Example



| index | `prices[i]` | `dp[i][0]` |                                                              | `dp[i][1]` |                                                              |
| ----- | ----------- | ---------- | ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| 0     | 7           | 0          |                                                              | -7         |                                                              |
| 1     | 1           | 0          | `max(dp[0][0], dp[0][1] + prices[1])`<br>`max(0, -7 + 1)`    | -1         | `max(dp[0][1], dp[0][0] - prices[1])`<br/>`max(-7, 0 - 1)=-1` |
| 2     | 5           | 4          | `max(dp[1][0], dp[1][1] + prices[2])`<br/>`max(0, -1 + 5)=4` # 以1买入以5卖出 | -1         | `max(dp[1][1], dp[1][0] - prices[2])`<br/>`max(-1, 0 - 4)=-1` # 依然选择以1买入 |
| 3     | 3           | 4          | `max(dp[2][0], dp[2][1] + prices[3])`<br/>`max(4, -1 + 3)=4` # 依然选择以5，卖出 | 1          | `max(dp[2][1], dp[2][0] - prices[3])`<br/>`max(-1, 4 - 3)=1` |
| 4     | 6           | 7          | `max(dp[3][0], dp[3][1] + prices[4])`<br/>`max(4, 1 + 6)=7` # 以3买入以6买出 | 1          | `max(dp[3][1], dp[3][0] - prices[4])`<br/>`max(1, 4 - 6)=1`  |
| 5     | 4           | 7          | `max(dp[4][0], dp[4][1] + prices[5])`<br/>`max(7, 1 + 4)=7` # 以3买入以4买出 | 3          | `max(dp[4][1], dp[4][0] - prices[5])`<br/>`max(1, 7 - 4)=1`  |
| 6     |             |            |                                                              |            |                                                              |
|       |             |            |                                                              |            |                                                              |
|       |             |            |                                                              |            |                                                              |



结合这个具体的例子来说，它的最优值的计算过程如下：

```
-1+5-3+6
```





### Example

```
7, 1, 5, 3, 4, 6
```



| index | `prices[i]` | `dp[i][0]` |                                                              | `dp[i][1]` |                                                              |
| ----- | ----------- | ---------- | ------------------------------------------------------------ | ---------- | ------------------------------------------------------------ |
| 0     | 7           | 0          |                                                              | -7         |                                                              |
| 1     | 1           | 0          | `max(dp[0][0], dp[0][1] + prices[1])`<br>`max(0, -7 + 1)`    | -1         | `max(dp[0][1], dp[0][0] - prices[1])`<br/>`max(-7, 0 - 1)=-1` |
| 2     | 5           | 4          | `max(dp[1][0], dp[1][1] + prices[2])`<br/>`max(0, -1 + 5)=4` # 以1买入以5卖出 | -1         | `max(dp[1][1], dp[1][0] - prices[2])`<br/>`max(-1, 0 - 4)=-1` |
| 3     | 3           | 4          | `max(dp[2][0], dp[2][1] + prices[3])`<br/>`max(4, -1 + 4)=4` | 1          | `max(dp[2][1], dp[2][0] - prices[3])`<br/>`max(-1, 4 - 3)=1` |
| 4     | 4           | 5          | `max(dp[3][0], dp[3][1] + prices[4])`<br/>`max(4, 1 + 4)=5` # 以3买入以4买出 | 1          | `max(dp[3][1], dp[3][0] - prices[4])`<br/>`max(1, 4 - 4)=1`  |
| 5     | 6           | 7          | `max(dp[4][0], dp[4][1] + prices[5])`<br/>`max(7, 1 + 6)=7` # 以3买入以6买出 | 3          | `max(dp[4][1], dp[4][0] - prices[5])`<br/>`max(1, 5 - 6)=1`  |
| 6     |             |            |                                                              |            |                                                              |
|       |             |            |                                                              |            |                                                              |
|       |             |            |                                                              |            |                                                              |

