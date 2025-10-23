# Connectivity &Connected-component&Transitive-closure

## wikipedia [Connectivity (graph theory)](https://en.wikipedia.org/wiki/Connectivity_(graph_theory))

## Dynamic connectivity

---

> Reference:
> 
> [stanford-CS166-Graph connectivity](https://web.stanford.edu/class/cs166/)  

---

### wikipedia [Dynamic connectivity](https://en.wikipedia.org/wiki/Dynamic_connectivity)

In [computing](https://en.wikipedia.org/wiki/Computing) and [graph theory](https://en.wikipedia.org/wiki/Graph_theory), a **dynamic connectivity** structure is a data structure that dynamically maintains information about the connected components of a graph.

The set *V* of vertices of the graph is fixed, but the set *E* of edges can change. The three cases, in order of difficulty, are:

- Edges are only added to the graph (this can be called *incremental connectivity*);
- Edges are only deleted from the graph (this can be called *decremental connectivity*);
- Edges can be either added or deleted (this can be called *fully dynamic connectivity*).

After each addition/deletion of an edge, the dynamic connectivity structure should adapt 

## Connected component&Transitive-closure

connected component和transitive closure之间的关系: 

将relation使用graph来进行表示，对于具备transitive性质的relation，对relation计算transitive closure，显然每个closure对应一个connected component。

draft: [partition of set](https://en.wikipedia.org/wiki/Partition_of_a_set)、[equivalence relation](https://en.wikipedia.org/wiki/Equivalence_relation) 

总结: transitive closure VS disjoint-set (从set、relation、graph角度进行分析)

a. transitive closure是求解各个connected component的，如果输入已经是graph了，那么使用这个算法会比较方便

b. disjoint-set(union-find-set)用于快速判断两个node是否属于同一个component，如果输入是discrete的，那么使用它会比较方便

### wikipedia [Component (graph theory)](https://en.wikipedia.org/wiki/Component_(graph_theory))

### Algorithms

Closures of Relations(从relation-structure的角度来进行分析)

1. 沿着relation不断地进行expand

2. one-by-one

The problem can also be solved by:

- [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm) 
- repeated [breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search) or [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search) starting from each node of the graph 
- Disjoint-set(union-find-set)

根据graph representation，选择合适的algorithm。

#### [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm)

---

> References: 
> 
> wikipedia [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm)
> 
> winona [CS 440 Theory of Algorithms / CS 468 Algorithms in Bioinformatics](https://cs.winona.edu/lin/cs440/ch08-2.pdf) 

---

#### Repeated BFS

wikipedia [Transitive_closure](https://en.wikipedia.org/wiki/Transitive_closure) 

> "repeated [breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search) or [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search) starting from each node of the graph"

Graph-repeated-BFS-flood-fill-transitive-closure

1. BFS flood fill的方式来找到connected component

2. repeated执行上述步骤，保证能够找到所有的connected component

注意，需要为每个node都执行一次。

##### Java

```Java
package com.test.www;

import java.util.*;

public class GraphTransitiveClosure<T> {
    private Map<T, Set<T>> adjacencyList; // 图的adjacent list表示方式
    private List<Set<T>> closures; // 传递闭包

    public GraphTransitiveClosure(Map<T, Set<T>> adjacencyList) {
        this.adjacencyList = adjacencyList;
        initClosures();

    }
    /**
     * @param edges 图的边
     */
    public GraphTransitiveClosure(List<List<T>> edges) {
        adjacencyList = edges.parallelStream().collect(
                HashMap::new,
                (Map<T, Set<T>> map, List<T> edge) -> {
                    final Set<T> groups1 = map.getOrDefault(edge.get(0), new HashSet<>());
                    groups1.add(edge.get(1));
                    map.put(edge.get(0), groups1);

                    final Set<T> groups2 = map.getOrDefault(edge.get(1), new HashSet<>());
                    groups2.add(edge.get(0));
                    map.put(edge.get(1), groups2);
                },
                (Map<T, Set<T>> map1, Map<T, Set<T>> map2) -> {
                    map2.forEach((index, otherIndexes) -> {
                        if (map1.containsKey(index)) {
                            map1.get(index).addAll(otherIndexes);
                        } else {
                            map1.put(index, otherIndexes);
                        }
                    });
                });
        initClosures();
    }

    private void initClosures() {
        final Set<T> visitedSet = new HashSet<>();
        closures = new ArrayList<>();
        for (T node : adjacencyList.keySet()) {
            if (!visitedSet.contains(node)) {
                closures.add(initClosure(node, visitedSet));
            }
        }
    }

    /**
     * BFS
     */
    private Set<T> initClosure(T node, Set<T> visitedSet) {
        Set<T> closure = new HashSet<>();
        Queue<T> queue = new LinkedList<>();
        queue.add(node);
        visitedSet.add(node);

        while (!queue.isEmpty()) {
            final T curNode = queue.remove();
            closure.add(curNode);
            for (T otherNode : adjacencyList.getOrDefault(curNode, new HashSet<>())) {
                if (!visitedSet.contains(otherNode)) {
                    visitedSet.add(otherNode);
                    queue.add(otherNode);
                }
            }
        }

        return closure;
    }

    public List<Set<T>> getClosures() {
        return closures;
    }
}
```

#### Disjoint-set(union-find-set)

disjoint-set(union-find-set): disjoint-set中的set正好和connected-component相对应

```python
from collections import defaultdict
from typing import *


class DisjointSet:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    def find(self, u):
        if self.parent[u] != u:
            self.parent[u] = self.find(self.parent[u])  # Path compression
        return self.parent[u]

    def union(self, u, v):
        root_u = self.find(u)
        root_v = self.find(v)
        if root_u != root_v:
            if self.rank[root_u] > self.rank[root_v]:
                self.parent[root_v] = root_u
            elif self.rank[root_u] < self.rank[root_v]:
                self.parent[root_u] = root_v
            else:
                self.parent[root_v] = root_u
                self.rank[root_u] += 1


def find_connected_components(edges: List, n: int):
    ds = DisjointSet(n)

    # Perform union operation for each edge
    for u, v in edges:
        ds.union(u, v)

    # Find the root of each vertex
    components = defaultdict(list)
    for vertex in range(n):
        root = ds.find(vertex)
        components[root].append(vertex)

    return list(components.values())


def main():
    # Example usage
    edges = [(0, 1), (1, 2), (3, 4)]
    n = 5  # Number of vertices
    connected_components = find_connected_components(edges, n)
    print("Connected Components:", connected_components)


if __name__ == '__main__':
    main()
```

### LeetCode

[LeetCode-1319. Number of Operations to Make Network Connected](https://leetcode.com/problems/number-of-operations-to-make-network-connected/) 

disjoint set中set的个数

[LeetCode-2685. Count the Number of Complete Components](https://leetcode.com/problems/count-the-number-of-complete-components/) 

disjoint set中set的个数

## Connected component border

一. 素材

1. wikipedia [Jump flooding algorithm](https://en.wikipedia.org/wiki/Jump_flooding_algorithm)

> The [grand strategy game](https://en.wikipedia.org/wiki/Grand_strategy_wargame) developer [Paradox Interactive](https://en.wikipedia.org/wiki/Paradox_Interactive) uses the JFA to render borders between countries and provinces.

二. labuladong [Flood Fill 算法详解](https://mp.weixin.qq.com/s/Y7snQIraCC6PRhj9ZSnlzw) 

其中提出了给connected component border进行染色的问题

### LeetCode

[LeetCode-1034. 边框着色-中等](https://leetcode.cn/problems/coloring-a-border/) 

## Connected-component labeling

参见 `Connected-component-labeling` 章节
