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



## 延迟删除

> NOTE:
>
> 一、本质上是暴力: 两层for循环:
>
> 1、内循环: 执行一次匹配，如果找到了匹配，则删除
>
> 2、外循环: 重复执行内循环
>
> 二、复杂度是$O(N^2)$
>
> 三、它的实现其实也是典型的采用

可以用**链表**和**延迟删除**来解决。

使用 `nexts` 数组充当链表（懒得做删除了），保持当前位置的下一个没有删除的位置。我这里使用`0`作为起始点，`-1`作为结束点。 每次遍历都从开始节点开始，匹配成功后，将当前匹配开始节点的前一个节点`prev`指向当前匹配的结束节点的下一个节点。 循环直到无法匹配成功。最后使用`nexts`数组还原字符串。

平均时间复杂度$$O(n^2)$$ 空间复杂度O(N)

