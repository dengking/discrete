# wikipedia [Tree traversal](https://en.wikipedia.org/wiki/Tree_traversal) 

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **tree traversal** (also known as **tree search**) is a form of [graph traversal](https://en.wikipedia.org/wiki/Graph_traversal) and refers to the process of visiting (checking and/or updating) each node in a [tree data structure](https://en.wikipedia.org/wiki/Tree_(data_structure)), exactly once. Such traversals are classified by the order in which the nodes are visited. The following algorithms are described for a [binary tree](https://en.wikipedia.org/wiki/Binary_tree), but they may be generalized to other trees as well.

> NOTE: 
>
> 1、graph traversal是tree traversal的一种推广

## Types

Unlike [linked lists](https://en.wikipedia.org/wiki/Linked_list), one-dimensional [arrays](https://en.wikipedia.org/wiki/Array_data_structure) and other [linear data structures](https://en.wikipedia.org/wiki/List_of_data_structures#Linear_data_structures), which are canonically traversed in linear order, trees may be traversed in multiple ways. They may be traversed in **depth-first** or **breadth-first order**. There are three common ways to traverse them in **depth-first order**: in-order, pre-order and post-order.[[1\]](https://en.wikipedia.org/wiki/Tree_traversal#cite_note-holtenotes-1) Beyond these basic traversals, various more complex or hybrid schemes are possible, such as [depth-limited searches](https://en.wikipedia.org/wiki/Depth-limited_search)like [iterative deepening depth-first search](https://en.wikipedia.org/wiki/Iterative_deepening_depth-first_search).

> NOTE: 
>
> 1、from one to many，复杂度在不断提升
>
> 2、下面对各种traversal进行了较好的总结，下面表格是根据TOC总结的
>
> |                         |                                    |
> | ----------------------- | ---------------------------------- |
> | **depth-first order**   | in-order, pre-order and post-order |
> | **breadth-first order** |                                    |
>
> 3、所谓先、后、中，是以patent节点为基准命名的
>
> 4、需要注意的是: 对于tree traversal，它是有两个order的:
>
> a、纵向: 深度、parent 和 children
>
> 一般是从parent到children，即自顶向下
>
> b、横向: 广度、sibling之间
>
> 一般是从left child到right child，即自左向右

### Data structures for tree traversal

Traversing a tree involves iterating over all nodes in some manner. Because from a given node there is more than one possible next node (it is not a linear data structure), then, assuming sequential computation (not parallel), some nodes must be **deferred**—stored in some way for later visiting. This is often done via a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) (LIFO) or [queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) (FIFO). As a tree is a **self-referential** (recursively defined) data structure, traversal can be defined by [recursion](https://en.wikipedia.org/wiki/Recursion) or, more subtly(精准的), [corecursion](https://en.wikipedia.org/wiki/Corecursion), in a very natural and clear fashion; in these cases the **deferred nodes** are stored implicitly in the [call stack](https://en.wikipedia.org/wiki/Call_stack).

> NOTE : 
>
> 1、data structure决定了对它操作的各种实现，因为tree是self-referential，所以对它的各种操作也是可以以 [recursion](https://en.wikipedia.org/wiki/Recursion) or [corecursion](https://en.wikipedia.org/wiki/Corecursion)的方式实现的；

**Depth-first search** is easily implemented via a **stack**, including **recursively** (via the **call stack**), while **breadth-first search** is easily implemented via a **queue**, including **corecursively**.

> NOTE: 
>
> 1、上述 "including **recursively** "、"including **corecursively** "要如何理解？

### Depth-first search

*Main article:* [Depth-first search](https://en.wikipedia.org/wiki/Depth-first_search)

These searches are referred to as *depth-first search* (DFS), as the search tree is deepened as much as possible on each child before going to the next **sibling**. For a binary tree, they are defined as display operations recursively at each node, starting with the root, whose algorithm is as follows:[[2\]](https://en.wikipedia.org/wiki/Tree_traversal#cite_note-2) [[3\]](https://en.wikipedia.org/wiki/Tree_traversal#cite_note-3)

The general recursive pattern for traversing a (non-empty) binary tree is this: At node `N` do the following:

(L) Recursively traverse its left subtree. This step is finished at the node `N` again.

(R) Recursively traverse its right subtree. This step is finished at the node `N` again.

(N) Process `N` itself.

These steps can be done *in any order*. If (L) is done before (R), the process is called left-to-right traversal, otherwise it is called right-to-left traversal. The following methods show left-to-right traversal:

#### Pre-order (NLR)

> NOTE: 
>
> 1、先序

1. Check if the current node is empty or null.（如果为null，则return）
2. Display the data part of the root (or current node).
3. Traverse the left subtree by recursively calling the pre-order function.
4. Traverse the right subtree by recursively calling the pre-order function.

The pre-order traversal is a [topologically sorted](https://en.wikipedia.org/wiki/Topological_sorting) one, because a parent node is processed before any of its child nodes is done.

> NOTE: 
> 1、" [topologically sorted](https://en.wikipedia.org/wiki/Topological_sorting) "要如何理解？
>
> 既然是"sort"，显然这就涉及了relation，根据上面这段话的描述来看，它采用的是patent-child relation。

[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d4/Sorted_binary_tree_preorder.svg/220px-Sorted_binary_tree_preorder.svg.png)](https://en.wikipedia.org/wiki/File:Sorted_binary_tree_preorder.svg)Pre-order: F, B, A, D, C, E, G, I, H.



#### In-order (LNR)

> NOTE: 
>
> 1、中序

1. Check if the current node is empty or null.（如果为null，则return）
2. Traverse the left subtree by recursively calling the in-order function.
3. Display the data part of the root (or current node).
4. Traverse the right subtree by recursively calling the in-order function.

In a [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree), in-order traversal retrieves data in sorted order.[[4\]](https://en.wikipedia.org/wiki/Tree_traversal#cite_note-4)

[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/7/77/Sorted_binary_tree_inorder.svg/220px-Sorted_binary_tree_inorder.svg.png)](https://en.wikipedia.org/wiki/File:Sorted_binary_tree_inorder.svg)In-order: A, B, C, D, E, F, G, H, I.

#### Out-order (RNL)

> NOTE: out和in相反

1. Check if the current node is empty or null.（如果为null，则return）
2. Traverse the right subtree by recursively calling the out-order function.
3. Display the data part of the root (or current node).
4. Traverse the left subtree by recursively calling the out-order function.

In a [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree), out-order traversal retrieves data in **reverse sorted order**.



#### Post-order (LRN)

1. Check if the current node is empty or null.（如果为null，则return）
2. Traverse the left subtree by recursively calling the post-order function.
3. Traverse the right subtree by recursively calling the post-order function.
4. Display the data part of the root (or current node).

The trace of a traversal is called a sequentialisation of the tree. The traversal trace is a list of each visited root. No one sequentialisation according to pre-, in- or post-order describes the underlying tree uniquely. Given a tree with distinct elements, either pre-order or post-order paired with in-order is sufficient to describe the tree uniquely. However, pre-order with post-order leaves some ambiguity in the tree structure.[[5\]](https://en.wikipedia.org/wiki/Tree_traversal#cite_note-5)

> NOTE: 
>
> 一、上面这段话描述的是根据traversal结果来反向构造出tree；作者给出的结论如下: 
>
> 1、单单根据pre-order、in-order、post-order中一个的traversal，是无法反向构造出tree的
>
> 2、根据pre-order + in-order能够反向构造出tree，根据post-order + in-order能够反向构造出tree，根据pre-order + post-order无法反向构造出tree。
>
> 二、翻译如下:
>
> 对遍历的跟踪称为树的序列化。
> 遍历跟踪是每个访问节点的列表。
> 没有人根据预序、内序或后序对底层树进行唯一的序列化描述。
> 给定一个具有不同元素的树，无论是pre-order还是与in-order配对的post-order都足以惟一地描述树。
> 然而，预购和后购在树形结构中留下了一些不确定性。
>
> 

[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9d/Sorted_binary_tree_postorder.svg/220px-Sorted_binary_tree_postorder.svg.png)](https://en.wikipedia.org/wiki/File:Sorted_binary_tree_postorder.svg)Post-order: A, C, E, D, B, H, I, G, F.

#### Generic tree

> NOTE: 
>
> 1、这一段的内容没有读懂

To traverse any tree with **depth-first search**, perform the following operations recursively at each node:

1、Perform pre-order operation.

2、For each i from 1 to the number of children do:

1. Visit *i*-th, if present.
2. Perform in-order operation.

3、Perform post-order operation.

Depending on the problem at hand, the pre-order, in-order or post-order operations may be void, or you may only want to visit a specific child, so these operations are optional. Also, in practice more than one of pre-order, in-order and post-order operations may be required. For example, when inserting into a **ternary tree**, a pre-order operation is performed by comparing items. A post-order operation may be needed afterwards to **re-balance** the tree.

### Breadth-first search / level order

Main article: [Breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search)

Trees can also be traversed in *level-order*, where we visit every node on a level before going to a lower level. This search is referred to as *breadth-first search* (BFS), as the search tree is broadened as much as possible on each depth before going to the next depth.



### Other types

There are also tree traversal algorithms that classify as neither depth-first search nor breadth-first search. One such algorithm is [Monte Carlo tree search](https://en.wikipedia.org/wiki/Monte_Carlo_tree_search), which concentrates on analyzing the most promising moves, basing the expansion of the [search tree](https://en.wikipedia.org/wiki/Search_tree) on [random sampling](https://en.wikipedia.org/wiki/Monte_Carlo_method) of the search space.



## Applications

### Pre-order traversal 

#### Prefix expression 

Pre-order traversal can be used to make a prefix expression ([Polish notation](https://en.wikipedia.org/wiki/Polish_notation)) from [expression trees](https://en.wikipedia.org/wiki/Parse_tree): traverse the expression tree pre-orderly. For example, traversing the depicted arithmetic expression in pre-order yields "`+ * 1 - 2 3 + 4 5`".



### In-order traversal 

#### Binary-search tree

In-order traversal is very commonly used on [binary search trees](https://en.wikipedia.org/wiki/Binary_search_tree) because it returns values from the underlying set in order, according to the comparator that set up the binary search tree (hence the name).



### Post-order traversal 



#### Delete or free entire binary tree

Post-order traversal while deleting or freeing nodes and values can delete or free an entire binary tree. Thereby the node is freed after freeing its children.

> NOTE: 
>
> 1、次序是: 先delete left child，然后delete right child，然后delete parent node；
>
> 2、这样做的原因是: 必须要自底向上地进行删除，因为如果先删除了parent node，则无法找到它的children node

#### Deep copy a tree

Also the duplication of a binary tree yields a post-order sequence of actions, because the pointer `copy` to the copy of a node is assigned to the corresponding child field `N.child` within the copy of the parent `N` immediately after `return copy` in the recursive procedure. This means that the parent cannot be finished before all children are finished.

> NOTE: 
>
> 1、次序是: 先deep copy left child，然后deep copy right child，然后deep copy parent
>
> 2、这样做的原因是: 因为新的parent node的children必须要是新的，也就是说，parent node是依赖于children node的

#### Postfix representation 

It can also generate a postfix representation ([Reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)) of a binary tree. Traversing the depicted arithmetic expression in post-order yields "1 2 3 - * 4 5 + +".

> NOTE: 如何根据字符串构造出expression tree



## Implementations

> NOTE: 
>
> 1、参见 `Implementation` 章节

## Infinite trees

> NOTE: 
>
> 1、未阅读
>
> 2、其实就是 [lazy evaluation](https://en.wikipedia.org/wiki/Lazy_evaluation)