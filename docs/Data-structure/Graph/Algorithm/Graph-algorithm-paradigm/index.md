# Graph algorithm paradigm

本节的内容是为在阅读 wikipedia [Transitive closure](https://en.wikipedia.org/wiki/Transitive_closure) 中的下面这段话时想到的:

> The problem can also be solved by the [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm), or by repeated [breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search) or [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search) starting from each node of the graph.

显然  [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm) 是典型的"穷举"，BFS，DFS。又联想到 [LeetCode-743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time/) # [五种最短路径算法总结](https://leetcode.cn/problems/network-delay-time/solution/dirkdtra-by-happysnaker-vjii/) 中总结了多种解决单源最短路径的算法，其中包括  [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm)、Dijkstra(BFS)、DFS。从这些内容可以看出: 

解决graph都computation algorithm可以使用多种 algorithm，而各种graph algorithm其实是可以归入到如下paradigm的:

一、穷举

Floyd–Warshall-algorithm

二、BFS-queue machine

1、[Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm)



三、DFS-stack machine	



|                                                              |                  |                                                              | data structure   |
| ------------------------------------------------------------ | ---------------- | ------------------------------------------------------------ | ---------------- |
|                                                              |                  |                                                              |                  |
| [Prim算法](https://leetcode.cn/problems/min-cost-to-connect-all-points/solution/prim-and-kruskal-by-yexiso-c500/) | 以**顶点**为基础 | 和Dijkstra's algorithm非常类似，以greedy的方式不断地扩展，并且它也可以使用`priority_queue`来进行优化。 | `priority_queue` |
| [Kruskal](https://leetcode.cn/problems/min-cost-to-connect-all-points/solution/prim-and-kruskal-by-yexiso-c500/) | 以**边**为基础   |                                                              | union-find-set   |

Algorithm is like a machine.



四、graph dp
