# Induction

"induction"即归纳，我觉得它所描述的是一种推广。本文对它进行分析。

## 维基百科[Mathematical induction](https://en.wikipedia.org/wiki/Mathematical_induction)

数学归纳法

**Mathematical induction** is a [mathematical proof](https://en.wikipedia.org/wiki/Mathematical_proof) technique. It is essentially used to prove that a property *P*(*n*) holds for every [natural number](https://en.wikipedia.org/wiki/Natural_number) *n*, i.e. for *n* = 0, 1, 2, 3, and so on. Metaphors can be informally used to understand the concept of mathematical induction, such as the metaphor of falling dominoes（多米诺骨牌） or climbing a ladder（梯子）.

The method of induction requires two cases to be proved. The first case, called the **base case** (or, sometimes, the **basis**), proves that the property holds for the number 0. The second case, called the **induction step**, proves that if the property holds for one natural number `n`,  then it holds for the next natural number `n+1`. These two steps establish the property `P(n)` for every natural number n=0,1,2,3...

The method can be extended to prove statements about more general [well-founded](https://en.wikipedia.org/wiki/Well-founded) structures, such as [trees](https://en.wikipedia.org/wiki/Tree_(set_theory)); this generalization, known as [structural induction](https://en.wikipedia.org/wiki/Structural_induction), is used in [mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic) and [computer science](https://en.wikipedia.org/wiki/Computer_science). Mathematical induction in this extended sense is closely related to [recursion](https://en.wikipedia.org/wiki/Recursion). Mathematical induction, in some form, is the foundation of all [correctness proofs for computer programs](https://en.wikipedia.org/wiki/Formal_verification).

对于软件工程师而言，碰到的更多的是 [structural induction](https://en.wikipedia.org/wiki/Structural_induction)。

## 维基百科[Structural induction](https://en.wikipedia.org/wiki/Structural_induction)

> NOTE: 维基百科的这篇文章总结的非常好

**Structural induction** is a [proof method](https://en.wikipedia.org/wiki/Proof_method) that is used in [mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic) (e.g., in the proof of [Łoś' theorem](https://en.wikipedia.org/wiki/Ultraproduct#Łoś'_theorem)), [computer science](https://en.wikipedia.org/wiki/Computer_science), [graph theory](https://en.wikipedia.org/wiki/Graph_theory), and some other mathematical fields. It is a generalization of [mathematical induction over natural numbers](https://en.wikipedia.org/wiki/Mathematical_induction) and can be further generalized to arbitrary [Noetherian induction](https://en.wikipedia.org/wiki/Noetherian_induction). **Structural recursion** is a [recursion](https://en.wikipedia.org/wiki/Recursion) method bearing the same relationship to structural induction as ordinary recursion bears to ordinary [mathematical induction](https://en.wikipedia.org/wiki/Mathematical_induction).

> NOTE: 最后一段话非常重要，它将表达的含义是：structural recursion 和 structural induction 的关系与recursion 和  [mathematical induction](https://en.wikipedia.org/wiki/Mathematical_induction) 的关系 相同。

Structural induction is used to prove that some proposition *P*(*x*) holds [for all](https://en.wikipedia.org/wiki/For_all) *x* of some sort of [recursively defined](https://en.wikipedia.org/wiki/Recursive_definition) structure, such as [formulas](https://en.wikipedia.org/wiki/First-order_logic#Formulas), [lists](https://en.wikipedia.org/wiki/List_(computer_science)), or [trees](https://en.wikipedia.org/wiki/Tree_(graph_theory)). A [well-founded](https://en.wikipedia.org/wiki/Well-founded) [partial order](https://en.wikipedia.org/wiki/Partial_order) is defined on the structures ("subformula" for formulas, "sublist" for lists, and "subtree" for trees). The structural induction proof is a proof that the proposition holds for all the [minimal](https://en.wikipedia.org/wiki/Minimal_element) structures and that if it holds for the immediate substructures of a certain structure *S*, then it must hold for *S* also. (Formally speaking, this then satisfies the premises of an axiom of [well-founded induction](https://en.wikipedia.org/wiki/Well-founded_induction), which asserts that these two conditions are sufficient for the proposition to hold for all *x*.)



A structurally recursive function uses the same idea to define a recursive function: "base cases" handle each minimal structure and a rule for recursion. **Structural recursion** is usually proved correct by **structural induction**; in particularly easy cases, the inductive step is often left out. The *length* and `++` functions in the example below are structurally recursive.

> NOTE: 上面这段话描述了structurally recursive function的实现思路。

> NOTE: 上面这段话也说明了recursion和induction之间的关系：recursion用于计算机实现，induction用于数学证明。



## 维基百科[Transfinite induction](https://en.wikipedia.org/wiki/Transfinite_induction)

“transfinite induction”即“无限归纳”。

