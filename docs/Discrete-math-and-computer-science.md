# Discrete math and computer science

> NOTE: 主要讨论如下议题：
>
> - 对于discrete objects的相关问题，如何设计algorithm来实现computation

正如在维基百科[Discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics)中所述：

> Concepts and notations from discrete mathematics are useful in studying and describing objects and problems in branches of [computer science](https://en.wikipedia.org/wiki/Computer_science), such as [computer algorithms](https://en.wikipedia.org/wiki/Computer_algorithm), [programming languages](https://en.wikipedia.org/wiki/Programming_language), [cryptography](https://en.wikipedia.org/wiki/Cryptography), [automated theorem proving](https://en.wikipedia.org/wiki/Automated_theorem_proving), and [software development](https://en.wikipedia.org/wiki/Software_development). Conversely, computer implementations are significant in applying ideas from discrete mathematics to real-world problems, such as in [operations research](https://en.wikipedia.org/wiki/Operations_research).

作为一个software engineer，对上面这段话的感受越来越深刻，总的来说，我越来越觉得：

> Computer science is discrete.

即“计算机科学是离散的”



## Example of discrete objects

[discrete structure](./Structure/Discrete-structure.md)、[recurrence relation](./Guide/Induction-and-Recursion/Recursion/Recurrence-relation.md)



### 函数调用过程是离散的

将调用一个函数看做是画一个点的话，函数的调用过程将呈现树结构，它是包含关系。



## Computation on discrete objects

在[Discrete math](./What-is-discrete-math/Discrete-math.md)中，我们已经总结了discrete objects的computable的特性，那如何来进行实现呢？下面是两种非常重要的computation形式：

- iteration
- recursion

后面我们将上述两种computation形式统称为“one-by-one”，很多的algorithm都是基于上述两种形式。

### 计算思维

当我们开始思考“Computation on discrete objects”的时候，其实就已经萌发了“计算思维”，即开始思考“哪些问题是可计算的？”、“该如何实现计算”

#### 哪些问题是可计算的？

Turing的可计算理论是对此的研究，下面是我基于discrete的直观的感受：对于discrete objects，分析其结构，找出规律，给出formal definition，那么我们就设计algorithm，对其进行计算。

#### 该如何实现计算

在“Computation on discrete objects”总结了两种非常常见的computation形式，其实这是非常粗浅的，更加具体说来是：基于discrete objects的relation、structure来设计algorithm。



##### relation and recursion

同一个关系、transitive relation、的structure，往往是recursive的

离散的结构可能具备递归特性，这样就可以进行递归定义了，就可以使用structural recursion来进行解决了。



什么样的关系可以形成什么样的结构。比如chain、tree、graph。

什么样的关系可以使用recursion来进行处理。

