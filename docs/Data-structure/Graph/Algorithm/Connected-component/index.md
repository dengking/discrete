# Connected component

素材:

一、和connected component密切相关的内容:

1、transitive closure:

将relation使用graph来进行表示，对于具备transitive性质的relation，对relation计算transitive closure，显然每个closure对应一个connected component

2、disjoint-set(union-find-set): disjoint-set中的set正好和connected-component相对应

3、[partition of set](https://en.wikipedia.org/wiki/Partition_of_a_set)、[equivalence relation](https://en.wikipedia.org/wiki/Equivalence_relation) 



总结:

一、transitive closure VS disjoint-set (从set、relation、graph角度进行分析)

a、transitive closure是求解各个connected component的，如果输入已经是graph了，那么使用这个算法会比较方便

b、disjoint-set(union-find-set)用于快速判断两个node是否属于同一个component，如果输入是discrete的，那么使用它会比较方便



## wikipedia [Component (graph theory)](https://en.wikipedia.org/wiki/Component_(graph_theory))



## wikipedia [Dynamic connectivity](https://en.wikipedia.org/wiki/Dynamic_connectivity)



