# Disjoint-set data structure、union–find data structure





## wanweibaike [Disjoint-set data structure](https://en.wanweibaike.com/wiki-Union%20find) 

In [computer science](https://en.wanweibaike.com/wiki-Computer_science), a **disjoint-set data structure**, also called a **union–find data structure** or **merge–find set**, is a data structure that stores a collection of [disjoint](https://en.wanweibaike.com/wiki-Disjoint_sets) (non-overlapping) sets. Equivalently, it stores a [partition of a set](https://en.wanweibaike.com/wiki-Partition_of_a_set) into disjoint subsets. It provides operations for adding new sets, merging sets (replacing them by their [union](https://en.wanweibaike.com/wiki-Union_(set_theory))), and finding a representative member of a set. The last operation allows to find out efficiently if any two elements are in the same or different sets.

Disjoint-set data structures play a key role in [Kruskal's algorithm](https://en.wanweibaike.com/wiki-Kruskal's_algorithm) for finding the [minimum spanning tree](https://en.wanweibaike.com/wiki-Minimum_spanning_tree) of a graph. The importance of minimum spanning trees means that disjoint-set data structures underlie a wide variety of algorithms. In addition, disjoint-set data structures also have applications to symbolic computation, as well in compilers, especially for [register allocation](https://en.wanweibaike.com/wiki-Register_allocation) problems.



### Applications

Disjoint-set data structures model the [partitioning of a set](https://en.wanweibaike.com/wiki-Partition_of_a_set), for example to keep track of the [connected components](https://en.wanweibaike.com/wiki-Connected_component_(graph_theory)) of an [undirected graph](https://en.wanweibaike.com/wiki-Undirected_graph). This model can then be used to determine whether two vertices belong to the same component, or whether adding an edge between them would result in a cycle. The Union–Find algorithm is used in high-performance implementations of [unification](https://en.wanweibaike.com/wiki-Unification_(computer_science)).[[15\]](https://en.wanweibaike.com/wiki-Union find#cite_note-Knight1989-15)

This data structure is used by the [Boost Graph Library](https://en.wanweibaike.com/wiki-Boost_Graph_Library) to implement its [Incremental Connected Components](http://www.boost.org/libs/graph/doc/incremental_components.html) functionality. It is also a key component in implementing [Kruskal's algorithm](https://en.wanweibaike.com/wiki-Kruskal's_algorithm) to find the [minimum spanning tree](https://en.wanweibaike.com/wiki-Minimum_spanning_tree) of a graph.

Note that the implementation as disjoint-set forests doesn't allow the deletion of edges, even without path compression or the rank heuristic.

Sharir and Agarwal report connections between the worst-case behavior of disjoint-sets and the length of [Davenport–Schinzel sequences](https://en.wanweibaike.com/wiki-Davenport–Schinzel_sequence), a combinatorial structure from computational geometry.[[16\]](https://en.wanweibaike.com/wiki-Union find#cite_note-Sharir1995-16)



## baike [并查集](https://baike.baidu.com/item/%E5%B9%B6%E6%9F%A5%E9%9B%86/9388442?fr=aladdin)



## zhuanlan.zhihu [算法学习笔记(1) : 并查集](https://zhuanlan.zhihu.com/p/93647900/)





## LeetCode

https://leetcode-cn.com/tag/union-find/problemset/