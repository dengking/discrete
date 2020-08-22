# Dijkstra's algorithm



## 维基百科[Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm)

The algorithm exists in many variants. Dijkstra's original algorithm found the shortest path between two given nodes,[[5\]](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#cite_note-Dijkstra1959-5) but a more common variant fixes a single node as the "source" node and finds shortest paths from the source to all other nodes in the graph, producing a [shortest-path tree](https://en.wikipedia.org/wiki/Shortest-path_tree).

> NOTE: single source

The Dijkstra algorithm uses labels that are positive integers or real numbers, which are [totally ordered](https://en.wikipedia.org/wiki/Total_order). It can be generalized to use any labels that are [partially ordered](https://en.wikipedia.org/wiki/Partially_ordered_set), provided the subsequent labels (a subsequent label is produced when traversing an edge) are [monotonically](https://en.wikipedia.org/wiki/Monotonic_function) non-decreasing. This generalization is called the generic Dijkstra shortest-path algorithm.[[7\]](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#cite_note-Generic_Dijkstra-7)

> NOTE: label的含义是什么？

