# Graph traversal

这是解决各种graph问题的基础。

## wikipedia [Graph traversal](https://en.wikipedia.org/wiki/Graph_traversal)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **graph traversal** (also known as **graph search**) refers to the process of visiting (checking and/or updating) each vertex in a [graph](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)). Such traversals are classified by the order in which the vertices are visited. [Tree traversal](https://en.wikipedia.org/wiki/Tree_traversal) is a special case of graph traversal.

> NOTE: 
>
> 1、其实traversal就是search

### Redundancy

Unlike tree traversal, graph traversal may require that some vertices be visited more than once, since it is not necessarily known before transitioning to a vertex that it has already been explored. As graphs become more [dense](https://en.wikipedia.org/wiki/Dense_graph), this redundancy becomes more prevalent(普遍), causing computation time to increase; as graphs become more sparse, the opposite holds true.

> NOTE: 
>
> 1、dense and sparse

Thus, it is usually necessary to remember which vertices have already been explored by the algorithm, so that vertices are revisited as infrequently as possible (or in the worst case, to prevent the traversal from continuing indefinitely(其实就是**dead loop**)). This may be accomplished by associating each vertex of the graph with a "color" or "visitation" state during the traversal, which is then checked and updated as the algorithm visits each vertex. If the vertex has already been visited, it is ignored and the path is pursued(追踪) no further; otherwise, the algorithm checks/updates the vertex and continues down its current path.

> NOTE: 
>
> 1、在graph traversal中，为了避免由于circle而导致的dead loop，graph traversal algorithm普遍采用的是“标记已经visit过的vertex，对于已经visit过的vertex，再次遇到的时候，直接pass掉”。

Several special cases of graphs imply(蕴含) the visitation of other vertices in their structure, and thus do not require that visitation be explicitly recorded during the traversal. An important example of this is a tree: during a traversal it may be assumed that all "ancestor" vertices of the current vertex (and others depending on the algorithm) have already been visited. Both the [depth-first](https://en.wikipedia.org/wiki/Depth-first_search) and [breadth-first graph searches](https://en.wikipedia.org/wiki/Breadth-first_search) are adaptations of tree-based algorithms, distinguished primarily by the lack of a structurally determined "root" vertex and the addition of a data structure to record the traversal's visitation state.

> NOTE: 
>
> 1、翻译如下:
>
> "图的一些特殊情况暗示了对其结构中的其他顶点的访问，因此不需要在遍历过程中明确地记录访问。
> 一个重要的例子是树:在遍历过程中，可以假设当前顶点的所有“祖先”顶点(以及其他取决于算法的顶点)都已经访问过了。
> 深度优先和宽度优先图搜索都是基于树的算法的适应，主要区别在于缺乏一个结构上确定的“根”顶点和添加一个数据结构来记录遍历的访问状态。"

### Graph traversal algorithms



#### Depth-first search

*Main article:* [Depth-first search](https://en.wikipedia.org/wiki/Depth-first_search)

> NOTE: 
>
> 1、参见`Depth-first search-DFS`章节

#### Breadth-first search

*Main article:* [Breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search)

> NOTE: 
>
> 1、参见`Breadth-first-search-BFS`章节



## Graph traversal and circle

1、graph的结构是比tree要复杂的，所以相比于tree它能够表达更多的relation；

2、graph是允许circle，因此在各种algorithm中，需要对circle进行特殊处理。

3、graph是运行disconnect。



## Visited array

1、在graph traversal中，为了避免由于circle而导致的dead loop，graph traversal algorithm普遍采用的是“标记已经visit过的vertex，对于已经visit过的vertex，再次遇到的时候，直接pass掉”。

2、对于graph中的一个node，可能有多条path通向它，在对它进行traverse的时候，为了避免重复，因此需要标注它是否已经被访问了。

> NOTE: 
>
> 1、在tree中，到达一个node，仅仅只有一条path，这是唯一的。

3、采用哪种标注策略呢？

对于采用recursive implementation，由于它本身就是深度优先的，因此，它的标准策略是非常简单的；

对于采用iterative implementation，因此，需要由programmer进行控制:

a、对于depth-first: 如果current node没有被标注，则将它的所有的descendant全部都push到explicit stack中后，才算这个node被visit了

b、对于breadth-first: 对于current node的所有的descendant，只要没有被标准，就enqueue。

4、将它标注为visited，就相当于在tree traversal中，调用了visit function。



### 两种往visited array中添加节点的方式

1、先判断是否visited，如果是，则不入queue

"leetcode [752. 打开转盘锁](https://leetcode-cn.com/problems/open-the-lock/) 中等 # 我的解"题中，就是采用的这种方式

2、先入queue，然后再入visited

"leetcode[【中规中矩】752. 打开转盘锁（宽度优先搜索）](https://leetcode-cn.com/problems/open-the-lock/solution/zhong-gui-zhong-ju-kuan-du-you-xian-sou-suo-by-jyj/) "中，就是使用的这种方式

## Graph traversal VS tree traversal



### Depth first traversal

Tree的depth first traversal是较复杂的，它分为preorder、inorder、postorder；

Graph的depth first traversal是非常简单的，它采用的是类似于preorder的策略；

可以看到，graph的depth-first traversal和tree的preorder traversal是非常类似的。



## Graph traversal and topological sorting

Graph traversal 是实现 topological sorting 的基础。

Topological sorting 和 Breadth-first search 是非常类似的: 不同level之间存在着 hierarchy 。



## Backtrace and Branch-and-Bound

Backtrace 对应的是 depth-first ；

Branch-and-Bound 对应的是 width-first ；



## BFS VS DFS

### What are the advantages of breadth-first search (BFS) over depth-first search (DFS)? 

Answer: BFS is complete and optimal, while DFS is not guaranteed to halt when there are loops. 

> NOTE: DFS的loop问题是可以避免的

### What is the advantage of DFS over BFS?

 Answer: If `m` is the maximum path length and `b` is the branching factor, the space complexity for DFS is `mb` while for BFS it is $b^m$.