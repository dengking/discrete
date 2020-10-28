# Representation and computation

在应用计算机科学中，寻找合适的representation，对于解决问题至关重要。

> NOTE: 下面是应用计算机科学的一些领域：
>
> - Computational [linguistics](https://en.wikipedia.org/wiki/Linguistics) 计算语言学
> - Computer algebra 计算代数
> - ...

在上一章提出的**结构化思维**，能够帮助我们理解、创造适合于问题的representation。


结构化表示是一种计算机语言，结构化表示后，才能够进行computation。

## Examples

不同的领域有着各自的representation，



### [Linguistics](https://en.wikipedia.org/wiki/Linguistics)

在语言学中使用[Grammar](https://en.wikipedia.org/wiki/Grammar)、[Syntax](https://en.wikipedia.org/wiki/Syntax)来表示语言的结构，最最典型的就是[Phrase structure grammar](https://en.wikipedia.org/wiki/Parsing_of_natural_language)。

regular language是linear structure，context free language是hierarchy 结构。因为regular language的grammar，即regular grammar无法表达containing关系

典型的例子就是compile principle中，广泛地使用tree、graph来，对于语言这种看似非常灵活的、无规律的东西，进行**形式化**的描述，这让programming language称为了可能



### Computer algebra



产生式、函数表达式（expression）都是数学**语言**，它们描述了**关系**。

在computer science中，我们知道，graph也可以用来描述**关系**。

在计算机科学中，我们应该使用discrete relation来分析事物，从而对它们进行描述、计算：

- 产生式可以使用tree structure来表示，tree 是一种 graph
- 函数表达式可以使用computation graph来表示



### Entity-relation model

使用Entity-relation model来描述现实世界，从后使用table来进行存储。



## draft



各种各样的问题，如果要使用computer来进行解决，那么一个非常重要的课题就是：如何来表示？显然这是各种data structure派上用场的时候了。

在computer science中，representation是一个非常核心的问题：

representation of words：D:\github\dengking\AI\machine-learning\docs\Application\NLP\Representation-of-word

computation graph也是一种representation

representation of image

- iterator是一种非常强大的抽象的描述方式，可以抽象地描述container、stream


- 使用更加抽象的语言

典型的例子就是iterator、range


- 对于同一个结构，可以使用不同的语言来进行描述

典型的例子就是对于MLP，可以使用graph、math expression来进行描述

素材：

结构化思维：

在文章：如何直观地解释 backpropagation 算法？ - Anonymous的回答 - 知乎

https://www.zhihu.com/question/27239198/answer/89853077 中有如下描述：

多层神经网络本质上是一个多层复合函数，数学是一门简洁但是含义丰富的原因，简单的公式，但是能够表达强大的结构