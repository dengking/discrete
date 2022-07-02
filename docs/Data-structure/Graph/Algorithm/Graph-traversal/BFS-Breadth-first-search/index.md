# Breadth-first search



## wikipedia [Breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search)

**Breadth-first search** (**BFS**) is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) for traversing or searching [tree](https://en.wikipedia.org/wiki/Tree_(data_structure)) or [graph](https://en.wikipedia.org/wiki/Graph_(data_structure)) data structures. It starts at the [tree root](https://en.wikipedia.org/wiki/Tree_(data_structure)#Terminology) (or some arbitrary node of a graph, sometimes referred to as a 'search key'[[1\]](https://en.wikipedia.org/wiki/Breadth-first_search#cite_note-1)), and explores all of the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.

> NOTE: 
>
> 1、"level"让我想到了hierarchy

### Pseudocode

**Input**: A graph *G* and a *starting vertex* *root* of *G*

**Output**: Goal state. The *parent* links trace the shortest path back to *root*[[7\]](https://en.wikipedia.org/wiki/Breadth-first_search#cite_note-7)

```pseudocode
 1  procedure BFS(G, root) is
 2      let Q be a queue
 3      label root as discovered
 4      Q.enqueue(root)
 5      while Q is not empty do
 6          v := Q.dequeue()
 7          if v is the goal then
 8              return v
 9          for all edges from v to w in G.adjacentEdges(v) do
10              if w is not labeled as discovered then
11                  label w as discovered
12                  Q.enqueue(w)
```



### Applications

Breadth-first search can be used to solve many problems in graph theory, for example:

- Copying [garbage collection](https://en.wikipedia.org/wiki/Garbage_collection_(computer_science)), [Cheney's algorithm](https://en.wikipedia.org/wiki/Cheney's_algorithm)
- Finding the [shortest path](https://en.wikipedia.org/wiki/Shortest_path) between two nodes *u* and *v*, with path length measured by number of edges (an advantage over [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search))[[12\]](https://en.wikipedia.org/wiki/Breadth-first_search#cite_note-12)
- [(Reverse) Cuthill–McKee](https://en.wikipedia.org/wiki/Cuthill–McKee_algorithm) mesh numbering
- [Ford–Fulkerson method](https://en.wikipedia.org/wiki/Ford–Fulkerson_algorithm) for computing the [maximum flow](https://en.wikipedia.org/wiki/Maximum_flow_problem) in a [flow network](https://en.wikipedia.org/wiki/Flow_network)
- Serialization/Deserialization of a binary tree vs serialization in sorted order, allows the tree to be re-constructed in an efficient manner.
- Construction of the *failure function* of the [Aho-Corasick](https://en.wikipedia.org/wiki/Aho-Corasick) pattern matcher.
- Testing [bipartiteness of a graph](https://en.wikipedia.org/wiki/Bipartite_graph#Testing_bipartiteness).

## geeksforgeeks [Depth First Search or DFS for a Graph](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)


