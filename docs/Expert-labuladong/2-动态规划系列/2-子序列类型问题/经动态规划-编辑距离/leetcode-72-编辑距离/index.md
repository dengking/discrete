# [72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/) 看你



## 我的解题

### 递归

```c++
#include <iostream>
#include <vector>
#include <queue>
#include <utility> // std::pair
#include <unordered_map>
#include <string>
#include <set>
#include <map>
#include <climits> // INT_MAX
using namespace std;

class Solution
{
  int minDistanceImpl(string &word1, int i, string &word2, int j)
  {
    if (i == -1)
    {
      return j + 1;
    }
    if (j == -1)
    {
      return i + 1;
    }
    if (word1[i] == word2[j])
    {
      return minDistanceImpl(word1, i - 1, word2, j - 1);
    }
    else
    {
      int add = minDistanceImpl(word1, i, word2, j - 1) + 1;        //增，使两者相等
      int del = minDistanceImpl(word1, i - 1, word2, j) + 1;        //删
      int update = minDistanceImpl(word1, i - 1, word2, j - 1) + 1; //改
      return min(add, min(del, update));
    }
  }

public:
  int minDistance(string word1, string word2)
  {
    return minDistanceImpl(word1, word1.size() - 1, word2, word2.size() - 1);
  }
};

int main()
{
  Solution s;
}

```

### 动态规划

