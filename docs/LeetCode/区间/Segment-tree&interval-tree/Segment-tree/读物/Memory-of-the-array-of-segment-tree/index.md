# The memory of the array of segment tree

geeksforgeeks [Segment Tree | Sum of given range](https://www.geeksforgeeks.org/segment-tree-sum-of-given-range/)

[LeetCode-Recursive Approach to Segment Trees](https://leetcode.com/articles/a-recursive-approach-to-segment-trees-range-sum-queries-lazy-propagation/) 



## stackoverflow [How is the memory of the array of segment tree 2 * 2 ^(ceil(log(n))) - 1?](https://stackoverflow.com/questions/28470692/how-is-the-memory-of-the-array-of-segment-tree-2-2-ceillogn-1)



### [A](https://stackoverflow.com/a/28502243)

> NOTE:
>
> 一、简而言之，segment tree的存储方式:
>
> 1、segment tree
>
> 2、complete binary tree
>
> 首先计算树的总高度，然后计算存储complete binary tree所需要的总节点个数。显然最终的complete binary tree是原segment tree的超级，它会保护原segment tree，这样原segment tree不是所有的节点都会是complete binary tree的leaf node







