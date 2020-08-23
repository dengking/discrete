# DFS and BFS

这是两种最最常见的search policy。



## 维基百科[Depth-first search](https://en.wikipedia.org/wiki/Depth-first_search)





## 维基百科[Breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search)





## BFS VS DFS

### What are the advantages of breadth-first search (BFS) over depth-first search (DFS)? 

Answer: BFS is complete and optimal, while DFS is not guaranteed to halt when there are loops. 

> NOTE: DFS的loop问题是可以避免的

### What is the advantage of DFS over BFS?

 Answer: If `m` is the maximum path length and `b` is the branching factor, the space complexity for DFS is `mb` while for BFS it is $b^m$.

