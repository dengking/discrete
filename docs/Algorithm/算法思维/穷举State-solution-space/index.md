# 穷举state space、solution space

正如在discrete book中所说的：

> an important problem- solving skill is the ability to count or enumunate objets

一、这是一种systematic method

二、问题的解空间、可能的组合、罗列所有的可能性、问题的解空间、组合分析

这是系统性地解决问题的第一步

我目前比较熟悉的分析解空间的方式是组合分析，这种分析方法并不能够代表所有，像动态规划的sequence类问题，它的解空间就不是组合分析的。



## 高效的穷举

很多高效的algorithm在于它比较好地罗列了问题的所有可能性，相比与暴力搜索，它高效的多，它们的一般思路为: 

问题的state space、solution space -> 寻找状态转移方程 -> 重叠子问题；高效地进行实现、以空间换时间；

在下面进行了讨论: 

一、`LeetCode\Subsequence-Subarray-Substring\Systematic-method-穷举`

二、`Algorithm\State-space-search`

三、滑动窗口

labuladong [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA) 

其中，对比了滑动窗口和暴力搜索

四、动态规划描述问题的state space

状态有哪些、状态的维度、状态的组合

## Combinational analysis

问题的解空间的构建依赖于combinational analysis中的原理。

