# Graph cycle detection

素材:

geeksforgeeks [Detect Cycle in a Directed Graph](https://www.geeksforgeeks.org/detect-cycle-in-a-graph/)

在每个node，知道它的parent、children

back edge

## DFS

### Undirected graph

#### gpt-4-vision

**Cycle detection** in a graph can be performed using **Depth-First Search (DFS)**. The idea is to traverse the graph using DFS and keep track of the **visited nodes**. If during the traversal you encounter a node that has already been visited and is not the parent of the **current node**, then a cycle exists in the graph.

Here's an example implementation of **cycle detection** in an undirected graph using DFS in Python:

```python
# Graph represented as an adjacency list
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}

# Function to perform DFS and detect a cycle
def dfs_cycle_detection(graph, node, visited, parent):
    # Mark the current node as visited
    visited.add(node)

    # Visit all the neighbors of the current node
    for neighbor in graph[node]:
        # If the neighbor is not visited, visit it recursively
        if neighbor not in visited:
            if dfs_cycle_detection(graph, neighbor, visited, node):
                return True
        # If the neighbor is visited and is not the parent, a cycle is detected
        elif neighbor != parent:
            return True

    # No cycle detected
    return False

# Function to check if the graph contains a cycle
def has_cycle(graph):
    visited = set()
    for node in graph:
        # If the node is not visited, start DFS from it
        if node not in visited:
            if dfs_cycle_detection(graph, node, visited, None):
                return True
    return False

# Check if the graph has a cycle
print(has_cycle(graph))  # Output: True
```

In this example, the `dfs_cycle_detection` function takes the graph, the current node, a set of **visited nodes**, and the **parent node** of the current node. It returns `True` if a cycle is detected and `False` otherwise.

The `has_cycle` function iterates over all nodes in the graph and starts **DFS** from each **unvisited node**. If any **DFS** call returns `True`, it means a **cycle** is detected, and the function returns `True`. If no cycles are detected after visiting all nodes, the function returns `False`.

Note that this implementation is for **undirected graphs**. For **directed graphs**, **cycle detection** would require additional logic to handle **back edges** and **cross edges**.



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

    def __dfs_cycle_detection__(self, node, visited: Set, parent):
        """
        Function to perform DFS and detect a cycle
        """
        # Mark the current node as visited
        visited.add(node)

        # Visit all the neighbors of the current node
        for adj_node in self.graph[node]:
            # If the neighbor is not visited, visit it recursively
            if adj_node not in visited:
                if self.__dfs_cycle_detection__(adj_node, visited, node):
                    return True
            # If the neighbor is visited and is not the parent, a cycle is detected
            elif adj_node != parent:
                return True

        # No cycle detected
        return False

    def has_cycle(self):
        """
        function to check if the graph contains a cycle
        """
        visited = set()
        for node in self.graph:
            # If the node is not visited, start DFS from it
            if node not in visited:
                if self.__dfs_cycle_detection__(node, visited, None):
                    return True
        return False


class TestSpanningTreeConstructionAlgorithm(unittest.TestCase):
    def test_spanning_tree_constructed_by_bfs(self):
        # Graph represented as an adjacency list
        graph = {
            'A': ['B', 'C'],
            'B': ['A', 'D', 'E'],
            'C': ['A', 'F'],
            'D': ['B'],
            'E': ['B', 'F'],
            'F': ['C', 'E']
        }
        directed_unweighted_graph_in_adj_list = DirectedUnweightedGraphInAdjacencyList(graph)
        flag = directed_unweighted_graph_in_adj_list.has_cycle()
        self.assertTrue(flag)


if __name__ == '__main__':
    unittest.main()

```



### Directed graph

#### gpt-4-vision

**Cycle detection** in a **directed graph** can be done using **Depth-First Search (DFS)** with an additional "**recursion stack**" (or "ancestors stack") to keep track of the nodes currently in the **recursion stack**. If a node is encountered that is already in the recursion stack, then a cycle exists.

Here's an example implementation of cycle detection in a directed graph using DFS in Python:

```python
# Directed graph represented as an adjacency list
graph = {
    'A': ['B', 'C'],
    'B': ['D'],
    'C': ['F'],
    'D': ['E'],
    'E': ['B'],  # This edge creates a cycle
    'F': []
}

# Function to perform DFS and detect a cycle
def dfs_cycle_detection(graph, node, visited, recursion_stack):
    # Mark the current node as visited and add it to the recursion stack
    visited.add(node)
    recursion_stack.add(node)

    # Visit all the neighbors of the current node
    for neighbor in graph[node]:
        # If the neighbor is not visited, visit it recursively
        if neighbor not in visited:
            if dfs_cycle_detection(graph, neighbor, visited, recursion_stack):
                return True
        # If the neighbor is in the recursion stack, a cycle is detected
        elif neighbor in recursion_stack:
            return True

    # Remove the node from the recursion stack before the function ends
    recursion_stack.remove(node)
    return False

# Function to check if the graph contains a cycle
def has_cycle(graph):
    visited = set()
    recursion_stack = set()
    for node in graph:
        # If the node is not visited, start DFS from it
        if node not in visited:
            if dfs_cycle_detection(graph, node, visited, recursion_stack):
                return True
    return False

# Check if the graph has a cycle
print(has_cycle(graph))  # Output: True
```

In this example, the `dfs_cycle_detection` function takes the graph, the current node, a set of visited nodes, and a set representing the **recursion stack**. It returns `True` if a cycle is detected and `False` otherwise.

The `has_cycle` function iterates over all nodes in the graph and starts DFS from each unvisited node. If any DFS call returns `True`, it means a cycle is detected, and the function returns `True`. If no cycles are detected after visiting all nodes, the function returns `False`.

The key difference between cycle detection in directed and undirected graphs is the use of the recursion stack to keep track of the nodes in the current DFS path. If a node is revisited while it's still in the recursion stack, it indicates the presence of a cycle.





## [LeetCode-684. Redundant Connection](https://leetcode.cn/problems/redundant-connection/)
