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

Sorting algorithms are often referred to as a word followed by the word "sort," and grammatically are used in English as noun phrases, for example in the sentence, "it is inefficient to use insertion sort on large lists," the phrase *insertion sort* refers to the [insertion sort](https://en.wikipedia.org/wiki/Insertion_sort) sorting algorithm.



## History

From the beginning of computing, the sorting problem has attracted a great deal of research, perhaps due to the complexity of solving it efficiently despite its simple, familiar statement. Among the authors of early sorting algorithms around 1951 was [Betty Holberton](https://en.wikipedia.org/wiki/Betty_Holberton) (née Snyder), who worked on [ENIAC](https://en.wikipedia.org/wiki/ENIAC) and [UNIVAC](https://en.wikipedia.org/wiki/UNIVAC).[[1\]](https://en.wikipedia.org/wiki/Sorting_algorithm#cite_note-refrigerator-1)[[2\]](https://en.wikipedia.org/wiki/Sorting_algorithm#cite_note-NYTimes-2) [Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) was analyzed as early as 1956.[[3\]](https://en.wikipedia.org/wiki/Sorting_algorithm#cite_note-3) Comparison sorting algorithms have a fundamental requirement of [Ω(*n* log *n*)](https://en.wikipedia.org/wiki/Big_omega_notation)comparisons (some input sequences will require a multiple of *n* log *n* comparisons); algorithms not based on comparisons, such as [counting sort](https://en.wikipedia.org/wiki/Counting_sort), can have better performance. Asymptotically optimal algorithms have been known since the mid-20th century—useful new algorithms are still being invented, with the now widely used [Timsort](https://en.wikipedia.org/wiki/Timsort) dating to 2002, and the [library sort](https://en.wikipedia.org/wiki/Library_sort) being first published in 2006.

Sorting algorithms are prevalent in introductory [computer science](https://en.wikipedia.org/wiki/Computer_science) classes, where the abundance of algorithms for the problem provides a gentle introduction to a variety of core algorithm concepts, such as [big O notation](https://en.wikipedia.org/wiki/Big_O_notation), [divide and conquer algorithms](https://en.wikipedia.org/wiki/Divide_and_conquer_algorithm), [data structures](https://en.wikipedia.org/wiki/Data_structure) such as [heaps](https://en.wikipedia.org/wiki/Heap_(data_structure)) and [binary trees](https://en.wikipedia.org/wiki/Binary_tree), [randomized algorithms](https://en.wikipedia.org/wiki/Randomized_algorithm), [best, worst and average case](https://en.wikipedia.org/wiki/Best,_worst_and_average_case) analysis, [time–space tradeoffs](https://en.wikipedia.org/wiki/Time–space_tradeoff), and [upper and lower bounds](https://en.wikipedia.org/wiki/Upper_and_lower_bounds).



## Classification

**Sorting algorithms** are often classified by:

- [Computational complexity](https://en.wikipedia.org/wiki/Computational_complexity_theory) ([worst, average and best](https://en.wikipedia.org/wiki/Best,_worst_and_average_case) behavior) in terms of the size of the list (*n*). For typical serial sorting algorithms good behavior is $O(n log {n})$, with parallel sort in $O(log^2n)$, and bad behavior is $O(n^2)$. (See [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation).) Ideal behavior for a serial sort is $O(n)$, but this is not possible in the average case. Optimal parallel sorting is $O(log n)$. [Comparison-based sorting algorithms](https://en.wikipedia.org/wiki/Comparison_sort) need at least Ω(*n* log *n*) comparisons for most inputs.
- [Computational complexity](https://en.wikipedia.org/wiki/Computational_complexity_theory) of swaps (for "in-place" algorithms).
- [Memory](https://en.wikipedia.org/wiki/Memory_(computing)) usage (and use of other computer resources). In particular, some sorting algorithms are "[in-place](https://en.wikipedia.org/wiki/In-place_algorithm)". Strictly, an in-place sort needs only O(1) memory beyond the items being sorted; sometimes O(log(*n*)) additional memory is considered "in-place".
- Recursion. Some algorithms are either recursive or non-recursive, while others may be both (e.g., merge sort).
- Stability: [stable sorting algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm#Stability) maintain the relative order of records with equal keys (i.e., values).
- Whether or not they are a [comparison sort](https://en.wikipedia.org/wiki/Comparison_sort). A comparison sort examines the data only by comparing two elements with a comparison operator.
- General method: insertion, exchange, selection, merging, *etc.* Exchange sorts include bubble sort and quicksort. Selection sorts include shaker sort and heapsort.
- Whether the algorithm is serial or parallel. The remainder of this discussion almost exclusively concentrates upon serial algorithms and assumes serial operation.
- Adaptability: Whether or not the presortedness of the input affects the running time. Algorithms that take this into account are known to be [adaptive](https://en.wikipedia.org/wiki/Adaptive_sort).

## Timsort vs quicksort

[Comparison between timsort and quicksort](https://stackoverflow.com/questions/7770230/comparison-between-timsort-and-quicksort)

