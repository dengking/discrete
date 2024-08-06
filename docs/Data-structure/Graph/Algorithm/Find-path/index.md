# Find path



对于directed unweighed graph: 

- find a path
- find all path
- find shortest path

[Python Patterns - Implementing Graphs](https://www.python.org/doc/essays/graphs/) 



```python
import unittest
from collections import deque
from typing import Dict, List, Optional


class DirectedUnweightedGraphInAdjacencyList:
    """
    1、以adjacency list实现directed unweighted graph
    2、https://www.python.org/doc/essays/graphs/
    """

    def __init__(self, graph: Dict[str, List[str]]):
        self.graph = graph

    def find_path_dfs(self, start, end) -> List[str]:
        return self.__find_path_dfs_impl__(start, end)

    def __find_path_dfs_impl__(self, start, end, path=[]) -> Optional[List[str]]:
        """
        1、可能找不到从start到end的path，所以需要通过返回值来表示是否找到了path
        2、需要注意它避免dead loop的方式，它没有使用visited set，而是直接基于path
        :param start:
        :param end:
        :param path:
        :return: 如果找到了从start到end的path，则返回path，否则返回None
        """
        path = path + [start]
        if start == end:
            return path
        for adj_node in filter(lambda neighbor: neighbor not in path, self.graph.get(start, [])):  # move next
            new_path = self.__find_path_dfs_impl__(adj_node, end, path)
            if new_path:
                return new_path
        return None

    def find_all_paths_dfs(self, start, end) -> List[List[str]]:
        return self.__find_all_paths_dfs_impl__(start, end)

    def __find_all_paths_dfs_impl__(self, start, end, path=[]) -> List[List[str]]:
        path = path + [start]
        if start == end:
            return [path]
        paths = []
        for adj_node in filter(lambda neighbor: neighbor not in path, self.graph.get(start, [])):  # move next
            paths += self.__find_all_paths_dfs_impl__(adj_node, end, path)  # 合并两个linked list
        return paths

    def find_shortest_path_dfs(self, start: str, end: str):
        return self.__find_shortest_path_dfs_impl__(start, end)

    def __find_shortest_path_dfs_impl__(self, start, end, path=[]):
        """

        :param start:
        :param end:
        :return:
        """
        path = path + [start]
        if start == end:
            return path
        if start not in self.graph:
            return None
        shortest = None
        for adj_node in filter(lambda neighbor: neighbor not in path, self.graph.get(start, [])):  # move next
            new_path = self.__find_shortest_path_dfs_impl__(adj_node, end, path)
            if new_path:
                if not shortest or len(new_path) < len(shortest):
                    shortest = new_path
        return shortest

    def find_shortest_path_bfs(self, start, end):
        distance = {start: [start]}  # 既充当visited set又记录path
        q = deque(start)
        while len(q):
            node = q.popleft()
            for adj_node in filter(lambda neighbor: neighbor not in distance, self.graph.get(node, [])):
                distance[adj_node] = [distance[node], adj_node]  # 首次到达的距离肯定是最近的
                q.append(adj_node)
        return distance.get(end)


class TestStringMethods(unittest.TestCase):

    def test_find_path_dfs(self):
        self.graph = DirectedUnweightedGraphInAdjacencyList(
            {'A': ['B', 'C'],
             'B': ['C', 'D'],
             'C': ['D'],
             'D': ['C'],
             'E': ['F'],
             'F': ['C']}
        )
        start = 'A'
        end = 'C'
        path = self.graph.find_path_dfs(start, end)
        print(path)
        self.assertEqual(len(path), 3)
        self.assertEqual(path[0], start)
        self.assertEqual(path[-1], end)

    def test_find_all_paths_dfs(self):
        self.graph = DirectedUnweightedGraphInAdjacencyList(
            {'A': ['B', 'C'],
             'B': ['C', 'D'],
             'C': ['D'],
             'D': ['C'],
             'E': ['F'],
             'F': ['C']}
        )
        start = 'A'
        end = 'C'
        paths = self.graph.find_all_paths_dfs(start, end)
        print(paths)
        self.assertEqual(len(paths), 2)
        for path in paths:
            self.assertEqual(path[0], start)
            self.assertEqual(path[-1], end)

    def test_find_shortest_path_dfs(self):
        self.graph = DirectedUnweightedGraphInAdjacencyList(
            {'A': ['B', 'C'],
             'B': ['C', 'D'],
             'C': ['D'],
             'D': ['C'],
             'E': ['F'],
             'F': ['C']}
        )
        start = 'A'
        end = 'C'
        path = self.graph.find_shortest_path_dfs(start, end)
        print(path)
        self.assertEqual(len(path), 2)
        self.assertEqual(path[0], start)
        self.assertEqual(path[-1], end)


if __name__ == '__main__':
    unittest.main()

```

上述code是典范



## BFS

[LeetCode-127. 单词接龙-困难](https://leetcode.cn/problems/word-ladder/) 



## LeetCode

[LeetCode-127. 单词接龙-困难](https://leetcode.cn/problems/word-ladder/) 

