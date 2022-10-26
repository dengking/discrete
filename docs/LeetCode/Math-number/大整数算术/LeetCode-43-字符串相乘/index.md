# **LeetCode** [43. 字符串相乘](https://leetcode.cn/problems/multiply-strings/)

 

## 我的解题

是参考 labuladong [教计算机做算术：字符串乘法](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484466&idx=1&sn=0281340cc1f41230e4512e905b9d27dd&scene=21#wechat_redirect) 写的。



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
  string multiply(string num1, string num2)
  {
    auto len1 = num1.size();
    auto len2 = num2.size();
    vector<int> num(len1 + len2, 0);
    for (int first = len1 - 1; first >= 0; --first)
    {
      for (int second = len2 - 1; second >= 0; --second)
      {
        int index = first + second + 1; // 注意不要忘记 + 1
        auto product = (num1[first] - '0') * (num2[second] - '0');
        auto sum = product + num[index]; //一定要累加
        num[index] = sum % 10;           //处理本位
        num[index - 1] += sum / 10;      // 处理进位
      }
    }
    int i = 0;
    while (i < num.size() && num[i] == 0)
    {
      ++i;
    }
    string res;
    for (; i < num.size(); ++i)
    {
      res.push_back(num[i] + '0');
    }
    return res.size() == 0 ? "0" : res;
  }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

