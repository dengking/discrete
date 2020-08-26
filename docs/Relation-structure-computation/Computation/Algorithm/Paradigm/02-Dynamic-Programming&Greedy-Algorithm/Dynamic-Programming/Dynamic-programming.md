# [Dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming)

**Dynamic programming** is both a [mathematical optimization](https://en.wikipedia.org/wiki/Mathematical_optimization) method and a computer programming method. The method was developed by [Richard Bellman](https://en.wikipedia.org/wiki/Richard_Bellman) in the 1950s and has found applications in numerous fields, from [aerospace engineering](https://en.wikipedia.org/wiki/Aerospace_engineering)（航天工程） to [economics](https://en.wikipedia.org/wiki/Economics). In both contexts it refers to simplifying a complicated problem by breaking it down into simpler sub-problems in a [recursive](https://en.wikipedia.org/wiki/Recursion) manner. While some **decision problems**（决策问题） cannot be taken apart this way, **decisions** that span several **points** in time do often break apart recursively. Likewise, in computer science, if a problem can be solved optimally by breaking it into sub-problems and then recursively finding the **optimal solutions** to the **sub-problems**, then it is said to have [optimal substructure](https://en.wikipedia.org/wiki/Optimal_substructure)（最优子结构）.

If sub-problems can be nested recursively inside larger problems, so that **dynamic programming** methods are applicable, then there is a **relation** between the value of the larger problem and the values of the sub-problems.[[1\]](https://en.wikipedia.org/wiki/Dynamic_programming#cite_note-:0-1)In the optimization literature this relationship is called the [Bellman equation](https://en.wikipedia.org/wiki/Bellman_equation).

## Overview

### Mathematical optimization

In terms of mathematical optimization, dynamic programming usually refers to simplifying a decision by breaking it down into a sequence of decision steps over time. This is done by defining a sequence of **value functions** *V*1, *V*2, ..., *V**n* taking *y* as an argument representing the **[state](https://en.wikipedia.org/wiki/State_variable)** of the system at times *i* from 1 to *n*. The definition of *V**n*(*y*) is the value obtained in state *y* at the last time *n*. The values *V**i* at earlier times *i* = *n* −1, *n* − 2, ..., 2, 1 can be found by working backwards, using a [recursive](https://en.wikipedia.org/wiki/Recursion) relationship called the [Bellman equation](https://en.wikipedia.org/wiki/Bellman_equation). For *i* = 2, ..., *n*, *V**i*−1 at any state *y* is calculated from *V**i* by maximizing a simple function (usually the sum) of the gain from a decision at time *i* − 1 and the function *V**i* at the new state of the system if this decision is made. Since *V**i* has already been calculated for the needed states, the above operation yields *V**i*−1 for those states. Finally, *V*1 at the initial state of the system is the value of the optimal solution. The optimal values of the decision variables can be recovered, one by one, by tracking back the calculations already performed. 





### Computer programming

There are two key attributes that a problem must have in order for **dynamic programming** to be applicable: [optimal substructure](https://en.wikipedia.org/wiki/Optimal_substructure) and [overlapping sub-problems](https://en.wikipedia.org/wiki/Overlapping_subproblem). If a problem can be solved by combining **optimal solutions** to *non-overlapping* sub-problems, the strategy is called "[divide and conquer](https://en.wikipedia.org/wiki/Divide_and_conquer_algorithm)" instead.[[1\]](https://en.wikipedia.org/wiki/Dynamic_programming#cite_note-:0-1) This is why [merge sort](https://en.wikipedia.org/wiki/Mergesort) and [quick sort](https://en.wikipedia.org/wiki/Quicksort) are not classified as dynamic programming problems.

***SUMMARY*** : sorting并不具备 [overlapping sub-problems](https://en.wikipedia.org/wiki/Overlapping_subproblem)的特性；

*Optimal substructure* means that the solution to a given **optimization problem** can be obtained by the combination of **optimal solutions** to its **sub-problems**. Such **optimal substructures** are usually described by means of [recursion](https://en.wikipedia.org/wiki/Recursion). For example, given a graph *G=(V,E)*, the **shortest path** *p* from a vertex *u* to a vertex *v* exhibits **optimal substructure**: take any intermediate vertex *w* on this shortest path *p*. If *p* is truly the shortest path, then it can be split into sub-paths *p1* from *u* to *w* and *p2* from *w* to *v* such that these, in turn, are indeed the shortest paths between the corresponding vertices (by the simple cut-and-paste argument described in *[Introduction to Algorithms](https://en.wikipedia.org/wiki/Introduction_to_Algorithms)*). Hence, one can easily formulate the solution for finding **shortest paths** in a recursive manner, which is what the [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman–Ford_algorithm) or the [Floyd–Warshall algorithm](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm) does.

*Overlapping* sub-problems means that the space of sub-problems must be small, that is, any recursive algorithm solving the problem should solve the same **sub-problems** over and over, rather than generating new sub-problems. For example, consider the recursive formulation for generating the Fibonacci series: $F_i = F_{i−1} + F_{i−2}$, with base case $F_1 = F_2 = 1$. Then $F_{43} = F_{42} + F_{41}$, and $F_{42} = F_{41} + F_{40}$. Now $F_{41}$ is being solved in the recursive sub-trees of both $F_{43}$ as well as $F_{42}$. Even though the total number of sub-problems is actually small (only 43 of them), we end up solving the same problems over and over if we adopt a naive recursive solution such as this. **Dynamic programming** takes account of this fact and solves each **sub-problem** only once.

[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/0/06/Fibonacci_dynamic_programming.svg/108px-Fibonacci_dynamic_programming.svg.png)](https://en.wikipedia.org/wiki/File:Fibonacci_dynamic_programming.svg)

**Figure 2.**  

This can be achieved in either of two ways:[*[citation needed](https://en.wikipedia.org/wiki/Wikipedia:Citation_needed)*]

- *[Top-down approach](https://en.wikipedia.org/wiki/Top-down_and_bottom-up_design)*: This is the direct fall-out of the recursive formulation of any problem. If the solution to any problem can be formulated recursively using the solution to its sub-problems, and if its sub-problems are overlapping, then one can easily [memoize](https://en.wikipedia.org/wiki/Memoize) or store the solutions to the sub-problems in a table. Whenever we attempt to solve a new sub-problem, we first check the table to see if it is already solved. If a solution has been recorded, we can use it directly, otherwise we solve the sub-problem and add its solution to the table.
- *[Bottom-up approach](https://en.wikipedia.org/wiki/Top-down_and_bottom-up_design)*: Once we formulate the solution to a problem recursively as in terms of its sub-problems, we can try reformulating the problem in a bottom-up fashion: try solving the sub-problems first and use their solutions to build-on and arrive at solutions to bigger sub-problems. This is also usually done in a tabular form by iteratively generating solutions to bigger and bigger sub-problems by using the solutions to small sub-problems. For example, if we already know the values of *F*41 and *F*40, we can directly calculate the value of *F*42.

Some [programming languages](https://en.wikipedia.org/wiki/Programming_language) can automatically [memoize](https://en.wikipedia.org/wiki/Memoization) the result of a function call with a particular set of arguments, in order to speed up [call-by-name](https://en.wikipedia.org/wiki/Call-by-name) evaluation (this mechanism is referred to as *[call-by-need](https://en.wikipedia.org/wiki/Call-by-need)*). Some languages make it possible portably (e.g. [Scheme](https://en.wikipedia.org/wiki/Scheme_(programming_language)), [Common Lisp](https://en.wikipedia.org/wiki/Common_Lisp), [Perl](https://en.wikipedia.org/wiki/Perl) or [D](https://en.wikipedia.org/wiki/D_(programming_language))). Some languages have automatic [memoization](https://en.wikipedia.org/wiki/Memoization) built in, such as tabled [Prolog](https://en.wikipedia.org/wiki/Prolog) and [J](https://en.wikipedia.org/wiki/J_(programming_language)), which supports memoization with the *M.* adverb.[[4\]](https://en.wikipedia.org/wiki/Dynamic_programming#cite_note-4) In any case, this is only possible for a [referentially transparent](https://en.wikipedia.org/wiki/Referential_transparency_(computer_science)) function. Memoization is also encountered as an easily accessible design pattern within term-rewrite based languages such as [Wolfram Language](https://en.wikipedia.org/wiki/Wolfram_Language).



## Examples: Computer algorithms

### Dijkstra's algorithm for the shortest path problem

### Fibonacci sequence

### A type of balanced 0–1 matrix

### Checkerboard

### Sequence alignment

### Tower of Hanoi puzzle

### Egg dropping puzzle

### Matrix chain multiplication

 *Main article:* [Matrix chain multiplication](https://en.wikipedia.org/wiki/Matrix_chain_multiplication) 



## Algorithms that use dynamic programming

- Recurrent solutions to [lattice models](https://en.wikipedia.org/wiki/Lattice_models) for protein-DNA binding
- [Backward induction](https://en.wikipedia.org/wiki/Backward_induction) as a solution method for finite-horizon [discrete-time](https://en.wikipedia.org/wiki/Discrete-time) dynamic optimization problems
- [Method of undetermined coefficients](https://en.wikipedia.org/wiki/Method_of_undetermined_coefficients) can be used to solve the [Bellman equation](https://en.wikipedia.org/wiki/Bellman_equation) in infinite-horizon, discrete-time, [discounted](https://en.wikipedia.org/wiki/Discounting), [time-invariant](https://en.wikipedia.org/wiki/Time-invariant_system) dynamic optimization problems
- Many [string](https://en.wikipedia.org/wiki/String_(computer_science)) algorithms including [longest common subsequence](https://en.wikipedia.org/wiki/Longest_common_subsequence_problem), [longest increasing subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence_problem), [longest common substring](https://en.wikipedia.org/wiki/Longest_common_substring_problem), [Levenshtein distance](https://en.wikipedia.org/wiki/Levenshtein_distance) (edit distance)
- Many algorithmic problems on [graphs](https://en.wikipedia.org/wiki/Undirected_graph) can be solved efficiently for graphs of bounded [treewidth](https://en.wikipedia.org/wiki/Treewidth) or bounded [clique-width](https://en.wikipedia.org/wiki/Clique-width) by using dynamic programming on a [tree decomposition](https://en.wikipedia.org/wiki/Tree_decomposition) of the graph.
- The [Cocke–Younger–Kasami (CYK) algorithm](https://en.wikipedia.org/wiki/CYK_algorithm) which determines whether and how a given string can be generated by a given [context-free grammar](https://en.wikipedia.org/wiki/Context-free_grammar)
- [Knuth's word wrapping algorithm](https://en.wikipedia.org/wiki/Word_wrap) that minimizes raggedness when word wrapping text
- The use of [transposition tables](https://en.wikipedia.org/wiki/Transposition_table) and [refutation tables](https://en.wikipedia.org/wiki/Refutation_table) in [computer chess](https://en.wikipedia.org/wiki/Computer_chess)
- The [Viterbi algorithm](https://en.wikipedia.org/wiki/Viterbi_algorithm) (used for [hidden Markov models](https://en.wikipedia.org/wiki/Hidden_Markov_model), and particularly in [part of speech tagging](https://en.wikipedia.org/wiki/Part_of_speech_tagging))
- The [Earley algorithm](https://en.wikipedia.org/wiki/Earley_algorithm) (a type of [chart parser](https://en.wikipedia.org/wiki/Chart_parser))
- The [Needleman–Wunsch algorithm](https://en.wikipedia.org/wiki/Needleman–Wunsch_algorithm) and other algorithms used in [bioinformatics](https://en.wikipedia.org/wiki/Bioinformatics), including [sequence alignment](https://en.wikipedia.org/wiki/Sequence_alignment), [structural alignment](https://en.wikipedia.org/wiki/Structural_alignment), [RNA structure prediction](https://en.wikipedia.org/wiki/RNA_structure)
- [Floyd's all-pairs shortest path algorithm](https://en.wikipedia.org/wiki/Floyd–Warshall_algorithm)
- Optimizing the order for [chain matrix multiplication](https://en.wikipedia.org/wiki/Chain_matrix_multiplication)
- [Pseudo-polynomial time](https://en.wikipedia.org/wiki/Pseudo-polynomial_time) algorithms for the [subset sum](https://en.wikipedia.org/wiki/Subset_sum_problem), [knapsack](https://en.wikipedia.org/wiki/Knapsack_problem) and [partition](https://en.wikipedia.org/wiki/Partition_problem) problems
- The [dynamic time warping](https://en.wikipedia.org/wiki/Dynamic_time_warping) algorithm for computing the global distance between two time series
- The [Selinger](https://en.wikipedia.org/wiki/Patricia_Selinger) (a.k.a. [System R](https://en.wikipedia.org/wiki/IBM_System_R)) algorithm for relational database query optimization
- [De Boor algorithm](https://en.wikipedia.org/wiki/De_Boor_algorithm) for evaluating B-spline curves
- [Duckworth–Lewis method](https://en.wikipedia.org/wiki/Duckworth–Lewis_method) for resolving the problem when games of cricket are interrupted
- The value iteration method for solving [Markov decision processes](https://en.wikipedia.org/wiki/Markov_decision_process)
- Some graphic image edge following selection methods such as the "magnet" selection tool in [Photoshop](https://en.wikipedia.org/wiki/Photoshop)
- Some methods for solving [interval scheduling](https://en.wikipedia.org/wiki/Interval_scheduling) problems
- Some methods for solving the [travelling salesman problem](https://en.wikipedia.org/wiki/Travelling_salesman_problem), either exactly (in [exponential time](https://en.wikipedia.org/wiki/Exponential_time)) or approximately (e.g. via the [bitonic tour](https://en.wikipedia.org/wiki/Bitonic_tour))
- [Recursive least squares](https://en.wikipedia.org/wiki/Recursive_least_squares) method
- [Beat](https://en.wikipedia.org/wiki/Beat_(music)) tracking in [music information retrieval](https://en.wikipedia.org/wiki/Music_information_retrieval)
- Adaptive-critic training strategy for [artificial neural networks](https://en.wikipedia.org/wiki/Artificial_neural_networks)
- Stereo algorithms for solving the [correspondence problem](https://en.wikipedia.org/wiki/Correspondence_problem) used in stereo vision
- [Seam carving](https://en.wikipedia.org/wiki/Seam_carving) (content-aware image resizing)
- The [Bellman–Ford algorithm](https://en.wikipedia.org/wiki/Bellman–Ford_algorithm) for finding the shortest distance in a graph
- Some approximate solution methods for the [linear search problem](https://en.wikipedia.org/wiki/Linear_search_problem)
- Kadane's algorithm for the [maximum subarray problem](https://en.wikipedia.org/wiki/Maximum_subarray_problem)
- Optimization of electric generation expansion plans in the [Wein Automatic System Planning (WASP)](https://www-pub.iaea.org/MTCD/publications/PDF/CMS-16.pdf) package

## See also

- [Convexity in economics](https://en.wikipedia.org/wiki/Convexity_in_economics)
- [Greedy algorithm](https://en.wikipedia.org/wiki/Greedy_algorithm)
- [Non-convexity (economics)](https://en.wikipedia.org/wiki/Non-convexity_(economics))
- [Stochastic programming](https://en.wikipedia.org/wiki/Stochastic_programming)
- [Stochastic dynamic programming](https://en.wikipedia.org/wiki/Stochastic_dynamic_programming)