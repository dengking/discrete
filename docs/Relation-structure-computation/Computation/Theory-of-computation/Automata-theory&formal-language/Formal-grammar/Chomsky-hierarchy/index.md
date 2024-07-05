# Chomsky hierarchy

## wikipedia [Chomsky hierarchy](https://en.wikipedia.org/wiki/Chomsky_hierarchy)

In the [formal languages](https://en.wikipedia.org/wiki/Formal_language) of [computer science](https://en.wikipedia.org/wiki/Computer_science) and [linguistics](https://en.wikipedia.org/wiki/Linguistics), the **Chomsky hierarchy** (occasionally referred to as the **Chomsky–Schützenberger hierarchy**) is a [containment hierarchy](https://en.wikipedia.org/wiki/Containment_hierarchy) of classes of [formal grammars](https://en.wikipedia.org/wiki/Formal_grammar).

This hierarchy of grammars was described by [Noam Chomsky](https://en.wikipedia.org/wiki/Noam_Chomsky) in 1956. It is also named after [Marcel-Paul Schützenberger](https://en.wikipedia.org/wiki/Marcel-Paul_Schützenberger), who played a crucial role in the development of the theory of [formal languages](https://en.wikipedia.org/wiki/Formal_language).



### The hierarchy

The following table summarizes each of Chomsky's four types of grammars, the class of language it generates, the type of automaton that recognizes it, and the form its rules must have. 

| Grammar |                          Languages                           |                          Automaton                           |               Production rules (constraints)*                |                         Examples                         |
| :-----: | :----------------------------------------------------------: | :----------------------------------------------------------: | :----------------------------------------------------------: | :------------------------------------------------------: |
| Type-0  | [Recursively enumerable](https://en.wikipedia.org/wiki/Recursively_enumerable_language) | [Turing machine](https://en.wikipedia.org/wiki/Turing_machine) |    $ \alpha A\beta \rightarrow \delta $ (no constraints)     | $ L=\{w|w $ describes a terminating Turing machine$ \} $ |
| Type-1  | [Context-sensitive](https://en.wikipedia.org/wiki/Context-sensitive_grammar) | [Linear-bounded non-deterministic Turing machine](https://en.wikipedia.org/wiki/Linear_bounded_automaton) |      $ \alpha A\beta \rightarrow \alpha \gamma \beta $       |              $ L=\{a^{n}b^{n}c^{n}|n>0\} $               |
| Type-2  | [Context-free](https://en.wikipedia.org/wiki/Context-free_grammar) | Non-deterministic [pushdown automaton](https://en.wikipedia.org/wiki/Pushdown_automaton) |                   $ A\rightarrow \alpha $                    |                 $ L=\{a^{n}b^{n}|n>0\} $                 |
| Type-3  |   [Regular](https://en.wikipedia.org/wiki/Regular_grammar)   | [Finite state automaton](https://en.wikipedia.org/wiki/Finite_state_automaton) | $ A\rightarrow {\text{a}} $ and $ A\rightarrow {\text{a}}B $ |                 $ L=\{a^{n}|n\geq 0\} $                  |

>  Meaning of symbols: 
>
> - $ {\text{a}} $ = terminal
> - $ A $, $ B $ = non-terminal
> - $ \alpha $, $ \beta $, $ \gamma $, $ \delta $ = string of terminals and/or non-terminals
>     -  $ \alpha $, $ \beta $, $ \delta $ = maybe empty 
>     -  $ \gamma $ = never empty 

[![The Chomsky hierarchy](https://upload.wikimedia.org/wikipedia/commons/thumb/9/9a/Chomsky-hierarchy.svg/200px-Chomsky-hierarchy.svg.png)](https://en.wikipedia.org/wiki/File:Chomsky-hierarchy.svg)

 Set inclusions described by the Chomsky hierarchy 

Note that the set of grammars corresponding to [recursive languages](https://en.wikipedia.org/wiki/Recursive_language) is not a member of this hierarchy; these would be properly between Type-0 and Type-1.

Every regular language is context-free, every context-free language is context-sensitive, every context-sensitive language is **recursive** and every **recursive language** is **recursively enumerable**. These are all **proper inclusions**, meaning that there exist recursively enumerable languages that are not context-sensitive, context-sensitive languages that are not context-free and context-free languages that are not regular.

#### Type-0 grammars

 *Main article:* [Unrestricted grammar](https://en.wikipedia.org/wiki/Unrestricted_grammar) 

Type-0 grammars include all formal grammars. They generate exactly all languages that can be recognized by a [Turing machine](https://en.wikipedia.org/wiki/Turing_machine). These languages are also known as the [*recursively enumerable*](https://en.wikipedia.org/wiki/Recursively_enumerable_language) or *Turing-recognizable* languages. Note that this is different from the [recursive languages](https://en.wikipedia.org/wiki/Recursive_language), which can be *decided* by an [always-halting Turing machine](https://en.wikipedia.org/wiki/Machine_that_always_halts). 



#### Type-1 grammars

 *Main article:* [Context-sensitive grammar](https://en.wikipedia.org/wiki/Context-sensitive_grammar) 

Type-1 grammars generate [context-sensitive languages](https://en.wikipedia.org/wiki/Context-sensitive_language). These grammars have rules of the form $ \alpha A\beta \rightarrow \alpha \gamma \beta $ with $ A $ a nonterminal and $ \alpha $, $ \beta $ and $ \gamma $ strings of terminals and/or nonterminals. The strings $ \alpha $ and $ \beta $ may be empty, but $ \gamma $ must be nonempty. The rule $ S\rightarrow \epsilon $ is allowed if $ S $ does not appear on the right side of any rule. The languages described by these grammars are exactly all languages that can be recognized by a [linear bounded automaton](https://en.wikipedia.org/wiki/Linear_bounded_automaton) (a nondeterministic Turing machine whose tape is bounded by a constant times the length of the input.) 

#### Type-2 grammars

 *Main article:* [Context-free grammar](https://en.wikipedia.org/wiki/Context-free_grammar) 

 Type-2 grammars generate the [context-free languages](https://en.wikipedia.org/wiki/Context-free_language). These are defined by rules of the form $ A\rightarrow \alpha $ with $ A $ being a nonterminal and $ \alpha $ being a string of terminals and/or nonterminals. These languages are exactly all languages that can be recognized by a non-deterministic [pushdown automaton](https://en.wikipedia.org/wiki/Pushdown_automaton). Context-free languages—or rather its subset of [deterministic context-free language](https://en.wikipedia.org/wiki/Deterministic_context-free_language)—are the theoretical basis for the phrase structure of most [programming languages](https://en.wikipedia.org/wiki/Programming_language), though their syntax also includes context-sensitive name resolution due to declarations and [scope](https://en.wikipedia.org/wiki/Scope_(computer_science)). Often a subset of grammars is used to make parsing easier, such as by an [LL parser](https://en.wikipedia.org/wiki/LL_parser). 

#### Type-3 grammars

 *Main article:* [Regular grammar](https://en.wikipedia.org/wiki/Regular_grammar) 

 Type-3 grammars generate the [regular languages](https://en.wikipedia.org/wiki/Regular_language). Such a grammar restricts its rules to a single nonterminal on the left-hand side and a right-hand side consisting of a single terminal, possibly followed by a single nonterminal (right regular). Alternatively, the right-hand side of the grammar can consist of a single terminal, possibly preceded by a single nonterminal (left regular). These generate the same languages. However, if left-regular rules and right-regular rules are combined, the language need no longer be regular. The rule $ S\rightarrow \epsilon $ is also allowed here if $ S $ does not appear on the right side of any rule. These languages are exactly all languages that can be decided by a [finite state automaton](https://en.wikipedia.org/wiki/Finite_state_automaton). Additionally, this family of formal languages can be obtained by [regular expressions](https://en.wikipedia.org/wiki/Regular_expression). Regular languages are commonly used to define search patterns and the lexical structure of programming languages. 







## 对比分析

Type-0 grammars又叫做[unrestricted grammar](https://en.wikipedia.org/wiki/Unrestricted_grammar)，从它的名字可以看出，它是unrestricted的，即

> No restrictions are made on the productions of an unrestricted grammar

那其它grammar（Type-1 grammars [Context-sensitive grammar](https://en.wikipedia.org/wiki/Context-sensitive_grammar)、Type-2 grammars [Context-free grammar](https://en.wikipedia.org/wiki/Context-free_grammar) 、Type-3 grammars [Regular grammar](https://en.wikipedia.org/wiki/Regular_grammar) ），对各自的production的restriction是什么呢？下面从这个角度对这几种grammar进行对比分析， 由上述Chomsky hierarchy所描述的层级可以看出，从Type 0 grammars到Type 3 grammars逐级增加restriction，所以在进行对比分析的时候，每个grammar只需要和它的升一级grammar进行对比即可。



### Type-0 grammars:[Unrestricted grammar formal definition](https://en.wikipedia.org/wiki/Unrestricted_grammar#Formal_definition)

An **unrestricted grammar** is a [formal grammar](https://en.wikipedia.org/wiki/Formal_grammar) $ G=(N,\Sigma ,P,S) $, where $ N $ is a set of nonterminal symbols, $ \Sigma $ is a set of [terminal symbols](https://en.wikipedia.org/wiki/Terminal_symbol), $ N $ and $ \Sigma $ are disjoint,  $ P $ is a set of [production rules](https://en.wikipedia.org/wiki/Production_(computer_science)) of the form $ \alpha \to \beta $ where $ \alpha $ and $ \beta $ are strings of symbols in $ N\cup \Sigma $ and $ \alpha $ is not the **empty string**, and $ S\in N $ is a specially designated start symbol. As the name implies, there are no real restrictions on the types of production rules that unrestricted grammars can have.

#### 对比分析

和其他的grammar production相比，它的unrestriction体现在：

- $\alpha$可以为terminal、non-terminal

- $\beta$可以为empty string

### Type-1 grammars:[Context-sensitive grammar formal definition](https://en.wikipedia.org/wiki/Context-sensitive_grammar#Formal_definition)

A [formal grammar](https://en.wikipedia.org/wiki/Formal_grammar) *G* = (*N*, Σ, *P*, *S*), where *N* is a set of nonterminal symbols, Σ is a set of terminal symbols, *P* is a set of production rules, and *S* is the [start symbol](https://en.wikipedia.org/wiki/Start_symbol_(formal_languages)), is **context-sensitive** if all rules in *P* are of the form

α*A*β → αγβ

where *A* ∈ *N*, α,β ∈ (*N*∪Σ)*  and γ ∈ (*N*∪Σ)+. 

上述`*`和`+`都是使用的正则表达式的概念。

#### 对比分析

 和[unrestricted grammar](https://en.wikipedia.org/wiki/Unrestricted_grammar) production相比，它的restriction在于：

- γ不可为empty string
- A（在产生式的左部）必须是non-terminal

上述两个restriction在Type-0 grammar中都不存在。



### Type-2 grammars:[Context-free grammar formal definitions](https://en.wikipedia.org/wiki/Context-free_grammar#Formal_definitions)

A context-free grammar *G* is defined by the 4-[tuple](https://en.wikipedia.org/wiki/Tuple): 

$ G=(V,\Sigma ,R,S) $ where

1、*V* is a finite set; each element $ v\in V $ is called *a nonterminal character* or a *variable*. Each variable represents a different type of phrase or clause in the sentence. Variables are also sometimes called syntactic categories. Each variable defines a sub-language of the language defined by *G*.

2、Σ is a finite set of *terminal*s, disjoint from *V*, which make up the actual content of the sentence. The set of terminals is the alphabet of the language defined by the grammar *G*.

3、*R* is a finite **relation** from *V* to $ (V\cup \Sigma )^{*} $, where the asterisk represents the [Kleene star](https://en.wikipedia.org/wiki/Kleene_star) operation. The members of *R* are called the *(rewrite) rule*s or *production*s of the grammar. (also commonly symbolized by a *P*)

> NOTE: See also
>
> -  [production rule](https://en.wikipedia.org/wiki/Formal_grammar#The_syntax_of_grammars) 
> -  [rewriting](https://en.wikipedia.org/wiki/Rewriting)

4、*S* is the start variable (or start symbol), used to represent the whole sentence (or program). It must be an element of *V*.



#### Production rule notation 

A [production rule](https://en.wikipedia.org/wiki/Formal_grammar#The_syntax_of_grammars) in *R* is formalized mathematically as a pair $ (\alpha ,\beta )\in R $, where $ \alpha \in V $ is a nonterminal and $ \beta \in (V\cup \Sigma )^{*} $ is a [string](https://en.wikipedia.org/wiki/String_(computer_science)) of variables and/or terminals; rather than using [ordered pair](https://en.wikipedia.org/wiki/Ordered_pair) notation, production rules are usually written using an arrow operator with *α* as its left hand side and *β* as its right hand side: $ \alpha \rightarrow \beta $.

It is allowed for *β* to be the [empty string](https://en.wikipedia.org/wiki/Empty_string), and in this case it is customary to denote it by ε. The form $ \alpha \rightarrow \varepsilon $ is called an *ε*-production. 

It is common to list all right-hand sides for the same left-hand side on the same line, using | (the [pipe symbol](https://en.wikipedia.org/wiki/Pipe_symbol)) to separate them. Rules $ \alpha \rightarrow \beta _{1} $ and $ \alpha \rightarrow \beta _{2} $ can hence be written as $ \alpha \rightarrow \beta _{1}\mid \beta _{2} $. In this case, $ \beta _{1} $ and $ \beta _{2} $ is called the first and second alternative, respectively.

#### Rule application 

For any strings $ u,v\in (V\cup \Sigma )^{*} $, we say *u* directly yields *v*, written as $ u\Rightarrow v\, $, if $ \exists (\alpha ,\beta )\in R $ with $ \alpha \in V $ and $ u_{1},u_{2}\in (V\cup \Sigma )^{*} $ such that $ u\,=u_{1}\alpha u_{2} $ and $ v\,=u_{1}\beta u_{2} $. Thus, *v* is a result of applying the rule $ (\alpha ,\beta ) $ to *u*.

#### Repetitive rule application 

For any strings $ u,v\in (V\cup \Sigma )^{*}, $ we say *u* **yields** *v*, written as $ u{\stackrel {*}{\Rightarrow }}v $ (or $ u\Rightarrow \Rightarrow v\, $ in some textbooks), if $ \exists k\geq 1\,\exists \,u_{1},\cdots ,u_{k}\in (V\cup \Sigma )^{*} $ such that $ u=\,u_{1}\Rightarrow u_{2}\Rightarrow \cdots \Rightarrow u_{k}\,=v $. In this case, if $ k\geq 2 $ (i.e., $ u\neq v $), the relation $ u{\stackrel {+}{\Rightarrow }}v $ holds. In other words, $ ({\stackrel {*}{\Rightarrow }}) $ and $ ({\stackrel {+}{\Rightarrow }}) $ are the [reflexive transitive closure](https://en.wikipedia.org/wiki/Reflexive_transitive_closure) (allowing a word to yield itself) and the [transitive closure](https://en.wikipedia.org/wiki/Transitive_closure) (requiring at least one step) of $ (\Rightarrow ) $, respectively.

#### Context-free language 

The language of a grammar $ G=(V,\Sigma ,R,S) $ is the set

$ L(G)=\{w\in \Sigma ^{*}:S{\stackrel {*}{\Rightarrow }}w\} $

A language *L* is said to be a context-free language (CFL), if there exists a CFG *G*, such that $ L\,=\,L(G) $.

[Non-deterministic pushdown automata](https://en.wikipedia.org/wiki/Pushdown_automaton#PDA_and_context-free_languages) recognize exactly the context-free languages.

#### 对比分析

[Context-free grammar](https://en.wikipedia.org/wiki/Context-free_grammar) 的restriction在于

> The left-hand side of the production rule is always **a** [nonterminal](https://en.wikipedia.org/wiki/Nonterminal) symbol. This means that the symbol does not appear in the resulting formal language. 

在type 1 grammar中，对产生式的左部中[nonterminal](https://en.wikipedia.org/wiki/Nonterminal) symbol的个数并没有限制。



### Type-3 grammars:[Regular grammar formal definition](https://en.wikipedia.org/wiki/Regular_grammar#Strictly_regular_grammars)

A **right regular grammar** (also called [right linear grammar](https://en.wikipedia.org/wiki/Linear_Grammar#Right-Linear_Grammars)) is a [formal grammar](https://en.wikipedia.org/wiki/Formal_grammar) (*N*, Σ, *P*, *S*) such that all the [production rules](https://en.wikipedia.org/wiki/Production_(computer_science)) in *P* are of one of the following forms:

1. *A* → *a*, where *A* is a [non-terminal](https://en.wikipedia.org/wiki/Terminal_and_nonterminal_symbols) in *N* and *a* is a terminal in Σ
2. *A* → *aB*, where *A* and *B* are non-terminals in *N* and *a* is in Σ
3. *A* → ε, where *A* is in *N* and ε denotes the [empty string](https://en.wikipedia.org/wiki/Empty_string), i.e. the string of length 0.

In a **left regular grammar** (also called [left linear grammar](https://en.wikipedia.org/wiki/Linear_Grammar#Left-Linear_Grammars)), all rules obey the forms

1. *A* → *a*, where *A* is a non-terminal in *N* and *a* is a terminal in Σ
2. *A* → *Ba*, where *A* and *B* are in *N* and *a* is in Σ
3. *A* → ε, where *A* is in *N* and ε is the empty string.

A **regular grammar** is a left **or** right regular grammar.

Some textbooks and articles disallow empty production rules, and assume that the empty string is not present in languages.

### 对比分析

与Type-2 grammars相比，Type-3 grammars的限制在于产生式右侧的non-terminal：

-  产生式的右侧最多只能够有一个non-terminal
-  产生式右侧的non-terminal只能够在最左侧或最右侧

显然，与Type-2 grammars相比，由于Type-3 grammar的production的右侧只能够有一个non-terminal，所以在按照它的production进行rewrite（扩展）的时候，只能够向一个方向进行扩展，所以最终的扩展结果只能够是一个线性的结构，所以它是[linear grammar](https://en.wikipedia.org/wiki/Linear_grammar)。而Type-2 grammar的production的右侧可以有多个non-terminal，所以在按照它的production进行rewrite（扩展）的时候，能够向多个方向进行扩展，所以最终的扩展结果是一个树形的结构，所以它不是[linear grammar](https://en.wikipedia.org/wiki/Linear_grammar)。

> NOTE: 描述的结构





### 总结

上述所有grammar的production都可以支持递归，即都可以是[recursive grammar](https://en.wikipedia.org/wiki/Recursive_grammar)。

> NOTE: 描述的递归性

在[Recursively enumerable language](https://en.wikipedia.org/wiki/Recursively_enumerable_language)中有这样的描述：

> All [regular](https://en.wikipedia.org/wiki/Regular_language), [context-free](https://en.wikipedia.org/wiki/Context-free_language), [context-sensitive](https://en.wikipedia.org/wiki/Context-sensitive_language) and [recursive](https://en.wikipedia.org/wiki/Recursive_language) languages are recursively enumerable.



### 对比分析By automaton

CFG的 automaton是pushdown automaton，我们知道pushdown automaton本质上来说就是stack，CFG本质上来说表示的是hierarchy结构/树形结构。
