# Kruskal's algorithm



## wikipedia [Kruskal's algorithm](https://en.wikipedia.org/wiki/Kruskal%27s_algorithm)

**Kruskal's algorithm**[[1\]](https://en.wikipedia.org/wiki/Kruskal's_algorithm#cite_note-1) finds a [minimum spanning forest](https://en.wikipedia.org/wiki/Minimum_spanning_tree) of an undirected [edge-weighted graph](https://en.wikipedia.org/wiki/Weighted_graph). 

If the graph is [connected](https://en.wikipedia.org/wiki/Connectivity_(graph_theory)), it finds a [minimum spanning tree](https://en.wikipedia.org/wiki/Minimum_spanning_tree). (A minimum spanning tree of a connected graph is a subset of the [edges](https://en.wikipedia.org/wiki/Edge_(graph_theory)) that forms a tree that includes every [vertex](https://en.wikipedia.org/wiki/Vertex_(graph_theory)), where the sum of the [weights](https://en.wikipedia.org/wiki/Weighted_graph) of all the edges in the tree is minimized. 

For a disconnected graph, a minimum spanning forest is composed of a minimum spanning tree for each [connected component](https://en.wikipedia.org/wiki/Connected_component_(graph_theory)).) 

It is a [greedy algorithm](https://en.wikipedia.org/wiki/Greedy_algorithm) in [graph theory](https://en.wikipedia.org/wiki/Graph_theory) as in each step it adds the next lowest-weight edge that will not form a [cycle](https://en.wikipedia.org/wiki/Cycle_(graph_theory)) to the **minimum spanning forest**.

> NOTE:
>
> 一、
>
> 1、undirected
>
> 2、forest
>
> 3、connected、disconnected
>
> 4、edge-driven



### Algorithm

1、create a forest *F* (a set of trees), where each vertex in the graph is a separate [tree](https://en.wikipedia.org/wiki/Tree_(graph_theory))

2、create a sorted set *S* containing all the edges in the graph

3、while *S* is [nonempty](https://en.wikipedia.org/wiki/Nonempty) and *F* is not yet [spanning](https://en.wikipedia.org/wiki/Spanning_tree)

- remove an edge with minimum weight from *S*
- if the removed edge connects two different trees then add it to the forest *F*, combining two trees into a single tree



### Pseudocode

The following code is implemented with a [disjoint-set data structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure). Here, we represent our forest *F* as a set of edges, and use the disjoint-set data structure to efficiently determine whether two vertices are part of the same tree.

```pseudocode
algorithm Kruskal(G) is
    F:= ∅
    for each v ∈ G.V do
        MAKE-SET(v)
    for each (u, v) in G.E ordered by weight(u, v), increasing do
        if FIND-SET(u) ≠ FIND-SET(v) then
            F:= F ∪ {(u, v)} ∪ {(v, u)}
            UNION(FIND-SET(u), FIND-SET(v))
    return F
```



## LeetCode



[LeetCode-1489. Find Critical and Pseudo-Critical Edges in Minimum Spanning Tree-中等](https://leetcode.cn/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/)

[LeetCode-1584. Min Cost to Connect All Points-中等](https://leetcode.cn/problems/min-cost-to-connect-all-points/)

