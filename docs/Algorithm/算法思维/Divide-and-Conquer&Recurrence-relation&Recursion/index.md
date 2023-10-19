# Divide-and-Conquer&Recurrence-relation&Recursion

本章内容概述: 

一、Divide-and-Conquer的思想是思考**原问题**和**子问题**之间的关系，总结出描述问题的 [recurrence relation](https://en.wikipedia.org/wiki/Recurrence_relation) (是一种 recursive definition)，然后借助recursion来实现进而求解。

上述思想是dynamic programming、greedy algorithm的基石，它们都是从它演变而来。

二、Divide-and-Conquer和Recursion

Divide-and-conquer algorithm 天然地适合于使用 recursion来实现: 

由于 **分治法** 产生的 **子问题** 和 **原问题** 往往是相同**性质**的，因此可以使用递归技术。分治法的核心是把问题的规模降低，因此，在回溯函数的参数中往往有表示问题规模的参数。

draft: 

1、"因此可以使用递归技术"的解释: 递归就是调用自身，也就是执行相同的操作，解决相同的问题

2、所有的recurrence relations，应该都可以使用Divide-and-conquer algorithm来实现



## Algorithm example

使用上述思想对一些algorithm进行分析。

### 二分算法

下面是一些典型的二分算法，即取k=2。

#### [二分搜索](https://en.wikipedia.org/wiki/Binary_search_algorithm)

$$
T(n) = 2T(n/2) = \log_2 n
$$


wikipedia [二分搜索](https://en.wikipedia.org/wiki/Binary_search_algorithm)


参见《`algorithm-analysis-binary-search.md`》

#### [合并排序](https://en.wikipedia.org/wiki/Merge_sort)

$$
T(n) =
\begin{cases}
O(1),  & n \le 1 \\
2T(n/2) + O(n), & n \gt 1
\end{cases}
$$

解上述递归方程，可知
$$
T(n) = O(n\log n)
$$



wikipedia [合并排序](https://en.wikipedia.org/wiki/Merge_sort)


#### [快速排序](https://en.wikipedia.org/wiki/Quicksort)

$$
T(n) =
\begin{cases}
O(1),  & n \le 1 \\
2T(n/2) + O(n), & n \gt 1
\end{cases}
$$

解上述递归方程，可知
$$
T(n) = O(n\log n)
$$

wikipedia [快速排序](https://en.wikipedia.org/wiki/Quicksort) 



### [External sorting](https://en.wanweibaike.com/wiki-External%20sorting)

TODO



### LeetCode

- [LeetCode-23. 合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)  # 方法三：分治合并

自顶向下



- 两数之和、三数之和

参见 labuladong [双指针技巧汇总](https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg) 



- [LeetCode-213. 打家劫舍 II-中等](https://leetcode.cn/problems/house-robber-ii/) 

题目要求不能抢相邻的，并且题目给出的环形数组，所以就可以分为三种情况:<br>1、`[1, n-2]`<br>2、`[0, n-2]`<br>3、`[1, n-1]`<br>然后从上述三种情况中进行择优录取。



- [LeetCode-321. 拼接最大数-困难](https://leetcode.cn/problems/create-maximum-number/) 

题目要求从两个数组中共取出k个数，找出最大的数，该算法依次取出所有的k个数，并进行择优录取。



## Balanced

merge-sort 自己主动就保持了平衡

quick-sort要通过特殊的操作来保持平衡

TODO: unbalanced partition、divide导致的退化





