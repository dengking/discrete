# Formal grammar



## wikipedia [Formal grammar](https://en.wikipedia.org/wiki/Formal_grammar)

In [formal language theory](https://en.wikipedia.org/wiki/Formal_language), a **grammar** (when the context is not given, often called a **formal grammar** for clarity) is a set of [production rules](https://en.wikipedia.org/wiki/Production_(computer_science)) for [strings](https://en.wikipedia.org/wiki/String_(computer_science)) in a [formal language](https://en.wikipedia.org/wiki/Formal_language). The rules describe how to form strings from the language's [alphabet](https://en.wikipedia.org/wiki/Alphabet_(computer_science)) that are valid according to the language's [syntax](https://en.wikipedia.org/wiki/Syntax_(programming_languages)). A grammar does not describe the [meaning of the strings](https://en.wikipedia.org/wiki/Semantics) or what can be done with them in whatever context—only their form.

> NOTE: 不涉及[semantics](https://en.wikipedia.org/wiki/Semantics)

A formal grammar is a set of rules for [**rewriting**](https://en.wikipedia.org/wiki/Rewriting) strings, along with a "start symbol" from which **rewriting** starts. Therefore, a **grammar** is usually thought of as a **language generator**. However, it can also sometimes be used as the basis for a "[recognizer](https://en.wikipedia.org/wiki/Recognizer)"—a function in computing that determines whether a given string belongs to the language or is grammatically incorrect. To describe such **recognizers**, formal language theory uses separate formalisms, known as [automata theory](https://en.wikipedia.org/wiki/Automata_theory). One of the interesting results of **automata theory** is that it is not possible to design a **recognizer** for certain **formal languages**. [Parsing](https://en.wikipedia.org/wiki/Parsing) is the process of recognizing an utterance (a string in natural languages) by breaking it down to a set of **symbols** and analyzing each one against the **grammar** of the language. Most languages have the meanings of their utterances structured according to their **syntax**—a practice known as [compositional semantics](https://en.wikipedia.org/wiki/Compositional_semantics). As a result, the first step to describing the meaning of an utterance in language is to break it down part by part and look at its analyzed form (known as its [parse tree](https://en.wikipedia.org/wiki/Parse_tree) in computer science, and as its [deep structure](https://en.wikipedia.org/wiki/Deep_structure_and_surface_structure) in [generative grammar](https://en.wikipedia.org/wiki/Generative_grammar)).

### Formal definition

*Main article:* [Unrestricted grammar](https://en.wikipedia.org/wiki/Unrestricted_grammar)

#### The syntax of grammars

> NOTE: 这一段是描述语法的语法，其实就是[Metasyntax](https://en.wikipedia.org/wiki/Metasyntax)

### The Chomsky hierarchy

*Main article:* [Chomsky hierarchy](https://en.wikipedia.org/wiki/Chomsky_hierarchy)

> NOTE: [Chomsky hierarchy](https://en.wikipedia.org/wiki/Chomsky_hierarchy)对formal grammar进行分类。在Chomsky-hierarchy章节对它进行分析。



## Analytic grammars

> NOTE: 在compiler中，往往是基于grammar来对language（其实就是我们所写的程序）进行分析，这个过程就是 [parsing](https://en.wikipedia.org/wiki/Parsing_algorithm), 



