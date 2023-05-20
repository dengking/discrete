# Kruskal's algorithm



## wikipedia [Kruskal's algorithm](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm)

**Kruskal's algorithm**[[1\]](https://en.wikipedia.org/wiki/Kruskal's_algorithm#cite_note-1) finds a [minimum spanning forest](https://en.wikipedia.org/wiki/Minimum_spanning_tree) of an undirected [edge-weighted graph](https://en.wikipedia.org/wiki/Weighted_graph). If the graph is [connected](https://en.wikipedia.org/wiki/Connectivity_(graph_theory)), it finds a [minimum spanning tree](https://en.wikipedia.org/wiki/Minimum_spanning_tree). (A minimum spanning tree of a connected graph is a subset of the [edges](https://en.wikipedia.org/wiki/Edge_(graph_theory)) that forms a tree that includes every [vertex](https://en.wikipedia.org/wiki/Vertex_(graph_theory)), where the sum of the [weights](https://en.wikipedia.org/wiki/Weighted_graph) of all the edges in the tree is minimized. For a disconnected graph, a minimum spanning forest is composed of a minimum spanning tree for each [connected component](https://en.wikipedia.org/wiki/Connected_component_(graph_theory)).) It is a [greedy algorithm](https://en.wikipedia.org/wiki/Greedy_algorithm) in [graph theory](https://en.wikipedia.org/wiki/Graph_theory) as in each step it adds the next lowest-weight edge that will not form a [cycle](https://en.wikipedia.org/wiki/Cycle_(graph_theory)) to the minimum spanning forest.

