# Corecursion

wikipedia [Dual](https://en.wikipedia.org/wiki/Dual) 

> [Dual (mathematics)](https://en.wikipedia.org/wiki/Dual_(mathematics)), a notion of paired concepts that mirror one another

显然:

> **corecursion** is a type of operation that is [dual](https://en.wikipedia.org/wiki/Dual_(category_theory)) to [recursion](https://en.wikipedia.org/wiki/Recursion_(computer_science))



## wikipedia [Corecursion](https://en.wikipedia.org/wiki/Corecursion)



In [computer science](https://en.wikipedia.org/wiki/Computer_science), **corecursion** is a type of operation that is [dual](https://en.wikipedia.org/wiki/Dual_(category_theory)) to [recursion](https://en.wikipedia.org/wiki/Recursion_(computer_science)): 

1、recursion works **analytically**, starting on data further from a **base case** and breaking it down into smaller data and repeating until one reaches a base case, 

2、corecursion works **synthetically**, starting from a **base case** and building it up, iteratively producing data further removed from a base case. Put simply, **corecursive algorithms** use the data that they themselves produce, bit by bit, as they become available, and needed, to produce further bits of data. A similar but distinct concept is [*generative recursion*](https://en.wikipedia.org/wiki/Generative_recursion#Structural_versus_generative_recursion) which may lack a definite（确切的） "direction" inherent in corecursion and recursion.

> NOTE: 
>
> 一、recursion 和 corecursion 的计算方向是相反：对于一个 [recurrence relations](https://en.wikipedia.org/wiki/Recurrence_relation) ，如*n! := n × (n - 1)!*.，recursion是从左至右，但是corecursion是从右至左，但是能够殊途同归
>
> 1、recursion works **analytically** VS corecursion works **synthetically**
>
> 2、recursion top-down VS corecursion bottom-up
>
> 3、recursion reduce VS corecursion produce

Where recursion allows programs to operate on arbitrarily complex data, so long as they can be reduced to simple data (base cases), corecursion allows programs to produce arbitrarily complex and potentially infinite data structures, such as [streams](https://en.wikipedia.org/wiki/Stream_(computing)), so long as it can be produced from simple data (**base cases**) in a sequence of *finite* steps. Where recursion may not terminate, never reaching a **base state**, corecursion starts from a **base state**, and thus produces subsequent steps deterministically, though it may proceed indefinitely (and thus not terminate under strict evaluation), or it may consume more than it produces and thus become non-*productive*. Many functions that are traditionally analyzed as recursive can alternatively, and arguably more naturally, be interpreted as **corecursive functions** that are terminated at a given stage, for example [recurrence relations](https://en.wikipedia.org/wiki/Recurrence_relation) such as the factorial（阶乘）.

**Corecursion** can produce both [finite](https://en.wikipedia.org/wiki/Finite_set) and [infinite](https://en.wikipedia.org/wiki/Infinite_set) [data structures](https://en.wikipedia.org/wiki/Data_structure) as results, and may employ [self-referential](https://en.wikipedia.org/wiki/Self-reference) data structures. **Corecursion** is often used in conjunction with [lazy evaluation](https://en.wikipedia.org/wiki/Lazy_evaluation), to produce only a finite subset of a potentially infinite structure (rather than trying to produce an entire infinite structure at once). Corecursion is a particularly important concept in [functional programming](https://en.wikipedia.org/wiki/Functional_programming), where corecursion and [codata](https://en.wikipedia.org/wiki/Codata_(computer_science)) allow [total languages](https://en.wikipedia.org/wiki/Total_language) to work with infinite data structures.

> NOTE : python的generator就是Corecursion的最好的例子。

## Examples

Corecursion can be understood by contrast with recursion, which is more familiar. While corecursion is primarily of interest in functional programming, it can be illustrated using imperative programming, which is done below using the [generator](https://en.wikipedia.org/wiki/Generator_(computer_programming)) facility in Python. In these examples **local variables** are used, and [assigned values](https://en.wikipedia.org/wiki/Assignment_(computer_science)) imperatively (destructively), though these are not necessary in corecursion in pure functional programming. In pure functional programming, rather than assigning to **local variables**, these computed values form an invariable sequence, and prior values are accessed by self-reference (later values in the sequence reference earlier values in the sequence to be computed). The assignments simply express this in the imperative paradigm and explicitly specify where the computations happen, which serves to clarify the exposition.

### Factorial

A classic example of recursion is computing the [factorial](https://en.wikipedia.org/wiki/Factorial)（阶乘）, which is defined recursively by *0! := 1* and *n! := n × (n - 1)!*.

To *recursively* compute its result on a given input, a recursive function calls (a copy of) *itself* with a different ("smaller" in some way) input and uses the result of this call to construct its result. The recursive call does the same, unless the *base case* has been reached. Thus a [call stack](https://en.wikipedia.org/wiki/Call_stack) develops in the process. For example, to compute *fac(3)*, this recursively calls in turn *fac(2)*, *fac(1)*, *fac(0)* ("winding up" the stack), at which point recursion terminates with *fac(0) = 1*, and then the **stack unwinds** in reverse order and the results are calculated on the way back along the **call stack** to the initial call frame *fac(3)* that uses the result of *fac(2) = 2* to calculate the final result as *3 × 2 = 3 × fac(2) =: fac(3)* and finally return *fac(3) = 6*. In this example a function returns a single value.

This **stack unwinding** can be explicated, defining the factorial *corecursively*, as an [iterator](https://en.wikipedia.org/wiki/Iteration), where one *starts* with the case of $ 1=:0! $, then from this starting value constructs factorial values for increasing numbers *1, 2, 3...* as in the above recursive definition with "time arrow" reversed, as it were, by reading it *backwards* as $ n!\times (n+1)=:(n+1)! $. The corecursive algorithm thus defined produces a *stream* of *all* factorials. This may be concretely implemented as a [generator](https://en.wikipedia.org/wiki/Generator_(computer_programming)). Symbolically, noting that computing next factorial value requires keeping track of both *n* and *f* (a previous factorial value), this can be represented as:

$ n,f=(0,1):(n+1,f\times (n+1)) $

In Python, a recursive factorial function can be defined as: 

```python
def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)
```

This could then be called for example as `factorial(5)` to compute *5!*.

A corresponding corecursive generator can be defined as:

```python
def factorials():
    n, f = 0, 1
    while True:
        yield f
        n, f = n + 1, f * (n + 1)
```

This generates an infinite stream of factorials in order; a finite portion of it can be produced by:

```python
def n_factorials(k):
    n, f = 0, 1
    while n <= k:
        yield f
        n, f = n + 1, f * (n + 1)
```

This could then be called to produce the factorials up to *5!* via:

```python
for f in n_factorials(5):
    print(f)
```

If we're only interested in a certain factorial, just the last value can be taken, or we can fuse the production and the access into one function,

```python
def nth_factorial(k):
    n, f = 0, 1
    while n < k:
        n, f = n + 1, f * (n + 1)
    yield f
```

As can be readily seen here, this is practically equivalent (just by substituting `return` for the only `yield` there) to the **accumulator argument technique** for [tail recursion](https://en.wikipedia.org/wiki/Tail_call), unwound into an explicit loop. Thus it can be said that the concept of corecursion is an explication of the embodiment of iterative computation processes by recursive definitions, where applicable.

因此，可以这样说，协递归的概念是通过递归定义来解释迭代计算过程的体现。



### Fibonacci sequence

In the same way, the [Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence) can be represented as:

$ a,b=(0,1):(b,a+b) $

Note that because the Fibonacci sequence is a [recurrence relation](https://en.wikipedia.org/wiki/Recurrence_relation) of order 2, the corecursive relation must track two successive terms, with the $ (b,-) $ corresponding to shift forward by one step, and the $ (-,a+b) $ corresponding to computing the next term. This can then be implemented as follows (using [parallel assignment](https://en.wikipedia.org/wiki/Parallel_assignment)):

```python
def fibonacci_sequence():
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b
```

In Haskell,

```haskell
 map fst ( (\(a,b) -> (b,a+b)) `iterate` (0,1) )
```



### Tree traversal

[Tree traversal](https://en.wikipedia.org/wiki/Tree_traversal) via a [depth-first](https://en.wikipedia.org/wiki/Depth-first) approach is a classic example of **recursion**. Dually, [breadth-first](https://en.wikipedia.org/wiki/Breadth-first) traversal can very naturally be implemented via **corecursion**.

Without using recursion or corecursion specifically, one may traverse a tree by starting at the **root node**, placing its child nodes in a **data structure**, then iterating by removing node after node from the **data structure** while placing each removed node's **children** back into that data structure.[[b\]](https://en.wikipedia.org/wiki/Corecursion#cite_note-2) If the data structure is a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) (LIFO), this yields **depth-first traversal**, and if the data structure is a [queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) (FIFO), this yields **breadth-first traversal**.

> NOTE: 在不使用recursion或者corecursion的时候，我们如果想要遍历一棵树，则需要借助于一个data structure来实现；

Using **recursion**, a (post-order)[[c\]](https://en.wikipedia.org/wiki/Corecursion#cite_note-3) **depth-first traversal** can be implemented by starting at the root node and recursively traversing each child subtree in turn (the subtree based at each child node) – the second child subtree does not start processing until the first child subtree is finished. Once a leaf node is reached or the children of a branch node have been exhausted, the node itself is visited (e.g., the value of the node itself is outputted). In this case, the **call stack** (of the **recursive functions**) acts as the **stack** that is iterated over.

Using **corecursion**, a **breadth-first traversal** can be implemented by starting at the root node, outputting its value,[[d\]](https://en.wikipedia.org/wiki/Corecursion#cite_note-4) then **breadth-first traversing** the subtrees – i.e., passing on the *whole list* of subtrees to the next step (not a single subtree, as in the recursive approach) – at the next step outputting the value of all of their root nodes, then passing on their child subtrees, etc.[[e\]](https://en.wikipedia.org/wiki/Corecursion#cite_note-5) In this case the **generator function**, indeed the output sequence itself, acts as the **queue**. As in the factorial example (above), where the auxiliary information of the index (which step one was at, *n*) was pushed forward, in addition to the actual output of *n*!, in this case the auxiliary information of the remaining subtrees is pushed forward, in addition to the actual output. Symbolically:

$ v,t=([],[FullTree]):(RootValues(t),ChildTrees(t)) $

