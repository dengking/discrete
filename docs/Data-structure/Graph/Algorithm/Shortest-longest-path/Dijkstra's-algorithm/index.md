# Dijkstra's algorithm

## 素材

一、wikipedia [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) 

二、labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 

这篇文章非常好。

## 使用条件

非负数边

## 概括

dijkstra=BFS+greedy-algorithm贪心算法+dynamic-programming动态规划

## wikipedia [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) 

The algorithm exists in many variants. Dijkstra's original algorithm found the shortest path between two given nodes,[[5\]](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#cite_note-Dijkstra1959-5) but a more common variant fixes a single node as the "source" node and finds shortest paths from the source to all other nodes in the graph, producing a [shortest-path tree](https://en.wikipedia.org/wiki/Shortest-path_tree).

> NOTE: 
>
> 一、single source
>
> 二、从后面的`Pseudocode`可知，dijkstra的implementation中，会将 [shortest-path tree](https://en.wikipedia.org/wiki/Shortest-path_tree) 存放到`prev` array中
>
> 

The Dijkstra algorithm uses labels that are positive integers or real numbers, which are [totally ordered](https://en.wikipedia.org/wiki/Total_order). It can be generalized to use any labels that are [partially ordered](https://en.wikipedia.org/wiki/Partially_ordered_set), provided the subsequent labels (a subsequent label is produced when traversing an edge) are [monotonically](https://en.wikipedia.org/wiki/Monotonic_function) non-decreasing. This generalization is called the generic Dijkstra shortest-path algorithm.[[7\]](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#cite_note-Generic_Dijkstra-7)

> NOTE: label的含义是什么？



This is [asymptotically](https://en.wanweibaike.com/wiki-Asymptotic_computational_complexity) the fastest known single-source [shortest-path algorithm](https://en.wanweibaike.com/wiki-Shortest_path_problem) for arbitrary [directed graphs](https://en.wanweibaike.com/wiki-Directed_graph) with unbounded non-negative weights. 

> NOTE: 
>
> 需要注意的是: dijkstra 算法是不允许负数边的

In some fields, [artificial intelligence](https://en.wanweibaike.com/wiki-Artificial_intelligence) in particular, Dijkstra's algorithm or a variant of it is known as **uniform cost search** and formulated as an instance of the more general idea of [best-first search](https://en.wanweibaike.com/wiki-Best-first_search).[[9\]](https://en.wanweibaike.com/wiki-Dijkstra's Algorithm#cite_note-felner-9)

### Pseudocode

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
> 上述伪代码的initialization:
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

#### Shortest path between vertices source and target

If we are only interested in a shortest path between vertices source and target, we can terminate the search after line 15 if `u = target`. 

Now we can read the shortest path from source to target by reverse iteration:

```pseudocode
1  S ← empty sequence
2  u ← target
3  if prev[u] is defined or u = source:          // Do something only if the vertex is reachable
4      while u is defined:                       // Construct the shortest path with a stack S
5          insert u at the beginning of S        // Push the vertex onto the stack
6          u ← prev[u]                           // Traverse from target to source
```

> NOTE: 
>
> 上述演示的是构造从source到target的shortest path的算法

Now sequence `S` is the list of vertices constituting one of the shortest paths from source to target, or the empty sequence if no path exists.

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
> 通过对比可知，`priority queue`的优势在于`u ← Q.extract_min()` 

### Practical optimizations and infinite graphs

In common presentations of Dijkstra's algorithm, initially all nodes are entered into the priority queue. This is, however, not necessary: the algorithm can start with a priority queue that contains only one item, and insert new items as they are discovered (instead of doing a decrease-key, check whether the key is in the queue; if it is, decrease its key, otherwise insert it).[[7\]](https://en.wanweibaike.com/wiki-Dijkstra's Algorithm#cite_note-mehlhorn-7):198 This variant has the same worst-case bounds as the common variant, but maintains a smaller priority queue in practice, speeding up the queue operations.[[9\]](https://en.wanweibaike.com/wiki-Dijkstra's Algorithm#cite_note-felner-9)

Moreover, not inserting all nodes in a graph makes it possible to extend the algorithm to find the shortest path from a single source to the closest of a set of target nodes on infinite graphs or those too large to represent in memory. The resulting algorithm is called *uniform-cost search* (UCS) in the artificial intelligence literature[[9\]](https://en.wanweibaike.com/wiki-Dijkstra's Algorithm#cite_note-felner-9)[[17\]](https://en.wanweibaike.com/wiki-Dijkstra's Algorithm#cite_note-aima-17)[[18\]](https://en.wanweibaike.com/wiki-Dijkstra's Algorithm#cite_note-18) and can be expressed in pseudocode as

```C++
procedure uniform_cost_search(Graph, start, goal) is
    node ← start
    cost ← 0
    frontier ← priority queue containing node only
    explored ← empty set
    do
        if frontier is empty then
            return failure
        node ← frontier.pop()
        if node is goal then
            return solution
        explored.add(node)
        for each of node's neighbors n do
            if n is not in explored then
                frontier.add(n)
```

### Related problems and algorithms

Unlike Dijkstra's algorithm, the [Bellman–Ford algorithm](https://en.wanweibaike.com/wiki-Bellman–Ford_algorithm) can be used on graphs with negative edge weights, as long as the graph contains no [negative cycle](https://en.wanweibaike.com/wiki-Negative_cycle) reachable from the source vertex *s*. The presence of such cycles means there is no shortest path, since the total weight becomes lower each time the cycle is traversed. (This statement assumes that a "path" is allowed to repeat vertices. In [graph theory](https://en.wanweibaike.com/wiki-Graph_theory) that is normally not allowed. In [theoretical computer science](https://en.wanweibaike.com/wiki-Theoretical_computer_science) it often is allowed.) It is possible to adapt Dijkstra's algorithm to handle negative weight edges by combining it with the Bellman-Ford algorithm (to remove negative edges and detect negative cycles), such an algorithm is called [Johnson's algorithm](https://en.wanweibaike.com/wiki-Johnson's_algorithm).

## Implementation

写法有多种版本:


wikipedia [Dijkstra's algorithm # Pseudocode](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#Pseudocode)

```pseudocode
1  function Dijkstra(Graph, source):
2      dist[source] ← 0                           // Initialization
3
4      create vertex priority queue Q
5      Q.add_with_priority(source, dist[source])
6
7      for each vertex v in Graph.Vertices:
8          if v ≠ source
9              dist[v] ← INFINITY                 // Unknown distance from source to v
10              prev[v] ← UNDEFINED                // Predecessor of v
11
12         Q.add_with_priority(v, dist[v])
13
14
15     while Q is not empty:                      // The main loop
16         u ← Q.extract_min()                    // Remove and return best vertex
17         for each neighbor v of u:              // only v that are still in Q
18             alt ← dist[u] + Graph.Edges(u, v)
19             if alt < dist[v] and dist[u] is not INFINITY:
20                 dist[v] ← alt
21                 prev[v] ← u
22                 Q.decrease_priority(v, alt)
23
24     return dist, prev
```


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

两者之间的差别:

1、labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 中多了如下逻辑:

```Java
    if (curDistFromStart > distTo[curNodeID]) {
        // 已经有一条更短的路径到达 curNode 节点了
        continue;
    }
```
那这个逻辑是否是必须要的呢？是有必要的，在笔记中进行了说明。

2、wikipedia [Dijkstra's algorithm # Pseudocode](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#Pseudocode) 一次性将所有等node都加入到queue中，labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 中是动态加入。如果 queue不支持 `decrease_priority` 接口，那么就无法按照 wikipedia [Dijkstra's algorithm # Pseudocode](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#Pseudocode) 中的写法写。


3、在具体的实现上，需要将distance/weight和node一起放到`priority_queue`中，不能够只放node或者只放distance/weight，因为这样是会导致无法对node进行排序、无法取出node等。wikipedia [Dijkstra's algorithm # Pseudocode](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#Pseudocode) 中是通过如下方式实现的:

```Java
Q.add_with_priority(source, dist[source])
Q.decrease_priority(v, alt)
```

在labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect)中是通过如下方式实现的:

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



## LeetCode 



[LeetCode-743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time/) 

[LeetCode-1631. 最小体力消耗路径](https://leetcode.cn/problems/path-with-minimum-effort/)

[LeetCode-1514. 概率最大的路径](https://leetcode.cn/problems/path-with-maximum-probability/)

[LeetCode-787. K 站中转内最便宜的航班-中等](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 



