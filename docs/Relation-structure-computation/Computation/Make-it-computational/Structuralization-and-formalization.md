# 结构化(structuralization) 和 形式化(formalization)

在当我们使用**relation**来描述事物的时候（即按照上面描述的node、orderd-pair的方式来进行组织），我们会发现它们会形成一定的structure，比如graph、tree、chain，我们建这种思维称为“**结构化思维**”，它其实就是"**计算思维**"(参见`Relation-structure-computation\Computation`章节)。

我们将根据relation得出其**structure**、**结构化表示**的过程称为**结构化**/**形式化**。只有**结构化**/**形式化**后才能够实现**computation**。

我觉得**计算机科学**是需要这种思维的，只有**结构化**了之后，计算机才能够对其进行**表示**（representation）、进而进行**计算**（computation）；这里所说的**结构化**如果往更高层面来思考的话，其实是：**形式化**，只有**形式化**后才能够使用计算机算法来进行计算，或者更加通俗地来说：**结构化**是**形式化**的一种。



## 从"语言"的角度来看待结构化

> NOTE: 从语言的角度来看待结构化

在文章`Language.md`中，我们已经知道**一切“描述”都是语言**。我们可以使用不同的language来进行描述，在computer science中，我们需要采用computer能够理解的语言来进行描述，这就是本节提出的"**结构化表示/语言**"，在上一节提出的**结构化思维**，能够帮助我们理解、创造适合于问题的representation。

**结构化表示/语言**是一种**计算机语言**，结构化表示后，才能够进行**computation**。

### Examples

**Structureed data**

结构化数据

**SQL**

http://en.wikipedia.org/wiki/SQL

**File format**

描述文件的结构



## Abstract structure

结构，可以是**有形**的结构，也可以是**无形**的、**逻辑**的结构，这就是**abstract structure**。显然，我们**结构化**得到的是**abstract structure**。

