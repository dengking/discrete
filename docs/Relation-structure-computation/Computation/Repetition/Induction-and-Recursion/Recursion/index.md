# Recursion

递归是一种优良的特性，在各个学科中都有着广泛的应用，它是一个重要的概念。在多个工程中都会涉及到递归，所以本章对递归定义及递归进行论述。本章先论述"Recursive-definition"，然后论述更加抽象的"Recursion"，因为前者相对而来说更加易于理解。有了这些认知，我们再来学习"Recursion in computer science"。



## Recursive definition

软件工程师，对于definition（定义）这个词肯定不会陌生，因为我们每天都在“定义一个函数”、“定义一个类”。wikipedia [definition](https://en.wikipedia.org/wiki/Definition)内容比较深奥，本文将简单地来说definition，定义就是在前文中所提及的“描述”(description)，不过定义有着更多限制。本文重点简述的是[Recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)，在计算机科学中，[recursion](https://en.wikipedia.org/wiki/Recursion)无处不在，软件工程师应该对它保持敏感，对于所有具备[recursion](https://en.wikipedia.org/wiki/Recursion)特性的（包括类型、过程等），都能够给出其[Recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)。

### wikipedia [Recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)

In [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), a **recursive definition**, or **inductive definition**（归纳定义）, is used to define the [elements](https://en.wikipedia.org/wiki/Element_(mathematics)) in a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) in terms of other elements in the set ([Aczel](https://en.wikipedia.org/wiki/Peter_Aczel) 1977:740ff). Some examples of **recursively-definable objects** include [factorials](https://en.wikipedia.org/wiki/Factorial), [natural numbers](https://en.wikipedia.org/wiki/Natural_number), [Fibonacci numbers](https://en.wikipedia.org/wiki/Fibonacci_number), and the [Cantor ternary set](https://en.wikipedia.org/wiki/Cantor_set).

> NOTE: 
>
> 一、上述对recursive definition的描述使用的是数学中的set的概念，数学中的set表示所有具备某一特性的object的集合，比如我们可以将所有具备相同type的object放到一个set中。下面我将它转换为software engineer更加熟悉的type（类型）的概念：
>
> 规定属于同一个set的所有元素都是具有相同类型的元素，则recursively-definable object是由相同类型的其他object（即这个集合中的其他元素）来进行定义的（构成）。
>
> 可以看到，当我们将set理解为type后，原来的描述就变成了software engineer非常容易理解的了。
>
> 上述定义是非常严谨的，使用了数学中的 [set](https://en.wikipedia.org/wiki/Set_(mathematics)) 的概念，可以认为它使用的是一种数学语言。在其他文章中都可以看到完全使用自然语言描述的recursive definition，比如：
>
> 在wikipedia [Recursion](https://en.wikipedia.org/wiki/Recursion)中：
>
> > **Recursion** (adjective: *recursive*) occurs when a thing is defined in terms of itself or of its type.
>
> 在wikipedia [Recursive acronym](https://en.wikipedia.org/wiki/Recursive_acronym)中：
>
> > A **recursive acronym** is an [acronym](https://en.wikipedia.org/wiki/Acronym) that [refers to itself](https://en.wikipedia.org/wiki/Recursion).
>
> 显然使用自然语言的描述是更加容易理解的。
>
> 如何理解recursively defined function？
>
> 显然，一个recursively defined function就是“ defined in terms of itself or of its type ”

A [recursive](https://en.wikipedia.org/wiki/Recursive) [definition](https://en.wikipedia.org/wiki/Definition) of a [function](https://en.wikipedia.org/wiki/Function_(mathematics)) defines values of the function for some inputs in terms of the values of the same function for other (usually smaller) inputs. For example, the [factorial](https://en.wikipedia.org/wiki/Factorial) function *n*! is defined by the rules

0! = 1.

(*n* + 1)! = (*n* + 1)·*n*!.

> NOTE: 
>
> 原文中给出了两种**recursive definition**：recursively defined functions and recursive defined objects

#### [Form of recursive definitions](https://en.wikipedia.org/wiki/Recursive_definition#Form_of_recursive_definitions)

Most recursive definitions have two foundations: a base case (basis) and an **inductive clause**.

> NOTE: 
>
> “inductive clause”的含义是“归纳子句”，关于“inductive ”，参见"Induction"。

That recursive definitions are valid – meaning that a recursive definition identifies a unique function – is a theorem of set theory known as the [recursion theorem](https://en.wikipedia.org/wiki/Recursion#The_recursion_theorem), the proof of which is non-trivial. Where the domain of the function is the **natural numbers**, sufficient conditions for the definition to be valid are that the value of `f(0)` (i.e., base case) is given, and that for n > 0, an algorithm is given for determining `f(n)` in terms of `f(0)`,`f(1)`, ... ,`f(n-1)` (i.e., inductive clause).

More generally, recursive definitions of functions can be made whenever the domain is a [well-ordered set](https://en.wikipedia.org/wiki/Well-order), using the principle of [transfinite recursion](https://en.wikipedia.org/wiki/Transfinite_recursion). The formal criteria for what constitutes a valid recursive definition are more complex for the general case.

> NOTE: 上面这段话并没有理解。

### 总结

按照原文第一段中对recursive definition的描述，发现其实它非常类似于induction（归纳法），我们知道，induction是bottom-up的，尤其是[natural numbers](https://en.wikipedia.org/wiki/Natural_number)的例子。而我对recursion的惯常印象是它是top-down。这两者不是矛盾吗？

“recursive definition”是一种描述方式，它不涉及实现的问题，它的描述可以是类似induction的自底向上，也可以是自顶向下，正如原文第一段所述的：[recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)也可以叫做**inductive definition**。“recursive definition”本质在于“ defined in terms of itself or of its type ”，正如本文第一段所描述的：

> In [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), a **recursive definition**, or **inductive definition**（归纳定义）, is used to define the [elements](https://en.wikipedia.org/wiki/Element_(mathematics)) in a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) in terms of other elements in the set

关于“recursive definition”的一个例子就是[Recursive grammar](https://en.wikipedia.org/wiki/Recursive_grammar)，比如在维基百科[Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))的[Recursive data types](https://en.wikipedia.org/wiki/Recursion_(computer_science)#Recursive_data_types)段中给出了这样的一个例子：

```
 <expr> ::= <number>
          | (<expr> * <expr>)
          | (<expr> + <expr>)
```

可以看到，`<expr>`的定义中就包含了"itself"。

“我对recursion的惯常印象是它是top-down”是源于我是从recursion function的角度来看待的。显然，这是描述与实现的差异。在原文的[Form of recursive definitions](https://en.wikipedia.org/wiki/Recursive_definition#Form_of_recursive_definitions)中给出了recursive definition所对应的function，显然对于这个function的实现，我们可以采用的实现方式有两种：

- 自底向上
- 自顶向下



### Recursive definition and [closure](https://en.wikipedia.org/wiki/Closure_(mathematics)) 

按照recursively defined sets的概念，这个set在构造新元素的operation下是closed的（参见 [Closure (mathematics)](https://en.wikipedia.org/wiki/Closure_(mathematics)) ）。



### Recursive definition and structure

[Recursive data types](https://en.wikipedia.org/wiki/Recursive_data_type)中专门描述可以使用recursive definition的structure，这在"Data-structure"章节中会进行讨论。

可以使用recursive definition进行定义的structure，都具备递归特性。 



## Recursion

本节描述Recursion，其实上一节"Recursive-definition"中的内容是更加容易理解的。

### wikipedia [Recursion](https://en.wikipedia.org/wiki/Recursion)

**Recursion** (adjective: *recursive*) occurs when a thing is defined in terms of **itself** or of its type. 

> NOTE: 其实上述定义就是的含义其实就是[recursive definition](./Recursive-definition.md)。在维基百科[Recursive acronym](https://en.wikipedia.org/wiki/Recursive_acronym)中使用 “refers to itself” 来表达这种含义。

Recursion is used in a variety of disciplines ranging from [linguistics](https://en.wikipedia.org/wiki/Linguistics) to [logic](https://en.wikipedia.org/wiki/Logic). The most common application of recursion is in [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), where a [function](https://en.wikipedia.org/wiki/Function_(mathematics)) being defined is applied within its own definition. While this apparently defines an infinite number of instances (function values), it is often done in such a way that no **loop** or **infinite chain** of references can occur.

> NOTE: 如果出现loop或者infinite chain，则程序就会出现死循环；

#### Formal definitions

In mathematics and computer science, a class of objects or methods exhibits **recursive behavior** when it can be defined by two properties:

1、A simple **base case** (or cases)—a **terminating scenario** that does not use **recursion** to produce an answer

2、A set of rules that **reduces**（这个词用得非常好） all other cases toward the **base case**

> NOTE: “reduce”说明recursion是自顶向下的。



The [Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence) is a classic example of recursion:

$ {\text{Fib}}(0)=0{\text{ as base case 1,}} $

$ {\text{Fib}}(1)=1{\text{ as base case 2,}} $

$ {\text{For all integers }}n>1,~{\text{ Fib}}(n):={\text{Fib}}(n-1)+{\text{Fib}}(n-2). $



Many mathematical axioms（公理） are based upon **recursive rules**. For example, the formal definition of the [natural numbers](https://en.wikipedia.org/wiki/Natural_number) by the [Peano axioms](https://en.wikipedia.org/wiki/Peano_axioms) can be described as: *0 is a natural number, and each natural number has a successor, which is also a natural number.* By this base case and recursive rule, one can generate the set of all natural numbers.

Recursively defined mathematical objects include [functions](https://en.wikipedia.org/wiki/Function_(mathematics)), [sets](https://en.wikipedia.org/wiki/Set_(mathematics)), and especially [fractals](https://en.wikipedia.org/wiki/Fractal).

> NOTE: 软件工程师应该对recursive definition敏感。

#### [In mathematics](https://en.wikipedia.org/wiki/Recursion#In_mathematics)



##### Recursively defined sets

> NOTE:
>
> 参见文章Recursive definition。

[Example: the natural numbers](https://en.wikipedia.org/wiki/Recursion#Example:_the_natural_numbers)

[Example: Proof procedure](https://en.wikipedia.org/wiki/Recursion#Example:_Proof_procedure)



#### [Functional recursion](https://en.wikipedia.org/wiki/Recursion#Functional_recursion)

> NOTE:
>
> 递归函数

A [function](https://en.wikipedia.org/wiki/Function_(mathematics)) may be recursively defined in terms of itself. A familiar example is the [Fibonacci number](https://en.wikipedia.org/wiki/Fibonacci_number) sequence: *F*(*n*) = *F*(*n* − 1) + *F*(*n* − 2). For such a definition to be useful, it must be reducible to non-recursively defined values: in this case *F*(0) = 0 and *F*(1) = 1.

A famous recursive function is the [Ackermann function](https://en.wikipedia.org/wiki/Ackermann_function), which, unlike the Fibonacci sequence, cannot be expressed without recursion.



#### Finite subdivision rules

Main article: [Finite subdivision rule](https://en.wikipedia.org/wiki/Finite_subdivision_rule)



#### The recursion theorem

> NOTE:
>
> "recursion theorem"的意思是"递归定理"

In [set theory](https://en.wikipedia.org/wiki/Set_theory), this is a theorem guaranteeing that recursively defined functions exist. Given a set *X*, an element *a* of *X* and a function $ f:X\rightarrow X $, the theorem states that there is a unique function $ F:\mathbb {N} \rightarrow X $ (where $ \mathbb {N} $ denotes the set of natural numbers including zero) such that

$ F(0)=a $

$ F(n+1)=f(F(n)) $

for any natural number *n*.

> NOTE: 并没有搞懂



#### In computer science

> NOTE:
>
> 参见 `Recursion-in-computer-science` 章节

## Double recursion



### wikipedia [Double recursion](https://en.wikipedia.org/wiki/Double_recursion)

In [recursive function theory](https://en.wikipedia.org/wiki/Recursive_function_theory), **double recursion** is an extension of [primitive recursion](https://en.wikipedia.org/wiki/Primitive_recursion) which allows the definition of non-primitive recursive functions like the [Ackermann function](https://en.wikipedia.org/wiki/Ackermann_function).


