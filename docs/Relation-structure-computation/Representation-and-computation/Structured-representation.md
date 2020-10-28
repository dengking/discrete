# 结构化表示

上一节使用**结构化思维**来看待**数学表达式**了，我觉得**计算机科学**是需要这种思维的，只有**结构化**了之后，计算机才能够对其进行**表示**（representation）、进而进行**计算**（computation）；这里所说的**结构化**如果往更高层面来思考的话，其实是：**形式化**，只有**形式化**后才能够使用计算机算法来进行计算，或者更加通俗地来说：**结构化**是**形式化**的一种。

各种各样的问题，如果要使用computer来进行解决，一个非常重要的课题就是：如何来表示？在应用计算机科学中，寻找合适的representation，对于解决问题至关重要(在computer science中，representation是一个非常核心的问题)。

在上一章提出的**结构化思维**，能够帮助我们理解、创造适合于问题的representation。

**结构化表示**是一种**计算机语言**，结构化表示后，才能够进行**computation**。

## Examples

不同的领域有着各自的representation。

### [Linguistics](https://en.wikipedia.org/wiki/Linguistics)

在语言学中使用[Grammar](https://en.wikipedia.org/wiki/Grammar)、[Syntax](https://en.wikipedia.org/wiki/Syntax)来表示语言的结构，最最典型的就是[Phrase structure grammar](https://en.wikipedia.org/wiki/Parsing_of_natural_language)。

regular language是linear structure，context free language是hierarchy 结构。因为regular language的grammar，即regular grammar无法表达containing关系。

典型的例子就是compile principle中，广泛地使用tree、graph来，对于语言这种看似非常灵活的、无规律的东西，进行**形式化**的描述，这让programming language称为了可能。



### Computer algebra

产生式、函数表达式（expression）都是数学**语言**，它们描述了**关系**。

在computer science中，我们知道，graph也可以用来描述**关系**。

在计算机科学中，我们应该使用discrete relation来分析事物，从而对它们进行描述、计算：

- 产生式可以使用tree structure来表示，tree 是一种 graph
- 函数表达式可以使用computation graph来表示



### Entity-relation model

使用Entity-relation model来描述现实世界，从后使用table来进行存储。

### Representation of word

参见工程machine-learning的`Application\NLP\Representation-of-word`章节 。



## draft: 结构化表示

使用computational graph来表示expression，使用tree来表示formal language。它们都是使用计算机能够接受的language来描述事物的典型例子，它们都是一种language。计算机能够接受的语言：structure。所以，结构化方式，即使用结构化的语言进行描述是解决计算问题的第一步。这需要和结构化思维一起。