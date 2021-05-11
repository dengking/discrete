# Computer algebra

## 以"relation-structure-computation"的角度来思考

一、expression的abstract structure

> NOTE: 
>
> 1、tag-make it computational Structuralization

1、expression(尤其是数学公式)的结构是典型的**abstract structure**，它们的structure可能呈现:

a、tree

b、chain

2、借鉴于它们的结构特性，能够设计高效的algorithm来对它们进行计算

下面是一些结构特性以及可以采用的:

Overlapping subproblem + dynamic programing、Optional substructure + greedy algorithm



二、这是symbolic computation的基础思想



产生式、函数表达式（expression）都是数学**语言**，它们描述了**关系**。

在computer science中，我们知道，graph也可以用来描述**关系**。



在计算机科学中，我们应该使用discrete relation来分析事物，从而对它们进行描述、计算：

- 产生式可以使用tree structure来表示，tree 是一种 graph
- 函数表达式可以使用computation graph来表示



## Computational graph and tree

使用computational graph来表示expression，使用tree来表示formal language。它们都是使用计算机能够接受的language来描述事物的典型例子，它们都是一种language。计算机能够接受的语言：structure。所以，结构化方式，即使用结构化的语言进行描述是解决计算问题的第一步。这就是典型的"make it computational: structuralization"。





## 数学公式的结构

数学公式的结构是典型的abstract structure。

#### Computational graph of math expression

使用computational graph来描述math expression。

素材：维基百科[Backpropagation](https://en.wikipedia.org/wiki/Backpropagation)：forward network对应的数学公式：
$$
g(x):=f^{L}(W^{L}f^{L-1}(W^{L-1}\cdots f^{1}(W^{1}x)\cdots ))
$$



素材：`machine-learning\docs\Theory\Deep-learning\Book-deep-learning\Part-II-Deep-Networks-Modern-Practices\Model-And-layer-And-computation-And-computational-graph.md`



#### Recurrence relation

[recurrence relation](./Recursion/Recurrence-relation.md)其实所描述的是两个元素的关系，这种关系可能是线性的。

[recurrence relation](./Recursion/Recurrence-relation.md)是非常适合于使用computer algorithm来实现的，因为它是离散的，它是可以使用one-by-one来计算出来的，我们也可以说它具有离散结构。

比如 :

- 递归公式 [Fibonacci number](https://en.wikipedia.org/wiki/Fibonacci_number)的结构非常类似于binary tree。



#### Permutation and combination

permutation和combination都是使用的乘法，它们都是nesting关系，都呈现出 tree 结构，在`Relation-structure-computation\Computation\Algorithm\Paradigm\Backtracking\Backtrack`章节中有**组合树**、**排列树**的描述。





## [Algebraic structure](https://infogalactic.com/info/Algebraic_structure)



## [Mathematical structure](https://en.wikipedia.org/wiki/Mathematical_structure)

In [mathematics](https://en.wikipedia.org/wiki/Mathematics), a **structure** is a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) endowed with some additional features on the set (e.g., [operation](https://en.wikipedia.org/wiki/Operation_(mathematics)), [relation](https://en.wikipedia.org/wiki/Relation_(math)), [metric](https://en.wikipedia.org/wiki/Metric_(mathematics)), [topology](https://en.wikipedia.org/wiki/Topology#Topologies_on_sets)).[[1\]](https://en.wikipedia.org/wiki/Mathematical_structure#cite_note-1) Often, the additional features are attached or related to the set, so as to provide it with some additional meaning or significance.