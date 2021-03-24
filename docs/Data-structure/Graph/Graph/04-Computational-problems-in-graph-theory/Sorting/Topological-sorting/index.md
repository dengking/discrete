# Topological sorting

一、[207. 课程表](https://leetcode-cn.com/problems/course-schedule/) # [力扣官方题解](https://leetcode-cn.com/problems/course-schedule/solution/ke-cheng-biao-by-leetcode-solution/)

1、如果图 `G` 中存在环（即图 `G` 不是「有向无环图」），那么图 `G` 不存在拓扑排序。

这是因为假设图中存在环 $x_1, x_2, \cdots, x_n, x_1$ ，那么 $x_1$ 在排列中必须出现在 $x_n$的前面，但 $x_n$ 同时也必须出现在 $x_1$  的前面，因此不存在一个满足要求的排列，也就不存在拓扑排序；

2、如果图 $G$ 是有向无环图，那么它的拓扑排序可能不止一种。举一个最极端的例子，如果图 $G$ 值包含 $n$ 个节点却没有任何边，那么任意一种编号的排列都可以作为拓扑排序。

二、



## wikipedia [Topological sorting](https://en.wikipedia.org/wiki/Topological_sorting)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **topological sort** or **topological ordering** of a [directed graph](https://en.wikipedia.org/wiki/Directed_graph) is a [linear ordering](https://en.wikipedia.org/wiki/Total_order) of its [vertices](https://en.wikipedia.org/wiki/Vertex_(graph_theory)) such that for every directed edge *uv* from vertex *u* to vertex *v*, *u* comes before *v* in the ordering. 

> NOTE: 
> 1、linear ordering是一个logical structure

For instance, the vertices of the graph may represent tasks to be performed, and the edges may represent constraints that one task must be performed before another; in this application, a topological ordering is just a valid sequence for the tasks. 

> NOTE: 
> 1、上述是典型的dependency graph

A topological ordering is possible if and only if the graph has no [directed cycles](https://en.wikipedia.org/wiki/Directed_cycle), that is, if it is a [directed acyclic graph](https://en.wikipedia.org/wiki/Directed_acyclic_graph) (DAG). Any DAG has at least one topological ordering, and [algorithms](https://en.wikipedia.org/wiki/Algorithm) are known for constructing a topological ordering of any DAG in [linear time](https://en.wikipedia.org/wiki/Linear_time). Topological sorting has many applications especially in ranking problems such as [feedback arc set](https://en.wikipedia.org/wiki/Feedback_arc_set).



## Implementation

github [Algo-Tree](https://github.com/Algo-Phantoms/Algo-Tree)/[Code](https://github.com/Algo-Phantoms/Algo-Tree/tree/main/Code)/[C++](https://github.com/Algo-Phantoms/Algo-Tree/tree/main/Code/C%2B%2B)/[Topological_sort.cpp](https://github.com/Algo-Phantoms/Algo-Tree/blob/main/Code/C%2B%2B/Topological_sort.cpp)

