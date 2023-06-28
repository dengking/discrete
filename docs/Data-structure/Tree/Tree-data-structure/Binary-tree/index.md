# Binary tree

## wikipedia [Binary tree](https://en.wikipedia.org/wiki/Binary_tree)

> NOTE:
>
> 最最常见的树结构

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **binary tree** is a [tree](https://en.wikipedia.org/wiki/Tree_structure) [data structure](https://en.wikipedia.org/wiki/Data_structure) in which each node has at most two [children](https://en.wikipedia.org/wiki/Child_node), which are referred to as the *left child* and the *right child*. A [recursive definition](https://en.wikipedia.org/wiki/Recursive_definition) using just [set theory](https://en.wikipedia.org/wiki/Set_theory) notions is that a (non-empty) binary tree is a [tuple](https://en.wikipedia.org/wiki/Tuple) (*L*, *S*, *R*), where *L* and *R* are binary trees or the [empty set](https://en.wikipedia.org/wiki/Empty_set) and *S* is a [singleton set](https://en.wikipedia.org/wiki/Singleton_set).[[1\]](https://en.wikipedia.org/wiki/Binary_tree#cite_note-GarnierTaylor2009-1) Some authors allow the binary tree to be the empty set as well.[[2\]](https://en.wikipedia.org/wiki/Binary_tree#cite_note-Skiena2009-2)

From a [graph theory](https://en.wikipedia.org/wiki/Graph_theory) perspective, binary (and K-ary) trees as defined here are actually [arborescences](https://en.wikipedia.org/wiki/Arborescence_(graph_theory)).[[3\]](https://en.wikipedia.org/wiki/Binary_tree#cite_note-Knuth1997-3) A binary tree may thus be also called a **bifurcating arborescence**[[3\]](https://en.wikipedia.org/wiki/Binary_tree#cite_note-Knuth1997-3)—a term which appears in some very old programming books,[[4\]](https://en.wikipedia.org/wiki/Binary_tree#cite_note-Flores1971-4) before the modern computer science terminology prevailed. It is also possible to interpret a binary tree as an [undirected](https://en.wikipedia.org/wiki/Undirected_graph), rather than a [directed graph](https://en.wikipedia.org/wiki/Directed_graph), in which case a binary tree is an [ordered](https://en.wikipedia.org/wiki/Ordered_tree), [rooted tree](https://en.wikipedia.org/wiki/Rooted_tree).[[5\]](https://en.wikipedia.org/wiki/Binary_tree#cite_note-5) Some authors use **rooted binary tree** instead of *binary tree* to emphasize the fact that the tree is rooted, but as defined above, a binary tree is always rooted.[[6\]](https://en.wikipedia.org/wiki/Binary_tree#cite_note-Mazur2010-6) A binary tree is a special case of an ordered [K-ary tree](https://en.wikipedia.org/wiki/K-ary_tree), where *k* is 2.

In mathematics, what is termed *binary tree* can vary significantly from author to author. Some use the definition commonly used in computer science,[[7\]](https://en.wikipedia.org/wiki/Binary_tree#cite_note-oem-7) but others define it as every non-leaf having exactly two children and don't necessarily order (as left/right) the children either.



In computing, binary trees can be used in two very different ways:

1、First, as a means of accessing nodes based on some value or label associated with each node.

2、Second, as a representation of data with a relevant bifurcating structure.

### Types of binary trees



#### full binary tree

A **full** binary tree (sometimes referred to as a **proper**[[15\]](https://en.wikipedia.org/wiki/Binary_tree#cite_note-15) or **plane** or **strict** binary tree) is a tree in which every node has either 0 or 2 children. Another way of defining a full binary tree is a [recursive definition](https://en.wikipedia.org/wiki/Recursive_definition). A full binary tree is either:

- A single vertex (a single node as the root node).
- A tree whose root node has two subtrees, both of which are full binary trees.



#### **complete binary tree**

A **complete** binary tree is a binary tree in which every level, *except possibly the last*, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and $2^h$ nodes at the last level *h*.[[19\]](https://en.wikipedia.org/wiki/Binary_tree#cite_note-complete_binary_tree-19) A perfect tree is therefore always complete but a complete tree is not necessarily perfect. Some authors use the term **complete** to refer instead to a **perfect** binary tree as defined above, in which case they call this type of tree (with a possibly not filled last level) an **almost complete** binary tree or **nearly complete** binary tree.[[20\]](https://en.wikipedia.org/wiki/Binary_tree#cite_note-almost_complete_binary_tree-20)[[21\]](https://en.wikipedia.org/wiki/Binary_tree#cite_note-nearly_complete_binary_tree-21) A complete binary tree can be efficiently represented using an array.



[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d9/Complete_binary2.svg/220px-Complete_binary2.svg.png)](https://en.wikipedia.org/wiki/File:Complete_binary2.svg)

A complete binary tree (that is not full)
