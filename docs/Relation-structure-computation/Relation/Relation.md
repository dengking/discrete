# Relation

现代数学的很多概念都是建立在[Set](https://en.wikipedia.org/wiki/Set_(mathematics))的基础之上，比如我们熟知的[Function](https://en.wikipedia.org/wiki/Function_(mathematics))概念，Relation也是如此，维基百科中介绍Relation的是[Finitary relation](https://en.wikipedia.org/wiki/Finitary_relation)。

## 维基百科[Finitary relation](https://en.wikipedia.org/wiki/Finitary_relation)

[Finitary relation](https://en.wikipedia.org/wiki/Finitary_relation)的含义是“有限元关系”，我们主要讨论的是[Binary relation](https://en.wikipedia.org/wiki/Binary_relation)（二元关系）。

## 维基百科[Binary relation](https://en.wikipedia.org/wiki/Binary_relation)

In [mathematics](https://en.wikipedia.org/wiki/Mathematics), a **binary relation** over two [sets](https://en.wikipedia.org/wiki/Set_(mathematics)) *A* and *B* is a set of [ordered pairs](https://en.wikipedia.org/wiki/Ordered_pair) (*a*, *b*), consisting of elements *a* of *A* and elements *b* of *B*. That is, it is a subset of the [Cartesian product](https://en.wikipedia.org/wiki/Cartesian_product) *A* × *B*. It encodes the information of relation: an element *a* is related to an element *b*, if and only if the pair (*a*, *b*) belongs to the set. 



> NOTE: 
>
> relation的本质上是set。
>
> 查看[Binary relation](https://en.wikipedia.org/wiki/Binary_relation)和[Function](https://en.wikipedia.org/wiki/Function_(mathematics))可知，[Binary relation](https://en.wikipedia.org/wiki/Binary_relation)是一个比[Function](https://en.wikipedia.org/wiki/Function_(mathematics))更加宽泛的概念：[Function](https://en.wikipedia.org/wiki/Function_(mathematics))是一种[Binary relation](https://en.wikipedia.org/wiki/Binary_relation)，但是反之则不一定成立。

## 关系的性质

### [Transitive relation](https://en.wikipedia.org/wiki/Transitive_relation)

"transitive"的中文意思是“传递性”

> Transitivity is a key property of both [partial orders](https://en.wikipedia.org/wiki/Partial_order) and [equivalence relations](https://en.wikipedia.org/wiki/Equivalence_relation)。

Transitive特性是一个非常优良的特性。

#### Order

要想进行排序，则关系必须具备transitive特性。 

#### Rewrite（proof）

一个例子就是：stock：证券、股票；股票：A股、B股，则stock：A股、B股。

#### Recursive

具备传递性关系，所形成的结构往往具备递归性，因为它的子结构也是具备这种传递性递归关系的。

### [Reflexive relation](https://en.wikipedia.org/wiki/Reflexive_relation)

“reflexive”即“反射性”。



### [Symmetric relation](https://en.wikipedia.org/wiki/Symmetric_relation)

“symmetric”即“对称”



## [Relational algebra](https://en.wikipedia.org/wiki/Relational_algebra)

关系代数，这是DBMS的基础。