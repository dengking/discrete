# 关于本章

本章讨论“Computation on discrete objects“。

## 计算思维

在`index.md`中，我们已经总结了discrete objects的computable的特性，那如何来实现Computation 呢？当我们开始思考“Computation on discrete objects”的时候，其实就已经萌发了“计算思维”，即开始思考“哪些问题是可计算的？”、“该如何实现计算”。

## 计算模型: one-by-one

在讲解具体的算法设计之前，我们首先介绍一种非常抽象的的计算模型：one-by-one。

|                                | unit        | 解释                                                         |
| ------------------------------ | ----------- | ------------------------------------------------------------ |
| CPU                            | instruction | CPU的执行过程是one instruction by another，直至到达终点      |
| Turing-machine                 | instruction | Turing-machine的computation也是one-by-one。                  |
| graph                          | node        | 基于graph的algorithm的执行过程往往是one node by another node，直至终止条件 |
| relation-based algorithm model | node        | 在下面章节会进行详细介绍                                     |
| function                       | subfunction | 函数的执行过程可以用one-by-one来进行描述：<br>将整个program简化为由function组成，<br>将函数简化为的节点，<br>存在调用关系的函数之间，使用连线<br>则形成了一个graph。<br>则函数的执行过程：<br>one subfunction by another subfunction<br>one node by another |

所有的one-by-one，都是enumerable、countable。

### unit

unit表示的是计算单位，在文章`Unit.md`中对一些常见的unit进行了总结。

### computation的度量

我们可以基于unit来对computation进行度量。通过度量computation的量，可以计算得到算法复杂度。

### 可计算性

再复杂的问题也需要转换为one-by-one的方式来进行计算，即使复杂如back-prop也是如此，否则是不可计算的。

Turing的可计算理论是对此的研究。



### 如何实现计算?

前面介绍了ono-by-one model，本节介绍如何来进行实现。

下面是两种非常重要的computation形式：

- iteration
- recursion

很多的algorithm都是基于上述两种形式。

## 如何设计algorithm？

这是一个非常复杂的问题，下面是我的一些经验之谈。



### Relation-based algorithm model

“Relation-based algorithm model”即“基于relation的algorithm model”，简单而言是：基于relation来设计algorithm。下面是对它的概括描述：

沿着structure、relation逐个进行处理，采用one-by-one computation（one node by another node）。

#### step 1

分析relation。

对于discrete objects，分析其结构，找出relation，给出formal definition，后面我们就可以开始设计algorithm，对其进行计算。

#### step 2

rewrite/expand operation

根据relation进行rewrite/expand，比如：

- 在parsing中，是根据production进行expand，production所表达的是包含关系

- 在graph中，则是根据相邻关系来进行expand的

上述过程，需要one-by-one执行。



#### Relation and recursion

同一个relation、transitive relation、的structure，往往是recursive的，可以进行递归定义了，可以使用structural recursion来进行解决。

关于relation、transitive relation，参见`Relation-structure-computation\Relation\Relation`章节。

它和optional sub structure密切相关。



#### 计算的方向

沿着关系、结构来进行计算，一般，我们可以选择两个不同的方向。

比如：递归是自顶向下、动态规划是自底向上、backprop是自顶向下、bottom-up parsing。




