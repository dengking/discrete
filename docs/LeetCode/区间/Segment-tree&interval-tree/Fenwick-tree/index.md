# Fenwick tree



Fenwick tre的思想:

1、按照Peter M. Fenwick的说法，正如所有的整数都可以表示成2的幂和，我们也可以把一串**序列**表示成一系列**子序列**的和。采用这个想法，我们可将一个**前缀和**划分成多个**子序列**的和，而划分的方法与**数的2的幂和**具有极其相似的方式。一方面，**子序列**的个数是其二进制表示中1的个数，另一方面，子序列代表的$f[i]$的个数也是2的幂。

> NOTE:
>
> 一、baike [树状数组](https://baike.baidu.com/item/%E6%A0%91%E7%8A%B6%E6%95%B0%E7%BB%84/313739?fr=aladdin) 
>
> 划分的方式和 **数的2的幂和** 非常类似，简单来说，就是有几个1就包含几个子序列，这其实是二进制的**重叠子结构**。这里所说的"子序列"，其实也可以认为是"子区间"。

2、本质上还是segment tree那一套



树状数组就是这样一种结构，它巧妙地利用了**二进制**（实际上，树状数组的英文名BIT，直译过来就是**二进制下标树**）。例如11，转化为二进制数就是 $(1011)_2$ ，如果我们要求前11项和，可以分别查询 $((0000)_2,(1000)_2]$ 、$((1000)_2,(1010)_2]$以及$((1010)_2,(1011)_2]$的和再相加。这三个区间怎么来的呢？其实就是**不断地去掉二进制数最右边的一个1**的过程（如下图）。

![img](https://pic4.zhimg.com/80/v2-a53a897f22763ef04a728f8263f06547_1440w.webp)

> NOTE:
>
> 一、zhihu [算法学习笔记(2) : 树状数组](https://zhuanlan.zhihu.com/p/93795692) 





思考:  `C[i]` 表示的是什么？ 

## wikipedia [Fenwick tree](https://en.wikipedia.org/wiki/Fenwick_tree)

A **Fenwick tree** or **binary indexed tree** is a data structure that can efficiently update elements and calculate [prefix sums](https://en.wikipedia.org/wiki/Prefix_sum) in a table of numbers.

When compared with a flat array of numbers, the **Fenwick tree** achieves a much better balance between two operations:

1、element update 

2、prefix sum calculation. 

A flat array of $n$ numbers can either store the elements or the **prefix sums**. In the first case, computing prefix sums requires linear time; in the second case, updating the array elements requires linear time (in both cases, the other operation can be performed in constant time). Fenwick trees allow both operations to be performed in $O(\log n)$ time. This is achieved by representing the numbers as a [tree](https://en.wikipedia.org/wiki/Tree_(data_structure)) with $n+1$ nodes where the value of each node in the tree is the **prefix sum** of the array from the index of the parent (inclusive) up to the index of the node (exclusive). The tree itself is implicit and can be stored as an array of $n$ numbers, with the implicit root node omitted from the array. The tree structure allows the operations of element retrieval, element update, prefix sum, and range sum to be performed using only $O(\log n)$ node accesses.



## geeksforgeeks [Binary Indexed Tree or Fenwick Tree](https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/)





## leetcode Fenwick tree

https://leetcode.com/tag/binary-indexed-tree/



[Introduction to Fenwick Tree/Binary Indexed Tree(BIT)](https://leetcode.com/discuss/general-discussion/1093346/introduction-to-fenwick-treebinary-indexed-treebit)