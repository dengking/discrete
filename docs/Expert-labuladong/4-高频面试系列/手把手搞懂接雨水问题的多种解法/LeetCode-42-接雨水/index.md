# leetcode [42. 接雨水](https://leetcode.cn/problems/trapping-rain-water/)

## 我的解题

是按照 [详解一道高频面试题：接雨水](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494095&idx=5&sn=8a69b2ca4d48e8b4db2b153a405c6e52&scene=21#wechat_redirect) 中的解法写的

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
  int trap(vector<int> &height)
  {

    int lmax = height.front(), rmax = height.back();
    int left = 1, right = height.size() - 2;

    int res = 0;

    while (left <= right)
    {
      if (lmax < rmax)
      {
        res += max(lmax - height[left], 0);
        lmax = max(lmax, height[left]);

        ++left;
      }
      else
      {
        res += max(rmax - height[right], 0);
        rmax = max(rmax, height[right]);
        --right;
      }
    }
    return res;
  }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

