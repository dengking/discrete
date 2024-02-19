# Graph traversal



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
> - medium [Top 25 Breadth First Search (BFS) Practice Problems](https://medium.com/techie-delight/top-20-breadth-first-search-bfs-practice-problems-ac2812283ab1)
>
> - labuladong 
>
>   - [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) (相比之下，这篇文章不及下面这篇)
>   -  [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 
>   - [益智游戏克星：BFS暴力搜索算法](https://mp.weixin.qq.com/s/Xn-oW7QRu8spYzL3B6zLxw)
>
> - geeksforgeeks [Depth First Search or DFS for a Graph](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)
>
>   

---



### wikipedia [Breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search) 

#### Pseudocode

**Input**: A graph *G* and a *starting vertex* *root* of *G*

**Output**: Goal state. The *parent* links trace the shortest path back to *root*[[7\]](https://en.wikipedia.org/wiki/Breadth-first_search#cite_note-7)

```pseudocode
 1  procedure BFS(G, root) is
 2      let Q be a queue
 3      label root as explored
 4      Q.enqueue(root)
 5      while Q is not empty do
 6          v := Q.dequeue()
 7          if v is the goal then
 8              return v
 9          for all edges from v to w in G.adjacentEdges(v) do
10              if w is not labeled as explored then
11                  label w as explored
12                  w.parent := v # trace the shortest path
13                  Q.enqueue(w)
```

### Code

在使用BFS构建 [spanning tree](https://en.wikipedia.org/wiki/Spanning_tree) 的时候是最能够体现两种BFS实现的差异

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

上面展示了两种BFS的写法，两种往visited set中添加节点的方式。

#### bfs1: eager mode

一、bfs1的写法源自于 labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 

- 其中对queue machine有着非常好的描述

- 其中对while-从上到下+for-同层从左到右到解释非常好

- 这篇文章对BFS binary tree、BFS multiple tree、BFS graph都进行了介绍

![image](./BFS-traverse.png)



- 这篇文章中给出来具体的code

```java
// 输入起点，进行 BFS 搜索
int BFS(Node start) {
    Queue<Node> q; // 核心数据结构
    Set<Node> visited; // 避免走回头路

    q.offer(start); // 将起点加入队列
    visited.add(start);

    int step = 0; // 记录搜索的步数
    while (q not empty) {
        int sz = q.size();
        /* 将当前队列中的所有节点向四周扩散一步 */
        for (int i = 0; i < sz; i++) {
            Node cur = q.poll();
            printf("从 %s 到 %s 的最短距离是 %s", start, cur, step);

            /* 将 cur 的相邻节点加入队列 */
            for (Node x : cur.adj()) {
                if (x not in visited) {
                    q.offer(x);
                    visited.add(x);
                }
            }
        }
        step++;
    }
}
```

再加上 BFS 算法利用`for`循环一层一层向外扩散的逻辑和`visited`集合防止走回头路的逻辑，当你每次从队列中拿出节点`cur`的时候，从`start`到`cur`的最短权重就是`step`记录的步数。

二、上述写法可以总结为:

- nested-loop
- 同时进入queue、visited-set



#### bfs2: lazy mode

bfs2源自chatGTP，相比于bfs1，它更加简单，它采用的是"If the node has not been visited, add it to the visited list"。



### Applications

Breadth-first search can be used to solve many problems in graph theory, for example:

- Copying [garbage collection](https://en.wikipedia.org/wiki/Garbage_collection_(computer_science)), [Cheney's algorithm](https://en.wikipedia.org/wiki/Cheney's_algorithm)

- Finding the [shortest path](https://en.wikipedia.org/wiki/Shortest_path) between two nodes *u* and *v*, with path length measured by number of edges (an advantage over [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search))[[12\]](https://en.wikipedia.org/wiki/Breadth-first_search#cite_note-12)

> NOTE: 
>
> 一、关于此，参见:
>
> 1、`BFS-shortest-path` 章节
>
> 二、[Dijkstra’s algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm) 可以看作是一种BFS

- [(Reverse) Cuthill–McKee](https://en.wikipedia.org/wiki/Cuthill–McKee_algorithm) mesh numbering

- [Ford–Fulkerson method](https://en.wikipedia.org/wiki/Ford–Fulkerson_algorithm) for computing the [maximum flow](https://en.wikipedia.org/wiki/Maximum_flow_problem) in a [flow network](https://en.wikipedia.org/wiki/Flow_network)

- Serialization/Deserialization of a binary tree vs serialization in sorted order, allows the tree to be re-constructed in an efficient manner.

- Construction of the *failure function* of the [Aho-Corasick](https://en.wikipedia.org/wiki/Aho-Corasick) pattern matcher.

- Testing [bipartiteness of a graph](https://en.wikipedia.org/wiki/Bipartite_graph#Testing_bipartiteness).

- [Topological sorting](https://en.wikipedia.org/wiki/Topological_sorting)

> NOTE:
>
> 一、这是最适合用graph BFS的问题

- 需要验证只有沿着一条边才能够进入到目标边，使用BFS进行反向查找 

```Java
    private boolean isInLinkLaneGroupValid() {
        if (!isFound()) {
            return false;
        }
        Set<UnimapLaneGroup> visited = new HashSet<>(); // 防止dead loop
        Queue<UnimapLaneGroup> q = new LinkedList<>();
        q.add(inLinkLaneGroup);
        visited.add(inLinkLaneGroup);
        while (!q.isEmpty()) {
            int cnt = q.size();
            if (cnt > 1) {
                return false;
            }
            while (cnt > 0) {
                UnimapLaneGroup laneGroup = q.poll();
                Arrays.stream(laneGroup.getPrevLaneGroups())
                        .filter(prevLaneGroup ->
                                LaneGroupUtil.isInCrossArea(prevLaneGroup)
                                        && isSameLinkKindAsEnterLaneGroup(prevLaneGroup)
                                        && !visited.contains(prevLaneGroup)
                        )
                        .forEach(prevLaneGroup -> {
                            q.add(prevLaneGroup);
                            visited.add(prevLaneGroup);
                        });
                --cnt;
            }
        }
        return true;
    }
```

- [spanning tree](https://en.wikipedia.org/wiki/Spanning_tree#Algorithms) 



### Complexity

#### Space complexity

[LeetCode-【宫水三叶】一题三解：「双向 BFS」& 「AStar 算法」&「IDA* 算法」](https://leetcode.cn/problems/open-the-lock/solution/gong-shui-san-xie-yi-ti-shuang-jie-shuan-wyr9/)

> 使用朴素 BFS 进行求解时，队列中最多会存在“两层”的搜索节点。
>
> 因此搜索空间的上界取决于 **目标节点所在的搜索层次的深度所对应的宽度**。





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



## LeetCode

