# Graph cycle detection

素材:

[geeksforgeeks-Detect Cycle in a Directed Graph](https://www.geeksforgeeks.org/detect-cycle-in-a-graph/) 

[geeksforgeeks-Detect cycle in an undirected graph](https://www.geeksforgeeks.org/detect-cycle-undirected-graph/) 

## 思路

draft: back edge，一个node，由多条边可以到达它

## Directed graph VS undirected graph

Directed graph和undirected graph的cycle detection的实现有着明显的差别，一个典型的例子是对于相邻的两个node(NodeA、NodeB):

对于undirected graph，因为这两个node可以通过彼此到达对方，当使用adjacent list进行存储的时候，会存储两条边，但是在undirected graph中，两个相连的node是不构成环的，在undirected graph中，不存在两个node的环；

对于directed graph，它对方向有着严格的定义；如果它们之间存在着到达对方的边，那么它们就构成了环，因此在directed graph中，允许由两个node构成的环；

## DFS

Q: 为什么directed graph需要recursion stack，但是undirected graph不需要呢？

### Undirected graph

draft: 三指针: parent、current、children；在每个node，知道它的parent、children

draft: 

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



#### gpt-4-vision: why use parent in cycle detection of undirected graph by dfs

In **cycle detection** for an undirected graph using Depth-First Search (DFS), the concept of a "parent" node is crucial to correctly identify cycles. Here's why:

##### Understanding the Role of the Parent Node

When performing DFS on an undirected graph, each edge is traversed twice (once from each end). This can lead to false positives in **cycle detection** if we don't account for(理解) the direction from which we arrived at a node. The **parent node** helps us distinguish between a legitimate cycle and a simple backtracking to the previous node.

##### How the Parent Node Helps

1. **Avoid False Positives**:
   - When you visit a node `v` from its **parent node** `u`, you mark `v` as visited.
   - If you encounter a visited node `w` during the DFS, you need to check if `w` is the parent of `v`.
   - If `w` is the parent of `v`, it means you are simply backtracking to the node you came from, which is not a cycle.
   - If `w` is not the parent of `v`, it indicates that there is another path to `w`, forming a cycle.

2. **Correct Cycle Detection**:
   - By keeping track of the parent node, you ensure that you only detect cycles that involve more than two nodes.
   - This helps in correctly identifying cycles in the graph.

##### Example

Consider the following undirected graph:

```
  1 -- 2
  |  / |
  | /  |
  3 -- 4
```

##### DFS with Parent Tracking

1. Start DFS from node `1`:
   - Mark `1` as visited.
   - Move to node `2` (parent of `2` is `1`).

2. From node `2`:
   - Mark `2` as visited.
   - Move to node `3` (parent of `3` is `2`).

3. From node `3`:
   - Mark `3` as visited.
   - Move to node `4` (parent of `4` is `3`).

4. From node `4`:
   - Mark `4` as visited.
   - Move to node `2` (already visited, but parent of `4` is `3` and not `2`), indicating a cycle.

##### Code Example

Here is a Python implementation of cycle detection in an undirected graph using DFS with parent tracking:

```python
def dfs(graph, node, visited, parent):
    visited[node] = True
    for neighbor in graph[node]:
        if not visited[neighbor]:
            if dfs(graph, neighbor, visited, node):
                return True
        elif neighbor != parent:
            return True
    return False

def has_cycle(graph):
    visited = {node: False for node in graph}
    for node in graph:
        if not visited[node]:
            if dfs(graph, node, visited, -1):
                return True
    return False

# Example graph represented as an adjacency list
graph = {
    1: [2, 3],
    2: [1, 3, 4],
    3: [1, 2, 4],
    4: [2, 3]
}

print(has_cycle(graph))  # Output: True
```

##### Explanation

- **`dfs` Function**:
  - Takes the graph, current node, visited dictionary, and parent node as arguments.
  - Marks the current node as visited.
  - Recursively visits all unvisited neighbors.
  - If a visited neighbor is found that is not the parent, a cycle is detected.

- **`has_cycle` Function**:
  - Initializes the visited dictionary.
  - Iterates through all nodes, starting a DFS from each unvisited node.
  - Returns `True` if any DFS call detects a cycle.

##### Summary

Using the parent node in cycle detection for an undirected graph with DFS helps to:
- Avoid false positives by distinguishing between backtracking and actual cycles.
- Correctly identify cycles by ensuring that a visited node is not simply the parent of the current node.

This approach ensures accurate cycle detection in undirected graphs.



### Directed graph

#### gpt-4-vision

**Cycle detection** in a **directed graph** can be done using **Depth-First Search (DFS)** with an additional "**recursion stack**" (or "ancestors stack") to keep track of the nodes currently in the **recursion stack**. If a node is encountered that is already in the recursion stack, then a cycle exists.

Here's an example implementation of **cycle detection** in a directed graph using DFS in Python:

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

The key difference between **cycle detection** in directed and undirected graphs is the use of the recursion stack to keep track of the nodes in the current DFS path. If a node is revisited while it's still in the recursion stack, it indicates the presence of a cycle.



## BFS: Kahn's algorithm topological sorting

wikipedia [Topological sorting](https://en.wikipedia.org/wiki/Topological_sorting) 

> Any DAG has at least one topological ordering, and [algorithms](https://en.wikipedia.org/wiki/Algorithm) are known for constructing a topological ordering of any DAG in [linear time](https://en.wikipedia.org/wiki/Linear_time). 

显然，如果无法执行topological sorting，那么就存在环





## Disjoint set

需要注意的是: 这种算法所能够判定的circle和DFS所能够判定的circle是不同的，典型的例子就是 [LeetCode-684. Redundant Connection](https://leetcode.cn/problems/redundant-connection/) ，如果使用前面的DFS算法，它是不会判断保护circle的。

### [LeetCode-684. Redundant Connection](https://leetcode.cn/problems/redundant-connection/) 
