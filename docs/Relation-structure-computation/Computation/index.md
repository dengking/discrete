# 关于本章

本章讨论“Computation on discrete objects“。

## 计算思维

在`index.md`中，我们已经总结了discrete objects的computable的特性，那如何来实现Computation 呢？当我们开始思考“Computation on discrete objects”的时候，其实就已经萌发了“计算思维”，即开始思考“哪些问题是可计算的？”、“该如何实现计算”。

## 计算模型: one-by-one

在讲解具体的算法设计之前，我们首先介绍一种非常抽象的的计算模型：one-by-one。

### Classification

#### 顺序执行，直至终点

|                | unit        | 解释                                                         |
| -------------- | ----------- | ------------------------------------------------------------ |
| CPU            | instruction | CPU的执行过程是one instruction by another，直至到达终点      |
| Turing-machine | instruction | Turing-machine的computation也是one-by-one。                  |
| function       | subfunction | 函数的执行过程可以用one-by-one来进行描述：<br>将整个program简化为由function组成，<br>将函数简化为的节点，<br>存在调用关系的函数之间，使用连线<br>则形成了一个graph。<br>则函数的执行过程：<br>one subfunction by another subfunction<br>one node by another |



#### 基于relation进行搜索，直至目标点

|                                | unit | 解释                                                         |
| ------------------------------ | ---- | ------------------------------------------------------------ |
| graph                          | node | 基于graph的algorithm的执行过程往往是one node by another node，直至终止条件 |
| relation-based algorithm model | node | 在下面章节会进行详细介绍                                     |

relation可以使用graph来实现，所以上述两者，其实本质上是相同的。

#### Iterative method

参见：

- 维基百科 [Iterative method](https://en.wikipedia.org/wiki/Iterative_method)

- 维基百科 [Mathematical optimization](https://en.wikipedia.org/wiki/Mathematical_optimization) `#` [Computational optimization techniques](https://en.wikipedia.org/wiki/Mathematical_optimization#Computational_optimization_techniques)，

下面是一些例子：

- [Gradient descent](https://en.wikipedia.org/wiki/Gradient_descent) 

主要用于解决 Continuous optimization problem，参见`Relation-structure-computation\Computation\Algorithm\Application\Optimization`。



所有的one-by-one，都是enumerable、countable。



### unit

unit表示的是计算单位，在文章`Unit.md`中对一些常见的unit进行了总结。

### computation的度量

我们可以基于unit来对computation进行度量。通过度量computation的量，可以计算得到算法复杂度。

### 可计算性

再复杂的问题也需要转换为one-by-one的方式来进行计算，即使复杂如back-prop也是如此，否则是不可计算的。

Turing的可计算理论是对此的研究。



## 如何实现计算?

前面介绍了ono-by-one model，本节介绍如何来进行实现。

下面是两种非常重要的computation形式：

- iteration
- recursion

很多的algorithm都是基于上述两种形式。

### 如何设计algorithm？

设计algorithm是实现computation的非常重要的一环，是一个非常复杂的问题，有着非常多的技巧，我们将在`Relation-structure-computation\Computation\Algorithm`中进行讨论。

### 计算的方向

我们常常会听到：

- 自底向上
- 自定向下
- 反向传播
- ......

上述这些都体现了计算的方向。

