# 关于本章

本章讨论“Computation on discrete objects“。

## 计算思维

在`Computer-science-is-discrete`章节中，我们已经总结了discrete objects的computable的特性，作为software engineer，我们需要思考: 如何来**实现Computation** ？当我们开始思考“Computation on discrete objects”的时候，其实就已经萌发了"计算思维"，即开始思考“哪些问题是可计算的？”、“该如何实现计算”。这是一个非常宏大的问题，我只能基于对现有理论的解读、具体的经验来进行总结，本章就是描述的这个主题。

## Make it computational

现实生活中的问题是非常复杂的，实现**计算**的第一步是使用一种language/representation来对问题进行描述，这种language/representation需要是computer能够理解的、是适合计算的。这是实现计算的前提条件，只有这样这样我们才能够在此基础上设计algorithm、实现computation。在`Make-it-computational`章节中对这个话题进行讨论。



## 计算模型: one-by-one

> NOTE: "one-by-one"其实就是Turing machine，本节的内容其实所涉及的就是theory of computation。

在讲解具体的算法设计之前，我们首先介绍一种非常抽象的的计算模型：one-by-one。下面列举了案例

### 顺序执行，直至终点

|                | unit        | 解释                                                         |
| -------------- | ----------- | ------------------------------------------------------------ |
| CPU            | instruction | CPU的执行过程是one instruction by another，直至到达终点      |
| Turing-machine | instruction | Turing-machine的computation也是one-by-one。                  |
| function       | subfunction | 函数的执行过程可以用one-by-one来进行描述：<br>将整个program简化为由function组成，<br>将函数简化为的节点，<br>存在调用关系的函数之间，使用连线<br>则形成了一个graph。<br>则函数的执行过程：<br>one subfunction by another subfunction<br>one node by another |



### 基于relation进行搜索，直至目标点

|                                | unit | 解释                                                         |
| ------------------------------ | ---- | ------------------------------------------------------------ |
| graph                          | node | 基于graph的algorithm的执行过程往往是one node by another node，直至终止条件 |
| relation-based algorithm model | node | 在下面章节会进行详细介绍                                     |

relation可以使用graph来实现，所以上述两者，其实本质上是相同的。

### Iterative method

参见：

1、维基百科 [Iterative method](https://en.wikipedia.org/wiki/Iterative_method)

2、维基百科 [Mathematical optimization](https://en.wikipedia.org/wiki/Mathematical_optimization) `#` [Computational optimization techniques](https://en.wikipedia.org/wiki/Mathematical_optimization#Computational_optimization_techniques)，

下面是一些例子：

1、[Gradient descent](https://en.wikipedia.org/wiki/Gradient_descent) 

主要用于解决 Continuous optimization problem，参见`Relation-structure-computation\Computation\Algorithm\Application\Optimization`。

### 逐步向目标靠近

很多求最值的algorithm都可以看做是：逐步向目标靠近，即重复执行着 **贪心选择**(greedy) 过程，从而实现 不断的 向 **目标** 靠近 ，显然它是符合one-by-one的，下面是这些例子：

1、best-first search

2、Iterative method 

3、greedy algorithm

这些algorithm的另外一个共性是：

1、可能无法获得全局最优

从search algorithm的角度来看，“逐步向目标靠近”也可以看做是一种search，关于search algorithm，参见：

- `Relation-structure-computation\Computation\Algorithm\Application\Search`







## Computation的度量

> NOTE: Turing的可计算理论是对此的研究。

所有的one-by-one，都是enumerable、countable。

### unit

unit表示的是计算单位，在文章`Unit.md`中对一些常见的unit进行了总结。

### computation的度量

我们可以基于unit来对computation进行度量。通过度量computation的量，可以计算得到算法复杂度。

### 可计算性

再复杂的问题也需要转换为one-by-one的方式来进行计算，即使复杂如back-prop也是如此，否则是不可计算的。



## 如何编程实现计算?

前面介绍了ono-by-one model其实更加偏向于理论的模型，本节介绍如何来编程进行实现。

### Repetition

从前面描述的one-by-one computation中，我们可以看出:

1) iterative method 和 greedy algorithm就是重复执行着 **贪心选择** 过程，从而实现 不断的 向 **目标** 靠近 

2) relation-based algorithm: 重复执行relation对应的computation

显然，它们都是典型的"重复执行某个computation"，我们简称为"repetition"，具备"repetition"特征的computation是非常容易编程实现的，这也是这种computation具备重要价值的原因。前面所描述的one-by-one model，其实是偏向于理论、太过抽象，repetition computation则让我们能够编程实现。在computer science中，我们可以看到repetition是无处不在的。

在`Repetition`章节，将对它进行详细说明。



### 计算的方向

沿着关系、结构来进行计算，一般，我们可以选择两个不同的方向，这将在`./Computation-direction`章节中进行介绍。

### 如何设计algorithm？

设计algorithm是实现computation的非常重要的一环，是一个非常复杂的问题，有着非常多的技巧，我们将在`Relation-structure-computation\Computation\Algorithm`中进行讨论。





