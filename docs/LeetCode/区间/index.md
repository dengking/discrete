# 区间问题

一、区间问题其实也是可以使用left- right double pointer来进行解释的，关于这一点，是在leetcode [Ikaruga](https://leetcode-cn.com/u/ikaruga/) [【合并区间】排序 + 双指针](https://leetcode-cn.com/problems/merge-intervals/solution/merge-intervals-by-ikaruga/) 上提出的



素材：

1、emre [Coding Patterns: Merge Intervals](https://emre.me/coding-patterns/merge-intervals/)

2、**甜姨的奇妙冒险** [秒懂力扣区间题目：重叠区间、合并区间、插入区间](https://mp.weixin.qq.com/s/ioUlNa4ZToCrun3qb4y4Ow)

二、区间交集个数



## 俄罗斯套娃

在下面的文章中，进行了介绍：

1、labuladong [最长递增子序列之信封嵌套问题](https://mp.weixin.qq.com/s/PSDCjKlTh8MtANdgi-QIug) 

> 这道题目其实是最长递增子序列（Longes Increasing Subsequence，简写为 LIS）的一个变种，因为很显然，每次合法的嵌套是大的套小的，相当于找一个最长递增的子序列，其长度就是最多能嵌套的信封个数。

2、[**甜姨的奇妙冒险** # 秒懂力扣区间题目：重叠区间、合并区间、插入区间](https://mp.weixin.qq.com/s/ioUlNa4ZToCrun3qb4y4Ow)

> 本题实质是求最长嵌套区间的长度，是经典题目「最长上升子序列」的变种，解法也一模一样，有动态规划 $O(N^2)$和 二分 $O(Nlog(N))$两种经典解法。

