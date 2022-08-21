# [72. 编辑距离](https://leetcode.cn/problems/edit-distance/) 看你



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

public:
  int minDistance(string word1, string word2)
  {
    int len1 = word1.size();
    int len2 = word2.size();
    vector<vector<int> > dp(len1 + 1, vector<int>(len2 + 1));
    for (int i = 1; i <= len2; ++i)
    { // i表示的是长度

      dp[0][i] = i;
    }
    for (int i = 1; i <= len1; ++i)
    { // i表示的是长度

      dp[i][0] = i;
    }
    for (int i = 1; i <= len1; ++i) // 表示长度
      for (int j = 1; j <= len2; ++j) // 表示长度
      {
        if (word1[i - 1] == word2[j - 1])
        {
          dp[i][j] = dp[i - 1][j - 1];
        }
        else
        {
          dp[i][j] = min(
              dp[i][j - 1] + 1, // 增
              min(
                  dp[i - 1][j] + 1,    // 删
                  dp[i - 1][j - 1] + 1 // 改
                  ));
        }
      }
    return dp[len1][len2];
  }
};

int main()
{
  Solution s;
}

```

