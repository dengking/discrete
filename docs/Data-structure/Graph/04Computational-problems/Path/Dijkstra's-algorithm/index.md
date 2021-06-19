# Dijkstra's algorithm

## 使用条件

非负数边

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
