# leetcode [20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)



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
  bool isValid(string s)
  {
    stack<char> st;
    for (auto &&c : s)
    {
      if (c == '(' || c == '[' || c == '{')
        st.push(c);
      if (c == ')')
      {
        if (!is_ok(st, '('))
        {
          return false;
        }
      }

      if (c == ']')
      {
        if (!is_ok(st, '['))
        {
          return false;
        }
      }
      if (c == '}')
      {
        if (!is_ok(st, '{'))
        {
          return false;
        }
      }
    }
    return st.empty();
  }
  bool is_ok(stack<char> &st, char expected)
  {
    if (st.empty())
    {
      return false;
    }
    else
    {
      if (st.top() == expected)
      {
        st.pop();
        return true;
      }
      else
      {
        return false;
      }
    }
  }
};

int main()
{
  Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```



## [官方解题](https://leetcode-cn.com/problems/valid-parentheses/solution/you-xiao-de-gua-hao-by-leetcode-solution/)

```c++
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (char ch: s) {
            if (pairs.count(ch)) {
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};

```

> NOTE:
>
> 上述使用hash map来进行精简