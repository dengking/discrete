# Repetition: iteration、recursion

在前面章节已经介绍了repetition，本章对它进行详细描述。在computer science中，iteration、recursion是实现repetitionn("重复执行某个computation")的两种主要方式: 

1、iteration

2、recursion

我觉得之所以recursion和iteration如此重要，是因为computer science中，离散是广泛存在的，在基于这些离散结构进行计算的时候，我们最最常用的就是recursion和iteration。正如在wikipedia [Iteration](https://en.wikipedia.org/wiki/Iteration)中有这样的总结：

> In [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), [iteration](https://en.wikipedia.org/wiki/Iteration) (along with the related technique of [recursion](https://en.wikipedia.org/wiki/Recursion)) is a standard element of [algorithms](https://en.wikipedia.org/wiki/Algorithm).



## Two direction、dual

> NOTE:
>
> 一、找到 [Recurrence relation](https://en.wikipedia.org/wiki/Recurrence_relation) (是一种 recursive definition)才是解决问题之根本

给定 [Recurrence relation](https://en.wikipedia.org/wiki/Recurrence_relation) (是一种 recursive definition)，它往往由: base case + clause 组成，对于它的computation，可以采用两种相反的方向: 

一、analytically top-down reduce to base case、stack push 

[Corecursion](./Recursion/Corecursion.md)、[Induction](./Induction-and-deduction/Induction.md)、iteration的方向相同，都是自底向上；

二、synthetically bottom-up produce from base case、stack pop

[Recursion](./Recursion/Recursion.md)、[Structural recursion](./Induction-and-deduction/Induction.md)的方向相同，都是自顶向下；

> NOTE:
>
> 一、上述analytically、synthetically，参考了:
>
> 1、wikipedia [Corecursion](https://en.wikipedia.org/wiki/Corecursion) 
>
> 2、龙书
>
> 二、关于dual，参见:
>
> wikipedia [Dual](https://en.wikipedia.org/wiki/Dual) 



draft: 

1、stack push+pop 才能够归零，才能够计算得到最终的结果。

2、pre-action、post-action

## Example

1、traverse on structure

参见`Relation-structure-computation\Structure\Computation-on-structure`章节。



