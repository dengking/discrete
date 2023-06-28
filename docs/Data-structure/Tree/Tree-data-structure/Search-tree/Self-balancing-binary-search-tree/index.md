# Self-balancing binary search tree



## wikipedia [Self-balancing binary search tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **self-balancing** (or **height-balanced**) **binary search tree** is any [node](https://en.wikipedia.org/wiki/Node_(computer_science))-based [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) that automatically keeps its height (maximal number of levels below the root) small in the face of arbitrary item insertions and deletions.

> NOTE: 
>
> 只有再修改tree的时候，才需要进行rebalance

These structures provide efficient implementations for mutable ordered [lists](https://en.wikipedia.org/wiki/List_(computing)), and can be used for other [abstract data structures](https://en.wikipedia.org/wiki/Abstract_data_structure) such as [associative arrays](https://en.wikipedia.org/wiki/Associative_arrays), [priority queues](https://en.wikipedia.org/wiki/Priority_queue) and [sets](https://en.wikipedia.org/wiki/Set_(computer_science)).

The [red–black tree](https://en.wikipedia.org/wiki/Red–black_tree), which is a type of **self-balancing binary search tree**, was called symmetric binary B-tree and was renamed but can still be confused with the generic concept of **self-balancing binary search tree** because of the initials.



### Overview

Most operations on a binary search tree (BST) take time directly proportional to the height of the tree, so it is desirable to keep the height small. A binary tree with height *h* can contain at most [$2^0+2^1+···+2^h = 2^{h+1}−1$]( https://en.wikipedia.org/wiki/Geometric_series#Formula ) nodes. It follows that for any tree with *n* nodes and height *h*: ${\displaystyle n\leq 2^{h+1}-1}$ 

And that implies: ${\displaystyle h\geq \lceil \log _{2}(n+1)-1\rceil \geq \lfloor \log _{2}n\rfloor }$

In other words, the minimum height of a binary tree with *n* nodes is [log](https://en.wikipedia.org/wiki/Logarithm)2(*n*), [rounded down](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions); that is, ${\displaystyle \lfloor \log _{2}n\rfloor }$



However, the simplest algorithms for BST item insertion may yield a tree with nodes *n* in rather common situations. For example, when the items are inserted in sorted [key](https://en.wikipedia.org/wiki/Key_(database)) order, the tree degenerates（退化） into a [linked list](https://en.wikipedia.org/wiki/Linked_list) with *n* nodes. The difference in performance between the two situations may be enormous: for *n* = 1,000,000, for example, the minimum height is ${\displaystyle \lfloor \log _{2}(1,000,000)\rfloor =19}$

If the data items are known ahead of time, the height can be kept small, in the average sense, by adding values in a random order, resulting in a [random binary search tree](https://en.wikipedia.org/wiki/Random_binary_search_tree). However, there are many situations (such as [online algorithms](https://en.wikipedia.org/wiki/Online_algorithm)) where this [randomization](https://en.wikipedia.org/wiki/Randomized_algorithm) is not viable.

Self-balancing binary trees solve this problem by performing transformations on the tree (such as [tree rotations](https://en.wikipedia.org/wiki/Tree_rotation)) at key insertion times, in order to keep the height proportional to $log_{2}(n)$. Although a certain [overhead](https://en.wikipedia.org/wiki/Computational_overhead) is involved, it may be justified in the long run by ensuring fast execution of later operations.

While it is possible to maintain a BST with minimum height with expected ${\displaystyle O(\log n)}$ time operations (lookup/insertion/removal), the additional space requirements required to maintain such a structure tend to outweigh the decrease in search time. For comparison, an AVL tree is guaranteed to be within a factor of 1.44 of the **optimal height** while requiring only two additional bits of storage in a naive implementation.[[1\]](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree#cite_note-knuth-1) Therefore, most self-balanced BST algorithms keep the height within a constant factor of this lower bound.

> NOTE: 
>
> 虽然可以通过预期时间操作（查找/插入/移除）维持具有最小高度的BST，但是维持这种结构所需的额外空间要求往往超过搜索时间的减少。 为了进行比较，AVL树保证在最佳高度的1.44倍内，而在一个简单的实现中只需要两个额外的存储位。[1] 因此，大多数自平衡BST算法将高度保持在该下限的常数因子内（即balanced的程度不同）。

In the [asymptotic](https://en.wikipedia.org/wiki/Asymptotic) ("[Big-O](https://en.wikipedia.org/wiki/Big_O_notation)") sense, a self-balancing BST structure containing *n* items allows the lookup, insertion, and removal of an item in O(log *n*) worst-case time, and [ordered enumeration](https://en.wikipedia.org/wiki/In-order_iteration) of all items in O(*n*) time. For some implementations these are per-operation time bounds, while for others they are [amortized](https://en.wikipedia.org/wiki/Amortized_analysis) bounds over a sequence of operations. These times are asymptotically optimal among all data structures that manipulate the key only through comparisons.



### Implementations

- [2-3 tree](https://en.wikipedia.org/wiki/2-3_tree)
- [AA tree](https://en.wikipedia.org/wiki/AA_tree)
- [AVL tree](https://en.wikipedia.org/wiki/AVL_tree)
- [B-tree](https://en.wikipedia.org/wiki/B-tree)
- [Red-black tree](https://en.wikipedia.org/wiki/Red-black_tree)
- [Scapegoat tree](https://en.wikipedia.org/wiki/Scapegoat_tree)
- [Splay tree](https://en.wikipedia.org/wiki/Splay_tree)
- [Treap](https://en.wikipedia.org/wiki/Treap)
- [Weight-balanced tree](https://en.wikipedia.org/wiki/Weight-balanced_tree)



### Applications

Self-balancing binary search trees can be used in a natural way to construct and maintain ordered lists, such as [priority queues](https://en.wikipedia.org/wiki/Priority_queue). They can also be used for [associative arrays](https://en.wikipedia.org/wiki/Associative_array); key-value pairs are simply inserted with an ordering based on the key alone. In this capacity, self-balancing BSTs have [a number of advantages and disadvantages](https://en.wikipedia.org/wiki/Associative_array#Efficient_representations) over their main competitor, [hash tables](https://en.wikipedia.org/wiki/Hash_table) : 

One advantage of self-balancing BSTs is that they allow fast (indeed, asymptotically optimal) enumeration of the items *in key order*, which hash tables do not provide. 

One disadvantage is that their lookup algorithms get more complicated when there may be multiple items with the same key. 

Self-balancing BSTs have better **worst-case lookup performance** than hash tables (${\displaystyle O(\log n)}$ compared to O(n)), but have **worse average-case performance** (${\displaystyle O(\log n)}$ compared to O(1)).

Self-balancing BSTs can be used to implement any algorithm that requires mutable ordered lists, to achieve optimal worst-case asymptotic performance. For example, if [binary tree sort](https://en.wikipedia.org/wiki/Binary_tree_sort) is implemented with a self-balanced BST, we have a very simple-to-describe yet [asymptotically optimal](https://en.wikipedia.org/wiki/Asymptotically_optimal) O(*n* log *n*) sorting algorithm. Similarly, many algorithms in [computational geometry](https://en.wikipedia.org/wiki/Computational_geometry) exploit variations on self-balancing BSTs to solve problems such as the [line segment intersection](https://en.wikipedia.org/wiki/Line_segment_intersection) problem and the [point location](https://en.wikipedia.org/wiki/Point_location) problem efficiently. (For average-case performance, however, self-balanced BSTs may be less efficient than other solutions. Binary tree sort, in particular, is likely to be slower than [merge sort](https://en.wikipedia.org/wiki/Merge_sort), [quicksort](https://en.wikipedia.org/wiki/Quicksort), or [heapsort](https://en.wikipedia.org/wiki/Heapsort), because of the tree-balancing overhead as well as [cache](https://en.wikipedia.org/wiki/Cache_(computing)) access patterns.)

> NOTE: 
>
> "line segment intersection"的意思是"线段相交"

Self-balancing BSTs are flexible data structures, in that it's easy to extend them to efficiently record additional information or perform new operations. For example, one can record the number of nodes in each subtree having a certain property, allowing one to count the number of nodes in a certain key range with that property in O(log *n*) time. These extensions can be used, for example, to optimize database queries or other list-processing algorithms.

