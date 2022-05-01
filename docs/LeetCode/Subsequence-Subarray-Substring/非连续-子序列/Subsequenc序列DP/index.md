# DP解子序列类型问题

如果子序列不满足单调性，但是具备最优子结构，在求最值问题的时候，可以使用动态规划算法。

参考:

一、labuladong 第二章、手把手刷动态规划 # 子序列类型问题

labuladong [子序列解题模板：最长回文子序列](https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA) 

二、宫水三叶

LeetCode [【宫水三叶】详解如何分析「序列 DP」问题（附序列 DP 问题目录）](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/gong-shui-san-xie-xiang-jie-ru-he-fen-xi-ykvk/)

https://github.com/SharingSource/LogicStack-LeetCode/wiki/%E5%BA%8F%E5%88%97-DP



## 子序列问题总结

在 labuladong [子序列解题模板：最长回文子序列](https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA) 中，对各种可能的情况进行了非常好的总结:

|      | 一个序列                                                     | 两个序列       |
| ---- | ------------------------------------------------------------ | -------------- |
| 一维 | 最长递增子序列、<br>最大子数组和 (`array[i]`结尾的目标子序列)、<br/>等差子序列 | 最长回文子序列 |
| 二维 |                                                              |                |
| 三维 |                                                              |                |



## 各种各样的问题

单个子序列

|            | 章节                                                         | 例题 |
| ---------- | ------------------------------------------------------------ | ---- |
| 递增子序列 | `Expert-labuladong\1-动态规划系列\1.2-子序列类型问题\LIS-最长递增子序列` |      |
| 等差子序列 | `LeetCode-446-等差数列划分-II-子序列-困难`                   |      |
| 回文子序列 |                                                              |      |



## TODO

https://stackoverflow.com/questions/tagged/dynamic-programming?tab=Active

序列问题与多条规划算法



# 序列DP



可以按照如下的方式来进行划分：

1、单个序列

2、两个序列

