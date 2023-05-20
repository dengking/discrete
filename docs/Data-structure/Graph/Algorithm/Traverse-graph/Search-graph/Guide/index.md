# 关于本章

graph search algorithm是非常之多的，因此需要首先建立起一个完整的视图，本章主要参考如下两篇文章:

1、umn [CSci 4511w: Class Notes on Search](https://www-users.cs.umn.edu/~gini/4511/search)

2、washington [Search: Cost & Heuristics](https://courses.cs.washington.edu/courses/cse473/14au/slides/03-hsearch.pdf)

3、wikipedia graph and tree search algorithm

参见下面的"wikipedia graph and tree search algorithm"段

## Relation-based algorithm model

graph search algorithm是典型的Relation-based algorithm model（参见`Relation-structure-computation\Computation\index.md`）。



## wikipedia graph and tree search algorithm



| [Graph](https://en.wanweibaike.com/wiki-Graph_traversal) and [tree search algorithms](https://en.wanweibaike.com/wiki-Tree_traversal) |
| :----------------------------------------------------------: |
| [α–β](https://en.wanweibaike.com/wiki-Alpha–beta_pruning) [A*](https://en.wanweibaike.com/wiki-A*_search_algorithm) [B*](https://en.wanweibaike.com/wiki-B*) [Backtracking](https://en.wanweibaike.com/wiki-Backtracking) [Beam](https://en.wanweibaike.com/wiki-Beam_search) [Bellman–Ford](https://en.wanweibaike.com/wiki-Bellman%20Ford) [Best-first](https://en.wanweibaike.com/wiki-Best-first_search) [Bidirectional](https://en.wanweibaike.com/wiki-Bidirectional_search) [Borůvka](https://en.wanweibaike.com/wiki-Borůvka's_algorithm) [Branch & bound](https://en.wanweibaike.com/wiki-Branch_and_bound) [BFS](https://en.wanweibaike.com/wiki-Breadth-first_search) [British Museum](https://en.wanweibaike.com/wiki-British_Museum_algorithm) [D*](https://en.wanweibaike.com/wiki-D*) [DFS](https://en.wanweibaike.com/wiki-Depth-first_search) [Dijkstra](https://en.wanweibaike.com/wiki-Dijkstra's_algorithm) [Edmonds](https://en.wanweibaike.com/wiki-Edmonds'_algorithm) [Floyd–Warshall](https://en.wanweibaike.com/wiki-Floyd–Warshall_algorithm) [Fringe search](https://en.wanweibaike.com/wiki-Fringe_search) [Hill climbing](https://en.wanweibaike.com/wiki-Hill_climbing) [IDA*](https://en.wanweibaike.com/wiki-Iterative_deepening_A*) [Iterative deepening](https://en.wanweibaike.com/wiki-Iterative_deepening_depth-first_search) [Johnson](https://en.wanweibaike.com/wiki-Johnson's_algorithm) [Jump point](https://en.wanweibaike.com/wiki-Jump_point_search) [Kruskal](https://en.wanweibaike.com/wiki-Kruskal's_algorithm) [Lexicographic BFS](https://en.wanweibaike.com/wiki-Lexicographic_breadth-first_search) [LPA*](https://en.wanweibaike.com/wiki-Lifelong_Planning_A*) [Prim](https://en.wanweibaike.com/wiki-Prim's_algorithm) [SMA*](https://en.wanweibaike.com/wiki-SMA*) |
|                           Listings                           |
| *[Graph algorithms](https://en.wanweibaike.com/wiki/Category-Graph_algorithms)* *[Search algorithms](https://en.wanweibaike.com/wiki/Category-Search_algorithms)* *[List of graph algorithms](https://en.wanweibaike.com/wiki-List_of_algorithms#Graph_algorithms)* |
|                        Related topics                        |
| [Dynamic programming](https://en.wanweibaike.com/wiki-Dynamic_programming) [Graph traversal](https://en.wanweibaike.com/wiki-Graph_traversal) [Tree traversal](https://en.wanweibaike.com/wiki-Tree_traversal) [Search games](https://en.wanweibaike.com/wiki-Search_game) |



## Classification



分类方法是参考的：umn [CSci 4511w: Class Notes on Search](https://www-users.cs.umn.edu/~gini/4511/search) “3. classes of search algorithms.”。

### uninformed VS informed 

uninformed 即 Blind search

informed 即 Heuristic search

| 类别             | Example                                                      | 说明 |
| ---------------- | ------------------------------------------------------------ | ---- |
| Blind search     | - Depth first search (DFS) <br>- Breadth first search (BFS) <br>- Iterative deepening depth-first search (IDS) |      |
| Heuristic search | - Best first search <br/>- Uniform cost search (UCS) <br>- Greedy search <br>- `A*` <br>- Iterative Deepening `A*` (`IDA*`) <br>- Beam search <br>- Hill climbing |      |

上述example是参考的washington [Search: Cost & Heuristics](https://courses.cs.washington.edu/courses/cse473/14au/slides/03-hsearch.pdf)。

### local VS global

| 类别   | Example                      | 说明 |
| ------ | ---------------------------- | ---- |
| local  | - greedy <br>- hill-climbing |      |
| global | - uniform cost <br>- `A*`    |      |

与此相关的是：局部最优与全局最优。

### systematic VS stochastic 

| 类别       | Example                          | 说明 |
| ---------- | -------------------------------- | ---- |
| systematic | - depth-first<br>- `A*`          |      |
| stochastic | - genetic algorithms（遗传算法） |      |


