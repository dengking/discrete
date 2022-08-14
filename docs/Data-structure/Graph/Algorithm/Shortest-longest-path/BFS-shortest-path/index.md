# BFS-shortest-path

素材:

一、labuladong 

1、labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect)

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

2、labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) 

3、labuladong [益智游戏克星：BFS暴力搜索算法](https://mp.weixin.qq.com/s/Xn-oW7QRu8spYzL3B6zLxw)

二、wikipedia [Breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search)

> Finding the [shortest path](https://en.wikipedia.org/wiki/Shortest_path) between two nodes *u* and *v*, with path length measured by number of edges (an advantage over [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search))[[12\]](https://en.wikipedia.org/wiki/Breadth-first_search#cite_note-12)



## Bidirectional BFS

这是BFS-shortest-path中经常使用的一种technique。



## LeetCode

| 题目                                                         |      | 来源                                                         |
| ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| [LeetCode -111. 二叉树的最小深度-简单](https://leetcode.cn/problems/minimum-depth-of-binary-tree/) |      | labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) |
| [LeetCode-127. 单词接龙-困难](https://leetcode.cn/problems/word-ladder/) |      | Google "bidirectional bfs - leetcode"                        |
| [LeetCode-752. 打开转盘锁-中等](https://leetcode.cn/problems/open-the-lock/) |      | labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) |
| [LeetCode-773. 滑动谜题-困难](https://leetcode.cn/problems/sliding-puzzle/) |      | labuladong [益智游戏克星：BFS暴力搜索算法](https://mp.weixin.qq.com/s/Xn-oW7QRu8spYzL3B6zLxw) |
|                                                              |      |                                                              |







