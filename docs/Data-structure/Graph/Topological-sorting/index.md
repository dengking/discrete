# Topological sorting

## LeetCode [207. 课程表](https://leetcode-cn.com/problems/course-schedule/) # [力扣官方题解](https://leetcode-cn.com/problems/course-schedule/solution/ke-cheng-biao-by-leetcode-solution/)

> NOTE: 
>
> 一、原文给出了两种算法:DFS和BFS，相比之下，BFS是更加容易理解的，因为它是符合我们直接进行topological sorting的顺序的
>
> 二、首先需要根据 `prerequisites` 数组构建出dependency graph，这样能够找到它的相邻节点，原味给出的解法中都是使用的**adjacent list**
>
> 



1、如果图 `G` 中存在环（即图 `G` 不是「有向无环图」），那么图 `G` 不存在**拓扑排序**。

这是因为假设图中存在环 $x_1, x_2, \cdots, x_n, x_1$ ，那么 $x_1$ 在排列中必须出现在 $x_n$的前面，但 $x_n$ 同时也必须出现在 $x_1$  的前面，因此不存在一个满足要求的排列，也就不存在拓扑排序；

> NOTE: 
>
> 一、上述使用的是反证法: 自相矛盾
>
> 二、在实现topological sorting的时候，一个非常重要的问题是circle，一旦有circle则无法进行topological sorting

2、如果图 $G$ 是有向无环图，那么它的拓扑排序可能不止一种。举一个最极端的例子，如果图 $G$ 值包含 $n$ 个节点却没有任何边，那么任意一种编号的排列都可以作为拓扑排序。



### 方法二: 广度优先搜索

> NOTE: 
>
> 一、使用 "入度" 和 "长度"概念来进行理解:
>
> 1、一个node，如果它的 "入度"  为0，则表示它没有依赖其他节点
>
> 2、一个node，如果它的 "出度"  为0，则表示没有其它节点依赖它
>
> 其实只需要入度即可: 某个节点的入度如果非0，则表示它存在依赖

上面的想法类似于**广度优先搜索**，因此我们可以将**广度优先搜索**的流程与**拓扑排序**的求解联系起来。



## 算法思想

1、找到没有被依赖的

2、使用dependency relation构建的structure，如果能够进行**topological sorting**，则会形成**hierarchy structure**。

3、沿着relation的分析不断地向下寻找，直到找到一个没有任何依赖的

4、应该是depth first search

5、这让我想起了topological sorting中，找到没有任何依赖的那个节点，然后反向不断地删减；其实，它和析构一个linked list是非常类似的，它们本质上都是对依赖关系的删除



## wikipedia [Topological sorting](https://en.wikipedia.org/wiki/Topological_sorting)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **topological sort** or **topological ordering** of a [directed graph](https://en.wikipedia.org/wiki/Directed_graph) is a [linear ordering](https://en.wikipedia.org/wiki/Total_order) of its [vertices](https://en.wikipedia.org/wiki/Vertex_(graph_theory)) such that for every directed edge *uv* from vertex *u* to vertex *v*, *u* comes before *v* in the ordering. 

> NOTE: 
> 1、linear ordering是一个logical structure

For instance, the vertices of the graph may represent tasks to be performed, and the edges may represent constraints that one task must be performed before another; in this application, a topological ordering is just a valid sequence for the tasks. 

> NOTE: 
> 1、上述是典型的dependency graph

A topological ordering is possible if and only if the graph has no [directed cycles](https://en.wikipedia.org/wiki/Directed_cycle), that is, if it is a [directed acyclic graph](https://en.wikipedia.org/wiki/Directed_acyclic_graph) (DAG). Any DAG has at least one topological ordering, and [algorithms](https://en.wikipedia.org/wiki/Algorithm) are known for constructing a topological ordering of any DAG in [linear time](https://en.wikipedia.org/wiki/Linear_time). Topological sorting has many applications especially in ranking problems such as [feedback arc set](https://en.wikipedia.org/wiki/Feedback_arc_set).



## labuladong [拓扑排序，YYDS！](https://mp.weixin.qq.com/s/7nP92FhCTpTKIAplj_xWpA)



## Implementation

github [Algo-Tree](https://github.com/Algo-Phantoms/Algo-Tree)/[Code](https://github.com/Algo-Phantoms/Algo-Tree/tree/main/Code)/[C++](https://github.com/Algo-Phantoms/Algo-Tree/tree/main/Code/C%2B%2B)/[Topological_sort.cpp](https://github.com/Algo-Phantoms/Algo-Tree/blob/main/Code/C%2B%2B/Topological_sort.cpp)



## LeetCode 课程表
https://leetcode-cn.com/problems/course-schedule/solution/ke-cheng-biao-by-leetcode-solution/

https://leetcode-cn.com/problems/course-schedule-ii/solution/ke-cheng-biao-ii-by-leetcode-solution/


https://leetcode-cn.com/problems/course-schedule-iv/





​																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																			

## TODO

jianshu [拓扑排序(一)——有向图成环检测](https://www.jianshu.com/p/d6042b659f70)

csdn [[ZZ]如何判断有向图是否成环](https://blog.csdn.net/leonsc/article/details/5973209)

csdn [数据结构 图 有向无环图](https://blog.csdn.net/nomad2/article/details/1559664)

csdn [拓扑排序判断有向图是否成环](https://blog.csdn.net/qq_40642465/article/details/80670269)

