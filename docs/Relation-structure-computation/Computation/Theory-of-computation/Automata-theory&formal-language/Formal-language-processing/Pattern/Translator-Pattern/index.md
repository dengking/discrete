# Translator Pattern

在阅读 wiki.c2 [External Polymorphism](https://proxy.c2.com/cgi/fullSearch?search=ExternalPolymorphism) 时，其中提及了[Translator Pattern](https://proxy.c2.com/cgi/fullSearch?search=TranslatorPattern)，看了一下，它让我想到了composition pattern、interpreter pattern。

## wiki.c2 [Translator Pattern](https://proxy.c2.com/cgi/fullSearch?search=TranslatorPattern)

*This is an attempt to present [ThomasKuehne](https://wiki.c2.com/?ThomasKuehne)'s Translator pattern in a simplified form. You can get the real version from: http://homepages.mcs.vuw.ac.nz/~tk/publications/papers/translator.pdf*



See [FunctionalPatternSystemForObjectOrientedDesign](https://wiki.c2.com/?FunctionalPatternSystemForObjectOrientedDesign)

### 问题描述

Often objects are organized into complex data structures such as trees or graphs in order to represent a system of relationships between the objects. Many times one of these structures will be useful in more than one context. For instance an abstract syntax tree would be useful in either a compiler or a pretty printer. In these cases the behavior of the structure and its components is extrinsic(非固有的、外在的) rather than intrinsic(固有的、本质的). That is to say that the behavior of each object in the structure has more to do with how the object is viewed by the **context** than with the nature of the object itself. When this situation occurs the symptoms(症状) include: 

1、relationships and behaviors that are correct for one context but not for another, 

2、polymorphic methods on the nodes that serve only a narrow subset of clients, overly complex traversal mechanisms that are intrusive or that require excessive book keeping. 

Ordinarily it is impossible to remedy(纠正、补救) this problem without violating the [OpenClosedPrinciple](https://wiki.c2.com/?OpenClosedPrinciple) because the definition of each object must change in response to its use in a new context.

> NOTE: 
>
> 一、概括来说，问题就是:
>
> 1、"the behavior of the structure and its components is extrinsic(非固有的、外在的) rather than intrinsic"，即"behavior of the structure"是由它的context决定的，而不是由它本身决定的，这就是 "extrinsic VS intrinsic"
>
> 2、"Ordinarily it is impossible to remedy(纠正、补救) this problem without violating the [OpenClosedPrinciple](https://wiki.c2.com/?OpenClosedPrinciple) because the definition of each object must change in response to its use in a new context."，让我想到了expression problem。

### 解决方案: translation 

**Therefore:**

Define a recursive traversal of the structure starting from some root node. Define a [GenericFunction](https://wiki.c2.com/?GenericFunction) that takes a node of the structure as a parameter and recursively translates that node, all of its sub-nodes and all of the edges between them to an equivalent structure in the new context. A one to one correspondence between the elements of the original structure and elements in the resulting structure need not be maintained, but the translation must be localized to each node and be composable (i.e. a node should be able to implement its translation in terms of translations on its sub-nodes.) Implement the elements in the resulting structure so that the system of relationships that it contains is capable of supplying the desired services. Finally, perform the desired operation by traversing the new structure and calling the appropriate method(s) on each node.

> NOTE: 
>
> 1、解决方案其实说起来是比较简单的: **translate** to a new、equivalent structure in the new context，然后在这个new structure上执行computation，这就是 "Translator Pattern" 中 Translator 的含义
>
> 2、它让我想起来 [Data, context and interaction](https://en.wikipedia.org/wiki/Data,_context_and_interaction#Execution_model)

**Resulting context:**

#### Advantages

This two-part process has several advantages.

1、Most importantly, the original structure and it's elements need not change. The use of [ExternalPolymorphism](https://wiki.c2.com/?ExternalPolymorphism) (via the [GenericFunction](https://wiki.c2.com/?GenericFunction)) requires only that the dynamic type of an object be obtainable at run-time. This advantage makes this approach desirable in situations where the [VisitorPattern](https://wiki.c2.com/?VisitorPattern) (which solves the same problem) is difficult or impossible to implement.

2、The elements of the generated structure can be customized to the specific task. The elements of the new structure can be of completely new types (indeed this is desirable) and the relationships between them can be modified in ways that suit the new context even if they would be inappropriate for the old one so long as there is a two-way mapping between the two structures.

3、Since the new structure is separate from the original its elements can be altered by the operation without harming the clients of the original.

4、The use of [HomomorphicMapping](https://wiki.c2.com/?HomomorphicMapping) makes it possible to update the second structure and the results of operations on it in response to changes in the original structure.

5、There is no dependence of the original structure on any part of the implementation of the new operation.

6、The use of  [ExternalPolymorphism](https://wiki.c2.com/?ExternalPolymorphism) makes it easy to add new functions as needed without disturbing existing classes.

#### Disadvantages

There are of course disadvantages:

1、[GenericFunction](https://wiki.c2.com/?GenericFunction)s are difficult to setup and maintain without direct language support.

2、As with all functional patterns for object oriented programming this approach is not idiomatic and will not be recognised or appreciated by most OO practitioners. This is not an OO approach -- it is a functional approach designed to allow multi-paradigm programming in an OO environment.

3、The use of  [ExternalPolymorphism](https://wiki.c2.com/?ExternalPolymorphism) makes it difficult to add new classes because all of the relevant functions will have to be updated.

*Objection: wouldn't a dispatch table allow one to work around this?* [AnswerMe](https://wiki.c2.com/?AnswerMe)

> NOTE: 异议



There may be an answer in the detailed discussion in the thesis. See [ObjectFunctionalImplementation](https://wiki.c2.com/?ObjectFunctionalImplementation) for discussion of attempts to implement the ideas. -- [JohnFletcher](https://wiki.c2.com/?JohnFletcher)



Compare with: [VisitorPattern](https://wiki.c2.com/?VisitorPattern)

## stackoverflow [Translator Pattern](https://stackoverflow.com/questions/1949708/translator-pattern)