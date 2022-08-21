# 子序列(subsequence)

subsequence的特征：

1、非连续

2、相对位置是保持不变的

## wikipedia [Subsequence](https://en.wikipedia.org/wiki/Subsequence)



## 穷举

对于子序列问题，穷举是不可行的，因为它的复杂度是非常高的，在下面文章中，有着非常好的论述:

一、LeetCode [446. 等差数列划分 II - 子序列](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/) 困难

这道题，我一开始就是使用的穷举的方法，在较大输入下，直接超时

二、labuladong [子序列解题模板：最长回文子序列](https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA) 

> 子序列问题是常见的算法问题，而且并不好解决。
>
> 首先，子序列问题本身就相对子串、子数组更困难一些，因为前者是不连续的序列，而后两者是连续的，就算穷举都不容易，更别说求解相关的算法问题了。

但是，有的时候，还是要进行穷举，那如何进行穷举呢？

### 回溯法

一、LeetCode [491. 递增子序列](https://leetcode.cn/problems/increasing-subsequences/) 中等，这是典型例子，它通过剪枝来选择符合条件的、去重

二、LeetCode [446. 等差数列划分 II - 子序列](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/) 困难，在这道题中，我刚开始使用回溯法进行穷举，结果超时。

三、这个问题在 labuladong [子序列解题模板：最长回文子序列](https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA) 有着总结



## 滑动窗口

需要注意，滑动窗口是不能够用来解子序列问题的，这在下面的文章中进行了说明：

1、[446. 等差数列划分 II - 子序列](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/) # [liweiwei1419](https://leetcode.cn/u/liweiwei1419/) # [动态规划（Java）](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence/solution/dong-tai-gui-hua-java-by-liweiwei1419-jc84/)



## 动态规划

参见 `Subsequenc序列DP` 章节。



## 二分搜索

二分搜索

> NOTE: 
>
> 1、动态规划和双指针滑动窗口都可以用于解决子序列的最优化问题
>
> 2、但是两者适用的问题不同，有必要进行总结
>
> 



### 二分查找的妙用判定子序列

二分法也可以用于子序列。



## 单调栈

一、由于子序列要求保持相对顺序，并且可以不连续，对于这类问题，单调栈是可以使用的。

二、这类问题的特征是：

1、移除部分

2、最值问题

它们都可以转换为和字典序相关的。

三、在对应的章节中，有着非常好的描述

## LeetCode 子序列类问题

https://leetcode.cn/problemset/all/?search=%E5%AD%90%E5%BA%8F%E5%88%97