在wikipedia [Language of mathematics](https://en.wikipedia.org/wiki/Language_of_mathematics)中，有对abstract structure的描述:

> **Mathematics describes abstract structures**: on the other hand, there are areas of pure mathematics which deal with [abstract structures](https://en.wikipedia.org/wiki/Abstract_structure), which have no known physical counterparts at all. However, it is difficult to give any categorical examples here, as even the most abstract structures can be co-opted as models in some branch of physics (see [Calabi-Yau spaces](https://en.wikipedia.org/wiki/Calabi-Yau_spaces) and [string theory](https://en.wikipedia.org/wiki/String_theory)).

下面结合具体的例子来对上述观点进行说明。



### Examples

不同的领域有着各自的representation。

### Example: [Linguistics](https://en.wikipedia.org/wiki/Linguistics) 

在语言学中使用[Grammar](https://en.wikipedia.org/wiki/Grammar)、[Syntax](https://en.wikipedia.org/wiki/Syntax)来表示语言的结构，最最典型的就是[Phrase structure grammar](https://en.wikipedia.org/wiki/Parsing_of_natural_language)。

regular language是linear structure，context free language是hierarchy 结构。因为regular language的grammar，即regular grammar无法表达containing关系。

典型的例子就是compile principle中，广泛地使用tree、graph来，对于语言这种看似非常灵活的、无规律的东西，进行**形式化**的描述，这让programming language称为了可能。



#### Representation of word

参见工程machine-learning的`Application\NLP\Representation-of-word`章节 。



### Example: Computer algebra

产生式、函数表达式（expression）都是数学**语言**，它们描述了**关系**。

在computer science中，我们知道，graph也可以用来描述**关系**。

在计算机科学中，我们应该使用discrete relation来分析事物，从而对它们进行描述、计算：

- 产生式可以使用tree structure来表示，tree 是一种 graph
- 函数表达式可以使用computation graph来表示



#### Computational graph and tree

使用computational graph来表示expression，使用tree来表示formal language。它们都是使用计算机能够接受的language来描述事物的典型例子，它们都是一种language。计算机能够接受的语言：structure。所以，结构化方式，即使用结构化的语言进行描述是解决计算问题的第一步。这需要和结构化思维一起。





#### 数学公式的结构

数学公式的结构是典型的abstract structure。

#### Example: computational graph of math expression

使用computational graph来描述math expression。

素材：维基百科[Backpropagation](https://en.wikipedia.org/wiki/Backpropagation)：forward network对应的数学公式：
$$
g(x):=f^{L}(W^{L}f^{L-1}(W^{L-1}\cdots f^{1}(W^{1}x)\cdots ))
$$



素材：`machine-learning\docs\Theory\Deep-learning\Book-deep-learning\Part-II-Deep-Networks-Modern-Practices\Model-And-layer-And-computation-And-computational-graph.md`



#### Example: recurrence relation

[recurrence relation](./Recursion/Recurrence-relation.md)其实所描述的是两个元素的关系，这种关系可能是线性的。

[recurrence relation](./Recursion/Recurrence-relation.md)是非常适合于使用computer algorithm来实现的，因为它是离散的，它是可以使用one-by-one来计算出来的，我们也可以说它具有离散结构。

比如 :

- 递归公式 [Fibonacci number](https://en.wikipedia.org/wiki/Fibonacci_number)的结构非常类似于binary tree。



#### Example: permutation and combination

permutation和combination都是使用的乘法，它们都是nesting关系，都呈现出 tree 结构，在`Relation-structure-computation\Computation\Algorithm\Paradigm\Backtracking\Backtrack`章节中有**组合树**、**排列树**的描述。





#### [Algebraic structure](https://infogalactic.com/info/Algebraic_structure)



#### [Mathematical structure](https://en.wikipedia.org/wiki/Mathematical_structure)

In [mathematics](https://en.wikipedia.org/wiki/Mathematics), a **structure** is a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) endowed with some additional features on the set (e.g., [operation](https://en.wikipedia.org/wiki/Operation_(mathematics)), [relation](https://en.wikipedia.org/wiki/Relation_(math)), [metric](https://en.wikipedia.org/wiki/Metric_(mathematics)), [topology](https://en.wikipedia.org/wiki/Topology#Topologies_on_sets)).[[1\]](https://en.wikipedia.org/wiki/Mathematical_structure#cite_note-1) Often, the additional features are attached or related to the set, so as to provide it with some additional meaning or significance.



### Example: Entity-relation model in DBMS

使用Entity-relation model来描述现实世界，从后使用table来进行存储。

参见: [Entity-relation model](https://en.wikipedia.org/wiki/Entity%E2%80%93relationship_model)。



### Example: 过程的结构

一些动态过程，比如函数执行过程、推导过程等，都呈现出一定的结构，本节对此进行分析，显然这种结构就是前面提到的逻辑结构。

#### Proof过程呈现出list或tree结构

在阅读[Proof theory](https://en.wikipedia.org/wiki/Proof_theory)时，其中的一段话：

> Proofs are typically presented as inductively-defined [data structures](https://en.wikipedia.org/wiki/Data_structures) such as plain lists, boxed lists, or [trees](https://en.wikipedia.org/wiki/Tree_(data_structure)), which are constructed according to the [axioms](https://en.wikipedia.org/wiki/Axiom) and [rules of inference](https://en.wikipedia.org/wiki/Rule_of_inference) of the logical system.

上面这段话的意思是，如果将推导的过程可以展示为一种数据结构，比如列表、树。[Parse tree](http://en.wikipedia.org/wiki/Parse_tree)就是一个典型的例子，在自顶向下[parsing](https://en.wikipedia.org/wiki/Parsing)的过程中，parser不断地使用production进行推导（expand），最终生成了一棵parse tree。

#### Parsing过程产生[Parse tree](http://en.wikipedia.org/wiki/Parse_tree)

在工程[automata-and-formal-language](https://dengking.github.io/automata-and-formal-language/)的[Formal-language](https://dengking.github.io/automata-and-formal-language/Formal-language/)章节的[Summary-of-theory](https://dengking.github.io/automata-and-formal-language/Formal-language/Summary-of-theory/)文章中我们已经总结了生成parse tree的过程相当于进行Proof，所以将本节置于“Proof过程呈现出list或tree结构”中。



#### 函数调用过程呈现tree结构

在[Compilers Principles, Techniques and Tools Second Edition(aka ***dragon book***)](https://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools) 的[7.2.1 Activation Trees](https://dengking.github.io/compiler-principle/Chapter-7-Run-Time-Environments/7.2-Stack-Allocation-of-Space/#721-activation-trees)中对此进行了详细分析。

