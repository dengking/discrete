



# [Parsing expression grammar](https://en.wikipedia.org/wiki/Parsing_expression_grammar#Implementing_parsers_from_parsing_expression_grammars)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **parsing expression grammar**, or **PEG**, is a type of [analytic](https://en.wikipedia.org/wiki/Formal_grammar#Analytic_grammars) [formal grammar](https://en.wikipedia.org/wiki/Formal_grammar), i.e. it describes a [formal language](https://en.wikipedia.org/wiki/Formal_language) in terms of a set of rules for recognizing [strings](https://en.wikipedia.org/wiki/String_(computer_science)) in the language. The formalism was introduced by Bryan Ford in 2004[[1\]](https://en.wikipedia.org/wiki/Parsing_expression_grammar#cite_note-For04-1) and is closely related to the family of [top-down parsing languages](https://en.wikipedia.org/wiki/Top-down_parsing_language) introduced in the early 1970s. Syntactically, PEGs also look similar to [context-free grammars](https://en.wikipedia.org/wiki/Context-free_grammar) (CFGs), but they have a different interpretation: the choice operator selects the first match in PEG, while it is ambiguous in CFG. This is closer to how string recognition tends to be done in practice, e.g. by a [recursive descent parser](https://en.wikipedia.org/wiki/Recursive_descent_parser).

> NOTE: PEG include regular grammar.

Unlike CFGs, PEGs cannot be [ambiguous](https://en.wikipedia.org/wiki/Ambiguous_grammar); if a string parses, it has exactly one valid [parse tree](https://en.wikipedia.org/wiki/Parse_tree). It is conjectured that there exist context-free languages that cannot be recognized by a PEG, but this is not yet proven.[[1\]](https://en.wikipedia.org/wiki/Parsing_expression_grammar#cite_note-For04-1) PEGs are well-suited to parsing computer languages (and artificial human languages such as [Lojban](https://en.wikipedia.org/wiki/Lojban)), but not [natural languages](https://en.wikipedia.org/wiki/Natural_language) where the performance of PEG algorithms is comparable to general CFG algorithms such as the [Earley algorithm](https://en.wikipedia.org/wiki/Earley_algorithm).

> NOTE: [Python3.8+](https://docs.python.org/3/reference/grammar.html) use PEG to describe its grammar.



## See also

[The Packrat Parsing and Parsing Expression Grammars Page](https://bford.info/packrat/)