# Bidirectional search

在 labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) 中提及了"双向 BFS 优化"，遂Google "double ended bfs"、"bidirectional bfs"，从而发现它的专业说法是"Bidirectional search"。

## wikipedia [Bidirectional search](https://en.wikipedia.org/wiki/Bidirectional_search)

**Bidirectional search** is a [graph search algorithm](https://en.wikipedia.org/wiki/Graph_search_algorithm) that finds a [shortest path](https://en.wikipedia.org/wiki/Shortest_path) from an initial [vertex](https://en.wikipedia.org/wiki/Vertex_(graph_theory)) to a goal vertex in a [directed graph](https://en.wikipedia.org/wiki/Directed_graph). It runs two simultaneous searches: one forward from the initial state, and one backward from the goal, stopping when the two meet.

> NOTE: 
>
> 一、stop condition是"stopping when the two meet"
>
> 二、需要注意的是，它主要用于"shortest path"



## 应用

### Bidirectional BFS

参见 `BFS-shortest-path` 章节。

### Bidirectional A* search

stackoverflow [Bidirectional A* (A-star) Search](https://stackoverflow.com/questions/3641741/bidirectional-a-a-star-search)

