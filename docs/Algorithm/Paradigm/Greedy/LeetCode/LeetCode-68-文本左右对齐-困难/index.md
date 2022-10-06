# [LeetCode-68. 文本左右对齐](https://leetcode.cn/problems/text-justification/) 困难



## 我的解题

1、首先决定每一行包含哪些单词

单词长度 + 空格 <= `maxWidth`

2、然后编排这一行单词





```c++
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
  vector<string> fullJustify(vector<string> &words, int maxWidth)
  {
    vector<string> res;
    int i = 0;
    vector<int> cur_row;
    int cnt = words.size();
    while (i < cnt)
    {
      int len = -1; // 每行的第一个不需要前面间隔一个空格，为了下面的循环书写便利，所以将它的初始值设置为-1
      cur_row.clear();
      while (len <= maxWidth)
      {
        if (i < cnt)
        {
          len += 1; //一个空格
          cur_row.push_back(i);
          len += words[i++].size();
        }
        else
        {
          break;
        }
      }
      // 是否存在循环退出的时候，i == cnt && len > maxWidth，从上述写法来看，是不会的，因为:
      // 从上述情况来看，只有一种可能性使循环退出
      // 存在可能性：最后一步: i == cnt  && len > maxWidt，显然，在这种情况下，是需要将最后一个元素给吐出来的
      if (len > maxWidth) // 需要吐出最后一个元素
      {
        --i;
        len -= (words[i].size() + 1);
        cur_row.pop_back(); //将最后一个元素给弹出来
      }
      bool isLast = i == cnt;
      dealRow(maxWidth, cur_row, isLast);
    }
  }

private:
  string dealRow(int maxWidth, vector<int> &cur_row, bool isLast)
  {
    string res(maxWidth, ' ');
  }
};
```

