# [91. 解码方法](https://leetcode-cn.com/problems/decode-ways/)

## 我的解题

10只能够放到一起，因此它需要看做是一个单独的元素。

思考: F(N) 和 F(N-1)的关系，新加的这个数，可以独自构成一个数，也可以和前面的数一起构成一个数。

```
F(N) = 
F(N-1) // 最后一个数，独自作为一个字母
 + 
F(N-2) // 最后一个数，和它前面的一个数一起作为一个字母
```



关于0的处理，如果碰到0，那么它只能等于 F(N-2)

```C++
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <variant>
using namespace std;
class Solution
{
public:
    int numDecodings(string s)
    {
        int N = s.size();
        vector<int> dp(N + 1);
        dp[0] = 1;
        for (int i = 0; i < N; ++i)
        {
            if (s[i] == '0')
            {
                if (i < 1)
                {
                    dp[i + 1] = 0;
                }
                else
                {
                    dp[i + 1] = dp[i - 1];
                }
            }
            else
            {
            }
        }
        return dp[N];
    }
};
```

