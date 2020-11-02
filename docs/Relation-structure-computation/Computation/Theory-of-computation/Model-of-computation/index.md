# [Model of computation](https://en.wikipedia.org/wiki/Model_of_computation)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), and more specifically in [computability theory](https://en.wikipedia.org/wiki/Computability_theory_(computer_science)) and [computational complexity theory](https://en.wikipedia.org/wiki/Computational_complexity_theory), a **model of computation** is a model which describes how an output of a [mathematical function](https://en.wikipedia.org/wiki/Function_(mathematics)) is computed given an input. A model describes how units of computations, memories, and communications are organized. The [computational complexity](https://en.wikipedia.org/wiki/Computational_complexity) of an [algorithm](https://en.wikipedia.org/wiki/Algorithm) can be measured given a model of computation. Using a model allows studying the performance of algorithms independently of the variations that are specific to particular [implementations](https://en.wikipedia.org/wiki/Implementation) and specific technology.

## Models

Models of computation can be classified in three categories: sequential models, functional models, and concurrent models.

Sequential models include:

- [Finite state machines](https://en.wikipedia.org/wiki/Finite_state_machine)
- [Pushdown automata](https://en.wikipedia.org/wiki/Pushdown_automata)
- [Turing machine](https://en.wikipedia.org/wiki/Turing_machine)

Functional models include:

- [Lambda calculus](https://en.wikipedia.org/wiki/Lambda_calculus)
- [Recursive functions](https://en.wikipedia.org/wiki/Μ-recursive_function)
- [Combinatory logic](https://en.wikipedia.org/wiki/Combinatory_logic)
- [Abstract rewriting systems](https://en.wikipedia.org/wiki/Abstract_rewriting_system)

Concurrent models include:

- [Cellular automaton](https://en.wikipedia.org/wiki/Cellular_automaton)
- [Kahn process networks](https://en.wikipedia.org/wiki/Kahn_process_networks)
- [Petri nets](https://en.wikipedia.org/wiki/Petri_nets)
- [Synchronous Data Flow](https://en.wikipedia.org/wiki/Synchronous_Data_Flow)
- [Interaction nets](https://en.wikipedia.org/wiki/Interaction_nets)
- [Actor model](https://en.wikipedia.org/wiki/Actor_model)

Models differ in their **expressive power**; for example, each function that can be computed by a *Finite state machine* can also be computed by a *Turing machine*, but not vice versa.

## Categories

There are many models of computation, differing in the set of admissible operations and their computations cost. They fall into the following broad categories:

- [Abstract machine](https://en.wikipedia.org/wiki/Abstract_machine) and models equivalent to it (e.g. [lambda calculus](https://en.wikipedia.org/wiki/Lambda_calculus) is equivalent to the [Turing machine](https://en.wikipedia.org/wiki/Turing_machine)) - used in proofs of computability and upper bounds on **computational complexity of algorithms**.
- [Decision tree models](https://en.wikipedia.org/wiki/Decision_tree_model) - used in proofs of lower bounds on computational complexity of algorithmic problems.