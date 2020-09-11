# 结构化思维

在当我们使用relation来描述事物的时候（即按照上面描述的node、orderd-pair的方式来进行组织），我们会发现它们会形成一定的structure，比如graph、tree、chain，我们建这种思维称为“**结构化思维**”。

结构，可以是**有形**的结构，也可以是**无形**的、**逻辑**的结构。

下面结合具体的例子来对上述观点进行说明。

## 数学公式的结构



### Example: computational graph of math expression

使用computational graph来描述math expression。

素材：维基百科[Backpropagation](https://en.wikipedia.org/wiki/Backpropagation)：forward network对应的数学公式：
$$
g(x):=f^{L}(W^{L}f^{L-1}(W^{L-1}\cdots f^{1}(W^{1}x)\cdots ))
$$



素材：`machine-learning\docs\Theory\Deep-learning\Book-deep-learning\Part-II-Deep-Networks-Modern-Practices\Model-And-layer-And-computation-And-computational-graph.md`



### Example: recurrence relation

[recurrence relation](./Recursion/Recurrence-relation.md)其实所描述的是两个元素的关系，这种关系可能是线性的。

[recurrence relation](./Recursion/Recurrence-relation.md)是非常适合于使用computer algorithm来实现的，因为它是离散的，它是可以使用one-by-one来计算出来的，我们也可以说它具有离散结构。

比如 :

- 递归公式 [Fibonacci number](https://en.wikipedia.org/wiki/Fibonacci_number)的结构非常类似于binary tree。



### Example: permutation and combination

permutation和combination都是使用的乘法，它们都是nesting关系，都呈现出 tree 结构，在`Relation-structure-computation\Computation\Algorithm\Paradigm\Backtracking\Backtrack`章节中有**组合树**、**排列树**的描述。

## 过程的结构

一些动态过程，比如函数执行过程、推导过程等，都呈现出一定的结构，本节对此进行分析，显然这种结构就是前面提到的逻辑结构。

### Proof过程呈现出list或tree结构

在阅读[Proof theory](https://en.wikipedia.org/wiki/Proof_theory)时，其中的一段话：

> Proofs are typically presented as inductively-defined [data structures](https://en.wikipedia.org/wiki/Data_structures) such as plain lists, boxed lists, or [trees](https://en.wikipedia.org/wiki/Tree_(data_structure)), which are constructed according to the [axioms](https://en.wikipedia.org/wiki/Axiom) and [rules of inference](https://en.wikipedia.org/wiki/Rule_of_inference) of the logical system.

上面这段话的意思是，如果将推导的过程可以展示为一种数据结构，比如列表、树。[Parse tree](http://en.wikipedia.org/wiki/Parse_tree)就是一个典型的例子，在自顶向下[parsing](https://en.wikipedia.org/wiki/Parsing)的过程中，parser不断地使用production进行推导（expand），最终生成了一棵parse tree。

### Parsing过程产生[Parse tree](http://en.wikipedia.org/wiki/Parse_tree)

在工程[automata-and-formal-language](https://dengking.github.io/automata-and-formal-language/)的[Formal-language](https://dengking.github.io/automata-and-formal-language/Formal-language/)章节的[Summary-of-theory](https://dengking.github.io/automata-and-formal-language/Formal-language/Summary-of-theory/)文章中我们已经总结了生成parse tree的过程相当于进行Proof，所以将本节置于“Proof过程呈现出list或tree结构”中。

### 函数调用过程呈现tree结构

在[Compilers Principles, Techniques and Tools Second Edition(aka ***dragon book***)](https://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools) 的[7.2.1 Activation Trees](https://dengking.github.io/compiler-principle/Chapter-7-Run-Time-Environments/7.2-Stack-Allocation-of-Space/#721-activation-trees)中对此进行了详细分析。



## Entity-relation model

对于现实生活中的复杂的relation，在DBMS中，需要考虑如何来表示、存储它们，DBMS中的entity-relation model就是对这个问题的回答。

## 结构化表示

上一节使用**结构化思维**来看待**数学表达式**了，我觉得**计算机科学**是需要这种思维的，只有**结构化**了之后，计算机才能够对其进行**表示**（representation）、进而进行**计算**（computation）；这里所说的**结构化**如果往更高层面来思考的话，其实是：**形式化**，只有**形式化**后才能够使用计算机算法来进行计算，或者更加通俗地来说：**结构化**是**形式化**的一种。

在`Relation-structure-computation\Representation-and-computation.md`中，对这个话题进行了展开。



## Thoughts

- 结构：产生式是containing关系，是树结构；函数是computation graph
- 不同类型的graph支持不同的操作，但是有一些基本操作是全部都要支持的，比如查询一个node的adjacent node
- 图，排序，关系，有序性，方向
- 简单仅仅是复杂的一种简化，比如：chain《-tree《-graph；binary-search其实是一种deep-first-search