# Recursion (computer science)

在[Recursion](https://dengking.github.io/Post/Recursion/)中，我们已经接触了recursion 的概念，本文将分析computer science中的recursion。

## 维基百科[Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))

**Recursion** in [computer science](https://en.wikipedia.org/wiki/Computer_science) is a method of solving a problem where the solution depends on solutions to smaller instances of the same problem (as opposed to [iteration](https://en.wikipedia.org/wiki/Iteration#Computing)). The approach can be applied to many types of problems, and [recursion](https://en.wikipedia.org/wiki/Recursion) is one of the central ideas of computer science. 

> The power of **recursion** evidently lies in the possibility of defining an infinite（无限的） set of objects by a finite（有限的） statement. In the same manner, an infinite number of computations can be described by a finite recursive program, even if this program contains no explicit repetitions.
>
> — [Niklaus Wirth](https://en.wikipedia.org/wiki/Niklaus_Wirth), *Algorithms + Data Structures = Programs*, 1976



> NOTE: 维基百科[Recursion](https://en.wikipedia.org/wiki/Recursion)是从定义（如何进行递归定义，参见维基百科[Recursive definition](https://en.wikipedia.org/wiki/Recursive_definition)）的角度来描述递归，维基百科[Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))中，是从解决问题的角度（如何编码实现）来描述递归，正如它的开头所述：
>
> > *This article is about recursive approaches to solving problems.*

> NOTE: 从finite（有限的） statement到 infinite（无限的），这正是recursion的强大所在；

Most computer [programming languages](https://en.wikipedia.org/wiki/Programming_language) support recursion by allowing a [function](https://en.wikipedia.org/wiki/Function_(computer_science)) to call itself from within its own code. Some [functional programming](https://en.wikipedia.org/wiki/Functional_programming) languages do not define any looping constructs but rely solely on recursion to repeatedly call code. [Computability theory](https://en.wikipedia.org/wiki/Computability_theory) proves that these recursive-only languages are [Turing complete](https://en.wikipedia.org/wiki/Turing_completeness); they are as computationally powerful as Turing complete imperative languages, meaning they can solve the same kinds of problems as imperative languages even without iterative control structures such as `while` and `for`.



### Recursive functions and algorithms

A common [computer programming](https://en.wikipedia.org/wiki/Computer_programming) tactic is to divide a problem into sub-problems of the same type as the original, solve those sub-problems, and combine the results. This is often referred to as the [divide-and-conquer method](https://en.wikipedia.org/wiki/Divide-and-conquer_method); when combined with a [lookup table](https://en.wikipedia.org/wiki/Lookup_table) that stores the results of solving sub-problems (to avoid solving them repeatedly and incurring extra computation time), it can be referred to as [dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming) or [memoization](https://en.wikipedia.org/wiki/Memoization).

> NOTE:  TODO 需要添加工程[algorithm](https://dengking.github.io/algorithm/)中，关于recursion和dynamic programming的比较。

A recursive function definition has one or more *base cases*, meaning input(s) for which the function produces a result [trivially](https://en.wikipedia.org/wiki/Trivial_(mathematics)) (without recurring), and one or more *recursive cases*, meaning input(s) for which the program recurs（递归，重现，重复） (calls itself). For example, the [factorial](https://en.wikipedia.org/wiki/Factorial) function can be defined recursively by the equations 0! = 1 and, for all *n* > 0, *n*! = *n*(*n* − 1)!. Neither equation by itself constitutes a complete definition; the first is the base case, and the second is the recursive case. Because the base case breaks the chain of recursion, it is sometimes also called the "terminating case".

The job of the **recursive cases** can be seen as breaking down complex inputs into simpler ones. In a properly designed recursive function, with each recursive call, the input problem must be simplified in such a way that eventually the **base case** must be reached. (Functions that are not intended to terminate under normal circumstances—for example, some [system and server processes](https://en.wikipedia.org/wiki/Daemon_(computer_software))—are an exception to this.) Neglecting to write a base case, or testing for it incorrectly, can cause an [infinite loop](https://en.wikipedia.org/wiki/Infinite_loop).

For some functions (such as one that computes the [series](https://en.wikipedia.org/wiki/Series_(mathematics)) for *e* = 1/0! + 1/1! + 1/2! + 1/3! + ...) there is not an obvious **base case** implied by the input data; for these one may add a [parameter](https://en.wikipedia.org/wiki/Parameter) (such as the number of terms to be added, in our series example) to provide a 'stopping criterion' that establishes the **base case**. Such an example is more naturally treated by **co-recursion**, where successive terms in the output are the partial sums; this can be converted to a recursion by using the indexing parameter to say "compute the *n*th term (*n*th partial sum)".

> NOTE: 在递归函数中添加一个入参，这个入参就表示停止条件；关于co-recursion，参见[Corecursion](./Corecursion.md)。



### Recursive data types

Many [computer programs](https://en.wikipedia.org/wiki/Computer_program) must process or generate an arbitrarily large quantity of [data](https://en.wikipedia.org/wiki/Data). Recursion is one technique for representing data whose exact size the [programmer](https://en.wikipedia.org/wiki/Programmer) does not know: the programmer can specify this data with a [self-referential](https://en.wikipedia.org/wiki/Self_reference) definition. There are two types of **self-referential definitions**: inductive and [coinductive](https://en.wikipedia.org/wiki/Coinduction) definitions.

Further information: [Algebraic data type](https://en.wikipedia.org/wiki/Algebraic_data_type)

#### Inductively defined data

*Main article:* [Recursive data type](https://en.wikipedia.org/wiki/Recursive_data_type)

Similarly recursive [definitions](https://en.wikipedia.org/wiki/Definition) are often used to model the structure of [expressions](https://en.wikipedia.org/wiki/Expression_(programming)) and [statements](https://en.wikipedia.org/wiki/Statement_(programming)) in programming languages. Language designers often express grammars in a syntax such as [Backus–Naur form](https://en.wikipedia.org/wiki/Backus–Naur_form); here is such a grammar, for a simple language of arithmetic expressions with multiplication and addition:

```
 <expr> ::= <number>
          | (<expr> * <expr>)
          | (<expr> + <expr>)
```

This says that an expression is either a number, a product of two expressions, or a sum of two expressions. By recursively referring to expressions in the second and third lines, the grammar permits arbitrarily complex arithmetic expressions such as `(5 * ((3 * 6) + 8))`, with more than one product or sum operation in a single expression.



#### Coinductively defined data and corecursion

*Main articles:* [Coinduction](https://en.wikipedia.org/wiki/Coinduction) *and* [Corecursion](https://en.wikipedia.org/wiki/Corecursion)



### Types of recursion



#### Single recursion and multiple recursion

Recursion that only contains a single self-reference is known as **single recursion**, while recursion that contains multiple self-references is known as **multiple recursion**. Standard examples of single recursion include list traversal, such as in a linear search, or computing the factorial function, while standard examples of multiple recursion include [tree traversal](https://en.wikipedia.org/wiki/Tree_traversal), such as in a **depth-first search**.

**Single recursion** is often much more efficient than **multiple recursion**, and can generally be replaced by an **iterative computation**, running in linear time and requiring constant space. **Multiple recursion**, by contrast, may require exponential time and space, and is more fundamentally recursive, not being able to be replaced by iteration without an **explicit stack**.

> NOTE: 通过Fibonacci和tree traversal 的例子就可以验证上面这段话

> NOTE: Multiple recursion的复杂性

Multiple recursion can sometimes be converted to single recursion (and, if desired, thence to iteration). For example, while computing the Fibonacci sequence naively is multiple iteration, as each value requires **two previous values**, it can be computed by single recursion by passing two successive values as parameters. This is more naturally framed as **corecursion**, building up from the **initial values**, tracking at each step two successive values – see [corecursion: examples](https://en.wikipedia.org/wiki/Corecursion#Examples). A more sophisticated example is using a [threaded binary tree](https://en.wikipedia.org/wiki/Threaded_binary_tree), which allows iterative tree traversal, rather than multiple recursion.

> NOTE : Fibonacci 函数的表达式中包含了两个递归调用，但是正如上面所说的： it can be computed by single recursion by passing two successive values as parameters；这样就可以将它转换为一个tail recursion了，这样就可以消除掉tail recursion，使用iterative方法来实现了；

#### Indirect recursion

*Main article:* [Mutual recursion](https://en.wikipedia.org/wiki/Mutual_recursion)

Most basic examples of **recursion**, and most of the examples presented here, demonstrate **direct recursion**, in which a function calls itself. *Indirect* recursion occurs when a function is called not by itself but by another function that it called (either directly or indirectly). For example, if *f* calls *f,* that is direct recursion, but if *f* calls *g* which calls *f,* then that is indirect recursion of *f.* Chains of three or more functions are possible; for example, function 1 calls function 2, function 2 calls function 3, and function 3 calls function 1 again.

Indirect recursion is also called [mutual recursion](https://en.wikipedia.org/wiki/Mutual_recursion), which is a more symmetric term, though this is simply a difference of emphasis, not a different notion. That is, if *f* calls *g* and then *g* calls *f,* which in turn calls *g* again, from the point of view of *f* alone, *f* is indirectly recursing, while from the point of view of *g* alone, it is indirectly recursing, while from the point of view of both, *f* and *g* are mutually recursing on each other. Similarly a set of three or more functions that call each other can be called a set of mutually recursive functions.

#### Anonymous recursion

*Main article:* [Anonymous recursion](https://en.wikipedia.org/wiki/Anonymous_recursion)

Recursion is usually done by explicitly calling a function by name. However, recursion can also be done via implicitly calling a function based on the current context, which is particularly useful for [anonymous functions](https://en.wikipedia.org/wiki/Anonymous_function), and is known as [anonymous recursion](https://en.wikipedia.org/wiki/Anonymous_recursion).

#### Structural versus generative recursion

*See also:* [Structural recursion](https://en.wikipedia.org/wiki/Structural_recursion)

Some authors classify recursion as either "**structural**" or "**generative**". The distinction is related to where a recursive procedure gets the data that it works on, and how it processes that data:

> [Functions that consume **structured data**] typically decompose their arguments into their immediate structural components and then process those components. If one of the immediate components belongs to the same class of data as the input, the function is recursive. For that reason, we refer to these functions as (STRUCTURALLY) RECURSIVE FUNCTIONS.
>
> — Felleisen, Findler, Flatt, and Krishnaurthi, *How to Design Programs*, 2001[[4\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-Felleisen_HtDP_2001-4)

Thus, the defining characteristic of a **structurally recursive function** is that the argument to each **recursive call** is the content of a field of the original input. **Structural recursion** includes nearly all **tree traversals**, including **XML processing**, **binary tree creation and search**, etc. By considering the algebraic structure of the natural numbers (that is, a natural number is either zero or the successor of a natural number), functions such as factorial may also be regarded as **structural recursion**.

**Generative recursion** is the alternative:

> Many well-known **recursive algorithms** generate an entirely new piece of data from the given data and recur on it. [*HtDP* (*How to Design Programs*)](https://en.wikipedia.org/wiki/How_to_Design_Programs) refers to this kind as **generative recursion**. Examples of generative recursion include: [gcd](https://en.wikipedia.org/wiki/Euclidean_algorithm), [quicksort](https://en.wikipedia.org/wiki/Quicksort), [binary search](https://en.wikipedia.org/wiki/Binary_search), [mergesort](https://en.wikipedia.org/wiki/Mergesort), [Newton's method](https://en.wikipedia.org/wiki/Newton's_method), [fractals](https://en.wikipedia.org/wiki/Fractal), and [adaptive integration](https://en.wikipedia.org/wiki/Adaptive_quadrature).
>
> — Matthias Felleisen, *Advanced Functional Programming*, 2002[[5\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-Felleisen_2002_108-5)



This distinction is important in [proving termination](https://en.wikipedia.org/wiki/Termination_analysis#Termination_proof) of a function.

- All **structurally recursive functions** on finite ([inductively defined](https://en.wikipedia.org/wiki/Recursive_data_type)) data structures can easily be shown to terminate, via [structural induction](https://en.wikipedia.org/wiki/Structural_induction): intuitively, each recursive call receives a smaller piece of input data, until a base case is reached.
- **Generatively recursive functions**, in contrast, do not necessarily feed smaller input to their recursive calls, so proof of their termination is not necessarily as simple, and avoiding [infinite loops](https://en.wikipedia.org/wiki/Infinite_loops) requires greater care. These **generatively recursive functions** can often be interpreted as **corecursive functions** – each step generates the new data, such as successive approximation in Newton's method – and terminating this **corecursion** requires that the data eventually satisfy some condition, which is not necessarily guaranteed.
- In terms of [loop variants](https://en.wikipedia.org/wiki/Loop_variant), **structural recursion** is when there is an obvious loop variant, namely size or complexity, which starts off finite and decreases at each recursive step.
- By contrast, **generative recursion** is when there is not such an obvious **loop variant**, and termination depends on a function, such as "error of approximation" that does not necessarily decrease to zero, and thus termination is not guaranteed without further analysis.



### Recursive programs

#### Recursive procedures

##### Factorial

##### Greatest common divisor

The [Euclidean algorithm](https://en.wikipedia.org/wiki/Euclidean_algorithm), which computes the [greatest common divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) of two integers, can be written recursively.

Function definition*:*

$ \gcd(x,y)={\begin{cases}x&{\mbox{if }}y=0\\\gcd(y,\operatorname {remainder} (x,y))&{\mbox{if }}y>0\\\end{cases}} $



[Pseudocode](https://en.wikipedia.org/wiki/Pseudocode) **(recursive):**

```
function gcd is:
input: integer x, integer y such that x > 0 and y >= 0


    1. if y is 0, return x
    2. otherwise, return [ gcd( y, (remainder of x/y) ) ]


end gcd
```



[Recurrence relation](https://en.wikipedia.org/wiki/Recurrence_relation) for greatest common divisor, where $ x\%y $ expresses the [remainder](https://en.wikipedia.org/wiki/Remainder) of $ x/y $:



$ \gcd(x,y)=\gcd(y,x\%y) $ if $ y\neq 0 $

$ \gcd(x,0)=x $

Computing the recurrence relation for x = 27 and y = 9:

```
gcd(27, 9)   = gcd(9, 27% 9)
             = gcd(9, 0)
             = 9	
```

The **recursive program** above is [tail-recursive](https://en.wikipedia.org/wiki/Tail-recursive); it is equivalent to an **iterative algorithm**, and the computation shown above shows the steps of evaluation that would be performed by a language that eliminates **tail calls**. Below is a version of the same algorithm using explicit iteration, suitable for a language that does not eliminate tail calls. By maintaining its state entirely in the variables *x* and *y* and using a looping construct, the program avoids making recursive calls and growing the call stack.

**Pseudocode (iterative):**

```
function gcd is:
input: integer x, integer y such that x >= y and y >= 0

    1. create new variable called remainder

    2. begin loop
          1. if y is zero, exit loop
          2. set remainder to the remainder of x/y
          3. set x to y
          4. set y to remainder
          5. repeat loop

    3. return x

end gcd
```

The iterative algorithm requires a temporary variable, and even given knowledge of the Euclidean algorithm it is more difficult to understand the process by simple inspection, although the two algorithms are very similar in their steps.

##### Towers of Hanoi

*Main article:* [Towers of Hanoi](https://en.wikipedia.org/wiki/Towers_of_Hanoi)

The Towers of Hanoi is a mathematical puzzle whose solution illustrates recursion.[[6\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-6)[[7\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-7) There are three pegs which can hold stacks of disks of different diameters. A larger disk may never be stacked on top of a smaller. Starting with *n* disks on one peg, they must be moved to another peg one at a time. What is the smallest number of steps to move the stack?



*Function definition*:



$ \operatorname {hanoi} (n)={\begin{cases}1&{\mbox{if }}n=1\\2\cdot \operatorname {hanoi} (n-1)+1&{\mbox{if }}n>1\\\end{cases}} $





*Recurrence relation for hanoi*:

$ h_{n}=2h_{n-1}+1 $

$ h_{1}=1 $

**Computing the recurrence relation for n = 4:**

```
hanoi(4)     = 2*hanoi(3) + 1
             = 2*(2*hanoi(2) + 1) + 1
             = 2*(2*(2*hanoi(1) + 1) + 1) + 1
             = 2*(2*(2*1 + 1) + 1) + 1
             = 2*(2*(3) + 1) + 1
             = 2*(7) + 1
             = 15
```

Example implementations:







##### Binary search



The [binary search](https://en.wikipedia.org/wiki/Binary_search) algorithm is a method of searching a [sorted array](https://en.wikipedia.org/wiki/Sorted_array) for a single element by cutting the array in half with each recursive pass. The trick is to pick a midpoint near the center of the array, compare the data at that point with the data being searched and then responding to one of three possible conditions: the data is found at the midpoint, the data at the midpoint is greater than the data being searched for, or the data at the midpoint is less than the data being searched for.

Recursion is used in this algorithm because with each pass a new array is created by cutting the old one in half. The binary search procedure is then called recursively, this time on the new (and smaller) array. Typically the array's size is adjusted by manipulating a beginning and ending index. The algorithm exhibits a logarithmic order of growth because it essentially divides the problem domain in half with each pass.

Example implementation of binary search in C:

```c
 /*
  Call binary_search with proper initial conditions.

  INPUT:
    data is an array of integers SORTED in ASCENDING order,
    toFind is the integer to search for,
    count is the total number of elements in the array

  OUTPUT:
    result of binary_search

 */
 int search(int *data, int toFind, int count)
 {
    //  Start = 0 (beginning index)
    //  End = count - 1 (top index)
    return binary_search(data, toFind, 0, count-1);
 }

 /*
   Binary Search Algorithm.

   INPUT:
        data is a array of integers SORTED in ASCENDING order,
        toFind is the integer to search for,
        start is the minimum array index,
        end is the maximum array index
   OUTPUT:
        position of the integer toFind within array data,
        -1 if not found
 */
 int binary_search(int *data, int toFind, int start, int end)
 {
    //Get the midpoint.
    int mid = start + (end - start)/2;   //Integer division

    //Stop condition.
    if (start > end)
       return -1;
    else if (data[mid] == toFind)        //Found?
       return mid;
    else if (data[mid] > toFind)         //Data is greater than toFind, search lower half
       return binary_search(data, toFind, start, mid-1);
    else                                 //Data is less than toFind, search upper half
       return binary_search(data, toFind, mid+1, end);
 }
```





#### Recursive data structures (structural recursion)

*Main article:* [Recursive data type](https://en.wikipedia.org/wiki/Recursive_data_type)



An important application of recursion in computer science is in defining dynamic **data structures** such as [lists](https://en.wikipedia.org/wiki/List_(abstract_data_type)) and [trees](https://en.wikipedia.org/wiki/Tree_(data_structure)). **Recursive data structures** can dynamically grow to a theoretically infinite size in response to runtime requirements; in contrast, the size of a static array must be set at compile time.



> "**Recursive algorithms** are particularly appropriate when the underlying problem or the data to be treated are defined in recursive terms."[[9\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-9)

The examples in this section illustrate what is known as "[structural recursion](https://en.wikipedia.org/wiki/Structural_recursion)". This term refers to the fact that the **recursive procedures** are acting on data that is defined recursively.

> As long as a programmer derives the template from a data definition, functions employ structural recursion. That is, the recursions in a function's body consume some immediate piece of a given compound value.[[5\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-Felleisen_2002_108-5)

##### Linked lists

*Main article:* [Linked list](https://en.wikipedia.org/wiki/Linked_list)

Below is a C definition of a linked list node structure. Notice especially how the node is defined in terms of itself. The "next" element of *struct node* is a pointer to another *struct node*, effectively creating a list type.

```c
struct node
{
  int data;           // some integer data
  struct node *next;  // pointer to another struct node
};
```

Because the *struct node* data structure is defined **recursively**, procedures that operate on it can be implemented naturally as **recursive procedures**. The *list_print* procedure defined below walks down the list until the list is empty (i.e., the list pointer has a value of NULL). For each node it prints the data element (an integer). In the C implementation, the list remains unchanged by the *list_print* procedure.

```c
void list_print(struct node *list)
{
    if (list != NULL)               // base case
    {
       printf ("%d ", list->data);  // print integer data followed by a space
       list_print (list->next);     // recursive call on the next node
    }
}
```



##### Binary trees

*Main article:* [Binary tree](https://en.wikipedia.org/wiki/Binary_tree)

Below is a simple definition for a binary tree node. Like the node for linked lists, it is defined in terms of itself, recursively. There are two self-referential pointers: left (pointing to the left sub-tree) and right (pointing to the right sub-tree).

```c
struct node
{
  int data;            // some integer data
  struct node *left;   // pointer to the left subtree
  struct node *right;  // point to the right subtree
};
```

Operations on the tree can be implemented using recursion. Note that because there are two self-referencing pointers (left and right), tree operations may require two recursive calls:

```c
// Test if tree_node contains i; return 1 if so, 0 if not.
int tree_contains(struct node *tree_node, int i) {
    if (tree_node == NULL)
        return 0;  // base case
    else if (tree_node->data == i)
        return 1;
    else
        return tree_contains(tree_node->left, i) || tree_contains(tree_node->right, i);
}
```



At most two recursive calls will be made for any given call to *tree_contains* as defined above.



```C
// Inorder traversal:
void tree_print(struct node *tree_node) {
        if (tree_node != NULL) {                  // base case
                tree_print(tree_node->left);      // go left
                printf("%d ", tree_node->data);   // print the integer followed by a space
                tree_print(tree_node->right);     // go right
        }
}
```



```
                              5
                        3              7
                  2          4    6            8
```

```
P(5)
    P(3)
        P(2)
            P(NULL) return 
            printf(2)
            P(NULL) return
        printf(3)
        p(4)
            P(NULL) return 
            printf(4)
            P(NULL) return
            
```



写递归函数的核心在于把我递归的本质：自顶向下，只有子问题都解了，才能够解上一层的问题。使用系统堆栈来实现该过程，因为系统堆栈能够不断地按照递归的顺序进行入栈，直到达到最小的子问题，从而将子问题解决，然后出栈，然后解决上一层子问题，直至最顶层的问题解决了；

每个递归调用都是一条直线，如果递归函数中，出现了两次递归调用，则就是两条线了；

对于有递归性质的问题或者结构，我们可以按照上述递归的思想去编写程序。当谈及需要验证或者模拟递归函数的执行过程的时候，就需要从相反的方向来解决问题了，我们需要从底向上来执行。



### Implementation issues

In actual implementation, rather than a pure recursive function (single check for base case, otherwise recursive step), a number of modifications may be made, for purposes of clarity or efficiency. These include:

- Wrapper function (at top)
- Short-circuiting（简化） the **base case**, aka "Arm's-length recursion" (at bottom)
- Hybrid algorithm (at bottom) – switching to a different algorithm once data is small enough

On the basis of elegance, **wrapper functions** are generally approved, while short-circuiting the base case is frowned upon, particularly in academia. Hybrid algorithms are often used for efficiency, to reduce the overhead of recursion in small cases, and arm's-length recursion is a special case of this.





### Recursion versus iteration

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





#### Multiply recursive problems

Multiply recursive problems are inherently recursive, because of prior state they need to track. One example is [tree traversal](https://en.wikipedia.org/wiki/Tree_traversal) as in [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search); though both recursive and iterative methods are used,[[19\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-19) they contrast with list traversal and linear search in a list, which is a singly recursive and thus naturally iterative method. Other examples include [divide-and-conquer algorithms](https://en.wikipedia.org/wiki/Divide-and-conquer_algorithm) such as [Quicksort](https://en.wikipedia.org/wiki/Quicksort), and functions such as the [Ackermann function](https://en.wikipedia.org/wiki/Ackermann_function). All of these algorithms can be implemented iteratively with the help of an explicit [stack](https://en.wikipedia.org/wiki/Stack_(data_structure)), but the programmer effort involved in managing the stack, and the complexity of the resulting program, arguably outweigh any advantages of the iterative solution.



#### Refactoring recursion

Recursive algorithms can be replaced with non-recursive counterparts.[[20\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-20). One method for replacing recursive algorithms is to simulate them using [heap memory](https://en.wikipedia.org/wiki/Memory_management) in place of [stack memory](https://en.wikipedia.org/wiki/Stack-based_memory_allocation).[[21\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-21) An alternative is to develop a replacement algorithm entirely based on non-recursive methods, which can be challenging.[[22\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-22) For example, recursive algorithms for [matching wildcards](https://en.wikipedia.org/wiki/Matching_wildcards), such as [Rich Salz](https://en.wikipedia.org/wiki/Rich_Salz)' [wildmat](https://en.wikipedia.org/wiki/Wildmat) algorithm,[[23\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-23) were once typical. Non-recursive algorithms for the same purpose, such as the [Krauss matching wildcards algorithm](https://en.wikipedia.org/wiki/Krauss_matching_wildcards_algorithm), have been developed to avoid the drawbacks of recursion[[24\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-24) and have improved only gradually based on techniques such as collecting [tests](https://en.wikipedia.org/wiki/Software_testing) and [profiling](https://en.wikipedia.org/wiki/Profiling_(computer_programming)) performance.[[25\]](https://en.wikipedia.org/wiki/Recursion_(computer_science)#cite_note-25)



### Tail-recursive functions

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



### Time-efficiency of recursive algorithms

The [time efficiency](https://en.wikipedia.org/wiki/Time_complexity) of recursive algorithms can be expressed in a [recurrence relation](https://en.wikipedia.org/wiki/Recurrence_relation) of [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation). They can (usually) then be simplified into a single Big-O term.

#### Shortcut rule (master theorem)

*Main article:* [Master theorem (analysis of algorithms)](https://en.wikipedia.org/wiki/Master_theorem_(analysis_of_algorithms))

If the time-complexity of the function is in the form

$ T(n)=a\cdot T(n/b)+f(n) $

Then the Big O of the time-complexity is thus:

- If $ f(n)=O(n^{\log _{b}a-\epsilon }) $ for some constant $ \epsilon >0 $, then $ T(n)=\Theta (n^{\log _{b}a}) $
- If $ f(n)=\Theta (n^{\log _{b}a}) $, then $ T(n)=\Theta (n^{\log _{b}a}\log n) $
- If $ f(n)=\Omega (n^{\log _{b}a+\epsilon }) $ for some constant $ \epsilon >0 $, and if $ a\cdot f(n/b)\leq c\cdot f(n) $ for some constant *c* < 1 and all sufficiently large *n*, then $ T(n)=\Theta (f(n)) $

where *a* represents the number of recursive calls at each level of recursion, *b* represents by what factor smaller the input is for the next level of recursion (i.e. the number of pieces you divide the problem into), and *f* (*n*) represents the work the function does independent of any recursion (e.g. partitioning, recombining) at each level of recursion.

