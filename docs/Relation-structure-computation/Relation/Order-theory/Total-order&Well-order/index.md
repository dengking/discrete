# Total order&Well order

“total order”即全序，具体参见: wikipedia [Total order](https://en.wikipedia.org/wiki/Total_order) 

## Formal definition

wikipedia [Total order](https://en.wikipedia.org/wiki/Total_order) 对“total order”的“formal definition”如下：

> Formally, a binary relation $\leq $ is a total order on a set $X$ if the following statements hold for all $a,b$ and $c$ in $X$:
> 
> [Antisymmetry](https://en.wikipedia.org/wiki/Antisymmetric_relation)
> 
> If $a\leq b$ and $ b\leq a$ then $a=b$;
> [Transitivity](https://en.wikipedia.org/wiki/Transitive_relation)
> 
> If $a\leq b$ and $ b\leq c$then $a\leq c$;
> [Connexity](https://en.wikipedia.org/wiki/Connex_relation)
> 
> $a\leq b$ or $b\leq a$}.

$\leq $表示的是一个binary relation，而非我们直观理解的“小于等于”。另外一点是，上述定义中“all”强调了集合中的所有元素都需要满足这种关系。

## Chain

对“total order”的直观理解是它是一个能够将这个集合“串”起来的关系，这样这个集合就形成了“chain”，显然，“chain”是从视觉直观角度来对其进行命名的，对此在原文中有这样的描述：

>  A set paired with a total order is called a **chain**, a **totally ordered set**, a **simply ordered set**, or a **linearly ordered set**.

原文的[Chains](https://en.wikipedia.org/wiki/Total_order#Chains)章节对此进行了详细分析。

## Connex relation

“connex relation”即“连通关系”

### wikipedia  [Connex relation](https://en.wikipedia.org/wiki/Connex_relation)





## Well-order

在阅读wikipedia [Recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)的 [Form of recursive definitions](https://en.wikipedia.org/wiki/Recursive_definition#Form_of_recursive_definitions) 章节时，发现了这个概念，遂对它进行了整理。

### wikipedia [Well-order](https://en.wikipedia.org/wiki/Well-order)



## [Well-order](https://en.wikipedia.org/wiki/Well-order) VS [total order](https://en.wikipedia.org/wiki/Total_order)

原文对[Well-order](https://en.wikipedia.org/wiki/Well-order) 的定义如下：

> In [mathematics](https://en.wikipedia.org/wiki/Mathematics), a **well-order** (or **well-ordering** or **well-order [relation](https://en.wikipedia.org/wiki/Binary_relation)**) on a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) *S* is a [total order](https://en.wikipedia.org/wiki/Total_order) on *S* with the property that every [non-empty](https://en.wikipedia.org/wiki/Non-empty) [subset](https://en.wikipedia.org/wiki/Subset) of *S* has a [least element](https://en.wikipedia.org/wiki/Least_element) in this ordering.

显然，它是在 [total order](https://en.wikipedia.org/wiki/Total_order) 的基础上添加了一个限制，那这限制有何意义呢？是保证`S`的每个子集依然满足 [total order](https://en.wikipedia.org/wiki/Total_order)？

其实理解well order的一个很好的方法是结合实例来进行理解，set theory所描述的tree就是一个典型的well order，在维基百科[Tree (set theory)](https://en.wikipedia.org/wiki/Tree_(set_theory))：

> In [set theory](https://en.wikipedia.org/wiki/Set_theory), a **tree** is a [partially ordered set](https://en.wikipedia.org/wiki/Partially_ordered_set) (*T*, <) such that for each *t* ∈ *T*, the set {*s* ∈ *T* : *s* < *t*} is [well-ordered](https://en.wikipedia.org/wiki/Well-ordered) by the relation <. Frequently trees are assumed to have only one root (i.e. [minimal element](https://en.wikipedia.org/wiki/Minimal_element)), as the typical questions investigated in this field are easily reduced to questions about single-rooted trees.

## 