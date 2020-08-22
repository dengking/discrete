# 关于本章

本章的标题是“Relation-structure-computation”，它的含义是关系、结构、计算”。本文对本章的内容进行综述，以从一个较高的角度来掌握本章的内容。

## 综述: 关系-结构-计算

如果discrete object之间没有relation，那么它们就是一堆杂乱无章、毫无规律可言的混沌系统，无法使用精简的数学语言对其进行描述（formal description），我们所关注的是那些具备中**relation**的discrete objects。

对于具备relation的discrete objects（可以看做是**node**），通过relation将discrete objects进行关联，显然它们形成了一个一个的**ordered pair**（可以看做是**edge**），这些**order pair**就形成了一定的**structure**。我们将在`Structure`章节讨论relation and structure，我们将使用relation的理论知识来描述structure。

> NOTE: “ordered”说明relation是具备**方向性**的

**relation**决定**structure**，相同的**relation**决定了它们具备相同的**structure**，进而可以使用相同的algorithm来进行计算。

一个典型的例子：class hierarchy、grammar tree都是**containing关系**，进而决定了对它们进行搜索的时候，可以采用相同的算法。

> NOTE: 在`Relation-structure-computation\Model\Containing-relation-model.md`中对**containing关系**进行了描述。

所以，relation是核心所在，relation决定structure  `->` 决定采用的algorithm。因此，我们基于relation来建立model（模型）：

- 设计出非常高效的algorithm来对它相关的问题进行computation（典型的例子containing关系，在computer science中，CFG、class inheritance都服从这种关系）

> NOTE: 上述这种建立model的思想在science中是广泛存在的，比如在概率论中，有着非常多的概率模型，数学家使用这些概率模型来描述实际问题，比如：
>
> - 正态分布
> - 二项式发布

后续，我会对computer science中常见的relation会进行深入研究，这样我们就可以使用已有的model来解决问题。

> NOTE: 在`Relation-structure-computation\Model`中对model进行描述。

computation是指为解决问题采用的algorithm；

## relation and structure

在上一节，我们提出了“**relation**决定**structure**”，关于此argument，我们需要进行深入思考：

- relation和structure之间的关系：relation的哪些特性决定了structure
- 在computer science中，常见的relation以及常见的structure

## graph and relation

**graph**是表示relation的有效工具，后面我们会看到graph的定义和relation的定义是非常类似的，基于graph的algorithm，可以解决很多relation的问题。所以，我们有必要学习graph-theory的知识。



## Computation

在discrete领域，我们考虑的主要是：对于具备relation的discrete objects的computation，后面我们将看到，对于某些relation，我们可以设计出非常高效的algorithm来对它们进行computation，我们将在`Computation`章节来讨论computation。

作为software engineer，我们需要思考的问题有：

### 哪些问题是可计算的？

可计算理论是对此问题的研究



### 该如何实现计算？

algorithm、常见的计算方式。

将会对如下两种重要的computation方式进行讨论：

- iteration
- recursion

### 计算的耗费

算法复杂度理论



### 计算的方向

沿着关系、结构来进行计算，一般，我们可以选择两个不同的方向。

比如：递归是自顶向下、动态规划是自底向上、backprop是自顶向下、bottom-up parsing。



## 结构化思维

在当我们使用relation来描述事物的时候（即按照上面描述的node、orderd-pair的方式来进行组织），我们会发现它们会形成一定的structure，比如graph、tree、chain，我们建这种思维称为“**结构化思维**”。

结构，可以是**有形**的结构，也可以是**无形**的、**逻辑**的结构。

下面结合具体的例子来对上述观点进行说明。

### 数学公式的结构

**Example: computational graph of math expression**

使用computational graph来描述math expression。

素材：维基百科[Backpropagation](https://en.wikipedia.org/wiki/Backpropagation)：forward network对应的数学公式：
$$
g(x):=f^{L}(W^{L}f^{L-1}(W^{L-1}\cdots f^{1}(W^{1}x)\cdots ))
$$



素材：`machine-learning\docs\Theory\Deep-learning\Book-deep-learning\Part-II-Deep-Networks-Modern-Practices\Model-And-layer-And-computation-And-computational-graph.md`



**Example: recurrence relation**

[recurrence relation](./Recursion/Recurrence-relation.md)其实所描述的是两个元素的关系，这种关系可能是线性的。

[recurrence relation](./Recursion/Recurrence-relation.md)是非常适合于使用computer algorithm来实现的，因为它是离散的，它是可以使用one-by-one来计算出来的，我们也可以说它具有离散结构。

### 结构化表示

上一节已经体现了使用**结构化思维**来看待**数学表达式**了，我觉得**计算机科学**是需要这种思维的，只有**结构化**了之后，计算机才能够对其进行表示（representation）、进而进行**计算**；这里所说的**结构化**如果往更高层面来思考的话，其实是：**形式化**，只有**形式化**后才能够使用计算机算法来进行计算，或者更加通俗地来说：**结构化**是**形式化**的一种。



产生式、函数表达式（expression）都是数学**语言**，它们描述了**关系**。

在computer science中，我们知道，graph也可以用来描述**关系**。

在计算机科学中，我们应该使用discrete relation来分析事物，从而对它们进行描述、计算：

- 产生式可以使用tree structure来表示，tree 是一种 graph
- 函数表达式可以使用computation graph来表示



基本上目前我碰到的这些离散的结构，都可以使用one-by-one的方式来设计算法。



## 章节说明

“relation”将在[Relation](./Relation/index.md)章节进行描述；

“structure”将在[Structure](./Structure/index.md)章节进行描述；

“computation”将在[Computation](./Computation/index.md)章节进行描述；



## Thoughts

- regular language是linear structure，context free language是hierarchy 结构。因为regular language的grammar，即regular grammar无法表达containing关系

- 结构：产生式是containing关系，是树结构；函数是computation graph
- 基于relation来设计algorithm：根据relation进行expand。在parsing中，是根据production进行expand，production所表达的是包含关系。在实际的graph中，则是根据相邻关系来进行expand的。
- 不同类型的graph支持不同的操作，但是有一些基本操作是全部都要支持的，比如查询一个node的adjacent node
- 图，排序，关系，有序性，方向
- 简单仅仅是复杂的一种简化，比如：chain《-tree《-graph；binary-search其实是一种deep-first-search

