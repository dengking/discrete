# Connected component

素材:

一、和connected component密切相关的内容:

1、transitive closure是关联的概念:

将relation使用graph来进行表示，对于具备transitive性质的relation，对relation计算transitive closure，显然每个closure对应一个connected component

2、disjoint-set(union-find-set)

3、[partition of set](https://en.wikipedia.org/wiki/Partition_of_a_set)、[equivalence relation](https://en.wikipedia.org/wiki/Equivalence_relation) 

总结:

从多个角度对同一个问题进行分析: 从set、relation、graph

a、transitive closure是求解各个connected component

b、disjoint-set(union-find-set)用于快速判断两个node是否属于同一个component



## wikipedia [Component (graph theory)](https://en.wikipedia.org/wiki/Component_(graph_theory))



## wikipedia [Dynamic connectivity](https://en.wikipedia.org/wiki/Dynamic_connectivity)



## wikipedia [Disjoint-set data structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure)



Disjoint-set data structures play a key role in [Kruskal's algorithm](https://en.wikipedia.org/wiki/Kruskal's_algorithm) for finding the [minimum spanning tree](https://en.wikipedia.org/wiki/Minimum_spanning_tree) of a graph.

> NOTE:
>
> minimal spanning tree的一个非常重要的operation就是判断一个node是否已经属于spanning-tree，这种operation正是disjoint-set的find操作。
