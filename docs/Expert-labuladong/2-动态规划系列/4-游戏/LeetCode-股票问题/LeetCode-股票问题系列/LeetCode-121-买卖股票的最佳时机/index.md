# LeetCode [121. 买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/) 简单



## 解法一: 一次遍历

这是我参照 labuladong [LeetCode 股票问题的一种通用解法](https://mp.weixin.qq.com/s/TrN7mMdLEPCmT5mOXzgP5A) 中，写出的答案。

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int maxProfit(vector<int> &prices)
	{
		int res = 0; // 最终结果，即最大利润
		int min_buy_price = prices[0]; // 最小买入价格
		for (size_t i = 1; i < prices.size(); ++i) // 卖出的时机
		{
			min_buy_price = min(prices[i], min_buy_price); // 更新最小买价
			res = max(res, prices[i] - min_buy_price);
		}
		return res;
	}
};

int main()
{
	vector<int> n { 1, 2, 5 };
	Solution s;
	cout << s.maxProfit(n) << endl;

	n = { 7, 1, 5, 3, 6, 4 };
	cout << s.maxProfit(n) << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

典型的打擂台+greedy algorithm+最优值问题。

## 解法二: 动态规划

一、这是按照 labuladong [团灭 LeetCode 股票买卖问题](https://mp.weixin.qq.com/s/lQEj_K1lUY83QtIzqTikGA) 中给出的解法写的，不过它的初始化是参考的[Gnakuw](https://leetcode.cn/u/nehzil/) # [121. 买卖股票的最佳时机（详细C++代码注释学习代码随想录的风格写的）](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solution/gu-piao-dong-tai-gui-hua-jie-fa-by-kino-7qh40/)  



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
   *        一、状态转移方程1:在第i天，交易了k次后，不持有股票
   *        dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
   *                          rest           sell(以当天的价格卖出)
   *        二、状态转移方程2:在第i天，交易了k次后，持有股票
   *        dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i]);
   *                          rest           buy(以当天的价格买入)
   *        三、base case
   *        1、需要注意，i=0表示的是第一天，-1表示的是还没有开始的初始状态
   *        dp[-1][k][0] = 0
   *        dp[-1][k][1] = -INFINITY # 无意义值
   *
   *        dp[i][0][0] = 0
   *        dp[i][0][1] = -INFINITY # 无意义值
   *
   *        四、由于这道题，k=1
   *        一、状态转移方程1:在第i天，交易了k次后，不持有股票
   *        dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i]);
   *                          rest           sell(以当天的价格卖出)
   *        二、状态转移方程2:在第i天，交易了k次后，持有股票
   *        dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][1-1][0] - prices[i]) = max(dp[i-1][1][1], 0 - prices[i]);
   *                          rest           buy(以当天的价格买入)
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
      dp[i][1] = max(dp[i - 1][1], -prices[i]);
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
  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

当上述algorithm提出的时候，dp table中的内容如下:

| index | prices | 不持有`dp[i][0]` |                                                              | 持有`dp[i][1]` |                                               |
| ----- | ------ | ---------------- | ------------------------------------------------------------ | -------------- | --------------------------------------------- |
| 0     | 7      | 0                |                                                              | -7             |                                               |
| 1     | 1      | 0                | `max(dp[0][0], dp[0][1] + prices[1])`<br>`max(0, -7 + 1) = 0` | -1             | `max(dp[0][1], -prices[1])`<br>`max(-7, -1)`  |
| 2     | 5      | 4                | `max(dp[1][0], dp[1][1] + prices[2])`<br/>`max(0, -1 + 5) = 0` | -1             | `max(dp[1][1], -prices[2])`<br/>`max(-1, -5)` |
| 3     | 3      | 4                | `max(dp[2][0], dp[2][1] + prices[3])`<br/>`max(4, -1 + 3) = 0` | -1             | `max(dp[2][1], -prices[3])`<br/>`max(-1, -3)` |
| 4     | 6      | 4                | `max(dp[3][0], dp[3][1] + prices[4])`<br/>`max(4, -1 + 6) = 5` | -1             | `max(dp[3][1], -prices[4])`<br/>`max(-1, -6)` |
| 5     | 4      | 5                |                                                              | -1             |                                               |
| 6     |        |                  |                                                              |                |                                               |

