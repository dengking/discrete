# wikipedia [Turing machine](https://en.wikipedia.org/wiki/Turing_machine)

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

## Overview

A Turing machine is a general example of a [central processing unit](https://en.wikipedia.org/wiki/Central_processing_unit) (CPU) that controls all data manipulation done by a computer, with the canonical machine using sequential memory to store data. More specifically, it is a machine ([automaton](https://en.wikipedia.org/wiki/Automaton)) capable of [enumerating](https://en.wikipedia.org/wiki/Enumeration) some arbitrary subset of valid strings of an [alphabet](https://en.wikipedia.org/wiki/Alphabet_(formal_languages)); these strings are part of a [recursively enumerable set](https://en.wikipedia.org/wiki/Recursively_enumerable_set). A Turing machine has a tape of infinite length on which it can perform read and write operations.

Assuming a [black box](https://en.wikipedia.org/wiki/Black_box), the Turing machine cannot know whether it will eventually enumerate any one specific string of the subset with a given program. This is due to the fact that the [halting problem](https://en.wikipedia.org/wiki/Halting_problem) is unsolvable, which has major implications for the theoretical limits of computing.

The Turing machine is capable of processing an [unrestricted grammar](https://en.wikipedia.org/wiki/Unrestricted_grammar), which further implies that it is capable of robustly evaluating first-order logic in an infinite number of ways. This is famously demonstrated through [lambda calculus](https://en.wikipedia.org/wiki/Lambda_calculus).

A Turing machine that is able to simulate any other Turing machine is called a [universal Turing machine](https://en.wikipedia.org/wiki/Universal_Turing_machine) (UTM, or simply a universal machine). A more mathematically oriented definition with a similar "universal" nature was introduced by [Alonzo Church](https://en.wikipedia.org/wiki/Alonzo_Church), whose work on lambda calculus intertwined with Turing's in a formal theory of [computation](https://en.wikipedia.org/wiki/Computation) known as the [Church–Turing thesis](https://en.wikipedia.org/wiki/Church–Turing_thesis). The thesis states that Turing machines indeed capture the informal notion of [effective methods](https://en.wikipedia.org/wiki/Effective_method) in [logic](https://en.wikipedia.org/wiki/Logic) and [mathematics](https://en.wikipedia.org/wiki/Mathematics), and provide a precise definition of an [algorithm](https://en.wikipedia.org/wiki/Algorithm) or "mechanical procedure". Studying their [abstract properties](https://en.wikipedia.org/wiki/Abstract_machine) yields many insights into [computer science](https://en.wikipedia.org/wiki/Computer_science) and [complexity theory](https://en.wikipedia.org/wiki/Computational_complexity_theory).

> NOTE:  [lambda calculus](https://en.wikipedia.org/wiki/Lambda_calculus) 不理解

## visualizations of Turing machines

see [Turing machine gallery](https://en.wikipedia.org/wiki/Turing_machine_gallery).



## Description

