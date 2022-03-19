# 不含重复字符的子字符串

## leetcode [剑指 Offer 48. 最长不含重复字符的子字符串](https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/) 中等

这题是判断不含重复字符的子字符串



## leetcode [1062. 最长重复子串](https://leetcode-cn.com/problems/longest-repeating-substring/) 中等

### [C++ 二分 + Rabin-Karp](https://leetcode-cn.com/problems/longest-repeating-substring/solution/c-er-fen-rabin-karp-by-sad-swirlesuwf-uspp/)

### [DP动态规划](https://leetcode-cn.com/problems/longest-repeating-substring/solution/dpdong-tai-gui-hua-by-johnkle-zyw8/)

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



leetcode [1044. 最长重复子串](https://leetcode-cn.com/problems/longest-duplicate-substring/) 中等

