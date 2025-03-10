# Segment tree

一. 

segment=线段

interval=区间

借助segment tree，可以实现关于区间统计的一类问题。

二. 

左右两个节点的区间不重叠



三. 线段树是否只能够处理离散的点？使用segment tree之前需要考虑如何定义区间，最最典型的例子是range sum query，它是基于array的，它的range是array index。

sweep line algorithm也是将line segment离散化后进行处理的

1、[LeetCode-218. The Skyline Problem](https://leetcode.cn/problems/the-skyline-problem/) 

输入是区间，需要首先将区间离散化然后再构建线段树



四、segment tree 和 merge sort非常类似: 

1、segment tree不需要考虑balanced的问题，因为它的一分为二是等分，并且它是perfect-binary-tree。

2、segment tree是典型的一分为二(top-down-pre-order-action)+两两合并(bottom-up-post-order-action)，它是dfs recursion的典型的模板，这一点它和merge sort非常类似。所以segment tree是left、right是相同的

![img](https://media.geeksforgeeks.org/wp-content/cdn-uploads/segment-tree1.png)

参考自: geeksforgeeks [Lazy Propagation in Segment Tree](https://www.geeksforgeeks.org/lazy-propagation-in-segment-tree/)



3、理解它的最最简单的case就是由四个元素组成的array。



## wikipedia [Segment tree](https://en.wikipedia.org/wiki/Segment_tree)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **segment tree,** also known as a **statistic tree**, is a [tree](https://en.wikipedia.org/wiki/Tree_(data_structure)) [data structure](https://en.wikipedia.org/wiki/Data_structure) used for storing information about [intervals](https://en.wikipedia.org/wiki/Interval_(mathematics)), or segments. It allows querying which of the stored segments contain a given point. It is, in principle, a static structure; that is, it's a structure that cannot be modified once it's built. A similar data structure is the [interval tree](https://en.wikipedia.org/wiki/Interval_tree).

> NOTE:
>
> 一、"storing information about [intervals](https://en.wikipedia.org/wiki/Interval_(mathematics))" 让我想到了  [interval tree](https://en.wikipedia.org/wiki/Interval_tree) 中的 [augmented tree](https://en.wikipedia.org/wiki/Interval_tree#Augmented_tree) 实现方式中的"extra annotation"
>
> 二、application:
>
> 1、It allows querying which of the stored segments contain a given point



### Description

> NOTE:
>
> 一、构建方式: 一分为二(top-down-pre-order-action)+两两合并(bottom-up-post-order-action)

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



### Generalization for higher dimensions

The **segment tree** can be generalized to higher dimension spaces, in the form of multi-level segment trees. In higher dimensional versions, the **segment tree** stores a collection of axis-parallel (hyper-)rectangles, and can retrieve the rectangles that contain a given query point.

> NOTE:
>
> 一、素材: 
>
> 1、cp-algorithms [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html) 中对此进行了介绍
>
> 2、[LeetCode-304. Range Sum Query 2D - Immutable-medium](https://leetcode.cn/problems/range-sum-query-2d-immutable/)
>
> 3、geeksforgeeks [Two Dimensional Segment Tree | Sub-Matrix Sum](https://www.geeksforgeeks.org/two-dimensional-segment-tree-sub-matrix-sum/)
>
> 

## segment tree、perfect binary tree

segment tree是以perfect binary tree的方式进行存储，关于此，参见:

一、挑战程序设计竞赛:

> 线段树是一棵完美二叉树(perfect binary tree)

二、stackoverflow [How is the memory of the array of segment tree 2 * 2 ^(ceil(log(n))) - 1?](https://stackoverflow.com/questions/28470692/how-is-the-memory-of-the-array-of-segment-tree-2-2-ceillogn-1) # [A](https://stackoverflow.com/a/28502243) 

其中的计算方式就是将它看做是一棵完美二叉树(perfect binary tree)



## Operation+implementation



两种写法: 

1、简化写法: cp-algorithms [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html) 

base case、empty case

min、max妙用

2、复杂写法: [LeetCode-Recursive Approach to Segment Trees](https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/) 



### Build



### Update

1、element update

2、range update（涉及lazy propagation）

参见:

cp-algorithms [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html) 

#### Element update

element update的第一步是需要找到对应的元素，然后执行update，找到元素的过程类似于binary search。

element update和build的实现非常类似: 都需要读取值然后自动向上、两两合并，所不同的是，update的值是从外面传入的，build的值是从array中读取的；另外update只需要对半边树执行，build则是两边都需要执行。

不断逼近，必然会相逢。

#### Range update

##### lazy propagation

一、动态开点

zhihu [数据结构学习笔记(5)动态开点线段树](https://zhuanlan.zhihu.com/p/559047943) 

二、lazy propagation

geeksforgeeks [Lazy Propagation in Segment Tree](https://www.geeksforgeeks.org/lazy-propagation-in-segment-tree/)

[LeetCode-segment tree](https://leetcode.com/tag/segment-tree/) 



### Query

cp-algorithms [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html) 、[LeetCode-segment tree](https://leetcode.com/tag/segment-tree/) 中query的实现方式不同:

cp-algorithms [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html) 中: 

1、base case: segment == range

2、empty exception case: range invalid(fall back)

3、recession: segment != range

[LeetCode-segment tree](https://leetcode.com/tag/segment-tree/) 中:

1、base case: segment <= range

2、empty exception case: range invalid(fall back)

3、recession: segment > range



cp-algorithms [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html) 中虽然base case相比于[LeetCode-segment tree](https://leetcode.com/tag/segment-tree/) 中要严苛，但是由于采用了divide-and-conquer，并且有empty exception case的兜底，因此在segment外的range肯定会命中empty exception case从而被丢弃，由多个segment组成的range肯定会被分解直至完全命中segment。



## 2D Segment Tree

一、素材

geeksforgeeks [Two Dimensional Segment Tree | Sub-Matrix Sum](https://www.geeksforgeeks.org/two-dimensional-segment-tree-sub-matrix-sum/)

cp-algorithms [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html) 

二、segment tree of segment tree



## 素材

一、cp-algorithms [Segment Tree](https://cp-algorithms.com/data_structures/segment_tree.html)

二、geeksforgeeks [Segment Tree | Sum of given range](https://www.geeksforgeeks.org/segment-tree-sum-of-given-range/)

三、LeetCode segment tree

1、cn:

LeetCode.cn [segment tree](https://leetcode.cn/tag/segment-tree/problemset/)

2、en:

[LeetCode-segment tree](https://leetcode.com/tag/segment-tree/) 



四、知乎

zhihu [LeetCode . 线段树专题](https://zhuanlan.zhihu.com/p/85846796)

zhihu [线段树(Segment Tree)(上)](https://zhuanlan.zhihu.com/p/436326746)

zhihu [线段树(Segment Tree)专题](https://zhuanlan.zhihu.com/p/40151999)

zhihu [线段树（segment tree)、区间树(interval tree)](https://zhuanlan.zhihu.com/p/105368572) 

