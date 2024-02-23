# Finite-state-automaton-based string algorithm

思路概述: 将text逐个character地输入到Automata中，character将导致state的transition。

> NOTE:
>
> 一、在 [stanford-cs166.1166-Aho-Corasick Automata](https://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Slides02.pdf) 中所展示的使用trie进行multiple string search非常好地形象地展示上述思路



## wikipedia [String-searching algorithm](https://en.wikipedia.org/wiki/String-searching_algorithm) # Finite-state-automaton-based search

In this approach, we avoid backtracking by constructing a [deterministic finite automaton](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) (DFA) that recognizes stored search string. These are expensive to construct—they are usually created using the [powerset construction](https://en.wikipedia.org/wiki/Powerset_construction)—but are very quick to use. For example, the [DFA](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) shown to the right recognizes the word "MOMMY". This approach is frequently generalized in practice to search for arbitrary [regular expressions](https://en.wikipedia.org/wiki/Regular_expression).



## Examples

- [Trie](https://en.wikipedia.org/wiki/Trie) 

  > NOTE:
  >
  > 一、 [stanford-cs166.1166-Aho-Corasick Automata](https://web.stanford.edu/class/archive/cs/cs166/cs166.1166/lectures/02/Slides02.pdf) 中使用trie进行multiple string search

- [Aho–Corasick algorithm](https://en.wikipedia.org/wiki/Aho%E2%80%93Corasick_algorithm) 

- [Suffix automaton](https://en.wikipedia.org/wiki/Suffix_automaton)

- [Suffix tree](https://en.wikipedia.org/wiki/Suffix_tree) 

- [Regex engine](https://en.wikipedia.org/wiki/Comparison_of_regular_expression_engines)

