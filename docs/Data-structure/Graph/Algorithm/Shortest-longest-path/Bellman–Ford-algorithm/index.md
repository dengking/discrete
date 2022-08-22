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
> | [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) | [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) |
>| ------------------------------------------------------------ | ------------------------------------------------------------ |
> | Dijkstra's algorithm uses a [priority queue](https://en.wikipedia.org/wiki/Priority_queue) to [greedily](https://en.wikipedia.org/wiki/Greedy_algorithm) select the closest vertex that has not yet been processed, and performs this relaxation process on all of its outgoing edges; | Bellman–Ford algorithm simply relaxes *all* the edges, and does this $|V|-1$ times, where $|V|$  is the number of vertices in the graph. |
>
> 
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
> 二、初次阅读上述code，会疑惑它是否是求解SSSP的，因为在step2中并没有看到对source对处理。这需要结合 geeksforgeeks [Bellman–Ford Algorithm | DP-23](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/)  中的source code来看。 

Simply put, the algorithm initializes the distance to the source to 0 and all other nodes to infinity. Then for all edges, if the distance to the destination can be shortened by taking the edge, the distance is updated to the new lower value.

#### Why repeat |V|−1 times?

Since the longest possible path without a cycle can be $|V|-1$ edges, the edges must be scanned $|V|-1$ times to ensure the shortest path has been found for all nodes. 

> NOTE: 
>
> 一、上面这段话的解释很一般，在 geeksforgeeks [Bellman–Ford Algorithm | DP-23](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/) 中有着更好的说明:
>
> > ***How does this work?*** Like other **Dynamic Programming** Problems, the algorithm calculates shortest paths in a bottom-up manner. It first calculates the shortest distances which have at-most one edge in the path. Then, it calculates the shortest paths with at-most 2 edges, and so on. After the i-th iteration of the outer loop, the shortest paths with at most i edges are calculated. There can be maximum |V| – 1 edges in any simple path, that is why the outer loop runs |v| – 1 times. The idea is, assuming that there is no **negative weight cycle**, if we have calculated **shortest paths** with at most i edges, then an iteration over all edges guarantees to give shortest path with at-most (i+1) edges (Proof is simple, you can refer [this](http://courses.csail.mit.edu/6.006/spring11/lectures/lec15.pdf) or [MIT Video Lecture](http://www.youtube.com/watch?v=Ttezuzs39nk))
>
> 

#### Finding negative cycles

A final scan of all the edges is performed and if any distance is updated, then a path of length $|V|$ edges has been found which can only occur if at least one negative cycle exists in the graph.

> NOTE: 
>
> 一、上面这段话结合 geeksforgeeks [Bellman–Ford Algorithm | DP-23](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/) 中的例子会更加容易理解



## Source code

### geeksforgeeks [Bellman–Ford Algorithm | DP-23](https://www.geeksforgeeks.org/bellman-ford-algorithm-dp-23/)





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

> NOTE: 上述代码在原文的代码基础上进行了一点微调。