其实，通过上述算法，已经能够看出它为什么能够求解出最终的答案了：

买`-prices[i]`、卖`+prices[i]` ，按照这种方法就可以通过加法计算出利润了。

通过上述程序和table中的演算过程可以看出:

1、`dp[i][1] = max(dp[i - 1][1], -prices[i])` 其实是在计算最低买入价格，从上述table可以看出，它计算得到的最低买入价格是`-1`；

2、`dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i])` 则是执行交易: `dp[i - 1][1] + prices[i]` 其实就是拿当前的价格和最低价买入的价格进行交易从而计算出利润；然后通过打擂台取出最优值。

3、其实上述算法的执行过程和 前面的一次遍历的算法方程其实是一模一样的。





## [文慕阳](https://leetcode.cn/u/wen-mu-yang/) # [C++ 利用哨兵👨‍✈️，维护一个单调栈📈(图解，直观掌握)](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/solution/c-li-yong-shao-bing-wei-hu-yi-ge-dan-diao-zhan-tu-/) 

> NOTE:
>
> 一、
>
> 单调栈能够找到最小的单调递增子序列，留在栈底的一定是最小的数值
>
> 单调栈能够找到最大的单调递减子序列，留在栈底的一定是最大的数值
>
> 二、这道题其实非常类似于"append-to-tail-and-flush"：
>
> 1、它的flush标志就是当遇到了更小的元素；另外它还有一个pseudo-flag-哨兵(sentinel)来充当flag。
>
> 2、它拿即将删除的元素和栈底元素进行做差其实就是append
>
> 三、它是典型的使用monolithic stack来保持过去的状态，并且由于它使用"单调栈能够找到最小的单调递增子序"，因此它能够保存过去最小的股票价格，并且保持相对顺序，所以这道题是非常适合于使用monolithic stack的。
>
> 四、它和很多的parse algorithm非常类似

一眼看过去，这个题本质就是要求某个数与其右边最大的数的差值。



在每次弹出的时候，我们拿他与买入的值(也就是栈底)做差，维护一个最大值。





第四步，入栈元素为 3，他比栈顶元素 5大，**我们直接弹栈，并拿他减去栈底元素1(这就是最重要的，模拟了买卖，因为 5 遇上了比它小的 3，因此即使后面遇到更大的元素 C，但是存在 C - 3 > C - 5，因此它已经没用了，计算之后弹出它**

![image.png](https://pic.leetcode.cn/c6549566891a8a73a2aefc98dd65c71bde518625fe2644a72d8e505bf08e1ebd-image.png)

第五步，入栈元素为 66，比栈顶元素大，入栈。

![image.png](https://pic.leetcode.cn/e762a53fd3eb9e2907aa30554ac083342945bb6f2f9b548fd89c160f2ea08cf8-image.png)

第七步，现在 **哨兵**👨‍✈️的作用就非常清楚啦，假如没有哨兵，我们单调栈中还有残留的元素没有进行判断(比如 prices 数组单调增的情况下，不加哨兵会出现 `max=0` 的情况)，因此 **哨兵**👨‍✈️的作用就是确保单调栈中的每个元素都被进行判定。因此最后的图像应该是这样：

![image.png](https://pic.leetcode.cn/018efc54412997315ffda187ddcf98be398489329b0b847055774bb1a56f8cb1-image.png)

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
  int maxProfit(vector<int> &prices)
  {
    vector<int> mono_stack;
    prices.emplace_back(0);
    int res = 0;
    for (auto &&p : prices)
    {
      while (!mono_stack.empty() && mono_stack.back() > p)
      {
        res = max(res, mono_stack.back() - mono_stack.front());
        mono_stack.pop_back();
      }
      mono_stack.push_back(p);
    }
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> nums1{6, 7};
  vector<int> nums2{6, 0, 4};
  int k = 5;
  s.maxNumber(nums1, nums2, k);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

