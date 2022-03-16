# leetcode [354. 俄罗斯套娃信封问题](https://leetcode-cn.com/problems/russian-doll-envelopes/) 困难



## 我的解题

### 动态规划LIS

```c++
#include <iostream>
#include <vector>
#include <algorithm>
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
  int maxEnvelopes(vector<vector<int> > &envelopes)
  {
    std::sort(envelopes.begin(), envelopes.end(), [](vector<int> &left, vector<int> &right)
              {
      if(left[0] == right[0]){
        return left[1] > right[1];
      }else{
        return left[0] < right[0];
      } });
    int N = envelopes.size();
    vector<int> dp(N, 1);
    for (int i = 1; i < N; ++i)
    {
      for (int j = 0; j < i; ++j)
      {
        if (envelopes[i][1] > envelopes[j][1])
        {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }
    return *max_element(dp.begin(), dp.end());
  }
};

int main()
{
  Solution s;
  vector<int> v{1, 2, 3};
  max(v);
}

```

上述程序在如下测试用例会超时：

https://leetcode-cn.com/submissions/detail/284398236/testcase/

