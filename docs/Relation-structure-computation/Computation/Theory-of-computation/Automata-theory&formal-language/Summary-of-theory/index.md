# 梳理

## Generating VS parsing

我们已经知道[formal grammars](https://en.wikipedia.org/wiki/Formal_grammar)是[generative grammar](https://en.wikipedia.org/wiki/Generative_grammar)。

[Generative grammar](https://en.wikipedia.org/wiki/Generative_grammar)：

> generative grammar considers [grammar](https://en.wikipedia.org/wiki/Grammar) as a system of rules that generates exactly those combinations of words that form grammatical sentences in a given language

上述所描述的是generating过程，即给定grammar，**生成**sentence in a given language，这个过程其实是不断地使用grammar rule来进行推导的。

它的反问题是：给定sentence，判断它是否符合这个语言的grammar。这就是[parsing](https://en.wikipedia.org/wiki/Parsing)。

通过上面的分析可以看出，generating和[parsing](https://en.wikipedia.org/wiki/Parsing)互为反过程。





## 从[Mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic)的角度来看[Formal grammars](https://en.wikipedia.org/wiki/Formal_grammar)

如果从[Mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic)的逻辑推导的角度来看待[Formal grammars](https://en.wikipedia.org/wiki/Formal_grammar)的话，[formal grammars](https://en.wikipedia.org/wiki/Formal_grammar)的很多内容就变得非常容易理解：[formal grammars](https://en.wikipedia.org/wiki/Formal_grammar)可以看做是一个[formal system](https://en.wikipedia.org/wiki/Formal_system)。

下面总结了formal grammar中的一些概念和mathematical logic中的一些概念之间的对应关系，如下：

| [Formal grammar](https://en.wikipedia.org/wiki/Formal_grammar)的概念 | [Mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic)的概念 |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Production rule](https://en.wikipedia.org/wiki/Production_(computer_science)) | [Formation rule](https://en.wikipedia.org/wiki/Formation_rule)、[Rule of inference](https://en.wikipedia.org/wiki/Rule_of_inference)、[Rewriting](https://en.wikipedia.org/wiki/Rewriting) |

上述对应关系的含义是：如果从[Mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic)来看待[Production rule](https://en.wikipedia.org/wiki/Production_(computer_science))的话，它就相当于是[Formation rule](https://en.wikipedia.org/wiki/Formation_rule)、[Rule of inference](https://en.wikipedia.org/wiki/Rule_of_inference)、[Rewriting](https://en.wikipedia.org/wiki/Rewriting)。

按照公式进行推导从另外一个角度来看其实是重写，不断地进行替换，感觉数理逻辑本质上就是这个东西。从这个角度来看，parsing的过程其实就是不断的推导的过程，不断的重写的过程。由于可能的推导格式是非常多的，所以需要不断地进行尝试，这个过程其实就是[search](https://en.wikipedia.org/wiki/Search_algorithm)、[backtracking](https://en.wikipedia.org/wiki/Backtracking)，所以从这个角度来看，[parsing](https://en.wikipedia.org/wiki/Parsing)所做的工作其实就是推导加search。自顶向下其实所对应的是正向推导，自底向上其实所对应的就是方向推导。

> NOTE: 在龙书的4.2.3 Derivations有这样的描述：
>
> The construction of a parse tree can be made precise by taking a **derivational view**, in which productions are treated as **rewriting rules**. Beginning with the start symbol, each rewriting step replaces a nonterminal by the body of one of its productions. This derivational view corresponds to the top-down construction of a parse tree, but the precision afforded by derivations will be especially helpful when bottom-up parsing is discussed. As we shall see, bottom-up parsing is related to a class of derivations known as "rightmost" derivations, in which the rightmost nonterminal is rewritten at each step.

上面的这些内容给我的启发是：不同的学科对同一事物的命名可能不同，但是它们本质上所描述的是同一事物。

其实上述所有这些讨论，本质上都是属于[Logic](https://en.wikipedia.org/wiki/Logic)学的范轴，推导（[inference](https://en.wikipedia.org/wiki/Inference)）就属于逻辑学的范轴。



## [Formal system](https://en.wikipedia.org/wiki/Formal_system) and formal language

下面这段摘自[Formal systems](https://en.wikipedia.org/wiki/Formation_rule#Formal_systems)

> A *formal system* (also called a *logical calculus*, or a *logical system*) consists of a formal language together with a [deductive apparatus](https://en.wikipedia.org/wiki/Deductive_apparatus) (also called a *deductive system*). The deductive apparatus may consist of a set of [transformation rules](https://en.wikipedia.org/wiki/Transformation_rule) (also called *inference rules*) or a set of [axioms](https://en.wikipedia.org/wiki/Axiom), or have both. A formal system is used to [derive](https://en.wikipedia.org/wiki/Proof_theory)(推导) one expression from one or more other expressions. Propositional and predicate calculi are examples of formal systems.

[Formal grammars](https://en.wikipedia.org/wiki/Formal_grammar) 相当于 [deductive apparatus](https://en.wikipedia.org/wiki/Deductive_apparatus)。





## [Automata theory](https://en.wikipedia.org/wiki/Automata_theory)和[Formal language](https://en.wikipedia.org/wiki/Formal_language)

[Chomsky hierarchy](https://en.wikipedia.org/wiki/Chomsky_hierarchy)将[Automata theory](https://en.wikipedia.org/wiki/Automata_theory)和[formal language](https://en.wikipedia.org/wiki/Formal_language)进行了关联和对应。需要注意的是，[Automata theory](https://en.wikipedia.org/wiki/Automata_theory)在其他领域有着非常广泛的应用。



## [Turing machine](https://en.wikipedia.org/wiki/Turing_machine) and [Mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic)

在第一段的NOTE中就对两者进行了分析。

除此之外，下面文章也是值得阅读的：

- [Automated theorem proving](https://en.wikipedia.org/wiki/Automated_theorem_proving)
- [Formal methods](https://en.wikipedia.org/wiki/Formal_methods) 

