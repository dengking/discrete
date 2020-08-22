# Relation

现代数学的很多概念都是建立在[Set](https://en.wikipedia.org/wiki/Set_(mathematics))的基础之上，比如我们熟知的[Function](https://en.wikipedia.org/wiki/Function_(mathematics))概念，Relation也是如此，维基百科中介绍Relation的是[Finitary relation](https://en.wikipedia.org/wiki/Finitary_relation)。

## Definition of relation

关于relation的定义，在`Discrete-math\Book-Discrete-Mathematics-and-Its-Applications\Chpater-9-Relations`中给出了：

> **Relationships** between elements of sets occur in many contexts. Every day we deal with **relationships** such as those between a business and its telephone number, an employee and his or her salary, a person and a relative, and so on. In mathematics we study **relationships** such as those between a positive integer and one that it divides, an integer and one that it is congruent to modulo 5, a real number and one that is larger than it, a real number `x` and the value `f(x)` where `f` is a function, and so on. **Relationships** such as that between a program and a variable it uses, and that between a computer language and a valid statement in this language often arise in computer science.
>
> **Relationships** between elements of **sets** are represented using the structure called a **relation**, which is just as sub set of the **Cartesian product** of the sets. Relations can be used to solve problems such as determining which pairs of cities are linked by airline flights in a network, finding a viable order for the different phases of a complicated project, or producing a useful way to store information in computer databases.

需要区分清楚relationship和relation：

relationship：就是我们平时所说的“关系”，比如“大于”、“小于”

relation：它是discrete math中对relationship的表示，它是一个set

显然discrete math中，关于relation的definition，采用的是概括法。

严格来说，我们平时所说的“关系”应该使用“relationship”这个词语。

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

按照工程`automata-and-formal-language`中的思想，rewrite的过程其实就是“推导”的过程。

一个例子就是：

```
stock：证券、股票；
股票：A股、B股;

则stock：A股、B股。
```



#### Recursive

具备传递性关系，所形成的结构往往具备递归性，因为它的子结构也是具备这种传递性递归关系的。

#### relation and circular

沿着relation不停地进行rewrite（或者说 推导），通过最终到达了远点，则形成了circle。当使用graph来表示relation时，这种现象是非常任意理解的。

当relation是dependency关系、reference关系（[Reference counting](https://en.wikipedia.org/wiki/Reference_counting)）的时候，如果图成环，则就会导致一些列问题。

- dead lock
- circular reference

### [Reflexive relation](https://en.wikipedia.org/wiki/Reflexive_relation)

“reflexive”即“反射性”。



### [Symmetric relation](https://en.wikipedia.org/wiki/Symmetric_relation)

“symmetric”即“对称”



## [Relational algebra](https://en.wikipedia.org/wiki/Relational_algebra)

关系代数，这是DBMS的基础。