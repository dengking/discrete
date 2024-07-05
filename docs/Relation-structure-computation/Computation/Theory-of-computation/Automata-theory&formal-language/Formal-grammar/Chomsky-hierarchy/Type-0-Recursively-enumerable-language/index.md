[TOC]



# [Recursively enumerable language](https://en.wikipedia.org/wiki/Recursively_enumerable_language)



# [Unrestricted grammar](https://en.wikipedia.org/wiki/Unrestricted_grammar)

In [automata theory](https://en.wikipedia.org/wiki/Automata_theory), the class of **unrestricted grammars** (also called **semi-Thue**, **type-0** or **phrase structure grammars**) is the most general class of grammars in the [Chomsky hierarchy](https://en.wikipedia.org/wiki/Chomsky_hierarchy). No restrictions are made on the productions of an unrestricted grammar, other than each of their left-hand sides being non-empty. This grammar class can generate arbitrary [recursively enumerable languages](https://en.wikipedia.org/wiki/Recursively_enumerable_language).

## Formal definition

An **unrestricted grammar** is a [formal grammar](https://en.wikipedia.org/wiki/Formal_grammar) $ G=(N,\Sigma ,P,S) $, where $ N $ is a set of nonterminal symbols, $ \Sigma $ is a set of [terminal symbols](https://en.wikipedia.org/wiki/Terminal_symbol), $ N $ and $ \Sigma $ are disjoint,  $ P $ is a set of [production rules](https://en.wikipedia.org/wiki/Production_(computer_science)) of the form $ \alpha \to \beta $ where $ \alpha $ and $ \beta $ are strings of symbols in $ N\cup \Sigma $ and $ \alpha $ is not the empty string, and $ S\in N $ is a specially designated start symbol. As the name implies, there are no real restrictions on the types of production rules that unrestricted grammars can have.

# [Semi-Thue system](https://en.wikipedia.org/wiki/Semi-Thue_system)

In [theoretical computer science](https://en.wikipedia.org/wiki/Theoretical_computer_science) and [mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic) a **string rewriting system** (**SRS**), historically called a **semi-[Thue](https://en.wikipedia.org/wiki/Axel_Thue) system**, is a [rewriting](https://en.wikipedia.org/wiki/Rewriting) system over [strings](https://en.wikipedia.org/wiki/String_(computer_science)) from a (usually [finite](https://en.wikipedia.org/wiki/Finite_set)) [alphabet](https://en.wikipedia.org/wiki/Alphabet_(computer_science)). Given a [binary relation](https://en.wikipedia.org/wiki/Binary_relation) $ R $ between fixed strings over the alphabet, called **rewrite rules**, denoted by $ s\rightarrow t $, an SRS extends the rewriting relation to all strings in which the left- and right-hand side of the rules appear as [substrings](https://en.wikipedia.org/wiki/Substring), that is $ usv\rightarrow utv $, where $ s $, $ t $, $ u $, and $ v $ are strings.