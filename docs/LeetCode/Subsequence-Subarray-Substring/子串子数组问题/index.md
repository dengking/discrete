# 子数组、子串问题

字符串其实可以看做是array of character，因此子串问题和子数组问题非常类似，很多情况下可以使用相同的算法，因此可以将它们放在一起讨论。

子串、子数组是连续的；

## 算法、复杂度

一、动态规划

二、双指针、滑动窗口

### 穷举

实现上最简单，但是复杂度较高。

#### 复杂度

与实现的方式有关:

1、$O(N^3)$​



### 动态规划

参见:

一、`DP解子序列问题`



#### 复杂度

视具体问题而定:

1、$O(N)$ (可以实现)

2、$O(N^2)$​



### 双指针 double pointer



#### 复杂度

$O(N)$



## 相关章节

在下面章节中，对子串、子数组相关问题进行了总结: 

一、`滑动窗口算法解决子串问题`

二、`最长回文子串`



## 例题



### 等差子数组

LeetCode [413. 等差数列划分](https://leetcode-cn.com/problems/arithmetic-slices/) 中等

动态规划 $O(N)$



### 最大子数组和

参见 `Expert-labuladong\1-动态规划系列\1.2-子序列类型问题\最大子数组` 

动态规划 $O(N)$



### 加油站

一、labuladong [当老司机学会了贪心算法](https://mp.weixin.qq.com/s/k-z_oewAqMYc3vpmOm4gEQ) # LeetCode [134. 加油站](https://leetcode-cn.com/problems/gas-station/)

