# 连续子数组、子串问题

一、子串、子数组是连续的；

二、字符串其实可以看做是array of character，因此子串问题和子数组问题非常类似，很多情况下可以使用相同的算法，因此可以将它们放在一起讨论。

## 穷举

嵌套for循环(left、right双指针)，通过嵌套的for循环，枚举中所有可能的子串、子数组情况。

典型例子:

1、最大子数组

`Expert-labuladong\1-动态规划系列\1.2-子序列类型问题\最大子数组`

实现上最简单，但是复杂度较高。

### 复杂度

与实现的方式有关:

1、$O(N^3)$​



## 动态规划



### 最大子数组和

参见 `Expert-labuladong\1-动态规划系列\1.2-子序列类型问题\最大子数组` 。



### LeetCode-连续1

参见 `LeetCode-连续1` 章节。



## 双指针 double pointer

left、right双指针从中间向两边扩散

### 最长回文子串

`Expert-labuladong\Palindrome-回文\最长回文子串`

$O(N)$



## 相关章节

在下面章节中，对子串、子数组相关问题进行了总结: 

一、`滑动窗口算法解决子串问题`

二、`最长回文子串`



## 例题



### 等差子数组

LeetCode [413. 等差数列划分](https://leetcode-cn.com/problems/arithmetic-slices/) 中等

动态规划 $O(N)$



### 加油站

一、labuladong [当老司机学会了贪心算法](https://mp.weixin.qq.com/s/k-z_oewAqMYc3vpmOm4gEQ) # LeetCode [134. 加油站](https://leetcode-cn.com/problems/gas-station/)

