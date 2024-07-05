# 关于本章

在阅读automata theory的时候，发现原来它是theory of computation的一个分支，所以此处就将theory of computation一并给整理了一下。

首先描述 [theory of computation](https://en.wikipedia.org/wiki/Theory_of_computation)，然后描述 [model of computation](https://en.wikipedia.org/wiki/Model_of_computation)，然后描述它的各个branch（共三个，这三个branch是software engineer经常会接触到的）。因为[model of computation](https://en.wikipedia.org/wiki/Model_of_computation)在三个branch中都会使用到，所以把它放到前面来进行描述。

## wikipedia [Theory of computation](https://en.wikipedia.org/wiki/Theory_of_computation)

In [theoretical computer science](https://en.wikipedia.org/wiki/Theoretical_computer_science) and [mathematics](https://en.wikipedia.org/wiki/Mathematics), the **theory of computation** is the branch that deals with how efficiently problems can be solved on a [model of computation](https://en.wikipedia.org/wiki/Model_of_computation), using an [algorithm](https://en.wikipedia.org/wiki/Algorithm). The field is divided into three major branches: 

- [automata theory](https://en.wikipedia.org/wiki/Automata_theory) and [formal languages](https://en.wikipedia.org/wiki/Formal_language)
- [computability theory](https://en.wikipedia.org/wiki/Computability_theory)
- [computational complexity theory](https://en.wikipedia.org/wiki/Computational_complexity_theory), 

which are linked by the question: *"What are the fundamental capabilities and limitations of computers?".*

In order to perform a rigorous study of computation, computer scientists work with a **mathematical abstraction** of computers called a [model of computation](https://en.wikipedia.org/wiki/Model_of_computation). There are several models in use, but the most commonly examined is the [Turing machine](https://en.wikipedia.org/wiki/Turing_machine). Computer scientists study the Turing machine because it is simple to formulate, can be analyzed and used to prove results, and because it represents what many consider the most powerful possible "reasonable" model of computation (see [Church–Turing thesis](https://en.wikipedia.org/wiki/Church–Turing_thesis)). It might seem that the potentially infinite memory capacity is an unrealizable attribute, but any [decidable](https://en.wikipedia.org/wiki/Decidability_(logic)) problem solved by a Turing machine will always require only a finite amount of memory. So in principle, any problem that can be solved (decided) by a Turing machine can be solved by a computer that has a finite amount of memory.