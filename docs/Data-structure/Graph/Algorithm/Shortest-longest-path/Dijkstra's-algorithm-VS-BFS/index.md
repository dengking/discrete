# BFS-VS-Dijkstra

一、在 baeldung [Difference Between BFS and Dijkstra’s Algorithms](https://www.baeldung.com/cs/graph-algorithms-bfs-dijkstra) 中有着非常好的总结:

> BFS calculates the shortest paths in unweighted graphs. 
>
> Dijkstra’s algorithm calculates the same thing in weighted graphs.

其实在我的看来，"Dijkstra’s algorithm"其实是属于BFS的。

二、labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 

这篇文章非常好

三、BFS中的step就是目标值，它不需要"edge relaxation"。

## baeldung [Difference Between BFS and Dijkstra’s Algorithms](https://www.baeldung.com/cs/graph-algorithms-bfs-dijkstra) 

### 1. Overview

In [graph theory](https://www.baeldung.com/cs/graphs), **SSSP (Single Source Shortest Path) algorithms solve the problem of finding the shortest path from a starting node (source), to all other nodes inside the graph**. The main algorithms that fall under this definition are [Breadth-First Search (BFS)](https://www.baeldung.com/java-breadth-first-search) and [Dijkstra](https://www.baeldung.com/java-dijkstra)‘s algorithms.

> NOTE:
>
> 两者都可以用于解决SSSP。

### 2. General Algorithm

> NOTE: 其实这可以概括为 "queue machine"

Let’s see a flow chart that better explains the general algorithm:

![img](https://www.baeldung.com/wp-content/uploads/sites/4/2020/05/SSSP-Algorithm-1024x339.png)

### 3. BFS Algorithm



### 4. Dijkstra’s Algorithm



## labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 

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