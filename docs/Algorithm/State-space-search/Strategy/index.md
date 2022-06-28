# state space、solution space的strategy、算法



## 穷举是解决一切问题的基础

素材：

1、在discrete book中所说的：

> an important problem- solving skill is the ability to count or enumunate objets

2、labuladong [我的刷题经验总结](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492216&idx=1&sn=36ae4ac33640cc3814186b75d6c8d368&scene=21#wechat_redirect)

> **如果要让我一句话总结，我想说算法的本质就是「穷举」**。

3、[liuzhenglaichn # Remember during interview](https://liuzhenglaichn.gitbook.io/algorithm/)

> First talk about the brute force solution, then think about better approaches.

一、这是一种systematic method

二、问题的解空间、可能的组合、罗列所有的可能性、问题的解空间、组合分析

这是系统性地解决问题的第一步。

我目前比较熟悉的分析解空间的方式是组合分析，这种分析方法并不能够代表所有，像动态规划的sequence类问题，它的解空间就不是组合分析的。



### 穷举的算法



#### for、brute-force

这种是最最简单的。

#### DFS-backtracking回溯法

1、LeetCode [491. 递增子序列](https://leetcode-cn.com/problems/increasing-subsequences/) 中等

2、



#### BFS-branch-and-bound



#### 二进制枚举

参见 `二进制枚举` 章节。



#### 双指针、滑动窗口





### 高效的穷举

很多高效的algorithm在于它比较好地罗列了问题的所有可能性，相比与暴力搜索，它高效的多，它们的一般思路为: 

问题的state space、solution space -> 寻找状态转移方程 -> 重叠子问题；高效地进行实现、以空间换时间；

在下面进行了讨论: 

一、`LeetCode\Subsequence-Subarray-Substring\Systematic-method-穷举`

二、`Algorithm\State-space-search`



三、滑动窗口

labuladong [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA) 

其中，对比了滑动窗口和暴力搜索

四、动态规划描述问题的state space

状态有哪些、状态的维度、状态的组合；

DP的选择；

#### Compared with brute-force search

通过与brute-force search来进行对比能够更加深入地理解backtracing、Branch-and-bound的思想：

总的来说，无论是backtracing还是branch-and-bound，都是充分运用已知信息来进行剪枝、进行优化、加速搜索，进而避免像暴力搜索那样搜索完整的解空间。





## Algorithm paradigm

本章描述实现search algorithm的常见Paradigm：

| algorithm paradigm | search strategy                               |
| ------------------ | --------------------------------------------- |
| Backtracking       | - Depth-first search                          |
| Branch-and-Bound   | - Breadth-first search<br>- Best-first search |



## Example

LeetCode [413. 等差数列划分](https://leetcode-cn.com/problems/arithmetic-slices/) 中等

