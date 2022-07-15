# [LeetCode-剑指 Offer II 072. 求平方根-简单](https://leetcode.cn/problems/jJ0w9p/)



## 我的解题



### 二分查找

这是在阅读 [知乎-如何看待中国学生为了进 Google、微软等外企疯狂地刷题？北美学生想进这些名企也要刷题吗？ - Haojun的回答]( https://www.zhihu.com/question/35133069/answer/97832096) 时发现的，其中已经提出了使用二分查找。其实这道题是比较特殊的，因为理论上正确的平方根应该是double类型的，但是这道题的返回值类型是int，并且要求向下取整，因此可以使用二分查找来求解，需要注意的是: 如果要求解准确的平方根，那么二分查找算法显然是不能够使用的，因为区间内有无数个小数。

下面的这种写法是典型的运用**二分查找**来进行**逼近**，需要注意的是这道题的返回值是`right`，这是因为`while (left <= right)` 的退出条件有两个:

1、`power == x`

2、`left > right`

由于题目要求是向下取整，因此最终的返回值是`right`。

```c++
// #include <bits/ne_stdc++.h>
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
#include <memory>

using namespace std;

class Solution
{
public:
  int mySqrt(int x)
  {
    int left = 0, right = x;
    while (left <= right)
    {
      double mid = left + (right - left) / 2;
      double power = mid * mid;
      if (power == x)
      {
        return mid;
      }
      else if (power < x)
      {
        left = mid + 1;
      }
      else
      {
        right = mid - 1;
      }
    }
    return right;
  }
};

int main()
{
}
// g++ test.cpp --ne_std=c++11 -pedantic -Wall -Wextra

```



### 牛顿迭代法



并且如果要准确的求解得到，需要用到一些比较高级的数学技巧: 牛顿迭代法