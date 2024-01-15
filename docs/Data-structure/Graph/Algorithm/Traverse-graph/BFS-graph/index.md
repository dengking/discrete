# Breadth-first search







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







