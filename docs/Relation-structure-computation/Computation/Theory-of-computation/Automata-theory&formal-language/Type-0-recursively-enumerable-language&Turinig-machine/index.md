# Recursively enumerable language&Turing machine

---

> References:
>
> - cam.ac.uk [What is a Turing machine?](https://www.cl.cam.ac.uk/projects/raspberrypi/tutorials/turing-machine/one.html)
> - euston96 [Turing machine](https://www.euston96.com/en/turing-machine/)
> - wikipedia [Turing machine](https://en.wikipedia.org/wiki/Turing_machine) 

---

wikipedia [Turing machine](https://en.wikipedia.org/wiki/Turing_machine)的介绍非常冗长，初读起来会比较费劲，所以找了一些其他的相对精简一些的文章，可以按照上述顺序阅读。



## wikipedia [Turing machine](https://en.wikipedia.org/wiki/Turing_machine)

A **Turing machine** is a [mathematical model of computation](https://en.wikipedia.org/wiki/Mathematical_model_of_computation) that defines an [abstract machine](https://en.wikipedia.org/wiki/Abstract_machine), which manipulates **symbols** on a strip of tape according to a **table of rules**. Despite the model's simplicity, given any [computer algorithm](https://en.wikipedia.org/wiki/Computer_algorithm), a Turing machine capable of simulating that algorithm's logic can be constructed.

The machine operates on an **infinite memory tape** divided into [discrete](https://en.wikipedia.org/wiki/Discrete_mathematics) "cells". The machine positions its "head" over a cell and "reads" or "scans" the symbol there. Then, as per the symbol and its present place in a "finite table" of user-specified instructions, the machine (i) writes a symbol (e.g., a digit or a letter from a finite alphabet) in the cell (some models allow symbol erasure or no writing), then (ii) either moves the **tape** one cell left or right (some models allow no motion, some models move the head), then (iii) (as determined by the observed symbol and the machine's place in the table) either proceeds to a subsequent instruction or halts the computation.

> NOTE: 上面这段话已经总结了Turing machine的组成和运行机制

The Turing machine was invented in 1936 by [Alan Turing](https://en.wikipedia.org/wiki/Alan_Turing). With this model, Turing was able to answer two questions in the negative: 

(1) Does a machine exist that can determine whether any arbitrary machine on its tape is "circular" (e.g., freezes, or fails to continue its computational task)

(2) does a machine exist that can determine whether any arbitrary machine on its tape ever prints a given symbol

> Note: 上面两句中，that引导的定从是修饰machine的

Thus by providing a mathematical description of a very simple device capable of arbitrary computations, he was able to prove properties of computation in general—and in particular, the [uncomputability](https://en.wikipedia.org/wiki/Computability) of the *[Entscheidungsproblem](https://en.wikipedia.org/wiki/Entscheidungsproblem)* ('decision problem').

> NOTE: 关于Turing提及的两个问题，并没有搞清楚这些问题到底是什么。

Thus, Turing machines prove **fundamental limitations** on the power of **mechanical computation**. While they can express arbitrary computations, their minimalist design makes them unsuitable for computation in practice: real-world [computers](https://en.wikipedia.org/wiki/Computer) are based on different designs that, unlike Turing machines, use [random-access memory](https://en.wikipedia.org/wiki/Random-access_memory).

> NOTE: 上面的一段话其实说明了Turing machine的价值所在：理论上证明 **mechanical computation**的限制所在，这对于通用计算机的诞生是具有非常重要的意义的。

> NOTE: 需要注意的是，虽然real-world [computers](https://en.wikipedia.org/wiki/Computer) 没有采纳Turing machine的设计，但是Turing machine启发了real-world [computers](https://en.wikipedia.org/wiki/Computer) 的设计。一个real-world [computers](https://en.wikipedia.org/wiki/Computer) ，应该能够提供和Turing machine相同的 power of **mechanical computation**。关于Turing machine和现代computer之间的关联，可以参看下面的overview章节，当然在学习计算机组成原理的时候，还是会讨论Turing machine和[Von Neumann architecture](https://en.wikipedia.org/wiki/Von_Neumann_architecture)、 [stored-program computer](https://en.wikipedia.org/wiki/Stored-program_computer)。
>
> 除此之外，Turing machine theory of computation



[Turing completeness](https://en.wikipedia.org/wiki/Turing_completeness) is the ability for a system of instructions to simulate a Turing machine. A programming language that is Turing complete is theoretically capable of expressing all tasks accomplishable by computers; nearly all programming languages are Turing complete if the limitations of finite memory are ignored.

![Automata theory.svg](https://upload.wikimedia.org/wikipedia/commons/thumb/a/a2/Automata_theory.svg/300px-Automata_theory.svg.png)

> Classes of automata



## wikipedia [Recursively enumerable language](https://en.wikipedia.org/wiki/Recursively_enumerable_language) 



### [Unrestricted grammar](https://en.wikipedia.org/wiki/Unrestricted_grammar)

In [automata theory](https://en.wikipedia.org/wiki/Automata_theory), the class of **unrestricted grammars** (also called **semi-Thue**, **type-0** or **phrase structure grammars**) is the most general class of grammars in the [Chomsky hierarchy](https://en.wikipedia.org/wiki/Chomsky_hierarchy). No restrictions are made on the productions of an unrestricted grammar, other than each of their left-hand sides being non-empty. This grammar class can generate arbitrary [recursively enumerable languages](https://en.wikipedia.org/wiki/Recursively_enumerable_language).

### Formal definition

An **unrestricted grammar** is a [formal grammar](https://en.wikipedia.org/wiki/Formal_grammar) $ G=(N,\Sigma ,P,S) $, where $ N $ is a set of nonterminal symbols, $ \Sigma $ is a set of [terminal symbols](https://en.wikipedia.org/wiki/Terminal_symbol), $ N $ and $ \Sigma $ are disjoint,  $ P $ is a set of [production rules](https://en.wikipedia.org/wiki/Production_(computer_science)) of the form $ \alpha \to \beta $ where $ \alpha $ and $ \beta $ are strings of symbols in $ N\cup \Sigma $ and $ \alpha $ is not the empty string, and $ S\in N $ is a specially designated start symbol. As the name implies, there are no real restrictions on the types of production rules that unrestricted grammars can have.

### [Semi-Thue system](https://en.wikipedia.org/wiki/Semi-Thue_system)

In [theoretical computer science](https://en.wikipedia.org/wiki/Theoretical_computer_science) and [mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic) a **string rewriting system** (**SRS**), historically called a **semi-[Thue](https://en.wikipedia.org/wiki/Axel_Thue) system**, is a [rewriting](https://en.wikipedia.org/wiki/Rewriting) system over [strings](https://en.wikipedia.org/wiki/String_(computer_science)) from a (usually [finite](https://en.wikipedia.org/wiki/Finite_set)) [alphabet](https://en.wikipedia.org/wiki/Alphabet_(computer_science)). Given a [binary relation](https://en.wikipedia.org/wiki/Binary_relation) $ R $ between fixed strings over the alphabet, called **rewrite rules**, denoted by $ s\rightarrow t $, an SRS extends the rewriting relation to all strings in which the left- and right-hand side of the rules appear as [substrings](https://en.wikipedia.org/wiki/Substring), that is $ usv\rightarrow utv $, where $ s $, $ t $, $ u $, and $ v $ are strings.

