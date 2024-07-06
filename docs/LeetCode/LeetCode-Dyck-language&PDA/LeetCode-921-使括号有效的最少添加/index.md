# [LeetCode-921. 使括号有效的最少添加](https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/)



## 我的解题

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
  int minAddToMakeValid(string s)
  {
    stack<char> sk;
    for (auto &&c : s)
    {
      if (c == '(')
      {
        sk.push(c);
      }
      else
      {
        if (sk.empty())
        {
          sk.push(c);
        }
        else if (sk.top() == '(')
        {
          sk.pop();
        }
        else
        {
          sk.push(c);
        }
      }
    }
    return sk.size();
  }
};

int main()
{
  Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

> NOTE:
>
> 上述算法是借助栈实现的

## [官方解题](https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/solution/shi-gua-hao-you-xiao-de-zui-shao-tian-jia-by-leetc/)

```python
class Solution(object):
    def minAddToMakeValid(self, S):
        ans = bal = 0
        for symbol in S:
            bal += 1 if symbol == '(' else -1
            # It is guaranteed bal >= -1
            if bal == -1:
                ans += 1
                bal += 1
        return ans + bal


```

> NOTE:
>
> 暂时没有搞懂

