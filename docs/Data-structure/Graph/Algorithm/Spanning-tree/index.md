# Spanning tree



## wikipedia [Spanning tree](https://en.wikipedia.org/wiki/Spanning_tree) 

In the [mathematical](https://en.wikipedia.org/wiki/Mathematics) field of [graph theory](https://en.wikipedia.org/wiki/Graph_theory), a **spanning tree** *T* of an [undirected graph](https://en.wikipedia.org/wiki/Undirected_graph) *G* is a subgraph that is a [tree](https://en.wikipedia.org/wiki/Tree_(graph_theory)) which includes all of the [vertices](https://en.wikipedia.org/wiki/Vertex_(graph_theory)) of *G*.

In general, a graph may have several spanning trees, but a graph that is not [connected](https://en.wikipedia.org/wiki/Connected_graph) will not contain a **spanning tree** (see about [spanning forests](https://en.wikipedia.org/wiki/Spanning_tree#Spanning_forests) below).

### Applications

Several [pathfinding](https://en.wikipedia.org/wiki/Pathfinding) algorithms, including [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) and the [A* search algorithm](https://en.wikipedia.org/wiki/A*_search_algorithm), internally build a **spanning tree** as an intermediate step in solving the problem.

> NOTE:
>
> 一、 [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) 的解称之为 [shortest-path-tree](https://en.wikipedia.org/wiki/Shortest-path_tree) 



### Spanning forests

A collection of disjoint (unconnected) trees is described as a *[forest](https://en.wikipedia.org/wiki/Forest_(graph_theory))*. A *spanning forest* in a graph is a subgraph that is a forest with an additional requirement. There are two incompatible requirements in use, of which one is relatively rare.

## Algorithms

> NOTE: 保证graph中的每个node只会被access一次

### Construction

A single **spanning tree** of a graph can be found in [linear time](https://en.wikipedia.org/wiki/Linear_time) by either [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search) or [breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search). Both of these algorithms explore the given graph, starting from an arbitrary vertex *v*, by looping through the neighbors of the vertices they discover and adding each unexplored neighbor to a data structure to be explored later. They differ in whether this data structure is a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) (in the case of **depth-first search**) or a [queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) (in the case of **breadth-first search**). In either case, one can form a **spanning tree** by connecting each vertex, other than the root vertex *v*, to the vertex from which it was discovered. This tree is known as a **depth-first search tree** or a **breadth-first search tree** according to the graph exploration algorithm used to construct it.[[18\]](https://en.wikipedia.org/wiki/Spanning_tree#cite_note-18) Depth-first search trees are a special case of a class of spanning trees called [Trémaux trees](https://en.wikipedia.org/wiki/Trémaux_tree), named after the 19th-century discoverer of **depth-first search**.

> NOTE:
>
> 一、其实就是traverse graph的过程 

#### BFS

```python
import unittest
from collections import deque
from typing import *


class DirectedUnweightedGraphInAdjacencyList:
    """
    1、以adjacency list实现directed unweighted graph
    2、https://www.python.org/doc/essays/graphs/
    """

    def __init__(self, graph: Dict[Union[str, int], List[Union[str, int]]]):
        self.graph = graph

    def construct_spanning_tree_by_bfs_eager_mark_explored(self, start: Union[str, int]) -> List[Tuple]:
        """

        :param start:
        :return:
        """
        spanning_tree = []

        q = deque()
        explored_set = set()
        q.append(start)
        explored_set.add(start)
        while q:
            size = len(q)
            for _ in range(size):
                cur_node = q.popleft()
                for adj_node in filter(lambda next_node: next_node not in explored_set, self.graph.get(cur_node, [])):
                    q.append(adj_node)
                    explored_set.add(adj_node)
                    spanning_tree.append((cur_node, adj_node))
        return spanning_tree

    def construct_spanning_tree_by_bfs_lazy_mark_visited(self, start: Union[str, int]) -> List[Tuple]:
        """

        :param start:
        :return:
        """
        spanning_tree = []

        q = deque()
        visited_set = set()

        q.append(start)
        while q:
            cur_node = q.popleft()
            if cur_node not in visited_set:
                visited_set.add(cur_node)
                for adj_node in filter(lambda next_node: next_node not in visited_set, self.graph.get(cur_node, [])):
                    q.append(adj_node)
                    spanning_tree.append((cur_node, adj_node))

        return spanning_tree


class TestSpanningTreeConstructionAlgorithm(unittest.TestCase):
    def test_spanning_tree_constructed_by_bfs(self):
        # Graph represented as an adjacency list
        graph = {
            0: [1, 2],
            1: [0, 2, 3],
            2: [0, 1, 4],
            3: [1],
            4: [2]
        }
        directed_unweighted_graph_in_adj_list = DirectedUnweightedGraphInAdjacencyList(graph)
        source = 1
        spanning_tree1 = directed_unweighted_graph_in_adj_list.construct_spanning_tree_by_bfs_eager_mark_explored(
            source)
        spanning_tree2 = directed_unweighted_graph_in_adj_list.construct_spanning_tree_by_bfs_lazy_mark_visited(source)
        print(f'spanning_tree1:{spanning_tree1}')
        print(f'spanning_tree2:{spanning_tree2}')

        self.assertEqual(len(spanning_tree1), len(spanning_tree2))
        self.assertEqual(len(spanning_tree1), 4)


if __name__ == '__main__':
    unittest.main()

```

运行结果如下:

```python
spanning_tree1:[(1, 0), (1, 2), (1, 3), (2, 4)]
spanning_tree2:[(1, 0), (1, 2), (1, 3), (0, 2), (2, 4)]


5 != 4

Expected :4
Actual   :5
```

上述 `construct_spanning_tree_by_bfs_lazy_mark_visited` 存在错误，从上述运行结果也可以看出 Eager mark explored BFS、Lazy mark visited BFS 两种BFS方式之间的差异: 

从node1可以到达node0、node2、node3，因此就构建了`[(1, 0), (1, 2), (1, 3)]` 同时将`[node0, node2, node3]`，在visit node1后就将它标记为visited; 然后从queue中取出node0，它能够达到node1、node2，由于node1已经被标记为visited，所以通过它只能够构建`(0, 2)`，然后将node2加入到queue中，需要注意的是，此时已经出现问题了:

`[(1, 0), (1, 2), (1, 3), (0, 2)]` 已经成环了，因为node2它既能够从node1到达又能够从node0到达，所以它两次被构建边、两次进入到queue中。

这其实就体现了lazy写法的一个弊端: 一个node，如果能够通过多个node到达，那么它可能多次进入到queue中，对于向spanning tree construction问题，它就不适用了。

#### DFS

```python
import unittest
from typing import *


class DirectedUnweightedGraphInAdjacencyList:
    """
    1、以adjacency list实现directed unweighted graph
    2、https://www.python.org/doc/essays/graphs/
    """

    def __init__(self, graph: Dict[Union[str, int], List[Union[str, int]]]):
        self.graph = graph

    def construct_spanning_tree_by_dfs(self,
                                       start: Union[str, int],
                                       visited_set=None,
                                       spanning_tree=None) -> List[Tuple]:

        if visited_set is None:
            visited_set = set()
        if spanning_tree is None:
            spanning_tree = []

        if start not in visited_set:
            visited_set.add(start)
            for adj_node in filter(lambda next_node: next_node not in visited_set, self.graph.get(start, [])):
                spanning_tree.append((start, adj_node))
                self.construct_spanning_tree_by_dfs(adj_node, visited_set, spanning_tree)

        return spanning_tree


class TestSpanningTreeConstructionAlgorithm(unittest.TestCase):
    def test_spanning_tree_constructed_by_bfs(self):
        # Graph represented as an adjacency list
        graph = {
            0: [1, 2],
            1: [0, 2, 3],
            2: [0, 1, 4],
            3: [1],
            4: [2]
        }
        directed_unweighted_graph_in_adj_list = DirectedUnweightedGraphInAdjacencyList(graph)
        source = 1
        spanning_tree1 = directed_unweighted_graph_in_adj_list.construct_spanning_tree_by_dfs(
            source)
        print(f'spanning_tree1:{spanning_tree1}')

        self.assertEqual(len(spanning_tree1), 4)


if __name__ == '__main__':
    unittest.main()

```



### Optimization(Minimum-spanning-tree)

参见 `Minimum-spanning-tree` 章节。

