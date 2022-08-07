# Edge relaxation

"edge relaxation"这个词我是在阅读wikipedia  [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 、wikipedia [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm) 时，发现的，在 wikipedia  [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 中有这样的描述:

> Like [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm), Bellman–Ford proceeds by [relaxation](https://en.wikipedia.org/wiki/Relaxation_(approximation)), in which approximations to the correct distance are replaced by better ones until they eventually reach the solution. In both algorithms, the approximate distance to each vertex is always an overestimate of the true distance, and is replaced by the minimum of its old value and the length of a newly found path. 

两者都属于求解最优值问题，它们两个提供了求解最优值问题的非常好的范式。

## stackoverflow [Relaxation of an edge in Dijkstra's algorithm](https://stackoverflow.com/questions/12782431/relaxation-of-an-edge-in-dijkstras-algorithm)

What does **relaxation of an edge** mean in the context of graph theory ? 

### [A](https://stackoverflow.com/a/12782683)

[Here's](http://web.cs.unlv.edu/larmore/Courses/CSC269/pathing) a nice description of the Algorithm that also explains the notion of relaxation.

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