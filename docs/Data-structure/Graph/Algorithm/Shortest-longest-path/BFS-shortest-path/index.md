# BFS-shortest-path-for-unweighted-directed-graph

## Code

首次到达的距离肯定是最近的，因此不需要进行relaxation。

`distance` 既充当visited set又记录path

```python
import unittest
from collections import deque
from typing import *


class DirectedUnweightedGraphInAdjacencyList:
    """
    1、以adjacency list实现directed unweighted graph
    2、https://www.python.org/doc/essays/graphs/
    """

    def __init__(self, graph: Dict[str, List[str]]):
        self.graph = graph

    def find_shortest_path_bfs1(self, start, end) -> List:
        distance = {start: [start]}  # 既充当visited set又记录path
        q = deque(start)
        while len(q):
            node = q.popleft()
            for adj_node in filter(lambda neighbor: neighbor not in distance, self.graph.get(node, [])):
                distance[adj_node] = distance[node] + [adj_node]  # 首次到达的距离肯定是最近的
                q.append(adj_node)
        return distance.get(end)

    def find_shortest_path_bfs2(self, start, end) -> int:
        distance: Dict[str, int] = {start: 0}  # 既充当visited set又记录path
        q = deque(start)
        while len(q):
            node = q.popleft()
            for adj_node in filter(lambda neighbor: neighbor not in distance, self.graph.get(node, [])):
                distance[adj_node] = distance[node] + 1  # 首次到达的距离肯定是最近的
                q.append(adj_node)
        return distance.get(end)

    def find_shortest_path_bfs3(self, start, end) -> int:
        distance: Dict[str, int] = {start: 0}  # 既充当visited set又记录path
        q = deque(start)
        step_cnt = 0
        while len(q):
            size = len(q)
            for _ in range(size):
                node = q.popleft()
                for adj_node in filter(lambda neighbor: neighbor not in distance, self.graph.get(node, [])):
                    distance[adj_node] = step_cnt  # 首次到达的距离肯定是最近的
                    q.append(adj_node)
            step_cnt += 1
        return distance.get(end)


class TestStringMethods(unittest.TestCase):

    def test_find_shortest_path_bfs(self):
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
        path = self.graph.find_shortest_path_bfs1(start, end)
        print(path)
        path_len2 = self.graph.find_shortest_path_bfs2(start, end)
        path_len3 = self.graph.find_shortest_path_bfs2(start, end)

        self.assertEqual(len(path) - 1, path_len2)
        self.assertEqual(len(path) - 1, path_len3)
        self.assertEqual(path[0], start)
        self.assertEqual(path[-1], end)


if __name__ == '__main__':
    unittest.main()

```



## 素材

### labuladong 

labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect)

> NOTE: 这篇文章中给出来具体的code

```java
// 输入起点，进行 BFS 搜索
int BFS(Node start) {
    Queue<Node> q; // 核心数据结构
    Set<Node> visited; // 避免走回头路

    q.offer(start); // 将起点加入队列
    visited.add(start);

    int step = 0; // 记录搜索的步数
    while (q not empty) {
        int sz = q.size();
        /* 将当前队列中的所有节点向四周扩散一步 */
        for (int i = 0; i < sz; i++) {
            Node cur = q.poll();
            printf("从 %s 到 %s 的最短距离是 %s", start, cur, step);

            /* 将 cur 的相邻节点加入队列 */
            for (Node x : cur.adj()) {
                if (x not in visited) {
                    q.offer(x);
                    visited.add(x);
                }
            }
        }
        step++;
    }
}
```

再加上 BFS 算法利用`for`循环一层一层向外扩散的逻辑和`visited`集合防止走回头路的逻辑，当你每次从队列中拿出节点`cur`的时候，从`start`到`cur`的最短权重就是`step`记录的步数。

labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) 

labuladong [益智游戏克星：BFS暴力搜索算法](https://mp.weixin.qq.com/s/Xn-oW7QRu8spYzL3B6zLxw)

### wikipedia [Breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search)

Finding the [shortest path](https://en.wikipedia.org/wiki/Shortest_path) between two nodes *u* and *v*, with path length measured by number of edges (an advantage over [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search))





## Bidirectional BFS

一、这是在 labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) 中发现的，BFS-shortest-path中经常使用的一种technique。

二、Google "bidirectional bfs - leetcode"-[LeetCode-Problems on Leetcode that uses Bidirectional BFS](https://leetcode.com/discuss/general-discussion/1170553/problems-on-leetcode-that-uses-bidirectional-bfs)

1、[LeetCode-752. 打开转盘锁-中等](https://leetcode.cn/problems/open-the-lock/) 

https://leetcode.com/problems/open-the-lock/discuss/908020/java-4ms-beats-100-bidirectional-bfs-with-explanation

2、[LeetCode-127. 单词接龙-困难](https://leetcode.cn/problems/word-ladder/) 

https://leetcode.com/problems/word-ladder/discuss/180745/Java-Bidirectional-BFS-in-21-ms

https://leetcode.com/problems/word-ladder/discuss/650367/python-bidirectional-bfs

https://leetcode.com/problems/word-ladder/discuss/729726/c-bidirectional-bfs

3、[LeetCode-1345. Jump Game IV-困难](https://leetcode.com/problems/jump-game-iv/)

https://leetcode.com/problems/jump-game-iv/discuss/507950/java-bidirectional-bfs

4、[LeetCode-1197. 进击的骑士-困难](https://leetcode.cn/problems/minimum-knight-moves/)

https://leetcode.com/discuss/explore/graph/1531509/Bidirectional-BFS

5、[LeetCode-279. Perfect Squares-中等](https://leetcode.com/problems/perfect-squares/)

https://leetcode.com/problems/perfect-squares/discuss/1736365/C%2B%2B-Bidirectional-BFS

三、geeksforgeeks [Bidirectional Search](https://www.geeksforgeeks.org/bidirectional-search/)

其中给出了bidirectional-BFS的sample code。

四、efficientcodeblog [Bidirectional Search : Two-End BFS](https://efficientcodeblog.wordpress.com/2017/12/13/bidirectional-search-two-end-bfs/)



## LeetCode

| 题目                                                         |      | 来源                                                         |
| ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| [LeetCode -111. 二叉树的最小深度-简单](https://leetcode.cn/problems/minimum-depth-of-binary-tree/) |      | labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) |
| [LeetCode-127. 单词接龙-困难](https://leetcode.cn/problems/word-ladder/) |      | Google "bidirectional bfs - leetcode"                        |
| [LeetCode-279. Perfect Squares-中等](https://leetcode.com/problems/perfect-squares/) |      |                                                              |
| [LeetCode-752. 打开转盘锁-中等](https://leetcode.cn/problems/open-the-lock/) |      | labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) |
| [LeetCode-773. 滑动谜题-困难](https://leetcode.cn/problems/sliding-puzzle/) |      | labuladong [益智游戏克星：BFS暴力搜索算法](https://mp.weixin.qq.com/s/Xn-oW7QRu8spYzL3B6zLxw) |
| [LeetCode-1197. 进击的骑士-困难](https://leetcode.cn/problems/minimum-knight-moves/) |      |                                                              |
| [LeetCode-1345. Jump Game IV-困难](https://leetcode.com/problems/jump-game-iv/) |      |                                                              |
|                                                              |      |                                                              |
|                                                              |      |                                                              |
|                                                              |      |                                                              |



