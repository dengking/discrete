# Order theory

[排序问题](https://en.wikipedia.org/wiki/Sorting_algorithm)是计算机科学中的一类典型问题， 有很多的问题最终都可以转换为排序问题，比如（TODO 增加一些例子，如循环依赖图），本章将研究排序的理论：order theory进行总结，经过本章，我们将对order有一个更加科学的认识。

Order theory非常重要，它对于实现computation非常重要，正如在`Relation-structure-computation\Make-it-computational`章节所总结的: 

> 只有**有序**才能够实现computation，才能够实现可靠性

## wikipedia [Order theory](https://en.wikipedia.org/wiki/Order_theory)

### 笔记

通过维基百科[Order theory](https://en.wikipedia.org/wiki/Order_theory)，我们可以看到，Order theory是建立在[binary relation](https://en.wikipedia.org/wiki/Binary_relation)之上的，它所研究的是**同一**集合中的元素之间的关系。[Order theory](https://en.wikipedia.org/wiki/Order_theory)将“排序”的概念进行了拓广，它告诉我们集合中的元素按照怎样的关系来进行组织，则它们是可以进行“排序”的，下面的[Binary relations](#Binary relations ) 章节对此进行了总结。

后面章节中，我们将依据这个理论，建立起非常多的概念，这些概念有一些是我们平时所熟知的，但是从order theory的，我们将会获得新的认知。



## Binary relations 

下面是维基百科[Binary relations](https://en.wikipedia.org/wiki/Binary_relation)中所总结的一些binary relation，我们重点关注的是order。

|                                                              | [Symmetric](https://en.wikipedia.org/wiki/Symmetric_relation) | [Antisymmetric](https://en.wikipedia.org/wiki/Antisymmetric_relation) | [Connex](https://en.wikipedia.org/wiki/Connex_relation) | [Well-founded](https://en.wikipedia.org/wiki/Well-founded_relation) | [Has joins](https://en.wikipedia.org/wiki/Join_and_meet) | [Has meets](https://en.wikipedia.org/wiki/Join_and_meet) |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------- | ------------------------------------------------------------ | -------------------------------------------------------- | -------------------------------------------------------- |
| [Equivalence relation](https://en.wikipedia.org/wiki/Equivalence_relation) | ✓                                                            | ✗                                                            | ✗                                                       | ✗                                                            | ✗                                                        | ✗                                                        |
| [Preorder (Quasiorder)](https://en.wikipedia.org/wiki/Preorder) | ✗                                                            | ✗                                                            | ✗                                                       | ✗                                                            | ✗                                                        | ✗                                                        |
| [Partial order](https://en.wikipedia.org/wiki/Partial_order) | ✗                                                            | ✓                                                            | ✗                                                       | ✗                                                            | ✗                                                        | ✗                                                        |
| [Total preorder](https://en.wikipedia.org/wiki/Total_preorder) | ✗                                                            | ✗                                                            | ✓                                                       | ✗                                                            | ✗                                                        | ✗                                                        |
| [Total order](https://en.wikipedia.org/wiki/Total_order)     | ✗                                                            | ✓                                                            | ✓                                                       | ✗                                                            | ✗                                                        | ✗                                                        |
| [Prewellordering](https://en.wikipedia.org/wiki/Prewellordering) | ✗                                                            | ✗                                                            | ✓                                                       | ✓                                                            | ✗                                                        | ✗                                                        |
| [Well-quasi-ordering](https://en.wikipedia.org/wiki/Well-quasi-ordering) | ✗                                                            | ✗                                                            | ✗                                                       | ✓                                                            | ✗                                                        | ✗                                                        |
| [Well-ordering](https://en.wikipedia.org/wiki/Well-order)    | ✗                                                            | ✓                                                            | ✓                                                       | ✓                                                            | ✗                                                        | ✗                                                        |
| [Lattice](https://en.wikipedia.org/wiki/Lattice_(order))     | ✗                                                            | ✓                                                            | ✗                                                       | ✗                                                            | ✓                                                        | ✓                                                        |
| [Join-semilattice](https://en.wikipedia.org/wiki/Join-semilattice) | ✗                                                            | ✓                                                            | ✗                                                       | ✗                                                            | ✓                                                        | ✗                                                        |
| [Meet-semilattice](https://en.wikipedia.org/wiki/Meet-semilattice) | ✗                                                            | ✓                                                            | ✗                                                       | ✗                                                            | ✗                                                        | ✓                                                        |

A "✓" indicates that the column property is required in the row definition. For example, the definition of an equivalence relation requires it to be symmetric. All definitions tacitly require [transitivity](https://en.wikipedia.org/wiki/Transitive_relation) and [reflexivity](https://en.wikipedia.org/wiki/Reflexive_relation).

> NOTE:  [transitivity](https://en.wikipedia.org/wiki/Transitive_relation) 是可以进行“排序”的前提条件。