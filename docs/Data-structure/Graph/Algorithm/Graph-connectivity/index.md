# Connectivity &Connected-component&Transitive-closure



## wikipedia [Connectivity (graph theory)](https://en.wikipedia.org/wiki/Connectivity_(graph_theory))



## Dynamic connectivity

---

> Reference:
>
> [stanford-CS166-Graph connectivity](https://web.stanford.edu/class/cs166/)  

---



### wikipedia [Dynamic connectivity](https://en.wikipedia.org/wiki/Dynamic_connectivity)

In [computing](https://en.wikipedia.org/wiki/Computing) and [graph theory](https://en.wikipedia.org/wiki/Graph_theory), a **dynamic connectivity** structure is a data structure that dynamically maintains information about the connected components of a graph.

The set *V* of vertices of the graph is fixed, but the set *E* of edges can change. The three cases, in order of difficulty, are:

- Edges are only added to the graph (this can be called *incremental connectivity*);
- Edges are only deleted from the graph (this can be called *decremental connectivity*);
- Edges can be either added or deleted (this can be called *fully dynamic connectivity*).

After each addition/deletion of an edge, the dynamic connectivity structure should adapt 



## Connected component&Transitive-closure

一、计算所有的connected component

1、transitive closure:

将relation使用graph来进行表示，对于具备transitive性质的relation，对relation计算transitive closure，显然每个closure对应一个connected component

2、disjoint-set(union-find-set): disjoint-set中的set正好和connected-component相对应

3、[partition of set](https://en.wikipedia.org/wiki/Partition_of_a_set)、[equivalence relation](https://en.wikipedia.org/wiki/Equivalence_relation) 



总结: transitive closure VS disjoint-set (从set、relation、graph角度进行分析)

a、transitive closure是求解各个connected component的，如果输入已经是graph了，那么使用这个算法会比较方便

b、disjoint-set(union-find-set)用于快速判断两个node是否属于同一个component，如果输入是discrete的，那么使用它会比较方便



二、connected-component-labeling

三、connected-component-border

### wikipedia [Component (graph theory)](https://en.wikipedia.org/wiki/Component_(graph_theory))



