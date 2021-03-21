# wikipedia [Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a *stack* is an [abstract data type](https://en.wikipedia.org/wiki/Abstract_data_type) that serves as a [collection](https://en.wikipedia.org/wiki/Collection_(computing)) of elements, with two principal operations:

- **push**, which adds an element to the collection, and
- **pop**, which removes the most recently added element that was not yet removed.

The order in which elements come off a stack gives rise to its alternative name, **LIFO** (**last in, first out**). Additionally, a [peek](https://en.wikipedia.org/wiki/Peek_(data_type_operation)) operation may give access to the top without modifying the stack. The name "stack" for this type of structure comes from the analogy to a set of physical items stacked on top of each other, which makes it easy to take an item off the top of the stack, while getting to an item deeper in the stack may require taking off multiple other items first. 

Considered as a [linear data structure](https://en.wikipedia.org/wiki/Linear_data_structure), or more abstractly a sequential collection, the push and pop operations occur only at one end of the structure, referred to as the *top* of the stack. This makes it possible to implement a stack as a [singly linked list](https://en.wikipedia.org/wiki/Singly_linked_list) and a pointer to the top element. A stack may be implemented to have a bounded capacity. If the stack is full and does not contain enough space to accept an entity to be pushed, the stack is then considered to be in an [overflow](https://en.wikipedia.org/wiki/Stack_overflow) state. The pop operation removes an item from the top of the stack.

A stack is needed to implement [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search).





## Applications of stacks



### Expression evaluation and syntax parsing

Calculators employing [reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) use a stack structure to hold values. Expressions can be represented in prefix, postfix or infix notations and conversion from one form to another may be accomplished using a stack. Many compilers use a stack for parsing the syntax of expressions, program blocks etc. before translating into low level code. Most programming languages are [context-free languages](https://en.wikipedia.org/wiki/Context-free_grammar), allowing them to be parsed with stack based machines.



### Backtracking

Main article: [Backtracking](https://en.wikipedia.org/wiki/Backtracking)

Another important application of stacks is [backtracking](https://en.wikipedia.org/wiki/Backtracking). Consider a simple example of finding the correct path in a maze. There are a series of points, from the starting point to the destination. We start from one point. To reach the final destination, there are several paths. Suppose we choose a random path. After following a certain path, we realise that the path we have chosen is wrong. So we need to find a way by which we can return to the beginning of that path. This can be done with the use of stacks. With the help of stacks, we remember the point where we have reached. This is done by pushing that point into the stack. In case we end up on the wrong path, we can pop the last point from the stack and thus return to the last point and continue our quest to find the right path. This is called backtracking.

The prototypical example of a backtracking algorithm is [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search), which finds all vertices of a graph that can be reached from a specified starting vertex. Other applications of backtracking involve searching through spaces that represent potential solutions to an optimization problem. [Branch and bound](https://en.wikipedia.org/wiki/Branch_and_bound) is a technique for performing such backtracking searches without exhaustively searching all of the potential solutions in such a space.

### Compile time memory management

Main articles: [Stack-based memory allocation](https://en.wikipedia.org/wiki/Stack-based_memory_allocation) and [Stack machine](https://en.wikipedia.org/wiki/Stack_machine)

A number of [programming languages](https://en.wikipedia.org/wiki/Programming_language) are [stack-oriented](https://en.wikipedia.org/wiki/Stack-oriented_programming_language), meaning they define most basic operations (adding two numbers, printing a character) as taking their arguments from the stack, and placing any return values back on the stack. For example, [PostScript](https://en.wikipedia.org/wiki/PostScript) has a return stack and an operand stack, and also has a graphics state stack and a dictionary stack. Many [virtual machines](https://en.wikipedia.org/wiki/Virtual_machine) are also stack-oriented, including the [p-code machine](https://en.wikipedia.org/wiki/P-code_machine) and the [Java Virtual Machine](https://en.wikipedia.org/wiki/Java_Virtual_Machine).

Almost all [calling conventions](https://en.wikipedia.org/wiki/Calling_convention)‍—‌the ways in which [subroutines](https://en.wikipedia.org/wiki/Subroutine) receive their parameters and return results‍—‌use a special stack (the "[call stack](https://en.wikipedia.org/wiki/Call_stack)") to hold information about procedure/function calling and nesting in order to switch to the context of the called function and restore to the caller function when the calling finishes. The functions follow a runtime protocol between caller and callee to save arguments and return value on the stack. Stacks are an important way of supporting nested or [recursive](https://en.wikipedia.org/wiki/Recursion) function calls. This type of stack is used implicitly by the compiler to support CALL and RETURN statements (or their equivalents) and is not manipulated directly by the programmer.

Some programming languages use the stack to store data that is local to a procedure. Space for local data items is allocated from the stack when the procedure is entered, and is deallocated when the procedure exits. The [C programming language](https://en.wikipedia.org/wiki/C_(programming_language)) is typically implemented in this way. Using the same stack for both data and procedure calls has important security implications (see below) of which a programmer must be aware in order to avoid introducing serious security bugs into a program.

### Efficient algorithms

Several [algorithms](https://en.wikipedia.org/wiki/Algorithm) use a stack (separate from the usual function call stack of most programming languages) as the principle [data structure](https://en.wikipedia.org/wiki/Data_structure) with which they organize their information. These include:

- [Graham scan](https://en.wikipedia.org/wiki/Graham_scan), an algorithm for the [convex hull](https://en.wikipedia.org/wiki/Convex_hull) of a two-dimensional system of points. A convex hull of a subset of the input is maintained in a stack, which is used to find and remove concavities in the boundary when a new point is added to the hull.[[10\]](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)#cite_note-10)
- Part of the [SMAWK algorithm](https://en.wikipedia.org/wiki/SMAWK_algorithm) for finding the row minima of a monotone matrix uses stacks in a similar way to Graham scan.[[11\]](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)#cite_note-11)
- [All nearest smaller values](https://en.wikipedia.org/wiki/All_nearest_smaller_values), the problem of finding, for each number in an array, the closest preceding number that is smaller than it. One algorithm for this problem uses a stack to maintain a collection of candidates for the nearest smaller value. For each position in the array, the stack is popped until a smaller value is found on its top, and then the value in the new position is pushed onto the stack.[[12\]](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)#cite_note-12)
- The [nearest-neighbor chain algorithm](https://en.wikipedia.org/wiki/Nearest-neighbor_chain_algorithm), a method for [agglomerative hierarchical clustering](https://en.wikipedia.org/wiki/Agglomerative_hierarchical_clustering) based on maintaining a stack of clusters, each of which is the nearest neighbor of its predecessor on the stack. When this method finds a pair of clusters that are mutual nearest neighbors, they are popped and merged.[[13\]](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)#cite_note-13)



> NOTE: 栈的后进先出的特性是一种倒序的特性，它非常适合于实现一些需要执行逆转操作的算法；

## Security

Some computing environments use stacks in ways that may make them vulnerable to [security breaches](https://en.wikipedia.org/wiki/Security_breaches) and attacks. Programmers working in such environments must take special care to avoid the pitfalls of these implementations.

For example, some programming languages use a common stack to store both data local to a called procedure and the linking information that allows the procedure to return to its caller. This means that the program moves data into and out of the same stack that contains critical return addresses for the procedure calls. If data is moved to the wrong location on the stack, or an oversized data item is moved to a stack location that is not large enough to contain it, return information for procedure calls may be corrupted, causing the program to fail.

Malicious parties may attempt a [stack smashing](https://en.wikipedia.org/wiki/Stack_smashing) attack that takes advantage of this type of implementation by providing oversized data input to a program that does not check the length of input. Such a program may copy the data in its entirety to a location on the stack, and in so doing it may change the return addresses for procedures that have called it. An attacker can experiment to find a specific type of data that can be provided to such a program such that the return address of the current procedure is reset to point to an area within the stack itself (and within the data provided by the attacker), which in turn contains instructions that carry out unauthorized operations.

This type of attack is a variation on the [buffer overflow](https://en.wikipedia.org/wiki/Buffer_overflow) attack and is an extremely frequent source of security breaches in software, mainly because some of the most popular compilers use a shared stack for both data and procedure calls, and do not verify the length of data items. Frequently programmers do not write code to verify the size of data items, either, and when an oversized or undersized data item is copied to the stack, a security breach may occur.