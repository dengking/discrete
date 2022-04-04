# leetcode [746. 使用最小花费爬楼梯](https://leetcode-cn.com/problems/min-cost-climbing-stairs/) 简单



## 我的解题

```
dp[i] = min(dp[i-1]+cost[i-1], dp[i-2]+cost[i-2])
```

