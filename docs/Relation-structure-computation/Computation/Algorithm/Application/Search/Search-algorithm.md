# Search algorithm

“search”是一个非常宏大的主题，有时候有这样的感觉：computer science解决很多问题的解法最终都可以归入search的范轴。

## 维基百科[Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm)

> NOTE: 这篇文章对search algorithm的描述是非常好的，尤其是对问题的分类

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **search algorithm** is any [algorithm](https://en.wikipedia.org/wiki/Algorithm) which solves the [search problem](https://en.wikipedia.org/wiki/Search_problem), namely, to retrieve information stored within some data structure, or calculated in the [search space](https://en.wikipedia.org/wiki/Feasible_region)（可行域、解空间） of a [problem domain](https://en.wikipedia.org/wiki/Problem_domain), either with [discrete or continuous values](https://en.wikipedia.org/wiki/Continuous_or_discrete_variable). Specific applications of search algorithms include:

- Problems in  [combinatorial optimization](https://en.wikipedia.org/wiki/Combinatorial_optimization) , such as:

  - The [vehicle routing problem](https://en.wikipedia.org/wiki/Vehicle_routing_problem), a form of [shortest path problem](https://en.wikipedia.org/wiki/Shortest_path_problem) 

    > NOTE: 汽车路径安排问题，这是一种“最短路径问题”

  - The [knapsack problem](https://en.wikipedia.org/wiki/Knapsack_problem): Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible.

  - The [nurse scheduling problem](https://en.wikipedia.org/wiki/Nurse_scheduling_problem)

- Problems in [constraint satisfaction](https://en.wikipedia.org/wiki/Constraint_satisfaction_problem), such as:

  - The [map coloring problem](https://en.wikipedia.org/wiki/Map_coloring_problem)
  
- Filling in a [sudoku](https://en.wikipedia.org/wiki/Sudoku) or [crossword puzzle](https://en.wikipedia.org/wiki/Crossword_puzzle)
  
- In [game theory](https://en.wikipedia.org/wiki/Game_theory) and especially [combinatorial game theory](https://en.wikipedia.org/wiki/Combinatorial_game_theory), choosing the best move to make next (such as with the [minmax](https://en.wikipedia.org/wiki/Minmax) algorithm)

- Finding a combination or password from the whole set of possibilities

- [Factoring](https://en.wikipedia.org/wiki/Factorization) an integer (an important problem in [cryptography](https://en.wikipedia.org/wiki/Cryptography))

  > NOTE: 分解一个integer

- Optimizing an industrial process, such as a [chemical reaction](https://en.wikipedia.org/wiki/Chemical_reaction), by changing the parameters of the process (like temperature, pressure, and pH)

- Retrieving a record from a [database](https://en.wikipedia.org/wiki/Database)

- Finding the maximum or minimum value in a [list](https://en.wikipedia.org/wiki/List_(abstract_data_type)) or [array](https://en.wikipedia.org/wiki/Array_data_structure)

- Checking to see if a given value is present in a set of values



The classic search problems described above and [web search](https://en.wikipedia.org/wiki/Web_search) are both problems in [information retrieval](https://en.wikipedia.org/wiki/Information_retrieval), but are generally studied as separate subfields and are solved and evaluated differently. are generally focused on filtering and that find documents most relevant to human queries. Classic search algorithms are typically evaluated on how fast they can find a solution, and whether or not that solution is guaranteed to be optimal. Though **information retrieval algorithms** must be fast, the quality of ranking is more important, as is whether or not good results have been left out and bad results included.

> NOTE: search是一个非常大的概念

The appropriate search algorithm often depends on the **data structure** being searched, and may also include **prior knowledge** about the data. Some database structures are specially constructed to make search algorithms faster or more efficient, such as a [search tree](https://en.wikipedia.org/wiki/Search_tree), [hash map](https://en.wikipedia.org/wiki/Hash_map), or a [database index](https://en.wikipedia.org/wiki/Database_index). [[1\]](https://en.wikipedia.org/wiki/Search_algorithm#cite_note-FOOTNOTEBeameFich200239-1)[[2\]](https://en.wikipedia.org/wiki/Search_algorithm#cite_note-FOOTNOTEKnuth1998§6.5_("Retrieval_on_Secondary_Keys")-2)

> NOTE: 选择合适的data structure组织数据来使search的time最优

**Search algorithms** can be classified based on their mechanism of searching. [Linear search](https://en.wikipedia.org/wiki/Linear_search) algorithms check every record for the one associated with a target key in a linear fashion.[[3\]](https://en.wikipedia.org/wiki/Search_algorithm#cite_note-FOOTNOTEKnuth1998§6.1_("Sequential_Searching")-3) [Binary, or half interval searches](https://en.wikipedia.org/wiki/Binary_search_algorithm), repeatedly target the center of the search structure and divide the search space in half. Comparison search algorithms improve on linear searching by successively eliminating records based on comparisons of the keys until the target record is found, and can be applied on data structures with a defined order.[[4\]](https://en.wikipedia.org/wiki/Search_algorithm#cite_note-FOOTNOTEKnuth1998§6.2_("Searching_by_Comparison_of_Keys")-4) Digital search algorithms work based on the properties of digits in data structures that use numerical keys.[[5\]](https://en.wikipedia.org/wiki/Search_algorithm#cite_note-FOOTNOTEKnuth1998§6.3_(Digital_Searching)-5) Finally, [hashing](https://en.wikipedia.org/wiki/Hash_table) directly maps keys to records based on a [hash function](https://en.wikipedia.org/wiki/Hash_function).[[6\]](https://en.wikipedia.org/wiki/Search_algorithm#cite_note-FOOTNOTEKnuth1998§6.4,_(Hashing)-6) Searches outside a linear search require that the data be sorted in some way.

> NOTE: “**Search algorithms** can be classified based on their mechanism of searching”，我们将“mechanism of searching”称为“method of search”，后面我们将看到“method of search”是非常之多的，绝不将就上述列举的几种



Algorithms are often evaluated by their [computational complexity](https://en.wikipedia.org/wiki/Computational_complexity), or maximum theoretical run time. Binary search functions, for example, have a maximum complexity of *O*(log *n*), or logarithmic time. This means that the maximum number of operations needed to find the search target is a logarithmic function of the size of the **search space**.

> NOTE: 最后一句提及的search space的概念非常重要。

### Classes



> NOTE : [Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm)的一个主要问题就是确定[search space](https://en.wikipedia.org/wiki/Feasible_region)，本文中[search space](https://en.wikipedia.org/wiki/Feasible_region)所链接的文章所描述的其实是可行域，可行域的含义可能有些限制，但是也可以用；**search space**可能是virtual spaces（如backtracing在解空间中搜索）也可能是的确存在一个data structure（如二分搜索在一个sorted array中进行搜索）；正如下面会进行分类：
>
> - For virtual search spaces
> - For sub-structures of a given structure
> - Search for the maximum of a function



#### For virtual search spaces

Algorithms for searching **virtual spaces** are used in the [constraint satisfaction problem](https://en.wikipedia.org/wiki/Constraint_satisfaction_problem), where the goal is to find a set of **value assignments** to certain variables that will satisfy specific mathematical [equations](https://en.wikipedia.org/wiki/Equation) and [inequations](https://en.wikipedia.org/wiki/Inequation) / equalities. They are also used when the goal is to find a **variable assignment** that will [maximize or minimize](https://en.wikipedia.org/wiki/Discrete_optimization) a certain function of those variables. Algorithms for these problems include the basic [brute-force search](https://en.wikipedia.org/wiki/Brute-force_search)(also called "naïve" or "uninformed" search), and a variety of [heuristics](https://en.wikipedia.org/wiki/Heuristic_function) that try to exploit partial knowledge about the structure of this space, such as linear relaxation, constraint generation, and [constraint propagation](https://en.wikipedia.org/wiki/Local_consistency).

> NOTE: blind search VS heuristic search

An important subclass are the [local search](https://en.wikipedia.org/wiki/Local_search_(optimization)) methods, that view the **elements** of the **search space** as the [vertices](https://en.wikipedia.org/wiki/Vertex_(graph_theory))（点） of a graph, with edges defined by a set of heuristics applicable to the case; and scan the space by moving from item to item along the edges, for example according to the [steepest descent](https://en.wikipedia.org/wiki/Gradient_descent) or [best-first](https://en.wikipedia.org/wiki/Best-first_search) criterion, or in a [stochastic search](https://en.wikipedia.org/wiki/Stochastic_optimization). This category includes a great variety of general [metaheuristic](https://en.wikipedia.org/wiki/Metaheuristic) methods, such as [simulated annealing](https://en.wikipedia.org/wiki/Simulated_annealing), [tabu search](https://en.wikipedia.org/wiki/Tabu_search), A-teams, and [genetic programming](https://en.wikipedia.org/wiki/Genetic_programming), that combine arbitrary heuristics in specific ways.

This class also includes various [tree search algorithms](https://en.wikipedia.org/wiki/Tree_traversal), that view the **elements** as vertices of a [tree](https://en.wikipedia.org/wiki/Tree_(graph_theory)), and traverse that tree in some special order. Examples of the latter include the exhaustive methods such as [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search) and [breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search), as well as various heuristic-based [search tree pruning](https://en.wikipedia.org/wiki/Pruning_(decision_trees)) methods such as [backtracking](https://en.wikipedia.org/wiki/Backtracking) and [branch and bound](https://en.wikipedia.org/wiki/Branch_and_bound). Unlike general metaheuristics, which at best work only in a probabilistic sense, many of these tree-search methods are guaranteed to find the exact or optimal solution, if given enough time. This is called "[completeness](https://en.wikipedia.org/wiki/Completeness_(logic))".

> NOTE: graph search（tree search也包括在其中，因为tree是一种特殊的graph），后面会进行专门的介绍。graph search是非常重要，因为virtual search space也可以转换为graph search。

Another important sub-class consists of algorithms for exploring the [game tree](https://en.wikipedia.org/wiki/Game_tree) of multiple-player games, such as [chess](https://en.wikipedia.org/wiki/Chess) or [backgammon](https://en.wikipedia.org/wiki/Backgammon)（双陆棋）, whose nodes consist of all possible game situations that could result from the current situation. The goal in these problems is to find the move that provides the best chance of a win, taking into account all possible moves of the opponent(s). Similar problems occur when humans or machines have to make successive decisions whose outcomes are not entirely under one's control, such as in [robot](https://en.wikipedia.org/wiki/Robot) guidance or in [marketing](https://en.wikipedia.org/wiki/Marketing), [financial](https://en.wikipedia.org/wiki/Finance), or [military](https://en.wikipedia.org/wiki/Military)strategy planning. This kind of problem — [combinatorial search](https://en.wikipedia.org/wiki/Combinatorial_search)（组合搜索） — has been extensively studied in the context of [artificial intelligence](https://en.wikipedia.org/wiki/Artificial_intelligence). Examples of algorithms for this class are the [minimax algorithm](https://en.wikipedia.org/wiki/Minimax), [alpha–beta pruning](https://en.wikipedia.org/wiki/Alpha–beta_pruning), * Informational search [[7\]](https://en.wikipedia.org/wiki/Search_algorithm#cite_note-7) and the [A* algorithm](https://en.wikipedia.org/wiki/A*_search_algorithm).



#### For sub-structures of a given structure

The name "combinatorial search"（组合搜索） is generally used for algorithms that look for a specific sub-structure of a given [discrete structure](https://en.wikipedia.org/wiki/Discrete_mathematics), such as a graph, a [string](https://en.wikipedia.org/wiki/String_(computer_science)), a finite [group](https://en.wikipedia.org/wiki/Group_(mathematics)), and so on. The term [combinatorial optimization](https://en.wikipedia.org/wiki/Combinatorial_optimization) is typically used when the goal is to find a **sub-structure** with a maximum (or minimum) value of some parameter. (Since the sub-structure is usually represented in the computer by a set of integer variables with constraints, these problems can be viewed as special cases of constraint satisfaction or discrete optimization; but they are usually formulated and solved in a more abstract setting where the internal representation is not explicitly mentioned.)

> NOTE: 这让我想起来[Optimal substructure](https://en.wikipedia.org/wiki/Optimal_substructure)

An important and extensively studied subclass are the [graph algorithms](https://en.wikipedia.org/wiki/List_of_algorithms#Graph_algorithms), in particular [graph traversal](https://en.wikipedia.org/wiki/Graph_traversal) algorithms, for finding specific sub-structures in a given graph — such as [subgraphs](https://en.wikipedia.org/wiki/Glossary_of_graph_theory#Subgraphs), [paths](https://en.wikipedia.org/wiki/Path_(graph_theory)), circuits, and so on. Examples include [Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm), [Kruskal's algorithm](https://en.wikipedia.org/wiki/Kruskal's_algorithm), the [nearest neighbour algorithm](https://en.wikipedia.org/wiki/Nearest_neighbour_algorithm), and [Prim's algorithm](https://en.wikipedia.org/wiki/Prim's_algorithm).

Another important subclass of this category are the [string searching algorithms](https://en.wikipedia.org/wiki/String_searching_algorithm), that search for patterns within strings. Two famous examples are the [Boyer–Moore](https://en.wikipedia.org/wiki/Boyer–Moore_string_search_algorithm) and [Knuth–Morris–Pratt algorithms](https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm), and several algorithms based on the [suffix tree](https://en.wikipedia.org/wiki/Suffix_tree) data structure.



#### Search for the maximum of a function

In 1953, American [statistician](https://en.wikipedia.org/wiki/Statistics) [Jack Kiefer](https://en.wikipedia.org/wiki/Jack_Kiefer_(statistician)) devised [Fibonacci search](https://en.wikipedia.org/wiki/Fibonacci_search_technique) which can be used to find the maximum of a unimodal（单峰） function and has many other applications in computer science.



#### For quantum computers

There are also search methods designed for [quantum computers](https://en.wikipedia.org/wiki/Quantum_computing), like [Grover's algorithm](https://en.wikipedia.org/wiki/Grover's_algorithm), that are theoretically faster than linear or brute-force search even without the help of data structures or heuristics.





### See also

- [Backward induction](https://en.wikipedia.org/wiki/Backward_induction)
- [Content-addressable memory](https://en.wikipedia.org/wiki/Content-addressable_memory) hardware
- [Dual-phase evolution](https://en.wikipedia.org/wiki/Dual-phase_evolution)
- [Linear search problem](https://en.wikipedia.org/wiki/Linear_search_problem)
- [No free lunch in search and optimization](https://en.wikipedia.org/wiki/No_free_lunch_in_search_and_optimization)
- [Recommender system](https://en.wikipedia.org/wiki/Recommender_system), also use statistical methods to rank results in very large data sets
- [Search engine (computing)](https://en.wikipedia.org/wiki/Search_engine_(computing))
- [Search game](https://en.wikipedia.org/wiki/Search_game)
- [Selection algorithm](https://en.wikipedia.org/wiki/Selection_algorithm)
- [Solver](https://en.wikipedia.org/wiki/Solver)
- [Sorting algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm) – An algorithm that arranges lists in order, necessary for executing certain search algorithms
- [Web search engine](https://en.wikipedia.org/wiki/Web_search_engine) – Software system that is designed to search for information on the World Wide Web

Categories:

- [Category:Search algorithms](https://en.wikipedia.org/wiki/Category:Search_algorithms)



## [Graph](https://en.wikipedia.org/wiki/Graph_traversal) **and** [tree search algorithms](https://en.wikipedia.org/wiki/Tree_traversal)

这部分内容在工程[data-structure](https://dengking.github.io/data-structure/)的graph章节进行了描述。



## Optimization algorithm and search algorithm

使用各种各样的[Optimization algorithm](https://en.wikipedia.org/wiki/Optimization_algorithm)来实现[Optimization](https://en.wikipedia.org/wiki/Mathematical_optimization)问题，其实其过程也可以看做是[Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm)，比如[Gradient descent](https://en.wikipedia.org/wiki/Gradient_descent)就是一个典型的例子，下面是说明此观点的素材：

[如何直观地解释 backpropagation 算法？ - Anonymous的回答 - 知乎]( https://www.zhihu.com/question/27239198/answer/89853077)中有这样的说明：

> 梯度下降法需要给定一个初始点，并求出该点的梯度向量，然后以负梯度方向为搜索方向，以一定的步长进行搜索，从而确定下一个迭代点，再计算该新的梯度方向，如此重复直到cost收敛。