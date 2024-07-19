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



## geeksforgeeks [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/) 

geeksforgeeks [Stack Data Structure](https://www.geeksforgeeks.org/stack-data-structure/) 对stack的相关内容总结的非常好，本章主要以它为主题来梳理stack的各种考题。



## 显示栈和隐式栈

隐式栈是指使用call stack，比如：

- python的`pgen`使用隐式栈来实现括号的匹配


