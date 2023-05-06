# Heap(data structure)



## wikipedia [Heap (data structure)](https://en.wikipedia.org/wiki/Heap_(data_structure)) 

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **heap** is a specialized [tree](https://en.wikipedia.org/wiki/Tree_(data_structure))-based [data structure](https://en.wikipedia.org/wiki/Data_structure) which is essentially an [almost complete](https://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees)[[1\]](https://en.wikipedia.org/wiki/Heap_(data_structure)#cite_note-1) binary tree that satisfies the **heap property**: 

1、in a *max heap*, for any given [node](https://en.wikipedia.org/wiki/Node_(computer_science)) C, if P is a parent node of C, then the *key* (the *value*) of P is greater than or equal to the key of C. 

2、In a *min heap*, the key of P is less than or equal to the key of C.[[2\]](https://en.wikipedia.org/wiki/Heap_(data_structure)#cite_note-2) 

3、The node at the "top" of the heap (with no parents) is called the *root* node.



However, a heap is not a sorted structure; it can be regarded as being partially ordered. 

Note that, as shown in the graphic, there is no implied ordering between siblings or cousins and no implied sequence for an [in-order traversal](https://en.wikipedia.org/wiki/Inorder_traversal) (as there would be in, e.g., a [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree)). The heap relation mentioned above applies only between nodes and their parents, grandparents, etc. 

> NOTE:
>
> 一、由**heap property**决定了heap-ordered-tree，这也决定了heap的主要用途(下面介绍了)，显然它和binary-search-tree是不同的。
>
> 二、思考: heap是否需要像binary-search-tree那样考虑balance问题？

A heap is a useful data structure when it is necessary to repeatedly remove the object with the highest (or lowest) priority, or when insertions need to be interspersed with removals of the root node.

> NOTE:
>
> 一、上面这段话介绍了heap的主要用途，翻译: 然而，堆不是一个排序结构;它可以看作是部分有序的。当需要重复删除具有最高(或最低)优先级的对象时，或者当插入需要与根节点的删除穿插在一起时，堆是一个有用的数据结构。



## Implementation

1、Binary heap

2、Fibonacci heap

3、Binomial heap

wikipedia [Binomial heap](https://en.wikipedia.org/wiki/Binomial_heap)

