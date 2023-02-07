# 关于本章

本章描述induction、deduction、recursion相关的内容，本章的内容主要来自于维基百科。在[Discrete Mathematics and Its Applications](../../Book-Discrete-Mathematics-and-Its-Applications/index.md)的[chapter 5](../../Book-Discrete-Mathematics-and-Its-Applications/Chapter-5-Induction-and-Recursion/index.md)中对与此相关的内容进行了描述。



## Summary

在前面，我们讨论了一系列概念，它们之间是有着一定的关联的，本文就对它们进行对比，进行总结。

无论是mathematical induction，还是structural induction，它们本质上都是 [proof method](https://en.wikipedia.org/wiki/Proof_method) （证明方法），它描述的是一种推广。

[Recursive definition](./Recursion/Recursive-definition.md)（也叫做**inductive definition**）正如其名，它是definition，是specification，所以需要非常严格，它不涉及实现。



| 递归                                                         | 归纳                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Recursion](./Recursion/Recursion.md)                        | [Induction](./Induction-and-deduction/Induction.md)          |
| [Corecursion](./Recursion/Corecursion.md)                    | [Coinduction](./Induction-and-deduction/Coinduction.md)      |
| [Structural recursion](./Induction-and-deduction/Induction.md) | [Structural induction](./Induction-and-deduction/Induction.md) |

关于Structural recursion和Structural induction，参见[Structural induction](./Induction-and-deduction/Induction.md)。

[Corecursion](./Recursion/Corecursion.md)、[Induction](./Induction-and-deduction/Induction.md)、iteration的方向相同，都是自底向上；

[Recursion](./Recursion/Recursion.md)、[Structural recursion](./Induction-and-deduction/Induction.md)的方向相同，都是自顶向下；



### Recursion VS corecursion

recursion 和 corecursion 的计算方向是相反：对于一个 [recurrence relations](https://en.wikipedia.org/wiki/Recurrence_relation) ，如*n! := n × (n - 1)!*.，recursion是从左至右，但是corecursion是从右至左，但是能够殊途同归

- recursion works **analytically** VS corecursion works **synthetically**
- recursion **top-down** VS corecursion **bottom-up**
- recursion **reduce** VS corecursion **produce**



在[Tree traversal](https://en.wikipedia.org/wiki/Tree_traversal)中有如下描述：

**Depth-first search** is easily implemented via a **stack**, including **recursively** (via the **call stack**), while **breadth-first search** is easily implemented via a **queue**, including **corecursively**.

### Recursion VS induction

无论是induction还是recursion，都需要base  case。

Induction本质上都是[proof method](https://en.wikipedia.org/wiki/Proof_method) 。

在维基百科[Structural induction](https://en.wikipedia.org/wiki/Structural_induction)中有这样的描述：

> A structurally recursive function uses the same idea to define a recursive function: "base cases" handle each minimal structure and a rule for recursion. Structural recursion is usually proved correct by structural induction; 

另外参见：https://www.cs.cmu.edu/~rwh/introsml/techniques/indrec.htm ，非常好的一篇文章。



analytically top-down reduce

synthetically bottom-up produce

