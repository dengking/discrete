# k-way merge algorithm 



关于实现，参见:

1、geeksforgeeks [Merge k sorted arrays | Set 1](https://www.geeksforgeeks.org/merge-k-sorted-arrays/)

2、leetcode [合并K个排序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/)



## wikipedia [k-way merge algorithm](https://en.wikipedia.org/wiki/K-way_merge_algorithm) 



In [computer science](https://en.wanweibaike.com/wiki-Computer_science), ***k*-way merge algorithms** or multiway merges are a specific type of [sequence merge algorithms](https://en.wanweibaike.com/wiki-Merge_algorithm) that specialize in taking in multiple sorted lists and merging them into a single sorted list. These merge algorithms generally refer to merge algorithms that take in a number of sorted lists greater than two. 2-way merges are also referred to as binary merges.

### *k*-way merge

> NOTE: 
>
> 1、原文都是纯粹的理论分析，需要结合具体的程序来进行理解才能够完全掌握，在 leetcode [23. 合并K个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/) # [官方解题](https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/) 中给出了非常好的分析，和下面的内容是有着很好的对应的。

The *k*-way merge problem consists of merging `k` sorted arrays to produce a single sorted array with the same elements. Denote by `n` the total number of elements. `n` is equal to the size of the output array and the sum of the sizes of the `k` input arrays. 

> NOTE: 
>
> 1、"`n` is equal to the size of the output array and the sum of the sizes of the `k` input arrays"
>
> 这段话的意思是: `n` 既等于 "the size of the output array"  又等于 "the sum of the sizes of the `k` input arrays""

For simplicity, we assume that none of the input arrays is empty. As a consequence `k < n`, which simplifies the reported running times. The problem can be solved in `O(n log k)` running time with `O(n)` space. Several algorithms that achieve this running time exist.

> NOTE: 
>
> 1、复杂度为什么是 `O(n log k)` ？

#### Iterative 2-Way merge

The problem can be solved by iteratively merging two of the `k` arrays using a 2-way merge until only a single array is left. If the arrays are merged in arbitrary order, then the resulting running time is only `O(kn)`. This is suboptimal(次优的).

The running time can be improved by iteratively merging the first with the second, the third with the fourth, and so on. As the number of arrays is halved in each iteration, there are only Θ(log k) iteration. In each iteration every element is moved exactly once. The running time per iteration is therefore in Θ(n) as n is the number of elements. The total running time is therefore in Θ(n log k).

> NOTE: 
>
> 1、一轮循环中，就将剩余list的个数降低一半，它是通过两两merge来实现的；这种方式比起第一种: 一次merge两个，要更优，它能够减少iteration的次数；

#### Direct *k*-way merge

In this case, we would simultaneously merge k-runs together.

A straightforward implementation would scan all k arrays to determine the minimum. This straightforward implementation results in a running time of Θ(kn). Note that this is mentioned only as a possibility, for the sake of discussion. Although it would work, it is not efficient.

> NOTE: 
>
> 这种算法它用到了如下两种数据结构

**Heap**



**Tournament Tree**

