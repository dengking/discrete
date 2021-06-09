# Branch and bound 

"Branch and bound" 一般翻译为 "分支限界法"；

在下面章节中，也对"Branch and bound"进行了讨论:

一、`Expert-labuladong\3.2-BFS算法系列`



## wikipedia [Branch and bound](https://en.wikipedia.org/wiki/Branch_and_bound)

**Branch and bound** (**BB**, **B&B**, or **BnB**) is an [algorithm](https://en.wanweibaike.com/wiki-Algorithm) [design paradigm](https://en.wanweibaike.com/wiki-Algorithmic_paradigm) for [discrete](https://en.wanweibaike.com/wiki-Discrete_optimization) and [combinatorial optimization](https://en.wanweibaike.com/wiki-Combinatorial_optimization) problems, as well as [mathematical optimization](https://en.wanweibaike.com/wiki-Mathematical_optimization). A branch-and-bound algorithm consists of a systematic enumeration of candidate solutions by means of [state space search](https://en.wanweibaike.com/wiki-State_space_search): the set of candidate solutions is thought of as forming a [rooted tree](https://en.wanweibaike.com/wiki-Tree_(graph_theory)) with the full set at the root. The algorithm explores *branches*(分支) of this tree, which represent subsets of the solution set. Before enumerating the candidate solutions of a branch, the branch is checked against upper and lower estimated *bounds*(上下界限) on the optimal solution, and is discarded if it cannot produce a better solution than the best one found so far by the algorithm.



The algorithm depends on efficient estimation of the lower and upper bounds of regions/branches of the search space. If no bounds are available, the algorithm degenerates to an exhaustive search.