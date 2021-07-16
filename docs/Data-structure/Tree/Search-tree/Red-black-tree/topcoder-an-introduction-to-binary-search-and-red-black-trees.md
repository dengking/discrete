[TOC]



# [an-introduction-to-binary-search-and-red-black-trees](https://www.topcoder.com/community/competitive-programming/tutorials/an-introduction-to-binary-search-and-red-black-trees/)

As a programmer, you’ll frequently come across tasks that deal with a number of objects — numbers, strings, people, and so forth — and that require you to store and process those objects. If you need to maintain a list of objects that are sorted and unique, and if you need to be able to quickly insert and retrieve objects to and from this list, the ideal data structure will be a **tree set** (or a **tree map**, if you consider each object a key and associate another object called a value to it).

Many programming languages provide built-in support for tree-based sets and maps — for instance, Java’s [TreeSet/TreeMap](http://java.sun.com/j2se/1.4.2/docs/api/java/util/TreeMap.html) classes and the `C++` Standard Template Library’s set and map classes — but because of their common use, it’s easy to misunderstand what actually happens behind the scenes, and how the underlying data structures actually work. That’s what this article is all about.

We’ll start off by looking at some of the general terms and concepts used in dealing with trees We’ll then focus on binary search trees (BST), a special type of tree that keeps elements sorted (but doesn’t guarantee efficient insertion and retrieval). Finally we’ll look at **red-black trees**, a variation of binary search trees that overcome BST’s limitations through a logarithmic bound on insertion and retrieval.

### Trees terminology

A tree is a data structure that represents data in a hierarchical manner. It associates every object to a node in the tree and maintains the parent/child relationships between those nodes. Each tree must have exactly one node, called the **root**, from which all nodes of the tree extend (and which has no parent of its own). The other end of the tree – the last level down — contains the **leaf nodes** of the tree.

![img](http://community.topcoder.com/i/education/rbtrees1.jpg)



The number of lines you pass through when you travel from the root until you reach a particular node is the **depth** of that node in the tree (node G in the figure above has a depth of 2). The **height** of the tree is the maximum depth of any node in the tree (the tree in Figure 1 has a height of 3). The number of children emanating from a given node is referred to as its **degree** — for example, node A above has a degree of 3 and node H has a degree of 1.

### Binary Search Tree (BST)

A **binary search tree** is a tree with one additional constraint — it keeps the elements in the tree in a particular order. Formally each node in the BST has two children (if any are missing we consider it a **nil node**), a left child and a right child. Nodes are rooted in place based on their values, with the smallest on the left and largest on the right.




![img](http://community.topcoder.com/i/education/rbtrees2.jpg)

### Traversing BST

A common requirement when using sets and maps is to go through the elements in order. With binary search trees, traversing from left to right is known as inorder tree traversal. In a tree where each node has a value and two pointers to the left and right children, inorder tree traversal can be thought of as:

```
    Procedure Inorder_traversal(Node n)if(n == nil)return; 
        Inorder_traversal(n.left_subtree); 
        Print(n.value); 
        Inorder_traversal(n.right_subtree); 
    … 
    Inorder_traversal(root); 
```

Operations on BST (insertion, deletion and retrieval)



### BST insertion:

When adding a new node to a binary search tree, note that the new node will always be a leaf in the tree. To insert a new node, all we will do is navigate the BST starting from the root. If the new node value is smaller than the current node value, we go left – if it is larger, we go right. When we reach a leaf node, the last step is to attach the new node as a child to this leaf node in a way that preserves the BST constraint.

For example, consider we want to add a new node with value 4 to the BST in Figure 1. Here are the steps we will go through:

- Let the current node = root = 5.
- As the new node is smaller than the current node (4 < 5), we will go left and set current node to 2.
- As the new node is greater than current node (4 > 2), we will go right and set the current node to 3.
- We’ve reached a leaf, so the last step is to attach the new node to the right of the current node. Here is how the new BST looks:




![img](http://community.topcoder.com/i/education/rbtrees3.jpg)

### BST Deletion:

Deleting a node from BST is a little more subtle. Formally there are three cases for deleting node n from a BST:

- If n has no children, we only have to remove n from the tree.
- If n has a single child, we remove n and connect its parent to its child.
- If n has two children, we need to :
  - Find the **smallest** node that is larger than `n`, call it `m`.
  - Remove `m` from the tree (if you have reached this case then m will always have no left child, though I’ll leave the proof to the reader), so we apply one or the other of the above cases to do this.
  - Replace the value of n with m.

Figure 4 shows these three cases in action.




![img](http://community.topcoder.com/i/education/rbtrees4.jpg)

### BST Retrieval:

Retrieving an element from binary search trees requires simple navigation, starting from the root and going left, if the current node is larger than the node we are looking for, or going right otherwise.

Any of these primitive operations on BST run in O(h) time, where h is the tree height, so the smaller the tree height the better running time operations will achieve. The problem with BST is that, depending on the order of inserting elements in the tree, the tree shape can vary. In the worst cases (such as inserting elements in order) the tree will look like a linked list in which each node has only a right child. This yields O(n) for primitive operations on the BST, with n the number of nodes in the tree.

To solve this problem many variations of binary search trees exist. Of these variations, red-black trees provide a well-balanced BST that guarantees a logarithmic bound on primitive operations.



#### Red-black Trees

Red-black trees are an evolution of binary search trees that aim to keep the tree balanced without affecting the complexity of the primitive operations. This is done by coloring each node in the tree with either red or black and preserving a set of properties that guarantee that the deepest path in the tree is not longer than twice the shortest one.

A red-black tree is a binary search tree with the following properties:

1. Every node is colored with either red or black.
2. All leaf (nil) nodes are colored with black; if a node’s child is missing then we will assume that it has a nil child in that place and this nil child is always colored black.
3. Both children of a red node must be black nodes.
4. Every path from a node n to a descendent leaf has the same number of black nodes (not counting node n). We call this number the black height of n, which is denoted by bh(n).

Figure 5 shows an example of a red-black tree.

![img](http://community.topcoder.com/i/education/rbtrees5.jpg)