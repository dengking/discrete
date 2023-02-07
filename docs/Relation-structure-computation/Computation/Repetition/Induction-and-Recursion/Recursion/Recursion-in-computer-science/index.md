# Recursion in computer science





## [Examples of recursive_definition in computer science](https://en.wikipedia.org/wiki/Recursive_definition#Examples_of_recursive_definitions)

有太多太多的算法、结构都是可以使用recursive definition的，能够recursive definition的，称它具备递归性。

### Recursive grammar

参见：

1、wikipedia [Recursive grammar](https://en.wikipedia.org/wiki/Recursive_grammar)

2、龙书[2.2.1 Definition of Grammars](https://dengking.github.io/compiler-principle/Chapter-2-A-Simple-Syntax-Directed-Translator/2.2-Syntax-Definition/#221-definition-of-grammars)



### Sub structure

一般带有“sub”的都是可以进行recursive definition的，它是一种典型的**containing关系**，它是可以使用CFG来进行描述的。下面是典型的sub structure：

1、subtree，sublist，在维基百科[Structural induction](https://en.wikipedia.org/wiki/Structural_induction)中所提及的：

> [recursively defined](https://en.wikipedia.org/wiki/Recursive_definition) structure, such as [formulas](https://en.wikipedia.org/wiki/First-order_logic#Formulas), [lists](https://en.wikipedia.org/wiki/List_(computer_science)), or [trees](https://en.wikipedia.org/wiki/Tree_(graph_theory))

下面是一些例子：

2、Subobjects（参见cppreference [Object#Subobjects](https://en.cppreference.com/w/cpp/language/object#Polymorphic_objects)）

3、wikipedia [Optimal substructure](https://en.wikipedia.org/wiki/Optimal_substructure) 



### Pointer of pointer

无论是在computer science还是在实际生活中，都存在着大量的类似于pointer of pointer的例子：

1、pointer of pointer

2、array of array（其实是一种sub structure，一个array可以看做是由多个sub array 组成）

3、mother of mother （家族hierarchy）

它们都是都是非常典型的recursion definition。下面对array of array即multiple-dimensional array进行说明。

**multiple-dimensional array**

在阅读 https://stackoverflow.com/a/4810676 时，其中有这样的描述：

>  Multidimensional arrays are often referred to as "arrays of arrays"

显然，这是典型的recursive definition。

与此类似的还有：multiple-level pointer。

multiple-dimensional array和multiple-level pointer可以看做是具备nesting关系（参见工程`data-structure`的`Graph\Tree\Tree-structure.md`章节）。

multiple-dimensional array和multiple-level pointer可以递归的进行处理，在文章 https://stackoverflow.com/a/5580952 中给出了示例程序。



素材:

[Recursion theory（Computability theory）](https://en.wikipedia.org/wiki/Computability_theory)

- [Recursive language](https://en.wikipedia.org/wiki/Recursive_language)

- [Recursive set](https://en.wikipedia.org/wiki/Recursive_set)
- [Recursively enumerable set](https://en.wikipedia.org/wiki/Recursively_enumerable_set)