# Finite-state-automaton-based string search algorithm

## wikipedia [String-searching algorithm](https://en.wikipedia.org/wiki/String-searching_algorithm) # Finite-state-automaton-based search

In this approach, we avoid backtracking by constructing a [deterministic finite automaton](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) (DFA) that recognizes stored search string. These are expensive to construct—they are usually created using the [powerset construction](https://en.wikipedia.org/wiki/Powerset_construction)—but are very quick to use. For example, the [DFA](https://en.wikipedia.org/wiki/Deterministic_finite_automaton) shown to the right recognizes the word "MOMMY". This approach is frequently generalized in practice to search for arbitrary [regular expressions](https://en.wikipedia.org/wiki/Regular_expression).



