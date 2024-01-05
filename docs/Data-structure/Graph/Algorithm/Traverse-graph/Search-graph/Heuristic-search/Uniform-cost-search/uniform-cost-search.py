import heapq
import unittest
from typing import Dict


def uniform_cost_search(graph: Dict[str, Dict[str, int]], start: str, goal: str):
    # Priority queue to hold the frontier with path cost
    frontier = [(0, start, [])]
    heapq.heapify(frontier)

    # Set to keep track of visited nodes
    explored = set()

    while frontier:
        # Pop the vertex with the smallest cost
        cost, current_vertex, path = heapq.heappop(frontier)

        # If the goal is reached, return the cost and path
        if current_vertex == goal:
            return cost, path + [current_vertex]

        # Mark the node as explored
        explored.add(current_vertex)

        # Add neighbors to the frontier if they haven't been explored
        for neighbor, neighbor_cost in graph[current_vertex].items():
            if neighbor not in explored:
                heapq.heappush(frontier, (cost + neighbor_cost, neighbor, path + [current_vertex]))

    return float("inf"), []  # If the goal is not reachable


class TestUniformCostSearch(unittest.TestCase):
    def test_uniform_cost_search_1(self):
        # Example usage:
        graph = {
            'A': {'B': 2, 'C': 5},
            'B': {'C': 1, 'D': 4},
            'C': {'D': 1, 'E': 7},
            'D': {'E': 3},
            'E': {}
        }

        start = 'A'
        goal = 'E'
        cost, path = uniform_cost_search(graph, start, goal)
        print(f"Cost: {cost}, Path: {path}")
        self.assertEqual(cost, 7)

    def test_uniform_cost_search_2(self):
        """
        一个非常简单的展示relaxation的例子
        :return:
        """
        # Example usage:
        graph = {
            'A': {'B': 1, 'C': 3},
            'B': {'C': 1},
            'C': {},
        }

        start = 'A'
        goal = 'C'
        cost, path = uniform_cost_search(graph, start, goal)
        print(f"Cost: {cost}, Path: {path}")
        self.assertEqual(cost, 2)


if __name__ == '__main__':
    unittest.main()
