# Merge algorithm



## wikipedia [Merge algorithm](https://en.wikipedia.org/wiki/Merge_algorithm)

 **Merge algorithms** are a family of [algorithms](https://en.wikipedia.org/wiki/Algorithm) that take multiple [sorted](https://en.wikipedia.org/wiki/Sorting_algorithm) lists as input and produce a single list as output, containing all the elements of the inputs lists in sorted order. These algorithms are used as [subroutines](https://en.wikipedia.org/wiki/Subroutine) in various [sorting algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm), most famously [merge sort](https://en.wikipedia.org/wiki/Merge_sort). 

### Application

 The merge algorithm plays a critical role in the [merge sort](https://en.wikipedia.org/wiki/Merge_sort) algorithm, a [comparison-based sorting algorithm](https://en.wikipedia.org/wiki/Comparison_sort). Conceptually, merge sort algorithm consists of two steps: 

1、[Recursively](https://en.wikipedia.org/wiki/Recursion_(computer_science)) divide the list into sublists of (roughly) equal length, until each sublist contains only one element, or in the case of iterative (bottom up) merge sort, consider a list of *n* elements as *n* sub-lists of size 1. A list containing a single element is, by definition, sorted.

2、Repeatedly **merge** sublists to create a new sorted sublist until the single list contains all elements. The single list is the sorted list.



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

When the inputs are linked lists, this algorithm can be implemented to use only a constant amount of working space; the pointers in the lists' nodes can be reused for bookkeeping and for constructing the final merged list.

In the merge sort algorithm, this [subroutine](https://en.wikipedia.org/wiki/Subroutine) is typically used to merge two sub-arrays A[lo..mid], A[mid..hi] of a single array A. This can be done by copying the sub-arrays into a temporary array, then applying the merge algorithm above.[[1\]](https://en.wikipedia.org/wiki/Merge_algorithm#cite_note-skiena-1) The allocation of a temporary array can be avoided, but at the expense of speed and programming ease. Various in-place merge algorithms have been devised,[[3\]](https://en.wikipedia.org/wiki/Merge_algorithm#cite_note-3) sometimes sacrificing the linear-time bound to produce an *O*(*n* log *n*) algorithm;[[4\]](https://en.wikipedia.org/wiki/Merge_algorithm#cite_note-4) see [Merge sort § Variants](https://en.wikipedia.org/wiki/Merge_sort#Variants) for discussion.



### K-way merging

 *Main article:* [K-way merge algorithm](https://en.wikipedia.org/wiki/K-way_merge_algorithm) 

> NOTE: 参见 `K-way-merge-algorithm` 章节。