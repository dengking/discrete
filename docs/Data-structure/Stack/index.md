# Stack

"stack"即"栈"，本章对它进行总结；它是一种简单，但是强大、用途广泛的ADT。

## wikipedia [Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) 

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a *stack* is an [abstract data type](https://en.wikipedia.org/wiki/Abstract_data_type) that serves as a [collection](https://en.wikipedia.org/wiki/Collection_(computing)) of elements, with two principal operations:

1. **push**, which adds an element to the collection, and

2. **pop**, which removes the most recently added element that was not yet removed.

The order in which elements come off a stack gives rise to its alternative name, **LIFO** (**last in, first out**). Additionally, a [peek](https://en.wikipedia.org/wiki/Peek_(data_type_operation)) operation may give access to the top without modifying the stack. The name "stack" for this type of structure comes from the analogy to a set of physical items stacked on top of each other, which makes it easy to take an item off the top of the stack, while getting to an item deeper in the stack may require taking off multiple other items first. 

A stack is needed to implement [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search).

### Security

Some computing environments use stacks in ways that may make them vulnerable to [security breaches](https://en.wikipedia.org/wiki/Security_breaches) and attacks. Programmers working in such environments must take special care to avoid the pitfalls of these implementations.



## Feature of stack

### 先进后出(先进后出)

栈的后进先出（先进后出）特性其实存在着一种天然的**逆序**（与此相反的是queue的先进先出则是天然的**顺序**）

- 逆序

### 有进有出

括号匹配（正括号进栈，反括号出栈），函数执行（调用函数进栈，函数返回出栈）

### 线性

栈是一种**线性**的数据结构，一些**线性序列**可以基于栈来做一些**相邻元素**的基于**某种关系**的**聚合**。

- 相邻
- 基于某种关系的聚合



## Applications of stacks

栈有着非常多的应用，这些纷繁复杂的应用主要使用了栈的各种特性。

### Expression evaluation and syntax parsing/PDA

> NOTE:
>
> wikipedia [Pushdown automaton](https://en.wikipedia.org/wiki/Pushdown_automaton) 
>
> [Stack machine](https://en.wikipedia.org/wiki/Stack_machine) 

Calculators employing [reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) use a stack structure to hold values. Expressions can be represented in prefix, postfix or infix notations and conversion from one form to another may be accomplished using a stack. Many compilers use a stack for parsing the syntax of expressions, program blocks etc. before translating into low level code. Most programming languages are [context-free languages](https://en.wikipedia.org/wiki/Context-free_grammar), allowing them to be parsed with stack based machines.

#### 括号匹配问题

其实括号匹配问题也可以使用这种思路来进行分析：包含有括号对的字符串是**线性**的，在进行括号匹配的时候，我们仅仅关注的是括号字符而忽视所有的其他字符，所以从这个角度来看的话，字符串仅仅包含了括号对，所以其中的元素都是相邻的；**正括号**与**反括号**之间存在的关系是**匹配关系**，只有当相邻两个括号字符之间存在着**匹配关系**的时候，我们才将它们**聚合**（对应这将出栈）；其实这种框架是能够解决非常多的类似这样的问题的



#### [Nearest-neighbor chain algorithm](https://en.wikipedia.org/wiki/Nearest-neighbor_chain_algorithm)

The [nearest-neighbor chain algorithm](https://en.wikipedia.org/wiki/Nearest-neighbor_chain_algorithm), a method for [agglomerative hierarchical clustering](https://en.wikipedia.org/wiki/Agglomerative_hierarchical_clustering) based on maintaining a stack of clusters, each of which is the nearest neighbor of its predecessor on the stack. When this method finds a pair of clusters that are mutual nearest neighbors, they are popped and merged.[[13\]](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)#cite_note-13)

> NOTE:
>
> 一、[agglomerative hierarchical clustering](https://en.wikipedia.org/wiki/Agglomerative_hierarchical_clustering) 即 "聚合式阶层分群法"，它非常类似于parsing中对stack的使用，它们都是使用stack来构建tree



### Backtracking/DFS

Main article: [Backtracking](https://en.wikipedia.org/wiki/Backtracking)



### Compile time memory management

Main articles: [Stack-based memory allocation](https://en.wikipedia.org/wiki/Stack-based_memory_allocation) and [Stack machine](https://en.wikipedia.org/wiki/Stack_machine)

### Efficient algorithms

Several [algorithms](https://en.wikipedia.org/wiki/Algorithm) use a stack (separate from the usual function call stack of most programming languages) as the principle [data structure](https://en.wikipedia.org/wiki/Data_structure) with which they organize their information. These include:

### Monotonic stack

#### [Graham scan](https://en.wikipedia.org/wiki/Graham_scan)

[Graham scan](https://en.wikipedia.org/wiki/Graham_scan), an algorithm for the [convex hull](https://en.wikipedia.org/wiki/Convex_hull) of a two-dimensional system of points. A convex hull of a subset of the input is maintained in a stack, which is used to find and remove concavities(凹陷) in the boundary when a new point is added to the hull.

> NOTE:
>
> 一、monotonic stack

#### [SMAWK algorithm](https://en.wikipedia.org/wiki/SMAWK_algorithm) 

Part of the [SMAWK algorithm](https://en.wikipedia.org/wiki/SMAWK_algorithm) for finding the row minima(极小值) of a monotone matrix(单调矩阵) uses stacks in a similar way to Graham scan.

> NOTE:
>
> 一、monotonic stack
>
> 使用栈来表示**最近**

#### [All nearest smaller values](https://en.wikipedia.org/wiki/All_nearest_smaller_values)

[All nearest smaller values](https://en.wikipedia.org/wiki/All_nearest_smaller_values), the problem of finding, for each number in an array, the closest preceding number that is smaller than it. One algorithm for this problem uses a stack to maintain a collection of candidates for the nearest smaller value. For each position in the array, the stack is popped until a smaller value is found on its top, and then the value in the new position is pushed onto the stack.

> NOTE:
>
> 一、monotonic stack

### Reverse by stack

栈的后进先出的特性是一种倒序的特性，它非常适合于实现一些需要执行逆转操作的算法；

### 用stack来保存过去状态

"括号匹配问题"和"[All nearest smaller values](https://en.wikipedia.org/wiki/All_nearest_smaller_values)"其实非常类似：

1、使用stack来保存状态

2、当匹配的时候，则pop

3、reverse-by-stack



### [Stack-oriented programming](https://en.wikipedia.org/wiki/Stack-oriented_programming)



## 显示栈和隐式栈

隐式栈是指使用call stack，比如：

- python的`pgen`使用隐式栈来实现括号的匹配



## geeksforgeeks [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/) 

> NOTE:
>
> geeksforgeeks [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/) 对stack的相关内容总结的非常好

Stack is a **linear data structure** which follows a particular order in which the operations are performed. The order may be LIFO(Last In First Out) or FILO(First In Last Out).

![img](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/stack.png)

There are many real-life examples of a stack. Consider an example of plates(盘子) stacked(堆叠) over one another in the canteen(餐厅). The plate which is at the top is the first one to be removed, i.e. the plate which has been placed at the bottommost position remains in the stack for the longest period of time. So, it can be simply seen to follow LIFO(Last In First Out)/FILO(First In Last Out) order.



###  Topics : 

- [Introduction](https://www.geeksforgeeks.org/stack-data-structure/#intro)
- [Design and Implementation](https://www.geeksforgeeks.org/stack-data-structure/#design)
- [Standard Problems](https://www.geeksforgeeks.org/stack-data-structure/#standard)

- [Operations on Stack](https://www.geeksforgeeks.org/stack-data-structure/#operations)
- [Misc](https://www.geeksforgeeks.org/stack-data-structure/#misc)
- [Quick Links](https://www.geeksforgeeks.org/stack-data-structure/#quick)

###  Introduction : 

1、[Introduction to Stack](https://www.geeksforgeeks.org/stack-data-structure-introduction-program/)

2、[Stack in C++ STL](https://www.geeksforgeeks.org/stack-in-cpp-stl/)

3、[Stack Class in Java](https://www.geeksforgeeks.org/stack-class-in-java/)

4、[Stack in Python](https://www.geeksforgeeks.org/stack-in-python/)

5、[Stack in C#](https://www.geeksforgeeks.org/c-sharp-stack-with-examples/)



###  Design and Implementation : 


1、 [Implement Queue using Stacks](https://www.geeksforgeeks.org/queue-using-stacks/)

3、 [Design and Implement Special Stack Data Structure | Added Space Optimized Version](https://www.geeksforgeeks.org/design-and-implement-special-stack-data-structure/)

4、 [Implement two stacks in an array](https://www.geeksforgeeks.org/implement-two-stacks-in-an-array/)

5、 [Implement Stack using Queues](https://www.geeksforgeeks.org/implement-stack-using-queue/)

6、 [Design a stack with operations on middle element](https://www.geeksforgeeks.org/design-a-stack-with-find-middle-operation/)

7、 [How to efficiently implement k stacks in a single array?](https://www.geeksforgeeks.org/efficiently-implement-k-stacks-single-array/)

8、 [How to create mergable stack?](https://www.geeksforgeeks.org/create-mergable-stack/)

9、 [Design a stack that supports getMin() in O(1) time and O(1) extra space](https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra-space/)

> NOTE: 
>
> 参见 `max-min-stack` 章节

10、 [Implement a stack using single queue](https://www.geeksforgeeks.org/implement-a-stack-using-single-queue/)

11、 [How to implement stack using priority queue or heap?](https://www.geeksforgeeks.org/implement-stack-using-priority-queue-or-heap/)

12、 [Create a customized data structure which evaluates functions in O(1)](https://www.geeksforgeeks.org/create-customized-data-structure-evaluates-functions-o1/)

13、 [Implement Stack and Queue using Deque](https://www.geeksforgeeks.org/implement-stack-queue-using-deque/)



###  Standard Problems based on Stack : 

> NOTE: 
>
> 一、fix conversion
>
> 二、Expression Evaluation
>
> 三、括号匹配

1、[Infix to Postfix Conversion using Stack](https://www.geeksforgeeks.org/stack-set-2-infix-to-postfix/)

2、[Prefix to Infix Conversion](https://www.geeksforgeeks.org/prefix-infix-conversion/)

3、[Prefix to Postfix Conversion](https://www.geeksforgeeks.org/prefix-postfix-conversion/)

4、[Postfix to Prefix Conversion](https://www.geeksforgeeks.org/postfix-prefix-conversion/)

5、[Postfix to Infix](https://www.geeksforgeeks.org/postfix-to-infix/)

6、[Convert Infix To Prefix Notation](https://www.geeksforgeeks.org/convert-infix-prefix-notation/)



7、[The Stock Span Problem](https://www.geeksforgeeks.org/the-stock-span-problem/)

> NOTE: 
>
> 1、股票价格跨度

8、[Check for balanced parentheses in an expression](https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/)



9、[Next Greater Element](https://www.geeksforgeeks.org/next-greater-element/)



10、[Next Greater Frequency Element](https://www.geeksforgeeks.org/next-greater-frequency-element/)



11、[Number of NGEs to the right](https://www.geeksforgeeks.org/number-nges-right/)



12、[Maximum product of indexes of next greater on left and right](https://www.geeksforgeeks.org/maximum-product-of-indexes-of-next-greater-on-left-and-right/)



13、[The Celebrity Problem](https://www.geeksforgeeks.org/the-celebrity-problem/)



14、[Expression Evaluation](https://www.geeksforgeeks.org/expression-evaluation/)



15、[Arithmetic Expression Evalution](https://www.geeksforgeeks.org/arithmetic-expression-evalution/)

16、[Evaluation of Postfix Expression](https://www.geeksforgeeks.org/stack-set-4-evaluation-postfix-expression/)



17、[Iterative Tower of Hanoi](https://www.geeksforgeeks.org/iterative-tower-of-hanoi/)



18、[Print next greater number of Q queries](https://www.geeksforgeeks.org/print-next-greater-number-q-queries/)



###  Operations on Stack : 


1、 [Reverse a stack using recursion](https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/)

2、 [Sort a stack using recursion](https://www.geeksforgeeks.org/sort-a-stack-using-recursion/)

3、 [Sort a stack using a temporary stack](https://www.geeksforgeeks.org/sort-stack-using-temporary-stack/)

4、 [Reverse a stack without using extra space in O(n)](https://www.geeksforgeeks.org/reverse-stack-without-using-extra-space/)

5、 [Delete middle element of a stack](https://www.geeksforgeeks.org/delete-middle-element-stack/)

6、 [Sorting array using Stacks](https://www.geeksforgeeks.org/sorting-array-using-stacks/)

7、 [Delete array elements which are smaller than next or become smaller](https://www.geeksforgeeks.org/delete-array-elements-which-are-smaller-than-next-or-become-smaller/)

8、 [Check if a queue can be sorted into another queue using a stack](https://www.geeksforgeeks.org/check-queue-can-sorted-another-queue-using-stack/)

9、 [Reverse individual words](https://www.geeksforgeeks.org/reverse-individual-words/)

10、 [Count subarrays where second highest lie before highest](https://www.geeksforgeeks.org/count-subarrays-second-highest-lie-highest/)

11、 [Check if an array is stack sortable](https://www.geeksforgeeks.org/check-array-stack-sortable/)

###  Misc : 


1、 [Iterative Postorder Traversal | Set 1 (Using Two Stacks)](https://www.geeksforgeeks.org/iterative-postorder-traversal/)

2、 [Iterative Postorder Traversal | Set 2 (Using One Stack)](https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/)

3、 [Merge Overlapping Intervals](https://www.geeksforgeeks.org/merging-intervals/)

4、 [Largest Rectangular Area in a Histogram | Set 2](https://www.geeksforgeeks.org/largest-rectangle-under-histogram/)

5、 [Print ancestors of a given binary tree node without recursion](https://www.geeksforgeeks.org/print-ancestors-of-a-given-binary-tree-node-without-recursion/)

6、 [Reverse a string using stack](https://www.geeksforgeeks.org/stack-set-3-reverse-string-using-stack/)

7、 [Program for Tower of Hanoi](https://www.geeksforgeeks.org/c-program-for-tower-of-hanoi/)

8、 [Find maximum depth of nested parenthesis in a string](https://www.geeksforgeeks.org/find-maximum-depth-nested-parenthesis-string/)

9、 [Find maximum of minimum for every window size in a given array](https://www.geeksforgeeks.org/find-the-maximum-of-minimums-for-every-window-size-in-a-given-array/)

10、 [Length of the longest valid substring](https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/)

11、 [Iterative Depth First Traversal of Graph](https://www.geeksforgeeks.org/iterative-depth-first-traversal/)

12、 [Minimum number of bracket reversals needed to make an expression balanced](https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-needed-to-make-an-expression-balanced/)

13、 [Expression contains redundant bracket or not](https://www.geeksforgeeks.org/expression-contains-redundant-bracket-not/)

14、 [Identify and mark unmatched parenthesis in an expression](https://www.geeksforgeeks.org/identify-mark-unmatched-parenthesis-expression/)

15、 [Check if two expressions with brackets are same](https://www.geeksforgeeks.org/check-two-expressions-brackets/)

16、 [Find index of closing bracket for a given opening bracket in an expression](https://www.geeksforgeeks.org/find-index-closing-bracket-given-opening-bracket-expression/)

17、 [Check for balanced parentheses in an expression](https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/)

18、 [Balanced expression with replacement](https://www.geeksforgeeks.org/balanced-expression-replacement/)

19、 [Check if a given array can represent Preorder Traversal of Binary Search Tree](https://www.geeksforgeeks.org/check-if-a-given-array-can-represent-preorder-traversal-of-binary-search-tree/)

20、 [Form minimum number from given sequence](https://www.geeksforgeeks.org/form-minimum-number-from-given-sequence/)

21、 [Find if an expression has duplicate parenthesis or not](https://www.geeksforgeeks.org/find-expression-duplicate-parenthesis-not/)

22、 [Find maximum difference between nearest left and right smaller elements](https://www.geeksforgeeks.org/find-maximum-difference-between-nearest-left-and-right-smaller-elements/)

23、 [Find next Smaller of next Greater in an array](https://www.geeksforgeeks.org/find-next-smaller-next-greater-array/)

24、 [Find maximum sum possible equal sum of three stacks](https://www.geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/)

25、 [Count natural numbers whose all permutation are greater than that number](https://www.geeksforgeeks.org/count-natural-numbers-whose-permutation-greater-number/)

26、 [Delete consecutive same words in a sequence](https://www.geeksforgeeks.org/delete-consecutive-words-sequence/)

27、 [Decode a string recursively encoded as count followed by substring](https://www.geeksforgeeks.org/decode-string-recursively-encoded-count-followed-substring/)

28、 [Bubble sort using two Stacks](https://www.geeksforgeeks.org/bubble-sort-using-two-stacks/)

29、 [Pattern Occurrences : Stack Implementation Java](https://www.geeksforgeeks.org/pattern-occurrences-stack-implementation-java/)

30、 [Iterative method to find ancestors of a given binary tree](https://www.geeksforgeeks.org/iterative-method-to-find-ancestors-of-a-given-binary-tree/)

31、 [Stack Permutations (Check if an array is stack permutation of other)](https://www.geeksforgeeks.org/stack-permutations-check-if-an-array-is-stack-permutation-of-other/)

32、 [Tracking current Maximum Element in a Stack](https://www.geeksforgeeks.org/tracking-current-maximum-element-in-a-stack/)

33、 [Check mirror in n-ary tree](https://www.geeksforgeeks.org/check-mirror-n-ary-tree/)

34、 [Reverse a number using stack](https://www.geeksforgeeks.org/reverse-number-using-stack/)

35、 [Reversing the first K elements of a Queue](https://www.geeksforgeeks.org/reversing-first-k-elements-queue/)

36、 [Reversing a Queue](https://www.geeksforgeeks.org/reversing-a-queue/)

37、 [Check if stack elements are pairwise consecutive](https://www.geeksforgeeks.org/check-if-stack-elements-are-pairwise-consecutive/)

38、 [Spaghetti Stack](https://www.geeksforgeeks.org/g-fact-87/)

39、 [Interleave the first half of the queue with second half](https://www.geeksforgeeks.org/interleave-first-half-queue-second-half/)

40、 [Remove brackets from an algebraic string containing + and – operators](https://www.geeksforgeeks.org/remove-brackets-algebraic-string-containing-operators/)

41、 [Growable array based stack](https://www.geeksforgeeks.org/growable-array-based-stack/)

42、 [Range Queries for Longest Correct Bracket Subsequence](https://www.geeksforgeeks.org/range-queries-longest-correct-bracket-subsequence-set-2/)

###  Quick Links : 

- [‘Practice Problems’ on Stack](https://practice.geeksforgeeks.org/topics/Stack/)
- [‘Videos’ on Stack](https://www.youtube.com/playlist?list=PLqM7alHXFySF7Lap-wi5qlaD8OEBx9RMV)
- [‘Quizzes’ on Stack](https://www.geeksforgeeks.org/data-structure-gq/stack-gq/)

