# Structural recursion versus generative recursion

## wikipedia [Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science)) # Structural versus generative recursion

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



## stackoverflow [How does structural recursion differ from generative recursion?](https://stackoverflow.com/questions/14268749/how-does-structural-recursion-differ-from-generative-recursion)



The description of generative recursion in [Wikipedia](http://en.wikipedia.org/wiki/Recursion_(computer_science)#Structural_versus_generative_recursion) is clear to me, but I'm confused about the concept of structural recursion.

Can someone explain if a function calculating nth Fibonacci number and a function calculating factorial from 1 to N will be structural or generative?



### COMMENTS

My two pennies: Fib is **generative recursive** using that definition because the data is "generated" as it goes along. Whereas, according to the article, **structural recursion** is about traversing an [existing] graph. The article goes on to state that an crucial distinction is that **structural recursion** can be proven to terminate through **structural induction** .. – user166390



### [A](https://stackoverflow.com/a/14268901)

The key difference between **structural** and **generative recursion** is where a **recursive procedure** gets the data that it works on and how it processes that data（ "**recursive procedure** gets the data that it works on"其实就是recursion function的**入参**）. Specifically, for **structural recursion**, a **recursive call** is made on a **subset** of the original input data. Whereas for **generative recursion**, a **recursive call** is made on data that was **constructed/calculated** from the original input data.

> NOTE: 上面这段话总结地是非常好的；

For example, if you wanted to count the number of elements in a linked list, you could do the following:

```C
int NumberOfNodes(ListNode* node) {
    if (node == nullptr) return 0;
    return 1 + NumberOfNodes(node->next);
}
```

Here, the recursive call to `NumberOfNodes` is being made on `node->next`, which is a piece of the original input which already existed. In this case, the recursion works by breaking down the input into smaller pieces, then recursing on the smaller pieces.

Similarly, this code to search a BST for a value would be structural recursion, because the recursive calls are to subparts of the original input:

```C
TreeNode* Find(TreeNode* root, DataType value) {
    if (root == nullptr) return nullptr;
    if (value < root->value) return Find(root->left, value);
    else return Find(root->right, value);
```

The term "structural recursion" comes from the fact that these structures (lists, BSTs, etc.) can be defined recursively:

- A list is either nothing, or a cell followed by a list.
- A binary tree is either nothing, or a node with two binary trees as children.

When doing structural recursion, you are "undoing"(解开、拆解) the operation from which these structures are built out of one another. For example, the `NumberOfNodes` function "undoes" the construction of taking a node and prepending it to an existing list. The `Find` operator "undoes" the operation of gluing(粘合) a node to two other trees. Therefore, it's easy to see why these functions have to terminate - eventually, you "undo" all of the operations that went in to building up the object in the first place, and the recursion stops.

> NOTE:
>
> 1、structural recursion对应的是undo，即拆解structure的过程

On the other hand, consider **Quicksort**, which does the following:

1、Pick a pivot.

2、Create three new lists: one of all elements less than the pivot, one of all elements greater than the pivot, and one of all elements equal to the pivot.

3、Recursively sort the first and second of these lists.

4、Concatenate the list of smaller, equal, and larger values.

Here, the **recursive calls** are being made on smaller arrays that weren't part of the original input - the lists had to be created from the data. (Typically, an implementation would reuse space for these lists, but those sublists weren't guaranteed to exist directly within the input).

This distinction is blurry（模糊的） when it comes to **natural numbers**. Usually, natural numbers are recursively defined as follows:

- 0 is a natural number.
- If n is a natural number, n + 1 is a natural number.
- Nothing else is a natural number.

Under this definition, the number `n` is a "part" of `n + 1`. Therefore, this recursive code to compute `n!` is structural recursion:

```C
int Factorial(int n) {
    if (n == 0) return 1;
    return n * Factorial(n - 1);
}
```

This is structural recursion, because the argument n - 1 was a "part" of the original input n.

Similarly, by this definition, computing the nth Fibonacci number recursively counts as structural recursion:

```C
int Fibonacci(int n) {
    if (n <= 1) return n;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
```

This is considered structural recursion because n - 1 is a part of n (formed by "undoing" the +1) and n - 2 is a part of n - 1 (again formed by "undoing" the +1).

On the other hand, this code to compute gcd would be considered generative recursion, rather than structural recursion:

```C
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
```

The reasoning is that since `a % b` is "computed" from `a` and `b`, rather than formed by "undoing" some number of +1 operations, the data is generated.

The reason that **generative recursion** is different from **structural recursion** is that there's no guarantee that it terminates. For example, think about this function:

```C
int BadTimes(int a, int b) {
    if (a == 0 && b == 0) return 0;
    return BadTimes(a * 2, b - 1);
}
```

This generative recursive function never terminates: `a` keeps getting bigger even though `b` keeps getting smaller.

Honestly, I've never heard of this distinction before and I teach courses in discrete math and programming. I wouldn't worry too much about it unless someone is requiring you to know the difference.

Hope this helps!