# 动态规划



## DP状态机、状态转移方程



一、从下面几个角度来进行讨论:

1、"DP状态机"、"状态转移方程"描述的是"**原问题**"和"**子问题**"之间的函数关系

2、所谓"状态"，它描述的是问题的规模

3、DP table的定义

它一般记录问题的解

显然它的维度是由"状态"的维度决定的

4、选择

二、

一提到“动态规划”算法我首先想到的是二维数组，在我的印象中动态规划算法就是一个对二维数组进行填值的过程，这个数组作为它按照一定的计算方法能够计算出矩阵中每个位置的值，并且在计算后面值时会用到前面的值。

在课本的例子中，能够使用动态规划算法解决的问题都具有最优子结构性质，也就是问题的最优解包含其子问题的最优解（当我在用动态规划解决问题的时候，用数学公式描述出这种关系是解决这个问题的核心所在）注意这样的描述本来就包含递归的思想。动态规划算法所维护的二维数组m[i][j]值表示子问题i到j的最优值。

动态规划算法也是从底层到高层，从子问题到完全问题逐渐来解决问题的。





## 动态规划问题的分类

### 分类方法一

一、计数

由于DP是会进行穷举的，因此可以实现计数，下面是相关例题: 

LeetCode [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) 困难



二、求解最值

最长递增子序列 LeetCode [300. 最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)。

LeetCode [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)

LeetCode [518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/)

### 分类方法二

一、子序列

参见 `Subsequence-子序列问题` 章节。



## 动态规划复杂度分析

一、动态规划是否能够实现 $O(N)$​ 的复杂度？

动态规划算法的复杂度和动态规划算法本身没有关系，而是和具体问题相关的:

1、最大子数组和使用动态规划是否能够实现 $O(N)$ 复杂度

参见 labuladong [动态规划套路：最大子数组和](https://mp.weixin.qq.com/s/nrULqCsRsrPKi3Y-nUfnqg)

> NOTE: 
>
> 子数组问题的理想复杂度就是$O(N)$

2、很多**子序列**问题，复杂度都为$O(N^2)$

关于这一点，是我在阅读 LeetCode [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) 困难 # [【负雪明烛】揭秘子序列动态规划的套路](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/fu-xue-ming-zhu-jie-mi-zi-xu-lie-dong-ta-gepk/) 时，想到的。



## TODO



berkeley [Chapter 6 Dynamic programming](https://people.eecs.berkeley.edu/~vazirani/algorithms/chap6.pdf)



## 素材

1、"wikipedia [Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science)) # Recursive functions and algorithms"
