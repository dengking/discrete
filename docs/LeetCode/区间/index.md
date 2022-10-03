# 区间问题



### Time-based interval

对于time-based interval，由于time是定向的有序的，因此这类问题往往是基于sorted的，因此它往往涉及如下:

一、sorted-ordered-data-structure

二、binary-search

三、sort



## Merge Intervals

参见 `Merge-intervals` 章节。



## Intersection count

区间交集个数。

例题:

一、我的日常安排系列



## 俄罗斯套娃

在下面的文章中，进行了介绍：

1、labuladong [最长递增子序列之信封嵌套问题](https://mp.weixin.qq.com/s/PSDCjKlTh8MtANdgi-QIug) 

> 这道题目其实是最长递增子序列（Longes Increasing Subsequence，简写为 LIS）的一个变种，因为很显然，每次合法的嵌套是大的套小的，相当于找一个最长递增的子序列，其长度就是最多能嵌套的信封个数。

2、[**甜姨的奇妙冒险** # 秒懂力扣区间题目：重叠区间、合并区间、插入区间](https://mp.weixin.qq.com/s/ioUlNa4ZToCrun3qb4y4Ow)

> 本题实质是求最长嵌套区间的长度，是经典题目「最长上升子序列」的变种，解法也一模一样，有动态规划 $O(N^2)$和 二分 $O(Nlog(N))$两种经典解法。

