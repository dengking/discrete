# Priority queue



## wikipedia [Priority queue](https://en.wikipedia.org/wiki/Priority_queue)

In [computer science](https://en.wanweibaike.com/wiki-Computer_science), a **priority queue** is an [abstract data type](https://en.wanweibaike.com/wiki-Abstract_data_type) similar to a regular [queue](https://en.wanweibaike.com/wiki-Queue_(abstract_data_type)) or [stack](https://en.wanweibaike.com/wiki-Stack_(abstract_data_type)) data structure in which each element additionally has a "**priority**" associated with it. In a priority queue, an element with high priority is served before an element with low priority. In some implementations, if two elements have the same priority, they are served according to the order in which they were enqueued, while in other implementations, ordering of elements with the same priority is undefined.

> NOTE:
>
> 根据priority来进行排名，原文的下面这段话总结得非常到位: 
>
> > One can imagine a priority queue as a modified [queue](https://en.wanweibaike.com/wiki-Queue_(abstract_data_type)), but when one would get the next element off the queue, the highest-priority element is retrieved first.
>
> 次序是由priority而决定的，而不是由位置决定的
>
> 



### Operations

A priority queue must at least support the following operations:

1、*is_empty*: check whether the queue has no elements.

2、*insert_with_priority*: add an [element](https://en.wanweibaike.com/wiki-Element_(mathematics)) to the [queue](https://en.wanweibaike.com/wiki-Queue_(abstract_data_type)) with an associated priority.

3、*pull_highest_priority_element*: remove the element from the queue that has the *highest priority*, and return it.



One can imagine a priority queue as a modified [queue](https://en.wanweibaike.com/wiki-Queue_(abstract_data_type)), but when one would get the next element off the queue, the highest-priority element is retrieved first.

> NOTE: 
>
> 这个比喻非常好



### Implementation

#### Naive implementations

> NOTE: 
>
> 现实中，并没有人会使用这种方式

#### Usual implementation

1、[heap](https://infogalactic.com/info/Heap_(data_structure)) 

2、[self-balancing binary search tree](https://infogalactic.com/info/Self-balancing_binary_search_tree)

### Equivalence of priority queues and sorting algorithms

#### Using a priority queue to sort

|                             Name                             |                Priority Queue Implementation                 |                             Best                             |                           Average                            |                            Worst                             |
| :----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: |
|      [Heapsort](https://infogalactic.com/info/Heapsort)      | [Heap](https://infogalactic.com/info/Heap_(data_structure))  | ![n \log(n)](https://infogalactic.com/w/images/math/5/9/0/59032eb6da2b67ed1aba8d4a4c55ebf6.png) | ![n \log(n)](https://infogalactic.com/w/images/math/5/9/0/59032eb6da2b67ed1aba8d4a4c55ebf6.png) | ![n \log(n)](https://infogalactic.com/w/images/math/5/9/0/59032eb6da2b67ed1aba8d4a4c55ebf6.png) |
|    [Smoothsort](https://infogalactic.com/info/Smoothsort)    |                        Leonardo Heap                         | ![n](https://infogalactic.com/w/images/math/7/b/8/7b8b965ad4bca0e41ab51de7b31363a1.png) | ![n \log(n)](https://infogalactic.com/w/images/math/5/9/0/59032eb6da2b67ed1aba8d4a4c55ebf6.png) | ![n \log (n)](https://infogalactic.com/w/images/math/5/9/0/59032eb6da2b67ed1aba8d4a4c55ebf6.png) |
| [Selection sort](https://infogalactic.com/info/Selection_sort) | Unordered [Array](https://infogalactic.com/info/Array_(disambiguation)#In_computer_science) | ![n^2](https://infogalactic.com/w/images/math/b/0/8/b08b1c6ec09f20907eb1d6f1392c01c6.png) | ![n^2](https://infogalactic.com/w/images/math/b/0/8/b08b1c6ec09f20907eb1d6f1392c01c6.png) | ![n^2](https://infogalactic.com/w/images/math/b/0/8/b08b1c6ec09f20907eb1d6f1392c01c6.png) |
| [Insertion Sort](https://infogalactic.com/info/Insertion_Sort) | Ordered [Array](https://infogalactic.com/info/Array_(disambiguation)#In_computer_science) | ![n ](https://infogalactic.com/w/images/math/7/b/8/7b8b965ad4bca0e41ab51de7b31363a1.png) | ![n^2 ](https://infogalactic.com/w/images/math/b/0/8/b08b1c6ec09f20907eb1d6f1392c01c6.png) | ![n^2 ](https://infogalactic.com/w/images/math/b/0/8/b08b1c6ec09f20907eb1d6f1392c01c6.png) |
|     [Tree sort](https://infogalactic.com/info/Tree_sort)     | [self-balancing binary search tree](https://infogalactic.com/info/Self-balancing_binary_search_tree) | ![n \log(n)](https://infogalactic.com/w/images/math/5/9/0/59032eb6da2b67ed1aba8d4a4c55ebf6.png) | ![n \log(n)](https://infogalactic.com/w/images/math/5/9/0/59032eb6da2b67ed1aba8d4a4c55ebf6.png) | ![n \log(n)](https://infogalactic.com/w/images/math/5/9/0/59032eb6da2b67ed1aba8d4a4c55ebf6.png) |



## Applications

> NOTE: 
>
> 在非常多的algorithm中，都使用到了priority queue

1、[LeetCode-23. 合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)

2、[LeetCode-215. 数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/)

使用min heap，不断地弹出小元素，留下大元素

3、labuladong [啊这，一道找中位数的算法题把东哥整不会了…](https://mp.weixin.qq.com/s/oklQN_xjYy--_fbFkd9wMg) 

[LeetCode-剑指 Offer 41. 数据流中的中位数](https://leetcode.cn/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/)

[LeetCode-295. 数据流的中位数](https://leetcode.cn/problems/find-median-from-data-stream/)

使用两个heap

4、[Prim算法](https://leetcode.cn/problems/min-cost-to-connect-all-points/solution/prim-and-kruskal-by-yexiso-c500/)



### wikipedia [Heap (data structure)](https://en.wikipedia.org/wiki/Heap_(data_structure)) # Applications

The heap data structure has many applications.

1、[Heapsort](https://en.wikipedia.org/wiki/Heapsort): One of the best sorting methods being in-place and with no quadratic worst-case scenarios.

2、[Selection algorithms](https://en.wikipedia.org/wiki/Selection_algorithm): A heap allows access to the min or max element in constant time, and other selections (such as median or kth-element) can be done in sub-linear time on data that is in a heap.[[19\]](https://en.wikipedia.org/wiki/Heap_(data_structure)#cite_note-24)

> NOTE:
>
> 一、[michaelpollmeier-Selecting top k items from a list efficiently in Java / Groovy](https://www.michaelpollmeier.com/selecting-top-k-items-from-a-list-efficiently-in-java-groovy)

3、[Graph algorithms](https://en.wikipedia.org/wiki/List_of_algorithms#Graph_algorithms): By using heaps as internal traversal data structures, run time will be reduced by polynomial order. Examples of such problems are [Prim's minimal-spanning-tree algorithm](https://en.wikipedia.org/wiki/Prim's_algorithm) and [Dijkstra's shortest-path algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm).

4、[Priority queue](https://en.wikipedia.org/wiki/Priority_queue): A priority queue is an abstract concept like "a list" or "a map"; just as a list can be implemented with a linked list or an array, a priority queue can be implemented with a heap or a variety of other methods.

5、[K-way merge](https://en.wikipedia.org/wiki/K-way_merge_algorithm): A heap data structure is useful to merge many already-sorted input streams into a single sorted output stream. Examples of the need for merging include external sorting and streaming results from distributed data such as a log structured merge tree. The inner loop is obtaining the min element, replacing with the next element for the corresponding input stream, then doing a sift-down heap operation. (Alternatively the replace function.) (Using extract-max and insert functions of a priority queue are much less efficient.)

> NOTE:
>
> 一、[LeetCode-23. 合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)

6、[Order statistics](https://en.wikipedia.org/wiki/Order_statistics): The Heap data structure can be used to efficiently find the kth smallest (or largest) element in an array.
