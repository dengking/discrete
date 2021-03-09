# [Tree traversal](https://en.wikipedia.org/wiki/Tree_traversal)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **tree traversal** (also known as **tree search**) is a form of [graph traversal](https://en.wikipedia.org/wiki/Graph_traversal) and refers to the process of visiting (checking and/or updating) each node in a [tree data structure](https://en.wikipedia.org/wiki/Tree_(data_structure)), exactly once. Such traversals are classified by the order in which the nodes are visited. The following algorithms are described for a [binary tree](https://en.wikipedia.org/wiki/Binary_tree), but they may be generalized to other trees as well.



## Types

Unlike [linked lists](https://en.wikipedia.org/wiki/Linked_list), one-dimensional [arrays](https://en.wikipedia.org/wiki/Array_data_structure) and other [linear data structures](https://en.wikipedia.org/wiki/List_of_data_structures#Linear_data_structures), which are canonically traversed in linear order, trees may be traversed in multiple ways. They may be traversed in **depth-first** or **breadth-first order**. There are three common ways to traverse them in **depth-first order**: in-order, pre-order and post-order.[[1\]](https://en.wikipedia.org/wiki/Tree_traversal#cite_note-holtenotes-1) Beyond these basic traversals, various more complex or hybrid schemes are possible, such as [depth-limited searches](https://en.wikipedia.org/wiki/Depth-limited_search)like [iterative deepening depth-first search](https://en.wikipedia.org/wiki/Iterative_deepening_depth-first_search).



### Data structures for tree traversal

Traversing a tree involves iterating over all nodes in some manner. Because from a given node there is more than one possible next node (it is not a linear data structure), then, assuming sequential computation (not parallel), some nodes must be **deferred**—stored in some way for later visiting. This is often done via a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) (LIFO) or [queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) (FIFO). As a tree is a **self-referential** (recursively defined) data structure, traversal can be defined by [recursion](https://en.wikipedia.org/wiki/Recursion)or, more subtly, [corecursion](https://en.wikipedia.org/wiki/Corecursion), in a very natural and clear fashion; in these cases the **deferred nodes** are stored implicitly in the [call stack](https://en.wikipedia.org/wiki/Call_stack).

***SUMMARY*** : data structure决定了对它操作的各种实现，因为tree是self-referential，所以对它的各种操作也是可以以 [recursion](https://en.wikipedia.org/wiki/Recursion)or[corecursion](https://en.wikipedia.org/wiki/Corecursion)的方式实现的；

**Depth-first search** is easily implemented via a **stack**, including **recursively** (via the **call stack**), while **breadth-first search** is easily implemented via a **queue**, including **corecursively**.

### Depth-first search

*Main article:* [Depth-first search](https://en.wikipedia.org/wiki/Depth-first_search)

These searches are referred to as *depth-first search* (DFS), as the search tree is deepened as much as possible on each child before going to the next **sibling**. For a binary tree, they are defined as display operations recursively at each node, starting with the root, whose algorithm is as follows:[[2\]](https://en.wikipedia.org/wiki/Tree_traversal#cite_note-2) [[3\]](https://en.wikipedia.org/wiki/Tree_traversal#cite_note-3)

The general recursive pattern for traversing a (non-empty) binary tree is this: At node N do the following:

(L) Recursively traverse its left subtree. This step is finished at the node N again.

(R) Recursively traverse its right subtree. This step is finished at the node N again.

(N) Process N itself.

These steps can be done *in any order*. If (L) is done before (R), the process is called left-to-right traversal, otherwise it is called right-to-left traversal. The following methods show left-to-right traversal:

#### Pre-order (NLR)

先序

1. Check if the current node is empty or null.（如果为null，则return）
2. Display the data part of the root (or current node).
3. Traverse the left subtree by recursively calling the pre-order function.
4. Traverse the right subtree by recursively calling the pre-order function.

The pre-order traversal is a [topologically sorted](https://en.wikipedia.org/wiki/Topological_sorting) one, because a parent node is processed before any of its child nodes is done.

[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d4/Sorted_binary_tree_preorder.svg/220px-Sorted_binary_tree_preorder.svg.png)](https://en.wikipedia.org/wiki/File:Sorted_binary_tree_preorder.svg)Pre-order: F, B, A, D, C, E, G, I, H.



#### In-order (LNR)

中序

1. Check if the current node is empty or null.（如果为null，则return）
2. Traverse the left subtree by recursively calling the in-order function.
3. Display the data part of the root (or current node).
4. Traverse the right subtree by recursively calling the in-order function.

In a [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree), in-order traversal retrieves data in sorted order.[[4\]](https://en.wikipedia.org/wiki/Tree_traversal#cite_note-4)

[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/7/77/Sorted_binary_tree_inorder.svg/220px-Sorted_binary_tree_inorder.svg.png)](https://en.wikipedia.org/wiki/File:Sorted_binary_tree_inorder.svg)In-order: A, B, C, D, E, F, G, H, I.

#### Out-order (RNL)

***SUMMARY*** : out和in相反

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

[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9d/Sorted_binary_tree_postorder.svg/220px-Sorted_binary_tree_postorder.svg.png)](https://en.wikipedia.org/wiki/File:Sorted_binary_tree_postorder.svg)Post-order: A, C, E, D, B, H, I, G, F.

#### Generic tree

To traverse any tree with **depth-first search**, perform the following operations recursively at each node:

1. Perform pre-order operation.
2. For each i from 1 to the number of children do:
   1. Visit *i*-th, if present.
   2. Perform in-order operation.
3. Perform post-order operation.

Depending on the problem at hand, the pre-order, in-order or post-order operations may be void, or you may only want to visit a specific child, so these operations are optional. Also, in practice more than one of pre-order, in-order and post-order operations may be required. For example, when inserting into a ternary tree, a pre-order operation is performed by comparing items. A post-order operation may be needed afterwards to re-balance the tree.

### Breadth-first search / level order

Main article: [Breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search)

Trees can also be traversed in *level-order*, where we visit every node on a level before going to a lower level. This search is referred to as *breadth-first search* (BFS), as the search tree is broadened as much as possible on each depth before going to the next depth.





### Other types

There are also tree traversal algorithms that classify as neither depth-first search nor breadth-first search. One such algorithm is [Monte Carlo tree search](https://en.wikipedia.org/wiki/Monte_Carlo_tree_search), which concentrates on analyzing the most promising moves, basing the expansion of the [search tree](https://en.wikipedia.org/wiki/Search_tree) on [random sampling](https://en.wikipedia.org/wiki/Monte_Carlo_method) of the search space.



## Applications

Pre-order traversal while duplicating nodes and edges can make a complete duplicate of a [binary tree](https://en.wikipedia.org/wiki/Binary_tree). It can also be used to make a prefix expression ([Polish notation](https://en.wikipedia.org/wiki/Polish_notation)) from [expression trees](https://en.wikipedia.org/wiki/Parse_tree): traverse the expression tree pre-orderly. For example, traversing the depicted arithmetic expression in pre-order yields "+ * 1 - 2 3 + 4 5".

In-order traversal is very commonly used on [binary search trees](https://en.wikipedia.org/wiki/Binary_search_tree) because it returns values from the underlying set in order, according to the comparator that set up the binary search tree (hence the name).

Post-order traversal while deleting or freeing nodes and values can delete or free an entire binary tree. It can also generate a postfix representation ([Reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation)) of a binary tree. Traversing the depicted arithmetic expression in post-order yields "1 2 3 - * 4 5 + +".

***SUMMARY*** : 如何根据字符串构造出expression tree



## Implementations

***THINKING*** : tree是满足递归结构的，那为什么广度优先遍历不能够使用递归而深度优先遍历能够使用递归呢？因为广度优先遍历并没有按照tree的递归结构来进行遍历，而深度优先遍历则是按照树的递归结构来进行遍历的；所以，深度优先遍历就能够按照递归的方式来进行实现；

### Depth-first search

***SUMMARY*** : 递归函数在执行过程中，其实是有一个call stack的，下面的伪代码都提供了两个版本：

- 递归版本
- 迭代版本



#### Pre-order

```pseudocode

preorder(node)
  if (node == null)
    return
  visit(node)
  preorder(node.left)
  preorder(node.right)
```

```pseudocode
iterativePreorder(node)
  if (node == null)
    return
  s ← empty stack
  s.push(node)
  while (not s.isEmpty())
    node ← s.pop()
    visit(node)
    //right child is pushed first so that left is processed first
    if (node.right ≠ null)
      s.push(node.right)
    if (node.left ≠ null)
      s.push(node.left)
```

***SUMMARY*** : 代码理解，stack中存放的是待visit的node，每次visit栈顶的node，一旦该node被visit后，就要将其pop；由于pre-order是一旦遇到该节点，就要进行visit，所以在`while`中就会首先执行`node ← s.pop()`、`visit(node)`，然后再先stack中压入新的node；

#### In-order

```pseudocode

inorder(node)
  if (node == null)
    return
  inorder(node.left)
  visit(node)
  inorder(node.right)
```

```pseudocode
iterativeInorder(node)
  s ← empty stack
  while (not s.isEmpty() or node ≠ null)
    if (node ≠ null)
      s.push(node)
      node ← node.left
    else
      node ← s.pop()
      visit(node)
      node ← node.right
```

***SUMMARY*** : in-order的一个特点是：只有当一个node没有left node或者它的left node已经visit过了，它才能够被visit，然后再去visit它的right node；否则它只能够在stack中等待，既然node在stack中，那么就可以获得到它的子节点的信息；

#### Post-order

```pseudocode
postorder(node)
  if (node == null)
    return
  postorder(node.left)
  postorder(node.right)
  visit(node)
```



```pseudocode
iterativePostorder(node)
  s ← empty stack
  lastNodeVisited ← null
  while (not s.isEmpty() or node ≠ null)
    if (node ≠ null)
      s.push(node)
      node ← node.left
    else
      peekNode ← s.peek()
      // if right child exists and traversing node
      // from left child, then move right
      if (peekNode.right ≠ null and lastNodeVisited ≠ peekNode.right)
        node ← peekNode.right
      else
        visit(peekNode)
        lastNodeVisited ← s.pop()
```

***SUMMARY*** : post-order和in-order其实是有点类似的；

All the above implementations require stack space proportional to the height of the tree which is a [call stack](https://en.wikipedia.org/wiki/Call_stack) for the recursive and a parent stack for the iterative ones. In a poorly balanced tree, this can be considerable. With the iterative implementations we can remove the stack requirement by maintaining parent pointers in each node, or by [threading the tree](https://en.wikipedia.org/wiki/Tree_traversal#Morris_in-order_traversal_using_threading) (next section).



#### Morris in-order traversal using threading

A binary tree is threaded by making every left child pointer (that would otherwise be null) point to the in-order predecessor of the node (if it exists) and every right child pointer (that would otherwise be null) point to the in-order successor of the node (if it exists).

Advantages:

1. Avoids recursion, which uses a call stack and consumes memory and time.
2. The node keeps a record of its parent.

Disadvantages:

1. The tree is more complex.
2. We can make only one traversal at a time.
3. It is more prone to errors when both the children are not present and both values of nodes point to their ancestors.

**Morris traversal** is an implementation of in-order traversal that uses threading:[[6\]](https://en.wikipedia.org/wiki/Tree_traversal#cite_note-6)

1. Create links to the in-order successor.
2. Print the data using these links.
3. Revert the changes to restore original tree.





### Breadth-first search



Also, listed below is pseudocode for a simple [queue](https://en.wikipedia.org/wiki/Queue_(data_structure)) based level-order traversal, and will require space proportional to the maximum number of nodes at a given depth. This can be as much as the total number of nodes / 2. A more space-efficient approach for this type of traversal can be implemented using an [iterative deepening depth-first search](https://en.wikipedia.org/wiki/Iterative_deepening_depth-first_search).

```pseudocode
levelorder(root)
  q ← empty queue
  q.enqueue(root)
  while (not q.isEmpty())
    node ← q.dequeue()
    visit(node)
    if (node.left ≠ null)
      q.enqueue(node.left)
    if (node.right ≠ null)
      q.enqueue(node.right)
```



## Infinite trees

