# Shortest and longest path 



---

> References:
>
> [stackoverflow-Negative weights using Dijkstra's Algorithm](https://stackoverflow.com/questions/6799172/negative-weights-using-dijkstras-algorithm) 
>
> [algs4.cs.princeton-4.4  Shortest Paths](https://algs4.cs.princeton.edu/44sp/) 
>
> [zhihu-如何看待 SPFA 算法已死这种说法？](https://www.zhihu.com/question/292283275/answer/484871888) 
>
> [zhihu-Dijkstra's 最短路径算法能不能解这个含有负权重的问题？](https://www.zhihu.com/question/21620069/answer/24518138) 
>
> [LeetCode-【宫水三叶】涵盖所有的「存图方式」与「最短路算法（详尽注释）」](https://leetcode.cn/problems/network-delay-time/solution/gong-shui-san-xie-yi-ti-wu-jie-wu-chong-oghpz/) 
>
> [LeetCode-五种最短路径算法总结](https://leetcode.cn/problems/network-delay-time/solution/dirkdtra-by-happysnaker-vjii/) 
>
> [wikipedia-Parallel all-pairs shortest path algorithm](https://en.wikipedia.org/wiki/Parallel_all-pairs_shortest_path_algorithm) 
>
> [wikipedia-Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 

---



Ask yourself: 

- SSSP or APSP?

**SSSP**=single-source-shortest-path

**APSP**=all-pair-shortest-paths 

- Is there negative weight edges in the graph？

- Is the graph finite or infinite？

显然，上述**维度**进行两两组合会产生多种可能性，我们从如下经典的算法入手来进行学习:

- [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm)  
- [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm) 

- [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) 

上述算法基本上涵盖了前面提到的各个维度，我们遵循循序渐进、由容到难的，从最简单、最通用的算法开始逐步进入到更加复杂的、更加优化的算法。



## Algorithms



|                                | [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) | [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm) | [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) | **BFS**    |
| ------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ---------- |
|                                | SSSP                                                         | APSP                                                         | SSSP                                                         |            |
|                                | weighted-digraph-with-negative-weight-edges                  | weighted-digraph-with-negative-weight-edges                  | weighted-digraph-without-negative-weight-edges               | unweighted |
| **graph representation**       | edges list                                                   | [adjacency matrix](https://en.wikipedia.org/wiki/Adjacency_matrix) | [adjacency list](https://en.wikipedia.org/wiki/Adjacency_list) |            |
| **algorithm paradigm**         | DP                                                           | DP                                                           | BFS+greedy+DP                                                |            |
| **approximation**              | edge relaxation                                              | edge relaxation                                              | edge relaxation                                              |            |
| **bast-case-time-complexity**  |                                                              | $O(V^3)$                                                     |                                                              |            |
| **worst-case-time-complexity** |                                                              | $O(V^3)$                                                     |                                                              |            |
|                                |                                                              |                                                              |                                                              |            |



### Edge relaxation

---

> References:
>
> - stackoverflow [Relaxation of an edge in Dijkstra's algorithm](https://stackoverflow.com/questions/12782431/relaxation-of-an-edge-in-dijkstras-algorithm) 
> - towardsdatascience [Understanding Edge Relaxation for Dijkstra’s Algorithm and Bellman-Ford Algorithm](https://towardsdatascience.com/algorithm-shortest-paths-1d8fa3f50769) 
> - baeldung [Edge Relaxation in Dijkstra’s Algorithm](https://www.baeldung.com/cs/dijkstra-edge-relaxation) 
> - wikipedia [Relaxation (approximation)](https://en.wikipedia.org/wiki/Relaxation_(approximation))

---

[Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 、[Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm) 、[Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) 都是 "proceed by edge relaxation"，关于"edge relaxation"，在 wikipedia [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 中有着非常好的总结:

> Like [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm), Bellman–Ford proceeds by [relaxation](https://en.wikipedia.org/wiki/Relaxation_(approximation)), in which approximations to the correct distance are replaced by better ones until they eventually reach the solution. In both algorithms, the approximate distance to each vertex is always an overestimate of the true distance, and is replaced by the minimum of its old value and the length of a newly found path. 

上述三个algorithm都是"proceed by [relaxation](https://en.wikipedia.org/wiki/Relaxation_(approximation))" ，它们所不同的是执行relaxation的次数、时机，它们展示了求解**最优值问题**的非常好的范式(paradigm)，这种paradigm可以归入到

- iterative-optimization-algorithm

- DP optimization algorithm

[relaxation](https://en.wikipedia.org/wiki/Relaxation_(approximation)) 的表面含义是"松弛"，它所链接的文章是 [wikipedia-Relaxation (approximation)](https://en.wikipedia.org/wiki/Relaxation_(approximation)) ，其中"approximation"的含义是"逼近"、"近似"，理解这个词是理解这些algorithm的基础；

在 "stackoverflow [Relaxation of an edge in Dijkstra's algorithm](https://stackoverflow.com/questions/12782431/relaxation-of-an-edge-in-dijkstras-algorithm) What does **relaxation of an edge** mean in the context of graph theory ?" # [A](https://stackoverflow.com/a/12782683) 中给出了这个词的由来的非常形象化的解释: 

> [Here's](http://web.cs.unlv.edu/larmore/Courses/CSC269/pathing) a nice description of the Algorithm that also explains the notion of relaxation.
>
> > The notion of "relaxation" comes from an analogy between the estimate of the shortest path and the length of a **helical tension spring**(螺旋拉升的弹簧), which is not designed for compression. Initially, the cost of the shortest path is an overestimate, likened to a stretched out spring. As shorter paths are found, the estimated cost is lowered, and the spring is relaxed. Eventually, the shortest path, if one exists, is found and the spring has been relaxed to its resting(静止) length.
>

简而言之:弹簧一开始被拉伸地很长，后来不断释放而越来越短最终恢复到弹簧的静止最短长度。在弹簧的语境中，"relax"的意思是"放松"、"释放"，显然它非常符合graph中求解shortest path的语境。

---

> 翻译: 
>
> "likened"的意思是类比、比照；
>
> "helical tension spring"的意思是"螺旋拉升的弹簧"
>
> "estimate"、"overestimate"
>
> "stretched out"的意思是"伸展"、"拉伸"

---

在 stackoverflow [Relaxation of an edge in Dijkstra's algorithm](https://stackoverflow.com/questions/12782431/relaxation-of-an-edge-in-dijkstras-algorithm) # [A](https://stackoverflow.com/a/12782820) 中给出了具体代码:

```pseudocode
if distance[u] + w < distance[v] then
    distance[v] := distance[u] + w
    predecessor[v] := u
```



#### 基于edge relaxation规范和简化algorithms 

基于**edge relaxation**，可以对上述algorithm的代码进行**规范**和**简化**:

- Dijkstra

  参考自: stackoverflow [Negative weights using Dijkstra's Algorithm](https://stackoverflow.com/questions/6799172/negative-weights-using-dijkstras-algorithm) 

  ```pseudocode
  Dijkstra(G, w, s)  {
     Initialize-Single-Source(G, s)
     S ← Ø
     Q ← V[G]//priority queue by d[v]
     while Q ≠ Ø do
        u ← Extract-Min(Q)
        S ← S U {u}
        for each vertex v in Adj[u] do
           Relax(u, v)
  }
  
  Initialize-Single-Source(G, s) {
     for each vertex v  V(G)
        d[v] ← ∞
        π[v] ← NIL
     d[s] ← 0
  }
  
  Relax(u, v) {
     //update only if we found a strictly shortest path
     if d[v] > d[u] + w(u,v) 
        d[v] ← d[u] + w(u,v)
        π[v] ← u
        Update(Q, v)
  }
  ```

  

### Others

#### Negative weight cycle 

都不支持negative cycle 



#### 解的表达方式

1、SSSP

shortest-path-tree

shortest-path-graph

```C++
void Dijkstra(Vertex source,Weight dist[], Vertex prev[])const; 

//dist[]用来保存最终的结果，

//prev[]用来记录每个结点的直接前驱
```

2、APSP

[incidence matrix](https://en.wikipedia.org/wiki/Incidence_matrix)

```C++
void Floyd(int arrDis[][], Vertex arrPath[][])const;

//arrDis[][]用来存储问题的解，即图中，任意两个结点之间的最短距离。使用邻接矩阵weight_adjacency对它进行初始化

//arrPath存储的是中间结点，arrPath[i][j]表示从结点i到结点j的最短路径需要经过的中间结点
```



### Comparison

---

> References: 
>
> - stackexchange [Am I right about the differences between Floyd-Warshall, Dijkstra's and Bellman-Ford algorithms?](https://softwareengineering.stackexchange.com/questions/158613/am-i-right-about-the-differences-between-floyd-warshall-dijkstras-and-bellman) 
> - stackoverflow [What is the basic difference between Bellman-ford and Floyd warshall algorithm?](https://stackoverflow.com/questions/34461496/what-is-the-basic-difference-between-bellman-ford-and-floyd-warshall-algorithm) 

---



#### Dijkstra's-algorithm-VS-Bellman–Ford-algorithm

素材: 

1、wikipedia [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm)



#### Dijkstra's-algorithm-VS-BFS

一、在 baeldung [Difference Between BFS and Dijkstra’s Algorithms](https://www.baeldung.com/cs/graph-algorithms-bfs-dijkstra) 中有着非常好的总结:

> BFS calculates the shortest paths in unweighted graphs. 
>
> Dijkstra’s algorithm calculates the same thing in weighted graphs.

其实在我的看来，"Dijkstra’s algorithm"其实是属于BFS的。

二、labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 

它介绍了BFS、Dijkstra's algorithm

三、BFS中的step就是目标值，它不需要"edge relaxation"。



#### Bellman–Ford-algorithm-VS-Floyd–Warshall-algorithm

---

> References: 
>
> geeksforgeeks [Bellman–Ford Algorithm | DP-23](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/) 

---

Bellman–Ford-algorithm: 枚举经过一条**边**、两条边...

> "the algorithm calculates **shortest paths** in a **bottom-up** manner. It first calculates the shortest distances which have at-most one edge in the path. Then, it calculates the shortest paths with at-most 2 edges, and so on. "



Floyd–Warshall-algorithm: 枚举经过一个**点**、两个点...

> "the algorithm calculates **shortest paths** in a **bottom-up** manner. It first calculates the shortest distances which have at-most one point in the path. Then, it calculates the shortest paths with at-most 2 points, and so on. "



## Bellman–Ford algorithm

### 概括

Bellman–Ford algorithm是一种简单(相比于Dijkstra's algorithm，它简单很多)但是versatile的算法，它可以简单地概括为: 对所有的edges执行 |V|−1 (|V|表示节点个数)的全体edge relaxation。那为什么是|V|−1次呢？在 geeksforgeeks [Bellman–Ford Algorithm | DP-23](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/) 中有着更好的说明:

> ***How does this work?*** Like other **Dynamic Programming** Problems, the algorithm calculates **shortest paths** in a bottom-up manner. It first calculates the shortest distances which have at-most one edge in the path. Then, it calculates the shortest paths with at-most 2 edges, and so on. After the i-th iteration of the outer loop, the shortest paths with at most i edges are calculated. There can be maximum |V| – 1 edges in any simple path, that is why the outer loop runs |v| – 1 times. The idea is, assuming that there is no **negative weight cycle**, if we have calculated **shortest paths** with at most i edges, then an iteration over all edges guarantees to give shortest path with at-most (i+1) edges (Proof is simple, you can refer [this](http://courses.csail.mit.edu/6.006/spring11/lectures/lec15.pdf) or [MIT Video Lecture](http://www.youtube.com/watch?v=Ttezuzs39nk))

并且它检测 **negative weight cycle** 的方式非常简单: 再执行一次全体edge relaxation，如果发现了relaxation，则肯定存在 **negative weight cycle** 。



#### Why support negative weight？

这个问题是可以对比Dijkstra's algorithm来进行理解的: Dijkstra's algorithm的支持negative weight的variant和不支持的已经蕴含了这个问题的答案。



### wikipedia [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 

The **Bellman–Ford algorithm** is an [algorithm](https://en.wanweibaike.com/wiki-Algorithm) that computes [shortest paths](https://en.wanweibaike.com/wiki-Shortest_path) from a single source [vertex](https://en.wanweibaike.com/wiki-Vertex_(graph_theory)) to all of the other vertices in a [weighted digraph](https://en.wanweibaike.com/wiki-Weighted_digraph).[[1\]](https://en.wanweibaike.com/wiki-Bellman Ford#cite_note-Bang-1) It is slower than [Dijkstra's algorithm](https://en.wanweibaike.com/wiki-Dijkstra's_algorithm) for the same problem, but more versatile, as it is capable of handling graphs in which some of the edge weights are negative numbers. 



#### Complexity

|                                                              | Complexity                        |
| :----------------------------------------------------------- | --------------------------------- |
| [Worst-case](https://en.wikipedia.org/wiki/Best,_worst_and_average_case) [performance](https://en.wikipedia.org/wiki/Time_complexity) | ${\displaystyle \Theta (|V||E|)}$ |
| [Best-case](https://en.wikipedia.org/wiki/Best,_worst_and_average_case) [performance](https://en.wikipedia.org/wiki/Time_complexity) | ${\displaystyle \Theta (|E|)}$    |
| [Worst-case](https://en.wikipedia.org/wiki/Best,_worst_and_average_case) [space complexity](https://en.wikipedia.org/wiki/Space_complexity) | ${\displaystyle \Theta (|V|)}$    |

> NOTE:
>
> 一、对于 [Best-case](https://en.wikipedia.org/wiki/Best,_worst_and_average_case) [performance](https://en.wikipedia.org/wiki/Time_complexity) ，需要结合 wikipedia [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) / [Improvements](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm#Improvements) 章节的内容来进行理解。

#### Algorithm

Like [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm), Bellman–Ford proceeds by [relaxation](https://en.wikipedia.org/wiki/Relaxation_(approximation)), in which approximations(逼近、近似) to the correct distance are replaced by better ones until they eventually reach the solution. In both algorithms, the **approximate distance** to each vertex is always an overestimate(高估) of the **true distance**, and is replaced by the minimum of its old value and the length of a newly found path. However, **Dijkstra's algorithm** uses a [priority queue](https://en.wikipedia.org/wiki/Priority_queue) to [greedily](https://en.wikipedia.org/wiki/Greedy_algorithm) select the closest vertex that has not yet been processed, and performs this **relaxation process** on all of its outgoing edges; by contrast, the **Bellman–Ford algorithm** simply relaxes *all* the edges, and does this $|V|-1$ times, where $|V|$  is the number of vertices in the graph. In each of these repetitions, the number of vertices with correctly calculated distances grows, from which it follows that eventually all vertices will have their correct distances. This method allows the Bellman–Ford algorithm to be applied to a wider class of inputs than Dijkstra. The intermediate answers depend on the order of edges relaxed, but the final answer remains the same.

> NOTE:
>
> 一、关于 [relaxation](https://en.wikipedia.org/wiki/Relaxation_(approximation)) 的表面含义是"松弛"，它所链接的文章是 [Relaxation (approximation)](https://en.wikipedia.org/wiki/Relaxation_(approximation)) ，前面也进行了说明
>
> **approximate distance** 
>    
>    **true distance** 
>    
> 二、上面这段话非常好地总结来 [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) 和 [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 之间的异同:
>
> 同: 
>
> "Like [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm), Bellman–Ford proceeds by [relaxation](https://en.wikipedia.org/wiki/Relaxation_(approximation)), in which approximations(逼近、近似) to the correct distance are replaced by better ones until they eventually reach the solution. In both algorithms, the **approximate distance** to each vertex is always an overestimate(高估) of the **true distance**, and is replaced by the minimum of its old value and the length of a newly found path. "
>
> 这一段的总结非常好。
>
> 异:
>
> | [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) | [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) |
>| ------------------------------------------------------------ | ------------------------------------------------------------ |
> | Dijkstra's algorithm uses a [priority queue](https://en.wikipedia.org/wiki/Priority_queue) to [greedily](https://en.wikipedia.org/wiki/Greedy_algorithm) select the closest vertex that has not yet been processed, and performs this relaxation process on all of its outgoing edges; | Bellman–Ford algorithm simply relaxes *all* the edges, and does this $|V|-1$ times, where $|V|$  is the number of vertices in the graph. |
>
> 三、思考: 为什么执行 $|V|-1$ 次 relaxation？在后面会进行介绍。



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

> NOTE: 
>
> 一、关于"Step 3: check for negative-weight cycles"，在 geeksforgeeks [Bellman–Ford Algorithm | DP-23](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/)  中有着更好的描述。
>
> 二、Bellman-Ford algorithm是求解SSSP(single source shortest path)的，它需要和Dijkstra执行相同的初始化: 
>
> ``` pseudocode
> distance[source] := 0              // The distance from the source to itself is, of course, zero
> ```
>
> 

Simply put, the algorithm initializes the distance to the source to 0 and all other nodes to infinity. Then for all edges, if the distance to the destination can be shortened by taking the edge, the distance is updated to the new lower value.

##### Why repeat |V|−1 times?

Since the longest possible path without a cycle can be $|V|-1$ edges, the edges must be scanned $|V|-1$ times to ensure the shortest path has been found for all nodes. 

> NOTE: 
>
> 一、上面这段话的解释很一般，在 geeksforgeeks [Bellman–Ford Algorithm | DP-23](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/) 中有着更好的说明，前面已经引用了，这里省略。

##### Finding negative cycles

When the algorithm is used to find shortest paths, the existence of negative cycles is a problem, preventing the algorithm from finding a correct answer. However, since it terminates upon finding a negative cycle, the Bellman–Ford algorithm can be used for applications in which this is the target to be sought – for example in [cycle-cancelling](https://en.wikipedia.org/wiki/Minimum-cost_flow_problem) techniques in [network flow](https://en.wikipedia.org/wiki/Flow_network) analysis.

> NOTE:
>
> 一、

#### Improvements / Variant

The Bellman–Ford algorithm may be improved in practice (although not in the worst case) by the observation that, if an iteration of the main loop of the algorithm terminates without making any changes, the algorithm can be immediately terminated, as subsequent iterations will not make any more changes. With this **early termination condition**, the main loop may in some cases use many fewer than |*V*| − 1 iterations, even though the worst case of the algorithm remains unchanged. The following improvements all maintain the $O(|V|\cdot |E|)$ worst-case time complexity.



### Implementation

#### Python

```c++
import unittest
from typing import List


class Graph:
    def __init__(self, vertices: int):
        self.V: int = vertices  # number of vertices
        self.graph: List[List] = []

    def add_edge(self, u: int, v: int, w: int):
        self.graph.append([u, v, w])

    def bellman_ford(self, src):
        # Step 1: Initialize distances from source to all other vertices as infinity
        dist = [float('inf')] * self.V
        dist[src] = 0

        # Step 2: Relax all edges |V| - 1 times
        for _ in range(self.V - 1):
            for u, v, w in self.graph:
                if dist[u] != float('inf') and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w

        # Step 3: Check for negative-weight cycles
        for u, v, w in self.graph:
            if dist[u] != float('inf') and dist[u] + w < dist[v]:
                print("Graph contains negative-weight cycle")
                return

        return dist


class TestBellmanFordAlgorithm(unittest.TestCase):
    def test_case_1(self):
        # Example usage
        g = Graph(5)
        g.add_edge(0, 1, -1)
        g.add_edge(0, 2, 4)
        g.add_edge(1, 2, 3)
        g.add_edge(1, 3, 2)
        g.add_edge(1, 4, 2)
        g.add_edge(3, 2, 5)
        g.add_edge(3, 1, 1)
        g.add_edge(4, 3, -3)

        source = 0
        distances = g.bellman_ford(source)

        print("Shortest distances from source", source)
        for i, distance in enumerate(distances):
            print(i, ":", distance)


if __name__ == '__main__':
    unittest.main()

```



#### C++

geeksforgeeks [Bellman–Ford Algorithm | DP-23](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/)



```C++
#include <iostream>
#include <string>
#include <unordered_map>
#include <array>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;
// A C++ program for Bellman-Ford's single source
// shortest path algorithm.

// a structure to represent a weighted edge in graph
struct Edge
{
    int src, dest, weight;
};

// a structure to represent a connected, directed and
// weighted graph
struct Graph
{
    // V-> Number of vertices, E-> Number of edges
    int V, E;

    // graph is represented as an array of edges.
    struct Edge *edge;
};

// Creates a graph with V vertices and E edges
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

// A utility function used to print the solution
void printArr(const vector<int> &dist)
{
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < dist.size(); ++i)
    {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// The main function that finds shortest distances from src
// to all other vertices using Bellman-Ford algorithm. The
// function also detects negative weight cycle
void BellmanFord(struct Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    // Step 1: Initialize distances from src to all other
    // vertices as INFINITE
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times. A simple
    // shortest path from src to any other vertex can have
    // at-most |V| - 1 edges
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            // dist[u] != INT_MAX 表示 u 是可达的
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: check for negative-weight cycles. The above
    // step guarantees shortest distances if graph doesn't
    // contain negative weight cycle. If we get a shorter
    // path, then there is a cycle.
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            printf("Graph contains negative weight cycle");
            return; // If negative cycle is detected, simply
                    // return
        }
    }

    printArr(dist);

    return;
}

// Driver program to test above functions
int main()
{
    /* Let us create the graph given in above example */
    int V = 5; // Number of vertices in graph
    int E = 8; // Number of edges in graph
    struct Graph *graph = createGraph(V, E);

    // add edge 0-1 (or A-B in above figure)
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = -1;

    // add edge 0-2 (or A-C in above figure)
    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 4;

    // add edge 1-2 (or B-C in above figure)
    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    // add edge 1-3 (or B-D in above figure)
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 2;

    // add edge 1-4 (or B-E in above figure)
    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 2;

    // add edge 3-2 (or D-C in above figure)
    graph->edge[5].src = 3;
    graph->edge[5].dest = 2;
    graph->edge[5].weight = 5;

    // add edge 3-1 (or D-B in above figure)
    graph->edge[6].src = 3;
    graph->edge[6].dest = 1;
    graph->edge[6].weight = 1;

    // add edge 4-3 (or E-D in above figure)
    graph->edge[7].src = 4;
    graph->edge[7].dest = 3;
    graph->edge[7].weight = -3;

    BellmanFord(graph, 0);

    return 0;
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



## Shortest Path Faster Algorithm



### wikipedia [Shortest Path Faster Algorithm](https://en.wikipedia.org/wiki/Shortest_Path_Faster_Algorithm)





## Max path in a graph

TODO: 需要补充一些例题。

参见: 

1、wikipedia [Longest path problem](https://en.wikipedia.org/wiki/Longest_path_problem)



## LeetCode



### [LeetCode-743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time/) 



### [LeetCode-120. 三角形最小路径和](https://leetcode.cn/problems/triangle/) 

