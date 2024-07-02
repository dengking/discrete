# Binary-serach-math

和数学相关的使用binary-search来解决的问题，有如下类型的问题:

1. 从搜索区间中搜索符合条件的一个数

   这类问题的一个典型特征是: 

   - 搜索区间可以根据题目意思推断出来
   - 单调函数，单调意味着是sorted的，因此可以使用binary search来进行搜索

2. BS approximation

   - left、right可以取到target: 直接返回`mid`

   - left、right无法取到target(比如left、right是整数、target是小数):

     BS保证不断地向target逼近:

     - 在退出loop前到最后一次循环，肯定满足: `left == right` 

     - 当退出循环的时候，`left > right`

   

   | LeetCode                                                     |                        |             |
   | ------------------------------------------------------------ | ---------------------- | ----------- |
   | [LeetCode-29. Divide Two Integers-middle](https://leetcode.cn/problems/divide-two-integers/) | 搜索满足条件最大的数字 | right bound |
   | [LeetCode-69. x 的平方根 ](https://leetcode.cn/problems/sqrtx/) / [LeetCode-剑指 Offer II 072. 求平方根-简单](https://leetcode.cn/problems/jJ0w9p/) |                        |             |
   | [LeetCode-875. 爱吃香蕉的珂珂-中等](https://leetcode.cn/problems/koko-eating-bananas/) | 搜索满足条件最小的数字 | left bound  |
   | [LeetCode-1011. 在 D 天内送达包裹的能力-中等](https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days/) | 搜索满足条件最小的数字 | left bound  |

   

   

## [LeetCode-29. Divide Two Integers-middle](https://leetcode.cn/problems/divide-two-integers/) 

这道题所考察的是binary search、quick multiplication。

解题思路: 在`[0, dividend]` 中搜索最大的 `quotient`，并且 `quotient` 它满足 

```
quotient = dividend // divisor 
quotient * divisor <= dividend
```

显然这是在搜索满足条件的最大的数字，可以使用right bound

可以将负数转换为正数来保证 $quotient * divisor$ 单调，求解满足条件的最大的数，显然这是可以使用binary search的。

**乘法**可以使用**快速乘算法**(只使用**加法**)实现。

### Python

```python
class Solution:
    INT_MIN = -2 ** 31
    INT_MAX = 2 ** 31 - 1

    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == 0:
            return 0
        if divisor == 1:
            return dividend
        if divisor == -1:
            if dividend > self.INT_MIN:
                return -dividend
            else:
                return self.INT_MAX
        sign = 1
        if (dividend < 0 < divisor) or (dividend > 0 > divisor):
            sign = -1
        dividend = abs(dividend)
        divisor = abs(divisor)
        left, right = 0, dividend
        while left <= right:
            mid = left + (right - left) // 2
            product = self.quick_mul(mid, divisor)
            if product == dividend:
                right = mid
                break
            elif product < dividend:
                left = mid + 1
            else:
                right = right - 1
        return right * sign

    @staticmethod
    def quick_mul(m, n) -> int:
        product = 0
        while n:
            if n & 1:
                product += m
            m += m
            n >>= 1
        return product


if __name__ == '__main__':
    solu = Solution()
    dividend = 2147483647
    divisor = 2
    solu.divide(dividend, divisor)

```



## [LeetCode-69. x 的平方根 ](https://leetcode.cn/problems/sqrtx/) / [LeetCode-剑指 Offer II 072. 求平方根-简单](https://leetcode.cn/problems/jJ0w9p/) 



### 二分查找

这是在阅读 [知乎-如何看待中国学生为了进 Google、微软等外企疯狂地刷题？北美学生想进这些名企也要刷题吗？ - Haojun的回答]( https://www.zhihu.com/question/35133069/answer/97832096) 时发现的，其中已经提出了使用二分查找。其实这道题是比较特殊的，因为理论上正确的平方根应该是double类型的，但是这道题的返回值类型是int，并且要求向下取整，因此可以使用二分查找来求解，需要注意的是: 如果要求解准确的平方根，那么二分查找算法显然是不能够使用的，因为区间内有无数个小数。

下面的这种写法是典型的运用**二分查找**来进行**逼近**，需要注意的是这道题的返回值是`right`，这是因为`while (left <= right)` 的退出条件有两个:

- `power == x`

- `left > right`

由于题目要求是向下取整，因此最终的返回值是`right`。



```c++
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left <= right) {
            double mid = left + (right - left) / 2;
            double power = mid * mid;
            if (power == x) {
                return mid;
            } else if (power < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};

int main() {
}
// g++ test.cpp --ne_std=c++11 -pedantic -Wall -Wextra

```



### 牛顿迭代法

并且如果要准确的求解得到，需要用到一些比较高级的数学技巧: 牛顿迭代法



## [LeetCode-367. 有效的完全平方数](https://leetcode.cn/problems/valid-perfect-square/)

```python
class Solution:
    def isPerfectSquare(self, num: int) -> bool:
        left, right = 1, num
        while left <= right:
            mid = left + (right - left) // 2
            square = mid * mid
            if square == num:
                return True
            elif square > num:
                right = mid - 1
            else:
                left = mid + 1
        return False

```



## [LeetCode-875. 爱吃香蕉的珂珂-中等](https://leetcode.cn/problems/koko-eating-bananas/) 

- 在阅读 labuladong [二分搜索只能用来查找元素吗？](https://mp.weixin.qq.com/s/QC24hyg0ZgjR7-LgnEzMYg) 时发现的这道题

- > 每个小时，她将会选择一堆香蕉，从中吃掉 `k` 根。如果这堆香蕉少于 `k` 根，她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。 

  表示向上取整

- 搜索满足条件的最小的数字，显然使用left bound

### Python

```python
import math
from typing import *


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def can_finish(speed):
            return sum(math.ceil(p / speed) for p in piles) <= h

        left, right = 1, max(piles)
        while left <= right:
            mid = (left + right) // 2
            if can_finish(mid):
                right = mid - 1
            else:
                left = mid + 1
        return left

```



### C++

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int minEatingSpeed(vector<int> &piles, int h)
	{
		int left = 1; // 最小速度
		int right = *max_element(std::begin(piles), std::end(piles)); // 最大速度
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			/**
			 * 以mid为speed可以吃完，但是目标是寻找最小speed，
			 * 因此，需要继续在左侧区间寻找，这好比找最左侧元素
			 */
			if (canFinish(piles, h, mid))
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		return left;
	}

	bool canFinish(vector<int> &piles, int h, int speed)
	{
		int total = 0; // 总耗时
		for (auto &&p : piles)
		{
			total += timeOf(p, speed);
			if (total > h)
			{
				return false;
			}
		}
		return true;
	}
	int timeOf(int p, int speed)
	{
		// 三元条件运算符必须要加括号，因为它的优先级较低
		return p / speed + (p % speed > 0 ? 1 : 0);
	}
};

int main()
{
	vector<int> nums = { 30, 11, 23, 4, 20 };
	Solution s;
	s.minEatingSpeed(nums, 6);
}

```



#### [官方解题](https://leetcode.cn/problems/koko-eating-bananas/solution/ai-chi-xiang-jiao-de-ke-ke-by-leetcode/)

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int minEatingSpeed(vector<int> &piles, int H)
	{
		int lo = 1, hi = pow(10, 9);
		while (lo < hi)
		{
			int mi = lo + (hi - lo) / 2;
			if (!possible(piles, H, mi))
				lo = mi + 1;
			else
				hi = mi;
		}

		return lo;
	}

	// Can Koko eat all bananas in H hours with eating speed K?
	bool possible(vector<int> &piles, int H, int K)
	{
		int time = 0;
		for (int p : piles)
			time += (p - 1) / K + 1;
		return time <= H;
	}
};

int main()
{
	vector<int> nums = { 30, 11, 23, 4, 20 };
	Solution s;
	s.minEatingSpeed(nums, 6);
}

```

需要学习的是向上取整公式。



## [LeetCode-1011. 在 D 天内送达包裹的能力-中等](https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days/) 

在阅读 labuladong [二分搜索只能用来查找元素吗？](https://mp.weixin.qq.com/s/QC24hyg0ZgjR7-LgnEzMYg) 时发现的这道题

### Python

```python
from typing import *


class Solution:
    def shipWithinDays(self, weights: List[int], days: int) -> int:
        def can_finish(capacity):
            # need 为需要运送的天数，默认值为1是因为不足一船也需要跑一趟
            # cur 为当前这一天已经运送的包裹重量之和
            need, cur = 1, 0
            for weight in weights:
                if cur + weight > capacity:
                    need += 1
                    cur = 0
                cur += weight
            return need <= days

        left, right = max(weights), sum(weights) - 1
        while left <= right:
            mid = (left + right) // 2
            if can_finish(mid):
                right -= 1
            else:
                left += 1
        return left

```



### C++

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int shipWithinDays(vector<int> &weights, int days)
	{
		int left = *max_element(begin(weights), end(weights));
		int right = accumulate(begin(weights), end(weights), 0);
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (possible(weights, days, mid))
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		return left;
	}
	bool possible(vector<int> &weights, int days, int cap)
	{
		int sum = 0;
		int real_days = 0;
		for (auto &&w : weights)
		{
			sum += w;
			if (sum > cap)
			{
				++real_days;
				sum = w;
			}
			else if (sum == cap)
			{
				++real_days;
				sum = 0;
			}
		}
		if (sum > 0)
		{
			++real_days;
		}
		return real_days <= days;
	}
};
int main()
{
	vector<int> nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Solution s;
	s.shipWithinDays(nums, 5);
}

```

