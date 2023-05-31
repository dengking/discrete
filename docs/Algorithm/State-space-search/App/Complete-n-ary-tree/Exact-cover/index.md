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

> NOTE:
>
> 一、基于 [incidence matrix](https://en.wikipedia.org/wiki/Incidence_matrix) (关联矩阵)
