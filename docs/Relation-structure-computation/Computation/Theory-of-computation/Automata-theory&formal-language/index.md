# 关于本章

本章节，首先描述上面是"formal"，引出[Formal language](https://en.wikipedia.org/wiki/Formal_language)， 然后对它进行详细的分析。维基百科的[Formal language](https://en.wikipedia.org/wiki/Formal_language)内容是非常好的（全面，深入浅出），需要仔细阅读。

首先说明formal language，formal grammar，automata，Chomsky hierarchy等基本概念，建立理论框架。

然后按照Chomsky hierarchy的每一层进行说明，对Chomsky hierarchy的每一层的说明采用如下顺序，即：

- Type-3 grammars: [Regular grammar](https://en.wikipedia.org/wiki/Regular_grammar)
- Type-2 grammars: [Context-free grammar](https://en.wikipedia.org/wiki/Context-free_grammar)
- Type-1 grammars: [Context-sensitive grammar](https://en.wikipedia.org/wiki/Context-sensitive_grammar)
- Type-0 grammars: [Unrestricted grammar](https://en.wikipedia.org/wiki/Unrestricted_grammar)

这是因为从Type-3 grammars到Type-0 grammars，grammar越来越抽象，越来越难理解，这样由易到难会比较符合认知规律。

在了解了这些之后，我们不能够仅仅局限于此，而是应该走向更加宽广的理论：[Theory of computation](https://en.wikipedia.org/wiki/Theory_of_computation)，因为按照2012 [ACM Computing Classification System](https://en.wikipedia.org/wiki/ACM_Computing_Classification_System)，前面所讨论的[formal language](https://en.wikipedia.org/wiki/Formal_language)，[automata theory](https://en.wikipedia.org/wiki/Automata_theory)都属于此范轴。

理论往往不是孤立的，而是相互关联，相互借用的，相互启发的，在阅读[Formal language](https://en.wikipedia.org/wiki/Formal_language)时，你会发现作者对它进行了大量的发散，涉及到的学科有[mathematics](https://en.wikipedia.org/wiki/Mathematics)（尤其是 [Mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic)）, [computer science](https://en.wikipedia.org/wiki/Computer_science), and [linguistics](https://en.wikipedia.org/wiki/Linguistics)。所以，在阅读的时候，就有必要梳理清楚概念之间的关系，抓住问题的本质，而不是被表面的描述识所扰乱。



## 学习计划--从入门到精通

[Formal language](https://en.wikipedia.org/wiki/Formal_language)所涉及的理论较多，并且大多数都是比较抽象的，刚开始学习（尤其对于缺乏使用programming language的人来说）可能会感觉比较吃力，以下是觉得比较好的学习计划：

首先搞清楚what is language、what is formal language、what is formal grammar、what is automata、What is the relationship between them，这样就建立起了建立起高屋建瓴的视野，这其实就是算入门了。推荐阅读下面的文章：

- [Formal Languages, Grammars, and Automata](http://www.sti.uniurb.it/aldini/publications/lfga.pdf)

入门了之后，就需要建立起theory framework，最终我们会发现，使用[Chomsky hierarchy](https://en.wikipedia.org/wiki/Chomsky_hierarchy)就能够将整个理论给统一起来；然后再逐个进行细致分析，最后就能够融会贯通，这其实就是精通了。



## [Formal language](https://en.wikipedia.org/wiki/Formal_language)

提及[formal language](https://en.wikipedia.org/wiki/Formal_language)，就得请出[Noam Chomsky](https://en.wikipedia.org/wiki/Noam_Chomsky)，因为下面的理论框架是由他所建立的，该theory framework的是按照[Chomsky hierarchy](https://en.wikipedia.org/wiki/Chomsky_hierarchy)来进行组织的：

| [Chomsky hierarchy](https://en.wikipedia.org/wiki/Chomsky_hierarchy) | [Grammars](https://en.wikipedia.org/wiki/Formal_grammar)     | Languages                                                    | [Abstract machines](https://en.wikipedia.org/wiki/Abstract_machine) |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| Type-0                                                       | [Unrestricted](https://en.wikipedia.org/wiki/Unrestricted_grammar) | [Recursively enumerable](https://en.wikipedia.org/wiki/Recursively_enumerable_language) | [Turing machine](https://en.wikipedia.org/wiki/Turing_machine) |
| —                                                            | (no common name)                                             | [Decidable](https://en.wikipedia.org/wiki/Recursive_language) | [Decider](https://en.wikipedia.org/wiki/Machine_that_always_halts) |
| Type-1                                                       | [Context-sensitive](https://en.wikipedia.org/wiki/Context-sensitive_grammar) | [Context-sensitive](https://en.wikipedia.org/wiki/Context-sensitive_language) | [Linear-bounded](https://en.wikipedia.org/wiki/Linear_bounded_automaton) |
| —                                                            | Positive [range concatenation](https://en.wikipedia.org/wiki/Range_concatenation_grammars) | Positive [range concatenation](https://en.wikipedia.org/wiki/Range_concatenation_language)* | [PTIME](https://en.wikipedia.org/wiki/PTIME) Turing Machine  |
| —                                                            | [Indexed](https://en.wikipedia.org/wiki/Indexed_grammar)     | [Indexed](https://en.wikipedia.org/wiki/Indexed_language)*   | [Nested stack](https://en.wikipedia.org/wiki/Nested_stack_automaton) |
| —                                                            | —                                                            | —                                                            | [Thread automaton](https://en.wikipedia.org/wiki/Thread_automaton) |
| —                                                            | [Linear context-free rewriting systems](https://en.wikipedia.org/wiki/Linear_context-free_rewriting_system) | [Linear context-free rewriting language](https://en.wikipedia.org/wiki/Linear_context-free_rewriting_language) | restricted [Tree stack automaton](https://en.wikipedia.org/wiki/Tree_stack_automaton) |
| —                                                            | [Tree-adjoining](https://en.wikipedia.org/wiki/Tree-adjoining_grammar) | [Tree-adjoining](https://en.wikipedia.org/wiki/Tree-adjoining_grammar) | [Embedded pushdown](https://en.wikipedia.org/wiki/Embedded_pushdown_automaton) |
| Type-2                                                       | [Context-free](https://en.wikipedia.org/wiki/Context-free_grammar) | [Context-free](https://en.wikipedia.org/wiki/Context-free_language) | [Nondeterministic pushdown](https://en.wikipedia.org/wiki/Pushdown_automaton) |
| —                                                            | [Deterministic context-free](https://en.wikipedia.org/wiki/Deterministic_context-free_grammar) | [Deterministic context-free](https://en.wikipedia.org/wiki/Deterministic_context-free_language) | [Deterministic pushdown](https://en.wikipedia.org/wiki/Deterministic_pushdown_automaton) |
| —                                                            | [Visibly pushdown](https://en.wikipedia.org/wiki/Nested_word) | [Visibly pushdown](https://en.wikipedia.org/wiki/Nested_word) | [Visibly pushdown](https://en.wikipedia.org/wiki/Nested_word) |
| Type-3                                                       | [Regular](https://en.wikipedia.org/wiki/Regular_grammar)     | [Regular](https://en.wikipedia.org/wiki/Regular_language)    | [Finite](https://en.wikipedia.org/wiki/Finite-state_machine) |
| —                                                            | —                                                            | [Star-free](https://en.wikipedia.org/wiki/Star-free_language) | [Counter-free (with aperiodic finite monoid)](https://en.wikipedia.org/wiki/Aperiodic_finite_state_automaton) |
| —                                                            | [Non-recursive](https://en.wikipedia.org/wiki/Non-recursive_grammar) | [Finite](https://en.wikipedia.org/wiki/Finite_language)      | [Acyclic finite](https://en.wikipedia.org/wiki/Deterministic_acyclic_finite_state_automaton) |

Each category of languages, except those marked by a `*`, is a [proper subset](https://en.wikipedia.org/wiki/Proper_subset) of the category directly above it. Any language in each category is generated by a grammar and by an automaton in the category in the same line.

### Expressive power

Type-3->Type-2->Type-1->Type-0

Linear structure->hierarchy structure->graph->...

relation越来越复杂，structure越来越复杂；

Expressive power逐渐增强；



## 入门读物

入门读物推荐：

- [Formal Languages, Grammars, and Automata](http://www.sti.uniurb.it/aldini/publications/lfga.pdf)

除此之外，推荐阅读如下巨著：

- [Introduction to Automata and Language Theory(aka ***Cinderella Book***)](http://infolab.stanford.edu/~ullman/ialc.html)

### Cinderella Book VS Dragon Book

[Introduction to Automata and Language Theory(aka ***Cinderella Book***)](http://infolab.stanford.edu/~ullman/ialc.html)是该领域的经典书籍。

[Introduction to Automata and Language Theory(aka ***Cinderella Book***)](http://infolab.stanford.edu/~ullman/ialc.html)和[Compilers: Principles, Techniques, and Tools (aka "***Dragon Book***")](http://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools)中的内容其实是紧密关联的，这不仅仅是因为Jeffrey D.Ullman参与了这两本书的编写，而是因为programming language是一种formal language，而Cinderella Book和Dragon Book其实都是在讲述和formal language相关的内容，当然，这些内容仅仅书中的一部分。Cinderella Book专注于讲述automata and language theory，而dragon book的内容则可以分为两个部分front end和back end，显然front end所讲述的内容就和automata and language theory紧密相关了。

## 参考

本项目的内容大多数来自:

- 维基百科: [Automata theory](https://en.wikipedia.org/wiki/Automata_theory) : [formal languages](https://en.wikipedia.org/wiki/Formal_language) **and** [formal grammars](https://en.wikipedia.org/wiki/Formal_grammar)
- [Introduction to Automata and Language Theory(aka ***Cinderella Book***)](http://infolab.stanford.edu/~ullman/ialc.html)

