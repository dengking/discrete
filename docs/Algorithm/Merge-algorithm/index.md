# Merge algorithm



## wikipedia [Merge algorithm](https://en.wikipedia.org/wiki/Merge_algorithm)

 **Merge algorithms** are a family of [algorithms](https://en.wikipedia.org/wiki/Algorithm) that take multiple [sorted](https://en.wikipedia.org/wiki/Sorting_algorithm) lists as input and produce a single list as output, containing all the elements of the inputs lists in sorted order. These algorithms are used as [subroutines](https://en.wikipedia.org/wiki/Subroutine) in various [sorting algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm), most famously [merge sort](https://en.wikipedia.org/wiki/Merge_sort). 

### Application

 The merge algorithm plays a critical role in the [merge sort](https://en.wikipedia.org/wiki/Merge_sort) algorithm, a [comparison-based sorting algorithm](https://en.wikipedia.org/wiki/Comparison_sort). Conceptually, merge sort algorithm consists of two steps: 

1、[Recursively](https://en.wikipedia.org/wiki/Recursion_(computer_science)) divide the list into sublists of (roughly) equal length, until each sublist contains only one element, or in the case of iterative (bottom up) merge sort, consider a list of *n* elements as *n* sub-lists of size 1. A list containing a single element is, by definition, sorted.

> NOTE: 
>
> 1、需要考虑 "iterative (bottom up) merge sort" 如何实现

2、Repeatedly **merge** sublists to create a new sorted sublist until the single list contains all elements. The single list is the sorted list.

> NOTE: 
>
> 1、这其实就非常类似于 k-way merge

The **merge algorithm** is used repeatedly in the **merge sort algorithm**.

An example merge sort is given in the illustration. It starts with an unsorted array of 7 integers. The array is divided into 7 partitions; each partition contains 1 element and is sorted. The sorted partitions are then merged to produce larger, sorted, partitions, until 1 partition, the sorted array, is left.



### Merging two lists

> NOTE: 
>
> 1、合并两个是相对简单的

Merging two sorted lists into one can be done in [linear time](https://en.wikipedia.org/wiki/Linear_time) and linear space. The following [pseudocode](https://en.wikipedia.org/wiki/Pseudocode) demonstrates an algorithm that merges input lists (either [linked lists](https://en.wikipedia.org/wiki/Linked_list) or [arrays](https://en.wikipedia.org/wiki/Array_data_structure)) *A* and *B* into a new list *C*.[[1\]](https://en.wikipedia.org/wiki/Merge_algorithm#cite_note-skiena-1)[[2\]](https://en.wikipedia.org/wiki/Merge_algorithm#cite_note-toolbox-2):104 The function head yields the first element of a list; "dropping" an element means removing it from its list, typically by incrementing a pointer or index. 

```pseudocode
algorithm merge(A, B) is
    inputs A, B : list
    returns list

    C := new empty list
    while A is not empty and B is not empty do
        if head(A) ≤ head(B) then
            append head(A) to C
            drop the head of A
        else
            append head(B) to C
            drop the head of B

    // By now, either A or B is empty. It remains to empty the other input list.
    while A is not empty do
        append head(A) to C
        drop the head of A
    while B is not empty do
        append head(B) to C
        drop the head of B

    return C
```

> NOTE: 
>
> 1、leetcode [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)
>
> 

When the inputs are linked lists, this algorithm can be implemented to use only a constant amount of working space; the pointers in the lists' nodes can be reused for bookkeeping and for constructing the final merged list.

In the merge sort algorithm, this [subroutine](https://en.wikipedia.org/wiki/Subroutine) is typically used to merge two sub-arrays A[lo..mid], A[mid..hi] of a single array A. This can be done by copying the sub-arrays into a temporary array, then applying the merge algorithm above.[[1\]](https://en.wikipedia.org/wiki/Merge_algorithm#cite_note-skiena-1) The allocation of a temporary array can be avoided, but at the expense of speed and programming ease. Various in-place merge algorithms have been devised,[[3\]](https://en.wikipedia.org/wiki/Merge_algorithm#cite_note-3) sometimes sacrificing the linear-time bound to produce an *O*(*n* log *n*) algorithm;[[4\]](https://en.wikipedia.org/wiki/Merge_algorithm#cite_note-4) see [Merge sort § Variants](https://en.wikipedia.org/wiki/Merge_sort#Variants) for discussion.



### K-way merging

 *Main article:* [K-way merge algorithm](https://en.wikipedia.org/wiki/K-way_merge_algorithm) 

> NOTE: 参见 `K-way-merge-algorithm` 章节。



## 素材

一、宫水三页 [【多路归并】从朴素优先队列到多路归并](https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247490029&idx=1&sn=bba9ddff88d247db310406ee418d5a15&chksm=fd9cb2f2caeb3be4b1f84962677337dcb5884374e5b6b80340834eaff79298d11151da2dd5f7&token=252055586&lang=zh_CN#rd)

## 相关算法

1、double pointer

典型例子merge sort，这种一般是merge two sequence

2、heap

这种一般是merge multiple sequence

## LeetCode 试题

下面总结一些归并的试题。

https://leetcode.cn/problemset/all/?search=%E5%90%88%E5%B9%B6%20

### Merge sequence

#### 一、 merge two sequence



leetcode [912. 排序数组](https://leetcode.cn/problems/sort-an-array/) (merge sort) 和 leetcode [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/) 

merge sortmerge的部分，和 leetcode [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/) 的逻辑是非常类似的。

下面的是合并两个序列的题目:

1、leetcode [88. 合并两个有序数组](https://leetcode.cn/problems/merge-sorted-array/)

2、

#### 二、merge multiple sequence

leetcode [23. 合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)

**两两合并**

leetcode [23. 合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/) 中，给出了递归写法和迭代写法；



#### 三、合并有序序列



##### 合并有序数组



##### 合并有序链表

1、[我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA) 中:

> **快慢指针**最神奇，链表操作无压力。
>
> 归并排序找中点，链表成环搞判定。



### Merge interval 合并区间

leetcode [56. 合并区间](https://leetcode.cn/problems/merge-intervals/)



#### 区间合并

LeetCode [56. 合并区间](https://leetcode.cn/problems/merge-intervals) 中等



### 合并二叉树

#### LeetCode [617. 合并二叉树](https://leetcode.cn/problems/merge-two-binary-trees/)



### merge + top K

#### LeetCode [373. 查找和最小的 K 对数字](https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/) 中等

#### LeetCode [786. 第 K 个最小的素数分数](https://leetcode.cn/problems/k-th-smallest-prime-fraction/) 困难

#### LeetCode [378. 有序矩阵中第 K 小的元素](https://leetcode.cn/problems/kth-smallest-element-in-a-sorted-matrix/) 中等

