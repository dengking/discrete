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



#### Breadth-first search

*Main article:* [Breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search)



## BFS

---

> References: 
>
> - wikipedia [Breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search) 
>
> - labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 
>
> 

---



### wikipedia [Breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search) 

**Breadth-first search** (**BFS**) is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) for traversing or searching [tree](https://en.wikipedia.org/wiki/Tree_(data_structure)) or [graph](https://en.wikipedia.org/wiki/Graph_(data_structure)) data structures. It starts at the [tree root](https://en.wikipedia.org/wiki/Tree_(data_structure)#Terminology) (or some arbitrary node of a graph, sometimes referred to as a 'search key'[[1\]](https://en.wikipedia.org/wiki/Breadth-first_search#cite_note-1)), and explores all of the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.

> NOTE: 
>
> 1、"level"让我想到了hierarchy

#### Pseudocode

**Input**: A graph *G* and a *starting vertex* *root* of *G*

**Output**: Goal state. The *parent* links trace the shortest path back to *root*[[7\]](https://en.wikipedia.org/wiki/Breadth-first_search#cite_note-7)

```pseudocode
 1  procedure BFS(G, root) is
 2      let Q be a queue
 3      label root as discovered
 4      Q.enqueue(root)
 5      while Q is not empty do
 6          v := Q.dequeue()
 7          if v is the goal then
 8              return v
 9          for all edges from v to w in G.adjacentEdges(v) do
10              if w is not labeled as discovered then
11                  label w as discovered
12                  Q.enqueue(w)
```

### Code

```python
import unittest
from collections import deque
from typing import Dict, List, Callable


class DirectedUnweightedGraphInAdjacencyList:
    """
    1、以adjacency list实现directed unweighted graph
    2、https://www.python.org/doc/essays/graphs/
    """

    def __init__(self, graph: Dict[str, List[str]]):
        self.graph = graph

    def bfs1(self, start: str, visitor: Callable = print) -> List[str]:
        """

        :param visitor:
        :param start:
        :return:
        """
        q = deque()
        visited_set = set()
        visited_nodes = []

        q.append(start)
        visited_set.add(start)
        while q:
            size = len(q)
            for _ in range(size):
                node = q.popleft()
                visitor(node)
                visited_nodes.append(node)
                for adj_node in filter(lambda adj_node: adj_node not in visited_set, self.graph[node]):
                    q.append(adj_node)
                    visited_set.add(adj_node)
        return visited_nodes

    def bfs2(self, start: str) -> List[str]:
        # Create a queue and enqueue the starting node
        queue = deque([start])
        # This list will keep track of all visited nodes
        visited = []
        # Loop as long as there are nodes in the queue
        while queue:
            # Dequeue a node from the queue
            current_node = queue.popleft()
            # If the node has not been visited, add it to the visited list
            if current_node not in visited:
                visited.append(current_node)
                # Enqueue all neighboring nodes
                for neighbor in self.graph[current_node]:
                    queue.append(neighbor)

        # Return the list of visited nodes
        return visited


class TestBFSAlgorithm(unittest.TestCase):
    def test_shortest_path_to_all_node(self):
        # Graph represented as an adjacency list
        graph = {
            'A': ['B', 'C'],
            'B': ['D', 'E'],
            'C': ['F'],
            'D': [],
            'E': ['F'],
            'F': []
        }
        directed_unweighted_graph_in_adj_list = DirectedUnweightedGraphInAdjacencyList(graph)
        source = 'A'
        nodes1 = directed_unweighted_graph_in_adj_list.bfs1(source)
        nodes2 = directed_unweighted_graph_in_adj_list.bfs2(source)
        self.assertEqual(len(nodes1), 6)
        self.assertEqual(nodes1, ['A', 'B', 'C', 'D', 'E', 'F'])
        self.assertEqual(nodes1, nodes2)


if __name__ == '__main__':
    unittest.main()

```



### Applications

Breadth-first search can be used to solve many problems in graph theory, for example:

1、Copying [garbage collection](https://en.wikipedia.org/wiki/Garbage_collection_(computer_science)), [Cheney's algorithm](https://en.wikipedia.org/wiki/Cheney's_algorithm)

2、Finding the [shortest path](https://en.wikipedia.org/wiki/Shortest_path) between two nodes *u* and *v*, with path length measured by number of edges (an advantage over [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search))[[12\]](https://en.wikipedia.org/wiki/Breadth-first_search#cite_note-12)

> NOTE: 
>
> 一、关于此，参见:
>
> 1、`BFS-shortest-path` 章节
>
> 二、[Dijkstra’s algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm) 可以看作是一种BFS

3、[(Reverse) Cuthill–McKee](https://en.wikipedia.org/wiki/Cuthill–McKee_algorithm) mesh numbering

4、[Ford–Fulkerson method](https://en.wikipedia.org/wiki/Ford–Fulkerson_algorithm) for computing the [maximum flow](https://en.wikipedia.org/wiki/Maximum_flow_problem) in a [flow network](https://en.wikipedia.org/wiki/Flow_network)

5、Serialization/Deserialization of a binary tree vs serialization in sorted order, allows the tree to be re-constructed in an efficient manner.

6、Construction of the *failure function* of the [Aho-Corasick](https://en.wikipedia.org/wiki/Aho-Corasick) pattern matcher.

7、Testing [bipartiteness of a graph](https://en.wikipedia.org/wiki/Bipartite_graph#Testing_bipartiteness).

8、[Topological sorting](https://en.wikipedia.org/wiki/Topological_sorting)

> NOTE:
>
> 一、这是最适合用graph BFS的问题





## Graph traversal VS tree traversal

参见 `Graph&tree&list` 章节。



## Circle

并不是所有的情况下都需要处理circle

dead loop

visited path

visted set

在求解最优值的时候，比如最短路径，如果edge都是positive的，那么这种情况下其实并不需要显式地处理circle，因为最优值的目标就能够避免重复选择路径。

### Visited set

1、在graph traversal中，为了避免由于circle而导致的dead loop，graph traversal algorithm普遍采用的是“标记已经visited vertex，对于visited vertex，再次遇到的时候，直接pass掉”。

2、对于graph中的一个node，可能有多条path通向它，在对它进行traverse的时候，为了避免重复，因此需要标注它是否已经被访问了。

> NOTE: 
>
> 1、在tree中，到达一个node，仅仅只有一条path，这是唯一的。

3、采用哪种标注策略呢？

对于采用recursive implementation，由于它本身就是深度优先的，因此，它的标注策略是非常简单的；

对于采用iterative implementation，因此，需要由programmer进行控制:

a、对于DFS: 如果current node没有被标注，则将它的所有的descendant全部都push到explicit stack中后，才算这个node被visit了

b、对于BFS: 对于current node的所有的descendant，只要没有被标准，就enqueue。

4、将它标注为visited，就相当于在tree traversal中，调用了visit function。



#### 两种往visited set中添加节点的方式

1、先判断是否visited，如果是，则不入queue

"[LeetCode-752. 打开转盘锁](https://leetcode.cn/problems/open-the-lock/) 中等 # 我的解"题中，就是采用的这种方式

2、先入queue，然后再入visited

"[LeetCode-【中规中矩】752. 打开转盘锁（宽度优先搜索）](https://leetcode.cn/problems/open-the-lock/solution/zhong-gui-zhong-ju-kuan-du-you-xian-sou-suo-by-jyj/) "中，就是使用的这种方式



