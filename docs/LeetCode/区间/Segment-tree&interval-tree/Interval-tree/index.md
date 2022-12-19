# Interval tree



## wikipedia [Interval tree](https://en.wikipedia.org/wiki/Interval_tree)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), an **interval tree** is a [tree data structure](https://en.wikipedia.org/wiki/Tree_(data_structure)) to hold [intervals](https://en.wikipedia.org/wiki/Interval_(mathematics)). Specifically, it allows one to efficiently find all intervals that overlap with any given interval or point. It is often used for windowing queries,[[1\]](https://en.wikipedia.org/wiki/Interval_tree#cite_note-1) for instance, 

1、to find all roads on a computerized map inside a rectangular viewport

2、to find all visible elements inside a three-dimensional scene. 

A similar data structure is the [segment tree](https://en.wikipedia.org/wiki/Segment_tree).



### Naive approach

Interval trees solve this problem. This article describes two alternative designs for an interval tree, dubbed the *centered interval tree* and the *augmented tree*.

### Centered interval tree

> NOTE:
>
> 一、未阅读
>
> 二、dgp.toronto.edu [CSC 378: Data Structures and Algorithm Analysis INTERVAL TREES](https://www.dgp.toronto.edu/public_user/JamesStewart/378notes/22intervals/) 中采用的就是这种方式
>
> 



### Augmented tree

> NOTE:
>
> 一、geeksforgeeks [Interval Tree](https://www.geeksforgeeks.org/interval-tree/) 中的实现方法就是采用的这种思路
>
> 以interval的low作为排序基准进行binary search tree的构建

An augmented tree can be built from a simple ordered tree, for example a [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) or [self-balancing binary search tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree), ordered by the 'low' values of the intervals. An extra annotation is then added to every node, recording the maximum upper value among all the intervals from this node down. Maintaining this attribute involves updating all ancestors of the node from the bottom up whenever a node is added or deleted. This takes only O(*h*) steps per node addition or removal, where *h* is the height of the node added or removed in the tree. If there are any [tree rotations](https://en.wikipedia.org/wiki/Tree_rotation) during insertion and deletion, the affected nodes may need updating as well.





## geeksforgeeks [Interval Tree](https://www.geeksforgeeks.org/interval-tree/)





```pseudocode
Interval overlappingIntervalSearch(root, x)
1) If x overlaps with root's interval, return the root's interval.

2) If left child of root is not empty and the max  in left child 
is greater than x's low value, recur for left child

3) Else recur for right child.
```
