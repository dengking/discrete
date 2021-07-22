# 子序列、子数组、子(字符)串



## 子序列(subsequence)

非连续，但是相对位置是保持不变的。

### 常用解法

常用解法:

1、如果"子序列、单调、最优化问题"，则可以使用滑动窗口

2、如果子序列，不满足单调性，但是具备最优子结构，在求最值问题的时候，可以使用动态规划算法

3、二分搜索

### draft

1、动态规划和双指针滑动窗口都可以用于解决子序列的最优化问题

2、但是两者适用的问题不同，有必要进行总结

### `二分查找的妙用判定子序列`

二分法也可以用于子序列。



### labuladong [子序列解题模板：最长回文子序列](https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA)

子序列问题是常见的算法问题，而且并不好解决。

首先，子序列问题本身就相对子串、子数组更困难一些，因为前者是不连续的序列，而后两者是连续的，就算穷举都不容易，更别说求解相关的算法问题了。



### LeetCode 子序列类问题

https://leetcode-cn.com/problemset/all/?search=%E5%AD%90%E5%BA%8F%E5%88%97

## 子串

子串: 连续的

### 章节

在下面章节中，对子串相关问题进行了总结: 

`滑动窗口算法解决子串问题`

`最长回文子串`

### 问题

#### leetcode [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) 中等



## 穷举、systematic method

这个问题在 labuladong [子序列解题模板：最长回文子序列](https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA) 有着总结: 

> 子序列问题是常见的算法问题，而且并不好解决。
>
> 首先，子序列问题本身就相对子串、子数组更困难一些，因为前者是不连续的序列，而后两者是连续的，就算穷举都不容易，更别说求解相关的算法问题了。



### 子串、子数组

一、嵌套for循环-left、right双指针

通过嵌套的for循环，枚举中所有可能的子串、子数组情况。

典型例子:

1、最大子数组

`Expert-labuladong\1-动态规划系列\1.2-子序列类型问题\最大子数组`

二、left、right双指针从中间向两边扩散

典型例子:

1、最长回文子串

`Expert-labuladong\Palindrome-回文\最长回文子串`



### 子序列

一、回溯法穷举

这个问题在 labuladong [子序列解题模板：最长回文子序列](https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA) 有着总结

典型例子:

1、`LeetCode-491-递增子序列`

典型的通过回溯法枚举出所有的可能子序列。



### 高效的穷举