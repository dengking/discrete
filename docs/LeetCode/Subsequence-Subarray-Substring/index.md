# 子序列、子数组、子(字符)串

这类问题是非常常见的问题，涉及到非常多的技巧，是常考题。

## 概念区分

### 子串(substring)、子数组(subarray)

一、子串、子数组是连续的

二、参见 `子串子数组问题` 章节。

### 子序列(subsequence)

一、非连续，但是相对位置是保持不变的，因此它的名称中有"序"

二、参见 `子序列问题` 章节。



## 技巧总结

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

#### 子串、子数组

一、嵌套for循环-left、right双指针

通过嵌套的for循环，枚举中所有可能的子串、子数组情况。

典型例子:

1、最大子数组

`Expert-labuladong\1-动态规划系列\1.2-子序列类型问题\最大子数组`

二、left、right双指针从中间向两边扩散

典型例子:

1、最长回文子串

`Expert-labuladong\Palindrome-回文\最长回文子串`



#### 子序列

一、回溯法穷举

这个问题在 labuladong [子序列解题模板：最长回文子序列](https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA) 有着总结

典型例子:

1、`LeetCode-491-递增子序列`

典型的通过回溯法枚举出所有的可能子序列。



## 常见问题

一、回文

二、最值

三、计数

四、公共


