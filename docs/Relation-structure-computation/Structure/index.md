# Structure

“structure”即“结构”，在阅读维基百科computer science、数学相关的文章中，经常碰到“structure”概念，这引起了我思考：what is structure？本文就对这个问题进行剖析。

Structure是一个宏大的话题，structure不仅仅局限于我们肉眼可见的物理structure，它还包括我们肉眼无法看到的逻辑（抽象）structure(abstract structure)。

## What is structure?

下面是wikipedia [Structure](https://en.wikipedia.org/wiki/Structure)中给出的定义：

> A **structure** is an arrangement and **organization** of interrelated（相互关联） **elements** in a material object or [system](https://en.wikipedia.org/wiki/System), or the object or system so organized. Material structures include man-made objects such as [buildings](https://en.wikipedia.org/wiki/Building) and [machines](https://en.wikipedia.org/wiki/Machine) and natural objects such as [biological organisms](https://en.wikipedia.org/wiki/Organism), [minerals](https://en.wikipedia.org/wiki/Mineral) and [chemicals](https://en.wikipedia.org/wiki/Chemical_substance). Abstract structures include [data structures](https://en.wikipedia.org/wiki/Data_structure) in [computer science](https://en.wikipedia.org/wiki/Computer_science) and [musical form](https://en.wikipedia.org/wiki/Musical_form). 

上述定义中的“material structures”是指物理的、肉眼可见的结构。上述定义是general的，下面看看与计算机科学最最”亲密“的数学中对structure的定义：

wikipedia [Mathematical structure](https://en.wikipedia.org/wiki/Mathematical_structure): 

> In [mathematics](https://en.wikipedia.org/wiki/Mathematics), a **structure** is a set endowed（赋予） with some additional features on the set (e.g., [operation](https://en.wikipedia.org/wiki/Operation_(mathematics)), [relation](https://en.wikipedia.org/wiki/Relation_(math)), [metric](https://en.wikipedia.org/wiki/Metric_(mathematics)), [topology](https://en.wikipedia.org/wiki/Topology#Topologies_on_sets)). Often, the additional features are attached or related to the set, so as to provide it with some additional meaning or significance.

wikipedia [Structure (mathematical logic)](https://en.wikipedia.org/wiki/Structure_(mathematical_logic))：

> In [universal algebra](https://en.wikipedia.org/wiki/Universal_algebra) and in [model theory](https://en.wikipedia.org/wiki/Model_theory), a **structure** consists of a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) along with a collection of [finitary operations](https://en.wikipedia.org/wiki/Finitary) and [relations](https://en.wikipedia.org/wiki/Finitary_relation) that are defined on it.

wikipedia [Algebraic structure](https://en.wikipedia.org/wiki/Algebraic_structure):

> In [mathematics](https://en.wikipedia.org/wiki/Mathematics), more specifically in [abstract algebra](https://en.wikipedia.org/wiki/Abstract_algebra) and [universal algebra](https://en.wikipedia.org/wiki/Universal_algebra), an **algebraic structure** consists of a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) *A* (called the **underlying set**, **carrier set** or **domain**), a collection of [operations](https://en.wikipedia.org/wiki/Operation_(mathematics)) on *A* of finite [arity](https://en.wikipedia.org/wiki/Arity) (typically [binary operations](https://en.wikipedia.org/wiki/Binary_operation)), and a finite set of [identities](https://en.wikipedia.org/wiki/Identity_(mathematics)), known as [axioms](https://en.wikipedia.org/wiki/Axiom#Non-logical_axioms), that these operations must satisfy. 

简言之，在数学中，当谈及structure的时候，它表示的是一个set以及赋予给它的"feature"。

数学中的定义所使用的是 [数学语言](https://en.wikipedia.org/wiki/Language_of_mathematics)，general定义中的“elements”使用 **数学语言** 来描述是  [set](https://en.wikipedia.org/wiki/Set_(mathematics)) ，general定义中的“interrelated”使用 **数学语言** 来描述是 [operations](https://en.wikipedia.org/wiki/Operation_(mathematics)) 或 [relations](https://en.wikipedia.org/wiki/Finitary_relation)。

阅读了上述定义，直观感受就是：

1、**structure**所描述的是元素以及元素之间的关系。

2、相同的元素，如果使用不同的**关系**来进行组织，就是不同的**structure**，就呈现出不同的视觉**形态**（后文中，我们把这称之为“**形状**”）

所以，我们说：**关系决定（或者说：定义）了structure，进而决定了形状**，所以，我们在研究结构的时候，切莫忽视了对**关系**分析。

> NOTE: 这个思想，在`Relation-structure-computation\index.md`中已经给出，本文只是给出它的形成过程。

在wikipedia [Mathematical structure](https://en.wikipedia.org/wiki/Mathematical_structure)中，列举了一些数学中的structure：

> A partial list of possible structures are [measures](https://en.wikipedia.org/wiki/Measure_theory), [algebraic structures](https://en.wikipedia.org/wiki/Algebraic_structure) ([groups](https://en.wikipedia.org/wiki/Group_(mathematics)), [fields](https://en.wikipedia.org/wiki/Field_(mathematics)), etc.), [topologies](https://en.wikipedia.org/wiki/Topology), [metric structures](https://en.wikipedia.org/wiki/Metric_space) ([geometries](https://en.wikipedia.org/wiki/Geometry)), [orders](https://en.wikipedia.org/wiki/Order_theory), [events](https://en.wikipedia.org/wiki/Event_structure), [equivalence relations](https://en.wikipedia.org/wiki/Equivalence_relation), [differential structures](https://en.wikipedia.org/wiki/Differential_structure), and [categories](https://en.wikipedia.org/wiki/Category_(category_theory)).

通过上面的描述，现在让我们来回答本节标题中的问题：**structure是我们按照某种关系对元素进行组织后形成的**。



## 结构的形状

当我们按照一定的关系对元素进行组织后，我们可以使用digraph将它们给“画”出来，这时会呈现一定的“形状”（此处使用“形状”这个词，是为了与"结构""这个词有所区分，它强调的是，我们肉眼可以看到的形态，但是，平时，我们更多的还是使用结构这个词），比如

1、按照parent-child关系来组织process，最终形成的是树形结构

2、按照inheritance来组织类，如果不允许多继承的话，则最终形成的是**tree**；如果允许多继承的话，则最终形成的是**hierarchy**

比较典型的形状有：

- Chain，线性的
- Hierarchy，非线性的，呈现出层次的结构
- Tree
- Network， 参见维基百科[Network](https://en.wikipedia.org/wiki/Complex_network)
- Lattice，参见维基百科[Lattice](https://en.wikipedia.org/wiki/Lattice_(order))

上诉前四种**形状**是在计算机科学中非常常见的，后面我们会对它们进行分析。

## Relation决定structure

按照有的关系来组织数据，它们会形成树结构（不会成环），比如parent-children关系；按照有的关系来组织数据，它们会形成层次化结构（是图，因为它会成环），这就是我们在上一节中提出的“**relation决定structure**”结论，关于此，我们需要进行深入思考:

**Relation的哪些特性决定了structure，或者说：什么样的relation可以形成什么样的结构，比如chain、tree、graph？**

要搞清楚这个问题，首先我们需要对“Relation”理论有一定的了解（参见`Relation-structure-computation\Relation\Relation`），然后在深入分析我们肉眼看到的各种形状背后的relation的性质。我目前无法给出**通用的解答**，只能够结合具体的几种形状来进行分析，关于这几种结构的分析参见：

| 形状      | 描述章节                                                     | 说明          |
| --------- | ------------------------------------------------------------ | ------------- |
| Hierarchy | `Relation-structure-computation\Model\Hierarchy-relation-model` |               |
| Tree      | `Relation-structure-computation\Model\Containing-relation-model` |               |
| Chain     | `Relation-structure-computation\Model\Chain`                 |               |
| Network   |                                                              | 其实就是graph |



## Discrete structure

有了[discrete](../What-is-discrete-math/Discrete-math.md)概念和[structure](./Structure.md)概念，那么理解what is discrete structure就比较容易了。下面是一些关于discrete structure的内容：



### quora [Explain what is the role of Discrete Structures in Computer Science](https://www.quora.com/Explain-what-is-the-role-of-Discrete-Structures-in-Computer-Science#:~:text=)

**Discrete structures** is study of mathematical **structures** that are fundamentally **discrete** (that is not continuous). This is usually the first **mathematics** course for **computer science** students; it helps them to start thinking about problems in a way **computers** can solve.



### [ACM Discrete structures](http://wiki.acm.org/cs2001/index.php?title=Discrete_structures)



### [Discrete Mathematics and Its Applications](https://www.amazon.com/Discrete-Mathematics-Applications-Kenneth-Rosen/dp/125967651X)

在这本书的[Preface](../Book-Discrete-Mathematics-and-Its-Applications/Preface.md)、[chapter 2](../Book-Discrete-Mathematics-and-Its-Applications/Chapter-2-Basic-Structures/index.md)、[chapter 9](../Book-Discrete-Mathematics-and-Its-Applications/Chpater-9-Relations/index.md)中有对discrete structure的描述。



## Abstract structure

在`Relation-structure-computation\Structuralization-and-formalization`章节中介绍了abstract structure。

## Classification

本节对structure的进行分类，需要注意的是此处的structure更多的是指abstract structure，当然也包含data structure。

### 1) linear

线性结构。这样的structure是非常普遍的，并且非常容易computation，下面是一些例子:

- [Chomsky hierarchy](https://en.wikipedia.org/wiki/Chomsky_hierarchy)中的Type-3 language即[Regular](https://en.wikipedia.org/wiki/Regular_language)就是linear结构
- Factorial是典型的线性结构，关于此，参见: https://infogalactic.com/info/Recursion_(computer_science)

### 2) nonlinear

非线性结构



## Thoughts

- 使用structure概念能够使我们的描述非常地便利。

- 我对structure的直观理解是：structure是将set中的element按照relation进行组织后形成的。

- 我觉得structure是最最典型的具备discrete特性的，所以它们往往是computable的。

