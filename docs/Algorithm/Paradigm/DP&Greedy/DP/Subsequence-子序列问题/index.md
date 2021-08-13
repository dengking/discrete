# DP解子序列类型问题

参考:

一、labuladong 第二章、手把手刷动态规划 # 子序列类型问题

labuladong [子序列解题模板：最长回文子序列](https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA) 

二、LeetCode [【宫水三叶】详解如何分析「序列 DP」问题（附序列 DP 问题目录）](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/gong-shui-san-xie-xiang-jie-ru-he-fen-xi-ykvk/)



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



## 穷举

对于子序列问题，穷举是不可行的，因为它的复杂度是非常高的，在下面文章中，有着非常好的论述:

一、LeetCode [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) 困难

这道题，我一开始就是使用的穷举的方法，在较大深入下，直接超时

二、labuladong [子序列解题模板：最长回文子序列](https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA) 

> 子序列问题是常见的算法问题，而且并不好解决。
>
> 首先，子序列问题本身就相对子串、子数组更困难一些，因为前者是不连续的序列，而后两者是连续的，就算穷举都不容易，更别说求解相关的算法问题了。

