# Graph in Level、Layer、Hierachy



## wikipedia [Layered graph drawing](https://en.wikipedia.org/wiki/Layered_graph_drawing)





## Calculate level order of a graph

Kahn's algorithm根据依赖关系计算出start node，纯粹的BFS则需要由使用者指定start node。



### gpt-4o: use python to write a topological sorting algorithm that calculate level order

Topological sorting is a linear ordering of vertices in a directed acyclic graph (DAG) such that for every directed edge $ u \to v $, vertex $ u $ comes before vertex $ v $ in the ordering. To calculate the level order of a topological sort, we can use [Kahn's algorithm](https://en.wikipedia.org/wiki/Topological_sorting#Kahn's_algorithm), which is based on the concept of in-degrees.

Here's a Python implementation of a **topological sorting algorithm** that also calculates the level order of the nodes:

```python
from collections import deque, defaultdict

def topological_sort(graph):
    # Calculate in-degrees of all vertices
    in_degree = {u: 0 for u in graph}
    for u in graph:
        for v in graph[u]:
            in_degree[v] += 1

    # Queue for vertices with no incoming edges (in-degree of 0)
    queue = deque([u for u in in_degree if in_degree[u] == 0])
    
    # List to store the topological order
    topological_order = []
    
    # Level order list
    level_order = []
    
    while queue:
        level_size = len(queue)
        current_level = []
        
        for _ in range(level_size):
            u = queue.popleft()
            current_level.append(u)
            topological_order.append(u)
            
            # Decrease the in-degree of neighboring vertices
            for v in graph[u]:
                in_degree[v] -= 1
                # If in-degree becomes 0, add it to the queue
                if in_degree[v] == 0:
                    queue.append(v)
        
        # Add the current level to the level order
        level_order.append(current_level)

    # Check if there was a cycle in the graph
    if len(topological_order) != len(graph):
        raise ValueError("Graph is not a DAG (contains a cycle)")

    return topological_order, level_order

# Example usage
if __name__ == "__main__":
    # Create a directed graph using an adjacency list
    graph = {
        'A': ['B', 'C'],
        'B': ['D'],
        'C': ['D'],
        'D': ['E'],
        'E': []
    }

    try:
        top_order, levels = topological_sort(graph)
        print("Topological Order:", top_order)
        print("Level Order:", levels)
    except ValueError as e:
        print(e)
```

#### Explanation of the Code

1. **Graph Representation**: The graph is represented as a dictionary where keys are nodes and values are lists of adjacent nodes.

2. **In-Degree Calculation**: We calculate the in-degree (number of incoming edges) for each vertex.

3. **Queue Initialization**: We initialize a queue with all vertices that have an in-degree of 0 (i.e., no dependencies).

4. **Processing the Queue**: We process each vertex in the queue:
   - For each vertex, we add it to the topological order and the current level.
   - We decrease the in-degree of its neighbors. If any neighbor's in-degree becomes 0, we add it to the queue.

5. **Level Order Tracking**: We maintain a list of levels, where each level corresponds to the vertices processed in one iteration of the while loop.

6. **Cycle Detection**: If the length of the topological order does not match the number of vertices in the graph, it indicates that the graph is not a DAG (it contains a cycle).

#### Example Output

For the provided graph, the output will be:

```
Topological Order: ['A', 'B', 'C', 'D', 'E']
Level Order: [['A'], ['B', 'C'], ['D'], ['E']]
```

This indicates that the topological order of the nodes is `A, B, C, D, E`, and the level order shows that `A` is at level 0, `B` and `C` are at level 1, `D` is at level 2, and `E` is at level 3.



### BFS

To calculate the level order of a graph, we can perform a breadth-first search (BFS) starting from a given source node. The level order traversal will give us the nodes at each level of the graph, similar to how we would traverse a tree level by level.

Here's a Python program that implements this using an adjacency list representation of the graph:

```python
from collections import deque, defaultdict

def level_order_traversal(graph, start):
    # Initialize a queue for BFS
    queue = deque([start])
    # To keep track of visited nodes
    visited = set([start])
    # List to store the level order
    level_order = []

    while queue:
        level_size = len(queue)  # Number of nodes at the current level
        current_level = []

        for _ in range(level_size):
            node = queue.popleft()
            current_level.append(node)

            # Add unvisited neighbors to the queue
            for neighbor in graph[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)

        # Add the current level to the level order
        level_order.append(current_level)

    return level_order

# Example usage
if __name__ == "__main__":
    # Create a directed graph using an adjacency list
    graph = {
        'A': ['B', 'C'],
        'B': ['D', 'E'],
        'C': ['F'],
        'D': [],
        'E': ['F'],
        'F': []
    }

    start_node = 'A'
    levels = level_order_traversal(graph, start_node)
    print("Level Order Traversal:", levels)
```

#### Explanation of the Code

1. **Graph Representation**: The graph is represented as a dictionary where keys are nodes and values are lists of adjacent nodes.

2. **BFS Initialization**: We initialize a queue with the starting node and a set to keep track of visited nodes.

3. **Level Order Calculation**:
   - We loop until the queue is empty.
   - For each level, we determine the number of nodes at that level (`level_size`).
   - We process each node at the current level, adding its unvisited neighbors to the queue and marking them as visited.
   - After processing all nodes at the current level, we add the list of nodes at that level to the `level_order` list.

4. **Output**: The program prints the level order traversal of the graph starting from the specified node.

#### Example Output

For the provided graph, the output will be:

```
Level Order Traversal: [['A'], ['B', 'C'], ['D', 'E', 'F']]
```

This indicates that:
- Level 0 contains node `A`.
- Level 1 contains nodes `B` and `C`.
- Level 2 contains nodes `D`, `E`, and `F`.

#### Note

- The graph can be directed or undirected, and the algorithm will work as long as the graph is connected. If the graph is disconnected, you may need to run the BFS from each unvisited node to ensure all nodes are covered.
- The starting node can be changed to any node present in the graph to get the level order starting from that node.