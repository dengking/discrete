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

            for adj_node, adj_distance in self.graph_in_adj_list.get(current_node, {}).items():
                new_distance = current_distance + adj_distance
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
                break
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

    def test_shortest_path_to_single_node_1(self):
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

    def test_shortest_path_to_single_node_2(self):
        """
        这个例子是展示edge relaxation的典型
        :return:
        """
        graph = {
            'A': {'B': 1, 'C': 3},
            'B': {'C': 1},
            'C': {},
        }
        self.dijkstra = DijkstraAlgorithmInFiniteGraphTrackingShortestPathGraph(graph)
        start = 'A'
        end = 'C'
        distance, shortest_path_graph = self.dijkstra.shortest_path_to_single_node(start, end)
        self.assertEqual(distance, 2)
        paths = self.dijkstra.reconstruct_all_path(shortest_path_graph, end)
        print(paths)
        self.assertEqual(len(paths), 1)
        self.assertEqual(paths[0], ['A', 'B', 'C'])

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

    def test_negative_edge(self):
        """
        这个例子验证这种实现能够处理negative weight edge，它来自:
        https://stackoverflow.com/a/6799344
        需要注意: 虽然上述链接中否定了Dijkstra's algorithm不能够处理negative weight edge，但是它的回答是不准确的，
        它的回答是基于使用了visited set的Dijkstra's algorithm implementation，但是上述implementation没有使用visited set,
        它是能够处理negative weight edge的
        :return:
        """
        graph = {
            'A': {'B': 1, 'C': 0, 'D': 99},
            'B': {'C': 1},
            'C': {},
            'D': {'B': -300},

        }
        self.dijkstra = DijkstraAlgorithmInFiniteGraphTrackingShortestPathGraph(graph)
        start = 'A'
        distances, shortest_path_graph = self.dijkstra.shortest_path_to_all_nodes(start)
        self.assertEqual(distances['C'], -200)


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
