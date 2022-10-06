# [LeetCode-1004. 最大连续1的个数 III](https://leetcode.cn/problems/max-consecutive-ones-iii/)



## [负雪明烛](https://leetcode.cn/u/fuxuemingzhu/) # [分享滑动窗口模板，秒杀滑动窗口问题](https://leetcode.cn/problems/max-consecutive-ones-iii/solution/fen-xiang-hua-dong-chuang-kou-mo-ban-mia-f76z/)

**重点：题意转换。把「最多可以把 K 个 0 变成 1，求仅包含 1 的最长子数组的长度」转换为 「找出一个最长的子数组，该子数组内最多允许有 K 个 0 」。**

经过上面的题意转换，我们可知本题是求**最大连续子区间**，可以使用**滑动窗口**方法。**滑动窗口**的限制条件是：窗口内最多有 K 个 0。

> NOTE:
>
> 一、"最大连续子区间"是这道题的点题之语。



```C++
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
  int longestOnes(vector<int> &A, int K)
  {
    int res = 0,   // 结果
        zeros = 0, // 区间中0的个数
        left = 0;
    for (int right = 0; right < A.size(); ++right) //将元素移入区间
    {
      if (A[right] == 0)
      {
        ++zeros;
      }
      while (zeros > K) // 这个while循环一定要放在后面的打擂台择优之前，它保证窗口内最多有K个0
      {
        if (A[left++] == 0) // 需要注意的是: A[left++] 相对于 A[left]; left = left + 1
        {                   // 它相当于将A[left]移出区间，显然之后left就需要自增1
          --zeros;
        }
      }
      res = max(res, right - left + 1); // 打擂台择优
    }
    return res;
  }
};

int main()
{
  vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int K = 2;
  Solution s;

  s.longestOnes(nums, K);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

> NOTE:
>
> 上述code非常好地展示了移入移出区间的过程