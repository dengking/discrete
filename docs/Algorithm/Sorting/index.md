# 关于本章

本章描述排序算法。

## wikipedia [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **sorting algorithm** is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) that puts elements of a [list](https://en.wikipedia.org/wiki/List_(computing)) in a certain [order](https://en.wikipedia.org/wiki/Total_order). The most frequently used orders are [numerical order](https://en.wikipedia.org/wiki/Numerical_order) and [lexicographical order](https://en.wikipedia.org/wiki/Lexicographical_order). 

> NOTE: 
>
> 可供选择的order是非常多的

Efficient [sorting](https://en.wikipedia.org/wiki/Sorting) is important for optimizing the [efficiency](https://en.wikipedia.org/wiki/Algorithmic_efficiency) of other algorithms (such as [search](https://en.wikipedia.org/wiki/Search_algorithm) and [merge](https://en.wikipedia.org/wiki/Merge_algorithm) algorithms) that require input data to be in sorted lists. Sorting is also often useful for [canonicalizing](https://en.wikipedia.org/wiki/Canonicalization)（标准化） data and for producing human-readable output. More formally, the output of any **sorting algorithm** must satisfy two conditions:

1、The output is in nondecreasing order (each element is no smaller than the previous element according to the desired [total order](https://en.wikipedia.org/wiki/Total_order));

2、The output is a [permutation](https://en.wikipedia.org/wiki/Permutation) (a reordering, yet retaining all of the original elements) of the input.

Further, the input data is often stored in an [array](https://en.wikipedia.org/wiki/Array_data_type), which allows [random access](https://en.wikipedia.org/wiki/Random_access), rather than a list, which only allows [sequential access](https://en.wikipedia.org/wiki/Sequential_access); though many algorithms can be applied to either type of data after suitable modification.

> NOTE: 
>
> 对数组排序和对链表排序，采用的算法可能不同





### History

[Bubble sort](https://en.wanweibaike.com/wiki-Bubble_sort)  (1956)

[Timsort](https://en.wanweibaike.com/wiki-Timsort) (2002)

[library sort](https://en.wanweibaike.com/wiki-Library_sort) (2006)

1、Comparison sorting algorithms have a fundamental requirement of [Ω(*n* log *n*)](https://en.wanweibaike.com/wiki-Big_omega_notation) comparisons (some input sequences will require a multiple of *n* log *n* comparisons, where n is the number of elements in the array to be sorted). 

2、Algorithms not based on comparisons, such as [counting sort](https://en.wanweibaike.com/wiki-Counting_sort), can have better performance. 

Asymptotically optimal algorithms have been known since the mid-20th century—useful new algorithms are still being invented, with the now widely used [Timsort](https://en.wanweibaike.com/wiki-Timsort) dating to 2002, and the [library sort](https://en.wanweibaike.com/wiki-Library_sort) being first published in 2006.



### Classification

**Sorting algorithms** are often classified by:

1、[Computational complexity](https://en.wikipedia.org/wiki/Computational_complexity_theory) ([worst, average and best](https://en.wikipedia.org/wiki/Best,_worst_and_average_case) behavior) in terms of the size of the list (*n*). 

For typical serial sorting algorithms good behavior is $O(n log {n})$, with parallel sort in $O(log^2n)$, and bad behavior is $O(n^2)$. (See [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation).) 

Ideal behavior for a serial sort is $O(n)$, but this is not possible in the average case. 

Optimal parallel sorting is $O(log n)$. 

[Comparison-based sorting algorithms](https://en.wikipedia.org/wiki/Comparison_sort) need at least Ω(*n* log *n*) comparisons for most inputs.

2、[Computational complexity](https://en.wikipedia.org/wiki/Computational_complexity_theory) of swaps (for "in-place" algorithms).

3、[Memory](https://en.wikipedia.org/wiki/Memory_(computing)) usage (and use of other computer resources). In particular, some sorting algorithms are "[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)". Strictly, an in-place sort needs only O(1) memory beyond the items being sorted; sometimes O(log(*n*)) additional memory is considered "in-place".

4、Recursion. Some algorithms are either recursive or non-recursive, while others may be both (e.g., merge sort).

5、Stability: [stable sorting algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm#Stability) maintain the relative order of records with equal keys (i.e., values).

6、Whether or not they are a [comparison sort](https://en.wikipedia.org/wiki/Comparison_sort). A comparison sort examines the data only by comparing two elements with a comparison operator.

6、General method: insertion, exchange, selection, merging, *etc.* 

Exchange sorts include bubble sort and quicksort. 

Selection sorts include cycle sort and heapsort.

6、Whether the algorithm is serial or parallel. The remainder of this discussion almost exclusively concentrates upon serial algorithms and assumes serial operation.

7、Adaptability: Whether or not the presortedness of the input affects the running time. Algorithms that take this into account are known to be [adaptive](https://en.wikipedia.org/wiki/Adaptive_sort).

#### Stability

> NOTE: 
>
> 原文花了很大的篇幅来介绍stability，其实它的含义是比较好理解的，在下面文章中，有着更加精简的论述:
>
> 1、cnblogs [【DS】排序算法的稳定性](https://www.cnblogs.com/lqminn/p/3642027.html)
>
> 考察排序算法的时候有一个很重要的特性，就是算法的稳定性：假定在待排序的记录序列中，存在多个具有相同的关键字的记录，若经过排序，这些记录的相对次序保持不变，即在原序列中，ri=rj，且ri在rj之前，而在排序后的序列中，ri仍在rj之前，则称这种排序算法是稳定的；否则称为不稳定的。
>
> **二、算法稳定性的重要性**
>
> 算法稳定性为什么这么重要呢？
>
> 1）在实际的应用中，我们交换的不一定只是一个整数，而可能是一个很大的对象，交换元素存在一定的开销；
>
> 2）参照基数排序（后面会讲），不稳定排序是无法完成基数排序的，讲述完基数排序后，还会补充这里的原因。

### Comparison of algorithms

Below is a table of [comparison sorts](https://en.wanweibaike.com/wiki-Comparison_sort). A comparison sort cannot perform better than *O*(*n* log *n*) on average.

|                             Name                             |    Best     |   Average   |         Worst         |                            Memory                            | Stable |          Method          |                         Other notes                          |
| :----------------------------------------------------------: | :---------: | :---------: | :-------------------: | :----------------------------------------------------------: | :----: | :----------------------: | :----------------------------------------------------------: |
|    [Quicksort](https://en.wanweibaike.com/wiki-Quicksort)    | $ n\log n $ | $ n\log n $ |       $ n^{2} $       |                          $ \log n $                          |   No   |       Partitioning       | Quicksort is usually done in-place with *O*(log *n*) stack space |
|   [Merge sort](https://en.wanweibaike.com/wiki-Merge_sort)   | $ n\log n $ | $ n\log n $ |      $ n\log n $      |                             *n*                              |  Yes   |         Merging          | [Highly parallelizable](https://en.wanweibaike.com/wiki-Merge_sort#Parallel_merge_sort) (up to *O*(log *n*) using the Three Hungarians' Algorithm) |
| [In-place merge sort](https://en.wanweibaike.com/wiki-In-place_merge_sort) |      —      |      —      |    $ n\log ^{2}n $    |                              1                               |  Yes   |         Merging          | Can be implemented as a stable sort based on stable in-place merging. |
|    [Introsort](https://en.wanweibaike.com/wiki-Introsort)    | $ n\log n $ | $ n\log n $ |      $ n\log n $      |                          $ \log n $                          |   No   | Partitioning & Selection | Used in several [STL](https://en.wanweibaike.com/wiki-Standard_Template_Library) implementations. |
|     [Heapsort](https://en.wanweibaike.com/wiki-Heapsort)     | $ n\log n $ | $ n\log n $ |      $ n\log n $      |                              1                               |   No   |        Selection         |                                                              |
| [Insertion sort](https://en.wanweibaike.com/wiki-Insertion_sort) |     *n*     |  $ n^{2} $  |       $ n^{2} $       |                              1                               |  Yes   |        Insertion         | *O*(*n* + *d*), in the worst case over sequences that have *d* [inversions](https://en.wanweibaike.com/wiki-Inversion_(discrete_mathematics)). |
|      [Timsort](https://en.wanweibaike.com/wiki-Timsort)      |     *n*     | $ n\log n $ |      $ n\log n $      |                             *n*                              |  Yes   |   Insertion & Merging    | Makes *n* comparisons when the data is already sorted or reverse sorted. |
| [Selection sort](https://en.wanweibaike.com/wiki-Selection_sort) |  $ n^{2} $  |  $ n^{2} $  |       $ n^{2} $       |                              1                               |   No   |        Selection         |  Stable with $ O(n)} extra space or when using linked lists  |
|    [Shellsort](https://en.wanweibaike.com/wiki-Shellsort)    | $ n\log n $ | $ n^{4/3} $ |      $ n^{3/2} $      |                              1                               |   No   |        Insertion         |                       Small code size.                       |
|  [Bubble sort](https://en.wanweibaike.com/wiki-Bubble_sort)  |     *n*     |  $ n^{2} $  |       $ n^{2} $       |                              1                               |  Yes   |        Exchanging        |                       Tiny code size.                        |
|    [Tree sort](https://en.wanweibaike.com/wiki-Tree_sort)    | $ n\log n $ | $ n\log n $ | $ n\log n $(balanced) |                             *n*                              |  Yes   |        Insertion         | When using a [self-balancing binary search tree](https://en.wanweibaike.com/wiki-Self-balancing_binary_search_tree). |
| [Library sort](https://en.wanweibaike.com/wiki-Library_sort) | $ n\log n $ | $ n\log n $ |       $ n^{2} $       |                             *n*                              |   No   |        Insertion         |                                                              |
| [Tournament sort](https://en.wanweibaike.com/wiki-Tournament_sort) | $ n\log n $ | $ n\log n $ |      $ n\log n $      | *n*[[12\]](https://en.wanweibaike.com/wiki-Sorting algorithm#cite_note-12) |   No   |        Selection         |                   Variation of Heap Sort.                    |

## Timsort vs quicksort

[Comparison between timsort and quicksort](https://stackoverflow.com/questions/7770230/comparison-between-timsort-and-quicksort)

