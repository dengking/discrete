# Graph algorithm paradigm

素材一: 本节的内容是为在阅读 wikipedia [Transitive closure](https://en.wikipedia.org/wiki/Transitive_closure) 中的下面这段话时想到的:

> The problem can also be solved by the [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm), or by repeated [breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search) or [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search) starting from each node of the graph.

其实上面这段话总结了三种穷举graph的algorithm paradigms： [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm) 所代表的"穷举"，repeated-BFS，repeated-DFS。

素材二: 又联想到 [LeetCode-743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time/) # [五种最短路径算法总结](https://leetcode.cn/problems/network-delay-time/solution/dirkdtra-by-happysnaker-vjii/) 中总结了多种解决单源最短路径的算法，其中包括  [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm)、Dijkstra(BFS)、DFS。

总的来说: 穷举是解决所有问题的基础，对于graph的各种问题亦是如此，从目前接触的各种graph algorithm，它们大多数都是基于穷举的，所不同的是穷举的方式不同，总的来说，是可以归入到如下paradigm的:

一. node-wise-$O(N^2)$ 穷举

典型的代表是Floyd–Warshall-algorithm

这是最最简单的穷举方式

二. repeated-BFS-queue-machine

1. [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm)



三. repeated-DFS-stack-machine	



|                                                              |                  |                                                              | data structure   |
| ------------------------------------------------------------ | ---------------- | ------------------------------------------------------------ | ---------------- |
|                                                              |                  |                                                              |                  |
| [Prim算法](https://leetcode.cn/problems/min-cost-to-connect-all-points/solution/prim-and-kruskal-by-yexiso-c500/) | 以**顶点**为基础 | 和Dijkstra's algorithm非常类似，以greedy的方式不断地扩展，并且它也可以使用`priority_queue`来进行优化。 | `priority_queue` |
| [Kruskal](https://leetcode.cn/problems/min-cost-to-connect-all-points/solution/prim-and-kruskal-by-yexiso-c500/) | 以**边**为基础   |                                                              | union-find-set   |

Algorithm is like a machine.



四、graph dp
