# leetcode [115. 不同的子序列](https://leetcode-cn.com/problems/distinct-subsequences/)



一、典型的使用dynamic programming来解决字符串序列问题

二、它的递归方程和最长公共子序列的方程方程类似: 

> 所以动态方程:
>
> 当 $S[j] == T[i]$ , $dp[i][j] = dp[i-1][j-1] + dp[i][j-1]$;
>
> 当 $S[j] != T[i]$ , $dp[i][j] = dp[i][j-1]$
>
> 作者：powcai
> 链接：https://leetcode-cn.com/problems/distinct-subsequences/solution/dong-tai-gui-hua-by-powcai-5/
> 来源：力扣（LeetCode）
> 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

三、如何理解上述递归方程呢？

1、`baba*`、 `ba*`，当添加`g`，则新序列的的个数有如下决定: 

a、子序列: `baba` 、`ba`

b、子序列