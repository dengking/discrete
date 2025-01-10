# Resolving Algorithm

最常使用的就是topological sorting，下面是一些素材:

electricmonk [Dependency Resolving Algorithm](https://www.electricmonk.nl/docs/dependency_resolving_algorithm/dependency_resolving_algorithm.html)

stackoverflow [Algorithm for dependency resolution](https://stackoverflow.com/questions/28099683/algorithm-for-dependency-resolution)

## Feedback arc set

‌**Feedback arc set（FAS）**‌是指在有向图中，通过移除某些边使得图中不再包含环的边集。具体来说，给定一个有向图[G=(V,E)](https://www.baidu.com/s?rsv_dl=re_dqa_generate&sa=re_dqa_generate&wd=G%3D(V%2CE)&rsv_pq=a9444cb3015bef34&oq=Feedback arc set&rsv_t=cc06+5QXHFVPjYntK2ttcTJGzjT6Ky+TCMaBZfkD9etWuDeWgPtfquQNef0&tn=baidu&ie=utf-8)，一个子集[E'](https://www.baidu.com/s?rsv_dl=re_dqa_generate&sa=re_dqa_generate&wd=E'&rsv_pq=a9444cb3015bef34&oq=Feedback arc set&rsv_t=cc06+5QXHFVPjYntK2ttcTJGzjT6Ky+TCMaBZfkD9etWuDeWgPtfquQNef0&tn=baidu&ie=utf-8)被称为FAS，如果移除[E'](https://www.baidu.com/s?rsv_dl=re_dqa_generate&sa=re_dqa_generate&wd=E'&rsv_pq=a9444cb3015bef34&oq=Feedback arc set&rsv_t=cc06+5QXHFVPjYntK2ttcTJGzjT6Ky+TCMaBZfkD9etWuDeWgPtfquQNef0&tn=baidu&ie=utf-8)中的边后，图G变为无环图。FAS问题可以形式化为：给定一个有向图G和预算b，找到一个大小为等于或小于b的FAS，如果存在的话‌1。

### FAS问题的NP-完全性

FAS问题被证明是NP-完全的，可以通过[顶点覆盖问题](https://www.baidu.com/s?rsv_dl=re_dqa_generate&sa=re_dqa_generate&wd=顶点覆盖问题&rsv_pq=a9444cb3015bef34&oq=Feedback arc set&rsv_t=cc06+5QXHFVPjYntK2ttcTJGzjT6Ky+TCMaBZfkD9etWuDeWgPtfquQNef0&tn=baidu&ie=utf-8)进行归约证明。具体来说：

1. ‌**FAS属于NP**‌：对于给定的有向图G和预算b，可以在多项式时间内验证一个边集是否为FAS。
2. ‌**FAS问题可以归约到顶点覆盖问题**‌：如果图G包含一个大小为b的顶点覆盖，则可以通过构造一个新图G'来找到一个大小为b的FAS。反之亦然，如果图G'包含一个大小为b的FAS，则图G包含一个大小不超过b的顶点覆盖‌1。

### FAS问题的应用场景

FAS问题在算法设计和优化中有着广泛的应用。例如：

- ‌**[排名问题](https://www.baidu.com/s?rsv_dl=re_dqa_generate&sa=re_dqa_generate&wd=排名问题&rsv_pq=a9444cb3015bef34&oq=Feedback arc set&rsv_t=cc06+5QXHFVPjYntK2ttcTJGzjT6Ky+TCMaBZfkD9etWuDeWgPtfquQNef0&tn=baidu&ie=utf-8)**‌：在从成对比较中推导出全局排名时，FAS问题与最小加权反馈弧集问题密切相关。通过解决FAS问题，可以高效地处理排名问题，并提高排名的准确性‌2。
- ‌**[竞赛图理论](https://www.baidu.com/s?rsv_dl=re_dqa_generate&sa=re_dqa_generate&wd=竞赛图理论&rsv_pq=a9444cb3015bef34&oq=Feedback arc set&rsv_t=cc06+5QXHFVPjYntK2ttcTJGzjT6Ky+TCMaBZfkD9etWuDeWgPtfquQNef0&tn=baidu&ie=utf-8)**‌：在竞赛图中，FAS问题用于确定移除哪些边可以使图变为无环图，这在竞赛理论和分析中非常重要‌3。



### wikipedia [Feedback arc set](https://en.wikipedia.org/wiki/Feedback_arc_set) 

In [graph theory](https://en.wikipedia.org/wiki/Graph_theory) and [graph algorithms](https://en.wikipedia.org/wiki/Graph_algorithm), a **feedback arc set** or **feedback edge set** in a [directed graph](https://en.wikipedia.org/wiki/Directed_graph) is a subset of the edges of the graph that contains at least one edge out of every cycle in the graph. Removing these edges from the graph breaks all of the cycles, producing an **acyclic subgraph** of the given graph, often called a [directed acyclic graph](https://en.wikipedia.org/wiki/Directed_acyclic_graph). A feedback arc set with the fewest possible edges is a **minimum feedback arc set** and its removal leaves a **maximum acyclic subgraph**; weighted versions of these [optimization problems](https://en.wikipedia.org/wiki/Optimization_problem) are also used.

 

Feedback arc sets have applications in circuit analysis, [chemical engineering](https://en.wikipedia.org/wiki/Chemical_engineering), [deadlock](https://en.wikipedia.org/wiki/Deadlock_(computer_science)) resolution, [ranked voting](https://en.wikipedia.org/wiki/Ranked_voting), ranking competitors in sporting events, [mathematical psychology](https://en.wikipedia.org/wiki/Mathematical_psychology), [ethology](https://en.wikipedia.org/wiki/Ethology), and [graph drawing](https://en.wikipedia.org/wiki/Graph_drawing).



