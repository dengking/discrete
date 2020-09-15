# Backtracking

“backtracking”即“回溯”。

## wikipedia [Backtracking](https://en.wikipedia.org/wiki/Backtracking)

**Backtracking** is a general [algorithm](https://en.wikipedia.org/wiki/Algorithm) for finding all (or some) solutions to some [computational problems](https://en.wikipedia.org/wiki/Computational_problem), notably [constraint satisfaction problems](https://en.wikipedia.org/wiki/Constraint_satisfaction_problem), that incrementally builds **candidates** to the solutions, and abandons a candidate ("backtracks") as soon as it determines that the candidate cannot possibly be completed to a valid solution.[[1\]](https://en.wikipedia.org/wiki/Backtracking#cite_note-1)[[2\]](https://en.wikipedia.org/wiki/Backtracking#cite_note-2)

> NOTE: 上面这段话的最后一句，就点明了backtrack的含义所在，非常精准。



Backtracking can be applied only for problems which admit the concept of a "partial candidate solution" and a relatively quick test of whether it can possibly be completed to a valid solution. It is useless, for example, for locating a given value in an unordered table. When it is applicable, however, backtracking is often much faster than [brute force enumeration](https://en.wikipedia.org/wiki/Brute_force_search) of all complete candidates, since it can eliminate（消除） many candidates with a single test.

> NOTE : 上面这段话说明了可以使用backtrack解决的问题
>
> [Backtracking](https://en.wikipedia.org/wiki/Backtracking) VS  [brute force enumeration](https://en.wikipedia.org/wiki/Brute_force_search) 

Backtracking is an important tool for solving [constraint satisfaction problems](https://en.wikipedia.org/wiki/Constraint_satisfaction_problem),[[3\]](https://en.wikipedia.org/wiki/Backtracking#cite_note-BiereHeule2009-3) such as [crosswords](https://en.wikipedia.org/wiki/Crosswords), [verbal arithmetic](https://en.wikipedia.org/wiki/Verbal_arithmetic), [Sudoku](https://en.wikipedia.org/wiki/Algorithmics_of_sudoku), and many other puzzles. It is often the most convenient (if not the most efficient[*citation needed*]) technique for [parsing](https://en.wikipedia.org/wiki/Parsing),[[4\]](https://en.wikipedia.org/wiki/Backtracking#cite_note-Watson2017-4) for the [knapsack problem](https://en.wikipedia.org/wiki/Knapsack_problem) and other [combinatorial optimization](https://en.wikipedia.org/wiki/Combinatorial_optimization) problems. It is also the basis of the so-called [logic programming](https://en.wikipedia.org/wiki/Logic_programming) languages such as [Icon](https://en.wikipedia.org/wiki/Icon_programming_language), [Planner](https://en.wikipedia.org/wiki/Planner_programming_language) and [Prolog](https://en.wikipedia.org/wiki/Prolog).

Backtracking depends on user-given "[black box procedures](https://en.wikipedia.org/wiki/Procedural_parameter)" that define the problem to be solved, the nature of the partial candidates, and how they are extended into complete candidates. It is therefore a [metaheuristic](https://en.wikipedia.org/wiki/Metaheuristic) （元启发）rather than a specific algorithm – although, unlike many other meta-heuristics, it is guaranteed to find all solutions to a finite problem in a bounded amount of time.

> NOTE: 需要注意的是，backtracking是一种算法框架，或者说是一种算法技术，而不是一种专用的算法。





### Description of the method

The **backtracking algorithm** enumerates a set of ***partial candidates*** that, in principle, could be *completed* in various ways to give all the possible solutions to the given problem. The completion is done incrementally, by a sequence of ***candidate extension steps.***



Conceptually, the **partial candidates** are represented as the nodes of a [tree structure](https://en.wikipedia.org/wiki/Tree_structure), the *potential search tree.* Each partial candidate is the parent of the candidates that differ from it by a single **extension step**; the leaves of the tree are the partial candidates that cannot be extended any further.

The **backtracking algorithm** traverses this search tree [recursively](https://en.wikipedia.org/wiki/Recursion_(computer_science)), from the root down, in [depth-first order](https://en.wikipedia.org/wiki/Depth-first_search). At each node *c*, the algorithm checks whether *c* can be completed to a valid solution. If it cannot, the whole sub-tree rooted at *c* is skipped (***pruned***（剪枝）). Otherwise, the algorithm (1) checks whether *c* itself is a valid solution, and if so reports it to the user; and (2) recursively enumerates all sub-trees of *c*. The two tests and the children of each node are defined by user-given procedures.

Therefore, the *actual search tree* that is traversed by the algorithm is only a part of the potential tree. The total cost of the algorithm is the number of nodes of the actual tree times the cost of obtaining and processing each node. This fact should be considered when choosing the potential search tree and implementing the pruning test.



#### Pseudocode

In order to apply **backtracking** to a specific class of problems, one must provide the data *P* for the particular instance of the problem that is to be solved, and six [procedural parameters](https://en.wikipedia.org/wiki/Procedural_parameter), *root*, *reject*, *accept*, *first*, *next*, and *output*. These procedures should take the instance data *P* as a parameter and should do the following:

1. *root*(*P*): return the partial candidate at the root of the search tree.
2. *reject*(*P*,*c*): return *true* only if the partial candidate *c* is not worth completing.
3. *accept*(*P*,*c*): return *true* if *c* is a solution of *P*, and *false* otherwise.
4. *first*(*P*,*c*): generate the first **extension** of candidate *c*.
5. *next*(*P*,*s*): generate the next alternative **extension** of a candidate, after the extension *s*.
6. *output*(*P*,*c*): use the solution *c* of *P*, as appropriate to the application.

The **backtracking algorithm** reduces the problem to the call *bt*(*root*(*P*)), where *bt* is the following recursive procedure:

```pseudocode
procedure bt(c)
  if reject(P,c) then return
  if accept(P,c) then output(P,c)
  s ← first(P,c)
  while s ≠ NULL do
    bt(s)
    s ← next(P,s)
```

#### Usage considerations

The *reject* procedure should be a [boolean-valued function](https://en.wikipedia.org/wiki/Boolean-valued_function) that returns *true* only if it is certain that no possible extension of *c* is a valid solution for *P*. If the procedure cannot reach a definite conclusion, it should return *false*. An incorrect *true* result may cause the *bt* procedure to miss some valid solutions. The procedure may assume that *reject*(*P*,*t*) returned *false* for every ancestor *t* of *c* in the search tree.

On the other hand, the efficiency of the backtracking algorithm depends on *reject* returning *true* for candidates that are as close to the root as possible. If *reject* always returns *false*, the algorithm will still find all solutions, but it will be equivalent to a brute-force search.

The *accept* procedure should return *true* if *c* is a complete and valid solution for the problem instance *P*, and *false* otherwise. It may assume that the partial candidate *c* and all its ancestors in the tree have passed the *reject*test.

The general pseudo-code above does not assume that the valid solutions are always leaves of the potential search tree. In other words, it admits the possibility that a valid solution for *P* can be further extended to yield other valid solutions.

The *first* and *next* procedures are used by the backtracking algorithm to enumerate the children of a node *c* of the tree, that is, the candidates that differ from *c* by a single extension step. The call *first*(*P*,*c*) should yield the first child of *c*, in some order; and the call *next*(*P*,*s*) should return the next sibling of node *s*, in that order. Both functions should return a distinctive "NULL" candidate, if the requested child does not exist.

Together, the *root*, *first*, and *next* functions define the set of partial candidates and the potential search tree. They should be chosen so that every solution of *P* occurs somewhere in the tree, and no partial candidate occurs more than once. Moreover, they should admit an efficient and effective *reject* predicate.

### Examples

Examples where backtracking can be used to solve puzzles or problems include:

- [Puzzles](https://en.wikipedia.org/wiki/Puzzle) such as [eight queens puzzle](https://en.wikipedia.org/wiki/Eight_queens_puzzle), [crosswords](https://en.wikipedia.org/wiki/Crosswords), [verbal arithmetic](https://en.wikipedia.org/wiki/Verbal_arithmetic), [Sudoku](https://en.wikipedia.org/wiki/Algorithmics_of_sudoku)[[nb 1\]](https://en.wikipedia.org/wiki/Backtracking#cite_note-6), and [Peg Solitaire](https://en.wikipedia.org/wiki/Peg_solitaire).
- [Combinatorial optimization](https://en.wikipedia.org/wiki/Combinatorial_optimization) problems such as [parsing](https://en.wikipedia.org/wiki/Parsing) and the [knapsack problem](https://en.wikipedia.org/wiki/Knapsack_problem).
- [Logic programming](https://en.wikipedia.org/wiki/Logic_programming) languages such as [Icon](https://en.wikipedia.org/wiki/Icon_programming_language), [Planner](https://en.wikipedia.org/wiki/Planner_programming_language) and [Prolog](https://en.wikipedia.org/wiki/Prolog), which use backtracking internally to generate answers.

The following is an example where backtracking is used for the [constraint satisfaction problem](https://en.wikipedia.org/wiki/Constraint_satisfaction_problem):

#### Constraint satisfaction

The general [constraint satisfaction problem](https://en.wikipedia.org/wiki/Constraint_satisfaction_problem) consists in finding a list of integers *x* = (*x*[1], *x*[2], …, *x*[*n*]), each in some range {1, 2, …, *m*}, that satisfies some arbitrary constraint (boolean function) *F*.

For this class of problems, the instance data *P* would be the integers *m* and *n*, and the predicate *F*. In a typical backtracking solution to this problem, one could define a partial candidate as a list of integers *c* = (*c*[1], *c*[2], …, *c*[k]), for any *k* between 0 and *n*, that are to be assigned to the first *k* variables *x*[1], *x*[2], …, *x*[*k*]. The root candidate would then be the empty list (). The *first* and *next* procedures would then be

```pseudocode
function first(P, c)
  k ← length(c)
  if k = n
    then return NULL
  else return (c[1], c[2], …, c[k], 1)

function next(P, s)
  k ← length(s)
  if s[k] = m
    then return NULL
  else return (s[1], s[2], …, s[k - 1], 1 + s[k])
```

Here *length*(*c*) is the number of elements in the list *c*.

The call *reject*(*P*, *c*) should return *true* if the constraint *F* cannot be satisfied by any list of *n* integers that begins with the *k* elements of *c*. For backtracking to be effective, there must be a way to detect this situation, at least for some candidates *c*, without enumerating all those *m**n* − *k* *n*-tuples.

For example, if *F* is the [conjunction](https://en.wikipedia.org/wiki/Logical_conjunction) of several boolean predicates, *F* = *F*[1] ∧ *F*[2] ∧ … ∧ *F*[*p*], and each *F*[*i*] depends only on a small subset of the variables *x*[1], …, *x*[*n*], then the *reject* procedure could simply check the terms *F*[*i*] that depend only on variables *x*[1], …, *x*[*k*], and return *true* if any of those terms returns *false*. In fact, *reject* needs only check those terms that do depend on *x*[*k*], since the terms that depend only on *x*[1], …, *x*[*k* − 1] will have been tested further up in the search tree.

Assuming that *reject* is implemented as above, then *accept*(*P*, *c*) needs only check whether *c* is complete, that is, whether it has *n* elements.

It is generally better to order the list of variables so that it begins with the most critical ones (i.e. the ones with fewest value options, or which have a greater impact on subsequent choices).

One could also allow the *next* function to choose which variable should be assigned when extending a partial candidate, based on the values of the variables already assigned by it. Further improvements can be obtained by the technique of [constraint propagation](https://en.wikipedia.org/wiki/Constraint_propagation).

In addition to retaining minimal recovery values used in backing up, backtracking implementations commonly keep a variable trail, to record value change history. An efficient implementation will avoid creating a variable trail entry between two successive changes when there is no choice point, as the backtracking will erase all of the changes as a single operation.

An alternative to the variable trail is to keep a [timestamp](https://en.wikipedia.org/wiki/Timestamp) of when the last change was made to the variable. The timestamp is compared to the timestamp of a choice point. If the choice point has an associated time later than that of the variable, it is unnecessary to revert the variable when the choice point is backtracked, as it was changed before the choice point occurred.