# Guide

通过wikipedia [Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm)，我们可以看到：“search”是一个非常宏大的主题，有时候有这样的感觉：computer science解决很多问题的解法最终都可以归入search的范轴。

正因为search algorithm的无处不在，所以对它的研究是非常有必要的。

## Search space

为了更好地描述、总结search algorithm，我们首先站在一个更高的层次，因此我们需要使用抽象而不是具体。我们首先明确search问题的object：search space。

## Search space的分类

有着多种分类标准：

| Classification criteria | Examples                                                     |
| ----------------------- | ------------------------------------------------------------ |
| virtual                 | 参见 维基百科 [Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm) `#` For virtual search spaces 章节 |
| physical/concrete       | - tree<br>- graph                                            |



按照“结构化思维”，可知：本质上都可以使用relation来进行描述，本质上都是discrete structure，因此可以使用相同的algorithm来解决它们的问题。

virtual search space和concrete search space遵循相同的relation，因此：

1、它们呈现相同的structure

2、可以使用相同的algorithm来实现它们的computation

由于人们的思维往往是易于接受具体，所以对于virtual space这种比较抽象的，我们往往使用具体事物来进行刻画，比如使用search tree来描述问题的解空间，因此，后面在描述各种search strategy的时候，我们是基于concrete structure来进行描述的，这样便于理解，所以讲这部分内容都放到了`Relation-structure-computation\Structure`章节中。



## Search in virtual space 

virtual space的搜索和concrete structure的搜索的过程、实现方式非常类似。

virtual space包括：

- 解空间
- 状态空间

以**结构化思维**来看，virtual space也有着**结构**，最最典型的例子是eight-queen puzzle，它可以使用**nesting关系**来解释：第一次包含n个选择，第二次包含n-1个选择，所以它最终呈现树形，所以可以使用**Relation-based algorithm model**。

参见：

- 结构化思维：`Relation-structure-computation\index.md`
- Relation-based algorithm model：`Relation-structure-computation\Computation\Relation-based-algorithm-model.md`
- nesting关系：`Relation-structure-computation\Model\Nesting-relation-model`

## [Graph](https://en.wikipedia.org/wiki/Graph_traversal) **and** [tree search algorithms](https://en.wikipedia.org/wiki/Tree_traversal)

这部分内容`Relation-structure-computation\Structure\Data-structure\Graph\Search-algorithm`章节进行了描述。



## Search purpose

搜索目标，是在search space中搜索所有的solution，还是搜索best solution。

## Search strategy

在`Relation-structure-computation\Structure\Data-structure\Graph\Search-algorithm\Methods`中进行了描述。



## Optimization algorithm and search algorithm

使用各种各样的[Optimization algorithm](https://en.wikipedia.org/wiki/Optimization_algorithm)来实现[Optimization](https://en.wikipedia.org/wiki/Mathematical_optimization)问题，其实其过程也可以看做是[Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm)：search for best solution，即寻找最优解，这些算法往往采用的策略是：不断地向最优解逼近，关于这个观点，在`Relation-structure-computation\Computation\index.md#Iterative method`章节中也进行了描述。

比如[Gradient descent](https://en.wikipedia.org/wiki/Gradient_descent)就是一个典型的例子：该算法的过程可以看做是不断地向目标逼近的过程，下面是说明此观点的素材：

[如何直观地解释 backpropagation 算法？ - Anonymous的回答 - 知乎]( https://www.zhihu.com/question/27239198/answer/89853077)中有这样的说明：

> 梯度下降法需要给定一个初始点，并求出该点的梯度向量，然后以负梯度方向为搜索方向，以一定的步长进行搜索，从而确定下一个迭代点，再计算该新的梯度方向，如此重复直到cost收敛。



