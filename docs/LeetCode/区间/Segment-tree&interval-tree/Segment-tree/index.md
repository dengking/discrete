# Segment tree

segment=线段

interval=区间

## wikipedia [Segment tree](https://en.wikipedia.org/wiki/Segment_tree)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **segment tree,** also known as a **statistic tree**, is a [tree](https://en.wikipedia.org/wiki/Tree_(data_structure)) [data structure](https://en.wikipedia.org/wiki/Data_structure) used for storing information about [intervals](https://en.wikipedia.org/wiki/Interval_(mathematics)), or segments. It allows querying which of the stored segments contain a given point. It is, in principle, a static structure; that is, it's a structure that cannot be modified once it's built. A similar data structure is the [interval tree](https://en.wikipedia.org/wiki/Interval_tree).

> NOTE:
>
> 一、"storing information about [intervals](https://en.wikipedia.org/wiki/Interval_(mathematics))" 让我想到了  [interval tree](https://en.wikipedia.org/wiki/Interval_tree) 中的 [augmented tree](https://en.wikipedia.org/wiki/Interval_tree#Augmented_tree) 实现方式中的"extra annotation"



### Structure description

> NOTE:
>
> 一、构建方式: 自底向上+两两合并

Let *S* be a set of intervals, or segments. Let *p*1, *p*2, ..., *pm* be the list of distinct interval endpoints, sorted from left to right. Consider the partitioning of the real line induced by those points. The regions of this partitioning are called *elementary intervals*. Thus, the elementary intervals are, from left to right:
$$
(-\infty ,p_{1}),[p_{1},p_{1}],(p_{1},p_{2}),[p_{2},p_{2}],\dots ,(p_{m-1},p_{m}),[p_{m},p_{m}],(p_{m},+\infty)
$$
That is, the list of elementary intervals consists of open intervals between two consecutive endpoints $p_i$ and $p_{i+1}$, alternated with closed intervals consisting of a single endpoint. Single points are treated themselves as intervals because the answer to a query is not necessarily the same at the interior of an elementary interval and its endpoints.

Given a set *I* of intervals, or segments, a segment tree *T* for *I* is structured as follows:

1、*T* is a [binary tree](https://en.wikipedia.org/wiki/Binary_tree).

2、Its [leaves](https://en.wikipedia.org/wiki/Leaf_node) correspond to the elementary intervals induced by the endpoints in *I*, in an ordered way: 

the leftmost leaf corresponds to the leftmost interval, and so on. 

The elementary interval corresponding to a leaf *v* is denoted Int(*v*).

3、The [internal nodes](https://en.wikipedia.org/wiki/Internal_node) of *T* correspond to intervals that are the [union](https://en.wikipedia.org/wiki/Union_(set_theory)) of elementary intervals: the interval Int(*N*) corresponding to node *N* is the union of the intervals corresponding to the leaves of the tree rooted at *N*. That implies that Int(*N*) is the union of the intervals of its two children.

4、Each node or leaf *v* in *T* stores the interval Int(*v*) and a set of intervals, in some data structure. This canonical subset of node *v* contains the intervals [*x*, *x′*] from *I* such that [*x*, *x′*] contains Int(*v*) and does not contain Int(parent(*v*)). That is, each node in *T* stores the segments that span through its interval, but do not span through the interval of its parent.



## cp-algorithms [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html)



## geeksforgeeks [Segment Tree | Sum of given range](https://www.geeksforgeeks.org/segment-tree-sum-of-given-range/)





## LeetCode segment tree

1、cn:

LeetCode.cn [segment tree](https://leetcode.cn/tag/segment-tree/problemset/)

2、en:

[LeetCode-segment tree](https://leetcode.com/tag/segment-tree/) 



## TODO

zhihu [LeetCode . 线段树专题](https://zhuanlan.zhihu.com/p/85846796)

zhihu [线段树(Segment Tree)(上)](https://zhuanlan.zhihu.com/p/436326746)

zhihu [线段树(Segment Tree)专题](https://zhuanlan.zhihu.com/p/40151999)

zhihu [线段树（segment tree)、区间树(interval tree)](https://zhuanlan.zhihu.com/p/105368572)