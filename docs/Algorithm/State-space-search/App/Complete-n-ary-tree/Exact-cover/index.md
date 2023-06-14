# Exact cover

一、在 zhihu [你认为最优美的数据结构是什么？ - RaoJi的回答 - 知乎](https://www.zhihu.com/question/32163076/answer/55533040) 中提及了[Dancing Links](https://en.wikipedia.org/wiki/Dancing_Links)、[Exact cover](https://en.wikipedia.org/wiki/Exact_cover)，由此而发现的。

二、"exact cover"的中文意思是"精确覆盖"

## wikipedia [Exact cover](https://en.wikipedia.org/wiki/Exact_cover)

In the [mathematical](https://en.wikipedia.org/wiki/Mathematical) field of [combinatorics](https://en.wikipedia.org/wiki/Combinatorics), given a collection *S* of [subsets](https://en.wikipedia.org/wiki/Subset) of a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) *X*, an **exact cover** is a subcollection $S^*$ of *S* such that each element in *X* is contained in *exactly one* subset in $S^*$. In other words, $S^*$ is a [partition](https://en.wikipedia.org/wiki/Partition_of_a_set) of *X* consisting of subsets contained in *S*. One says that each element in *X* **is covered by** exactly one subset in $S^*$. An exact cover is a kind of [cover](https://en.wikipedia.org/wiki/Cover_(topology)).



### Formal definition

> NOTE:
>
> 一、"不重不漏"，源自 zhihu [精确覆盖问题](https://zhuanlan.zhihu.com/p/617477033) 

#### examples

> NOTE:
>
> 一、在下面文章中，给出了更容易理解的例子:
>
> zhihu [精确覆盖问题](https://zhuanlan.zhihu.com/p/617477033) 
>
> zhihu [数独sudoku的解法与舞蹈链dancing link list](https://zhuanlan.zhihu.com/p/69737736?utm_id=0) 



### Representations

#### Matrix and hypergraph representations

> NOTE:
>
> 一、[incidence matrix](https://en.wikipedia.org/wiki/Incidence_matrix) 即"关联矩阵"，它能够用于表示relation

The relation "contains" can be represented by an [incidence matrix](https://en.wikipedia.org/wiki/Incidence_matrix).

The matrix includes one row for each subset in S and one column for each element in *X*. The entry in a particular row and column is 1 if the corresponding subset contains the corresponding element, and is 0 otherwise. As each row represents the elements contained in the corresponding subset and each column represents the subsets containing the corresponding element, an incidence matrix effectively provides both the standard and inverse representations.

In the matrix representation, an exact cover is a selection of rows such that each column contains a 1 in exactly one selected row.

For example, the relation "contains" in the [detailed example](https://en.wikipedia.org/wiki/Exact_cover#Detailed_example) above can be represented by a 6×7 incidence matrix:

|          |   1   |   2   |   3   |   4   |   5   |   6   |   7   |
| :------: | :---: | :---: | :---: | :---: | :---: | :---: | ----- |
|   *A*    |   1   |   0   |   0   |   1   |   0   |   0   | 1     |
|   *B*    | **1** |   0   |   0   | **1** |   0   |   0   | 0     |
|   *C*    |   0   |   0   |   0   |   1   |   1   |   0   | 1     |
|   *D*    |   0   |   0   | **1** |   0   | **1** | **1** | 0     |
|   *E*    |   0   |   1   |   1   |   0   |   0   |   1   | 1     |
|   *F*    |   0   | **1** |   0   |   0   |   0   |   0   | **1** |

Again, the subcollection $S^*$ = {*B*, *D*, *F*} is an exact cover, since each element is contained in exactly one selected subset, i.e., each column contains a 1 in exactly one selected row, as the highlighting makes clear.

#### Graph representation

The relation "contains" can be represented by a [bipartite graph](https://en.wikipedia.org/wiki/Bipartite_graph).

The vertices of the graph are divided into two disjoint sets, one representing the subsets in S and another representing the elements in *X*. If a subset contains an element, an edge connects the corresponding vertices in the graph.

In the graph representation, an exact cover is a selection of vertices corresponding to subsets such that each vertex corresponding to an element is connected to exactly one selected vertex.

For example, the relation "contains" in the [detailed example](https://en.wikipedia.org/wiki/Exact_cover#Detailed_example) above can be represented by a bipartite graph with 6+7 = 13 vertices:

[![Exact-cover-bigraph-highlighted.svg](https://upload.wikimedia.org/wikipedia/en/thumb/9/96/Exact-cover-bigraph-highlighted.svg/300px-Exact-cover-bigraph-highlighted.svg.png)](https://en.wikipedia.org/wiki/File:Exact-cover-bigraph-highlighted.svg)





## wikipedia [Knuth's Algorithm X](https://en.wikipedia.org/wiki/Knuth%27s_Algorithm_X)

**Algorithm X** is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) for solving the [exact cover](https://en.wikipedia.org/wiki/Exact_cover) problem. It is a straightforward [recursive](https://en.wikipedia.org/wiki/Recursion_(computer_science)), [nondeterministic](https://en.wikipedia.org/wiki/Nondeterministic_algorithm), [depth-first](https://en.wikipedia.org/wiki/Depth-first), [backtracking](https://en.wikipedia.org/wiki/Backtracking) algorithm used by [Donald Knuth](https://en.wikipedia.org/wiki/Donald_Knuth) to demonstrate an efficient implementation called DLX, which uses the [dancing links](https://en.wikipedia.org/wiki/Dancing_links) technique.

The exact cover problem is represented in Algorithm X by a matrix *A* consisting of 0s and 1s. The goal is to select a subset of the rows such that the digit 1 appears in each column exactly once.

Algorithm X works as follows:

```
# If the matrix A has no columns, the current partial solution is a valid solution; terminate successfully.
    1、Otherwise choose a column c (deterministically).
    2、Choose a row r such that Ar, c = 1 (nondeterministically).
    3、Include row r in the partial solution.
    4、For each column j such that Ar, j = 1,
        for each row i such that Ai, j = 1,
            delete row i from matrix A. # 消除与这个set包含相同元素的(相互重叠的)set(行)
        delete column j from matrix A. # 消除这个set包含点(列)
    Repeat this algorithm recursively on the reduced matrix A.
```



> NOTE:
>
> 一、基于 [incidence matrix](https://en.wikipedia.org/wiki/Incidence_matrix) (关联矩阵)，每次尝试选择一行(set)，然后消除这个set包含点(列)、与这个set包含相同元素的(相互重叠的)set(行)，如此往复直至最后。
>



The nondeterministic choice of *r* means that the algorithm recurses over independent **subalgorithms**; each **subalgorithm** inherits the current matrix *A*, but reduces it with respect to a different row *r*. If column *c* is entirely zero, there are no subalgorithms and the process terminates unsuccessfully.

> NOTE:
>
> 一、r是row，即一个set，
>
> 二、"independent **subalgorithm**" 指的是什么？指的是选择一行？应该是的，因为下面段落中提及了search tree

The subalgorithms form a [search tree](https://en.wikipedia.org/wiki/Search_tree) in a natural way, with the original problem at the root and with level *k* containing each subalgorithm that corresponds to *k* chosen rows. Backtracking is the process of traversing the tree in preorder, depth first.

Any systematic rule for choosing column *c* in this procedure will find all solutions, but some rules work much better than others. To reduce the number of iterations, Knuth suggests that the **column-choosing algorithm** select a column with the smallest number of 1s in it.



### Implementations

Knuth's main purpose in describing Algorithm X was to demonstrate the utility of [dancing links](https://en.wikipedia.org/wiki/Dancing_links). Knuth showed that Algorithm X can be implemented efficiently on a computer using dancing links in a process Knuth calls *"DLX"*. DLX uses the matrix representation of the [exact cover](https://en.wikipedia.org/wiki/Exact_cover) problem, implemented as [doubly linked lists](https://en.wikipedia.org/wiki/Doubly_linked_list) of the 1s of the matrix: each 1 element has a link to the next 1 above, below, to the left, and to the right of itself. (Technically, because the lists are circular, this forms a [torus](https://en.wikipedia.org/wiki/Torus)). Because exact cover problems tend to be sparse, this representation is usually much more efficient in both size and processing time required. DLX then uses dancing links to quickly select permutations of rows as possible solutions and to efficiently backtrack (undo) mistaken guesses.



## Dancing Link

是在zhihu [你认为最优美的数据结构是什么？ - RaoJi的回答 - 知乎]( https://www.zhihu.com/question/32163076/answer/55533040) 时发现的，下面是一些内容:

oi-wiki [Dancing Links](https://oi-wiki.org/search/dlx/)

## wikipedia [Dancing Links](https://en.wikipedia.org/wiki/Dancing_Links)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **dancing links** (**DLX**) is a technique for adding and deleting a node from a circular [doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list). It is particularly useful for efficiently implementing [backtracking](https://en.wikipedia.org/wiki/Backtracking) algorithms, such as [Knuth's Algorithm X](https://en.wikipedia.org/wiki/Knuth's_Algorithm_X) for the [exact cover problem](https://en.wikipedia.org/wiki/Exact_cover_problem).[[1\]](https://en.wikipedia.org/wiki/Dancing_Links#cite_note-1) Algorithm X is a [recursive](https://en.wikipedia.org/wiki/Recursion_(computer_science)), [nondeterministic](https://en.wikipedia.org/wiki/Nondeterministic_algorithm), [depth-first](https://en.wikipedia.org/wiki/Depth-first), [backtracking](https://en.wikipedia.org/wiki/Backtracking) [algorithm](https://en.wikipedia.org/wiki/Algorithm) that finds all solutions to the [exact cover](https://en.wikipedia.org/wiki/Exact_cover) problem. Some of the better-known exact cover problems include [tiling](https://en.wikipedia.org/wiki/Tessellation), the [*n* queens problem](https://en.wikipedia.org/wiki/Eight_queens_puzzle), and [Sudoku](https://en.wikipedia.org/wiki/Sudoku).

The name *dancing links*, which was suggested by [Donald Knuth](https://en.wikipedia.org/wiki/Donald_Knuth), stems from the way the algorithm works, as iterations of the algorithm cause the links to "dance" with partner links so as to resemble an "exquisitely choreographed dance." Knuth credits Hiroshi Hitotsumatsu and Kōhei Noshita with having invented the idea in 1979,[[2\]](https://en.wikipedia.org/wiki/Dancing_Links#cite_note-2) but it is his paper which has popularized it.

### Implementation

As the remainder of this article discusses the details of an implementation technique for Algorithm X, the reader is strongly encouraged to read the [Algorithm X](https://en.wikipedia.org/wiki/Algorithm_X) article first.

#### Main ideas

The idea of DLX is based on the observation that in a circular [doubly linked list](https://en.wikipedia.org/wiki/Doubly_linked_list) of nodes,

```
x.left.right ← x.right;
x.right.left ← x.left;
```

will remove node *x* from the list, while

```
x.left.right ← x;
x.right.left ← x;
```

will restore *x'*s position in the list, assuming that `x.right` and `x.left` have been left unmodified. This works regardless of the number of elements in the list, even if that number is 1.

Knuth observed that a naive implementation of his Algorithm X would spend an inordinate amount of time searching for 1's. When selecting a column, the entire matrix had to be searched for 1's. When selecting a row, an entire column had to be searched for 1's. After selecting a row, that row and a number of columns had to be searched for 1's. To improve this search time from [complexity](https://en.wikipedia.org/wiki/Big_O_notation) O(n) to O(1), Knuth implemented a [sparse matrix](https://en.wikipedia.org/wiki/Sparse_matrix) where only 1's are stored.

At all times, each node in the matrix will point to the adjacent nodes to the left and right (1's in the same row), above and below (1's in the same column), and the header for its column (described below). Each row and column in the matrix will consist of a circular doubly-linked list of nodes.

#### Header



> NOTE:
>
> 一、"control row"

Each column will have a special node known as the "column header," which will be included in the column list, and will form a special row ("control row") consisting of all the columns which still exist in the matrix.

Finally, each column header may optionally track the number of nodes in its column, so that locating a column with the lowest number of nodes is of [complexity](https://en.wikipedia.org/wiki/Big_O_notation) O(*n*) rather than O(*n*×*m*) where *n* is the number of columns and *m* is the number of rows. Selecting a column with a low node count is a heuristic which improves performance in some cases, but is not essential to the algorithm.
