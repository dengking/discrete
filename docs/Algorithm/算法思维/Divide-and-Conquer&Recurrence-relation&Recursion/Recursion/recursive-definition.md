
# Recursive definition

软件工程师，对于definition(定义)这个词肯定不会陌生，因为我们每天都在“定义一个函数”、“定义一个类”。wikipedia [definition](https://en.wikipedia.org/wiki/Definition)内容比较深奥，简单地来说definition(定义)就是在前文中所提及的“描述”(description)，不过定义有着更多限制。本文重点简述的是[recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)，在计算机科学中，[recursion](https://en.wikipedia.org/wiki/Recursion)无处不在，软件工程师应该对它保持敏感，对于所有具备[recursion](https://en.wikipedia.org/wiki/Recursion)特性的（包括类型、过程等），都能够给出其[Recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)。

## wikipedia [Recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)

In [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), a **recursive definition**, or **inductive definition**（归纳定义）, is used to define the [elements](https://en.wikipedia.org/wiki/Element_(mathematics)) in a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) in terms of other elements in the set ([Aczel](https://en.wikipedia.org/wiki/Peter_Aczel) 1977:740ff). Some examples of **recursively-definable objects** include [factorials](https://en.wikipedia.org/wiki/Factorial), [natural numbers](https://en.wikipedia.org/wiki/Natural_number), [Fibonacci numbers](https://en.wikipedia.org/wiki/Fibonacci_number), and the [Cantor ternary set](https://en.wikipedia.org/wiki/Cantor_set).

> NOTE: 上述对recursive definition的描述使用的是数学中的set的概念，数学中的set表示所有具备某一特性的object的集合，比如我们可以将所有具备相同type的object放到一个set中。下面我将它转换为software engineer更加熟悉的type（类型）的概念：
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

$$ 
0! = 1 \\
(n + 1)! = (n + 1) \cdot n! 
$$

> NOTE: 
>
> 原文中给出了两种**recursive definition**：recursively defined functions and recursive defined objects

#### [Form of recursive definitions](https://en.wikipedia.org/wiki/Recursive_definition#Form_of_recursive_definitions)

Most recursive definitions have two foundations: a base case (basis) and an **inductive clause**.

> NOTE: “inductive clause”的含义是“归纳子句”，关于“inductive ”，参见"Induction"。

The difference between a [circular definition](https://en.wikipedia.org/wiki/Circular_definition "Circular definition") and a **recursive definition** is that a **recursive definition** must always have _base cases_, cases that satisfy the definition _without_ being defined in terms of the definition itself, and that all other instances in the inductive clauses must be "smaller" in some sense (i.e., _closer_ to those base cases that terminate the recursion) — a rule also known as "recur only with a simpler case".


### 总结

按照原文第一段中对recursive definition的描述，发现其实它非常类似于induction（归纳法），我们知道，induction是bottom-up的，尤其是[natural numbers](https://en.wikipedia.org/wiki/Natural_number)的例子。而我对recursion的惯常印象是它是top-down。这两者不是矛盾吗？

“recursive definition”是一种描述方式，它不涉及实现的问题，它的描述可以是类似induction的自底向上，也可以是自顶向下，正如原文第一段所述的：[recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)也可以叫做**inductive definition**。“recursive definition”本质在于“ defined in terms of itself or of its type ”，正如本文第一段所描述的：

> In [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), a **recursive definition**, or **inductive definition**（归纳定义）, is used to define the [elements](https://en.wikipedia.org/wiki/Element_(mathematics)) in a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) in terms of other elements in the set


## Examples

### Recursive grammar
关于“recursive definition”的一个例子就是 [recursive grammar](https://en.wikipedia.org/wiki/Recursive_grammar)，比如在维基百科[Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))的[Recursive data types](https://en.wikipedia.org/wiki/Recursion_(computer_science)#Recursive_data_types)段中给出了这样的一个例子：

```
 <expr> ::= <number>
          | (<expr> * <expr>)
          | (<expr> + <expr>)
```

可以看到，`<expr>`的定义中就包含了"itself"。

“我对recursion的惯常印象是它是top-down”是源于我是从recursion function的角度来看待的。显然，这是描述与实现的差异。在原文的[Form of recursive definitions](https://en.wikipedia.org/wiki/Recursive_definition#Form_of_recursive_definitions)中给出了recursive definition所对应的function，显然对于这个function的实现，我们可以采用的实现方式有两种：

- 自底向上
- 自顶向下

### Linked-list
链表的标准定义（Lisp / Haskell 风格）：
```Lisp
List → Nil | Cons(value, List)
```
改写成文法形式：
```EBNF
list → value list | ε （右递归，自身在右边）
```
#### 为什么linked-list的文法形式只能是右递归
`ε` 不能和 value相连构成list

### Recursive definition and [closure](https://en.wikipedia.org/wiki/Closure_(mathematics)) 

按照recursively defined sets的概念，这个set在构造新元素的operation下是closed的（参见 [Closure (mathematics)](https://en.wikipedia.org/wiki/Closure_(mathematics)) ）。



### Recursive definition and structure

[Recursive data types](https://en.wikipedia.org/wiki/Recursive_data_type)中专门描述可以使用recursive definition的structure，这在"Data-structure"章节中会进行讨论。

可以使用recursive definition进行定义的structure，都具备递归特性。 