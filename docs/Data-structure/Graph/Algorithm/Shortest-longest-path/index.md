# Shortest and longest path 



## 算法总结

素材:

1、[【宫水三叶】涵盖所有的「存图方式」与「最短路算法（详尽注释）」](https://leetcode.cn/problems/network-delay-time/solution/gong-shui-san-xie-yi-ti-wu-jie-wu-chong-oghpz/)

2、[LeetCode-五种最短路径算法总结](https://leetcode.cn/problems/network-delay-time/solution/dirkdtra-by-happysnaker-vjii/)

|      | Algorithm                                                    | weighted/unweighted | 问题类型                                                     | 算法思想      | Computation complexity |
| ---- | ------------------------------------------------------------ | ------------------- | ------------------------------------------------------------ | ------------- | ---------------------- |
| 1    | [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm) | weighted            | "A single execution of the algorithm will find the lengths (summed weights) of shortest paths between all pairs of vertices" | **穷举+DP**   | $O(V*E)$               |
| 2    | [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm) | weighted            | Single source shortest path(SSSP)                            | **greedy+dp** |                        |
| 3    | [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) | weighted            | Single source shortest path(SSSP)                            | **穷举+DP**   | $O(V^3)$               |
| 4    | BFS                                                          | unweighted          |                                                              |               |                        |



### Common issue



#### 解的表达方式

1、SSSP

```C++
void Dijkstra(Vertex source,Weight dist[], Vertex prev[])const; 

//dist[]用来保存最终的结果，

//prev[]用来记录每个结点的直接前驱
```

2、"shortest paths between all pairs of vertices"

 

```C++
void Floyd(int arrDis[][], Vertex arrPath[][])const;

//arrDis[][]用来存储问题的解，即图中，任意两个结点之间的最短距离。使用邻接矩阵weight_adjacency对它进行初始化

//arrPath存储的是中间结点，arrPath[i][j]表示从结点i到结点j的最短路径需要经过的中间结点
```





#### Edge relaxation

两种都属于optimization algorithm，都使用了edge relaxation，关于此，参见 `Edge-relaxation` ，在wikipedia [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 中，关于两者的对比有着非常好的总结。



## Max path in a graph



参见: 

1、wikipedia [Longest path problem](https://en.wikipedia.org/wiki/Longest_path_problem)



## LeetCode

|                                                              |                                                              | 算法 |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---- |
| [LeetCode-743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time/) | 单纯的单源最短路径问题，可以使用多种算法求解，非常适合于练手 |      |
| [LeetCode-120. 三角形最小路径和](https://leetcode.cn/problems/triangle/) |                                                              | DP   |
|                                                              |                                                              |      |