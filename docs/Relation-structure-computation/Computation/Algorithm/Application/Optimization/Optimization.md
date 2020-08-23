# Optimization

在computer science中，optimization是一类非常重要的问题。从wikipedia [Mathematical optimization](https://en.wikipedia.org/wiki/Mathematical_optimization)的内容可知，optimization是一个非常宏大的问题。作为software engineer，我们需要关注的是algorithm implementation。

## wikipedia [Mathematical optimization](https://en.wikipedia.org/wiki/Mathematical_optimization)

**Mathematical optimization** (alternatively spelled *optimisation*) or **mathematical programming** is the selection of a best element (with regard to some criterion) from some set of available alternatives.[[1\]](https://en.wikipedia.org/wiki/Mathematical_optimization#cite_note-1) Optimization problems of sorts arise in all quantitative disciplines from [computer science](https://en.wikipedia.org/wiki/Computer_science) and [engineering](https://en.wikipedia.org/wiki/Engineering) to [operations research](https://en.wikipedia.org/wiki/Operations_research) and [economics](https://en.wikipedia.org/wiki/Economics), and the development of solution methods has been of interest in [mathematics](https://en.wikipedia.org/wiki/Mathematics) for centuries.[[2\]](https://en.wikipedia.org/wiki/Mathematical_optimization#cite_note-2)

In the simplest case, an [optimization problem](https://en.wikipedia.org/wiki/Optimization_problem) consists of [maximizing or minimizing](https://en.wikipedia.org/wiki/Maxima_and_minima) a [real function](https://en.wikipedia.org/wiki/Function_of_a_real_variable) by systematically choosing [input](https://en.wikipedia.org/wiki/Argument_of_a_function) values from within an allowed set and computing the [value](https://en.wikipedia.org/wiki/Value_(mathematics)) of the function. The generalization of optimization theory and techniques to other formulations constitutes a large area of [applied mathematics](https://en.wikipedia.org/wiki/Applied_mathematics). More generally, optimization includes finding "best available" values of some objective function given a defined [domain](https://en.wikipedia.org/wiki/Domain_of_a_function) (or input), including a variety of different types of objective functions and different types of domains.

### Optimization problems

> NOTE: 原文这一段，主要是参考维基百科 [Optimization problem](https://en.wikipedia.org/wiki/Optimization_problem)

### Computational optimization techniques

> NOTE: 原文这一段描述的是如何使用program来解决optimization问题，这是我们作为programmer需要重点学习的。

To solve problems, researchers may use [algorithms](https://en.wikipedia.org/wiki/Algorithm) that terminate in a finite number of steps, or [iterative methods](https://en.wikipedia.org/wiki/Iterative_method) that converge to a solution (on some specified class of problems), or [heuristics](https://en.wikipedia.org/wiki/Heuristic_algorithm) that may provide approximate solutions to some problems (although their iterates need not converge).

> NOTE: 很多optimization，无法使用program求得最优值，而是求得一个近似值



## Classification of optimization problem

以 wikipedia [Optimization problem](https://en.wikipedia.org/wiki/Optimization_problem) 中描述的分类方法为主，然后补充wikipedia [Mathematical optimization](https://en.wikipedia.org/wiki/Mathematical_optimization) （Optimization**:** [Algorithms](https://en.wikipedia.org/wiki/Optimization_algorithm)**,** [methods](https://en.wikipedia.org/wiki/Iterative_method)**, and** [heuristics](https://en.wikipedia.org/wiki/Heuristic_algorithm) ）中提供的各种更加具体的类别。

### wikipedia [Optimization problem](https://en.wikipedia.org/wiki/Optimization_problem) 

In [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), an **optimization problem** is the [problem](https://en.wikipedia.org/wiki/Computational_problem) of finding the *best* solution from all [feasible solutions](https://en.wikipedia.org/wiki/Feasible_solution). 

Optimization problems can be divided into two categories depending on whether the [variables](https://en.wikipedia.org/wiki/Variable_(mathematics)) are [continuous](https://en.wikipedia.org/wiki/Continuous_variable) or [discrete](https://en.wikipedia.org/wiki/Discrete_variable). 

- An optimization problem with [discrete](https://en.wikipedia.org/wiki/Discrete_mathematics) variables is known as a [discrete optimization](https://en.wikipedia.org/wiki/Discrete_optimization). In a discrete optimization problem, we are looking for an object such as an [integer](https://en.wikipedia.org/wiki/Integer), [permutation](https://en.wikipedia.org/wiki/Permutation) or [graph](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)) from a [countable set](https://en.wikipedia.org/wiki/Countable_set). 
- A problem with continuous variables is known as a *[continuous optimization](https://en.wikipedia.org/wiki/Continuous_optimization)*, in which an optimal value from a [continuous function](https://en.wikipedia.org/wiki/Continuous_function) must be found. They can include [constrained problems](https://en.wikipedia.org/wiki/Constrained_optimization) and multimodal problems.

> NOTE: 在数学中，根据discrete、continuous来进行分类的方式普遍存在，比如：
>
> 

#### Continuous optimization problem

The *standard form* of a [continuous](https://en.wikipedia.org/wiki/Continuity_(mathematics)) optimization problem is[[1\]](https://en.wikipedia.org/wiki/Optimization_problem#cite_note-1)

where

- $ f:\mathbb {R} ^{n}\to \mathbb {R} $ is the **objective function** to be minimized over the *n*-variable vector $ x $,
- $ g_{i}(x)\leq 0 $ are called **inequality constraints**
- $ h_{j}(x)=0 $ are called **equality constraints**, and
- $ m\geq 0\ and\ p\geq 0 $.

If $ m $ and $ p $ equal 0, the problem is an unconstrained optimization problem. By convention, the standard form defines a **minimization problem**. A **maximization problem** can be treated by [negating](https://en.wikipedia.org/wiki/Additive_inverse) the objective function.

#### Combinatorial optimization problem

Main article: [Combinatorial optimization](https://en.wikipedia.org/wiki/Combinatorial_optimization)

Formally, a [combinatorial optimization](https://en.wikipedia.org/wiki/Combinatorial_optimization) problem $ A $ is a quadruple[*citation needed*] $ (I,f,m,g) $, where

- $ I $ is a [set](https://en.wikipedia.org/wiki/Set_(mathematics)) of instances;
- given an instance $ x\in I $, $ f(x) $ is the set of feasible solutions;
- given an instance $ x $ and a feasible solution $ y $ of $ x $, $ m(x,y) $ denotes the [measure](https://en.wikipedia.org/wiki/Measure_(mathematics)) of $ y $, which is usually a [positive](https://en.wikipedia.org/wiki/Positive_(mathematics)) [real](https://en.wikipedia.org/wiki/Real_number).
- $ g $ is the goal function, and is either $ \min $ or $ \max $.

The goal is then to find for some instance $ x $ an *optimal solution*, that is, a feasible solution $ y $ with
$$
m(x,y)=g{\bigl \{}m(x,y')\mid y'\in f(x){\bigr \}}
$$
For each combinatorial optimization problem, there is a corresponding [decision problem](https://en.wikipedia.org/wiki/Decision_problem) that asks whether there is a feasible solution for some particular measure $ m_{0} $. For example, if there is a [graph](https://en.wikipedia.org/wiki/Graph_(discrete_mathematics)) $ G $ which contains vertices $ u $ and $ v $, an optimization problem might be "find a path from $ u $ to $ v $ that uses the fewest edges". This problem might have an answer of, say, 4. A corresponding decision problem would be "is there a path from $ u $ to $ v $ that uses 10 or fewer edges?" This problem can be answered with a simple 'yes' or 'no'.



### Summary

| 类别                               |                                                              | 子类别                                                       | 方法论                                             |
| ---------------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | -------------------------------------------------- |
| Continuous optimization problem    | - 维基百科 [Continuous optimization](https://en.wikipedia.org/wiki/Continuous_optimization) | - [Unconstrained nonlinear](https://en.wikipedia.org/wiki/Nonlinear_programming) <br>- [Constrained nonlinear](https://en.wikipedia.org/wiki/Nonlinear_programming) <br>- [Convex optimization](https://en.wikipedia.org/wiki/Convex_optimization) <br> | 比较典型的有: <br/>- Iterative method              |
| Combinatorial optimization problem | - 维基百科 [Discrete optimization](https://en.wikipedia.org/wiki/Discrete_optimization) <br>- 维基百科 [Combinatorial optimization](https://en.wikipedia.org/wiki/Combinatorial_optimization) |                                                              | 比较典型的有: <br>- relation-based algorithm model |

一般，在实践中， 上述两种类别的optimization problem采用的是不同的计算方法。