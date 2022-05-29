# leetcode [1062. 最长重复子串](https://leetcode-cn.com/problems/longest-repeating-substring/) 中等

## [C++ 二分 + Rabin-Karp](https://leetcode-cn.com/problems/longest-repeating-substring/solution/c-er-fen-rabin-karp-by-sad-swirlesuwf-uspp/)





## [DP动态规划](https://leetcode-cn.com/problems/longest-repeating-substring/solution/dpdong-tai-gui-hua-by-johnkle-zyw8/)

```python
class Solution:
    def longestRepeatingSubstring(self, s):
        n = len(s)
        res = 0
        #dp[i][j] 分别以s[i]和s[j]结尾的重复子串的长度
        dp = [[0]*(n+1) for _ in range(n+1)]
        for i in range(1,n+1):
            for j in range(i+1,n+1):
                if s[i-1] == s[j-1]:
                    dp[i][j] = dp[i-1][j-1]+1
                res = max(res,dp[i][j])
        return res

```

> NOTE:
>
> 一、典型的穷举
>
> 二、需要注意的是，由于递归方程使用的是`-1`，因此需要考虑underflow的情况，所以将解整体移动了一格
>
> 三、上述dp仅仅使用了由上角
>
> 四、下面是c++解法：
>
> ```c++
> #include <iostream>
> #include <string>
> #include <algorithm>
> #include <vector>
> #include <bitset>
> #include <map>
> #include <stack>
> #include <unordered_map>
> #include <unordered_set>
> #include <cmath>
> using namespace std;
> 
> class Solution
> {
> public:
>   int longestRepeatingSubstring(string s)
>   {
>     int n = s.size();
>     vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
>     int res = 0;
>     for (int i = 1; i < n + 1; ++i)
>     {
>       for (int j = i + 1; j < n + 1; ++j)
>       {
>         if (s[i - 1] == s[j - 1]) // 转换为数组下标
>         {
>           dp[i][j] = dp[i - 1][j - 1] + 1;
>         }
>         res = max(res, dp[i][j]);
>       }
>     }
>     return res;
>   }
> };
> 
> ```
>
> 

