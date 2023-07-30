# Discrete objects

作为一个software engineer，我越来越觉得：

> Computer science is discrete.

为什么呢？因为我发现computer science所研究的对象可以概括为"**discrete objects**": 

1、具备 **relation** 的discrete objects

> draft: 
>
> 1、这在 "Relation-structure-computation" 中进行了很好的描述

2、连续的对象，往往首先需要离散化(discretization)，才能够对它进行表示，进而设计算法来对它进行解决

> draft: 
>
> 1、discretization的一个典型例子: 路网模型



computer science中两个非常基本的问题是：

一、representation

"representation"即"表示"。

2、how to represent？discrete it. 

二、computation

computation往具体说，它会包含algorithm。



使用程序解决设计问题的第一步：给出它的结构化的representation，否则，它将很难使用计算机程序解决，而对于具备relation的discrete objects，我们往往能够找到较好的representation，从而设计算法来解决问题，并且好的representation是高效地实现computation的前提。

思考: 对于discrete objects相关的computation问题，如何设计algorithm？如何设计representation？

关于此的思考，触发了我写作本书，我的写作目的主要是：梳理相关的理论知识与实践经验，以图寻找背后抽象的规律。

> draft: 
>
> 1、这一步涉及对问题进行离散化
>
> 2、关于结构化representation，参见`Relation-structure-computation\Representation-and-computation\Structured-representation`。
>
> 3、解决问题的思路: 离散化然后找到合适的表示。



从更加抽象的角度来思考，我们会发现，representation和computation都具备**discrete**特性，下面是一些例证: 

> Draft:
>
> 一、下面是论证“computer science is discrete”的例子：
>
> 二、本节的内容让我联想到了抽象数学中的abstract structure。

一、One-by-one model

在`Relation-structure-computation\Computation`中描述的one-by-one model体现了“Computer science is discrete"。one-by-one是典型的离散的，而不是连续的。

二、Recursive definition and discrete

任何recursive definition，都是离散的，都可以进行计算

三、函数的执行是离散的

名称中的sub，表示其具备**包含关系**。

将函数抽象成一个一个的节点，则我们所描述的是一张图。

显然它是具备离散特性的。

它的执行模型是离散的

将调用一个函数看做是画一个点的话，函数的调用过程将呈现树结构，它是**包含关系**（在`Relation-structure-computation`章节会对此进行描述）。

四、0 and 1

everything in computer is 0 or 1.

五、数字电路

computer往往采用的是数字电路



## Property of discrete objects

本节总结由discrete衍生出来的一系列特性，显然discrete objects除了具备discrete特性，还具备如下特性。

### Enumerable

“enumerable”即“可枚举的”，这个特性非常重要。

wikipedia [Discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics)：

> Discrete objects can often be [enumerated](https://en.wikipedia.org/wiki/Enumeration) by integers. 



### Countable

关于“countable”，可以参见wikipedia [Countable set](https://en.wikipedia.org/wiki/Countable_set)。

discrete objects一般是countable的（有的是无法count的）。



### Computable

关于“computable”，参见 wikipedia [Computability theory](https://en.wikipedia.org/wiki/Computability_theory)、wikipedia [Computability](https://en.wikipedia.org/wiki/Computability)。

discrete objects，一般是computable的，作为software engineer，我们就需要思考：如何来实现“Computation on discrete objects”；显然与此相关的一个重要课题就是：算法，这在后续的章节中会进行介绍。Countable是对computation进行量化进而进行**算法复杂度分析**的前提。



## Discrete VS continuous

首先，来思考discrete的含义。

“discrete”即“离散”，“continuous”即“连续”，两者可以看做是一对反义词，如果是discrete的话，则必然就不是continuous的。

关于“discrete”的概念，wikipedia [Discrete space](https://en.wikipedia.org/wiki/Discrete_space)给出了解释。我的直观理解就是不相连的、是一个一个node，后面我们将它称为“discrete object”。

关于“continuous”的概念，wikipedia [Continuous function](https://en.wikipedia.org/wiki/Continuous_function)给出了解释，我的直观理解是相连的、是（平滑的）曲线。

关于这个问题，wikipedia [Discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics)的第一段的论述也是比较好的。

根据这两个性质，可以将数学学科进行分类。



## Discrete math

关于discrete math，我想起了在大学二年级时学习discrete math课程，当时使用的教材是非常经典的[Discrete Mathematics and Its Applications](https://www.amazon.com/Discrete-Mathematics-Applications-Kenneth-Rosen/dp/125967651X)，因此这个工程中的一些内容是源自于这本教材。

可以使用discrete math中的理论、思想来进行理解和描述，正如在wikipedia [Discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics)中所述：

> Concepts and notations from discrete mathematics are useful in studying and describing objects and problems in branches of [computer science](https://en.wikipedia.org/wiki/Computer_science), such as [computer algorithms](https://en.wikipedia.org/wiki/Computer_algorithm), [programming languages](https://en.wikipedia.org/wiki/Programming_language), [cryptography](https://en.wikipedia.org/wiki/Cryptography), [automated theorem proving](https://en.wikipedia.org/wiki/Automated_theorem_proving), and [software development](https://en.wikipedia.org/wiki/Software_development). Conversely, computer implementations are significant in applying ideas from discrete mathematics to real-world problems, such as in [operations research](https://en.wikipedia.org/wiki/Operations_research).



