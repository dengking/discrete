# wikipedia [Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))

> NOTE: 
>
> 1、在"Recursion"中，我们已经接触了recursion 的概念，本文将分析computer science中的recursion。

**Recursion** in [computer science](https://en.wikipedia.org/wiki/Computer_science) is a method of solving a problem where the solution depends on solutions to smaller instances of the same problem (as opposed to [iteration](https://en.wikipedia.org/wiki/Iteration#Computing)). The approach can be applied to many types of problems, and [recursion](https://en.wikipedia.org/wiki/Recursion) is one of the central ideas of computer science. 

> The power of **recursion** evidently lies in the possibility of defining an infinite（无限的） set of objects by a finite（有限的） statement. In the same manner, an infinite number of computations can be described by a finite recursive program, even if this program contains no explicit repetitions.
>
> — [Niklaus Wirth](https://en.wikipedia.org/wiki/Niklaus_Wirth), *Algorithms + Data Structures = Programs*, 1976



> NOTE: 维基百科[Recursion](https://en.wikipedia.org/wiki/Recursion)是从定义（如何进行递归定义，参见维基百科[Recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)）的角度来描述递归，维基百科[Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))中，是从解决问题的角度（如何编码实现）来描述递归，正如它的开头所述：
>
> > *This article is about recursive approaches to solving problems.*

> NOTE: 从finite（有限的） statement到 infinite（无限的），这正是recursion的强大所在；

Most computer [programming languages](https://en.wikipedia.org/wiki/Programming_language) support recursion by allowing a [function](https://en.wikipedia.org/wiki/Function_(computer_science)) to call itself from within its own code. Some [functional programming](https://en.wikipedia.org/wiki/Functional_programming) languages do not define any looping constructs but rely solely on recursion to repeatedly call code. [Computability theory](https://en.wikipedia.org/wiki/Computability_theory) proves that these recursive-only languages are [Turing complete](https://en.wikipedia.org/wiki/Turing_completeness); they are as computationally powerful as Turing complete imperative languages, meaning they can solve the same kinds of problems as imperative languages even without iterative control structures such as `while` and `for`.



## Recursive functions and algorithms

A common [computer programming](https://en.wikipedia.org/wiki/Computer_programming) tactic is to divide a problem into sub-problems of the same type as the original, solve those sub-problems, and combine the results. This is often referred to as the [divide-and-conquer method](https://en.wikipedia.org/wiki/Divide-and-conquer_method); when combined with a [lookup table](https://en.wikipedia.org/wiki/Lookup_table) that stores the results of solving sub-problems (to avoid solving them repeatedly and incurring extra computation time), it can be referred to as [dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming) or [memoization](https://en.wikipedia.org/wiki/Memoization).

> NOTE:  
>
> 1、需要添加工程[algorithm](https://dengking.github.io/algorithm/)中，关于recursion和dynamic programming的比较。
>
> 2、上面这段话，对从recursion到dynamic programming的论述是比较好的

A recursive function definition has one or more *base cases*, meaning input(s) for which the function produces a result [trivially](https://en.wikipedia.org/wiki/Trivial_(mathematics)) (without recurring), and one or more *recursive cases*, meaning input(s) for which the program recurs（递归，重现，重复） (calls itself). For example, the [factorial](https://en.wikipedia.org/wiki/Factorial) function can be defined recursively by the equations 0! = 1 and, for all *n* > 0, *n*! = *n*(*n* − 1)!. Neither equation by itself constitutes a complete definition; the first is the base case, and the second is the recursive case. Because the base case breaks the chain of recursion, it is sometimes also called the "terminating case".

The job of the **recursive cases** can be seen as breaking down complex inputs into simpler ones. In a properly designed recursive function, with each recursive call, the input problem must be simplified in such a way that eventually the **base case** must be reached. (Functions that are not intended to terminate under normal circumstances—for example, some [system and server processes](https://en.wikipedia.org/wiki/Daemon_(computer_software))—are an exception to this.) Neglecting(忘记、忽略) to write a base case, or testing for it incorrectly, can cause an [infinite loop](https://en.wikipedia.org/wiki/Infinite_loop).

> NOTE: 
>
> 包含两个部分:
>
> 1、base cases
>
> 2、recursive cases

For some functions (such as one that computes the [series](https://en.wikipedia.org/wiki/Series_(mathematics)) for *e* = 1/0! + 1/1! + 1/2! + 1/3! + ...) there is not an obvious **base case** implied by the input data; for these one may add a [parameter](https://en.wikipedia.org/wiki/Parameter) (such as the number of terms to be added, in our series example) to provide a 'stopping criterion' that establishes the **base case**. Such an example is more naturally treated by **co-recursion**, where successive terms in the output are the partial sums; this can be converted to a recursion by using the indexing parameter to say "compute the *n*th term (*n*th partial sum)".

> NOTE: 在递归函数中添加一个入参，这个入参就表示停止条件；关于co-recursion，参见[Corecursion](./Corecursion.md)。



## Recursive data types

Many [computer programs](https://en.wikipedia.org/wiki/Computer_program) must process or generate an arbitrarily large quantity of [data](https://en.wikipedia.org/wiki/Data). Recursion is one technique for representing data whose exact size the [programmer](https://en.wikipedia.org/wiki/Programmer) does not know: the programmer can specify this data with a [self-referential](https://en.wikipedia.org/wiki/Self_reference) definition. There are two types of **self-referential definitions**: inductive and [coinductive](https://en.wikipedia.org/wiki/Coinduction) definitions.

Further information: [Algebraic data type](https://en.wikipedia.org/wiki/Algebraic_data_type)

### Inductively defined data

*Main article:* [Recursive data type](https://en.wikipedia.org/wiki/Recursive_data_type)

Similarly recursive [definitions](https://en.wikipedia.org/wiki/Definition) are often used to model the structure of [expressions](https://en.wikipedia.org/wiki/Expression_(programming)) and [statements](https://en.wikipedia.org/wiki/Statement_(programming)) in programming languages. Language designers often express grammars in a syntax such as [Backus–Naur form](https://en.wikipedia.org/wiki/Backus–Naur_form); here is such a grammar, for a simple language of arithmetic expressions with multiplication and addition:

```
 <expr> ::= <number>
          | (<expr> * <expr>)
          | (<expr> + <expr>)
```

This says that an expression is either a number, a product of two expressions, or a sum of two expressions. By recursively referring to expressions in the second and third lines, the grammar permits arbitrarily complex arithmetic expressions such as `(5 * ((3 * 6) + 8))`, with more than one product or sum operation in a single expression.



### Coinductively defined data and corecursion

*Main articles:* [Coinduction](https://en.wikipedia.org/wiki/Coinduction) *and* [Corecursion](https://en.wikipedia.org/wiki/Corecursion)

A coinductive definition of infinite [streams](https://en.wikipedia.org/wiki/Stream_(computer_science)) of strings, given informally, might look like this:

```
A stream of strings is an object s such that:
 head(s) is a string, and
 tail(s) is a stream of strings.
```

## Types of recursion



### Single recursion and multiple recursion

Recursion that only contains a single self-reference is known as **single recursion**, while recursion that contains multiple self-references is known as **multiple recursion**. Standard examples of single recursion include list traversal, such as in a linear search, or computing the factorial function, while standard examples of multiple recursion include [tree traversal](https://en.wikipedia.org/wiki/Tree_traversal), such as in a **depth-first search**.

> NOTE:
>
> 1、上面这一段的总结非常好

**Single recursion** is often much more efficient than **multiple recursion**, and can generally be replaced by an **iterative computation**, running in linear time and requiring constant space. **Multiple recursion**, by contrast, may require exponential time and space, and is more fundamentally recursive, not being able to be replaced by iteration without an **explicit stack**.

> NOTE: 
>
> 1、通过Fibonacci和tree traversal 的例子就可以验证上面这段话
>
> 2、Multiple recursion的复杂性

Multiple recursion can sometimes be converted to single recursion (and, if desired, thence to iteration). For example, while computing the Fibonacci sequence naively is multiple iteration, as each value requires **two previous values**, it can be computed by single recursion by passing two successive values as parameters. This is more naturally framed as **corecursion**, building up from the **initial values**, tracking at each step two successive values – see [corecursion: examples](https://en.wikipedia.org/wiki/Corecursion#Examples). A more sophisticated example is using a [threaded binary tree](https://en.wikipedia.org/wiki/Threaded_binary_tree), which allows iterative tree traversal, rather than multiple recursion.

> NOTE : Fibonacci 函数的表达式中包含了两个递归调用，但是正如上面所说的： it can be computed by single recursion by passing two successive values as parameters；这样就可以将它转换为一个tail recursion了，这样就可以消除掉tail recursion，使用iterative方法来实现了；

### Indirect recursion

*Main article:* [Mutual recursion](https://en.wikipedia.org/wiki/Mutual_recursion)

Most basic examples of **recursion**, and most of the examples presented here, demonstrate **direct recursion**, in which a function calls itself. *Indirect* recursion occurs when a function is called not by itself but by another function that it called (either directly or indirectly). For example, if *f* calls *f,* that is direct recursion, but if *f* calls *g* which calls *f,* then that is indirect recursion of *f.* Chains of three or more functions are possible; for example, function 1 calls function 2, function 2 calls function 3, and function 3 calls function 1 again.

Indirect recursion is also called [mutual recursion](https://en.wikipedia.org/wiki/Mutual_recursion), which is a more symmetric term, though this is simply a difference of emphasis, not a different notion. That is, if *f* calls *g* and then *g* calls *f,* which in turn calls *g* again, from the point of view of *f* alone, *f* is indirectly recursing, while from the point of view of *g* alone, it is indirectly recursing, while from the point of view of both, *f* and *g* are mutually recursing on each other. Similarly a set of three or more functions that call each other can be called a set of mutually recursive functions.

### Anonymous recursion

*Main article:* [Anonymous recursion](https://en.wikipedia.org/wiki/Anonymous_recursion)

Recursion is usually done by explicitly calling a function by name. However, recursion can also be done via implicitly calling a function based on the current context, which is particularly useful for [anonymous functions](https://en.wikipedia.org/wiki/Anonymous_function), and is known as [anonymous recursion](https://en.wikipedia.org/wiki/Anonymous_recursion).

### Structural versus generative recursion

> NOTE:
>
> 1、参见 `Structural-and-generative-recursion` 章节



## Recursive programs

> NOTE: 
>
> 1、参见 `Recursive-programs` 章节



## Implementation issues

In actual implementation, rather than a pure recursive function (single check for base case, otherwise recursive step), a number of modifications may be made, for purposes of clarity or efficiency. These include:

- Wrapper function (at top)
- Short-circuiting（简化） the **base case**, aka "Arm's-length recursion" (at bottom)
- Hybrid algorithm (at bottom) – switching to a different algorithm once data is small enough

On the basis of elegance, **wrapper functions** are generally approved, while short-circuiting the base case is frowned upon, particularly in academia. Hybrid algorithms are often used for efficiency, to reduce the overhead of recursion in small cases, and arm's-length recursion is a special case of this.





## Recursion versus iteration

Recursion and [iteration](https://en.wikipedia.org/wiki/Iteration) are equally expressive: recursion can be replaced by iteration with an explicit [call stack](https://en.wikipedia.org/wiki/Call_stack), while iteration can be replaced with [tail recursion](https://en.wikipedia.org/wiki/Tail_call). Which approach is preferable depends on the problem under consideration and the language used. In [imperative programming](https://en.wikipedia.org/wiki/Imperative_programming), iteration is preferred, particularly for simple recursion, as it avoids the overhead of function calls and call stack management, but recursion is generally used for **multiple recursion**. By contrast, in [functional languages](https://en.wikipedia.org/wiki/Functional_programming) recursion is preferred, with tail recursion optimization leading to little overhead. Implementing an algorithm using iteration may not be easily achievable.

For example, a [factorial](https://en.wikipedia.org/wiki/Factorial) function may be implemented iteratively in [C](https://en.wikipedia.org/wiki/C_(programming_language)) by assigning to an loop index variable and accumulator variable, rather than by passing arguments and returning values by recursion:

```c
unsigned int factorial(unsigned int n) {
  unsigned int product = 1; // empty product is 1
  while (n) {
    product *= n;
    --n;
  }
  return product;
}
```





### Multiply recursive problems

Multiply recursive problems are inherently recursive, because of prior state they need to track. One example is [tree traversal](https://en.wikipedia.org/wiki/Tree_traversal) as in [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search); though both recursive and iterative methods are used,[[19\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-19) they contrast with list traversal and linear search in a list, which is a singly recursive and thus naturally iterative method. Other examples include [divide-and-conquer algorithms](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm) such as [Quicksort](https://en.wikipedia.org/wiki/Quicksort), and functions such as the [Ackermann function](https://en.wikipedia.org/wiki/Ackermann_function). All of these algorithms can be implemented iteratively with the help of an explicit [stack](https://en.wikipedia.org/wiki/Stack_(data_structure)), but the programmer effort involved in managing the stack, and the complexity of the resulting program, arguably outweigh any advantages of the iterative solution.



### Refactoring recursion

Recursive algorithms can be replaced with non-recursive counterparts.[[20\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-20). One method for replacing recursive algorithms is to simulate them using [heap memory](https://en.wikipedia.org/wiki/Memory_management) in place of [stack memory](https://en.wikipedia.org/wiki/Stack-based_memory_allocation).[[21\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-21) An alternative is to develop a replacement algorithm entirely based on non-recursive methods, which can be challenging.[[22\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-22) For example, recursive algorithms for [matching wildcards](https://en.wikipedia.org/wiki/Matching_wildcards), such as [Rich Salz](https://en.wikipedia.org/wiki/Rich_Salz)' [wildmat](https://en.wikipedia.org/wiki/Wildmat) algorithm,[[23\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-23) were once typical. Non-recursive algorithms for the same purpose, such as the [Krauss matching wildcards algorithm](https://en.wikipedia.org/wiki/Krauss_matching_wildcards_algorithm), have been developed to avoid the drawbacks of recursion[[24\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-24) and have improved only gradually based on techniques such as collecting [tests](https://en.wikipedia.org/wiki/Software_testing) and [profiling](https://en.wikipedia.org/wiki/Profiling_(computer_programming)) performance.[[25\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-25)



## Tail-recursive functions

Tail-recursive functions are functions in which all recursive calls are [tail calls](https://en.wikipedia.org/wiki/Tail_call) and hence do not build up any deferred operations. For example, the gcd function (shown again below) is tail-recursive. In contrast, the factorial function (also below) is **not** tail-recursive; because its recursive call is not in tail position, it builds up deferred multiplication operations that must be performed after the final recursive call completes. With a [compiler](https://en.wikipedia.org/wiki/Compiler) or [interpreter](https://en.wikipedia.org/wiki/Interpreter_(computing)) that treats **tail-recursive calls** as [jumps](https://en.wikipedia.org/wiki/Goto) rather than **function calls**, a **tail-recursive function** such as gcd will execute using **constant space**. Thus the program is essentially iterative, equivalent to using imperative language control structures like the "for" and "while" loops.

[Tail recursion](https://en.wikipedia.org/wiki/Tail_recursion)**:**

```c
//INPUT: Integers x, y such that x >= y and y >= 0
int gcd(int x, int y)
{
  if (y == 0)
     return x;
  else
     return gcd(y, x % y);
}
```

**Augmenting recursion:**

```c
//INPUT: n is an Integer such that n >= 0
int fact(int n)
{
   if (n == 0)
      return 1;
   else
      return n * fact(n - 1);
}
```

The significance of **tail recursion** is that when making a **tail-recursive call** (or any tail call), the caller's return position need not be saved on the [call stack](https://en.wikipedia.org/wiki/Call_stack); when the recursive call returns, it will branch directly on the previously saved return position. Therefore, in languages that recognize this property of tail calls, tail recursion saves both space and time.



## Time-efficiency of recursive algorithms

The [time efficiency](https://en.wikipedia.org/wiki/Time_complexity) of recursive algorithms can be expressed in a [recurrence relation](https://en.wikipedia.org/wiki/Recurrence_relation) of [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation). They can (usually) then be simplified into a single Big-O term.

### Shortcut rule (master theorem)

*Main article:* [Master theorem (analysis of algorithms)](https://en.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms))

If the time-complexity of the function is in the form

$ T(n)=a\cdot T(n/b)+f(n) $

Then the Big O of the time-complexity is thus:

- If $ f(n)=O(n^{\log _{b}a-\epsilon }) $ for some constant $ \epsilon >0 $, then $ T(n)=\Theta (n^{\log _{b}a}) $
- If $ f(n)=\Theta (n^{\log _{b}a}) $, then $ T(n)=\Theta (n^{\log _{b}a}\log n) $
- If $ f(n)=\Omega (n^{\log _{b}a+\epsilon }) $ for some constant $ \epsilon >0 $, and if $ a\cdot f(n/b)\leq c\cdot f(n) $ for some constant *c* < 1 and all sufficiently large *n*, then $ T(n)=\Theta (f(n)) $

where *a* represents the number of recursive calls at each level of recursion, *b* represents by what factor smaller the input is for the next level of recursion (i.e. the number of pieces you divide the problem into), and *f* (*n*) represents the work the function does independent of any recursion (e.g. partitioning, recombining) at each level of recursion.

