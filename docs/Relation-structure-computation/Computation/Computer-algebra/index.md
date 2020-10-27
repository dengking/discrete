# 关于本章

本章讨论”computer algebra“即”计算代数“。

在学习back propagation的时候，查阅了 [如何直观地解释 backpropagation 算法？ - YE Y的回答 - 知乎](https://www.zhihu.com/question/27239198/answer/43560763) ，其中提及了“计算代数”，查询了一下，在计算机科学中是有这种学科的：Computer algebra，下面是wikipedia [Computer algebra](https://en.wikipedia.org/wiki/Computer_algebra) 。



## 维基百科 [Computer algebra](https://en.wikipedia.org/wiki/Computer_algebra)

In [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), **computer algebra**, also called **symbolic computation** or **algebraic computation**, is a scientific area that refers to the study and development of [algorithms](https://en.wikipedia.org/wiki/Algorithm) and [software](https://en.wikipedia.org/wiki/Software) for manipulating [mathematical expressions](https://en.wikipedia.org/wiki/Expression_(mathematics)) and other [mathematical objects](https://en.wikipedia.org/wiki/Mathematical_object). 





## Implementation of computer algebra: symbolic programming 

本节描述如何实现computer algebra，目前最常采用的一种方式是symbolic programming，在工程programming-language的`Theory\Programming-paradigm\Symbolic-programming`章节对它进行了详细介绍。

在software engineering中，我们常常需要以通用的方式来描述一个数学计算，比如: 

1) 如何描述computation graph

2) 在量化交易中，自定义**基差**计算公式

3) ......

在这类应用中，往往存在着两个阶段:

1) 构建阶段

使用symbol来构建math expression，往往需要使用domain-specifier language，比如直接使用math language。

2) Evaluation阶段

然后对这些symbol进行赋值，然后对math expression进行evaluate，从而得到最终的结果。

### Examples

下面是一些具体的实现: 

#### [SymPy](https://www.sympy.org/en/index.html)

**SymPy** is a Python library for **symbolic mathematics**. It aims to become a full-featured **computer algebra system** (CAS) while keeping the code as simple as possible in order to be comprehensible and easily extensible. SymPy is written entirely in Python.



#### ArashPartow [exprtk](https://github.com/ArashPartow/exprtk)



#### Deep learning

Deep learning中，我们需要构建computational graph，computational graph就是典型的symbolic mathematics。目前大多数deep learning implementation，都支持symbolic programming。

#### Expression template

Expression template是C++ TMP中的一种重要trick，参见`C-family-language\C++\Idiom\TMP\Expression-Template`。

#### Wolfram Language

参见wikipedia [Wolfram Language](https://en.wikipedia.org/wiki/Wolfram_Language): 

> It emphasizes [symbolic computation](https://en.wikipedia.org/wiki/Symbolic_computation), [functional programming](https://en.wikipedia.org/wiki/Functional_programming), and [rule-based programming](https://en.wikipedia.org/wiki/Rule-based_programming)[[8\]](https://en.wikipedia.org/wiki/Wolfram_Language#cite_note-LangName-8) and can employ arbitrary [structures](https://en.wikipedia.org/wiki/Data_structure) and data.[[8\]](https://en.wikipedia.org/wiki/Wolfram_Language#cite_note-LangName-8) It is the programming language of the mathematical symbolic computation program [Mathematica](https://en.wikipedia.org/wiki/Mathematica).[[9\]](https://en.wikipedia.org/wiki/Wolfram_Language#cite_note-25anv-9)



### Symbolic programming VS imperative programming in Symbolic mathematics

关于这个主题，参见工程machine-learning的`Programming\Programming-paradigm\Symbolic-and-imperative`章节。





## Computational graph

在wikipedia [Computer algebra](https://en.wikipedia.org/wiki/Computer_algebra) “`Computer science aspects#Expressions`”段中，让我想起了在compiler principle中描述的对expression的表示：syntax tree、grammar tree，显然computational graph也是一种表达方式；显然在计算代数中，非常重要的一个课题就是如何来表示computation，显然computational graph是一种非常强大的工具；各种各样的问题，如果要使用computer来进行解决，那么一个非常重要的课题就是：如何来表示？显然这是各种data structure排上用场的时候了。

symbolic computation: computational graph是就是一种典型的symbolic computation，它在6.5.5 Symbol-to-Symbol Derivatives、6.5.4 Back-Propagation Computation in Fully-Connected MLP 中有描述

关于computational graph，参见：

https://www.zhihu.com/question/27239198/answer/734273315

https://zhuanlan.zhihu.com/p/69175484

https://zhuanlan.zhihu.com/p/70075944

https://zhuanlan.zhihu.com/p/71869192





## 结构化表示

使用computational graph来表示expression，使用tree来表示formal language。它们都是使用计算机能够接受的language来描述事物的典型例子，它们都是一种language。计算机能够接受的语言：structure。所以，结构化方式，即使用结构化的语言进行描述是解决计算问题的第一步。这需要和结构化思维一起。



## 结构化思维

在文章：如何直观地解释 backpropagation 算法？ - Anonymous的回答 - 知乎

https://www.zhihu.com/question/27239198/answer/89853077 中有如下描述：

多层神经网络本质上是一个多层复合函数，数学是一门简洁但是含义丰富的原因，简单的公式，但是能够表达强大的结构