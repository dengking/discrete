# Computer science is discrete



作为一个software engineer，我越来越觉得：

> Computer science is discrete.

computer science中两个非常基本的问题是：

1) representation

关于representation，在文章Language介绍了与它相关的内容；往具体说，它包含data structure。

2) computation

computation往具体说，它包含algorithm。



representation和computation密切相关：

1) 解决设计问题的第一步往往是：给出它的结构化的representation，关于结构化representation，参见`Relation-structure-computation\Representation-and-computation\Structured-representation`。

2) 好的representation是高效地实现computation的前提。



representation和computation都具备**discrete**特性，可以使用discrete math中的理论、思想来进行理解和描述，正如在wikipedia [Discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics)中所述：

> Concepts and notations from discrete mathematics are useful in studying and describing objects and problems in branches of [computer science](https://en.wikipedia.org/wiki/Computer_science), such as [computer algorithms](https://en.wikipedia.org/wiki/Computer_algorithm), [programming languages](https://en.wikipedia.org/wiki/Programming_language), [cryptography](https://en.wikipedia.org/wiki/Cryptography), [automated theorem proving](https://en.wikipedia.org/wiki/Automated_theorem_proving), and [software development](https://en.wikipedia.org/wiki/Software_development). Conversely, computer implementations are significant in applying ideas from discrete mathematics to real-world problems, such as in [operations research](https://en.wikipedia.org/wiki/Operations_research).

关于此的思考，触发了我写作本书，我的写作目的主要是：梳理discrete math的理论知识，用这些知识，更好地解决computer scientific中representation、computation，往更加具体来说是：

- 对于discrete objects相关的computation问题，如何设计algorithm？如何设计representation？

在`Discrete-math\Why-we-need-discrete-math`中，也阐述了我的写作动机。

关于discrete math，我想起了在大学二年级时学习discrete math课程，当时使用的教材是非常经典的[Discrete Mathematics and Its Applications](https://www.amazon.com/Discrete-Mathematics-Applications-Kenneth-Rosen/dp/125967651X)，因此这个工程中的一些内容是源自于这本教材。



## 例证

下面是论证“computer science is discrete”的例子：

### One-by-one model

在`Relation-structure-computation\Computation`中描述的one-by-one model体现了“Computer science is discrete"。one-by-one是典型的离散的，而不是连续的。

### Recursive definition and discrete

任何recursive definition，都是离散的，都可以进行计算



### 函数的执行是离散的

名称中的sub，表示其具备**包含关系**。

将函数抽象成一个一个的节点，则我们所描述的是一张图。

显然它是具备离散特性的。

它的执行模型是离散的

将调用一个函数看做是画一个点的话，函数的调用过程将呈现树结构，它是**包含关系**（在`Relation-structure-computation`章节会对此进行描述）。



### 0 and 1

everything in computer is 0 or 1.

### 数字电路

computer往往采用的是数字电路



## Discrete VS continuous

首先，来思考discrete的含义。

“discrete”即“离散”，“continuous”即“连续”，两者可以看做是一对反义词，如果是discrete的话，则必然就不是continuous的。

关于“discrete”的概念，维基百科[Discrete space](https://en.wikipedia.org/wiki/Discrete_space)给出了解释。我的直观理解就是不相连的、是一个一个node，后面我们将它称为“discrete object”。

关于“continuous”的概念，维基百科[Continuous function](https://en.wikipedia.org/wiki/Continuous_function)给出了解释，我的直观理解是相连的、是（平滑的）曲线。

关于这个问题，维基百科[Discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics)的第一段的论述也是比较好的。

根据这两个性质，可以将数学学科进行分类。



## Property of discrete objects

本节总结由discrete衍生出来的一系列特性，显然discrete objects除了具备discrete特性，还具备如下特性。

### Enumerable

“enumerable”即“可枚举的”，这个特性非常重要。

维基百科[Discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics)：

> Discrete objects can often be [enumerated](https://en.wikipedia.org/wiki/Enumeration) by integers. 



### Countable

关于“countable”，可以参见wikipedia [Countable set](https://en.wikipedia.org/wiki/Countable_set)。

discrete objects一般是countable的（有的是无法count的）。



### Computable

关于“computable”，参见维基百科[Computability theory](https://en.wikipedia.org/wiki/Computability_theory)、维基百科[Computability](https://en.wikipedia.org/wiki/Computability)。

discrete objects，一般是computable的，作为software engineer，我们就需要思考：如何来实现“Computation on discrete objects”；显然与此相关的一个重要课题就是：算法，这在后续的章节中会进行介绍。Countable是对computation进行量化进而进行**算法复杂度分析**的前提。