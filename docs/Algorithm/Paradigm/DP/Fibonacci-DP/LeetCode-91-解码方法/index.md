# leetcode [91. 解码方法](https://leetcode.cn/problems/decode-ways/) 中等

## 我的解题

`F(N)` 表示长度为`N`的字符串的解码方法，思考: `F(N)` 和 `F(N-1)`的关系，新加的这个数，可以独自构成一个数，也可以和前面的数一起构成一个数。

```
F(N) = 
F(N-1) // 最后一个数，独自作为一个字母
 + 
F(N-2) // 最后一个数，和它前面的一个数一起作为一个字母
```

另外需要注意的是，这道题在上述递归公式的基础上增加了很多限制条件，这是增加题目难度的一些寻常做法：

1、连续两位数，如果大小超过26是不能够连在一起的

2、一些不可能的情况

```
输入
"22345457890"
输出
3
预期结果
0
```

3、10只能够放到一起，因此它需要看做是一个单独的元素。

关于0的处理，如果碰到0，那么它只能等于 F(N-2)

### 完整代码

```C++
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
  int numDecodings(string s)
  {
    int N = s.size();
    vector<int> dp(N + 1); // +1 是因为可以需要考虑长度为0
    dp[0] = 1;             //对于计数问题，dp[0] = 1 是常规操作，它表示有一种编码方法
    // 下面分两种情况讨论:
    // 1、为'0'
    // 2、不为'0'
    for (int i = 1; i <= N; ++i)
    {
      if (s[i - 1] == '0') // 需要考虑长度到下标的转换
      {
        if (i <= 1)
        {
          dp[i] = 0;
          return 0;
        }
        else
        {
          if (s[i - 2] == '1' || s[i - 2] == '2') // 前一位数这两个数，才能够形成有个有效的二位数
            dp[i] = dp[i - 2];                    //
          else
            return 0;
        }
      }
      else
      {
        dp[i] = dp[i - 1]; // 单独映射到一个字母
        if (i >= 2)        //考虑两位
        {
          if (s[i - 2] == '0') // 前一位数0，则不需要考虑两者形成两位数
          {
            continue;
          }
          else
          {
            auto ss = s.substr(i - 2, 2);
            if (atoi(ss.c_str()) <= 26) // 需要考察两位数能否映射为一个字母
              dp[i] += dp[i - 2];
          }
        }
      }
    }
    return dp[N];
  }
};

int main()
{
}
```

