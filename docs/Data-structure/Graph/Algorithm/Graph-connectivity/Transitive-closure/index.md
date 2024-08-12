# Transitive closure

## What is closure?

“closure"是”close“的名词形式。这个词在阅读过程中经常碰到，本文对它进行总结，需要注意的是 [Closure (mathematics)](https://en.wikipedia.org/wiki/Closure_(mathematics)) 和 [Closure (computer programming)](https://en.wikipedia.org/wiki/Closure_(computer_programming)) 是两个完全不同的概念，不能够弄混。 



### Closure (mathematics)

1、龙书

2、离散数学的关系章节中有闭包的描述

3、[Kleene star](https://en.wikipedia.org/wiki/Kleene_star)

4、[Context-free grammar](https://en.wikipedia.org/wiki/Context-free_grammar#Closure_properties)中也有关于closure的描述

5、从 [Formation rule](https://en.wikipedia.org/wiki/Formation_rule)/[Production rule](https://en.wikipedia.org/wiki/Production_(computer_science)) 的角度来看待闭包

6、从逻辑学推导的角度来看待闭包

closure是基于逻辑推导和集合论([Set theory](https://en.wikipedia.org/wiki/Set_theory) )的，[Set theory](https://en.wikipedia.org/wiki/Set_theory) 是数学的基石所在，很多其他数学学科都是建立在它的基础之上。



### wikipedia [Closure (mathematics)](https://en.wikipedia.org/wiki/Closure_(mathematics))

> NOTE: 下面是我的一些理解:
>
> 重复运用一个relation，从而形成一条path
>

A [set](https://en.wikipedia.org/wiki/Set_(mathematics)) is **closed** under an [operation](https://en.wikipedia.org/wiki/Operation_(mathematics)) if performance of that operation on members of the set always produces a member of that set. 

#### Examples

1. [Recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)

2. The [transitive closure](https://en.wikipedia.org/wiki/Transitive_set#Transitive_closure) of a [set](https://en.wikipedia.org/wiki/Set_(mathematics)).

3. In [formal languages](https://en.wikipedia.org/wiki/Formal_language), the [Kleene closure](https://en.wikipedia.org/wiki/Kleene_closure) of a language



## Transitive closure

### What is transitive closure?

#### Examples

- 在 [**TensorFlow: Large-Scale Machine Learning on Heterogeneous Distributed Systems**](http://download.tensorflow.org/paper/whitepaper2015.pdf) 中提及了**transitive closure：** 

> the TensorFlow implementation can compute the **transitive closure** of all nodes that must be executed in order to compute the outputs that were requested



#### wikipedia [Transitive_closure](https://en.wikipedia.org/wiki/Transitive_closure) 


