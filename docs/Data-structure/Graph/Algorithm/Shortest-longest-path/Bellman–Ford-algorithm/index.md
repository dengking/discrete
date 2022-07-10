# Bellman–Ford algorithm

一、需要注意的是: [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 属于 DP范畴。

二、"Like [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm), Bellman–Ford proceeds by [relaxation](https://en.wikipedia.org/wiki/Relaxation_(approximation))"

## wikipedia [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 

The **Bellman–Ford algorithm** is an [algorithm](https://en.wanweibaike.com/wiki-Algorithm) that computes [shortest paths](https://en.wanweibaike.com/wiki-Shortest_path) from a single source [vertex](https://en.wanweibaike.com/wiki-Vertex_(graph_theory)) to all of the other vertices in a [weighted digraph](https://en.wanweibaike.com/wiki-Weighted_digraph).[[1\]](https://en.wanweibaike.com/wiki-Bellman Ford#cite_note-Bang-1) It is slower than [Dijkstra's algorithm](https://en.wanweibaike.com/wiki-Dijkstra's_algorithm) for the same problem, but more versatile, as it is capable of handling graphs in which some of the edge weights are negative numbers. 

> NOTE: 
>
> 能够处理负数

### Algorithm

Like [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm), Bellman–Ford proceeds by [relaxation](https://en.wikipedia.org/wiki/Relaxation_(approximation)), in which approximations(逼近、近似) to the correct distance are replaced by better ones until they eventually reach the solution. In both algorithms, the approximate distance to each vertex is always an overestimate(高估) of the **true distance**, and is replaced by the minimum of its old value and the length of a newly found path. However, Dijkstra's algorithm uses a [priority queue](https://en.wikipedia.org/wiki/Priority_queue) to [greedily](https://en.wikipedia.org/wiki/Greedy_algorithm) select the closest vertex that has not yet been processed, and performs this relaxation process on all of its outgoing edges; by contrast, the Bellman–Ford algorithm simply relaxes *all* the edges, and does this $|V|-1$ times, where $|V|$  is the number of vertices in the graph. In each of these repetitions, the number of vertices with correctly calculated distances grows, from which it follows that eventually all vertices will have their correct distances. This method allows the Bellman–Ford algorithm to be applied to a wider class of inputs than Dijkstra. The intermediate answers depend on the order of edges relaxed, but the final answer remains the same.

> NOTE:
>
> 一、[relaxation](https://en.wikipedia.org/wiki/Relaxation_(approximation)) 的表面含义是"松弛"，它所链接的文章是 [Relaxation (approximation)](https://en.wikipedia.org/wiki/Relaxation_(approximation)) ，其中"approximation"的含义是"逼近"、"近似"，理解这个词是理解上面这段话的基础，结合具体代码来说，它指的是:
>
> ```
>              if distance[u] + w < distance[v] then
>                  distance[v] := distance[u] + w
>                  predecessor[v] := u
> ```
>
> 
>
> 二、上面这段话非常好地总结来 [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) 和 [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 之间的异同:
>
> 同: 
>
> "Like [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm), Bellman–Ford proceeds by [relaxation](https://en.wikipedia.org/wiki/Relaxation_(approximation)), in which approximations(逼近、近似) to the correct distance are replaced by better ones until they eventually reach the solution. In both algorithms, the approximate distance to each vertex is always an overestimate(高估) of the **true distance**, and is replaced by the minimum of its old value and the length of a newly found path. "
>
> 这一段的总结非常好。
>
> 异:
>
> "Dijkstra's algorithm uses a [priority queue](https://en.wikipedia.org/wiki/Priority_queue) to [greedily](https://en.wikipedia.org/wiki/Greedy_algorithm) select the closest vertex that has not yet been processed, and performs this relaxation process on all of its outgoing edges; 
>
> Bellman–Ford algorithm simply relaxes *all* the edges, and does this $|V|-1$ times, where $|V|$  is the number of vertices in the graph. " 
>
> |      | [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) | [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) |
> | ---- | ------------------------------------------------------------ | ------------------------------------------------------------ |
> |      |                                                              |                                                              |
> |      |                                                              |                                                              |
> |      |                                                              |                                                              |
>
>  
>
> 三、思考: 为什么执行 $|V|-1$ 次 relaxation？从穷举的角度来思考：对于一个有$|V|$ 个节点的图，每个节点最多有 $|V|-1$  个processor节点。原文本节的最后一段对这个问题进行了说明。



```pseudocode
function BellmanFord(list vertices, list edges, vertex source) is

    // This implementation takes in a graph, represented as
    // lists of vertices (represented as integers [0..n-1]) and edges,
    // and fills two arrays (distance and predecessor) holding
    // the shortest path from the source to each vertex

    distance := list of size n
    predecessor := list of size n

    // Step 1: initialize graph
    for each vertex v in vertices do

        distance[v] := inf             // Initialize the distance to all vertices to infinity
        predecessor[v] := null         // And having a null predecessor
    
    distance[source] := 0              // The distance from the source to itself is, of course, zero

    // Step 2: relax edges repeatedly
    
    repeat |V|−1 times:
         for each edge (u, v) with weight w in edges do
             if distance[u] + w < distance[v] then
                 distance[v] := distance[u] + w
                 predecessor[v] := u

    // Step 3: check for negative-weight cycles
    for each edge (u, v) with weight w in edges do
        if distance[u] + w < distance[v] then
            // Step 4: find a negative-weight cycle
            negativeloop := [v, u]
            repeat |V|−1 times:
                u := negativeloop[0]
                for each edge (u, v) with weight w in edges do
                    if distance[u] + w < distance[v] then
                        negativeloop := concatenate([v], negativeloop)
            find a cycle in negativeloop, let it be ncycle
            // use any cycle detection algorithm here
            error "Graph contains a negative-weight cycle", ncycle

    return distance, predecessor
```

> NOTE: 关于"Step 3: check for negative-weight cycles"，在 geeksforgeeks [Bellman–Ford Algorithm | DP-23](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/)  中有着更好的描述。

Since the longest possible path without a cycle can be $|V|-1$ edges, the edges must be scanned $|V|-1$ times to ensure the shortest path has been found for all nodes. A final scan of all the edges is performed and if any distance is updated, then a path of length $|V|$ edges has been found which can only occur if at least one negative cycle exists in the graph.



