# Exact cover

一、在 zhihu [你认为最优美的数据结构是什么？ - RaoJi的回答 - 知乎](https://www.zhihu.com/question/32163076/answer/55533040) 中提及了[Dancing Links](https://en.wikipedia.org/wiki/Dancing_Links)、[Exact cover](https://en.wikipedia.org/wiki/Exact_cover)，由此而发现的。

二、"exact cover"的中文意思是"精确覆盖"，它蕴含着"不重不漏"

三、exact cover problem有多种实现方式:

1、DLX

2、backtrack

## wikipedia [Exact cover](https://en.wikipedia.org/wiki/Exact_cover)

In the [mathematical](https://en.wikipedia.org/wiki/Mathematical) field of [combinatorics](https://en.wikipedia.org/wiki/Combinatorics), given a collection *S* of [subsets](https://en.wikipedia.org/wiki/Subset) of a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) *X*, an **exact cover** is a subcollection $S^*$ of *S* such that each element in *X* is contained in *exactly one* subset in $S^*$. In other words, $S^*$ is a [partition](https://en.wikipedia.org/wiki/Partition_of_a_set) of *X* consisting of subsets contained in *S*. One says that each element in *X* **is covered by** exactly one subset in $S^*$. An exact cover is a kind of [cover](https://en.wikipedia.org/wiki/Cover_(topology)).

> NOTE:
>
> 一、通俗理解:
>
> zhihu [精确覆盖问题](https://zhuanlan.zhihu.com/p/617477033) 
>
> 精确覆盖问题（Exact cover）的定义如下：
>
> > 给定一个大集合X={a1, a2, ..., am}（本文我们默认集合中不包含重复元素，且集合元素无序，下文不再赘述），以及一系列X的子集S1, S2, ..., Sn。要求从这n个子集中选出若干个，使得选出的所有子集两两互斥，且它们的并集恰好等于X。



### Formal definition

> NOTE:
>
> 一、"不重不漏"，源自 zhihu [精确覆盖问题](https://zhuanlan.zhihu.com/p/617477033) 

### Examples

> NOTE:
>
> 一、在下面文章中，给出了更容易理解的例子:
>
> zhihu [精确覆盖问题](https://zhuanlan.zhihu.com/p/617477033) 
>
> zhihu [数独sudoku的解法与舞蹈链dancing link list](https://zhuanlan.zhihu.com/p/69737736?utm_id=0) 



#### Basic examples

Let S = {*N*, *O*, *P*, *E*} be a collection of subsets of a set *X* = {1, 2, 3, 4} such that:

- *N* = { },
- *O* = {1, 3},
- *P* = {1, 2, 3}, and
- *E* = {2, 4}.

The subcollection {*O*, *E*} is an **exact cover** of *X*, since the subsets *O* = {1, 3} and *E* = {2, 4} are disjoint and their union is *X* = {1, 2, 3, 4}.



#### Detailed example

Let S = {*A*, *B*, *C*, *D*, *E*, *F*} be a collection of subsets of a set *X* = {1, 2, 3, 4, 5, 6, 7} such that:

- *A* = {1, 4, 7};
- ***B*** = {**1**, **4**};
- *C* = {4, 5, 7};
- ***D*** = {**3**, **5**, **6**};
- *E* = {2, 3, 6, 7}; and
- ***F*** = {**2**, **7**}.

The subcollection S* = {*B*, *D*, *F*} is an **exact cover**, since each element is covered by (contained in) exactly one selected subset, as the highlighting makes clear.



#### Noteworthy examples

Due to its NP-completeness, any problem in NP can be [reduced](https://en.wikipedia.org/wiki/Reduction_(complexity)) to **exact cover** problems, which then can be solved with techniques such as **Dancing Links**. However, for some well known problems, the reduction is particularly direct. For instance, the problem of tiling a board with [pentominoes](https://en.wikipedia.org/wiki/Pentominoes), and solving [Sudoku](https://en.wikipedia.org/wiki/Sudoku) can both be viewed as **exact cover** problems.

##### Pentomino tiling

> NOTE:
>
> 一、五格镶嵌

*Main article:* [Pentomino](https://en.wikipedia.org/wiki/Pentomino) 



##### Sudoku

*Main articles: [Sudoku](https://en.wikipedia.org/wiki/Sudoku), [Mathematics of Sudoku](https://en.wikipedia.org/wiki/Mathematics_of_Sudoku), [Sudoku solving algorithms](https://en.wikipedia.org/wiki/Sudoku_solving_algorithms)* 



##### N queens problem

*Main article:* [N queens problem](https://en.wikipedia.org/wiki/N_queens_problem)

The [N queens problem](https://en.wikipedia.org/wiki/N_queens_problem) is an example of a generalized exact cover problem.



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

Again, the subcollection $S^*$ = {*B*, *D*, *F*} is an **exact cover**, since each element is contained in exactly one selected subset, i.e., each column contains a 1 in exactly one selected row, as the highlighting makes clear.

#### Graph representation

The relation "contains" can be represented by a [bipartite graph](https://en.wikipedia.org/wiki/Bipartite_graph).

The vertices of the graph are divided into two disjoint sets, one representing the subsets in S and another representing the elements in *X*. If a subset contains an element, an edge connects the corresponding vertices in the graph.

In the graph representation, an exact cover is a selection of vertices corresponding to subsets such that each vertex corresponding to an element is connected to exactly one selected vertex.

For example, the relation "contains" in the [detailed example](https://en.wikipedia.org/wiki/Exact_cover#Detailed_example) above can be represented by a bipartite graph with 6+7 = 13 vertices:

[![Exact-cover-bigraph-highlighted.svg](https://upload.wikimedia.org/wikipedia/en/thumb/9/96/Exact-cover-bigraph-highlighted.svg/300px-Exact-cover-bigraph-highlighted.svg.png)](https://en.wikipedia.org/wiki/File:Exact-cover-bigraph-highlighted.svg)





