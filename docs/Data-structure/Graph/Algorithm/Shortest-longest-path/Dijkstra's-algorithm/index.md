# Dijkstra's algorithm

## 素材

一、wikipedia [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) 

二、labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 



## 概括

一、dijkstra algorithm=BFS+greedy-algorithm贪心算法+dynamic-programming动态规划: 

1、greedy-algorithm贪心算法: 每次选择距离source最短的node进行expand、relaxation approximation。



2、wikipedia [Dijkstra's algorithm # Pseudocode](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#Pseudocode) 一次性将所有等node都加入到queue中，labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 中是动态加入。如果 queue不支持 `decrease_priority` 接口，那么就无法按照 wikipedia [Dijkstra's algorithm # Pseudocode](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#Pseudocode) 中的写法写。



3、使用 priority queue/heap 按照distance对node进行排序，在具体实现上，需要将distance/weight和node一起放到`priority_queue`中，不能够只放node或者只放distance/weight，因为这样是会导致无法对node进行排序、无法取出node等。wikipedia [Dijkstra's algorithm # Pseudocode](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#Pseudocode) 中是通过如下方式实现的:

```Java
Q.add_with_priority(source, dist[source])
Q.decrease_priority(v, alt)
```

在labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect)中是通过如下方式实现的:

```Java
class State {
    // 图节点的 id
    int id;
    // 从 start 节点到当前节点的距离
    int distFromStart;

    State(int id, int distFromStart) {
        this.id = id;
        this.distFromStart = distFromStart;
    }
}
```



二、为什么不支持负数边？why dijkstra algorithm not allow negative edge？

Dijkstra's algorithm does not allow negative edge weights because it relies on the assumption that once a node has been visited (i.e., the shortest path to that node has been found), its shortest path will not change. This assumption is based on the fact that adding more edges to a path will only increase the total path cost when all edge weights are non-negative.

Here's a breakdown(分解) of why negative edge weights cause problems for Dijkstra's algorithm:

1. **Greedy Approach**: Dijkstra's algorithm is a greedy algorithm that makes the locally optimal choice at each step. It assumes that the shortest path to a node is finalized as soon as that node is added to the set of visited nodes. This is because, with non-negative edge weights, any extension of a path would only make it longer.
2. **Priority Queue**: The algorithm uses a priority queue (or a min-heap) to select the next node with the smallest tentative distance. If a node is revisited with a shorter path due to a negative edge, the priority queue may not correctly reflect the updated shortest paths, leading to incorrect results.
3. **Incorrect Shortest Path**: If negative edge weights are present, a path that has already been determined to be the shortest could be further shortened by taking a detour through a negative edge, violating the algorithm's assumption. Dijkstra's algorithm does not revisit nodes to check if their shortest path has been updated, which means it can miss shorter paths created by negative edges.
4. **Negative Cycles**: If a graph contains a negative cycle (a cycle whose edges sum to a negative value), the shortest path is undefined because you could repeatedly traverse the negative cycle and reduce the path length indefinitely. Dijkstra's algorithm does not have a mechanism to detect negative cycles.

To handle graphs with negative edge weights, algorithms like Bellman-Ford or Johnson's algorithm (which uses Bellman-Ford as a preprocessing step) should be used. These algorithms are designed to accommodate negative edge weights and can detect **negative cycles**.



三、Dijkstra's algorithm是否需要visited set？

对于没有 negative weight edge 的graph，在使用 Dijkstra's algorithm 的时候，是不需要考虑cycle问题的，这是因为 Dijkstra's algorithm 是 greedy algorithm，如果出现cycle，重复visit到一个node，显然更多的path是会导致distance增加的，显然这种path会被丢弃。



四、generic Dijkstra shortest-path algorithm



五、construct shortest path tree、shortest path graph

1、将 [shortest-path tree](https://en.wikipedia.org/wiki/Shortest-path_tree)、shortest path graph 存放到`prev` array中

2、stop condition: source node没有predecessor

## wikipedia [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) 

The algorithm exists in many variants. Dijkstra's original algorithm found the shortest path between two given nodes,[[5\]](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#cite_note-Dijkstra1959-5) but a more common variant fixes a single node as the "source" node and finds shortest paths from the source to all other nodes in the graph, producing a [shortest-path tree](https://en.wikipedia.org/wiki/Shortest-path_tree).

> NOTE: 
>
> 一、single source
>
> 二、从后面的`Pseudocode`可知，dijkstra的implementation中，会将 [shortest-path tree](https://en.wikipedia.org/wiki/Shortest-path_tree) 存放到`prev` array中
>

### Generic Dijkstra shortest-path algorithm

The **Dijkstra algorithm** uses labels that are positive integers or real numbers, which are [totally ordered](https://en.wikipedia.org/wiki/Total_order). It can be generalized to use any labels that are [partially ordered](https://en.wikipedia.org/wiki/Partially_ordered_set), provided the subsequent labels (a subsequent label is produced when traversing an edge) are [monotonically](https://en.wikipedia.org/wiki/Monotonic_function) non-decreasing. This generalization is called the **generic Dijkstra shortest-path algorithm**.[[7\]](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#cite_note-Generic_Dijkstra-7)

> NOTE: 
>
> 一、generic Dijkstra shortest-path algorithm
>
> 上面这段话所介绍的generic Dijkstra shortest-path algorithm，它强调的是 "labels that are [partially ordered](https://en.wikipedia.org/wiki/Partially_ordered_set)"，如果从graph的角度来说，它所蕴含的是weighted directed graph的weight是 [partially ordered](https://en.wikipedia.org/wiki/Partially_ordered_set) 的。



This is [asymptotically](https://en.wanweibaike.com/wiki-Asymptotic_computational_complexity) the fastest known single-source [shortest-path algorithm](https://en.wanweibaike.com/wiki-Shortest_path_problem) for arbitrary [directed graphs](https://en.wanweibaike.com/wiki-Directed_graph) with unbounded non-negative weights. 

> NOTE: 
>
> 一、为什么dijkstra 算法是不允许负数边的？这在前面进行了讨论。

In some fields, [artificial intelligence](https://en.wanweibaike.com/wiki-Artificial_intelligence) in particular, Dijkstra's algorithm or a variant of it is known as **uniform cost search** and formulated as an instance of the more general idea of [best-first search](https://en.wanweibaike.com/wiki-Best-first_search).

### Pseudocode



[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/e/e4/DijkstraDemo.gif/220px-DijkstraDemo.gif)](https://en.wikipedia.org/wiki/File:DijkstraDemo.gif)

A demo of **Dijkstra's algorithm** based on **Euclidean distance**.

1、Red lines are the shortest path covering, i.e., connecting `u` and `prev[u]`. 

2、Blue lines indicate where relaxing happens, i.e., connecting *v* with a node *u* in *Q*, which gives a shorter path from the source to *v*.



#### Not using a priority queue

```pseudocode
 1  function Dijkstra(Graph, source):
 2
 3      create vertex set Q
 4
 5      for each vertex v in Graph:            
 6          dist[v] ← INFINITY                 
 7          prev[v] ← UNDEFINED                
 8          add v to Q                     
 9      dist[source] ← 0                       
10     
11      while Q is not empty:
12          u ← vertex in Q with min dist[u]   
13                                             
14          remove u from Q
15         
16          for each neighbor v of u:           // only v that are still in Q
17              alt ← dist[u] + length(u, v)
18              if alt < dist[v]:              
19                  dist[v] ← alt
20                  prev[v] ← u
21
22      return dist[], prev[]
```

> NOTE: 
>
> 一、上述伪代码的initialization:
>
> ```pseudocode
>  5      for each vertex v in Graph:            
>  6          dist[v] ← INFINITY                 
>  7          prev[v] ← UNDEFINED                
>  8          add v to Q                     
>  9      dist[source] ← 0  
> ```
>
> 
>
> ```pseudocode
> 11      while Q is not empty:
> 12          u ← vertex in Q with min dist[u]   
> 13                                             
> 14          remove u from Q
> ```
>
> 显然，`while`的第一次取到的`source`
>
> 它和 `计算机算法设计与分析-4-5-单源最短路径` 中的实现方式是有差异的。

##### Reconstruct Shortest path

> NOTE:
>
> 一、这一节讲述的是构造从source到target的shortest path的算法，它分了两种情况来进行讨论: 
>
> 1、find a shortest path between vertices ***source*** and ***target*** 
>
> 2、find all the shortest paths between ***source*** and ***target*** (there might be several different ones of the same length) 
>
> a、记录
>
> b、reconstruct
>
> 使用一个stack

Case 1: a shortest path between vertices ***source*** and ***target*** 

If we are only interested in a **shortest path** between vertices ***source*** and ***target***, we can terminate the search after line 15 if `u = target`. 

Now we can read the **shortest path** from ***source*** to ***target*** by reverse iteration:

```pseudocode
1  S ← empty sequence
2  u ← target
3  if prev[u] is defined or u = source:          // Do something only if the vertex is reachable
4      while u is defined:                       // Construct the shortest path with a stack S
5          insert u at the beginning of S        // Push the vertex onto the stack
6          u ← prev[u]                           // Traverse from target to source
```

Now sequence `S` is the list of vertices constituting one of the shortest paths from source to target, or the empty sequence if no path exists.

> NOTE:
>
> 一、上述pseudocode中的 `S` 是一个stack

Case 2: [shortest-path tree](https://en.wikipedia.org/wiki/Shortest-path_tree): 从source到所有的node的 shortest path 

A more general problem would be to find all the shortest paths between ***source*** and ***target*** (there might be several different ones of the same length). Then instead of storing only a single node in each entry of `prev[]`, we would store all nodes satisfying the **relaxation condition**. For example, if both `r` and `source` connect to `target` and both of them lie on different **shortest paths** through `target` (because the edge cost is the same in both cases), then we would add both `r` and `source` to `prev[target]`. When the algorithm completes, `prev[]` data structure will actually describe a graph that is a subset of the original graph with some edges removed. Its key property will be that if the algorithm was run with some **starting node**, then every path from that node to any other node in the new graph will be the **shortest path** between those nodes in the original graph, and all paths of that length from the original graph will be present in the new graph. Then to actually find all these shortest paths between two given nodes we would use a path finding algorithm on the new graph, such as [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search).

> NOTE:
>
> 一、在后面的python implementation中的shortest path graph展示了上述思路的实现



#### Using a priority queue

```C++
1  function Dijkstra(Graph, source):
2      dist[source] ← 0                           // Initialization
3
4      create vertex priority queue Q
5
6      for each vertex v in Graph:          
7          if v ≠ source
8              dist[v] ← INFINITY                 // Unknown distance from source to v
9              prev[v] ← UNDEFINED                // Predecessor of v
10
11         Q.add_with_priority(v, dist[v])
12
13
14     while Q is not empty:                      // The main loop
15         u ← Q.extract_min()                    // Remove and return best vertex
16         for each neighbor v of u:              // only v that are still in Q
17             alt ← dist[u] + length(u, v)
18             if alt < dist[v]
19                 dist[v] ← alt
20                 prev[v] ← u
21                 Q.decrease_priority(v, alt)    // 由于node已经存在于 Q 中了，因此此处仅仅是更新，而不是插入
22
23     return dist, prev
```

> NOTE: 
>
> 一、
>
> 通过对比可知，`priority queue`的优势在于`u ← Q.extract_min()` 



### Practical optimizations and infinite graphs

> NOTE:
>
> 一、GPT:
>
> > Uniform-cost search is a variant of Dijkstra's algorithm that is used when all actions have a cost and you want to find the least-cost path to the goal. It expands the node with the lowest path cost, and it is guaranteed to find the least-cost path to the goal as long as the cost of each step is positive.
>
> uniform-cost-search是将Dijkstra's algorithm修改后用于infinite graph，由于它是基于Dijkstra's algorithm，所以它也是不支持negative weighted edge的
>
> 二、在后面展示了完整的代码
>
> 从pseudocode可以看出，它使用了visited set，那它为什么需要呢？
>
> 从pseudocode可以看出，它没有使用edge relaxation，那它为什么需要呢？
>
> 下面是GPT: why uniform cost search do not use relaxation？的回答:
>
> > Uniform-cost search does not explicitly use the concept of relaxation as seen in Dijkstra's algorithm because it operates under a different principle. Relaxation in Dijkstra's algorithm is the process of updating the shortest known distance to a vertex when a shorter path is found. This is done by "relaxing" the edges, checking if the known distance to a vertex can be improved by taking a newly discovered path.
> >
> > In contrast, uniform-cost search is a more general search algorithm that does not assume the graph is weighted or directed. It is a form of best-first search that uses a priority queue to explore nodes in order of their path cost from the start node, expanding the least-cost unexplored node at each step.
> >
> > Here's why relaxation is not explicitly used in uniform-cost search:
> >
> > 1. **Priority Queue**: Uniform-cost search uses a priority queue to manage the frontier of nodes to be explored. The priority queue automatically ensures that the node with the lowest cumulative cost is chosen for expansion. This implicitly takes care of the need to find the shortest path without the need for a separate relaxation step.
> > 2. **Exploration Order**: Since uniform-cost search always expands the node with the lowest path cost first, it naturally follows the shortest path to each node without needing to update distances. If a shorter path to a node is found, that node will be expanded before any longer paths due to the nature of the priority queue.
> > 3. **Goal Test**: Uniform-cost search can stop as soon as it reaches the goal node because it is guaranteed that this is the lowest-cost path to the goal. There is no need to continue searching to find a potentially shorter path, as would be the case with relaxation in Dijkstra's algorithm.
> > 4. **General Applicability**: Uniform-cost search is a more general algorithm that can be applied to any search problem, not just pathfinding in weighted graphs. It does not rely on the structure of a graph or the presence of edge weights, so the concept of relaxation is not applicable.
> >
> > In summary, uniform-cost search inherently ensures that the shortest path is found by the order in which nodes are expanded, without the need for a separate relaxation process. The use of a priority queue to manage the frontier is key to this behavior.

In common presentations of **Dijkstra's algorithm**, initially all nodes are entered into the priority queue. This is, however, not necessary: the algorithm can start with a priority queue that contains only one item, and insert new items as they are discovered (instead of doing a decrease-key, check whether the key is in the queue; if it is, decrease its key, otherwise insert it).[[7\]](https://en.wanweibaike.com/wiki-Dijkstra's Algorithm#cite_note-mehlhorn-7):198 This variant has the same worst-case bounds as the common variant, but maintains a smaller priority queue in practice, speeding up the queue operations.

Moreover, not inserting all nodes in a graph makes it possible to extend the algorithm to find the shortest path from a single source to the closest of a set of target nodes on infinite graphs or those too large to represent in memory. The resulting algorithm is called *uniform-cost search* (UCS) in the artificial intelligence literature[[9\]](https://en.wanweibaike.com/wiki-Dijkstra's Algorithm#cite_note-felner-9)[[17\]](https://en.wanweibaike.com/wiki-Dijkstra's Algorithm#cite_note-aima-17)[[18\]](https://en.wanweibaike.com/wiki-Dijkstra's Algorithm#cite_note-18) and can be expressed in pseudocode as

```pseudocode
procedure uniform_cost_search(start) is
    node ← start
    frontier ← priority queue containing node only
    expanded ← empty set
    do
        if frontier is empty then
            return failure
        node ← frontier.pop()
        if node is a goal state then
            return solution(node)
        expanded.add(node)
        for each of node's neighbors n do
            if n is not in expanded and not in frontier then
                frontier.add(n)
            else if n is in frontier with higher cost
                replace existing node with n
```



### Related problems and algorithms

Unlike Dijkstra's algorithm, the [Bellman–Ford algorithm](https://en.wanweibaike.com/wiki-Bellman–Ford_algorithm) can be used on graphs with negative edge weights, as long as the graph contains no [negative cycle](https://en.wanweibaike.com/wiki-Negative_cycle) reachable from the source vertex *s*. The presence of such cycles means there is no shortest path, since the total weight becomes lower each time the cycle is traversed. (This statement assumes that a "path" is allowed to repeat vertices. In [graph theory](https://en.wanweibaike.com/wiki-Graph_theory) that is normally not allowed. In [theoretical computer science](https://en.wanweibaike.com/wiki-Theoretical_computer_science) it often is allowed.) It is possible to adapt Dijkstra's algorithm to handle negative weight edges by combining it with the Bellman-Ford algorithm (to remove negative edges and detect negative cycles), such an algorithm is called [Johnson's algorithm](https://en.wanweibaike.com/wiki-Johnson's_algorithm).

## Implementation



### Python

#### DijkstraAlgorithmInFiniteGraph

```C++
import heapq
import unittest
from typing import Dict, List


class DijkstraAlgorithmInFiniteGraphTrackingShortestPathGraph:
    """
    有限图的Dijkstra's algorithm，它分为:
    1、计算从 source 到所有 node   的最短路径的长度
    2、计算从 source 到    target 的最短路径的长度
    """

    def __init__(self, graph_in_adj_list: Dict[str, Dict[str, int]]):
        self.graph_in_adj_list = graph_in_adj_list

    def shortest_path_to_all_nodes(self, source: str, track_shortest_path_graph=True):
        """
        1、计算从 source 到所有 node 的距离
        2、注意: 由于self.graph_in_adj_list的key可能不包括所有的node，因此对于使用self.graph_in_adj_list的key构建的dict，
        为了避免KeyError，使用Dict.get(key, default value)
        :param source:
        :param track_shortest_path_graph: 是否记录最短路径
        :return:
        """
        distances = {node: float('inf') for node in
                     self.graph_in_adj_list}  # 从start到各个node的距离，这里使用的是dict comprehension语法
        distances[source] = 0
        shortest_path_graph: Dict[str, List[str]] = {vertex: [] for vertex in self.graph_in_adj_list}

        q = [(0, source)]  # https://docs.python.org/3/library/heapq.html
        while q:
            current_distance, current_node = heapq.heappop(q)
            # 下面的这个判定其实是可以去除的，在 https://leetcode.cn/problems/network-delay-time/ 中
            if current_distance > distances[current_node]:
                continue

            for adj_node, new_distance in self.graph_in_adj_list.get(current_node, {}).items():
                new_distance = current_distance + new_distance
                if new_distance < distances.get(adj_node, float('inf')):
                    distances[adj_node] = new_distance
                    heapq.heappush(q, (new_distance, adj_node))
                    if track_shortest_path_graph:
                        shortest_path_graph[adj_node] = [current_node]
                elif new_distance == distances[adj_node]:
                    if track_shortest_path_graph:
                        shortest_path_graph[adj_node].append(current_node)

        return distances, shortest_path_graph if track_shortest_path_graph else distances

    def reconstruct_all_path(self, shortest_path_graph: Dict[str, List[str]], target: str) -> List[List[str]]:
        """
        构建从source到target的所有的path
        :return:
        """
        all_paths: List[List[str]] = []
        # 注意: 要将target首先放到path中，因为shortest_path_graph只保存了target的predecessors
        self.__dfs_reconstruct_all_path__(all_paths, shortest_path_graph, target, [target])
        return all_paths

    @classmethod
    def __dfs_reconstruct_all_path__(cls, all_paths: List[List[str]], shortest_path_graph: Dict[str, List[str]], node,
                                     path: List):
        # Stop condition: if we reached the start of the path, add the current path to the list
        # Stop condition: source node，source node是没有predecessor的
        if not shortest_path_graph[node]:
            all_paths.append(path[::-1])  # Reverse the path
            return
        for predecessor in shortest_path_graph.get(node, []):
            cls.__dfs_reconstruct_all_path__(all_paths, shortest_path_graph, predecessor, path + [predecessor])

    def shortest_path_to_single_node(self, source: str, target: str, track_shortest_path=True):
        """
        计算从 source 到 target 的最短路径的长度
        :param track_shortest_path: 是否记录最短路径
        :param source:
        :param target:
        :return:
        """
        distances = {node: float('inf') for node in self.graph_in_adj_list}
        distances[source] = 0
        shortest_path_graph: Dict[str, List[str]] = {vertex: [] for vertex in self.graph_in_adj_list}
        shortest_distance = float('inf')
        q = [(0, source)]
        while q:
            distance, node = heapq.heappop(q)
            if target == node:
                shortest_distance = distance
            for adj_node, adj_distance in self.graph_in_adj_list.get(node, {}).items():
                new_distance = distance + adj_distance
                if new_distance < distances.get(adj_node, float('inf')):
                    distances[adj_node] = new_distance
                    heapq.heappush(q, (new_distance, adj_node))
                    if track_shortest_path:
                        shortest_path_graph[adj_node] = [node]
                elif new_distance == adj_distance:
                    if track_shortest_path:
                        shortest_path_graph[adj_node].append(node)
        return shortest_distance, shortest_path_graph if track_shortest_path else distances


class DijkstraAlgorithmInFiniteGraphTrackingShortestPathTree:
    """
    添加它的目的是为了和前面的进行区分
    """

    def __init__(self, graph_in_adj_list: Dict[str, Dict[str, int]]):
        self.graph_in_adj_list = graph_in_adj_list

    def shortest_path_to_all_nodes(self, source: str, track_shortest_path_tree=True):
        """
        1、计算从 source 到所有 node 的距离
        2、注意: 由于self.graph_in_adj_list的key可能不包括所有的node，因此对于使用self.graph_in_adj_list的key构建的dict，
        为了避免KeyError，使用Dict.get(key, default value)
        :param source:
        :param track_shortest_path_tree: 是否记录最短路径
        :return:
        """
        distances = {node: float('inf') for node in
                     self.graph_in_adj_list}  # 从start到各个node的距离，这里使用的是dict comprehension语法
        distances[source] = 0
        shortest_path_tree: Dict[str, str] = {vertex: None for vertex in self.graph_in_adj_list}

        q = [(0, source)]  # https://docs.python.org/3/library/heapq.html
        while q:
            current_distance, current_node = heapq.heappop(q)
            # 下面的这个判定其实是可以去除的，在 https://leetcode.cn/problems/network-delay-time/ 中
            if current_distance > distances[current_node]:
                continue

            for adj_node, new_distance in self.graph_in_adj_list.get(current_node, {}).items():
                new_distance = current_distance + new_distance
                if new_distance < distances.get(adj_node, float('inf')):
                    distances[adj_node] = new_distance
                    heapq.heappush(q, (new_distance, adj_node))
                    if track_shortest_path_tree:
                        shortest_path_tree[adj_node] = current_node

        return distances, shortest_path_tree if track_shortest_path_tree else distances

    @staticmethod
    def reconstruct_path(shortest_path_tree: Dict[str, str], target: str) -> List[str]:
        """
        构建从source到target的所有的path
        :return:
        """
        path: List[str] = []
        node = target
        # Stop condition: source node，source node是没有predecessor的
        while node is not None:
            path.append(node)
            node = shortest_path_tree[node]
        path.reverse()
        return path


class TestDijkstraAlgorithmInFiniteGraph(unittest.TestCase):

    def test_shortest_path_to_single_node(self):
        graph = {
            'A': {'B': 1, 'C': 4},
            'B': {'C': 2, 'D': 5},
            'C': {'D': 1},
            'D': {'E': 1},
            'E': {}
        }
        self.dijkstra = DijkstraAlgorithmInFiniteGraphTrackingShortestPathGraph(graph)
        start = 'A'
        end = 'E'
        distance, shortest_path_graph = self.dijkstra.shortest_path_to_single_node(start, end)
        self.assertEqual(distance, 5)
        paths = self.dijkstra.reconstruct_all_path(shortest_path_graph, end)
        print(paths)
        self.assertEqual(len(paths), 1)
        self.assertEqual(paths[0], ['A', 'B', 'C', 'D', 'E'])

    def test_shortest_path_to_all_node(self):
        graph = {
            'A': {'B': 1, 'C': 4},
            'B': {'C': 2, 'D': 5},
            'C': {'D': 1},
            'D': {'E': 1},
            'E': {}
        }
        self.dijkstra = DijkstraAlgorithmInFiniteGraphTrackingShortestPathGraph(graph)
        start = 'A'
        distances, shortest_path_graph = self.dijkstra.shortest_path_to_all_nodes(start)
        d = 'D'
        e = 'E'
        self.assertEqual(distances[d], 4)
        self.assertEqual(distances[e], 5)
        paths = self.dijkstra.reconstruct_all_path(shortest_path_graph, d)
        print(paths)
        self.assertEqual(len(paths), 1)
        self.assertEqual(paths[0], ['A', 'B', 'C', 'D'])
        paths = self.dijkstra.reconstruct_all_path(shortest_path_graph, e)
        print(paths)
        self.assertEqual(len(paths), 1)
        self.assertEqual(paths[0], ['A', 'B', 'C', 'D', 'E'])


class TestDijkstraAlgorithmInFiniteGraphTrackingShortestPathTree(unittest.TestCase):
    def test_shortest_path_to_all_node(self):
        graph = {
            'A': {'B': 1, 'C': 4},
            'B': {'C': 2, 'D': 5},
            'C': {'D': 1},
            'D': {}
        }
        dijkstra = DijkstraAlgorithmInFiniteGraphTrackingShortestPathTree(graph)
        source = 'A'
        distances, shortest_path_tree = dijkstra.shortest_path_to_all_nodes(source)
        d = 'D'
        self.assertEqual(distances[d], 4)
        path = dijkstra.reconstruct_path(shortest_path_tree, d)
        print(path)
        self.assertEqual(path, ['A', 'B', 'C', 'D'])


if __name__ == '__main__':
    unittest.main()

```



#### UniformCostSearch



### Java


labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect)

```Java
// 返回节点 from 到节点 to 之间的边的权重
int weight(int from, int to);

// 输入节点 s 返回 s 的相邻节点
List<Integer> adj(int s);

// 输入一幅图和一个起点 start，计算 start 到其他节点的最短距离
int[] dijkstra(int start, List<Integer>[] graph) {
    // 图中节点的个数
    int V = graph.length;
    // 记录最短路径的权重，你可以理解为 dp table
    // 定义：distTo[i] 的值就是节点 start 到达节点 i 的最短路径权重
    int[] distTo = new int[V];
    // 求最小值，所以 dp table 初始化为正无穷
    Arrays.fill(distTo, Integer.MAX_VALUE);
    // base case，start 到 start 的最短距离就是 0
    distTo[start] = 0;

    // 优先级队列，distFromStart 较小的排在前面
    Queue<State> pq = new PriorityQueue<>((a, b) -> {
        return a.distFromStart - b.distFromStart;
    });

    // 从起点 start 开始进行 BFS
    pq.offer(new State(start, 0));

    while (!pq.isEmpty()) {
        State curState = pq.poll();
        int curNodeID = curState.id;
        int curDistFromStart = curState.distFromStart;

        if (curDistFromStart > distTo[curNodeID]) {
            // 已经有一条更短的路径到达 curNode 节点了
            continue;
        }
        // 将 curNode 的相邻节点装入队列
        for (int nextNodeID : adj(curNodeID)) {
            // 看看从 curNode 达到 nextNode 的距离是否会更短
            int distToNextNode = distTo[curNodeID] + weight(curNodeID, nextNodeID);
            if (distTo[nextNodeID] > distToNextNode) {
                // 更新 dp table
                distTo[nextNodeID] = distToNextNode;
                // 将这个节点以及距离放入队列
                pq.offer(new State(nextNodeID, distToNextNode));
            }
        }
    }
    return distTo;
}
```





### 一个疑惑点

写法有多种版本:


wikipedia [Dijkstra's algorithm # Pseudocode](https://en.wikipedia.org/wiki/Dijkstra's_algorithm#Pseudocode)

```pseudocode
1  function Dijkstra(Graph, source):
2      dist[source] ← 0                           // Initialization
3
4      create vertex priority queue Q
5      Q.add_with_priority(source, dist[source])
6
7      for each vertex v in Graph.Vertices:
8          if v ≠ source
9              dist[v] ← INFINITY                 // Unknown distance from source to v
10              prev[v] ← UNDEFINED                // Predecessor of v
11
12         Q.add_with_priority(v, dist[v])
13
14
15     while Q is not empty:                      // The main loop
16         u ← Q.extract_min()                    // Remove and return best vertex
17         for each neighbor v of u:              // only v that are still in Q
18             alt ← dist[u] + Graph.Edges(u, v)
19             if alt < dist[v] and dist[u] is not INFINITY:
20                 dist[v] ← alt
21                 prev[v] ← u
22                 Q.decrease_priority(v, alt)
23
24     return dist, prev
```




labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect)

```Java
// 返回节点 from 到节点 to 之间的边的权重
int weight(int from, int to);

// 输入节点 s 返回 s 的相邻节点
List<Integer> adj(int s);

// 输入一幅图和一个起点 start，计算 start 到其他节点的最短距离
int[] dijkstra(int start, List<Integer>[] graph) {
    // 图中节点的个数
    int V = graph.length;
    // 记录最短路径的权重，你可以理解为 dp table
    // 定义：distTo[i] 的值就是节点 start 到达节点 i 的最短路径权重
    int[] distTo = new int[V];
    // 求最小值，所以 dp table 初始化为正无穷
    Arrays.fill(distTo, Integer.MAX_VALUE);
    // base case，start 到 start 的最短距离就是 0
    distTo[start] = 0;

    // 优先级队列，distFromStart 较小的排在前面
    Queue<State> pq = new PriorityQueue<>((a, b) -> {
        return a.distFromStart - b.distFromStart;
    });

    // 从起点 start 开始进行 BFS
    pq.offer(new State(start, 0));

    while (!pq.isEmpty()) {
        State curState = pq.poll();
        int curNodeID = curState.id;
        int curDistFromStart = curState.distFromStart;

        if (curDistFromStart > distTo[curNodeID]) {
            // 已经有一条更短的路径到达 curNode 节点了
            continue;
        }
        // 将 curNode 的相邻节点装入队列
        for (int nextNodeID : adj(curNodeID)) {
            // 看看从 curNode 达到 nextNode 的距离是否会更短
            int distToNextNode = distTo[curNodeID] + weight(curNodeID, nextNodeID);
            if (distTo[nextNodeID] > distToNextNode) {
                // 更新 dp table
                distTo[nextNodeID] = distToNextNode;
                // 将这个节点以及距离放入队列
                pq.offer(new State(nextNodeID, distToNextNode));
            }
        }
    }
    return distTo;
}
```



两者之间的差别:

1、labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 中多了如下逻辑:

```Java
    if (curDistFromStart > distTo[curNodeID]) {
        // 已经有一条更短的路径到达 curNode 节点了
        continue;
    }
```

那这个逻辑是否是必须要的呢？

在 [LeetCode-743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time/) 中我尝试将它去掉，代码依然能够通过。



## LeetCode 



### [LeetCode-743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time/) 

```python
import heapq
import unittest
from typing import List, Dict


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        distances = {i + 1: float('inf') for i in range(n)}
        graph_in_ajd_list: Dict[int, Dict] = {t[0]: {} for t in times}
        for t in times:
            graph_in_ajd_list[t[0]][t[1]] = t[2]
        distances[k] = 0
        q = [(0, k)]
        while q:
            distance, node = heapq.heappop(q)
            for adj_node, adj_distance in graph_in_ajd_list.get(node, {}).items():
                new_distance = distance + adj_distance
                if new_distance < distances[adj_node]:
                    distances[adj_node] = new_distance
                    heapq.heappush(q, (new_distance, adj_node))

        max_distance = -1
        if float('inf') in distances.values():
            return max_distance
        return max(distances.values())


class TestStringMethods(unittest.TestCase):

    def test_case_1(self):
        self.solution = Solution()
        times = [[1, 2, 1], [2, 3, 2], [1, 3, 4]]
        n = 3
        k = 1

        self.assertEqual(self.solution.networkDelayTime(times, n, k), -1)


if __name__ == '__main__':
    unittest.main()

```



[LeetCode-1631. 最小体力消耗路径](https://leetcode.cn/problems/path-with-minimum-effort/)

[LeetCode-1514. 概率最大的路径](https://leetcode.cn/problems/path-with-maximum-probability/)

[LeetCode-787. K 站中转内最便宜的航班-中等](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 



