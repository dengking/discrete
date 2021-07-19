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



## TODO

berkeley [Chapter 6 Dynamic programming](https://people.eecs.berkeley.edu/~vazirani/algorithms/chap6.pdf)



## 素材

1、"wikipedia [Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science)) # Recursive functions and algorithms"



## LeetCode

LeetCode [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)

LeetCode [518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/)

