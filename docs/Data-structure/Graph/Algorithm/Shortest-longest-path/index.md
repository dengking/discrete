# Shortest and longest path 



## LeetCode

|                                                              |                                                              | 算法 |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---- |
| [LeetCode-743. 网络延迟时间](https://leetcode.cn/problems/network-delay-time/) | 单纯的单源最短路径问题，可以使用多种算法求解，非常适合于练手 |      |
| [LeetCode-120. 三角形最小路径和](https://leetcode.cn/problems/triangle/) |                                                              | DP   |
|                                                              |                                                              |      |



## 算法总结

素材:

1、[【宫水三叶】涵盖所有的「存图方式」与「最短路算法（详尽注释）」](https://leetcode.cn/problems/network-delay-time/solution/gong-shui-san-xie-yi-ti-wu-jie-wu-chong-oghpz/)

2、[五种最短路径算法总结](https://leetcode.cn/problems/network-delay-time/solution/dirkdtra-by-happysnaker-vjii/)



## Dijkstra VS Floyd



### 1. 所属种类

Dijkstra算法是典型的贪心算法

Floyd算法是动态规划算法

### 2. 所解决的问题

Dijkstra算法所解决的问题是图的单源最短路径问题，也就是对于一个给定的图，我们首先指定该图中的一个点作为源点，然后求出从源点到图中其它结点的最短距离。

Floyd算法所解决的问题是图中任意两个结点之间的最短路径。显然，运用Floyd算法是无需指定源点的

### 3.解的表达方式

```C++
void Dijkstra(Vertex source,Weight dist[], Vertex prev[])const; 

//dist[]用来保存最终的结果，

//prev[]用来记录每个结点的直接前驱
```



 

```C++
void Floyd(int arrDis[][], Vertex arrPath[][])const;

//arrDis[][]用来存储问题的解，即图中，任意两个结点之间的最短距离。使用邻接矩阵weight_adjacency对它进行初始化

//arrPath存储的是中间结点，arrPath[i][j]表示从结点i到结点j的最短路径需要经过的中间结点
```





### Edge relaxation

"edge relaxation"这个词我是在阅读 

两者都属于求解最优值问题，它们两个提供了求解最优值问题的非常好的范式。

#### stackoverflow [Relaxation of an edge in Dijkstra's algorithm](https://stackoverflow.com/questions/12782431/relaxation-of-an-edge-in-dijkstras-algorithm)

What does **relaxation of an edge** mean in the context of graph theory ? 

### [A](https://stackoverflow.com/a/12782683)
Here's a nice description of the Algorithm that also explains the notion of relaxation.

> The notion of "relaxation" comes from an analogy between the estimate of the shortest path and the length of a **helical tension spring**(螺旋拉升的弹簧), which is not designed for compression. Initially, the cost of the shortest path is an overestimate, likened to a stretched out spring. As shorter paths are found, the estimated cost is lowered, and the spring is relaxed. Eventually, the shortest path, if one exists, is found and the spring has been relaxed to its resting(静止) length.

> NOTE: 
> 一、
> "likened"的意思是类比、比照
> "helical tension spring"的意思是"螺旋拉升的弹簧"
> 二、上面这段话中使用了"estimate"、"overestimate"
> 三、"stretched out"的意思是"伸展"、"拉伸"
> 简而言之:弹簧一开始被拉伸地很长，后来不断释放而越来越短最终恢复到弹簧的静止最短长度。在弹簧的语境中，"relax"的意思是"放松"、"释放"

### [A](https://stackoverflow.com/a/12782820)

```
if directly_connected(v, u)
    if est(S, v) > est(S, u) + dist(u,v)
       est(S, v) = est(S, u) + dist(u, v)
```


towardsdatascience [Understanding Edge Relaxation for Dijkstra’s Algorithm and Bellman-Ford Algorithm](https://towardsdatascience.com/algorithm-shortest-paths-1d8fa3f50769)

baeldung [Edge Relaxation in Dijkstra’s Algorithm](https://www.baeldung.com/cs/dijkstra-edge-relaxation)

## Single source shortest path(SSSP)

最短路径问题的算法:

一、Dijkstra's algorithm

参见 `Dijkstra's-algorithm` 章节

二、Bellman Ford algorithm

参见 `Bellman–Ford-algorithm` 章节

三、动态规划

参见 `DP解路径问题` 章节

四、BFS



## Max path in a graph



参见: 

1、wikipedia [Longest path problem](https://en.wikipedia.org/wiki/Longest_path_problem)