# 结构化(structuralization) 和 形式化(formalization)

## 结构化(structuralization)

在当我们使用**relation**来描述事物的时候（即按照前面描述的node、orderd-pair的方式来进行组织），我们会发现它们会形成一定的structure，比如graph、tree、chain，我们建这种思维称为“**结构化思维**”，它其实就是"**计算思维**"(参见`Relation-structure-computation\Computation`章节)。

我们将根据relation得出其**structure**、**结构化表示**的过程称为**结构化**/**形式化**。只有**结构化**/**形式化**后才能够实现**computation**。

> NOTE: 
> 1、formal representation

我觉得**计算机科学**是需要这种思维的，只有**结构化**了之后，计算机才能够对其进行**表示**（representation）、进而进行**计算**（computation）；这里所说的**结构化**如果往更高层面来思考的话，其实是：**形式化**，只有**形式化**后才能够使用计算机算法来进行计算，或者更加通俗地来说：**结构化**是**形式化**的一种。

### Examples

**Structureed data**

结构化数据

**SQL**

http://en.wikipedia.org/wiki/SQL

**File format**

描述文件的结构



## 从"语言"的角度来看待结构化

> NOTE: 从语言的角度来看待结构化

在文章`Language`中，我们已经知道**一切“描述”都是语言**。我们可以使用不同的language来进行描述，在computer science中，我们需要采用computer能够理解的语言来进行描述，这就是本节提出的"**结构化表示/语言**"，在上一节提出的**结构化思维**，能够帮助我们理解、创造适合于问题的representation。

**结构化表示/语言**是一种**计算机语言**，结构化表示后，才能够进行**computation**。



## Abstract structure

> NOTE: 
>
> 1、这在 `Structure` 章节中已经讨论了

结构，可以是**有形**的结构，也可以是**无形**的、**逻辑**的结构，这就是**abstract structure**。显然，我们**结构化**得到的是**abstract structure**。

在wikipedia [Language of mathematics](https://en.wikipedia.org/wiki/Language_of_mathematics)中，有对abstract structure的描述:

> **Mathematics describes abstract structures**: on the other hand, there are areas of pure mathematics which deal with [abstract structures](https://en.wikipedia.org/wiki/Abstract_structure), which have no known physical counterparts at all. However, it is difficult to give any categorical examples here, as even the most abstract structures can be co-opted as models in some branch of physics (see [Calabi-Yau spaces](https://en.wikipedia.org/wiki/Calabi-Yau_spaces) and [string theory](https://en.wikipedia.org/wiki/String_theory)).





## Examples

下面结合具体的例子来对上述观点进行说明。不同的领域有着各自的representation。



### Example: [Linguistics](https://en.wikipedia.org/wiki/Linguistics) 

在语言学中使用[Grammar](https://en.wikipedia.org/wiki/Grammar)、[Syntax](https://en.wikipedia.org/wiki/Syntax)来表示语言的结构，最最典型的就是[Phrase structure grammar](https://en.wikipedia.org/wiki/Parsing_of_natural_language)。

regular language是linear structure，context free language是hierarchy 结构。因为regular language的grammar，即regular grammar无法表达containing关系。

典型的例子就是compile principle中，广泛地使用tree、graph来，对于语言这种看似非常灵活的、无规律的东西，进行**形式化**的描述，这让programming language称为了可能。



#### Representation of word

参见工程machine-learning的`Application\NLP\Representation-of-word`章节 。



### Example: Computer algebra

参见 `Computer-algebra` 章节。



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

