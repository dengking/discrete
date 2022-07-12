# Optimal substructure

## 以"结构化思维"来看到substructure 

"substructure"的"sub"提升了我们它对应的是"nest、contain关系"。

最优子结构其实就具备递归性质：全问题的最优解蕴含着子问题的最优解。

所以我们即可以自顶向下来运用递归关系也可以自底向上来运用递归关系。动态规划就是自底向上的。

## labuladong [动态规划详解](https://mp.weixin.qq.com/s/Cw39C9MY9Wr2JlcvBQZMcA) # 二、凑零钱问题

其中给出了非常好的解释:

一、使用了高考刺成绩的例子

二、强调了 "子问题相互独立"

## wikipedia [Optimal substructure](https://en.wikipedia.org/wiki/Optimal_substructure)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a problem is said to have **optimal substructure** if an optimal solution can be constructed from optimal solutions of its subproblems. This property is used to determine the usefulness of **dynamic programming** and **greedy algorithms** for a problem.[[1\]](https://en.wikipedia.org/wiki/Optimal_substructure#cite_note-cormen-1)

> NOTE: 
>
> 1、optimal substructure其实也体现了[递归关系](https://en.wikipedia.org/wiki/Recursion)；
>
> 2、原问题 和 子问题

Typically, a [greedy algorithm](https://en.wikipedia.org/wiki/Greedy_algorithm) is used to solve a problem with optimal substructure if it can be proven by induction that this is optimal at each step.[[1\]](https://en.wikipedia.org/wiki/Optimal_substructure#cite_note-cormen-1) Otherwise, provided the problem exhibits [overlapping subproblems](https://en.wikipedia.org/wiki/Overlapping_subproblem) as well, [dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming) is used. If there are no appropriate greedy algorithms and the problem fails to exhibit overlapping subproblems, often a lengthy but straightforward search of the solution space is the best alternative（使用搜索算法）.

In the application of [dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming) to [mathematical optimization](https://en.wikipedia.org/wiki/Optimization_(mathematics)), [Richard Bellman](https://en.wikipedia.org/wiki/Richard_Bellman)'s [Principle of Optimality](https://en.wikipedia.org/wiki/Principle_of_optimality) is based on the idea that in order to solve a dynamic optimization problem from some starting period *t* to some ending period *T*, one implicitly has to solve subproblems starting from later dates *s*, where *t<s<T*. This is an example of **optimal substructure**. The **Principle of Optimality** is used to derive the [Bellman equation](https://en.wikipedia.org/wiki/Bellman_equation), which shows how the value of the problem starting from *t* is related to the value of the problem starting from *s*.



### Problems with optimal substructure

1、[Longest common subsequence problem](https://en.wikipedia.org/wiki/Longest_common_subsequence_problem)

2、[Longest increasing subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence)

3、[Longest palindromic substring](https://en.wikipedia.org/wiki/Longest_palindromic_substring)

4、[All-Pairs Shortest Path](https://en.wikipedia.org/wiki/Shortest_path_problem#All-pairs_shortest_paths)

5、Any problem that can be solved by [dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming).

### Problems *without* optimal substructure

1、[Longest path problem](https://en.wikipedia.org/wiki/Longest_path_problem)

2、**Least-cost airline fare.** (Using online flight search, we will frequently find that the cheapest flight from airport A to airport B involves a single connection through airport C, but the cheapest flight from airport A to airport C involves a connection through some other airport D.)



## Example

理解  [optimal substructure](https://en.wikipedia.org/wiki/Optimal_substructure) 的最好的例子是 graph shortest path，在wikipedia [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm) 中就提及了此。