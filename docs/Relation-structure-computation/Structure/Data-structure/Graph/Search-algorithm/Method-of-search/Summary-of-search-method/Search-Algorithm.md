# Search Algorithms

## [CSci 4511w: Class Notes on Search](https://www-users.cs.umn.edu/~gini/4511/search)

The description of most of the search algorithms in these notes is taken from J. Pearl, "Heuristics", Addison-Wesley, 1984.

### Important issues about Search Algorithms

We will address:

#### 1. how to write search algorithms. 

In particular we will examine:

- the data structure to keep unexplored nodes. We use a queue (often called a list in many AI books) called ***OPEN***.
- expansion of a node (or generation of its successors). All the successors of a node can be generated at once (method most commonly used) or they could be generated one at a time either in a systematic way or in a random way. The number of successors is called the ***branching factor***.
- strategies for selecting which node to expand next. Different algorithms result from different choices (e.g. **depth-first** when **successor nodes** are added at the **beginning** of the queue, **breadth-first** when **successor nodes** are added at the **end** of the queue, etc),
- test for goal. We will assume the existence of a predicate that applied to a state will return true or false.
- **bookkeeping** (keeping track of visited nodes, keeping track of path to goal, etc). Keeping track of visited nodes is usually done by keeping them in a queue (or, better a hash-table) called ***CLOSED***. This prevents getting trapped into loops or repeating work but results in a large space complexity. This is (most often) necessary when optimal solutions are sought, but can be (mostly) avoided in other cases.
  Keeping track of the path followed is not always necessary (when the problem is to find a **goal state** and knowing how to get there is not important).

