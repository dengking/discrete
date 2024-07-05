# wikipedia [Formal language](https://en.wikipedia.org/wiki/Formal_language)

> NOTE: 充分理解本文的前提是对[Mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic)有基本的认知，参见上一章节。

In [mathematics](https://en.wikipedia.org/wiki/Mathematics), [computer science](https://en.wikipedia.org/wiki/Computer_science), and [linguistics](https://en.wikipedia.org/wiki/Linguistics), a **formal language** consists of [words](https://en.wikipedia.org/wiki/String_(computer_science)) whose [letters](https://en.wikipedia.org/wiki/Symbol_(formal)) are taken from an [alphabet](https://en.wikipedia.org/wiki/Alphabet_(computer_science)) and are [well-formed](https://en.wikipedia.org/wiki/Well-formedness) according to a specific set of rules. 

The [alphabet](https://en.wikipedia.org/wiki/Alphabet_(computer_science)) of a formal language consist of symbols, letters, or tokens that concatenate into strings of the language. Each string concatenated from symbols of this alphabet is called a **word**, and the words that belong to a particular formal language are sometimes called *well-formed words* or *[well-formed formulas](https://en.wikipedia.org/wiki/Well-formed_formula)*. A formal language is often defined by means of a [formal grammar](https://en.wikipedia.org/wiki/Formal_grammar) such as a [regular grammar](https://en.wikipedia.org/wiki/Regular_grammar) or [context-free grammar](https://en.wikipedia.org/wiki/Context-free_grammar), which consists of its [formation rules](https://en.wikipedia.org/wiki/Formation_rule). 

The field of **formal language theory** studies primarily the purely [syntactical](https://en.wikipedia.org/wiki/Syntax)（语法） aspects of such languages—that is, their **internal structural patterns**. **Formal language theory** sprang out of linguistics, as a way of understanding the syntactic regularities（规律） of [natural languages](https://en.wikipedia.org/wiki/Natural_language). 

In computer science, **formal languages** are used among others as the basis for defining the **grammar** of [programming languages](https://en.wikipedia.org/wiki/Programming_language) and formalized versions of subsets of natural languages in which the words of the language represent concepts that are associated with particular meanings or [semantics](https://en.wikipedia.org/wiki/Semantics)（语义）. 

In [computational complexity theory](https://en.wikipedia.org/wiki/Computational_complexity_theory), [decision problems](https://en.wikipedia.org/wiki/Decision_problem) are typically defined as **formal languages**, and [complexity classes](https://en.wikipedia.org/wiki/Complexity_class) are defined as the sets of the formal languages that can be [parsed by machines](https://en.wikipedia.org/wiki/Parser) with limited computational power. 

In [logic](https://en.wikipedia.org/wiki/Logic) and the [foundations of mathematics](https://en.wikipedia.org/wiki/Foundations_of_mathematics), formal languages are used to represent the syntax of [axiomatic systems](https://en.wikipedia.org/wiki/Axiomatic_system), and [mathematical formalism](https://en.wikipedia.org/wiki/Formalism_(mathematics)) is the philosophy that all of mathematics can be reduced to the syntactic manipulation of formal languages in this way. 

> NOTE: 上面这段话的第一句话揭示了 **formal language** 和 [logic](https://en.wikipedia.org/wiki/Logic) 之间的关系。

> NOTE: 最后一段话的意思是：[mathematical formalism](https://en.wikipedia.org/wiki/Formalism_(mathematics))的思想是：所有的数学都可以通过这种方式简化为formal language的syntactic manipulation。浏览了一下这篇文章，发现[theory of computation](https://en.wikipedia.org/wiki/Theory_of_computation)中的很多课题都源于这个思想，比如[Turing machine](https://en.wikipedia.org/wiki/Turing_machine)。



## Words over an alphabet

An **alphabet**, in the context of formal languages, can be any [set](https://en.wikipedia.org/wiki/Set_(mathematics)), although it often makes sense to use an [alphabet](https://en.wikipedia.org/wiki/Alphabet) in the usual sense of the word, or more generally a [character set](https://en.wikipedia.org/wiki/Character_set) such as [ASCII](https://en.wikipedia.org/wiki/ASCII) or [Unicode](https://en.wikipedia.org/wiki/Unicode). The elements of an alphabet are called its **letters**. An alphabet may contain an [infinite](https://en.wikipedia.org/wiki/Countable_set) number of elements; however, most definitions in formal language theory specify alphabets with a finite number of elements, and most results apply only to them.

A **word** over an alphabet can be any finite sequence (i.e., [string](https://en.wikipedia.org/wiki/String_(computer_science))) of letters. The set of all words over an alphabet Σ is usually denoted by Σ* (using the [Kleene star](https://en.wikipedia.org/wiki/Kleene_star)). The length of a word is the number of letters it is composed of. For any alphabet, there is only one word of length 0, the *empty word*, which is often denoted by e, ε, λ or even Λ. By [concatenation](https://en.wikipedia.org/wiki/Concatenation) one can combine two words to form a new word, whose length is the sum of the lengths of the original words. The result of concatenating a word with the empty word is the original word.

In some applications, especially in [logic](https://en.wikipedia.org/wiki/Logic), the alphabet is also known as the *vocabulary* and words are known as *formulas* or *sentences*; this breaks the letter/word metaphor and replaces it by a word/sentence metaphor.

> NOTE: 在formal language理论中，**alphabet**、 [character set](https://en.wikipedia.org/wiki/Character_set)  、vocabulary可以认为是同义词。



## Definition

A **formal language** *L* over an alphabet Σ is a [subset](https://en.wikipedia.org/wiki/Subset) of Σ*, that is, a set of [words](https://en.wikipedia.org/wiki/Formal_language#Words_over_an_alphabet) over that alphabet. Sometimes the sets of words are grouped into expressions, whereas rules and constraints may be formulated for the creation of 'well-formed expressions'.

> NOTE: 所谓的rules其实就是grammar。

In computer science and mathematics, which do not usually deal with [natural languages](https://en.wikipedia.org/wiki/Natural_language), the adjective "formal" is often omitted as redundant.

> NOTE: 按照这个说法，programming language的更加严谨的说法是：programming formal language。

While formal language theory usually concerns itself with formal languages that are described by some syntactical rules, the actual definition of the concept "formal language" is only as above: a (possibly infinite) set of finite-length strings composed from a given alphabet, no more and no less. In practice, there are many languages that can be described by **rules**, such as [regular languages](https://en.wikipedia.org/wiki/Regular_language) or [context-free languages](https://en.wikipedia.org/wiki/Context-free_language). The notion of a [formal grammar](https://en.wikipedia.org/wiki/Formal_grammar) may be closer to the intuitive concept of a "language," one described by syntactic rules. By an abuse of the definition, a particular formal language is often thought of as being equipped with a **formal grammar** that describes it.

> NOTE: 上面这段话所强调的是formal language的准确定义中是不包含rules（grammar）的。但是实际中，要想准确的定义一门语言是离不开rules的。以programming language为例的话，它需要词法和语法才能够正确地描述该语言。



### Constructions

For finite languages, one can explicitly **enumerate** all well-formed words. For example, we can describe a language *L* as just *L* = {a, b, ab, cba}. The [degenerate](https://en.wikipedia.org/wiki/Degeneracy_(mathematics)) case of this construction is the **empty language**, which contains no words at all (*L* = [∅](https://en.wikipedia.org/wiki/∅)).

However, even over a finite (non-empty) alphabet such as Σ = {a, b} there are an infinite number of finite-length words that can potentially be expressed: "a", "abb", "ababba", "aaababbbbaab", .... Therefore, formal languages are typically infinite, and describing an infinite formal language is not as simple as writing *L* = {a, b, ab, cba}. Here are some examples of formal languages:

- *L* = Σ*, the set of *all* words over Σ;
- $L = \{a\}^* = {a^n}$, where *n* ranges over the natural numbers and "$a^n$" means "a" repeated *n* times (this is the set of words consisting only of the symbol "a");
- the set of syntactically correct programs in a given programming language (the syntax of which is usually defined by a [context-free grammar](https://en.wikipedia.org/wiki/Context-free_grammar));
- the set of inputs upon which a certain [Turing machine](https://en.wikipedia.org/wiki/Turing_machine) halts; or
- the set of maximal strings of [alphanumeric](https://en.wikipedia.org/wiki/Alphanumeric) [ASCII](https://en.wikipedia.org/wiki/ASCII) characters on this line, i.e.,
  the set {the, set, of, maximal, strings, alphanumeric, ASCII, characters, on, this, line, i, e}.



## Language-specification formalisms

Formal languages are used as tools in multiple disciplines. However, **formal language theory** rarely concerns itself with particular languages (except as examples), but is mainly concerned with the study of various types of **formalisms** to describe languages. For instance, a language can be given as

- those strings generated by some [formal grammar](https://en.wikipedia.org/wiki/Formal_grammar);
- those strings described or matched by a particular [regular expression](https://en.wikipedia.org/wiki/Regular_expression);
- those strings accepted by some [automaton](https://en.wikipedia.org/wiki/Automata_theory), such as a [Turing machine](https://en.wikipedia.org/wiki/Turing_machine) or [finite-state automaton](https://en.wikipedia.org/wiki/Finite-state_machine);
- those strings for which some [decision procedure](https://en.wikipedia.org/wiki/Decision_problem) (an [algorithm](https://en.wikipedia.org/wiki/Algorithm) that asks a sequence of related YES/NO questions) produces the answer YES.

Typical questions asked about such **formalisms** include:

- What is their expressive power? (Can formalism *X* describe every language that formalism *Y* can describe? Can it describe other languages?)
- What is their recognizability? (How difficult is it to decide whether a given word belongs to a language described by formalism *X*?)
- What is their comparability? (How difficult is it to decide whether two languages, one described in formalism *X* and one in formalism *Y*, or in *X* again, are actually the same language?).

Surprisingly often, the answer to these decision problems is "it cannot be done at all", or "it is extremely expensive" (with a characterization of how expensive). Therefore, formal language theory is a major application area of [computability theory](https://en.wikipedia.org/wiki/Computability_theory_(computer_science)) and [complexity theory](https://en.wikipedia.org/wiki/Computational_complexity_theory). Formal languages may be classified in the [Chomsky hierarchy](https://en.wikipedia.org/wiki/Chomsky_hierarchy) based on the expressive power of their **generative grammar** as well as the complexity of their recognizing [automaton](https://en.wikipedia.org/wiki/Automata_theory). [Context-free grammars](https://en.wikipedia.org/wiki/Context-free_grammar) and [regular grammars](https://en.wikipedia.org/wiki/Regular_grammar) provide a good compromise between expressivity and ease of [parsing](https://en.wikipedia.org/wiki/Parsing), and are widely used in practical applications.



## [Operations on languages](https://en.wikipedia.org/wiki/Formal_language#Operations_on_languages)



## Applications

### Programming languages

*Main articles:* [Compiler compiler](https://en.wikipedia.org/wiki/Compiler_compiler) and [Syntax (programming languages)](https://en.wikipedia.org/wiki/Syntax_(programming_languages))

### [Formal theories, systems, and proofs](https://en.wikipedia.org/wiki/Formal_language#Formal_theories,_systems,_and_proofs)

