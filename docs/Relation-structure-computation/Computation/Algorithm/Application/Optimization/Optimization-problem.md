

# [Optimization problem](https://en.wikipedia.org/wiki/Optimization_problem)

For broader coverage of this topic, see [Mathematical optimization](https://en.wikipedia.org/wiki/Mathematical_optimization).

In [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), an **optimization problem** is the [problem](https://en.wikipedia.org/wiki/Computational_problem) of finding the *best* solution from all [feasible solutions](https://en.wikipedia.org/wiki/Feasible_solution). Optimization problems can be divided into two categories depending on whether the [variables](https://en.wikipedia.org/wiki/Variable_(mathematics)) are [continuous](https://en.wikipedia.org/wiki/Continuous_variable) or [discrete](https://en.wikipedia.org/wiki/Discrete_variable). An optimization problem with [discrete](https://en.wikipedia.org/wiki/Discrete_mathematics) variables is known as a [discrete optimization](https://en.wikipedia.org/wiki/Discrete_optimization). In a discrete optimization problem, we are looking for an object such as an [integer](https://en.wikipedia.org/wiki/Integer), [permutation](https://en.wikipedia.org/wiki/Permutation) or [graph](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)) from a [countable set](https://en.wikipedia.org/wiki/Countable_set). Problems with continuous variables include constrained problems and multimodal problems.

## Continuous optimization problem

The *standard form* of a [continuous](https://en.wikipedia.org/wiki/Continuity_(mathematics)) optimization problem is[[1\]](https://en.wikipedia.org/wiki/Optimization_problem#cite_note-1)



where

- $ f:\mathbb {R} ^{n}\to \mathbb {R} $ is the **objective function** to be minimized over the *n*-variable vector $ x $,
- $ g_{i}(x)\leq 0 $ are called **inequality constraints**
- $ h_{j}(x)=0 $ are called **equality constraints**, and
- $ m\geq 0\ and\ p\geq 0 $.

If $ m $ and $ p $ equal 0, the problem is an unconstrained optimization problem. By convention, the standard form defines a **minimization problem**. A **maximization problem** can be treated by [negating](https://en.wikipedia.org/wiki/Additive_inverse) the objective function.

## Combinatorial optimization problem

Main article: [Combinatorial optimization](https://en.wikipedia.org/wiki/Combinatorial_optimization)

Formally, a [combinatorial optimization](https://en.wikipedia.org/wiki/Combinatorial_optimization) problem $ A $ is a quadruple[*citation needed*] $ (I,f,m,g) $, where

- $ I $ is a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) of instances;
- given an instance $ x\in I $, $ f(x) $ is the set of feasible solutions;
- given an instance $ x $ and a feasible solution $ y $ of $ x $, $ m(x,y) $ denotes the [measure](https://en.wikipedia.org/wiki/Measure_(mathematics)) of $ y $, which is usually a [positive](https://en.wikipedia.org/wiki/Positive_(mathematics)) [real](https://en.wikipedia.org/wiki/Real_number).
- $ g $ is the goal function, and is either $ \min $ or $ \max $.

The goal is then to find for some instance $ x $ an *optimal solution*, that is, a feasible solution $ y $ with



For each combinatorial optimization problem, there is a corresponding [decision problem](https://en.wikipedia.org/wiki/Decision_problem) that asks whether there is a feasible solution for some particular measure $ m_{0} $. For example, if there is a [graph](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)) $ G $ which contains vertices $ u $ and $ v $, an optimization problem might be "find a path from $ u $ to $ v $ that uses the fewest edges". This problem might have an answer of, say, 4. A corresponding decision problem would be "is there a path from $ u $ to $ v $ that uses 10 or fewer edges?" This problem can be answered with a simple 'yes' or 'no'.

In the field of [approximation algorithms](https://en.wikipedia.org/wiki/Approximation_algorithm), algorithms are designed to find near-optimal solutions to hard problems. The usual decision version is then an inadequate definition of the problem since it only specifies acceptable solutions. Even though we could introduce suitable decision problems, the problem is more naturally characterized as an optimization problem.[[2\]](https://en.wikipedia.org/wiki/Optimization_problem#cite_note-Ausiello03-2)