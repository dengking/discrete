# [LeetCode-133. Clone Graph-Medium](https://leetcode.cn/problems/clone-graph/) 



## DFS   

### Python

初次尝试的使用的是`visited_set`，由于这个题目提供的graph中是可能存在circle的(显然存在循环依赖)，如果使用`visited_set`，显然会导致在进行dfs的时候，位于path的后部分的node，如果它依赖于前面的node，而前面的node已经位于`visited_set`中来，那么显然在构建它的neighbors的时候，所构建的是一个empty linked list。

总的来说: 这种方式的另外一个弊端是: 它会导致少构建neighbors比实际少。

那如何解决这个问题呢？将`visited_set`转换为 `new_node_map`，进行寄存然后直接取

```python
from typing import *


# Definition for a Node.
class Node:
    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class Solution:

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        new_node_map = {}
        return self.dfs(node, new_node_map)

    def dfs(self, node: Optional['Node'], new_node_map: Dict[Node, Node]) -> Optional['Node']:
        if node is None:
            return None
        elif node in new_node_map:
            return new_node_map[node]
        else:
            new_node = Node(node.val)
            new_node_map[node] = new_node
            if node.neighbors:
                new_node.neighbors = [new_neighbor for new_neighbor in [
                    self.dfs(neighbor, new_node_map) for neighbor in node.neighbors
                ] if new_neighbor is not None]
            return new_node


if __name__ == '__main__':
    n1 = Node(1)
    n2 = Node(2)
    n3 = Node(3)
    n4 = Node(4)
    n1.neighbors = [n2, n4]
    n2.neighbors = [n1, n3]
    n3.neighbors = [n2, n4]
    n4.neighbors = [n1, n3]
    solu = Solution()
    solu.cloneGraph(n1)

```

