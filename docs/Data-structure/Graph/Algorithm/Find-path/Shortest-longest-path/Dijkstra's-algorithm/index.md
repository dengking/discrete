# Dijkstra's algorithm

---

> References: 
>
> - wikipedia [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) 
>
> - labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 
>
> - [stackoverflow-Negative weights using Dijkstra's Algorithm](https://stackoverflow.com/questions/6799172/negative-weights-using-dijkstras-algorithm) # [A](https://stackoverflow.com/a/55596739) 
>
> - [zhihu-Dijkstra's 最短路径算法能不能解这个含有负权重的问题？](https://www.zhihu.com/question/21620069/answer/24518138) 

---

## wikipedia [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) 

> NOTE:
>
> 一、这篇文章的是存在一个问题的: 它没有描述清楚 Dijkstra's algorithm 的各种variant，并且它没有说明它到底使用的哪种。如果不交代这个前提，那么讨论 Dijkstra's algorithm 的 negative weight edge 是没有意义的，因为有的版本是支持negative weight edge，有的是不支持的。并且 "Algorithm" 节中描述的算法 和 "Pseudocode" 节的是对不上的: "Algorithm"中描述的算法使用的是 "NO re-entrance allowed"( 通过visited set实现的 )，通过 [Dijkstra's 最短路径算法能不能解这个含有负权重的问题？ - Quokka的回答 - 知乎](https://www.zhihu.com/question/21620069/answer/24518138) 中的内容可知，原始版本的不支持negative weight的Dijkstra's algorithm: 
>
> 1、NO re-entrance allowed( 通过visited set实现的 )，因此，
>
> 2、source to target
>
> 原始版本的不支持negative weight的Dijkstra's algorithm，由于明确不支持negative weight，所以它在首次到达target node后就可以终止算法(如果需要支持negative weight，则需要 re-entrance allowed+计算出source to all nodes的距离，结合 [stackoverflow-Negative weights using Dijkstra's Algorithm](https://stackoverflow.com/questions/6799172/negative-weights-using-dijkstras-algorithm) # [A](https://stackoverflow.com/a/55596739) 中的例子来理解这段话)
>
> 对于没有 negative weight 的graph，使用 原始版本的Dijkstra's algorithm "NO re-entrance allowed"( 通过visited set实现的 ) 的性能是最优的。
>
> 其它的各种variant都是基于"原始版本的不支持negative weight的Dijkstra's algorithm"。

The algorithm exists in many variants. Dijkstra's original algorithm found the shortest path between two given nodes,[[5\]](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#cite_note-Dijkstra1959-5) but a more common variant fixes a single node as the "source" node and finds shortest paths from the source to all other nodes in the graph, producing a [shortest-path tree](https://en.wikipedia.org/wiki/Shortest-path_tree).

> NOTE: 
>
> 一、single source
>
> 二、从后面的`Pseudocode`可知，dijkstra的implementation中，会将 [shortest-path tree](https://en.wikipedia.org/wiki/Shortest-path_tree) 存放到`prev` array中

The algorithm exists in many variants. Dijkstra's original algorithm found the shortest path between two given nodes,[[6\]](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#cite_note-Dijkstra1959-6) but a more common variant fixes a single node as the "source" node and finds shortest paths from the source to all other nodes in the graph, producing a [shortest-path tree](https://en.wikipedia.org/wiki/Shortest-path_tree).

> NOTE:
>
> 一、后面会介绍Dijkstra's algorithm的各种variants

### Generic Dijkstra shortest-path algorithm

The **Dijkstra algorithm** uses labels that are positive integers or real numbers, which are [totally ordered](https://en.wikipedia.org/wiki/Total_order). It can be generalized to use any labels that are [partially ordered](https://en.wikipedia.org/wiki/Partially_ordered_set), provided the subsequent labels (a subsequent label is produced when traversing an edge) are [monotonically](https://en.wikipedia.org/wiki/Monotonic_function) non-decreasing. This generalization is called the **generic Dijkstra shortest-path algorithm**.[[7\]](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#cite_note-Generic_Dijkstra-7)

> NOTE: 
>
> 一、generic Dijkstra shortest-path algorithm
>
> 上面这段话所介绍的generic Dijkstra shortest-path algorithm，它强调的是 "labels that are [partially ordered](https://en.wikipedia.org/wiki/Partially_ordered_set)"，如果从graph的角度来说，它所蕴含的是weighted directed graph的weight是 [partially ordered](https://en.wikipedia.org/wiki/Partially_ordered_set) 的。



This is [asymptotically](https://en.wanweibaike.com/wiki-Asymptotic_computational_complexity) the fastest known single-source [shortest-path algorithm](https://en.wanweibaike.com/wiki-Shortest_path_problem) for arbitrary [directed graphs](https://en.wanweibaike.com/wiki-Directed_graph) with unbounded non-negative weights. 

> NOTE: 
>
> 一、为什么dijkstra 算法是不允许负数边的？这在前面进行了讨论。

In some fields, [artificial intelligence](https://en.wanweibaike.com/wiki-Artificial_intelligence) in particular, Dijkstra's algorithm or a variant of it is known as **uniform cost search** and formulated as an instance of the more general idea of [best-first search](https://en.wanweibaike.com/wiki-Best-first_search).

### Algorithm

> NOTE:
>
> 一、原始版本的Dijkstra's algorithm "NO re-entrance allowed"( 通过visited set实现的 )，因此不支持negative weight；后面的 "Pseudocode" 章节描述的和本节的不匹配。 

### Pseudocode



[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e4/DijkstraDemo.gif/220px-DijkstraDemo.gif)](https://en.wikipedia.org/wiki/File:DijkstraDemo.gif)

A demo of **Dijkstra's algorithm** based on **Euclidean distance**.

1、Red lines are the shortest path covering, i.e., connecting `u` and `prev[u]`. 

2、Blue lines indicate where relaxing happens, i.e., connecting *v* with a node *u* in *Q*, which gives a shorter path from the source to *v*.



#### Not using a priority queue

```pseudocode
 1  function Dijkstra(Graph, source):
 2
 3      create vertex set Q
 4
 5      for each vertex v in Graph:            
 6          dist[v] ← INFINITY                 
 7          prev[v] ← UNDEFINED                
 8          add v to Q                     
 9      dist[source] ← 0                       
10     
11      while Q is not empty:
12          u ← vertex in Q with min dist[u]   
13                                             
14          remove u from Q
15         
16          for each neighbor v of u:           // only v that are still in Q
17              alt ← dist[u] + length(u, v)
18              if alt < dist[v]:              
19                  dist[v] ← alt
20                  prev[v] ← u
21
22      return dist[], prev[]
```

> NOTE: 
>
> 一、上述伪代码的initialization:
>
> ```pseudocode
>  5      for each vertex v in Graph:            
>  6          dist[v] ← INFINITY                 
>  7          prev[v] ← UNDEFINED                
>  8          add v to Q                     
>  9      dist[source] ← 0  
> ```
>
> 
>
> ```pseudocode
> 11      while Q is not empty:
> 12          u ← vertex in Q with min dist[u]   
> 13                                             
> 14          remove u from Q
> ```
>
> 显然，`while`的第一次取到的`source`
>
> 它和 `计算机算法设计与分析-4-5-单源最短路径` 中的实现方式是有差异的。

##### Reconstruct Shortest path

> NOTE:
>
> 一、这一节讲述的是构造从source到target的shortest path的算法，它分了两种情况来进行讨论: 
>
> 1、find a shortest path between vertices ***source*** and ***target*** 
>
> 2、find all the shortest paths between ***source*** and ***target*** (there might be several different ones of the same length) 
>
> a、记录
>
> b、reconstruct
>
> 使用一个stack

Case 1: a shortest path between vertices ***source*** and ***target*** 

If we are only interested in a **shortest path** between vertices ***source*** and ***target***, we can terminate the search after line 15 if `u = target`. 

Now we can read the **shortest path** from ***source*** to ***target*** by reverse iteration:

```pseudocode
1  S ← empty sequence
2  u ← target
3  if prev[u] is defined or u = source:          // Do something only if the vertex is reachable
4      while u is defined:                       // Construct the shortest path with a stack S
5          insert u at the beginning of S        // Push the vertex onto the stack
6          u ← prev[u]                           // Traverse from target to source
```

Now sequence `S` is the list of vertices constituting one of the shortest paths from source to target, or the empty sequence if no path exists.

> NOTE:
>
> 一、上述pseudocode中的 `S` 是一个stack

Case 2: [shortest-path tree](https://en.wikipedia.org/wiki/Shortest-path_tree): 从source到所有的node的 shortest path 

A more general problem would be to find all the shortest paths between ***source*** and ***target*** (there might be several different ones of the same length). Then instead of storing only a single node in each entry of `prev[]`, we would store all nodes satisfying the **relaxation condition**. For example, if both `r` and `source` connect to `target` and both of them lie on different **shortest paths** through `target` (because the edge cost is the same in both cases), then we would add both `r` and `source` to `prev[target]`. When the algorithm completes, `prev[]` data structure will actually describe a graph that is a subset of the original graph with some edges removed. Its key property will be that if the algorithm was run with some **starting node**, then every path from that node to any other node in the new graph will be the **shortest path** between those nodes in the original graph, and all paths of that length from the original graph will be present in the new graph. Then to actually find all these shortest paths between two given nodes we would use a path finding algorithm on the new graph, such as [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search).

> NOTE:
>
> 一、在后面的python implementation中的shortest path graph展示了上述思路的实现



#### Using a priority queue

```C++
1  function Dijkstra(Graph, source):
2      dist[source] ← 0                           // Initialization
3
4      create vertex priority queue Q
5
6      for each vertex v in Graph:          
7          if v ≠ source
8              dist[v] ← INFINITY                 // Unknown distance from source to v
9              prev[v] ← UNDEFINED                // Predecessor of v
10
11         Q.add_with_priority(v, dist[v])
12
13
14     while Q is not empty:                      // The main loop
15         u ← Q.extract_min()                    // Remove and return best vertex
16         for each neighbor v of u:              // only v that are still in Q
17             alt ← dist[u] + length(u, v)
18             if alt < dist[v]
19                 dist[v] ← alt
20                 prev[v] ← u
21                 Q.decrease_priority(v, alt)    // 由于node已经存在于 Q 中了，因此此处仅仅是更新，而不是插入
22
23     return dist, prev
```

> NOTE: 
>
> 一、
>
> 通过对比可知，`priority queue`的优势在于`u ← Q.extract_min()` 



### Practical optimizations and infinite graphs

> NOTE:
>
> 一、本节所描述的其实是 Dijkstra's algorithm 的一种 variant 

[![img](https://upload.wikimedia.org/wikipedia/commons/2/23/Dijkstras_progress_animation.gif)](https://en.wikipedia.org/wiki/File:Dijkstras_progress_animation.gif)

Illustration of **Dijkstra's algorithm** finding a path from a **start node** (lower left, red) to a **goal node** (upper right, green) in a [robot](https://en.wikipedia.org/wiki/Robotics) [motion planning](https://en.wikipedia.org/wiki/Motion_planning) problem. Open nodes represent the "tentative" set (aka set of "unvisited" nodes). Filled nodes are the visited ones, with color representing the distance: the greener, the closer. Nodes in all the different directions are explored uniformly, appearing more-or-less as a circular [wavefront](https://en.wikipedia.org/wiki/Wavefront) as Dijkstra's algorithm uses a [heuristic](https://en.wikipedia.org/wiki/Consistent_heuristic) identically equal to 0.



> NOTE:
>
> 一、GPT:
>
> > Uniform-cost search is a variant of Dijkstra's algorithm that is used when all actions have a cost and you want to find the least-cost path to the goal. It expands the node with the lowest path cost, and it is guaranteed to find the least-cost path to the goal as long as the cost of each step is positive.
>
> uniform-cost-search是将Dijkstra's algorithm修改后用于infinite graph，由于它是基于Dijkstra's algorithm，所以它也是不支持negative weighted edge的
>
> 二、在后面展示了完整的代码
>
> 从pseudocode可以看出，它使用了visited set，那它为什么需要呢？
>
> 从pseudocode可以看出，它没有使用edge relaxation，那它为什么需要呢？
>
> 下面是GPT: why uniform cost search do not use relaxation？的回答:
>
> > Uniform-cost search does not explicitly use the concept of relaxation as seen in Dijkstra's algorithm because it operates under a different principle. Relaxation in Dijkstra's algorithm is the process of updating the shortest known distance to a vertex when a shorter path is found. This is done by "relaxing" the edges, checking if the known distance to a vertex can be improved by taking a newly discovered path.
> >
> > In contrast, uniform-cost search is a more general search algorithm that does not assume the graph is weighted or directed. It is a form of best-first search that uses a priority queue to explore nodes in order of their path cost from the start node, expanding the least-cost unexplored node at each step.
> >
> > Here's why relaxation is not explicitly used in uniform-cost search:
> >
> > 1. **Priority Queue**: Uniform-cost search uses a priority queue to manage the frontier of nodes to be explored. The priority queue automatically ensures that the node with the lowest cumulative cost is chosen for expansion. This implicitly takes care of the need to find the shortest path without the need for a separate relaxation step.
> > 2. **Exploration Order**: Since uniform-cost search always expands the node with the lowest path cost first, it naturally follows the shortest path to each node without needing to update distances. If a shorter path to a node is found, that node will be expanded before any longer paths due to the nature of the priority queue.
> > 3. **Goal Test**: Uniform-cost search can stop as soon as it reaches the goal node because it is guaranteed that this is the lowest-cost path to the goal. There is no need to continue searching to find a potentially shorter path, as would be the case with relaxation in Dijkstra's algorithm.
> > 4. **General Applicability**: Uniform-cost search is a more general algorithm that can be applied to any search problem, not just pathfinding in weighted graphs. It does not rely on the structure of a graph or the presence of edge weights, so the concept of relaxation is not applicable.
> >
> > In summary, uniform-cost search inherently ensures that the shortest path is found by the order in which nodes are expanded, without the need for a separate relaxation process. The use of a priority queue to manage the frontier is key to this behavior.
>
> 三、**Uniform-cost search** VS **Dijkstra's algorithm**
>
> 两者都是用来priority queue来进行greed selection，不同的是: 
>
> **Dijkstra's algorithm**  使用的是edge relaxation
>
> **Uniform-cost search** 使用的是closed set(最优质已经确定)，因为总是greedy选择最优的，因此从priority queue中pop出来的总是最优的，因此可以将它们放到
>
> 从下面的case来看，两者都能够找到最优值:
>
> ```python
>         graph = {
>             'A': {'B': 1, 'C': 3},
>             'B': {'C': 1},
>             'C': {},
>         }
>         
>         start = 'A'
>         end = 'C'
> ```
>
> 

In common presentations of **Dijkstra's algorithm**, initially all nodes are entered into the priority queue. This is, however, not necessary: the algorithm can start with a priority queue that contains only one item, and insert new items as they are discovered (instead of doing a decrease-key, check whether the key is in the queue; if it is, decrease its key, otherwise insert it).[[7\]](https://en.wanweibaike.com/wiki-Dijkstra's Algorithm#cite_note-mehlhorn-7):198 This variant has the same worst-case bounds as the common variant, but maintains a smaller priority queue in practice, speeding up the queue operations.

Moreover, not inserting all nodes in a graph makes it possible to extend the algorithm to find the shortest path from a single source to the closest of a set of target nodes on infinite graphs or those too large to represent in memory. The resulting algorithm is called *uniform-cost search* (UCS) in the artificial intelligence literature[[9\]](https://en.wanweibaike.com/wiki-Dijkstra's Algorithm#cite_note-felner-9)[[17\]](https://en.wanweibaike.com/wiki-Dijkstra's Algorithm#cite_note-aima-17)[[18\]](https://en.wanweibaike.com/wiki-Dijkstra's Algorithm#cite_note-18) and can be expressed in pseudocode as

```pseudocode
procedure uniform_cost_search(start) is
    node ← start
    frontier ← priority queue containing node only
    expanded ← empty set
    do
        if frontier is empty then
            return failure
        node ← frontier.pop()
        if node is a goal state then
            return solution(node)
        expanded.add(node)
        for each of node's neighbors n do
            if n is not in expanded and not in frontier then
                frontier.add(n)
            else if n is in frontier with higher cost
                replace existing node with n
```



### Related problems and algorithms

Unlike Dijkstra's algorithm, the [Bellman–Ford algorithm](https://en.wanweibaike.com/wiki-Bellman–Ford_algorithm) can be used on graphs with negative edge weights, as long as the graph contains no [negative cycle](https://en.wanweibaike.com/wiki-Negative_cycle) reachable from the source vertex *s*. The presence of such cycles means there is no shortest path, since the total weight becomes lower each time the cycle is traversed. (This statement assumes that a "path" is allowed to repeat vertices. In [graph theory](https://en.wanweibaike.com/wiki-Graph_theory) that is normally not allowed. In [theoretical computer science](https://en.wanweibaike.com/wiki-Theoretical_computer_science) it often is allowed.) It is possible to adapt Dijkstra's algorithm to handle negative weight edges by combining it with the Bellman-Ford algorithm (to remove negative edges and detect negative cycles), such an algorithm is called [Johnson's algorithm](https://en.wanweibaike.com/wiki-Johnson's_algorithm).

> NOTE:
>
> 一、通过"Variants of Dijkstra's Algorithmz"章节的内容可知，除了 [Johnson's algorithm](https://en.wanweibaike.com/wiki-Johnson's_algorithm) ，还有其它的 variant 可以支持negative weight graph。



## Variants of Dijkstra's Algorithm



---

> References:
>
> - [stackoverflow-Negative weights using Dijkstra's Algorithm](https://stackoverflow.com/questions/6799172/negative-weights-using-dijkstras-algorithm) # [A](https://stackoverflow.com/a/55596739) 
>
> - [zhihu-Dijkstra's 最短路径算法能不能解这个含有负权重的问题？](https://www.zhihu.com/question/21620069/answer/24518138) 
> - [algs4.cs.princeton-4.4  Shortest Paths](https://algs4.cs.princeton.edu/44sp/) 
> - [zhihu-如何看待 SPFA 算法已死这种说法？](https://www.zhihu.com/question/292283275/answer/484871888) 

---



---

> 说明: 
>
> 1、本节的内容是我在思考Dijkstra's Algorithm是否支持negative edge这个问题时，通过 Google 发现了 "References" 中所链接的非常有价值的内容，它们不仅拓展而去加深了我对Dijkstra's Algorithm的认知，让我认识到Dijkstra's Algorithm有着多种variants，这些variants能够处理不同类型的graph，总的来说: 需要根据graph的类型灵活的选择合适的implementation。本节主要以graph是否包含**negative edge**来描述**标准版本的Dijkstra's Algorithm**以及它的一些variant。
>
> 2、 由于明确主流的programming language已经支持了priority queue，所以后续都不再描述Dijkstra最初的实现中的nested-for版本了，而是全部使用priority queue。 
>
> 3、通过对比各种variant，能够更好地掌握这些算法

---



[stackoverflow-Negative weights using Dijkstra's Algorithm](https://stackoverflow.com/questions/6799172/negative-weights-using-dijkstras-algorithm) # [A](https://stackoverflow.com/a/55596739) 

> **There are 3 kinds of implementation of Dijkstra's algorithm**: 
>
> 1、Using a **nested `for`-loop** to relax vertices. This is the easiest way to implement Dijkstra's algorithm. The time complexity is O(V^2).
>
> 2、Priority-queue/heap based implementation + NO re-entrance allowed, where **re-entrance means a relaxed vertex can be pushed into the priority-queue again to be relaxed again later**.
>
> 3、Priority-queue/heap based implementation + re-entrance allowed.

[Dijkstra's 最短路径算法能不能解这个含有负权重的问题？ - Quokka的回答 - 知乎](https://www.zhihu.com/question/21620069/answer/24518138)

> 对于有负权边但无[负权回路](https://www.zhihu.com/search?q=负权回路&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A24518138})的图：
>
> 1、如果是标准的O(V^2)的Dijkstra，那是算不出的（除非碰巧算对）。
>
> 2、如果是优先队列优化（或者说堆优化）的版本，也不行（除非碰巧算对）。
>
> 3、如果是优先队列优化**+允许重入队**（详细解释见下文），那么可以（是真的可以计算出来，不是碰巧）。但这实际上已经是priority queue-based Bellman-Ford了，是 [Bellman-Ford算法](https://www.zhihu.com/search?q=Bellman-Ford算法&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A24518138}) 的变种。国内 ACMer 也把这个算法叫做使用优先队列的 [SPFA](https://en.wikipedia.org/wiki/Shortest_path_faster_algorithm) 算法，国外似乎习惯把这个算法仍旧叫做堆优化的Dijkstra，或者 generalized Dijkstra，看作Dijkstra的变种，可能是习惯不一样吧。不过此时已经说不清这到底是Dijkstra还是Bellman-Ford算法了……但是需要注意的是，该算法的运行时间可能为指数！！
>
> > NOTE:
> >
> > 一、SPFA算法指的是 [Shortest path faster algorithm](https://en.wikipedia.org/wiki/Shortest_path_faster_algorithm) ，需要注意的是，原始的 [SPFA](https://en.wikipedia.org/wiki/Shortest_path_faster_algorithm) 算法没有使用priority queue。
>
> 可以参考[Shortest Paths](https://link.zhihu.com/?target=http%3A//algs4.cs.princeton.edu/44sp/)，其中有这么一段话：
>
> > **Q.** Does Dijkstra's algorithm work with negative weights?
> > **A.** Yes and no. There are two shortest paths algorithms known as *Dijkstra's algorithm*, depending on whether a vertex can be enqueued on the priority queue more than once. When the weights are nonnegative, the two versions coincide (as no vertex will be enqueued more than once). The version implemented in [DijkstraSP.java](https://link.zhihu.com/?target=http%3A//algs4.cs.princeton.edu/44sp/DijkstraSP.java.html) (which allows a vertex to be enqueued more than once) is correct in the presence of negative edge weights (but no negative cycles) but its running time is exponential in the worst case. (We note that [DijkstraSP.java](https://link.zhihu.com/?target=http%3A//algs4.cs.princeton.edu/44sp/DijkstraSP.java.html) throws an exception if the edge-weighted digraph has an edge with a negative weight, so that a programmer is not surprised by this exponential behavior.) If we modify [DijkstraSP.java](https://link.zhihu.com/?target=http%3A//algs4.cs.princeton.edu/44sp/DijkstraSP.java.html) so that a vertex cannot be enqueued more than once (e.g., using a `marked[]` array to mark those vertices that have been relaxed), then the algorithm is guaranteed to run in *E* log *V* time but it may yield incorrect results when there are edges with negative weights.
>
> > NOTE:
> >
> > 一、需要注意: 上面这段话其实是有误导的，通过"Graph with non-negative weight edge"中的内容可知，对于有多条path到达的node，它是可能多次进入priority queue的，不过是可以将它标记为状态的，这样可以避免再次对它进行expand。
>
> 作者：Quokka
> 链接：https://www.zhihu.com/question/21620069/answer/24518138
> 来源：知乎
> 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
>
> 
>
> 算法 3 的时间复杂度不好分析，算法的运行时间依赖于输入数据的分布。**在非[负权图](https://www.zhihu.com/search?q=负权图&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A24518138})的情况下，此算法与算法 2 行为完全相同，时间复杂度为O（(V+E)lg V）；而对于有负权边但无负权回路的图，算法的最坏运行时间是顶点数目的指数**（详见 [https://courses.engr.illinois.edu/cs498374/fa2014/notes/26-sssp.pdf](https://link.zhihu.com/?target=https%3A//courses.engr.illinois.edu/cs498374/fa2014/notes/26-sssp.pdf)，课后练习第 7 题）。不过在随机图上实际运行起来往往比较快。
>
> 这个算法实在太奇葩了，它既不是Dij，也不是BF；既是Dij的变种，又是BF的变种，是一个混合产物。由于这个算法的运行时间不稳定，有时在[算法竞赛](https://www.zhihu.com/search?q=算法竞赛&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A24518138})中可以构造出来一些图卡这个算法让它退化，之后在国内spfa就有了一些魔改版（尤其是在09年集训队[姜碧野](https://www.zhihu.com/search?q=姜碧野&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A24518138})的论文之后），乱改松弛/入队/出队等的顺序或者把优先队列换成栈等其他数据结构，彻底乱成了一锅粥。这些变种算法实践中通常都是有效的，然而其最坏时间复杂度，甚至是算法的正确性都难以得到保证，也许在极端情形下会出错或者变得特别慢，我个人的建议是不要趟这些浑水。
>
> 当然，**原始的 SPFA（就是使用普通 FIFO 的队列那种）算法正确性是可以保证的，并且最差时间复杂度和 Bellman-Ford 相同，为 O(VE)。**事实上，此时 SPFA 正是 Moore 1957 年提出的[最短路算法](https://www.zhihu.com/search?q=最短路算法&search_source=Entity&hybrid_search_source=Entity&hybrid_search_extra={"sourceType"%3A"answer"%2C"sourceId"%3A24518138})，应该叫 Queue-based Bellman-Ford 或者 **Bellman-Ford-Moore 算法。该算法和 Bellman-Ford 算法的有效操作是完全等价的**：BF 算法每一轮会遍历所有边，但可能很多边都无法进行松弛，遍历这些边是没有意义的；BFM 的每一轮计算则是采用队列的方式，只扫描该轮中有可能被松弛的边，因此减少了很多无效操作，运行起来更快。BFM 算法的正确性和复杂度证明同样见上述 Illinois 的算法讲义。
>
> 下面这个回答里说的很清楚，**SPFA 的各种优化本质上就是让队列更接近优先队列。**但是考虑到队列版的 SPFA （或者说 BFM 算法）稳定地优于 Bellman-Ford，而优先队列版的 SPFA 在正权图上可以达到堆优化 Dijkstra 的性能，带负权边的图上却可能退化到指数级；所以只要参考优先队列版 SPFA （其实应该叫 priority-queue based Bellman-Ford）的卡法，就能相应地卡 SPFA 的各种魔改版。



### Graph with non-negative weight edge 

对于没有 negative weight edge 的graph，显然经过的edge越多，则distance越大，即它是单调递增的，Dijkstra's algorithm 是 greedy algorithm，每次从priority queue中选择出来的node满足如下条件:

1、它每次从priority queue中选择最短的edge进行expand

2、经过的path数量是最少的

显然，上述两个条件都保证了每次从priority queue中选择出来的node，从source到它的距离都是最近的，因此可以**断言**它就是**终态的node**；由于可能有多种路径到达一个node，因此可能重复visit到一个终态的node，如果已经确定它是终态的，那么可以直接将它给pass掉不再对它进行expand，这就是前面提到的的"NO re-entrance"的含义。显然这是一个很好的优化，那如何来实现呢？

**关键字**: 终态node、NO re-entrance



#### NO re-entrance的实现

有如下两种方式:

1、visited set；

将**终态的node**放到**visited set**中，这样再次碰到的时候就可以将它pass掉。

2、不使用visited set，而是通过距离来进行判断，当从priority queue中pop出来的node，如果发现到它的距离比之前的距离更大，显然这就是一个**终态的node** ，可以将它pass掉。

在 labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 、chatGPT给出的实现中使用的是这种写法的。



#### 原始版本的Dijkstra's Algorithm Code

```python
import heapq
from typing import List, Dict
import unittest


def dijkstra_with_visited_set(graph: Dict[str, Dict[str, int]], start: str):
    # Initialize distances from start to all other nodes as infinity
    distances = {node: float('infinity') for node in graph}
    # Set distance to the start node to zero
    distances[start] = 0

    # Priority queue to hold nodes to visit
    priority_queue = [(0, start)]

    # Set to keep track of visited nodes
    visited = set()

    while priority_queue:
        # Select the node with the smallest distance
        current_distance, current_node = heapq.heappop(priority_queue)

        # If this node has been visited, skip it
        if current_node in visited:
            continue

        # Mark the node as visited
        visited.add(current_node)

        # Check all the neighbors of the current node
        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight

            # If the distance to the neighbor is less through this node...
            if distance < distances[neighbor]:
                # Update the distance
                distances[neighbor] = distance
                # Add the neighbor to the priority queue for consideration
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances


def dijkstra_without_visited_set(graph: Dict[str, Dict[str, int]], start: str):
    # Initialize distances from start to all other nodes as infinity
    distances = {node: float('infinity') for node in graph}
    # Set distance to the start node to zero
    distances[start] = 0

    # Priority queue to hold nodes to visit
    priority_queue = [(0, start)]

    while priority_queue:
        # Select the node with the smallest distance
        current_distance, current_node = heapq.heappop(priority_queue)

        # If this node has been visited, skip it
        if current_distance > distances[current_node]:
            continue

        # Check all the neighbors of the current node
        for neighbor, weight in graph[current_node].items():
            distance = current_distance + weight

            # If the distance to the neighbor is less through this node...
            if distance < distances[neighbor]:
                # Update the distance
                distances[neighbor] = distance
                # Add the neighbor to the priority queue for consideration
                heapq.heappush(priority_queue, (distance, neighbor))

    return distances


class TestDijkstraAlgorithm(unittest.TestCase):

    def test_case_0(self):
        # Example usage:
        graph = {
            'A': {'B': 1, 'C': 3},
            'B': {'C': 1},
            'C': {},
        }
        start_node = 'A'
        end_node = 'C'
        shortest_paths_1 = dijkstra_with_visited_set(graph, start_node)
        shortest_paths_2 = dijkstra_without_visited_set(graph, start_node)
        print(shortest_paths_1[end_node], shortest_paths_2[end_node])
        self.assertEqual(shortest_paths_1[end_node], shortest_paths_2[end_node])
        self.assertEqual(shortest_paths_1[end_node], 2)


if __name__ == '__main__':
    unittest.main()

```



### Graph with negative weight edge 

Q: 为什么原始版本的Dijkstra's algorithm不支持negative weight？

A: 由于存在negative weight edge，则不再满足前面的edge越少，则distance越小的条件，因为增加负数边可能相反导致总距离减少，所以无法保证单调递增的，所以无法使用greedy algorithm，无法提早将一些node标记为终态，此时需要需要尝试所有的node才能够最终得到最优值。

> 补充:
>
> chatGPT: why dijkstra algorithm not allow negative edge？
>
> Dijkstra's algorithm does not allow negative edge weights because it relies on the assumption that once a node has been visited (i.e., the shortest path to that node has been found), its shortest path will not change. This assumption is based on the fact that adding more edges to a path will only increase the total path cost when all edge weights are non-negative.
>
> Here's a breakdown(分解) of why negative edge weights cause problems for Dijkstra's algorithm:
>
> 1. **Greedy Approach**: Dijkstra's algorithm is a greedy algorithm that makes the locally optimal choice at each step. It assumes that the shortest path to a node is finalized as soon as that node is added to the set of visited nodes. This is because, with non-negative edge weights, any extension of a path would only make it longer.
> 2. **Priority Queue**: The algorithm uses a priority queue (or a min-heap) to select the next node with the smallest tentative distance. If a node is revisited with a shorter path due to a negative edge, the priority queue may not correctly reflect the updated shortest paths, leading to incorrect results.
> 3. **Incorrect Shortest Path**: If negative edge weights are present, a path that has already been determined to be the shortest could be further shortened by taking a detour through a negative edge, violating the algorithm's assumption. Dijkstra's algorithm does not revisit nodes to check if their shortest path has been updated, which means it can miss shorter paths created by negative edges.
> 4. **Negative Cycles**: If a graph contains a negative cycle (a cycle whose edges sum to a negative value), the shortest path is undefined because you could repeatedly traverse the negative cycle and reduce the path length indefinitely. Dijkstra's algorithm does not have a mechanism to detect negative cycles.
>
> To handle graphs with negative edge weights, algorithms like Bellman-Ford or Johnson's algorithm (which uses Bellman-Ford as a preprocessing step) should be used. These algorithms are designed to accommodate negative edge weights and can detect **negative cycles**.
>



Algorithms:

1、[Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 

这是最最基础的算法 

### Graph with negative-weight-cycle 





## 概括

一、dijkstra algorithm=BFS+greedy-algorithm贪心算法+dynamic-programming动态规划: 

1、对上面这段话的解释: 每次选择距离source最短的node(greedy-algorithm贪心算法)进行expand(BFS)、对 expand得到的node进行edge relaxation approximation。

这段话比较抽象，结合一个具体的例子来理解最好:

```python
        graph = {
            'A': {'B': 1, 'C': 3},
            'B': {'C': 1},
            'C': {},
        }
        
        start = 'A'
        end = 'C'
```

这个例子虽小，但是体现Dijkstra's algorithm的精妙所在，使用这个例子来模拟算法，我有了如下感悟:

a、到达一个node的path有多条，Dijkstra's algorithm会尝试各条，edge relaxation保证了选择当前最优秀的进入到priority queue替换之前的(一个node可能会被多次relaxation)，同时阻挡来后续的劣质的 

2、wikipedia [Dijkstra's algorithm # Pseudocode](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#Pseudocode) 一次性将所有等node都加入到queue中，labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 中是动态加入。如果 queue不支持 `decrease_priority` 接口，那么就无法按照 wikipedia [Dijkstra's algorithm # Pseudocode](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#Pseudocode) 中的写法写。



3、使用 priority queue/heap 按照distance对node进行排序，在具体实现上，需要将distance/weight和node一起放到`priority_queue`中，不能够只放node或者只放distance/weight，因为这样是会导致无法对node进行排序、无法取出node等。wikipedia [Dijkstra's algorithm # Pseudocode](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#Pseudocode) 中是通过如下方式实现的:

```Java
Q.add_with_priority(source, dist[source])
Q.decrease_priority(v, alt)
```

在labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 中是通过如下方式实现的:

```Java
class State {
    // 图节点的 id
    int id;
    // 从 start 节点到当前节点的距离
    int distFromStart;

    State(int id, int distFromStart) {
        this.id = id;
        this.distFromStart = distFromStart;
    }
}
```



四、generic Dijkstra shortest-path algorithm



五、construct shortest path tree、shortest path graph

1、将 [shortest-path tree](https://en.wikipedia.org/wiki/Shortest-path_tree)、shortest path graph 存放到`prev` array中

2、stop condition: source node没有predecessor



## Implementation



### Python

#### DijkstraAlgorithmInFiniteGraph

```C++
import heapq
import unittest
from typing import Dict, List


class DijkstraAlgorithmInFiniteGraphTrackingShortestPathGraph:
    """
    有限图的Dijkstra's algorithm，它分为:
    1、计算从 source 到所有 node   的最短路径的长度
    2、计算从 source 到    target 的最短路径的长度
    """

    def __init__(self, graph_in_adj_list: Dict[str, Dict[str, int]]):
        self.graph_in_adj_list = graph_in_adj_list

    def shortest_path_to_all_nodes(self, source: str, track_shortest_path_graph=True):
        """
        1、计算从 source 到所有 node 的距离
        2、注意: 由于self.graph_in_adj_list的key可能不包括所有的node，因此对于使用self.graph_in_adj_list的key构建的dict，
        为了避免KeyError，使用Dict.get(key, default value)
        :param source:
        :param track_shortest_path_graph: 是否记录最短路径
        :return:
        """
        distances = {node: float('inf') for node in
                     self.graph_in_adj_list}  # 从start到各个node的距离，这里使用的是dict comprehension语法
        distances[source] = 0
        shortest_path_graph: Dict[str, List[str]] = {vertex: [] for vertex in self.graph_in_adj_list}

        q = [(0, source)]  # https://docs.python.org/3/library/heapq.html
        while q:
            current_distance, current_node = heapq.heappop(q)
            # 下面的这个判定其实是可以去除的，在 https://leetcode.cn/problems/network-delay-time/ 中
            if current_distance > distances[current_node]:
                continue

            for adj_node, new_distance in self.graph_in_adj_list.get(current_node, {}).items():
                new_distance = current_distance + new_distance
                if new_distance < distances.get(adj_node, float('inf')):
                    distances[adj_node] = new_distance
                    heapq.heappush(q, (new_distance, adj_node))
                    if track_shortest_path_graph:
                        shortest_path_graph[adj_node] = [current_node]
                elif new_distance == distances[adj_node]:
                    if track_shortest_path_graph:
                        shortest_path_graph[adj_node].append(current_node)

        return distances, shortest_path_graph if track_shortest_path_graph else distances

    def reconstruct_all_path(self, shortest_path_graph: Dict[str, List[str]], target: str) -> List[List[str]]:
        """
        构建从source到target的所有的path
        :return:
        """
        all_paths: List[List[str]] = []
        # 注意: 要将target首先放到path中，因为shortest_path_graph只保存了target的predecessors
        self.__dfs_reconstruct_all_path__(all_paths, shortest_path_graph, target, [target])
        return all_paths

    @classmethod
    def __dfs_reconstruct_all_path__(cls, all_paths: List[List[str]], shortest_path_graph: Dict[str, List[str]], node,
                                     path: List):
        # Stop condition: if we reached the start of the path, add the current path to the list
        # Stop condition: source node，source node是没有predecessor的
        if not shortest_path_graph[node]:
            all_paths.append(path[::-1])  # Reverse the path
            return
        for predecessor in shortest_path_graph.get(node, []):
            cls.__dfs_reconstruct_all_path__(all_paths, shortest_path_graph, predecessor, path + [predecessor])

    def shortest_path_to_single_node(self, source: str, target: str, track_shortest_path=True):
        """
        计算从 source 到 target 的最短路径的长度
        :param track_shortest_path: 是否记录最短路径
        :param source:
        :param target:
        :return:
        """
        distances = {node: float('inf') for node in self.graph_in_adj_list}
        distances[source] = 0
        shortest_path_graph: Dict[str, List[str]] = {vertex: [] for vertex in self.graph_in_adj_list}
        shortest_distance = float('inf')
        q = [(0, source)]
        while q:
            distance, node = heapq.heappop(q)
            if target == node:
                shortest_distance = distance
                break
            for adj_node, adj_distance in self.graph_in_adj_list.get(node, {}).items():
                new_distance = distance + adj_distance
                if new_distance < distances.get(adj_node, float('inf')):
                    distances[adj_node] = new_distance
                    heapq.heappush(q, (new_distance, adj_node))
                    if track_shortest_path:
                        shortest_path_graph[adj_node] = [node]
                elif new_distance == adj_distance:
                    if track_shortest_path:
                        shortest_path_graph[adj_node].append(node)
        return shortest_distance, shortest_path_graph if track_shortest_path else distances


class DijkstraAlgorithmInFiniteGraphTrackingShortestPathTree:
    """
    添加它的目的是为了和前面的进行区分
    """

    def __init__(self, graph_in_adj_list: Dict[str, Dict[str, int]]):
        self.graph_in_adj_list = graph_in_adj_list

    def shortest_path_to_all_nodes(self, source: str, track_shortest_path_tree=True):
        """
        1、计算从 source 到所有 node 的距离
        2、注意: 由于self.graph_in_adj_list的key可能不包括所有的node，因此对于使用self.graph_in_adj_list的key构建的dict，
        为了避免KeyError，使用Dict.get(key, default value)
        :param source:
        :param track_shortest_path_tree: 是否记录最短路径
        :return:
        """
        distances = {node: float('inf') for node in
                     self.graph_in_adj_list}  # 从start到各个node的距离，这里使用的是dict comprehension语法
        distances[source] = 0
        shortest_path_tree: Dict[str, str] = {vertex: None for vertex in self.graph_in_adj_list}

        q = [(0, source)]  # https://docs.python.org/3/library/heapq.html
        while q:
            current_distance, current_node = heapq.heappop(q)
            # 下面的这个判定其实是可以去除的，在 https://leetcode.cn/problems/network-delay-time/ 中
            if current_distance > distances[current_node]:
                continue

            for adj_node, new_distance in self.graph_in_adj_list.get(current_node, {}).items():
                new_distance = current_distance + new_distance
                if new_distance < distances.get(adj_node, float('inf')):
                    distances[adj_node] = new_distance
                    heapq.heappush(q, (new_distance, adj_node))
                    if track_shortest_path_tree:
                        shortest_path_tree[adj_node] = current_node

        return distances, shortest_path_tree if track_shortest_path_tree else distances

    @staticmethod
    def reconstruct_path(shortest_path_tree: Dict[str, str], target: str) -> List[str]:
        """
        构建从source到target的所有的path
        :return:
        """
        path: List[str] = []
        node = target
        # Stop condition: source node，source node是没有predecessor的
        while node is not None:
            path.append(node)
            node = shortest_path_tree[node]
        path.reverse()
        return path


class TestDijkstraAlgorithmInFiniteGraph(unittest.TestCase):

    def test_shortest_path_to_single_node_1(self):
        graph = {
            'A': {'B': 1, 'C': 4},
            'B': {'C': 2, 'D': 5},
            'C': {'D': 1},
            'D': {'E': 1},
            'E': {}
        }
        self.dijkstra = DijkstraAlgorithmInFiniteGraphTrackingShortestPathGraph(graph)
        start = 'A'
        end = 'E'
        distance, shortest_path_graph = self.dijkstra.shortest_path_to_single_node(start, end)
        self.assertEqual(distance, 5)
        paths = self.dijkstra.reconstruct_all_path(shortest_path_graph, end)
        print(paths)
        self.assertEqual(len(paths), 1)
        self.assertEqual(paths[0], ['A', 'B', 'C', 'D', 'E'])

    def test_shortest_path_to_single_node_2(self):
        """
        这个例子是展示edge relaxation的典型
        :return:
        """
        graph = {
            'A': {'B': 1, 'C': 3},
            'B': {'C': 1},
            'C': {},
        }
        self.dijkstra = DijkstraAlgorithmInFiniteGraphTrackingShortestPathGraph(graph)
        start = 'A'
        end = 'C'
        distance, shortest_path_graph = self.dijkstra.shortest_path_to_single_node(start, end)
        self.assertEqual(distance, 2)
        paths = self.dijkstra.reconstruct_all_path(shortest_path_graph, end)
        print(paths)
        self.assertEqual(len(paths), 1)
        self.assertEqual(paths[0], ['A', 'B', 'C'])

    def test_shortest_path_to_all_node(self):
        graph = {
            'A': {'B': 1, 'C': 4},
            'B': {'C': 2, 'D': 5},
            'C': {'D': 1},
            'D': {'E': 1},
            'E': {}
        }
        self.dijkstra = DijkstraAlgorithmInFiniteGraphTrackingShortestPathGraph(graph)
        start = 'A'
        distances, shortest_path_graph = self.dijkstra.shortest_path_to_all_nodes(start)
        d = 'D'
        e = 'E'
        self.assertEqual(distances[d], 4)
        self.assertEqual(distances[e], 5)
        paths = self.dijkstra.reconstruct_all_path(shortest_path_graph, d)
        print(paths)
        self.assertEqual(len(paths), 1)
        self.assertEqual(paths[0], ['A', 'B', 'C', 'D'])
        paths = self.dijkstra.reconstruct_all_path(shortest_path_graph, e)
        print(paths)
        self.assertEqual(len(paths), 1)
        self.assertEqual(paths[0], ['A', 'B', 'C', 'D', 'E'])


class TestDijkstraAlgorithmInFiniteGraphTrackingShortestPathTree(unittest.TestCase):
    def test_shortest_path_to_all_node(self):
        graph = {
            'A': {'B': 1, 'C': 4},
            'B': {'C': 2, 'D': 5},
            'C': {'D': 1},
            'D': {}
        }
        dijkstra = DijkstraAlgorithmInFiniteGraphTrackingShortestPathTree(graph)
        source = 'A'
        distances, shortest_path_tree = dijkstra.shortest_path_to_all_nodes(source)
        d = 'D'
        self.assertEqual(distances[d], 4)
        path = dijkstra.reconstruct_path(shortest_path_tree, d)
        print(path)
        self.assertEqual(path, ['A', 'B', 'C', 'D'])


if __name__ == '__main__':
    unittest.main()

```



#### UniformCostSearch

```python
import heapq
import unittest
from typing import Dict


def uniform_cost_search(graph: Dict[str, Dict[str, int]], start: str, goal: str):
    # Priority queue to hold the frontier with path cost
    frontier = [(0, start, [])]
    heapq.heapify(frontier)

    # Set to keep track of visited nodes
    explored = set()

    while frontier:
        # Pop the vertex with the smallest cost
        cost, current_vertex, path = heapq.heappop(frontier)

        # If the goal is reached, return the cost and path
        if current_vertex == goal:
            return cost, path + [current_vertex]

        # Mark the node as explored
        explored.add(current_vertex)

        # Add neighbors to the frontier if they haven't been explored
        for neighbor, neighbor_cost in graph[current_vertex].items():
            if neighbor not in explored:
                heapq.heappush(frontier, (cost + neighbor_cost, neighbor, path + [current_vertex]))

    return float("inf"), []  # If the goal is not reachable


class TestUniformCostSearch(unittest.TestCase):
    def test_uniform_cost_search_1(self):
        # Example usage:
        graph = {
            'A': {'B': 2, 'C': 5},
            'B': {'C': 1, 'D': 4},
            'C': {'D': 1, 'E': 7},
            'D': {'E': 3},
            'E': {}
        }

        start = 'A'
        goal = 'E'
        cost, path = uniform_cost_search(graph, start, goal)
        print(f"Cost: {cost}, Path: {path}")
        self.assertEqual(cost, 7)

    def test_uniform_cost_search_2(self):
        """
        一个非常简单的展示relaxation的例子
        :return:
        """
        # Example usage:
        graph = {
            'A': {'B': 1, 'C': 3},
            'B': {'C': 1},
            'C': {},
        }

        start = 'A'
        goal = 'C'
        cost, path = uniform_cost_search(graph, start, goal)
        print(f"Cost: {cost}, Path: {path}")
        self.assertEqual(cost, 2)


if __name__ == '__main__':
    unittest.main()

```



### Java


labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect)

```Java
// 返回节点 from 到节点 to 之间的边的权重
int weight(int from, int to);

// 输入节点 s 返回 s 的相邻节点
List<Integer> adj(int s);

// 输入一幅图和一个起点 start，计算 start 到其他节点的最短距离
int[] dijkstra(int start, List<Integer>[] graph) {
    // 图中节点的个数
    int V = graph.length;
    // 记录最短路径的权重，你可以理解为 dp table
    // 定义：distTo[i] 的值就是节点 start 到达节点 i 的最短路径权重
    int[] distTo = new int[V];
    // 求最小值，所以 dp table 初始化为正无穷
    Arrays.fill(distTo, Integer.MAX_VALUE);
    // base case，start 到 start 的最短距离就是 0
    distTo[start] = 0;

    // 优先级队列，distFromStart 较小的排在前面
    Queue<State> pq = new PriorityQueue<>((a, b) -> {
        return a.distFromStart - b.distFromStart;
    });

    // 从起点 start 开始进行 BFS
    pq.offer(new State(start, 0));

    while (!pq.isEmpty()) {
        State curState = pq.poll();
        int curNodeID = curState.id;
        int curDistFromStart = curState.distFromStart;

        if (curDistFromStart > distTo[curNodeID]) {
            // 已经有一条更短的路径到达 curNode 节点了
            continue;
        }
        // 将 curNode 的相邻节点装入队列
        for (int nextNodeID : adj(curNodeID)) {
            // 看看从 curNode 达到 nextNode 的距离是否会更短
            int distToNextNode = distTo[curNodeID] + weight(curNodeID, nextNodeID);
            if (distTo[nextNodeID] > distToNextNode) {
                // 更新 dp table
                distTo[nextNodeID] = distToNextNode;
                // 将这个节点以及距离放入队列
                pq.offer(new State(nextNodeID, distToNextNode));
            }
        }
    }
    return distTo;
}
```





## LeetCode 



### [LeetCode-743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time/) 

```python
import heapq
import unittest
from typing import List, Dict


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        distances = {i + 1: float('inf') for i in range(n)}
        graph_in_ajd_list: Dict[int, Dict] = {t[0]: {} for t in times}
        for t in times:
            graph_in_ajd_list[t[0]][t[1]] = t[2]
        distances[k] = 0
        q = [(0, k)]
        while q:
            distance, node = heapq.heappop(q)
            for adj_node, adj_distance in graph_in_ajd_list.get(node, {}).items():
                new_distance = distance + adj_distance
                if new_distance < distances[adj_node]:
                    distances[adj_node] = new_distance
                    heapq.heappush(q, (new_distance, adj_node))

        max_distance = -1
        if float('inf') in distances.values():
            return max_distance
        return max(distances.values())


class TestStringMethods(unittest.TestCase):

    def test_case_1(self):
        self.solution = Solution()
        times = [[1, 2, 1], [2, 3, 2], [1, 3, 4]]
        n = 3
        k = 1

        self.assertEqual(self.solution.networkDelayTime(times, n, k), -1)


if __name__ == '__main__':
    unittest.main()

```



[LeetCode-1631. 最小体力消耗路径](https://leetcode.cn/problems/path-with-minimum-effort/) 



[LeetCode-1514. 概率最大的路径](https://leetcode.cn/problems/path-with-maximum-probability/) 



[LeetCode-787. K 站中转内最便宜的航班-中等](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 



