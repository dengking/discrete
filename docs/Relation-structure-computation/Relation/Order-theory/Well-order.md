# Well-order

在阅读维基百科[Recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)的[Form of recursive definitions](https://en.wikipedia.org/wiki/Recursive_definition#Form_of_recursive_definitions)章节时，发现了这个概念，遂对它进行了整理。

## 维基百科[Well-order](https://en.wikipedia.org/wiki/Well-order)

### 笔记

#### [Well-order](https://en.wikipedia.org/wiki/Well-order) VS  [total order](https://en.wikipedia.org/wiki/Total_order)

原文对[Well-order](https://en.wikipedia.org/wiki/Well-order) 的定义如下：

> In [mathematics](https://en.wikipedia.org/wiki/Mathematics), a **well-order** (or **well-ordering** or **well-order [relation](https://en.wikipedia.org/wiki/Binary_relation)**) on a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) *S* is a [total order](https://en.wikipedia.org/wiki/Total_order) on *S* with the property that every [non-empty](https://en.wikipedia.org/wiki/Non-empty) [subset](https://en.wikipedia.org/wiki/Subset) of *S* has a [least element](https://en.wikipedia.org/wiki/Least_element) in this ordering. 

显然，它是在 [total order](https://en.wikipedia.org/wiki/Total_order) 的基础上添加了一个限制，那这限制有何意义呢？是保证`S`的每个子集依然满足 [total order](https://en.wikipedia.org/wiki/Total_order)？



其实理解well order的一个很好的方法是结合实例来进行理解，set theory所描述的tree就是一个典型的well order，在维基百科[Tree (set theory)](https://en.wikipedia.org/wiki/Tree_(set_theory))：

> In [set theory](https://en.wikipedia.org/wiki/Set_theory), a **tree** is a [partially ordered set](https://en.wikipedia.org/wiki/Partially_ordered_set) (*T*, <) such that for each *t* ∈ *T*, the set {*s* ∈ *T* : *s* < *t*} is [well-ordered](https://en.wikipedia.org/wiki/Well-ordered) by the relation <. Frequently trees are assumed to have only one root (i.e. [minimal element](https://en.wikipedia.org/wiki/Minimal_element)), as the typical questions investigated in this field are easily reduced to questions about single-rooted trees.

## 维基百科Well-founded relation

并没有理解维基百科[Well-founded relation](https://en.wikipedia.org/wiki/Well-founded_relation)。