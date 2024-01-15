# Automata theory

---

> References: 
>
> - wikipedia [Automata theory](https://en.wikipedia.org/wiki/Automata_theory) 

---





## wikipedia [Abstract machine](https://en.wikipedia.org/wiki/Abstract_machine)

An **abstract machine**, also called an **abstract computer**, is a theoretical model of a [computer](https://en.wikipedia.org/wiki/Computer) hardware or software system used in [automata theory](https://en.wikipedia.org/wiki/Automata_theory). Abstraction of computing processes is used in both the [computer science](https://en.wikipedia.org/wiki/Computer_science) and [computer engineering](https://en.wikipedia.org/wiki/Computer_engineering) disciplines and usually assumes a [discrete time](https://en.wikipedia.org/wiki/Discrete_time) [paradigm](https://en.wikipedia.org/wiki/Paradigm).



## wikipedia [Automata theory](https://en.wikipedia.org/wiki/Automata_theory)

> TIPS: In Chinese, [Automata theory](https://en.wikipedia.org/wiki/Automata_theory) means 自动机理论.

**Automata theory** is the study of [abstract machines](https://en.wikipedia.org/wiki/Abstract_machine) and [automata](https://en.wikipedia.org/wiki/Automaton), as well as the [computational problems](https://en.wikipedia.org/wiki/Computational_problem) that can be solved using them. It is a theory in [theoretical computer science](https://en.wikipedia.org/wiki/Theoretical_computer_science) and [discrete mathematics](https://en.wikipedia.org/wiki/Discrete_mathematics) (a subject of study in both [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science)). The word *automata* (the plural of *automaton*) comes from the Greek word αὐτόματα, which means "self-making".

The figure at right illustrates a [finite-state machine](https://en.wikipedia.org/wiki/Finite-state_machine), which belongs to a well-known type of automaton. This automaton（自动机） consists of [states](https://en.wikipedia.org/wiki/State_(computer_science)) (represented in the figure by circles) and transitions (represented by arrows). As the automaton sees a symbol of input, it makes a transition (or jump) to another state, according to its [transition function](https://en.wikipedia.org/wiki/Transition_system), which takes the current state and the recent symbol as its inputs.

[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9d/DFAexample.svg/300px-DFAexample.svg.png)](https://en.wikipedia.org/wiki/File:DFAexample.svg)



**Automata theory** is closely related to [formal language](https://en.wikipedia.org/wiki/Formal_language) theory. An automaton is a **finite representation** of a formal language that may be an **infinite set**. **Automata** are often classified by the class of **formal languages** they can recognize, typically illustrated by the [Chomsky hierarchy](https://en.wikipedia.org/wiki/Chomsky_hierarchy), which describes the relations between various languages and kinds of formalized logics.

> TIPS: It is obvious that automata theory is an important tool for research formal language.

Automata play a major role in [theory of computation](https://en.wikipedia.org/wiki/Theory_of_computation), [compiler construction](https://en.wikipedia.org/wiki/Compiler_construction)（编译器的构建）, [artificial intelligence](https://en.wikipedia.org/wiki/Artificial_intelligence), [parsing](https://en.wikipedia.org/wiki/Parsing) and [formal verification](https://en.wikipedia.org/wiki/Formal_verification).

The study of the mathematical properties of such automata is automata theory. The picture is a visualization of an automaton that recognizes strings containing an even number of *0*s. The automaton starts in state *S1*, and transitions to the non-accepting state *S2* upon reading the symbol *0*. Reading another *0* causes the automaton to transition back to the accepting state *S1*. In both states the symbol *1* is ignored by making a transition to the current state. 

> TIPS: The diagram above is called a [state diagram](https://en.wikipedia.org/wiki/State_diagram).



## Applications

stack machine

queue machine

state machine



## Automata software

### Python

[python-statemachine](https://github.com/fgmacedo/python-statemachine)

[automata](https://github.com/caleb531/automata) 

[automata-from-regex](https://github.com/sdht0/automata-from-regex)

[pywonderland](https://github.com/neozhaoliang/pywonderland)

### Cloujr

[automat](https://github.com/ztellman/automat) 

### Java

[stateless4j](https://github.com/stateless4j/stateless4j) 



### C++

[state]( https://gameprogrammingpatterns.com/state.html )

[How to Code a State Machine in C or C++](https://barrgroup.com/Embedded-Systems/How-To/Coding-State-Machines)

[State Machine Design in C++]( http://www.drdobbs.com/cpp/state-machine-design-in-c/184401236 )

[Expressive Code for State Machines in C++](https://www.fluentcpp.com/2019/09/24/expressive-code-for-state-machines-in-cpp/)

[C++ code for state machine](https://stackoverflow.com/questions/14676709/c-code-for-state-machine)

### RUST

[regex-automata](https://github.com/BurntSushi/regex-automata)

