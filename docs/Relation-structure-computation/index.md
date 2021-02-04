# 关于本章

本章的标题是"Relation-structure-computation"，它的含义是关系、结构、计算”。本文对本章的内容进行综述，以从一个较高的角度来掌握本章的内容。



## 综述: relation-structure-computation

如果discrete object之间没有relation，那么它们就是一堆杂乱无章、毫无规律可言的混沌系统，无法使用精简的数学语言对其进行描述（**formal description**），我们所关注的是那些具备中**relation**的discrete objects。

对于具备relation的discrete objects（可以看做是**node**），通过relation将discrete objects进行关联，显然它们形成了一个一个的**ordered pair**（可以看做是**edge**），这些**ordered pair**就形成了一定的**structure**。我们将在`Structure`章节讨论relation and structure，我们将使用relation的理论知识来描述structure。

> NOTE: “ordered”说明relation是具备**方向性**的

**relation**决定**structure**，相同的**relation**决定了它们具备相同的**structure**，进而可以使用相同的algorithm来进行计算(**computation**)。

一个典型的例子：class hierarchy、grammar tree都是**containing关系**，进而决定了对它们进行搜索的时候，可以采用相同的算法。

所以，**relation是核心所在**: **relation决定structure**  `->` 决定采用的algorithm(**computation**)。因此，我们**基于relation来建立model**（模型）：

> 设计出非常高效的algorithm来对它相关的问题进行computation（典型的例子containing关系，在computer science中，CFG、class inheritance都服从这种关系）

后续，我会对computer science中常见的relation会进行深入研究，这样我们就可以使用已有的model来解决问题。

在`Relation-structure-computation\Model`中对model进行描述。

在`Relation-structure-computation\Model\Containing-relation-model.md`中对**containing关系**进行了描述。

> NOTE: 上述这种建立model的思想在science中是广泛存在的，比如在概率论中，有着非常多的概率模型，数学家使用这些概率模型来描述实际问题，比如：
>
> - 正态分布
> - 二项式发布

computation是指为解决问题采用的algorithm；



## Relation and structure are abstraction

Relation 和 structure 都是 abstraction，relation 是从 concrete 中抽象出来的，于此类似的是 structure 也是如此的。



## Graph and relation

**graph**是表示relation的有效工具，后面我们会看到graph的定义和relation的定义是非常类似的，基于graph的algorithm，可以解决很多relation的问题。所以，我们有必要学习graph-theory的知识。



## Computation

在discrete领域，我们考虑的主要是：对于具备relation的discrete objects的computation，后面我们将看到，对于某些relation，我们可以设计出非常高效的algorithm来对它们进行computation，我们将在`Computation`章节来讨论computation。



## 章节说明

“relation”将在[Relation](./Relation/index.md)章节进行描述；

“structure”将在[Structure](./Structure/index.md)章节进行描述；

“computation”将在[Computation](./Computation/index.md)章节进行描述；





## Book 《Discrete Computational Structures》

https://books.google.com/books/about/Discrete_Computational_Structures.html?id=KrLiBQAAQBAJ&source=kp_book_description

https://www.elsevier.com/books/discrete-computational-structures/korfhage/978-0-12-420850-6