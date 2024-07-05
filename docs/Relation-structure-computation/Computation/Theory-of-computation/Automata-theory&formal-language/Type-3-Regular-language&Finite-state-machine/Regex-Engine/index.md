# Regex engine

Thompson's construction algorithm将regex转化为epsilon NFA;

Powerset construction algorithm将epsilon NFA转换为DFA;

epsilon transition在这两个算法中都发挥着非常重要的作用;



## Thompson's construction



### wikipedia [Thompson's construction](https://en.wikipedia.org/wiki/Thompson%27s_construction)

The **empty-expression** ε is converted to

[![inline](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7e/Thompson-epsilon.svg/278px-Thompson-epsilon.svg.png)](https://en.wikipedia.org/wiki/File:Thompson-epsilon.svg)

A **symbol** *a* of the input alphabet is converted to

[![inline](https://upload.wikimedia.org/wikipedia/commons/thumb/9/93/Thompson-a-symbol.svg/278px-Thompson-a-symbol.svg.png)](https://en.wikipedia.org/wiki/File:Thompson-a-symbol.svg)

The **union expression** *s*|*t* is converted to

[![inline](https://upload.wikimedia.org/wikipedia/commons/thumb/2/25/Thompson-or.svg/453px-Thompson-or.svg.png)](https://en.wikipedia.org/wiki/File:Thompson-or.svg)

State *q* goes via ε either to the initial state of *N*(*s*) or *N*(*t*). Their final states become intermediate states of the whole NFA and merge via two ε-transitions into the final state of the NFA.



The **concatenation expression** *st* is converted to

[![inline](https://upload.wikimedia.org/wikipedia/commons/thumb/5/55/Thompson-concat.svg/398px-Thompson-concat.svg.png)](https://en.wikipedia.org/wiki/File:Thompson-concat.svg)



The **[Kleene star](https://en.wikipedia.org/wiki/Kleene_star) expression** $s^*$ is converted to

[![inline](https://upload.wikimedia.org/wikipedia/commons/thumb/8/8e/Thompson-kleene-star.svg/503px-Thompson-kleene-star.svg.png)](https://en.wikipedia.org/wiki/File:Thompson-kleene-star.svg)

An ε-transition connects initial and final state of the NFA with the sub-NFA *N*(*s*) in between. Another ε-transition from the inner final to the inner initial state of *N*(*s*) allows for repetition of expression *s* according to the star operator.



## Powerset construction



### wikipedia [Powerset construction](https://en.wikipedia.org/wiki/Powerset_construction)

In the [theory of computation](https://en.wikipedia.org/wiki/Theory_of_computation) and [automata theory](https://en.wikipedia.org/wiki/Automata_theory), the **powerset construction** or **subset construction** is a standard method for [converting](https://en.wikipedia.org/wiki/Automata_construction) a [nondeterministic finite automaton](https://en.wikipedia.org/wiki/Nondeterministic_finite_automaton) (NFA) into a [deterministic finite automaton](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) (DFA) which recognizes the same [formal language](https://en.wikipedia.org/wiki/Formal_language). It is important in theory because it establishes that NFAs, despite their additional flexibility, are unable to recognize any language that cannot be recognized by some DFA. It is also important in practice for converting easier-to-construct NFAs into more efficiently executable DFAs. However, if the NFA has *n* states, the resulting DFA may have up to $2^n$ states, an exponentially larger number, which sometimes makes the construction impractical for large NFAs.

The construction, sometimes called the **Rabin–Scott powerset construction** (or **subset construction**) to distinguish it from similar constructions for other types of automata, was first published by [Michael O. Rabin](https://en.wikipedia.org/wiki/Michael_O._Rabin) and [Dana Scott](https://en.wikipedia.org/wiki/Dana_Scott) in 1959.

### Intuition

To simulate the operation of a DFA on a given input string, one needs to keep track of **a single state** at any time: the state that the automaton will reach after seeing a [prefix](https://en.wikipedia.org/wiki/Substring#Prefix) of the input. In contrast, to simulate an NFA, one needs to keep track of **a set of states**: all of the states that the automaton could reach after seeing the same prefix of the input, according to the nondeterministic choices made by the automaton. If, after a certain prefix of the input, a set *S* of states can be reached, then after the next input symbol *x* the set of reachable states is a deterministic function of *S* and *x*. Therefore, the sets of reachable NFA states play the same role in the NFA simulation as single DFA states play in the DFA simulation, and in fact the sets of NFA states appearing in this simulation may be re-interpreted as being states of a DFA.

> NOTE: 
>
> 一、The difference between DFA and NFA can help to understand why **a single state** in DFA versus **a set of states** in NFA,  below is come from [Finite-state machine](https://en.wikipedia.org/wiki/Finite-state_machine#Determinism):
>
> In a deterministic automaton, every state has exactly one transition for each possible input. In a non-deterministic automaton, an input can lead to one, more than one, or no transition for a given state. The [powerset construction](https://en.wikipedia.org/wiki/Powerset_construction) algorithm can transform any nondeterministic automaton into a (usually more complex) deterministic automaton with identical functionality.





## 素材

codeguru [**Write Your Own Regular Expression Parser**](https://www.codeguru.com/cplusplus/write-your-own-regular-expression-parser/)

https://se.ifmo.ru/~ad/Documentation/Mastering_RegExp/mastregex2-CHP-4.html

https://devopedia.org/regex-engines

wikipedia [Comparison of regular expression engines](https://en.wikipedia.org/wiki/Comparison_of_regular_expression_engines) 

Gregory-Cernera: 

- [niemaattarian](https://github.com/niemaattarian)/**[Thompsons-Construction-on-NFAs](https://github.com/niemaattarian/Thompsons-Construction-on-NFAs)**

- medium [**Visualizing Thompson’s Construction Algorithm for NFAs, step-by-step**](https://medium.com/swlh/visualizing-thompsons-construction-algorithm-for-nfas-step-by-step-f92ef378581b)

- medium [Converting Regular Expressions to Postfix Notation with the Shunting-Yard Algorithm](https://gregorycernera.medium.com/converting-regular-expressions-to-postfix-notation-with-the-shunting-yard-algorithm-63d22ea1cf88)

