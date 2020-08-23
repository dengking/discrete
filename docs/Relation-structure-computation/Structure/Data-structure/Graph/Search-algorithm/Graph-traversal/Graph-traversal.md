# Graph traversal



## 维基百科[Graph traversal](https://en.wikipedia.org/wiki/Graph_traversal)



## graph traversal and circle

graph的结构是比tree要复杂的，所以相比于tree它能够表达更多的relation；

graph是允许circle，因此在各种algorithm中，需要对circle进行特殊处理。

graph是运行disconnect。

在graph traversal中，为了避免由于circle而导致的dead loop，graph traversal algorithm普遍采用的是“标记已经visit过的vertex，对于已经visit过的vertex，再次遇到的时候，直接pass掉”。



## Dijkstra's algorithm and breadth-first search

Dijkstra's algorithm和breadth-first search非常类似