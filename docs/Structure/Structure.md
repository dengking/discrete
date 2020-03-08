# Structure

“structure”即“结构”，在阅读维基百科computer science、数学相关的文章中，经常碰到“structure”概念，这引起了我思考：what is structure？本文就对这个问题进行剖析。

Structure是一个宏大的话题，structure不仅仅局限于我们肉眼可见的物理structure，它还包括我们肉眼无法看到的逻辑（抽象）structure。

## What is structure?

下面是维基百科[Structure](https://en.wikipedia.org/wiki/Structure)中给出的定义：

> A **structure** is an arrangement and **organization** of interrelated（相互关联） **elements** in a material object or [system](https://en.wikipedia.org/wiki/System), or the object or system so organized. Material structures include man-made objects such as [buildings](https://en.wikipedia.org/wiki/Building) and [machines](https://en.wikipedia.org/wiki/Machine) and natural objects such as [biological organisms](https://en.wikipedia.org/wiki/Organism), [minerals](https://en.wikipedia.org/wiki/Mineral) and [chemicals](https://en.wikipedia.org/wiki/Chemical_substance). Abstract structures include [data structures](https://en.wikipedia.org/wiki/Data_structure) in [computer science](https://en.wikipedia.org/wiki/Computer_science) and [musical form](https://en.wikipedia.org/wiki/Musical_form). 

上述定义中的“material structures”是指物理的、肉眼可见的结构。上述定义是general的，下面看看与计算机科学最最”亲密“的数学中对structure的定义：

[Mathematical structure](https://en.wikipedia.org/wiki/Mathematical_structure)

> In [mathematics](https://en.wikipedia.org/wiki/Mathematics), a **structure** is a set endowed（赋予） with some additional features on the set (e.g., [operation](https://en.wikipedia.org/wiki/Operation_(mathematics)), [relation](https://en.wikipedia.org/wiki/Relation_(math)), [metric](https://en.wikipedia.org/wiki/Metric_(mathematics)), [topology](https://en.wikipedia.org/wiki/Topology#Topologies_on_sets)). Often, the additional features are attached or related to the set, so as to provide it with some additional meaning or significance.

[Structure (mathematical logic)](https://en.wikipedia.org/wiki/Structure_(mathematical_logic))：

> In [universal algebra](https://en.wikipedia.org/wiki/Universal_algebra) and in [model theory](https://en.wikipedia.org/wiki/Model_theory), a **structure** consists of a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) along with a collection of [finitary operations](https://en.wikipedia.org/wiki/Finitary) and [relations](https://en.wikipedia.org/wiki/Finitary_relation) that are defined on it.

[Algebraic structure](https://en.wikipedia.org/wiki/Algebraic_structure)

> In [mathematics](https://en.wikipedia.org/wiki/Mathematics), more specifically in [abstract algebra](https://en.wikipedia.org/wiki/Abstract_algebra) and [universal algebra](https://en.wikipedia.org/wiki/Universal_algebra), an **algebraic structure** consists of a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) *A* (called the **underlying set**, **carrier set** or **domain**), a collection of [operations](https://en.wikipedia.org/wiki/Operation_(mathematics)) on *A* of finite [arity](https://en.wikipedia.org/wiki/Arity) (typically [binary operations](https://en.wikipedia.org/wiki/Binary_operation)), and a finite set of [identities](https://en.wikipedia.org/wiki/Identity_(mathematics)), known as [axioms](https://en.wikipedia.org/wiki/Axiom#Non-logical_axioms), that these operations must satisfy. 

简言之，在数学中，当谈及structure的时候，它表示的是一个set以及赋予给它的feature。

数学中的定义所使用的是[数学语言](https://en.wikipedia.org/wiki/Language_of_mathematics)，general定义中的“elements”使用 **数学语言** 来描述是  [set](https://en.wikipedia.org/wiki/Set_(mathematics)) ，general定义中的“interrelated”使用 **数学语言** 来描述是 [operations](https://en.wikipedia.org/wiki/Operation_(mathematics)) 或 [relations](https://en.wikipedia.org/wiki/Finitary_relation)。

阅读了上述定义，直观感受就是：**structure**不仅仅关乎元素，而且关乎它们之间的**关系**。总的来说：**structure**所描述的是元素以及元素之间的关系。

相同的元素，如果使用不同的**关系**来进行组织，就是不同的**structure**，就呈现出不同的视觉**形态**（后文中，我们把这称之为“**形状**”），所以，在此，我们说：**关系决定（或者说：定义）了structure，进而决定了形状**，所以，我们在研究结构的时候，切莫忽视了对关系分析。

在维基百科[Mathematical structure](https://en.wikipedia.org/wiki/Mathematical_structure)中，列举了一些数学中的structure：

> A partial list of possible structures are [measures](https://en.wikipedia.org/wiki/Measure_theory), [algebraic structures](https://en.wikipedia.org/wiki/Algebraic_structure) ([groups](https://en.wikipedia.org/wiki/Group_(mathematics)), [fields](https://en.wikipedia.org/wiki/Field_(mathematics)), etc.), [topologies](https://en.wikipedia.org/wiki/Topology), [metric structures](https://en.wikipedia.org/wiki/Metric_space) ([geometries](https://en.wikipedia.org/wiki/Geometry)), [orders](https://en.wikipedia.org/wiki/Order_theory), [events](https://en.wikipedia.org/wiki/Event_structure), [equivalence relations](https://en.wikipedia.org/wiki/Equivalence_relation), [differential structures](https://en.wikipedia.org/wiki/Differential_structure), and [categories](https://en.wikipedia.org/wiki/Category_(category_theory)).

通过上面的描述，现在让我们来回答本节标题中的问题：structure是我们按照某种关系对元素进行组织后形成的。

## 如何来表示structure？



## 思考

### Structure of  recurrence relation

显然recurrence relation也是一种结构。

#### [Fibonacci number](https://en.wikipedia.org/wiki/Fibonacci_number)的递归公式的结构

我觉得fibonacci number的递归公式的结构非常类似于binary tree。