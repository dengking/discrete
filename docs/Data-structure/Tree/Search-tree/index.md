# Search tree

"search tree"是被广泛使用的一种tree；



## wikipedia [Search tree](https://en.wikipedia.org/wiki/Search_tree)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **search tree** is a [tree data structure](https://en.wikipedia.org/wiki/Tree_data_structure) used for locating specific keys from within a set. In order for a [tree](https://en.wikipedia.org/wiki/Tree_data_structure) to function as a search tree, the key for each node must be greater than any keys in subtrees on the left, and less than any keys in subtrees on the right.[[1\]](https://en.wikipedia.org/wiki/Search_tree#cite_note-1)

The advantage of search trees is that their efficient search time given the tree is reasonably balanced, which is to say the [leaves](https://en.wikipedia.org/wiki/Tree_data_structure#Terminologies_used_in_Trees) at either end are of comparable depths. Various search-tree data structures exist, several of which also allow efficient insertion and deletion of elements, which operations then have to maintain tree balance.

Search trees are often used to implement an [associative array](https://en.wikipedia.org/wiki/Associative_array). The search tree algorithm uses the key from the [key-value pair](https://en.wikipedia.org/wiki/Key-value_pair) to find a location, and then the application stores the entire key–value pair at that particular location.

### Types of Trees

#### Binary Search Tree

Main article: [Binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree)

A Binary Search Tree is a node-based data structure where each node contains a key and two subtrees, the left and right. For all nodes, the left subtree's key must be less than the node's key, and the right subtree's key must be greater than the node's key. These subtrees must all qualify as binary search trees.

The worst-case [time complexity](https://en.wikipedia.org/wiki/Time_complexity) for searching a binary search tree is the [height of the tree](https://en.wikipedia.org/wiki/Tree_(data_structure)#Terminology_used_in_trees), which can be as small as O(log n) for a tree with n elements.

#### B-tree

Main article: [B-tree](https://en.wikipedia.org/wiki/B-tree)

B-trees are generalizations of binary search trees in that they can have a variable number of subtrees at each node. While child-nodes have a pre-defined range, they will not necessarily be filled with data, meaning B-trees can potentially waste some space. The advantage is that B-trees do not need to be re-balanced as frequently as other [self-balancing trees](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree).

Due to the variable range of their node length, B-trees are optimized for systems that read large blocks of data, they are also commonly used in databases.

The time complexity for searching a B-tree is O(log n).

#### (a,b)-tree

Main article: [(a,b)-tree](https://en.wikipedia.org/wiki/(a,b)-tree)

An (a,b)-tree is a search tree where all of its leaves are the same depth. Each node has at least **a** children and at most **b** children, while the root has at least 2 children and at most **b** children.

**a** and **b** can be decided with the following formula:[[2\]](https://en.wikipedia.org/wiki/Search_tree#cite_note-2)

{\displaystyle 2\leq a\leq {\frac {(b+1)}{2}}}![2\leq a\leq {\frac  {(b+1)}{2}}](https://wikimedia.org/api/rest_v1/media/math/render/svg/48c13c821a07827e3972d2b9c4cdc9ed26993b23)

The time complexity for searching an (a,b)-tree is O(log n).



#### Ternary search tree

Main article: [Ternary search tree](https://en.wikipedia.org/wiki/Ternary_search_tree)

A ternary search tree is a type of [tree](https://en.wikipedia.org/wiki/Tree) that can have 3 nodes: a lo kid, an equal kid, and a hi kid. Each node stores a single character and the tree itself is ordered the same way a binary search tree is, with the exception of a possible third node.

Searching a ternary search tree involves passing in a [string](https://en.wikipedia.org/wiki/String_(computer_science)) to test whether any path contains it.

The time complexity for searching a balanced ternary search tree is O(log n).





### Searching Algorithms

#### Searching for a Specific Key

Assuming the tree is ordered, we can take a key and attempt to locate it within the tree. The following algorithms are generalized for binary search trees, but the same idea can be applied to trees of other formats.

##### Recursive

```c
search-recursive(key, node)
    if node is NULL
        return EMPTY_TREE
    if key < node.key
        return search-recursive(key, node.left)
    else if key > node.key
        return search-recursive(key, node.right)
    else
        return node
```

##### Iterative

```c
searchIterative(key, node)
    currentNode := node
    while currentNode is not NULL
        if currentNode.key = key
            return currentNode
        else if currentNode.key > key
            currentNode := currentNode.left
        else
            currentNode := currentNode.right
```

#### Searching for Min and Max

In a sorted tree, the minimum is located at the node farthest left, while the maximum is located at the node farthest right.[[3\]](https://en.wikipedia.org/wiki/Search_tree#cite_note-3)

##### Minimum

```c
findMinimum(node)
    if node is NULL
        return EMPTY_TREE
    min := node
    while min.left is not NULL
        min := min.left
    return min.key
```

##### Maximum

```c
findMaximum(node)
    if node is NULL
        return EMPTY_TREE
    max := node
    while max.right is not NULL
        max := max.right
    return max.key
```
