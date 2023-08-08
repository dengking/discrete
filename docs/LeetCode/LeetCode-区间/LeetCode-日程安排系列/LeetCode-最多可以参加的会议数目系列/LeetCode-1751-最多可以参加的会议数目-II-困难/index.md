# [LeetCode-1751. 最多可以参加的会议数目 II-困难](https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended-ii/)

这道题是在阅读 [宫水三叶-【面试高频题】难度 2/5，结合二分的序列 DP 运用题](https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==\&mid=2247490648\&idx=1\&sn=9212ffccd1b29a129c63cfb5a7dfd0e4) 时发现的。



## [宫水三叶-【面试高频题】难度 2/5，结合二分的序列 DP 运用题](https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==\&mid=2247490648\&idx=1\&sn=9212ffccd1b29a129c63cfb5a7dfd0e4)

> NOTE: 这个题目和背包DP有些类似。

定义 `f[i][j]` 为考虑前 `i` 个事件，选择不超过 `j` 的最大价值。

对于每个事件，都有选择与不选两种选择：

1、不选: `f[i][j]=f[i-1][j]`

2、选: 找到第 `i` 件事件之前，与第 `i` 件事件不冲突的事件，记为 last，则有 `f[i][j]=f[last][j-1]+value_i`

两者取 `max `，则是`f[i][j]`  的值。