> NOTE: 上述过程，非常类似于一个automaton，在工程[compiler-principle](https://dengking.github.io/compiler-principle/)和工程[automata-and-formal-language](https://dengking.github.io/automata-and-formal-language)中有涉及，parsing的过程与上述过程非常类似，需要结合top-down parsing和bottom-up parsing来一起进行理解，另外可以参见维基百科[Pushdown automaton](https://en.wikipedia.org/wiki/Pushdown_automaton)。

#### 2. properties of search algorithms and the solutions they find:

- Termination: the computation is guaranteed to terminate, no matter how large the search space is.

  > NOTE: 保证termination的一种常见情况是：避免loop。下面的“repeated nodes are checked”就是为了避免loop。

- Completeness: an algorithm is complete if it terminates with a solution when one exists.

- Admissibility: an algorithm is admissible if it is guaranteed to return an optimal solution whenever a solution exists.

  > NOTE: Admissibility的意思是“可容许性”。

- Space complexity and Time complexity: how the size of the memory and the time needed to run the algorithm grows depending on **branching factor**, **depth of solution**, **number of nodes**, etc.

Let's briefly examine the properties of some commonly used **uninformed search algorithms**.

#### Depth-First Search

Termination:

guaranteed for a finite space if repeated nodes are checked. Guaranteed when a depth bound（深度界限） is used. Not guaranteed otherwise.

> NOTE: “repeated nodes are checked”就是为了避免“loop”。

Completeness:

not guaranteed in general. Guaranteed if the search space is finite (exhaustive search) and repeated nodes are checked.

Admissibility:

not guaranteed.

#### Breadth-First Search

Termination:

guaranteed for finite space. Guaranteed when a solution exists.

> NOTE: 感觉此处是有问题的：如果存在loop，并且算法没有避免loop，则它无法terminate。

Completeness:

guaranteed.

Admissibility:

the algorithm will always find the shortest path (it might not be the optimal path, if arcs have different costs).

#### Depth-First Search Iterative-Deepening

Termination:

guaranteed for finite space. Guaranteed when a solution exists.

Completeness:

guaranteed.

Admissibility:

the algorithm will always find the shortest path (it might not be the optimal path, if arcs have different costs).



#### 3. classes of search algorithms.

- **uninformed** (depth-first, breadth-first, uniform cost, depth-limited, iterative deepening) versus **informed** (greedy, `A*`, `IDA*`, `SMA*`)

  > NOTE: **uninformed**的中文意思是“无知的”，在本文中，它所表示的是blind search，没有heuristics的

- **local** (greedy, hill-climbing) versus **global** (uniform cost, `A*`, etc)

- **systematic** (depth-first, `A*`, etc) versus **stochastic** (simulated annealing, genetic algorithms)

> NOTE: 
>
> ## 关于pointer的解释
>
> 在下面的各种algorithm中，都会看到**pointer**，原文中，作者并没有对pointer进行解释。根据“Depth-First Search with depth bound”中，我们可以推测得知：
>
> 每个node，都有一个指向它的parent的pointer，简称为**parent pointer**：
>
> ```c++
> 2.2.4 put the successors on top of OPEN and 
>              provide for each a pointer back to n # 每个节点都有一个指向它的上级节点的指针
> ```
>
> 使用parent pointer的原因是为了能够得到完整的solution：
>
> ```c++
> 3. If a goal node is found, 
>    then exit with the solution obtained by tracing back 
>         through its pointers 
> ```
>
> 

### Description of an Uninformed Search Algorithm:

#### Depth-First Search with depth bound

> NOTE: 带深度限制的深度优先搜索

```pseudocode
1. Put the start node on OPEN.
2. until OPEN is empty or a goal node has been reached
   2.1 remove the topmost node from OPEN and put it on CLOSED.  Call this node n.
   2.2 if the depth of n is less than the depth bound 
       then
       2.2.1 expand n, generating all successors (if any).  
       2.2.2 if any of these successors is already on 
             the traversal path discard it
       2.2.3 if any of these successors is a goal node, 
             exit 
       2.2.4 put the successors on top of OPEN and 
             provide for each a pointer back to n # 每个节点都有一个指向它的上级节点的指针
       else
       2.2.5 clean up CLOSED.
3. If a goal node is found, 
   then exit with the solution obtained by tracing back 
        through its pointers 
   else announce failure.
```

> NOTE: 
>
> 上述algorithm中的"2.2.4 put the successors on top of OPEN"对应的是“1. how to write search algorithms“中关于“strategies for selecting which node to expand next”的讨论：
>
> **depth-first** when **successor nodes** are added at the **beginning** of the queue

Notes:

- Nodes that have been expanded (i.e. their successors have been generated) are called **closed**, nodes that were generated and are awaiting expansion are called **open**. Two queues, `CLOSED` and `OPEN` keep track of these two sets of nodes.
- The depth of a node in a graph is defined recursively as 1 + depth of its shallowest parent. The start node has 0 depth.
- If the **depth bound** is less than the **solution depth** the algorithm terminates without finding a solution. If the **depth bound** is greater the algorithm might find a non optimal solution. This can be remedied（弥补） by completing the search to the depth of the last solution found and then returning the best solution.
- To save memory `CLOSED` needs to be cleaned up by keeping in it only the nodes on the current traversal path.

> NOTE: 所搜索的是从start到goal的一条path。
>
> 上述算法其实是backtracking，它使用的是自己维护的stack，即`OPEN`。
>
> 上述算法中，`CLOSED` 仅仅保存的是path，而非所有的已经visit过的node。
>
> 步骤2是一个`while`循环，它会不断执行，直至条件满足。
>
> 步骤2.2.1和步骤2.2.4是需要注意的，它一次性产生所有的successor，并且将所有的successor都入栈，即加入到OPEN中。
>
> 
>
> 步骤2.2.2不理解。



### Description of an Informed Search Algorithm

#### Best-First Search

The term **best-first search** is used in different ways by different authors:

- The Russell and Norvig textbook calls **best-first search** any algorithm that sorts the nodes according to some function and selects the best each time. 

- Judea Pearl has a somewhat different definition of best-first, which is given here. 

The major difference is in the specification of how to handle nodes already seen (Russell and Norvig do not specify what to do) and in when goal test is done (Russell and Norvig in Graph-Search check for goal only on the first element of `OPEN`, Pearl checks as soon as the successors of a node are generated).

> NOTE: 主要差异在于：
>
> - how to handle nodes already seen
> - when goal test is done
>
> 需要注意的是，下面的algorithm采用的是Pearl的。

```pseudocode
1. Put the start node S on OPEN.
2. until OPEN is empty or a goal node has been reached
   2.1 remove from OPEN a node at which f is minimum (break ties arbitrarily) and put it on CLOSED.  Call this node n.
   2.2 expand n, generating all successors (if any).
   2.3 if any of the successors of n is a goal node, exit.
   2.4 for each successor n' of n
       2.4.1 calculate f(n')
       2.4.2 if n' was neither on OPEN nor CLOSED, add it to 
             OPEN.  Attach the cost f(n') to it.
       2.4.3 if n' was already on OPEN or on CLOSED compare
             the new value f(n') with the previously assigned
             value f(n').  If the old value is lower discard 
             the newly generated node.  If the new value is 
             lower, substitute the new node for the old node.  
             If the old node was on CLOSED move it back to 
             OPEN.
3. If a goal node is found, 
   then exit with the solution obtained by tracing back 
        through pointers
   else announce failure.
```

> NOTE:
>
> 上述algorithm中的"2.4.2 if n' was neither on OPEN nor CLOSED, add it to OPEN."对应的是“1. how to write search algorithms“中关于“strategies for selecting which node to expand next”的讨论：
>
> **breadth-first** when **successor nodes** are added at the **end** of the queue

Notes:

- Step 2.3 requires checking if any of the children of the node just expanded is a **goal node**. This allows terminating as soon as a **goal** is found, but the solution returned might have a larger value of `f` than the **optimal solution**. To guarantee an optimal solution we need to use a `f` function that understimates（预测） the cost (as done in `A*`) and to test for goal after a node has been selected for expansion.

  > NOTE: 也就是说，上述algorithm不保证optimal solution

- The computation required to do the tests is (that) step 2.4.3 can be substantial. We could eliminate this step, at the cost of having to maintain duplicate descriptions of identical nodes.

  > NOTE: 步骤2.4.3需要进行大量的计算

- If a lower value has been found for a node `n'` that had already been visited (step 2.4.3) and the old node was on `CLOSED`, instead of moving it back to `OPEN` we could leave it on `CLOSED`, redirect the **pointer** to its **parent node** (so it will point to the new parent on the shorter path), and recompute the `f` values of its descendants. This requires keeping track of descendants of nodes and not only of their parent (so it makes the program more complex to write), but it saves reexpanding nodes that have already been expanded (so it can save time if expansion is an expensive process).

  > NOTE: 对于“If a lower value has been found for a node `n'` that had already been visited (step 2.4.3) and the old node was on `CLOSED`”，上述算法中给出的处理方法是：move it back to `OPEN`.  上面这一段给出了另外一种处理方案：
  >
  > instead of moving it back to `OPEN` we could leave it on `CLOSED`, redirect the pointer to its parent node (so it will point to the new parent on the shorter path), and recompute the `f` values of its descendants
  >
  > 这段话的意思是：对于`n'`，它已经有了lower value，则意味着：有一条cost更低的path通向它；此时已经位于`CLOSED`了，我们可以将它的pointer指向新的path，然后重新计算它的descendants的 `f` values

- In general there are no constraints on the function `f(n)`. Best first always selects for expansion the node with the smallest `f` value, so `f` values must be smaller for better nodes. Also, best-first discards multiple paths leading to the same node and keeps the path with the smallest `f` value.

- Properties of Best-First

  - Completeness:

    guaranteed on finite search spaces

  - Admissibility:
    not guaranteed
  - Time Complexity:
    depends on the accuracy of the heuristic function. See more later under `A*`.
  - Space Complexity:
    O(B to the power of d) where B = branching factor, and d = solution depth

> NOTE: best-first search和[Dijkstra's algorithm](https://en.wikipedia.org/wiki/Dijkstra's_algorithm)是比较类似的

#### `A*`

```c++
1. Put the start node S on OPEN.  Attach to s the cost 
   g(s) = 0.  Initialize CLOSED to the empty queue.  
2. until OPEN is empty or a goal node has been reached
   2.1 remove from OPEN a node at which f is minimum 
       (break ties arbitrarily) and put it on CLOSED.  
       Call this node n.
   2.2 if n is a goal node, exit.
   2.3 expand n, generating all successors (if any).
   2.4 for each successor n' of n
       2.4.1 calculate f(n')= g(n') + h(n')
                            = g(n) + c(n,n') + h(n').
       2.4.2 if n' was neither on OPEN nor CLOSED, add 
             it to OPEN.  Attach the cost f(n') to it.
       2.4.3 if n' was already on OPEN or on CLOSED 
             direct its pointers along the path yielding 
             the lowest g(n') and keep the lowest f(n').
       2.4.4 if n' required pointer adjustment and was 
             found on CLOSED, move it back to OPEN.
3. If a goal node is found, 
   then exit with the solution obtained by tracing back 
        through its pointers
   else announce failure.
```

> NOTE: 上述2.4.2、2.4.3、2.4.4和Best-First Search algorithm的2.4.3类似。

- `A*` is a special case of **best-first search** where:

  - The cost `f(n)` of a node is computed as `f(n) = g(n) + h(n)`, where `g(n)` is the cost of the current path from `s` to `n`, and `h(n)` is an estimate of the cost of the path from `n` to **goal**
  - The `g` cost of a node `n` is computed recursively by adding the `g` cost of its parent node `m` to the cost of the arc from the parent `m` to the node `n` `g(n) = g(m) + c(m,n)`. We assume arc costs to be positive. The start node has a cost `g(s) = 0`.
  - `h(n)` is an underestimate of the cost of the optimal path from `n` to goal. If we call `h*(n)` the cost of the optimal path `forall n h(n) < = h*(n)`. This implies that a goal node has a cost `h(goal) = 0`

- The check for the goal node (step 2.2) must be done after the node has been selected for expansion to guarantee an optimal solution

  > NOTE:  为什么能够实现？

- The redirection of the **parent pointer** is done using only the `g` value of the node (not the `f` value). This guarantees that the path used to any node is the best path.

- When the heuristic used is monotone（单调的）, `A*` never reopens nodes from `CLOSED`. This means that whenever a node is put into `CLOSED`, `A*` has already found the **optimal path** to it.

- If `forall n h(n) = 0` the algorithm `A*` is the same as Branch&Bound (or Uniform Cost).
  If `forall n h(n) = 0` and `forall n, n' c(n,n')=1` the algorithm `A*` is the same as Breadth-First Search.

- Properties of `A*`

  - Completeness:

    guaranteed even on infinite graphs provided that the branching factor is finite and that there is some positive constant delta such that every operator cost at least delta.

  - Admissibility:

    guaranteed given an admissible heuristics (i.e. h(n) is an underestimate of the cost of the optimal path from n to the goal for every node)

  - Time Complexity:

    depends on the accuracy of the heuristic function. If the heuristic function is exact A* runs in linear time, if the heuristic function is useless, the time complexity is exponential (as for uniform cost).

  - Space Complexity:

    O(B to the power of d)



#### `Iterative-Deepening A*` (`IDA*`)

`IDA*` is similar to Depth-First Iterative-Deepening, the difference being the cutoff criteria. A path is cutoff when its total cots f(n) exceeds a cost threshold. `IDA*` starts with a threshold equal to f(s) (which is equal to h'(s) since g(s) = 0). Each iteration is a depth-first search, cutting off a branch when its f(n) value exceeds the threshold. If a solution is found, the algorithm terminates. Otherwise, the threshold is increased to the minimum f value that exceeded the previous threshold and another depth-first search is started from scratch. This continues until a solution is found.

- Time Complexity:

  depends on the accuracy of the heuristic function. If the heuristic function is exact `IDA*` runs in linear time, if the heuristic function is useless, the time complexity is exponential (as for uniform cost).

- Space Complexity:

  O(d)

