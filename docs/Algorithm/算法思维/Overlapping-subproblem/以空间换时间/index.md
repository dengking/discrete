# Time-space-tradeoff: 以空间换时间

一、当存在overlapping subproblem的时候，就需要考虑"以空间换时间"来提升性能。

二、当超时的时候，就需要考虑如何以空间换时间。

## Dynamic programming / 动态规划

这是最最典型的以空间换时间，将子问题的解保存下来，在下面文章中，有着非常好的分析: 

1、labuladong [动态规划设计之最长递增子序列](https://mp.weixin.qq.com/s/02o_OPgePjaz3dXnw9TA1w)



## 数组算法中的以空间换时间

一、min、max

股票买卖问题

求一个不断扩展的区间中的min、max，可以通过维护min、max而实现，这在 labuladong [LeetCode 股票问题的一种通用解法](https://mp.weixin.qq.com/s/TrN7mMdLEPCmT5mOXzgP5A) 中，进行了详细的说明。

它可以看做是 "以空间换时间"，将 $O(n^2)$​ 穷举 转换为 $O(n)$​ 穷举。



二、最大子数组和问题

这在 `Expert-labuladong\1-动态规划系列\1.2-子序列类型问题\最大子数组` 章节中，进行了讨论。最最常规的实现方式是$O(n^3)$，通过观察递归关系，记录子问题的解，然后根据递归关系，获取更大问题的解，可以将其转换为$O(n^2)$​。

### 找数算法中的以空间换时间

LeetCode [1711. 大餐计数](https://leetcode-cn.com/problems/count-good-meals/)

使用hash map保持数字出现的次数。

> NOTE: 
>
> 在很多的地方都使用了这种用法，比如:
>
> 1、滑动窗口

## LeetCode  [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)

以空间换时间



## hash map 以空间换时间



### LeetCode [1711. 大餐计数](https://leetcode-cn.com/problems/count-good-meals/)



### LeetCode  [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)



## 预处理字符串-加速匹配

一、binary search 二分查找优化subsequence子序列匹配

labuladong [二分查找的妙用：判定子序列](https://mp.weixin.qq.com/s/hWi2hTrQewL_YKioGkXQJg)

LeetCode [392. 判断子序列](https://leetcode-cn.com/problems/is-subsequence/) 简单



二、KMP algorithm



三、滑动窗口



## LeetCode [解数独](https://leetcode-cn.com/problems/sudoku-solver/solution/jie-shu-du-by-leetcode-solution/)

其中就用"以空间换时间"来进行优化。



## Algorithms use memory to gain performance improvement

使用空间换取时间

https://www.sciencedirect.com/topics/computer-science/performance-gain

https://stackoverflow.com/questions/1898161/memory-vs-performance

