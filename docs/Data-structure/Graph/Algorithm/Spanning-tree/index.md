# Spanning tree



## wikipedia [Spanning tree](https://en.wikipedia.org/wiki/Spanning_tree)

In the [mathematical](https://en.wikipedia.org/wiki/Mathematics) field of [graph theory](https://en.wikipedia.org/wiki/Graph_theory), a **spanning tree** *T* of an [undirected graph](https://en.wikipedia.org/wiki/Undirected_graph) *G* is a subgraph that is a [tree](https://en.wikipedia.org/wiki/Tree_(graph_theory)) which includes all of the [vertices](https://en.wikipedia.org/wiki/Vertex_(graph_theory)) of *G*.

In general, a graph may have several spanning trees, but a graph that is not [connected](https://en.wikipedia.org/wiki/Connected_graph) will not contain a spanning tree (see about [spanning forests](https://en.wikipedia.org/wiki/Spanning_tree#Spanning_forests) below).

### Applications

Several [pathfinding](https://en.wikipedia.org/wiki/Pathfinding) algorithms, including [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) and the [A* search algorithm](https://en.wikipedia.org/wiki/A*_search_algorithm), internally build a spanning tree as an intermediate step in solving the problem.

> NOTE:
>
> 一、 [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) 的解称之为 [shortest-path-tree](https://en.wikipedia.org/wiki/Shortest-path_tree) 



### Spanning forests

A collection of disjoint (unconnected) trees is described as a *[forest](https://en.wikipedia.org/wiki/Forest_(graph_theory))*. A *spanning forest* in a graph is a subgraph that is a forest with an additional requirement. There are two incompatible requirements in use, of which one is relatively rare.

## Algorithms



### Construction

A single **spanning tree** of a graph can be found in [linear time](https://en.wikipedia.org/wiki/Linear_time) by either [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search) or [breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search). Both of these algorithms explore the given graph, starting from an arbitrary vertex *v*, by looping through the neighbors of the vertices they discover and adding each unexplored neighbor to a data structure to be explored later. They differ in whether this data structure is a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) (in the case of **depth-first search**) or a [queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) (in the case of **breadth-first search**). In either case, one can form a **spanning tree** by connecting each vertex, other than the root vertex *v*, to the vertex from which it was discovered. This tree is known as a **depth-first search tree** or a **breadth-first search tree** according to the graph exploration algorithm used to construct it.[[18\]](https://en.wikipedia.org/wiki/Spanning_tree#cite_note-18) Depth-first search trees are a special case of a class of spanning trees called [Trémaux trees](https://en.wikipedia.org/wiki/Trémaux_tree), named after the 19th-century discoverer of **depth-first search**.

> NOTE:
>
> 一、其实就是traverse graph的过程 

#### BFS

```python
import unittest
from collections import deque
from typing import Dict, List, Tuple, Union


class DirectedUnweightedGraphInAdjacencyList:
    """
    1、以adjacency list实现directed unweighted graph
    2、https://www.python.org/doc/essays/graphs/
    """

    def __init__(self, graph: Dict[Union[str, int], List[Union[str, int]]]):
        self.graph = graph

    def construct_spanning_tree_by_bfs1(self, start: Union[str, int]) -> List[Tuple[Union[str, int], Union[str, int]]]:
        """

        :param start:
        :return:
        """
        spanning_tree = []

        q = deque()
        visited_set = set()
        q.append(start)
        visited_set.add(start)
        while q:
            size = len(q)
            for _ in range(size):
                node = q.popleft()
                for adj_node in filter(lambda adjacent_node: adjacent_node not in visited_set,
                                       self.graph.get(node, [])):
                    q.append(adj_node)
                    visited_set.add(adj_node)
                    spanning_tree.append((node, adj_node))
        return spanning_tree

    def construct_spanning_tree_by_bfs2(self, start: Union[str, int]) -> List[Tuple[Union[str, int], Union[str, int]]]:
        """

        :param start:
        :return:
        """
        spanning_tree = []

        q = deque()
        visited_set = set()

        q.append(start)
        while q:
            size = len(q)
            for _ in range(size):
                node = q.popleft()
                if node not in visited_set:
                    visited_set.add(node)
                    for adj_node in filter(lambda adjacent_node: adjacent_node not in visited_set,
                                           self.graph.get(node, [])):
                        q.append(adj_node)
                        spanning_tree.append((node, adj_node))

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
        spanning_tree1 = directed_unweighted_graph_in_adj_list.construct_spanning_tree_by_bfs1(source)
        spanning_tree2 = directed_unweighted_graph_in_adj_list.construct_spanning_tree_by_bfs2(source)
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

上述 `construct_spanning_tree_by_bfs2` 存在错误，从上述运行结果也可以看出 `construct_spanning_tree_by_bfs1`、`construct_spanning_tree_by_bfs2` 两种BFS方式之间的差异: 

eager: 只要碰到node，就将它放到visited set中，它能够避免node重复进入到queue中

lazy   : 

每个node都需要access一遍，但是当将它们用于spanning tree都construction的时候，bfs2就不适用了。

#### DFS



### Optimization(Minimum-spanning-tree)

参见 `Minimum-spanning-tree` 章节。

