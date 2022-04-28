# LeetCode [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/) 简单



## 我的解题

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



## [文慕阳](https://leetcode-cn.com/u/wen-mu-yang/) # [C++ 利用哨兵👨‍✈️，维护一个单调栈📈(图解，直观掌握)](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/c-li-yong-shao-bing-wei-hu-yi-ge-dan-diao-zhan-tu-/) 

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

![image.png](https://pic.leetcode-cn.com/c6549566891a8a73a2aefc98dd65c71bde518625fe2644a72d8e505bf08e1ebd-image.png)

第五步，入栈元素为 66，比栈顶元素大，入栈。

![image.png](https://pic.leetcode-cn.com/e762a53fd3eb9e2907aa30554ac083342945bb6f2f9b548fd89c160f2ea08cf8-image.png)

第七步，现在 **哨兵**👨‍✈️的作用就非常清楚啦，假如没有哨兵，我们单调栈中还有残留的元素没有进行判断(比如 prices 数组单调增的情况下，不加哨兵会出现 `max=0` 的情况)，因此 **哨兵**👨‍✈️的作用就是确保单调栈中的每个元素都被进行判定。因此最后的图像应该是这样：

![image.png](https://pic.leetcode-cn.com/018efc54412997315ffda187ddcf98be398489329b0b847055774bb1a56f8cb1-image.png)

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

