# 股票问题系列

## 买卖一次 k = 1

#### LeetCode [剑指 Offer 63. 股票的最大利润](https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/) 中等

假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？



#### LeetCode [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/) 简单



给定一个数组 prices ，它的第 i 个元素 `prices[i]` 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

## 不限买卖次数 k=infinity

#### LeetCode [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/) 简单

给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。



## 买卖两次 k = 2

#### LeetCode [123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/) 困难



## 买卖 k 次

#### LeetCode [188. 买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/) 困难 



## 不限买卖次数 + 冷冻期

#### LeetCode [309. 最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/) 中等

给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

1、你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

2、卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。



## 不限买卖次数 + 手续费

#### LeetCode [714. 买卖股票的最佳时机含手续费](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/) 中等

给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。



## leetcode [『 动态规划 』 DP模板解决一众买卖股票问题](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/solution/by-flix-us00/)



```python
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:

        n = len(prices)
        if n<2 or k==0:
            return 0
        
        k = min(k, n//2)        # n 天最多只能进行 n/2 笔交易
        dp = [[[0]*2 for j in range(k+1)] for _ in range(n)]
        
        # 将不合理的初始状态统统设为一个较大的负值
        for j in range(k+1):
            dp[0][j][1] = float('-inf')
            dp[0][j][0] = float('-inf')
        
        # 合理的初始化
        dp[0][0][0] = 0
        dp[0][1][1] = -prices[0]

        # 状态转移
        for i in range(1, n):
            for j in range(1, k+1):
                dp[i][j][1] = max(dp[i-1][j][1], dp[i-1][j-1][0] - prices[i])
                dp[i][j][0] = max(dp[i-1][j][0], dp[i-1][j][1] + prices[i])
        
        # j次买卖股票后的最大值即为最大利润
        return max(dp[n-1][j][0] for j in range(k+1))   


```

