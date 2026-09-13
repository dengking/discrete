# NFA

## wikipedia [Nondeterministic finite automaton](https://en.wikipedia.org/wiki/Nondeterministic_finite_automaton)

#### Formal definition

An *NFA* is represented formally by a 5-[tuple](https://en.wikipedia.org/wiki/Tuple), ${\displaystyle (Q,\Sigma ,\delta ,q_{0},F)}$, consisting of

- a finite [set](https://en.wikipedia.org/wiki/Set_(mathematics)) of states ${\displaystyle Q}$.
- a finite set of [input symbols](https://en.wikipedia.org/wiki/Input_symbol) ${\displaystyle \Sigma }$.
- a transition function ${\displaystyle \delta }$ : ${\displaystyle Q\times \Sigma \rightarrow {\mathcal {P}}(Q)}$.
- an *initial* (or *start*) state ${\displaystyle q_{0}\in Q}$.
- a set of states ${\displaystyle F}$ distinguished as *accepting* (or *final*) *states* ${\displaystyle F\subseteq Q}$.

Here, ${\displaystyle {\mathcal {P}}(Q)}$ denotes the [power set](https://en.wikipedia.org/wiki/Power_set) of ${\displaystyle Q}$.

#### Example: $(0|1)^{\star}1(1|3)^{3}$

NFA for [regex](https://en.wikipedia.org/wiki/Regular_expression) $(0|1)^{\star}1(1|3)^{3}$, A [DFA](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) for that [language](https://en.wikipedia.org/wiki/Formal_language) has at least 16 states.

![](Relatively_small_NFA.svg)

#### Example: $(0|1)^{\star}1$

The following automaton ${\displaystyle M}$, with a binary alphabet, determines if the input ends with a 1. Let ${\displaystyle M=(\{p,q\},\{0,1\},\delta ,p,\{q\})}$ where the transition function ${\displaystyle \delta }$ can be defined by this state transition table (cf. upper left picture):

| InputState          | 0                            | 1                            |
|:-------------------:|:----------------------------:|:----------------------------:|
| ${\displaystyle p}$ | ${\displaystyle \{p\}}$      | ${\displaystyle \{p,q\}}$    |
| ${\displaystyle q}$ | ${\displaystyle \emptyset }$ | ${\displaystyle \emptyset }$ |

##### NFA

![](NFASimpleExample.svg)

##### NFA-ε

![](NFAexample.svg)

Since the set ${\displaystyle \delta (p,1)}$ contains more than one state, ${\displaystyle M}$ is nondeterministic. The language of ${\displaystyle M}$ can be described by the regular language given by the regular expression $(0|1)^{\star}1$.

#### NFA with $\epsilon$-moves

**Nondeterministic finite automaton** with ε-moves (NFA-ε) is a further generalization to NFA. In this kind of automaton, the **transition function** is additionally defined on the [empty string](https://en.wikipedia.org/wiki/Empty_string) ε. A transition without consuming an input symbol is called an ε-transition and is represented in state diagrams by an arrow labeled "ε". ε-transitions provide a convenient way of modeling systems whose current states are not precisely known: i.e., if we are modeling a system and it is not clear whether the current state (after processing some input string) should be q or q', then we can add an ε-transition between these two states, thus putting the automaton in both states simultaneously.

> NOTE:
> 
> 一、wikipedia [Epsilon transition](https://en.wikipedia.org/wiki/Epsilon_transition) 
> 
> 上面这段话非常好地介绍了 [epsilon transition](https://en.wikipedia.org/wiki/Epsilon_transition) 的意义，但是 [epsilon transition](https://en.wikipedia.org/wiki/Epsilon_transition) 的作用是否仅限于此呢？在后面会进行详细补充

## Epsilon transition

[LeetCode-10. Regular Expression Matching-hard](https://leetcode.cn/problems/regular-expression-matching/) 

epsilon transition保证能够找到所有的可能性。

epsilon transition 是为了找到所有可能的**起始状态**，这样后续的匹配可以从这些可能的起始状态开始匹配。

这种方式直接将regex看做是NFA，它不需要显示地构造出一个DFA，这样避免对 undeterministic 的讨论: 对于同一状态，遇到相同字符的时候，出现多种转换方式的讨论。

```
/**
* 在匹配完成后，如果node有epsilon transition，则不断执行epsilon transition
* 一、因为可能出现字符串比pattern短的情况，比如:
* s = "a"
* p = "ab*"
* 二、最后的"c*a*"都不在匹配
* s = "cbaacacaaccbaabcb"
* p = "c*b*b*.*ac*.*bc*a*"
*/
```

stackoverflow [What does an NFA with epsilon transitions let us do?](https://stackoverflow.com/questions/29401562/what-does-an-nfa-with-epsilon-transitions-let-us-do)

其中的例子很好

### wikipedia [Epsilon transition](https://en.wikipedia.org/wiki/Epsilon_transition)

An **epsilon transition** (also **epsilon move** or **lambda transition**) allows an [automaton](https://en.wikipedia.org/wiki/Automata_theory) to change its state spontaneously(自发的), i.e. without consuming an input symbol. It may appear in almost all kinds of **nondeterministic automaton** in formal language theory, in particular:

- [Nondeterministic Turing machine](https://en.wikipedia.org/wiki/Nondeterministic_Turing_machine)
- [Nondeterministic pushdown automaton](https://en.wikipedia.org/wiki/Nondeterministic_pushdown_automaton)
- [Nondeterministic finite automaton](https://en.wikipedia.org/wiki/Nondeterministic_finite_automaton)


