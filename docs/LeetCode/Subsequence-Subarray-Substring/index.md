# 子序列、子数组、子(字符)串

三者是经常出现的一些说法，其实并没有严格的定义，当碰到类似的问题的时候，我们需要从如下角度来进行思考:

1、是否连续

2、是否需要保持原顺序

这类问题是非常常见的问题，涉及到非常多的技巧，是常考题。



## 概念区分

### 连续

一般称之为子串(substring)、子数组(subarray)，但是在有的题目中子串(substring)、子数组(subarray)也可能是非连续的，因此需要具体问题具体分析。

一、子串、子数组是连续的

二、参见 `子串子数组问题` 章节。

### 非连续

一般称之为子序列(subsequence)

一、非连续，但是相对位置是保持不变的，因此它的名称中有"序"

二、参见 `子序列问题` 章节。



## 常见问题

一、回文

二、最值

三、计数

四、公共



## 算法、复杂度

一、穷举

二、动态规划

三、双指针、滑动窗口

四、二分查找



### state space、solution space、穷举、systematic method

这个问题在 labuladong [子序列解题模板：最长回文子序列](https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA) 有着总结: 

> 子序列问题是常见的算法问题，而且并不好解决。
>
> 首先，子序列问题本身就相对子串、子数组更困难一些，因为前者是不连续的序列，而后两者是连续的，就算穷举都不容易，更别说求解相关的算法问题了。

labuladong [LeetCode 股票问题的一种通用解法](https://mp.weixin.qq.com/s/TrN7mMdLEPCmT5mOXzgP5A)

穷举所有可能的组合



## subsequence子序列 VS subarray子数组、substr子(字符)串

一、DP

参见对应章节

二、complexity: $O(N^2)$ VS $O(N)$

对于子序列问题，追求 $O(N^2)$ 的复杂度；

对于子数组问题，追求 $O(N)$ 的复杂度； 

三、滑动窗口

subsequence子序列 不适合使用 滑动窗口；

subarray子数组、substr子(字符)串 适合使用 滑动窗口；