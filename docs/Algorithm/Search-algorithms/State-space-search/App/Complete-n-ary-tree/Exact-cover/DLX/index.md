# DLX



## wikipedia [Knuth's Algorithm X](https://en.wikipedia.org/wiki/Knuth%27s_Algorithm_X)

**Algorithm X** is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) for solving the [exact cover](https://en.wikipedia.org/wiki/Exact_cover) problem. It is a straightforward [recursive](https://en.wikipedia.org/wiki/Recursion_(computer_science)), [nondeterministic](https://en.wikipedia.org/wiki/Nondeterministic_algorithm), [depth-first](https://en.wikipedia.org/wiki/Depth-first), [backtracking](https://en.wikipedia.org/wiki/Backtracking) algorithm used by [Donald Knuth](https://en.wikipedia.org/wiki/Donald_Knuth) to demonstrate an efficient implementation called DLX, which uses the [dancing links](https://en.wikipedia.org/wiki/Dancing_links) technique.

> NOTE:
>
> 一、非常好的概括

The exact cover problem is represented in Algorithm X by a matrix *A* consisting of 0s and 1s. The goal is to select a subset of the rows such that the digit 1 appears in each column exactly once.

Algorithm X works as follows:

`#` If the matrix $A$ has no columns, the current partial solution is a valid solution; terminate successfully.

​    1、Otherwise choose a column $c$ (deterministically).

​    2、Choose a row r such that $A_{r, c} = 1$ (nondeterministically).

​    3、Include row $r$ in the partial solution.

​    4、For each column $j$ such that $A_{r, j}= 1$ ,

​          for each row i such that $A_{i, j}=1$,

​              delete row $i$ from matrix $A$. # 消除与这个set包含相同元素的(相互重叠的)set(行)		

​          delete column $j$ from matrix A. # 消除这个set包含点(列)

​    5、Repeat this algorithm recursively on the reduced matrix A.



> NOTE:
>
> 一、基于 [incidence matrix](https://en.wikipedia.org/wiki/Incidence_matrix) (关联矩阵)，每次尝试选择一行(set)，然后消除这个set包含点(列)、与这个set包含相同元素的(相互重叠的)set(行)，如此往复直至最后。
>



The nondeterministic choice of *r* means that the algorithm recurses over independent **subalgorithms**; each **subalgorithm** inherits the current matrix *A*, but reduces it with respect to a different row *r*. If column *c* is entirely zero, there are no **subalgorithms** and the process terminates unsuccessfully.

> NOTE:
>
> 一、r是row，即一个set，
>
> 二、"**subalgorithm**" 指的是什么？结合上面的内容可知它指的是选择一行并执行后续的消除(2~5)

The subalgorithms form a [search tree](https://en.wikipedia.org/wiki/Search_tree) in a natural way, with the original problem at the root and with level *k* containing each subalgorithm that corresponds to *k* chosen rows. Backtracking is the process of traversing the tree in preorder, depth first.

> NOTE:
>
> 一、上面这段话中的 "The subalgorithms form a [search tree](https://en.wikipedia.org/wiki/Search_tree) in a natural way" 如何理解呢？
>
> 删行，每次执行 subalgorithm 会删除一行，因此

Any systematic rule for choosing column *c* in this procedure will find all solutions, but some rules work much better than others. To reduce the number of iterations, Knuth suggests that the **column-choosing algorithm** select a column with the smallest number of 1s in it.

### Example

For example, consider the exact cover problem specified by the universe *U* = {1, 2, 3, 4, 5, 6, 7} and the collection of sets S = {*A*, *B*, *C*, *D*, *E*, *F*}, where:

- *A* = {1, 4, 7};
- *B* = {1, 4};
- *C* = {4, 5, 7};
- *D* = {3, 5, 6};
- *E* = {2, 3, 6, 7}; and
- *F* = {2, 7}.



This problem is represented by the matrix:

|      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| *A*  |  1   |  0   |  0   |  1   |  0   |  0   |  1   |
| *B*  |  1   |  0   |  0   |  1   |  0   |  0   |  0   |
| *C*  |  0   |  0   |  0   |  1   |  1   |  0   |  1   |
| *D*  |  0   |  0   |  1   |  0   |  1   |  1   |  0   |
| *E*  |  0   |  1   |  1   |  0   |  0   |  1   |  1   |
| *F*  |  0   |  1   |  0   |  0   |  0   |  0   |  1   |

```python
constraint_matrix = [
    [1, 0, 0, 1, 0, 0, 1],
    [1, 0, 0, 1, 0, 0, 0],
    [0, 0, 0, 1, 1, 0, 1],
    [0, 0, 1, 0, 1, 1, 0],
    [0, 1, 1, 0, 0, 1, 1],
    [0, 1, 0, 0, 0, 0, 1],
]
```



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

```pseudocode
x.left.right ← x.right;
x.right.left ← x.left;
```

will remove node *x* from the list, while

```pseudocode
x.left.right ← x;
x.right.left ← x;
```

will restore *x'*s position in the list, assuming that `x.right` and `x.left` have been left unmodified. This works regardless of the number of elements in the list, even if that number is 1.

> NOTE:
>
> 一、对于Dancing Links，下面操作非常容易实现:
>
> 1、eliminated
>
> 2、restored

Knuth observed that a naive implementation of his Algorithm X would spend an inordinate(过多的) amount of time searching for 1's. When selecting a column, the entire matrix had to be searched for 1's. When selecting a row, an entire column had to be searched for 1's. After selecting a row, that row and a number of columns had to be searched for 1's. To improve this search time from [complexity](https://en.wikipedia.org/wiki/Big_O_notation) O(n) to O(1), Knuth implemented a [sparse matrix](https://en.wikipedia.org/wiki/Sparse_matrix) where only 1's are stored.

> NOTE:
>
> 一、 "[sparse matrix](https://en.wikipedia.org/wiki/Sparse_matrix)" 是一个创举。

At all times, each node in the matrix will point to the adjacent nodes to the **left** and **right** (1's in the same row), **above** and **below** (1's in the same column), and the **header for its column** (described below). Each row and column in the matrix will consist of a circular doubly-linked list of nodes.



#### Header

> NOTE:
>
> 一、"control row"

Each column will have a special node known as the "**column header**", which will be included in the column list, and will form a special row ("**control row**") consisting of all the columns which still exist in the matrix.

Finally, each **column heade**r may optionally track the number of nodes in its column, so that locating a column with the lowest number of nodes is of [complexity](https://en.wikipedia.org/wiki/Big_O_notation) O(*n*) rather than O(*n*×*m*) where *n* is the number of columns and *m* is the number of rows. Selecting a column with a low node count is a heuristic which improves performance in some cases, but is not essential to the algorithm.



#### Exploring

In Algorithm X, rows and columns are regularly **eliminated** from and **restored** to the matrix. 

> NOTE:
>
> 一、删除后如何恢复？

**Eliminations** are determined by selecting a column and a row in that column. If a selected column doesn't have any rows, the current matrix is unsolvable and must be backtracked. When an **elimination** occurs, all columns for which the selected row contains a 1 are removed, along with all rows (including the selected row) that contain a 1 in any of the removed columns. The columns are removed because they have been filled, and the rows are removed because they conflict with the selected row. 

To remove a single column, first remove the selected column's header. Next, for each row where the selected column contains a 1, traverse the row and remove it from other columns (this makes those rows inaccessible and is how conflicts are prevented). Repeat this **column removal** for each column where the selected row contains a 1. This order ensures that any removed node is removed exactly once and in a predictable order, so it can be backtracked appropriately. If the resulting matrix has no columns, then they have all been filled and the selected rows form the solution.



#### Backtracking

To backtrack, the above process must be reversed using the second algorithm stated above. One requirement of using that algorithm is that backtracking must be done as an exact reversal of eliminations. Knuth's paper gives a clear picture of these relationships and how the node removal and reinsertion works, and provides a slight relaxation of this limitation.



#### Optional constraints

It is also possible to solve one-cover problems in which a particular constraint is optional, but can be satisfied no more than once. Dancing Links accommodates these with primary columns which must be filled and secondary columns which are optional. This alters the algorithm's solution test from a matrix having no columns to a matrix having no primary columns and if the heuristic of minimum one's in a column is being used then it needs to be checked only within primary columns. Knuth discusses optional constraints as applied to the [*n* queens problem](https://en.wikipedia.org/wiki/Eight_queens_puzzle). The chessboard diagonals represent optional constraints, as some diagonals may not be occupied. If a diagonal is occupied, it can be occupied only once.



## Implementation

### 如何实现sparse [incidence matrix](https://en.wikipedia.org/wiki/Incidence_matrix) (关联矩阵) ？

> NOTE:
>
> 在 wikipedia [Dancing Links](https://en.wikipedia.org/wiki/Dancing_Links) 中使用的是sparse matrix，为了以示区分，我使用的是 sparse [incidence matrix](https://en.wikipedia.org/wiki/Incidence_matrix) (关联矩阵) 这个词

DLX算法是采用的是sparse [incidence matrix](https://en.wikipedia.org/wiki/Incidence_matrix) (关联矩阵) 来描述问题，它充分展示了选择问题的合适表示方式来设计算法的重要性。DLX算法的sparse [incidence matrix](https://en.wikipedia.org/wiki/Incidence_matrix) 如图所示:

[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/3/37/Dancing_links.svg/220px-Dancing_links.svg.png)](https://en.wikipedia.org/wiki/File:Dancing_links.svg) 

关键词:  sparse matrix、circular doubly-linked list

#### Nodes

`Node` <--- `HeaderNode` 

​          <--- `RootNode` 



`Node` 有5个pointer:

1、left、right

2、above(up)、below(down)

3、header for its column（属于哪一列），后面简称"**column header**"、header node

```python

class Node:
    def __init__(self, header, value):
        self.header = header  # header for its column（属于哪一列），后面简称"**column header**"、header node
        self.up = self
        self.down = self
        self.left = self
        self.right = self
        self.value = value

    def __repr__(self):
        return f"Node: row={self.value},col={self.header.value}"


class HeaderNode(Node):
    def __init__(self, column_id):
        super(HeaderNode, self).__init__(self, column_id)
        self.cnt = 0  # 这一列有多少行，作为heuristic

    def __repr__(self):
        return "HeaderNode: {}".format(self.value)


class RootNode(Node):
    def __init__(self):
        super(RootNode, self).__init__(self, 'RootNode')

    def __repr__(self):
        return 'RootNode'

```



#### Circular doubly-linked list

"Each row and column in the matrix will consist of a **circular doubly-linked list** of nodes".



一、DLX算法充分应用了circular doubly linked list的特性:

1、在circular doubly linked list中，拿到一个节点就相当于拿到整个linked list，它能够方便地对整个linked list进行遍历

2、在circular doubly linked list中，能够非常容易实现插入、删除一个节点

二、dummy node: 

a、root是control row的dummy node

b、control row是每一列的dummy node

DLX是通过root拿到control row，然后拿到每一列，来将这个matrix给构建起来的



显然它的实现是需要对link的操作非常熟悉。



#### 搜索策略

概述: exact cover问题的解是由row组成的，因此它是需要对row进行backtrack: 每一列肯定要选择一行，因此它会尝试一列的所有的行，所以它可以看作是**列驱动**的。

每次都会选择**行数**最少的一列，然后尝试这一列的不同的行（backtrack）；选择最少行数的列是一种heuristic，显然行数最少的，能够快速地尝试它的每一行，按照作者的说法，能够加速搜索。DLX是**列驱动**的，固定地选择行数最少的一列，然后选择与这一列相交的行。只在选择一列、一行后，才进行下一轮的迭代。	

选择一列就相当于这一列的值已经满足了，就可以将这一列进行cover（从sparse incidence matrix中删除），此时这一列已经从matrix中抽出列，然后对这列的所有的行进行尝试，尝试完了后，才能够将这一列进行uncover复原。

`__select_min_header__` 中，当搜索到一个列，这个列上没有row的时候，此时是可以直接判定这个检索是失败的，对于这种情况有两种实现方式:

1、判定这一列的行树，如果为0，则直接return

2、不做特殊处理，和其它的有行的列的处理流程一样，由于它上面没有行，所以会直接进行`__cover__`、`__uncover__` 

在 `__solve_impl__` 中，对于这个`cnt`为0的header，它会直接进入`__uncover__`中，然后返回。也就是说，这种写法的本意是: 只有在header上有row的情况下，才会进入下一轮的迭代中，否则直接`__uncover__`返回。

在尝试了一列的所有的row之后，才可以`__uncover__`。

这种写法的另外一个优势是: 如果存在一列上没有任何行，即问题本身是无解的，则它是可以直接将这个没有任何行的列给选择出来的。



3、为什么cover和uncover是朝着相反的方向

why cover and uncover function iterate towards reverse direction in dancing link algorithm

> In the Dancing Links algorithm, the "cover" and "uncover" functions iterate in the reverse direction to efficiently backtrack and restore the state of the algorithm.
>
> The Dancing Links algorithm is used to solve exact cover problems, such as the Sudoku puzzle or the N-Queens problem. It is based on the idea of representing the problem as a matrix of 0s and 1s, where each row represents a constraint and each column represents a choice. The goal is to find a combination of choices that satisfies all the constraints.
>
> The "cover" function is used to remove a column from the matrix and all rows that intersect with that column. This removal is done by updating the links between the neighboring nodes in the matrix. The purpose of covering a column is to indicate that a choice has been made and to prevent it from being chosen again in subsequent iterations.
>
> On the other hand, the "uncover" function is used to restore a previously covered column and its associated rows. It reverses the changes made by the "cover" function, restoring the links between the nodes and allowing the algorithm to explore other possible choices.
>
> By iterating in the reverse direction during the "uncover" operation, the algorithm can efficiently backtrack to the previous state and explore alternative choices. This is crucial for finding all possible solutions to the exact cover problem.
>
> In summary, the reverse direction of iteration in the "cover" and "uncover" functions in the Dancing Links algorithm allows for efficient backtracking and exploration of alternative choices to find all possible solutions.





### Python

https://github.com/topics/dancing-links?l=python 

[mcgill-Algorithm X in 30 lines!](https://www.cs.mcgill.ca/~aassaf9/python/algorithm_x.html)

[sraaphorst ](https://github.com/sraaphorst)/ [dlx-python](https://github.com/sraaphorst/dlx-python)

[zacholade](https://github.com/zacholade)/**[sudoku-dancing-links](https://github.com/zacholade/sudoku-dancing-links)** 



#### Get all solutions

[jovian-dancing-links](https://jovian.com/fuzzyray/dancing-links)

```c++
from typing import List, Union

"""
1、https://jovian.com/fuzzyray/dancing-links
"""


class Node:
    """Nodes for the sparse matrix"""

    def __init__(self, header_node=None):
        self.value = None  # 节点的值
        self.left = self
        self.right = self
        self.up = self
        self.down = self
        self.column = header_node

    def __repr__(self):
        return f"Node:row={self.value},col={self.column.value}"


class ColumnNode(Node):
    def __init__(self, column_id):
        super().__init__(header_node=self)
        self.value = column_id
        self.node_count = 0

    def __repr__(self):
        return "HeaderNode: {}".format(self.value)


class RootNode(Node):
    def __init__(self, value='root'):
        super().__init__()
        self.value = value

    def __repr__(self):
        return "RootNode"


class DancingLinksAlgorithm:

    def __init__(self, matrix: List[List]):
        self.root = RootNode()  # Create our root node for accessing the matrix
        self.columns = []  # all columns
        self.__create_sparse_matrix__(matrix)
        self.solutions = []  # 所有的答案

    def __create_sparse_matrix__(self, matrix: List):
        # Create the column header nodes
        for col_idx in range(len(matrix[0])):
            new_node = ColumnNode(col_idx)
            last_node = self.root.left
            new_node.right = self.root
            self.root.left = new_node
            new_node.left = last_node
            last_node.right = new_node
            self.columns.append(new_node)

        for row_idx in range(len(matrix)):  # 逐行构建
            row_start_node = None
            for col_idx in range(len(matrix[0])):
                if matrix[row_idx][col_idx]:
                    # Link new node up/down
                    header: ColumnNode = self.columns[col_idx]
                    new_node = Node(header)
                    new_node.value = row_idx
                    col_last_node = header.up
                    new_node.down = header
                    header.up = new_node
                    new_node.up = col_last_node
                    col_last_node.down = new_node
                    header.node_count += 1
                    # Link new node left/right
                    if row_start_node:
                        row_last_node = row_start_node.left
                        new_node.right = row_start_node
                        row_start_node.left = new_node
                        new_node.left = row_last_node
                        row_last_node.right = new_node
                    else:
                        row_start_node = new_node

    def print_matrix(self):
        node: Union[Node, ColumnNode] = self.root
        while node.right != self.root:
            node = node.right
            column = node
            print(node, 'node_count:', node.node_count)
            while node.down != column:
                node = node.down
                print('\t{} Right{} Left{}'.format(node, node.right, node.left))
            node = node.down

    def get_min_column(self) -> ColumnNode:
        """
        get_min_column implements Heuristic S from Donald Knuth's Dancing Links paper. The Heuristic is to
        deterministically choose the column with the least number of nodes.
        :return:
        """
        node: Union[Node, ColumnNode] = self.root.right
        min_column = node
        while node != self.root:
            if node.node_count < min_column.node_count:
                min_column = node
            node = node.right
        return min_column

    @classmethod
    def __cover__(cls, node: Union[ColumnNode, Node]):
        column = node.column
        column.right.left = column.left
        column.left.right = column.right

        row = column.down
        while row != column:
            right_node = row.right
            # 需要注意: 对于row本身是不需要执行下面循环体的，这是因为需要通过列拿到这些行，所以不能够将这列和这些行的关系解除
            # 在前面的逻辑中这一列已经被从control row中剔除了，所以它们无法通过这一列被检索到
            while right_node != row:
                right_node.up.down = right_node.down
                right_node.down.up = right_node.up
                right_node.column.node_count -= 1
                right_node = right_node.right
            row = row.down

    @classmethod
    def __uncover__(cls, node):
        column = node.column

        row = column.up
        while row != column:
            left_node = row.left
            while left_node != row:
                left_node.up.down = left_node
                left_node.down.up = left_node
                left_node.column.node_count += 1
                left_node = left_node.left
            row = row.up

        column.right.left = column
        column.left.right = column

    def solve(self):
        self.__solve_impl__(0)
        return self.solutions

    def __solve_impl__(self, k, solution=[]):
        if self.root.right == self.root:
            self.solutions.append(solution[:])
            return

        column = self.get_min_column()
        if column.node_count == 0:
            return
        self.__cover__(column)
        print(f'cover column:{column}')
        row_node = column.down
        while row_node != column:
            solution.append(row_node)
            left_node = row_node.left
            while left_node != row_node:  # 将这一行所有占据的列给消除掉
                self.__cover__(left_node)
                left_node = left_node.left

            self.__solve_impl__(k + 1, solution)

            solution.pop()
            # undo
            right_node = row_node.right
            while right_node != row_node:
                self.__uncover__(right_node)
                right_node = right_node.right
            row_node = row_node.down  # move next

        self.__uncover__(column)
        print(f'uncover column:{column}')


if __name__ == '__main__':
    constraint_matrix1 = [
        [(0, 0, 1), 0, 0, 0, (0, 0, 1), 0, 0, 0, (0, 0, 1), 0, 0, 0],  # 1 at (0,0)
        [0, (0, 1, 1), 0, 0, (0, 1, 1), 0, 0, 0, 0, (0, 1, 1), 0, 0],  # 1 at (0,1)
        [0, 0, (1, 0, 1), 0, 0, (1, 0, 1), 0, 0, (1, 0, 1), 0, 0, 0],  # 1 at (1,0)
        [0, 0, 0, (1, 1, 1), 0, (1, 1, 1), 0, 0, 0, (1, 1, 1), 0, 0],  # 1 at (1,1)
        [(0, 0, 2), 0, 0, 0, 0, 0, (0, 0, 2), 0, 0, 0, (0, 0, 2), 0],  # 2 at (0,0)
        [0, (0, 1, 2), 0, 0, 0, 0, (0, 1, 2), 0, 0, 0, 0, (0, 1, 2)],  # 2 at (0,1)
        [0, 0, (1, 0, 2), 0, 0, 0, 0, (1, 0, 2), 0, 0, (1, 0, 2), 0],  # 2 at (1,0)
        [0, 0, 0, (1, 1, 2), 0, 0, 0, (1, 1, 2), 0, 0, 0, (1, 1, 2)]  # 2 at (1,1)
    ]

    dlx1 = DancingLinksAlgorithm(constraint_matrix1)
    print(dlx1.solve())

    constraint_matrix2 = [
        [1, 0, 0, 1, 0, 0, 1],
        [1, 0, 0, 1, 0, 0, 0],
        [0, 0, 0, 1, 1, 0, 1],
        [0, 0, 1, 0, 1, 1, 0],
        [0, 1, 1, 0, 0, 1, 1],
        [0, 1, 0, 0, 0, 0, 1],
    ]
    dlx2 = DancingLinksAlgorithm(constraint_matrix2)
    print(dlx2.solve())

```



```c++
cover: HeaderNode: 0
cover: HeaderNode: 1
cover: HeaderNode: 2
cover: HeaderNode: 3
uncover: HeaderNode: 3
uncover: HeaderNode: 2
uncover: HeaderNode: 1
cover: HeaderNode: 1
cover: HeaderNode: 2
cover: HeaderNode: 3
uncover: HeaderNode: 3
uncover: HeaderNode: 2
uncover: HeaderNode: 1
uncover: HeaderNode: 0
```



上述方式非常类似于加括号。



test

```py
from typing import List


class Node:
    def __init__(self, header, value):
        self.header = header
        self.up = self
        self.down = self
        self.left = self
        self.right = self
        self.value = value


class HeaderNode(Node):
    def __init__(self, column_id):
        super(HeaderNode, self).__init__(self, column_id)
        self.cnt = 0


class RootNode(Node):
    def __init__(self):
        super(RootNode, self).__init__(self, 'RootNode')

    def __repr__(self):
        return 'RootNode'


class DancingLinksAlgorithm:
    def __init__(self, matrix: List):
        self.root = RootNode()
        self.__create__(matrix)
        self.headers = []
        self.solutions = []

    def __create__(self, matrix: List):
        for col in range(0, len(matrix[0])):
            node = HeaderNode(col)
            last_node = self.root.left
            last_node.right = node
            self.root.left = node
            node.left = last_node
            node.right = self.root
            self.headers.append(node)
        for row in range(0, len(matrix)):
            row_first_node = None
            for col in range(0, matrix[row]):
                header = self.headers[col]
                if matrix[row][col]:
                    node = Node(header, matrix[row][col])
                    col_last_node = header.up
                    col_last_node.down = node
                    node.up = col_last_node
                    node.down = header
                    header.up = node
                    if row_first_node is None:
                        row_first_node = node
                    else:
                        row_last_node = row_first_node.left
                        row_last_node.right = node
                        node.left = row_last_node
                        node.right = row_first_node
                        row_first_node.left = node

    def solve(self):
        self.__solve_impl__(0)

    def cover(self, node):
        pass

    def uncover(self, node):
        pass

    def __select_min_header__(self):
        pass

    def __solve_impl__(self, k, solution=[]):
        if self.root.left == self.root:
            self.solutions.append(solution[:])

```



### C++



#### [gkaranikas](https://github.com/gkaranikas)/[dancing-links](https://github.com/gkaranikas/dancing-links)



column header node 和 matrix node必须是相同的类型，只有这样才能够相互引用。

首先构建control row，然后逐列构建。

因为无论是行还是列，都需要整体地进行删除和恢复，因此，它们都需要使用**doubly linked list**来进行实现。

