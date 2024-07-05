# Formal and formal language

Formal在computer science中有着非常重要的地位，计算机科学家门围绕着它创建了很多理论。

## Formal

所以我们需要首先搞清楚它的含义。下面我们先通过一些例子来认识formal，然后再来进行总结。

### Examples of formal 

#### example 1

[Deep Learning](http://www.deeplearningbook.org/front_matter.pdf)的Chapter 1 Introduction的如下描述：

> In the early days of artificial intelligence, the field rapidly tackled and solved problems that are intellectually difficult for human beings but relatively straightforward for computers—problems that can be described by a list of **formal**, mathematical rules. The true challenge to artificial intelligence proved to be solving the tasks that are easy for people to perform but hard for people to describe
> **formally**—problems that we solve **intuitively**, that feel automatic, like recognizing spoken words or faces in images.

可以使用“formal， mathematical rules“描述的问题，具备着固定的rule，所以使用computer program是非常任意实现的。而与它相反的一类问题，是无法使用rule进行描述的，这类问题，在上面这段话中使用”intuitive“来表示，解决这类问题的方法是AI。

#### example 2

[Deep Learning](http://www.deeplearningbook.org/front_matter.pdf)的Chapter 5.1 Learning Algorithms的如下描述：

>  “A computer program is said to learn from experience `E` with respect to some class of tasks `T` and performance measure `P` , if its performance at tasks in `T` , as measured by `P` , improves with experience `E` .” One can imagine a very wide variety of experiences `E` , tasks `T` , and performance measures `P` , and we do not make any attempt in this book to provide a **formal definition** of what may be used for each of these entities. Instead, the following sections provide **intuitive descriptions** and examples of the different kinds of tasks, performance measures and experiences that can be used to construct machine learning algorithms.

formal language-》 formal definition

natural language-》intuitive description

#### examples

Examples of formal description

https://dictionary.cambridge.org/example/english/formal-description

> In this section and the next, we turn our attention to providing a more formal description of the underlying type system.



## 什么是formal？

关于formal的直觉是：

- 有固定的规则

### 从词源说起

https://simple.wikipedia.org/wiki/Formal

> **Formal** is a word used to describe anything that has form or [structure](https://simple.wikipedia.org/wiki/Structure). So it is something which is used or done in accordance with [rules](https://simple.wikipedia.org/wiki/Rule) or [ceremonies](https://simple.wikipedia.org/wiki/Ceremony).

上面这句中的form其实就可以理解为rule。

> In [mathematics](https://simple.wikipedia.org/wiki/Mathematics), formal [logic](https://simple.wikipedia.org/wiki/Logic) is a way of thinking about mathematics questions using strict rules.



https://www.yourdictionary.com/formal



### 维基百科formal汇总

我们需要重点关注三个科学学科：

[Linguistics](https://en.wikipedia.org/wiki/Formal#Linguistics)、[Logic and mathematics](https://en.wikipedia.org/wiki/Formal#Logic_and_mathematics)、[Computer science](https://en.wikipedia.org/wiki/Formal#Computer_science)

这三个学科中的formal是密切相关的。

## Formalism 

文章[Formalism (philosophy)](https://en.wikipedia.org/wiki/Formalism_(philosophy)), [Formalism (philosophy of mathematics)](https://en.wikipedia.org/wiki/Formalism_(philosophy_of_mathematics))将formal描述为一种科学的思想，显然它从更高的哲学的角度来概括formal，我觉得以它作为掌握formal的入口是非常好的，因为科学总数遵循相同的哲学思想，或者说哲学指导着科学。

## Formal language

显然，这个词由formal来进行修饰，所以它肯定是具备前面所描述的formal的性质的：即有固定规则，就[formal language](https://en.wikipedia.org/wiki/Formal_language)而言，它的formal是源于它的[grammar](https://en.wikipedia.org/wiki/Grammar)上，它的语法是[formal grammar](https://en.wikipedia.org/wiki/Formal_grammar)，这种语法的规则是固定的。所以对于这种语言，只要向computer描述清楚它的grammar，那么computer就可以“读懂”它，即这种语言是machine-readable的。

关于formal language的machine readable，可以参见：https://en.wikipedia.org/wiki/Semantic_Web

## Formal definition

使用formal language来描述的definition就是formal definition。



## Formal language的优势

Formal language的优势在于它的formal，即有固定的rule。在逻辑学，rule对于的是推导规则，所以formal language是可以进行推导。





## 思考：Formal与人工智能

deep learning book的chapter one