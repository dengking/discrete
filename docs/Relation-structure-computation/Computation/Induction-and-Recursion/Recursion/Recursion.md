# Recursion

本文描述Recursion，其实上一篇[Recursive-definition](./Recursive-definition.md)中的内容是更加容易理解的。

## 维基百科[Recursion](https://en.wikipedia.org/wiki/Recursion)

**Recursion** (adjective: *recursive*) occurs when a thing is defined in terms of **itself** or of its type. 

> NOTE: 其实上述定义就是的含义其实就是[recursive definition](./Recursive-definition.md)。在维基百科[Recursive acronym](https://en.wikipedia.org/wiki/Recursive_acronym)中使用 “refers to itself” 来表达这种含义。

Recursion is used in a variety of disciplines ranging from [linguistics](https://en.wikipedia.org/wiki/Linguistics) to [logic](https://en.wikipedia.org/wiki/Logic). The most common application of recursion is in [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), where a [function](https://en.wikipedia.org/wiki/Function_(mathematics)) being defined is applied within its own definition. While this apparently defines an infinite number of instances (function values), it is often done in such a way that no **loop** or **infinite chain** of references can occur.

> NOTE: 如果出现loop或者infinite chain，则程序就会出现死循环；

## Formal definitions

In mathematics and computer science, a class of objects or methods exhibits **recursive behavior** when it can be defined by two properties:

1. A simple **base case** (or cases)—a **terminating scenario** that does not use **recursion** to produce an answer
2. A set of rules that **reduces**（这个词用得非常好） all other cases toward the **base case**

> NOTE: “reduce”说明recursion是自顶向下的。



The [Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence) is a classic example of recursion:

$ {\text{Fib}}(0)=0{\text{ as base case 1,}} $

$ {\text{Fib}}(1)=1{\text{ as base case 2,}} $

$ {\text{For all integers }}n>1,~{\text{ Fib}}(n):={\text{Fib}}(n-1)+{\text{Fib}}(n-2). $



Many mathematical axioms（公理） are based upon **recursive rules**. For example, the formal definition of the [natural numbers](https://en.wikipedia.org/wiki/Natural_number) by the [Peano axioms](https://en.wikipedia.org/wiki/Peano_axioms) can be described as: *0 is a natural number, and each natural number has a successor, which is also a natural number.* By this base case and recursive rule, one can generate the set of all natural numbers.

Recursively defined mathematical objects include [functions](https://en.wikipedia.org/wiki/Function_(mathematics)), [sets](https://en.wikipedia.org/wiki/Set_(mathematics)), and especially [fractals](https://en.wikipedia.org/wiki/Fractal).

> NOTE: 软件工程师应该对recursive definition敏感。

## [In mathematics](https://en.wikipedia.org/wiki/Recursion#In_mathematics)



### Recursively defined sets

参见文章[Recursive definition](./Recursive-definition.md)。

#### [Example: the natural numbers](https://en.wikipedia.org/wiki/Recursion#Example:_the_natural_numbers)

#### [Example: Proof procedure](https://en.wikipedia.org/wiki/Recursion#Example:_Proof_procedure)



### [Functional recursion](https://en.wikipedia.org/wiki/Recursion#Functional_recursion)

递归函数

A [function](https://en.wikipedia.org/wiki/Function_(mathematics)) may be recursively defined in terms of itself. A familiar example is the [Fibonacci number](https://en.wikipedia.org/wiki/Fibonacci_number) sequence: *F*(*n*) = *F*(*n* − 1) + *F*(*n* − 2). For such a definition to be useful, it must be reducible to non-recursively defined values: in this case *F*(0) = 0 and *F*(1) = 1.

A famous recursive function is the [Ackermann function](https://en.wikipedia.org/wiki/Ackermann_function), which, unlike the Fibonacci sequence, cannot be expressed without recursion.



### Finite subdivision rules

Main article: [Finite subdivision rule](https://en.wikipedia.org/wiki/Finite_subdivision_rule)



### The recursion theorem

 递归定理

In [set theory](https://en.wikipedia.org/wiki/Set_theory), this is a theorem guaranteeing that recursively defined functions exist. Given a set *X*, an element *a* of *X* and a function $ f:X\rightarrow X $, the theorem states that there is a unique function $ F:\mathbb {N} \rightarrow X $ (where $ \mathbb {N} $ denotes the set of natural numbers including zero) such that

$ F(0)=a $

$ F(n+1)=f(F(n)) $

for any natural number *n*.

> NOTE: 并没有搞懂



## In computer science

参见工程文章 `Recursion-in-computer-science\Recursion(computer-science).md`。




