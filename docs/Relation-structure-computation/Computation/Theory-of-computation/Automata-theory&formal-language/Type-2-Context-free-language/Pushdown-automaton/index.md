# Pushdown automaton

中文翻译做: "下推自动机"

---

> References: 
>
> [zhihu-[笔记]下推自动机](https://zhuanlan.zhihu.com/p/669440520) (通俗易懂)
>
> [baike-下推自动机](https://baike.baidu.com/item/%E4%B8%8B%E6%8E%A8%E8%87%AA%E5%8A%A8%E6%9C%BA/10988477?fr=ge_ala) 

---



## wikipedia [Pushdown automaton](https://en.wikipedia.org/wiki/Pushdown_automaton)

In the [theory of computation](https://en.wikipedia.org/wiki/Theory_of_computation), a branch of [theoretical computer science](https://en.wikipedia.org/wiki/Theoretical_computer_science), a **pushdown automaton** (**PDA**) is a type of [automaton](https://en.wikipedia.org/wiki/Automata_theory) that employs a [stack](https://en.wikipedia.org/wiki/Stack_(data_structure)).

**Pushdown automata** are used in theories about what can be computed by machines. They are more capable than [finite-state machines](https://en.wikipedia.org/wiki/Finite-state_machine) but less capable than [Turing machines](https://en.wikipedia.org/wiki/Turing_machine). [Deterministic pushdown automata](https://en.wikipedia.org/wiki/Deterministic_pushdown_automata) can recognize all [deterministic context-free languages](https://en.wikipedia.org/wiki/Deterministic_context-free_language) while nondeterministic ones can recognize all [context-free languages](https://en.wikipedia.org/wiki/Context-free_language), with the former often used in [parser](https://en.wikipedia.org/wiki/Parser) design.

The term "pushdown" refers to the fact that the [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) can be regarded as being "pushed down" like a tray dispenser at a cafeteria, since the operations never work on elements other than the top element. A **stack automaton**, by contrast, does allow access to and operations on deeper elements. Stack automata can recognize a strictly larger set of languages than pushdown automata.[[1\]](https://en.wikipedia.org/wiki/Pushdown_automaton#cite_note-Hopcroft.Ullman.1967-1) A [nested stack automaton](https://en.wikipedia.org/wiki/Nested_stack_automaton) allows full access, and also allows stacked values to be entire sub-stacks rather than just single finite symbols.

### Informal description

A [finite state machine](https://en.wikipedia.org/wiki/Finite_state_machine) just looks at the **input signal** and the **current state**: it has no stack to work with. It chooses a new state, the result of following the transition. A **pushdown automaton (PDA)** differs from a finite state machine in two ways:

1. It can use the top of the stack to decide which transition to take.
2. It can manipulate the stack as part of performing a transition.

A **pushdown automaton** reads a given input string from left to right. In each step, it chooses a transition by indexing a table by input symbol, current state, and the symbol at the top of the stack. A pushdown automaton can also manipulate the stack, as part of performing a transition. The manipulation can be to push a particular symbol to the top of the stack, or to pop off the top of the stack. The automaton can alternatively ignore the stack, and leave it as it is.

Put together: Given an input symbol, current state, and stack symbol, the automaton can follow a transition to another state, and optionally manipulate (push or pop) the stack.

> NOTE: In fact, without concrete example,  the above description is very difficult to understand. A LL parser is a typical **pushdown automaton**, the Wikipedia entry [LL parser](https://en.wikipedia.org/wiki/LL_parse) give an concrete and concise [example](https://en.wikipedia.org/wiki/LL_parser#Concrete_example) to explain the mechanism of thee parser, that is **pushdown automaton**. After reading it, I think you will grasp what above paragraph describe.



[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/7/71/Pushdown-overview.svg/340px-Pushdown-overview.svg.png)](https://en.wikipedia.org/wiki/File:Pushdown-overview.svg)

> A diagram of a pushdown automaton



## wikipedia [Deterministic pushdown automaton](https://en.wikipedia.org/wiki/Deterministic_pushdown_automaton)

