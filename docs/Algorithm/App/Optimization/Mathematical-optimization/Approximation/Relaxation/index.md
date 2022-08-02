# Relaxation 

我是在阅读 wikipedia [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 的时候发现的这个词，其中有这样的描述:

> Like [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm), Bellman–Ford proceeds by [relaxation](https://en.wikipedia.org/wiki/Relaxation_(approximation)), in which approximations to the correct distance are replaced by better ones until they eventually reach the solution. In both algorithms, the approximate distance to each vertex is always an overestimate of the true distance, and is replaced by the minimum of its old value and the length of a newly found path. 

跟随链接，发现了这个词。





## 分类

| 类别                          | 素材                                                         |
| ----------------------------- | ------------------------------------------------------------ |
| Relaxation (approximation)    | wikipedia [Relaxation (approximation)](https://en.wikipedia.org/wiki/Relaxation_(approximation)) |
| Relaxation (iterative method) | wikipedia [Relaxation (iterative method)](https://en.wikipedia.org/wiki/Relaxation_(iterative_method)) |
|                               |                                                              |



## Relaxation (approximation)

### wikipedia [Relaxation (approximation)](https://en.wikipedia.org/wiki/Relaxation_(approximation))

In [mathematical optimization](https://en.wikipedia.org/wiki/Mathematical_optimization) and related fields, **relaxation** is a [modeling strategy](https://en.wikipedia.org/wiki/Mathematical_model). A relaxation is an [approximation](https://en.wikipedia.org/wiki/Approximation) of a difficult problem by a nearby problem that is easier to solve. A solution of the relaxed problem provides information about the original problem.

> NOTE: 上述描述有些divide-and-conquer的意味，通过上述描述来看，edge relaxation是典型的 [relaxation (approximation)](https://en.wikipedia.org/wiki/Relaxation_(approximation)) ，wikipedia [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm) 中的" [relaxation](https://en.wikipedia.org/wiki/Relaxation_(approximation)) "就指向的这篇文章。

