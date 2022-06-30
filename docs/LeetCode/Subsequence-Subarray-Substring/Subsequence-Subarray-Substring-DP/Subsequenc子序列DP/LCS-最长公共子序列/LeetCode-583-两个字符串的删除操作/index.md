# LeetCode [583. 两个字符串的删除操作](https://leetcode-cn.com/problems/delete-operation-for-two-strings/) 中等



## 我的解题

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>

using namespace std;

class Solution
{
public:
  int minDistance(string word1, string word2)
  {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));

    for (int i = 1; i <= word1.size(); ++i)
      for (int j = 1; j <= word2.size(); ++j)
      {
        if (word1[i - 1] == word2[j - 1])
        {
          dp[i][j] = 1 + dp[i - 1][j - 1];
        }
        else
        {
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    int lcs = dp[word1.size()][word2.size()];
    return word1.size() - lcs + word2.size() - lcs;
  }
};

int main()
{
}
```

