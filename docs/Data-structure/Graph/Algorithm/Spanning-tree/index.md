# Spanning tree



## wikipedia [Spanning tree](https://en.wikipedia.org/wiki/Spanning_tree)

In the [mathematical](https://en.wikipedia.org/wiki/Mathematics) field of [graph theory](https://en.wikipedia.org/wiki/Graph_theory), a **spanning tree** *T* of an [undirected graph](https://en.wikipedia.org/wiki/Undirected_graph) *G* is a subgraph that is a [tree](https://en.wikipedia.org/wiki/Tree_(graph_theory)) which includes all of the [vertices](https://en.wikipedia.org/wiki/Vertex_(graph_theory)) of *G*.

In general, a graph may have several spanning trees, but a graph that is not [connected](https://en.wikipedia.org/wiki/Connected_graph) will not contain a spanning tree (see about [spanning forests](https://en.wikipedia.org/wiki/Spanning_tree#Spanning_forests) below).

### Applications

Several [pathfinding](https://en.wikipedia.org/wiki/Pathfinding) algorithms, including [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) and the [A* search algorithm](https://en.wikipedia.org/wiki/A*_search_algorithm), internally build a spanning tree as an intermediate step in solving the problem.

> NOTE:
>
> 一、 [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) 的解称之为 [shortest-path-tree](https://en.wikipedia.org/wiki/Shortest-path_tree) 



### Spanning forests

A collection of disjoint (unconnected) trees is described as a *[forest](https://en.wikipedia.org/wiki/Forest_(graph_theory))*. A *spanning forest* in a graph is a subgraph that is a forest with an additional requirement. There are two incompatible requirements in use, of which one is relatively rare.

## Algorithms



### Construction

A single **spanning tree** of a graph can be found in [linear time](https://en.wikipedia.org/wiki/Linear_time) by either [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search) or [breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search). Both of these algorithms explore the given graph, starting from an arbitrary vertex *v*, by looping through the neighbors of the vertices they discover and adding each unexplored neighbor to a data structure to be explored later. They differ in whether this data structure is a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) (in the case of **depth-first search**) or a [queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) (in the case of **breadth-first search**). In either case, one can form a **spanning tree** by connecting each vertex, other than the root vertex *v*, to the vertex from which it was discovered. This tree is known as a **depth-first search tree** or a **breadth-first search tree** according to the graph exploration algorithm used to construct it.[[18\]](https://en.wikipedia.org/wiki/Spanning_tree#cite_note-18) Depth-first search trees are a special case of a class of spanning trees called [Trémaux trees](https://en.wikipedia.org/wiki/Trémaux_tree), named after the 19th-century discoverer of **depth-first search**.

> NOTE:
>
> 一、其实就是traverse graph的过程 

#### BFS



#### DFS



### Optimization(Minimum-spanning-tree)

参见 `Minimum-spanning-tree` 章节。

