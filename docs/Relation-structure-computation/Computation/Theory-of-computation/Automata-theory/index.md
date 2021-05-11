



# wikipedia [Automata theory](https://en.wikipedia.org/wiki/Automata_theory)

> TIPS: In Chinese, [Automata theory](https://en.wikipedia.org/wiki/Automata_theory) means 自动机理论.

**Automata theory** is the study of [abstract machines](https://en.wikipedia.org/wiki/Abstract_machine) and [automata](https://en.wikipedia.org/wiki/Automaton), as well as the [computational problems](https://en.wikipedia.org/wiki/Computational_problem) that can be solved using them. It is a theory in [theoretical computer science](https://en.wikipedia.org/wiki/Theoretical_computer_science) and [discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics) (a subject of study in both [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science)). The word *automata* (the plural of *automaton*) comes from the Greek word αὐτόματα, which means "self-making".

The figure at right illustrates a [finite-state machine](https://en.wikipedia.org/wiki/Finite-state_machine), which belongs to a well-known type of automaton. This automaton（自动机） consists of [states](https://en.wikipedia.org/wiki/State_(computer_science)) (represented in the figure by circles) and transitions (represented by arrows). As the automaton sees a symbol of input, it makes a transition (or jump) to another state, according to its [transition function](https://en.wikipedia.org/wiki/Transition_system), which takes the current state and the recent symbol as its inputs.

**Automata theory** is closely related to [formal language](https://en.wikipedia.org/wiki/Formal_language) theory. An automaton is a **finite representation** of a formal language that may be an **infinite set**. **Automata** are often classified by the class of **formal languages** they can recognize, typically illustrated by the [Chomsky hierarchy](https://en.wikipedia.org/wiki/Chomsky_hierarchy), which describes the relations between various languages and kinds of formalized logics.

> TIPS: It is obvious that automata theory is an important tool for research formal language.

Automata play a major role in [theory of computation](https://en.wikipedia.org/wiki/Theory_of_computation), [compiler construction](https://en.wikipedia.org/wiki/Compiler_construction)（编译器的构建）, [artificial intelligence](https://en.wikipedia.org/wiki/Artificial_intelligence), [parsing](https://en.wikipedia.org/wiki/Parsing) and [formal verification](https://en.wikipedia.org/wiki/Formal_verification).

Classes of automata:

- [Turing machine](https://en.wikipedia.org/wiki/Turing_machine)
  - [Pushdown automaton](https://en.wikipedia.org/wiki/Pushdown_automaton)
    - [Finite-state machine](https://en.wikipedia.org/wiki/Finite-state_machine)
      - [Combinational logic](https://en.wikipedia.org/wiki/Combinational_logic)



[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9d/DFAexample.svg/300px-DFAexample.svg.png)](https://en.wikipedia.org/wiki/File:DFAexample.svg)

The study of the mathematical properties of such automata is automata theory. The picture is a visualization of an automaton that recognizes strings containing an even number of *0*s. The automaton starts in state *S1*, and transitions to the non-accepting state *S2* upon reading the symbol *0*. Reading another *0* causes the automaton to transition back to the accepting state *S1*. In both states the symbol *1* is ignored by making a transition to the current state. 

> TIPS: The diagram above is called a [state diagram](https://en.wikipedia.org/wiki/State_diagram).

## Automata

Following is an introductory definition of one type of automaton, which attempts to help one grasp the essential concepts involved in automata theory/theories. 

### Informal description

An automaton *runs* when it is given some sequence of *inputs* in discrete (individual) *time steps* or steps. 

An automaton processes **one input** picked from a set of *[symbols](https://en.wikipedia.org/wiki/Symbol_(formal))* or *letters*, which is called an *[alphabet](https://en.wikipedia.org/wiki/Alphabet_(computer_science))*. 

The symbols received by the automaton as input at any step are a finite sequence of symbols called *words*. 

An automaton has a finite set of *states*. At each moment during a run of the automaton, the automaton is *in* one of its states. When the automaton receives new input it moves to another state (or transitions) based on a **function** that takes the **current state** and **symbol** as parameters. This function is called the *transition function*. 

The automaton reads the symbols of the input word one after another and transitions from state to state according to the **transition function** until the word is read completely. Once the input word has been read, the automaton is said to have stopped. The state at which the automaton stops is called the *final state*. 

Depending on the **final state**, it's said that the automaton either *accepts* or *rejects* an input word. There is a subset of states of the automaton, which is defined as the set of *accepting states*. If the **final state** is an **accepting state**, then the automaton *accepts* the word. Otherwise, the word is *rejected*. The set of all the words accepted by an automaton is called the *[language](https://en.wikipedia.org/wiki/Formal_language) recognized by the automaton*.



In short, an automaton is a [mathematical object](https://en.wikipedia.org/wiki/Mathematical_object) that takes a word as input and decides whether to accept it or reject it. Since all computational problems are reducible into the accept/reject question on inputs, (all problem instances can be represented in a finite length of symbols), automata theory plays a crucial role in [computational theory](https://en.wikipedia.org/wiki/Computational_theory).

> TIPS: In formal language, automata act as recognizer or matcher consuming **characters** or **tokens**. The graph above is a good example of automaton. Automata can be used not only in formal language,  it has many application in computer science, such as:
>
> - [Event-driven finite-state machine](https://en.wikipedia.org/wiki/Event-driven_finite-state_machine)
> - [State machine replication](https://en.wikipedia.org/wiki/State_machine_replication)
>
> In these applications, what automaton consume can be event. See [Finite-state machine](https://en.wikipedia.org/wiki/Finite-state_machine#Software_applications) for more detail.

### Formal definition

 **Automaton** 





## Classes of automata

 The following is an incomplete list of types of automata. 

|                          Automaton                           |                    Recognizable language                     |
| :----------------------------------------------------------: | :----------------------------------------------------------: |
| [Nondeterministic/Deterministic Finite state machine](https://en.wikipedia.org/wiki/Finite_state_machine) (FSM) | [regular languages](https://en.wikipedia.org/wiki/Regular_language) |
| [Deterministic pushdown automaton](https://en.wikipedia.org/wiki/Deterministic_pushdown_automaton) (DPDA) | [deterministic context-free languages](https://en.wikipedia.org/wiki/Deterministic_context-free_language) |
| [Pushdown automaton](https://en.wikipedia.org/wiki/Pushdown_automaton) (PDA) | [context-free languages](https://en.wikipedia.org/wiki/Context-free_language) |
| [Linear bounded automaton](https://en.wikipedia.org/wiki/Linear_bounded_automaton) (LBA) | [context-sensitive languages](https://en.wikipedia.org/wiki/Context-sensitive_language) |
| [Turing machine](https://en.wikipedia.org/wiki/Turing_machine) | [recursively enumerable languages](https://en.wikipedia.org/wiki/Recursively_enumerable_language) |
| Deterministic [Büchi automaton](https://en.wikipedia.org/wiki/Büchi_automaton) | [ω-limit languages](https://en.wikipedia.org/wiki/Omega_language#Operations) |
|               Nondeterministic Büchi automaton               | [ω-regular languages](https://en.wikipedia.org/wiki/Omega-regular_language) |
| [Rabin automaton](https://en.wikipedia.org/wiki/Rabin_automaton), [Streett automaton](https://en.wikipedia.org/wiki/Streett_automaton), [Parity automaton](https://en.wikipedia.org/wiki/Parity_automaton), [Muller automaton](https://en.wikipedia.org/wiki/Muller_automaton) |                                                              |

### Discrete, continuous, and hybrid automata

 Normally automata theory describes the states of abstract machines but there are [analog automata](https://en.wikipedia.org/wiki/Analog_automata) or [continuous automata](https://en.wikipedia.org/w/index.php?title=Continuous_automata&action=edit&redlink=1) or [hybrid discrete-continuous automata](https://en.wikipedia.org/wiki/Hybrid_automaton), which use analog data, continuous time, or both. 

## Hierarchy in terms of powers

 The following is an incomplete hierarchy in terms of powers of different types of virtual machines. The hierarchy reflects the nested categories of languages the machines are able to accept.[[1\]](https://en.wikipedia.org/wiki/Automata_theory#cite_note-Aaniya_B-1) 

|                          Automaton                           |
| :----------------------------------------------------------: |
| [Deterministic Finite Automaton](https://en.wikipedia.org/wiki/Deterministic_Finite_Automaton) (DFA) -- Lowest Power <br/>(same power)   $ || $  (same power)<br/> [Nondeterministic Finite Automaton](https://en.wikipedia.org/wiki/Nondeterministic_Finite_Automaton) (NFA) (above is weaker)   $ \cap $  (below is stronger) <br/>[Deterministic Push Down Automaton](https://en.wikipedia.org/wiki/Deterministic_pushdown_automaton) (DPDA-I) <br/>with 1 push-down store<br/> $ \cap $ <br/>[Nondeterministic Push Down Automaton](https://en.wikipedia.org/w/index.php?title=Nondeterministic_Push_Down_Automaton&action=edit&redlink=1) (NPDA-I) <br/>with 1 push-down store<br/> $ \cap $ <br/>[Linear Bounded Automaton](https://en.wikipedia.org/wiki/Linear_bounded_automaton) (LBA) <br/>$ \cap $ <br/>[Deterministic Push Down Automaton](https://en.wikipedia.org/wiki/Deterministic_pushdown_automaton) (DPDA-II) <br/>with 2 push-down stores<br/> $ || $ <br/>[Nondeterministic Push Down Automaton](https://en.wikipedia.org/w/index.php?title=Nondeterministic_Push_Down_Automaton&action=edit&redlink=1) (NPDA-II) <br/>with 2 push-down stores<br/> $ || $ <br/>[Deterministic Turing Machine](https://en.wikipedia.org/wiki/Deterministic_Turing_machine) (DTM)<br/> $ || $ <br/>[Nondeterministic Turing Machine](https://en.wikipedia.org/wiki/Nondeterministic_Turing_machine) (NTM) $ || $ [<br/>Probabilistic Turing Machine](https://en.wikipedia.org/wiki/Probabilistic_Turing_machine) (PTM)<br/> $ || $ <br/>[Multitape Turing Machine](https://en.wikipedia.org/wiki/Multitape_Turing_machine) (MTM) $ || $ [Mu<br/>ltidimensional Turing Machine](https://en.wikipedia.org/wiki/Turing_machine_equivalents#Other_equivalent_machines_and_methods) |

## Applications

Each model in automata theory plays important roles in several applied areas. [Finite automata](https://en.wikipedia.org/wiki/Finite_automata) are used in text processing, compilers, and hardware design. [Context-free grammar](https://en.wikipedia.org/wiki/Context-free_grammar) (CFGs) are used in programming languages and artificial intelligence. Originally, CFGs were used in the study of the human languages. [Cellular automata](https://en.wikipedia.org/wiki/Cellular_automata) are used in the field of biology, the most common example being [John Conway](https://en.wikipedia.org/wiki/John_Horton_Conway)'s [Game of Life](https://en.wikipedia.org/wiki/Conway's_Game_of_Life). Some other examples which could be explained using automata theory in biology include mollusk and pine cones growth and pigmentation patterns. Going further, a theory suggesting that the whole universe is computed by some sort of a discrete automaton, is advocated by some scientists. The idea originated in the work of [Konrad Zuse](https://en.wikipedia.org/wiki/Konrad_Zuse), and was popularized in America by [Edward Fredkin](https://en.wikipedia.org/wiki/Edward_Fredkin). Automata also appear in the theory of finite fields: the set of irreducible polynomials which can be written as composition of degree two polynomials is in fact a regular language.[[2\]](https://en.wikipedia.org/wiki/Automata_theory#cite_note-2) 

## Automata simulators

Automata simulators are pedagogical tools used to teach, learn and research automata theory. An automata simulator takes as input the description of an automaton and then simulates its working for an arbitrary input string. The description of the automaton can be entered in several ways. An automaton can be defined in a [symbolic language](https://en.wikipedia.org/wiki/Symbolic_language_(programming)) or its specification may be entered in a predesigned form or its transition diagram may be drawn by clicking and dragging the mouse. Well known automata simulators include Turing's World, JFLAP, VAS, TAGS and SimStudio.[[3\]](https://en.wikipedia.org/wiki/Automata_theory#cite_note-3) 

