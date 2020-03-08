# Summary

## 前言

在前面，我们讨论了一系列概念，它们之间是有着一定的关联的，本文就对它们进行对比，进行总结，下面是中文部分。

## 正文

无论是Mathematical induction，还是Structural induction，它们本质上都是[proof method](https://en.wikipedia.org/wiki/Proof_method) （证明方法），它描述的是一种推广。

[Recursive definition](./Recursion/Recursive-definition.md)（也叫做**inductive definition**）正如其名，它是definition，是specification，所以需要非常严格，它不涉及实现。



| 递归                                                         | 归纳                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| [Recursion](./Recursion/Recursion.md)                        | [Induction](./Induction-and-deduction/Induction.md)          |
| [Corecursion](./Recursion/Corecursion.md)                    | [Coinduction](./Induction-and-deduction/Coinduction.md)      |
| [Structural recursion](./Induction-and-deduction/Induction.md) | [Structural induction](./Induction-and-deduction/Induction.md) |

关于Structural recursion和Structural induction，参见[Structural induction](./Induction-and-deduction/Induction.md)。

[Corecursion](./Recursion/Corecursion.md)、[Induction](./Induction-and-deduction/Induction.md)、iteration的方向相同，都是自底向上；

[Recursion](./Recursion/Recursion.md)、[Structural recursion](./Induction-and-deduction/Induction.md)的方向相同，都是自顶向下；



## Recursion VS corecursion

recursion 和 corecursion 的计算方向是相反：对于一个 [recurrence relations](https://en.wikipedia.org/wiki/Recurrence_relation) ，如*n! := n × (n - 1)!*.，recursion是从左至右，但是corecursion是从右至左，但是能够殊途同归

- recursion works **analytically** VS corecursion works **synthetically**
- recursion **top-down** VS corecursion **bottom-up**
- recursion **reduce** VS corecursion **produce**

在[Tree traversal](https://en.wikipedia.org/wiki/Tree_traversal)中有如下描述：

**Depth-first search** is easily implemented via a **stack**, including **recursively** (via the **call stack**), while **breadth-first search** is easily implemented via a **queue**, including **corecursively**.

## Recursion VS induction

无论是induction还是recursion，都需要base  case。

Induction本质上都是[proof method](https://en.wikipedia.org/wiki/Proof_method) 。

在维基百科[Structural induction](https://en.wikipedia.org/wiki/Structural_induction)中有这样的描述：

> A structurally recursive function uses the same idea to define a recursive function: "base cases" handle each minimal structure and a rule for recursion. Structural recursion is usually proved correct by structural induction; 

另外参见：https://www.cs.cmu.edu/~rwh/introsml/techniques/indrec.htm ，非常好的一篇文章。





## Structural recursion versus generative recursion

在[Recursion (computer science)](https://en.wikipedia.org/wiki/Recursion_(computer_science))中有专门的章节来描述Structural versus generative recursion。



### [How does structural recursion differ from generative recursion?](https://stackoverflow.com/questions/14268749/how-does-structural-recursion-differ-from-generative-recursion)



The description of generative recursion in [Wikipedia](http://en.wikipedia.org/wiki/Recursion_(computer_science)#Structural_versus_generative_recursion) is clear to me, but I'm confused about the concept of structural recursion.

Can someone explain if a function calculating nth Fibonacci number and a function calculating factorial from 1 to N will be structural or generative?



***COMMENTS***

- My two pennies: Fib is **generative recursive** using that definition because the data is "generated" as it goes along. Whereas, according to the article, **structural recursion** is about traversing an [existing] graph. The article goes on to state that an crucial distinction is that **structural recursion** can be proven to terminate through **structural induction** .. – user166390



#### [A](https://stackoverflow.com/a/14268901)

The key difference between **structural** and **generative recursion** is where a **recursive procedure** gets the data that it works on and how it processes that data（ **recursive procedure** gets the data that it works on其实就是recursion function的**入参**）. Specifically, for **structural recursion**, a **recursive call** is made on a **subset** of the original input data. Whereas for **generative recursion**, a **recursive call** is made on data that was **constructed/calculated** from the original input data.

***SUMMARY*** : 上面这段话总结地是非常好的；

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

When doing structural recursion, you are "undoing" the operation from which these structures are built out of one another. For example, the `NumberOfNodes` function "undoes" the construction of taking a node and prepending it to an existing list. The `Find` operator "undoes" the operation of gluing a node to two other trees. Therefore, it's easy to see why these functions have to terminate - eventually, you "undo" all of the operations that went in to building up the object in the first place, and the recursion stops.

On the other hand, consider **Quicksort**, which does the following:

1. Pick a pivot.
2. Create three new lists: one of all elements less than the pivot, one of all elements greater than the pivot, and one of all elements equal to the pivot.
3. Recursively sort the first and second of these lists.
4. Concatenate the list of smaller, equal, and larger values.

Here, the **recursive calls** are being made on smaller arrays that weren't part of the original input - the lists had to be created from the data. (Typically, an implementation would reuse space for these lists, but those sublists weren't guaranteed to exist directly within the input).

This distinction is blurry（模糊的） when it comes to **natural numbers**. Usually, natural numbers are recursively defined as follows:

- 0 is a natural number.
- If n is a natural number, n + 1 is a natural number.
- Nothing else is a natural number.

Under this definition, the number n is a "part" of n + 1. Therefore, this recursive code to compute n! is structural recursion:

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