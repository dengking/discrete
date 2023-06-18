# DLX



## wikipedia [Knuth's Algorithm X](https://en.wikipedia.org/wiki/Knuth%27s_Algorithm_X)

**Algorithm X** is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) for solving the [exact cover](https://en.wikipedia.org/wiki/Exact_cover) problem. It is a straightforward [recursive](https://en.wikipedia.org/wiki/Recursion_(computer_science)), [nondeterministic](https://en.wikipedia.org/wiki/Nondeterministic_algorithm), [depth-first](https://en.wikipedia.org/wiki/Depth-first), [backtracking](https://en.wikipedia.org/wiki/Backtracking) algorithm used by [Donald Knuth](https://en.wikipedia.org/wiki/Donald_Knuth) to demonstrate an efficient implementation called DLX, which uses the [dancing links](https://en.wikipedia.org/wiki/Dancing_links) technique.

> NOTE:
>
> 一、非常好的概括

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

The name *dancing links*, which was suggested by [Donald Knuth](https://en.wikipedia.org/wiki/Donald_Knuth), stems from the way the algorithm works, as iterations of the algorithm cause the links to "dance" with partner links so as to resemble an "exquisitely choreographed dance." Knuth credits(认为是...的功劳、归功于) Hiroshi Hitotsumatsu and Kōhei Noshita with having invented the idea in 1979,[[2\]](https://en.wikipedia.org/wiki/Dancing_Links#cite_note-2) but it is his paper which has popularized it.

> NOTE:
>
> 一、"exquisitely choreographed dance" "精心编排的舞蹈"

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

Knuth observed that a naive implementation of his Algorithm X would spend an inordinate(过多的) amount of time searching for 1's. When selecting a column, the entire matrix had to be searched for 1's. When selecting a row, an entire column had to be searched for 1's. After selecting a row, that row and a number of columns had to be searched for 1's. To improve this search time from [complexity](https://en.wikipedia.org/wiki/Big_O_notation) O(n) to O(1), Knuth implemented a [sparse matrix](https://en.wikipedia.org/wiki/Sparse_matrix) where only 1's are stored.

> NOTE:
>
> 一、 "[sparse matrix](https://en.wikipedia.org/wiki/Sparse_matrix)" 是一个创举。

At all times, each node in the matrix will point to the adjacent nodes to the left and right (1's in the same row), above and below (1's in the same column), and the header for its column (described below). Each row and column in the matrix will consist of a circular doubly-linked list of nodes.

> NOTE:
>
> 一、dancing links的主要结构:
>
> a、每个节点有5个pointer:
>
> 1、left、right
>
> 2、above、below
>
> 3、header for its column（属于哪一列）
>
> b、"Each row and column in the matrix will consist of a circular doubly-linked list of nodes"

#### Header

> NOTE:
>
> 一、"control row"

Each column will have a special node known as the "column header," which will be included in the column list, and will form a special row ("**control row**") consisting of all the columns which still exist in the matrix.

Finally, each column header may optionally track the number of nodes in its column, so that locating a column with the lowest number of nodes is of [complexity](https://en.wikipedia.org/wiki/Big_O_notation) O(*n*) rather than O(*n*×*m*) where *n* is the number of columns and *m* is the number of rows. Selecting a column with a low node count is a heuristic which improves performance in some cases, but is not essential to the algorithm.



#### Exploring

In Algorithm X, rows and columns are regularly eliminated from and restored to the matrix. 

> NOTE:
>
> 一、删除后如何恢复？

Eliminations are determined by selecting a column and a row in that column. If a selected column doesn't have any rows, the current matrix is unsolvable and must be backtracked. When an elimination occurs, all columns for which the selected row contains a 1 are removed, along with all rows (including the selected row) that contain a 1 in any of the removed columns. The columns are removed because they have been filled, and the rows are removed because they conflict with the selected row. To remove a single column, first remove the selected column's header. Next, for each row where the selected column contains a 1, traverse the row and remove it from other columns (this makes those rows inaccessible and is how conflicts are prevented). Repeat this column removal for each column where the selected row contains a 1. This order ensures that any removed node is removed exactly once and in a predictable order, so it can be backtracked appropriately. If the resulting matrix has no columns, then they have all been filled and the selected rows form the solution.



#### Backtracking

To backtrack, the above process must be reversed using the second algorithm stated above. One requirement of using that algorithm is that backtracking must be done as an exact reversal of eliminations. Knuth's paper gives a clear picture of these relationships and how the node removal and reinsertion works, and provides a slight relaxation of this limitation.



#### Optional constraints

It is also possible to solve one-cover problems in which a particular constraint is optional, but can be satisfied no more than once. Dancing Links accommodates these with primary columns which must be filled and secondary columns which are optional. This alters the algorithm's solution test from a matrix having no columns to a matrix having no primary columns and if the heuristic of minimum one's in a column is being used then it needs to be checked only within primary columns. Knuth discusses optional constraints as applied to the [*n* queens problem](https://en.wikipedia.org/wiki/Eight_queens_puzzle). The chessboard diagonals represent optional constraints, as some diagonals may not be occupied. If a diagonal is occupied, it can be occupied only once.

