# [**HJ52** **计算字符串的编辑距离**](https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314?tpId=37&tqId=21275&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



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
using namespace std;

int main()
{
  string s1;
  cin >> s1;
  string s2;
  cin >> s2;
  int s1_len = s1.size();
  int s2_len = s2.size();
  vector<vector<int>> dp(s1_len + 1, vector<int>(s2_len + 1)); // 表示的是长度，加1是因为长度为0的情况
  for (int first = 1; first <= s1_len; ++first)                // 第一列
  {
    dp[first][0] = first;
  }
  for (int second = 1; second <= s2_len; ++second) // 第一行
  {
    dp[0][second] = second;
  }
  for (int first = 1; first <= s1_len; ++first)
  {
    for (int second = 1; second <= s2_len; ++second)
    {
      if (s1[first - 1] == s2[second - 1])
      {
        dp[first][second] = dp[first - 1][second - 1];
      }
      else
      {
        dp[first][second] = min(
            dp[first][second - 1] + 1, // 增加
            min(
                dp[first - 1][second - 1] + 1, // 修改

                dp[first - 1][second] + 1 // 删除

                ));
      }
    }
  }
  cout << dp[s1_len][s2_len];
}
```

