# Transitive closure

## What is closure?

“closure"是”close“的名词形式。这个词在阅读过程中经常碰到，本文对它进行总结:

1、需要注意的是 [Closure (mathematics)](https://en.wikipedia.org/wiki/Closure_(mathematics)) 和 [Closure (computer programming)](https://en.wikipedia.org/wiki/Closure_(computer_programming)) 是两个完全不同的概念，不能够弄混。 



### Closure (mathematics)

1、龙书

2、离散数学的关系章节中有闭包的描述

3、[Kleene star](https://en.wikipedia.org/wiki/Kleene_star)

4、[Context-free grammar](https://en.wikipedia.org/wiki/Context-free_grammar#Closure_properties)中也有关于closure的描述

5、从 [Formation rule](https://en.wikipedia.org/wiki/Formation_rule)/[Production rule](https://en.wikipedia.org/wiki/Production_(computer_science)) 的角度来看待闭包

6、从逻辑学推导的角度来看待闭包

我一直想要搞清楚的closure就是基于逻辑推导和集合论的。

[Set theory](https://en.wikipedia.org/wiki/Set_theory)是数学的基石所在，很多其他数学学科都是建立在它的基础之上。



### wikipedia [Closure (mathematics)](https://en.wikipedia.org/wiki/Closure_(mathematics))

> NOTE: 下面是我的一些理解:
>
> 1、重复运用一个relation，从而形成一条path。
>
> 

A [set](https://en.wikipedia.org/wiki/Set_(mathematics)) is **closed** under an [operation](https://en.wikipedia.org/wiki/Operation_(mathematics)) if performance of that operation on members of the set always produces a member of that set. 

#### Examples

1、[Recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)

2、The [transitive closure](https://en.wikipedia.org/wiki/Transitive_set#Transitive_closure) of a [set](https://en.wikipedia.org/wiki/Set_(mathematics)).

3、In [formal languages](https://en.wikipedia.org/wiki/Formal_language), the [Kleene closure](https://en.wikipedia.org/wiki/Kleene_closure) of a language



## Transitive closure

### What is transitive closure?

#### Examples

- 在 [**TensorFlow: Large-Scale Machine Learning on Heterogeneous Distributed Systems**](http://download.tensorflow.org/paper/whitepaper2015.pdf) 中提及了**transitive closure：** 

> the TensorFlow implementation can compute the **transitive closure** of all nodes that must be executed in order to compute the outputs that were requested



#### wikipedia [Transitive_closure](https://en.wikipedia.org/wiki/Transitive_closure) 



### Algorithms

The problem can also be solved by:

- [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm) 
- repeated [breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search) or [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search) starting from each node of the graph 

> NOTE: 
>
> 一、
>

Closures of Relations(从relation-structure的角度来进行分析)

1、沿着relation不断地进行expand

2、one-by-one



根据graph representation，选择合适的algorithm。



#### Warshall’s Algorithm

---

> References: 
>
> wikipedia [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm)
>
> winona [CS 440 Theory of Algorithms / CS 468 Algorithms in Bioinformatics](https://cs.winona.edu/lin/cs440/ch08-2.pdf) 

---



#### Repeated BFS

wikipedia [Transitive_closure](https://en.wikipedia.org/wiki/Transitive_closure) 

> "repeated [breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search) or [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search) starting from each node of the graph"

Graph-repeated-BFS-flood-fill-transitive-closure

1、BFS flood fill的方式来找到connected component

2、repeated执行上述步骤，保证能够找到所有的connected component

注意，需要为每个node都执行一次。



##### Java



```Java
package com.test.www;

import java.util.*;

public class GraphTransitiveClosure<T> {
    private Map<T, Set<T>> adjacencyList; // 图的adjacent list表示方式
    private List<Set<T>> closures; // 传递闭包

    public GraphTransitiveClosure(Map<T, Set<T>> adjacencyList) {
        this.adjacencyList = adjacencyList;
        initClosures();

    }
    /**
     * @param edges 图的边
     */
    public GraphTransitiveClosure(List<List<T>> edges) {
        adjacencyList = edges.parallelStream().collect(
                HashMap::new,
                (Map<T, Set<T>> map, List<T> edge) -> {
                    final Set<T> groups1 = map.getOrDefault(edge.get(0), new HashSet<>());
                    groups1.add(edge.get(1));
                    map.put(edge.get(0), groups1);

                    final Set<T> groups2 = map.getOrDefault(edge.get(1), new HashSet<>());
                    groups2.add(edge.get(0));
                    map.put(edge.get(1), groups2);
                },
                (Map<T, Set<T>> map1, Map<T, Set<T>> map2) -> {
                    map2.forEach((index, otherIndexes) -> {
                        if (map1.containsKey(index)) {
                            map1.get(index).addAll(otherIndexes);
                        } else {
                            map1.put(index, otherIndexes);
                        }
                    });
                });
        initClosures();
    }

    private void initClosures() {
        final Set<T> visitedSet = new HashSet<>();
        closures = new ArrayList<>();
        for (T node : adjacencyList.keySet()) {
            if (!visitedSet.contains(node)) {
                closures.add(initClosure(node, visitedSet));
            }
        }
    }

    /**
     * BFS
     */
    private Set<T> initClosure(T node, Set<T> visitedSet) {
        Set<T> closure = new HashSet<>();
        Queue<T> queue = new LinkedList<>();
        queue.add(node);
        visitedSet.add(node);

        while (!queue.isEmpty()) {
            final T curNode = queue.remove();
            closure.add(curNode);
            for (T otherNode : adjacencyList.getOrDefault(curNode, new HashSet<>())) {
                if (!visitedSet.contains(otherNode)) {
                    visitedSet.add(otherNode);
                    queue.add(otherNode);
                }
            }
        }

        return closure;
    }

    public List<Set<T>> getClosures() {
        return closures;
    }
}

```

