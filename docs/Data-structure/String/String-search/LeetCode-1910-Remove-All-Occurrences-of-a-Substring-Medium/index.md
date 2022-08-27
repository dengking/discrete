# [LeetCode-1910. Remove All Occurrences of a Substring-中等](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/)

cn: https://leetcode.cn/problems/remove-all-occurrences-of-a-substring/



## 我的解题

### stack

这是按照hint写的:

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
  string removeOccurrences(string s, string part)
  {
    vector<char> st;
    for (int i = 0; i < s.size(); ++i)
    {
      st.push_back(s[i]);
      if (st.size() >= part.size())
      {
        bool matched = true;
        for (int j = 0; j < part.size(); ++j)
        {
          if (*(part.rbegin() + j) != *(st.rbegin() + j))
          {
            matched = false;
          }
        }
        if (matched)
        {
          for (int j = 0; j < part.size(); ++j)
          {
            st.pop_back();
          }
        }
      }
    }
    return string(st.begin(), st.end());
  }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

