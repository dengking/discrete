# LeetCode [14. 最长公共前缀](https://leetcode.cn/problems/longest-common-prefix/)



## 纵向扫描

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
  string longestCommonPrefix(vector<string> &strs)
  {
    int min_len = min_element(strs.begin(), strs.end(), [](const string &s, const string &t)
                              { return s.size() < t.size(); })
                      ->size();

    for (auto &&s : strs)
    {
      min_len = min(min_len, s.size());
    }
    if (min_len == 0)
    {
      return "";
    }
    int i = 0;
    for (; i < min_len; ++i)
    {
      auto c = strs[0][i];
      bool equal = true;
      for (auto &&s : strs)
      {
        if (s[i] != c)
        {
          equal = false;
          break;
        }
      }
      if (!equal)
        break;
    }
    return i ? strs[0].substr(0, 1) : "";
  }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

