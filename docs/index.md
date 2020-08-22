# 关于本工程



## Computer scientific is discrete

作为一个software engineer，我越来越觉得：

> Computer science is discrete.

computer science中两个非常基本的问题是：

- representation（往具体说，它包含data structure）
- computation（往具体说，它包含algorithm）

> representation和computation密切相关：
>
> - 解决设计问题的第一步往往是：给出它的结构化的representation
>
> - 好的representation是高效地实现computation的前提

representation和computation都具备**discrete**特性，可以使用discrete math中的理论、思想来进行理解和描述，正如在维基百科[Discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics)中所述：

> Concepts and notations from discrete mathematics are useful in studying and describing objects and problems in branches of [computer science](https://en.wikipedia.org/wiki/Computer_science), such as [computer algorithms](https://en.wikipedia.org/wiki/Computer_algorithm), [programming languages](https://en.wikipedia.org/wiki/Programming_language), [cryptography](https://en.wikipedia.org/wiki/Cryptography), [automated theorem proving](https://en.wikipedia.org/wiki/Automated_theorem_proving), and [software development](https://en.wikipedia.org/wiki/Software_development). Conversely, computer implementations are significant in applying ideas from discrete mathematics to real-world problems, such as in [operations research](https://en.wikipedia.org/wiki/Operations_research).

关于此的思考，触发了我写作本书，我的写作目的主要是：梳理discrete math的理论知识，用这些知识，更好地解决computer scientific中representation、computation，往更加具体来说是：

- 对于discrete objects相关的computation问题，如何设计algorithm？如何设计representation？

在`Discrete-math\Why-we-need-discrete-math.md`中，也阐述了我的写作动机。

关于discrete math，我想起了在大学二年级时学习discrete math课程，当时使用的教材是非常经典的[Discrete Mathematics and Its Applications](https://www.amazon.com/Discrete-Mathematics-Applications-Kenneth-Rosen/dp/125967651X)，因此这个工程中的一些内容是源自于这本教材。

在 [`Computer-science-is-discrete.md`](./Computer-science-is-discrete.md) 中给出了论证该观点的例子。



## 书写思路

首先说明什么是discrete、discrete math，然后描述discrete objects的特性，discrete objects的这些特性使得它是computable的，这样我们就可以设计algorithm来解决与它相关的问题。discrete math中的理论知识是后续algorithm、data-structure的基础。



## Discrete VS continuous

首先，来思考discrete的含义。

“discrete”即“离散”，“continuous”即“连续”，两者可以看做是一对反义词，如果是discrete的话，则必然就不是continuous的。

关于“discrete”的概念，维基百科[Discrete space](https://en.wikipedia.org/wiki/Discrete_space)给出了解释。我的直观理解就是不相连的、是一个一个node，后面我们将它称为“discrete object”。

关于“continuous”的概念，维基百科[Continuous function](https://en.wikipedia.org/wiki/Continuous_function)给出了解释，我的直观理解是相连的、是（平滑的）曲线。

关于这个问题，维基百科[Discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics)的第一段的论述也是比较好的。

根据这两个性质，可以将数学学科进行分类。



## Discrete math

本节回答“what is discrete math”，以及看看topics in discrete mathematics。

### 维基百科[Discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics)

**Discrete mathematics** is the study of [mathematical structures](https://en.wikipedia.org/wiki/Mathematical_structures) that are fundamentally [discrete](https://en.wikipedia.org/wiki/Discrete_space) rather than [continuous](https://en.wikipedia.org/wiki/Continuous_function). In contrast to [real numbers](https://en.wikipedia.org/wiki/Real_number) that have the property of varying "smoothly", the objects studied in discrete mathematics – such as [integers](https://en.wikipedia.org/wiki/Integer), [graphs](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)), and [statements](https://en.wikipedia.org/wiki/Statement_(logic)) in [logic](https://en.wikipedia.org/wiki/Mathematical_logic) – do not vary smoothly in this way, but have distinct, separated values. Discrete mathematics therefore excludes topics in "continuous mathematics" such as [calculus](https://en.wikipedia.org/wiki/Calculus) or [Euclidean geometry](https://en.wikipedia.org/wiki/Euclidean_geometry). Discrete objects can often be [enumerated](https://en.wikipedia.org/wiki/Enumeration) by integers. More formally, discrete mathematics has been characterized as the branch of mathematics dealing with [countable sets](https://en.wikipedia.org/wiki/Countable_set) (finite sets or sets with the same [cardinality](https://en.wikipedia.org/wiki/Cardinality) as the natural numbers). 

> NOTE: 维基百科的这一段总结的非常好。



#### [Topics in discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics#Topics_in_discrete_mathematics)



## Property of discrete objects

本节总结由discrete衍生出来的一系列特性，显然discrete objects除了具备discrete特性，还具备如下特性。

### Enumerable

“enumerable”即“可枚举的”，这个特性非常重要。

维基百科[Discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics)：

> Discrete objects can often be [enumerated](https://en.wikipedia.org/wiki/Enumeration) by integers. 



### Countable

关于“countable”，可以参见维基百科[Countable set](https://en.wikipedia.org/wiki/Countable_set)。

discrete objects一般是countable的（有的是无法count的）。



### Computable

关于“computable”，参见维基百科[Computability theory](https://en.wikipedia.org/wiki/Computability_theory)、维基百科[Computability](https://en.wikipedia.org/wiki/Computability)。

discrete objects，一般是computable的，作为software engineer，我们就需要思考：如何来实现“Computation on discrete objects”；显然与此相关的一个重要课题就是：算法，这在后续的章节中会进行介绍。

