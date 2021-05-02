# Examples of tree structures

在上一篇中，我们已经知道，具备nesting关系的结构都可以表示成tree structure，本文对计算机科学中的tree structure进行枚举。

## [Directory structure](https://en.wikipedia.org/wiki/Directory_structure) ([directory](https://en.wikipedia.org/wiki/Directory_(computing)))

目录是典型的可用使用tree来进行描述的，它满足nesting关系。

See also: 

[Tree (command)](https://en.wikipedia.org/wiki/Tree_(command))

[Path (computing)](https://en.wikipedia.org/wiki/Path_(computing))

## [Process tree](https://en.wikipedia.org/wiki/Pstree)

parent-children关系。

## [File format](https://en.wikipedia.org/wiki/File_format)

nesting关系。

1、[Document Object Model](https://en.wikipedia.org/wiki/Document_Object_Model)（[XML](https://en.wikipedia.org/wiki/XML)）

2、[json](https://en.wikipedia.org/wiki/JSON)

3、[yaml](https://en.wikipedia.org/wiki/YAML)

## [Namespace](https://en.wikipedia.org/wiki/Namespace)

nesting关系。

Namespace的应用场景实在太多，在维基百科的[Namespace](https://en.wikipedia.org/wiki/Namespace)对它总结地非常好。在对它进行思考的时候，发觉使用namespace来组织的数据最终就是hierarchy结构。其实也可以简单地将namespace看做是括号。

## Expression

[binary expression tree](https://en.wikipedia.org/wiki/Binary_expression_tree)

## Source code

[Parse tree](https://en.wikipedia.org/wiki/Parse_tree)、[Abstract syntax tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree)。

nesting关系。

## Activation tree

nesting关系。

函数的调用过程也是可以使用tree来进行描述的，参见:

1、[Compilers Principles, Techniques and Tools Second Edition(aka ***dragon book***)](https://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools) 的[7.2.1 Activation Trees](https://dengking.github.io/compiler-principle/Chapter-7-Run-Time-Environments/7.2-Stack-Allocation-of-Space/#721-activation-trees)。

2、`Function-recursion-tree-stack` 章节


### Recursion activation tree

递归函数的调用过程也是可以使用tree来进行描述的

#### Divide and conquer

[Divide-and-conquer algorithm](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm)是典型的递归算法



## Linguistics

在语言学中，基本上是使用tree来描述语言的结构。

If you have read book describing the **compiler technology**, for example the classic definitive book [Compilers: Principles, Techniques, and Tools](https://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools) by Alfred V. Aho, Monica S. Lam, Ravi Sethi, and Jeffrey D. Ullman, you will be aware how important the tree structure is to the compiler. As described in chapter 2.2.3 Parse Trees:

> Tree data structures figure prominently in compiling.

There are some many tree in the book, such as [Parse tree](https://en.wikipedia.org/wiki/Parse_tree), [abstract syntax tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree), activation tree(in chapter 7.2.1 Activation Trees), [expression tree](https://en.wikipedia.org/wiki/Binary_expression_tree).

Essentially Speaking, a **programming language** is a [formal language](https://en.wikipedia.org/wiki/Formal_language), what have been concluded in article structure is that 

>  Tree can be used to describe the structure of [sentences](https://en.wikipedia.org/wiki/Sentence_(linguistics)) that is  [syntax](https://en.wikipedia.org/wiki/Syntax) and  [formal grammar](https://en.wikipedia.org/wiki/Formal_grammar) can be convert to [tree](https://en.wikipedia.org/wiki/Tree_(data_structure)).

So it's natural to use trees in the compiling.

[Regular expression](https://en.wikipedia.org/wiki/Regular_expression), [algebraic expression](https://en.wikipedia.org/wiki/Algebraic_expression) can be described using  [formal grammar](https://en.wikipedia.org/wiki/Formal_grammar), so given an expression, it can be converted to an equivalent  [parse tree](https://en.wikipedia.org/wiki/Parse_tree).



### Expression

[binary expression tree](https://en.wikipedia.org/wiki/Binary_expression_tree)

### Source code

[Abstract syntax tree](https://en.wikipedia.org/wiki/Abstract_syntax_tree)使用一棵树表达了源代码的语法结构

## Nesting结构的一些例子

[Nested function](https://en.wikipedia.org/wiki/Nested_function)

[Scope (computer science)](https://en.wikipedia.org/wiki/Scope_(computer_science))

与nesting紧密相关的词有：

- enclosing（参见下面的enclosing function）、[Closure (computer programming)](https://en.wikipedia.org/wiki/Closure_(computer_programming))
- [block](https://en.wikipedia.org/wiki/Block_(programming))

[Nested function](https://en.wikipedia.org/wiki/Nested_function) and [enclosing function](https://en.wikipedia.org/wiki/Nested_function)



## Counting problems can be solved using tree diagrams

在[Discrete Mathematics and Its Applications](https://dengking.github.io/discrete-math/Book-Discrete-Mathematics-and-Its-Applications/)的[6.1 The Basics of Counting](https://dengking.github.io/discrete-math/Book-Discrete-Mathematics-and-Its-Applications/Chapter-6-Counting/#61-the-basics-of-counting)中使用tree diagram来描述**Counting problems**，这是一种典型的逻辑结构（并非肉眼可见的树结构）。