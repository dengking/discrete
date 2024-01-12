# Breadth-first search

一、labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 

1、其中对queue machine有着非常好的描述

2、其中对while-从上到下+for-同层从左到右到解释非常好

3、这篇文章对BFS binary tree、BFS multiple tree、BFS graph都进行了介绍

![image](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdGiaE70bfibhZwtP90zPlWicsgQMNtxF34YCQsbbOHcuXprVr3WN4NojM8d43crlggwmMFksq6C4ibvfg/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)



4、这篇文章中给出来具体的code

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



二、labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) 

相比之下，这篇文章不及 labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 。

三、labuladong [益智游戏克星：BFS暴力搜索算法](https://mp.weixin.qq.com/s/Xn-oW7QRu8spYzL3B6zLxw)

四、geeksforgeeks [Depth First Search or DFS for a Graph](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)





## Queue machine

使用BFS的算法其实非常类似于queue machine，这是和 [stack machine](https://en.wikipedia.org/wiki/Stack_machine) 相对应的。

在 baeldung [Difference Between BFS and Dijkstra’s Algorithms](https://www.baeldung.com/cs/graph-algorithms-bfs-dijkstra) 中，对queue machine的流程图有着非常好的描述:



> ![img](./SSSP-Algorithm-1024x339.png)



### Queue machine的导火索

queue machine需要首先喂入一个节点，这样while循环条件才能够满足，这样才能够启动machine。这是在阅读 labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 时想到的。

Queue machine算法都非常类似于一个机器，加入一点原料后，开始运转。

### Queue machine steps:

1、initialization

2、expand





### medium [Top 25 Breadth First Search (BFS) Practice Problems](https://medium.com/techie-delight/top-20-breadth-first-search-bfs-practice-problems-ac2812283ab1)



## Space complexity

[LeetCode-【宫水三叶】一题三解：「双向 BFS」& 「AStar 算法」&「IDA* 算法」](https://leetcode.cn/problems/open-the-lock/solution/gong-shui-san-xie-yi-ti-shuang-jie-shuan-wyr9/)

> 使用朴素 BFS 进行求解时，队列中最多会存在“两层”的搜索节点。
>
> 因此搜索空间的上界取决于 **目标节点所在的搜索层次的深度所对应的宽度**。

