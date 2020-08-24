# 关于本章

graph search algorithm是非常之多的，因此需要首先建立起一个完整的视图，本章主要参考如下两篇文章:

- umn [CSci 4511w: Class Notes on Search](https://www-users.cs.umn.edu/~gini/4511/search)
- washington [Search: Cost & Heuristics](https://courses.cs.washington.edu/courses/cse473/14au/slides/03-hsearch.pdf)

graph search algorithm是典型的Relation-based algorithm model（参见`Relation-structure-computation\Computation\index.md`）。

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



