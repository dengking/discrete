import heapq
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
        path = []
        self.__find_path_dfs_impl__(start, end, path)
        return path

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
        if start not in self.graph:
            return None
        for node in self.graph[start]:  # move next
            if node not in path:
                new_path = self.__find_path_dfs_impl__(node, end, path)
                if new_path:
                    return new_path
        return None

    def find_all_paths_dfs(self, start, end) -> List[List[str]]:
        return self.__find_all_paths_dfs_impl__(start, end)

    def __find_all_paths_dfs_impl__(self, start, end, path=[]):
        path = path + [start]
        if start == end:
            return [path]
        if start not in self.graph:
            return []
        paths = []
        for node in self.graph[start]:  # move next
            if node not in path:
                paths += self.__find_path_dfs_impl__(node, end, path)
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
        for node in self.graph[start]:
            if node not in path:
                new_path = self.__find_shortest_path_dfs_impl__(node, end, path)
                if new_path:
                    if not shortest or len(new_path) < len(shortest):
                        shortest = new_path
        return shortest

    def find_path_bfs(self, start: str, end: str) -> Optional[List[str]]:
        """

        :param start:
        :param end:
        :return:
        """

    def find_shortest_path_bfs(self, start, end):
        dist = {start: [start]}
        q = deque(start)
        while len(q):
            at = q.popleft()
            for next_node in self.graph[at]:
                if next_node not in dist:
                    dist[next_node] = [dist[at], next_node]
                    q.append(next_node)
        return dist.get(end)

    def dijkstra(self, start):
        distances = {node: float('inf') for node in self.graph}  # 从start到各个node的距离，这里使用的是dict comprehension语法
        distances[start] = 0

        heap = [(0, start)]
        while heap:
            current_distance, current_node = heapq.heappop(heap)

            if current_distance > distances[current_node]:
                continue
            if current_node not in self.graph:
                continue
            for neighbor in self.graph[current_node]:
                distance = current_distance + 1  # Unweighted graph, so distance is always 1
                if distance < distances[neighbor]:
                    distances[neighbor] = distance
                    heapq.heappush(heap, (distance, neighbor))

        return distances


class TestStringMethods(unittest.TestCase):
    def __init__(self):
        super().__init__()
        self.graph = DirectedUnweightedGraphInAdjacencyList(
            {'A': ['B', 'C'],
             'B': ['C', 'D'],
             'C': ['D'],
             'D': ['C'],
             'E': ['F'],
             'F': ['C']}
        )

    def test_upper(self):
        self.assertEqual('foo'.upper(), 'FOO')

    def test_isupper(self):
        self.assertTrue('FOO'.isupper())
        self.assertFalse('Foo'.isupper())

    def test_split(self):
        s = 'hello world'
        self.assertEqual(s.split(), ['hello', 'world'])
        # check that s.split fails when the separator is not a string
        with self.assertRaises(TypeError):
            s.split(2)


if __name__ == '__main__':
    unittest.main()
