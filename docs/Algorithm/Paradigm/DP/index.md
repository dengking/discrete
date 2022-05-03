# 动态规划



## DP VS DFS

DP本质上还是从解空间穷举、状态空间穷举，这一点和DFS 是相同的：

一、无论是DP还是回溯法都是基于选择来对问题进行建模的、都是基于**选择**，**选择**导致状态的转移：

1、在DFS中，状态转移对应的是：

a、递归进入到下一层；

b、从解空间的上一个节点进入到了下一个节点；

c、从graph或tree的上一个节点到下一个节点；

2、在DP中，选择导致状态的转移：

二、问题规模、状态的描述

1、在DFS中，问题的规模、状态一般通过递归函数的参数来进行描述。

在DFS中，我们一般将问题的规模通过函数的入参数进行传入，其实这个入参对应的是动态规划的状态，也就是动态规划的状态其实和问题的规模密切相关，关于这一点，在 labuladong [毕 业 旅 行](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491204&idx=1&sn=3f03f4da933ffa0baf4eb05f444d85e3&scene=21#wechat_redirect) / [旅游省钱大法：加权最短路径](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491204&idx=1&sn=3f03f4da933ffa0baf4eb05f444d85e3&scene=21#wechat_redirect) 中的例子能够非常好的说明。其实这是能够说通的，因为我们动态规划就是将子问题的结果给保存下来，所以它的状态就是和子问题相对应的。

2、动态规划也是如此，所不同的是，它将结果给保存下来了。

最最能够体现它们之间关联的是如下例子：

a、labuladong [毕 业 旅 行](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491204&idx=1&sn=3f03f4da933ffa0baf4eb05f444d85e3&scene=21#wechat_redirect) / [旅游省钱大法：加权最短路径](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491204&idx=1&sn=3f03f4da933ffa0baf4eb05f444d85e3&scene=21#wechat_redirect)

三、解的保存；

DFS with return value；

DP- table将问题的解保存下来；

让我想起这个点的是：

1、存在性问题

a、背包DP存在性问题

b、之前写的DFS的存在性问题：当使用DFS解存在性问题的时候，通过return bool来判断。

2、labuladong [毕 业 旅 行](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491204&idx=1&sn=3f03f4da933ffa0baf4eb05f444d85e3&scene=21#wechat_redirect) / [旅游省钱大法：加权最短路径](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491204&idx=1&sn=3f03f4da933ffa0baf4eb05f444d85e3&scene=21#wechat_redirect) 中展示的基于DFS 的最值问题



四、子问题的相互独立。



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

在课本的例子中，能够使用动态规划算法解决的问题都具有最优子结构性质，也就是问题的最优解包含其子问题的最优解（当我在用动态规划解决问题的时候，用数学公式描述出这种关系是解决这个问题的核心所在）注意这样的描述本来就包含递归的思想。动态规划算法所维护的二维数组`m[i][j]`值表示子问题i到j的最优值。

动态规划算法也是从底层到高层，从子问题到完全问题逐渐来解决问题的。



## 动态规划问题的分类

### 分类方法一

一、计数

> NOTE:
>
> tag-DP解计数问题

由于DP是会进行穷举的，因此可以实现计数。

二、求解最值



### 分类方法二

一、子序列

参见 `非连续-子序列` 章节。

二、子数组

参见 `连续-子串子数组` 章节。

三、DP解最短路径问题

四、数位DP

五、区间DP





## 动态规划复杂度分析

一、动态规划是否能够实现 $O(N)$​ 的复杂度？

动态规划算法的复杂度和动态规划算法本身没有关系，而是和具体问题相关的:

### $O(N)$ 复杂度

一、一些子数组问题可以实现$O(N)$ 复杂度

1、最大子数组和使用动态规划是否能够实现 $O(N)$ 复杂度

参见 labuladong [动态规划套路：最大子数组和](https://mp.weixin.qq.com/s/nrULqCsRsrPKi3Y-nUfnqg)

> NOTE: 
>
> 子数组问题的理想复杂度就是$O(N)$

2、LeetCode [413. 等差数列划分](https://leetcode-cn.com/problems/arithmetic-slices/) 中等

等差子数组的个数



### $O(N^2)$ 复杂度

一、很多**子序列**问题，复杂度都为$O(N^2)$​​​ 复杂度

关于这一点，是我在阅读 LeetCode [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) 困难 # [【负雪明烛】揭秘子序列动态规划的套路](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/fu-xue-ming-zhu-jie-mi-zi-xu-lie-dong-ta-gepk/) 时，想到的。



## 素材

1、wikipedia [Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science)) # Recursive functions and algorithms

2、berkeley [Chapter 6 Dynamic programming](https://people.eecs.berkeley.edu/~vazirani/algorithms/chap6.pdf)

