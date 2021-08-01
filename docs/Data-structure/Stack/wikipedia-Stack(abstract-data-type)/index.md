# wikipedia [Stack (abstract data type)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a *stack* is an [abstract data type](https://en.wikipedia.org/wiki/Abstract_data_type) that serves as a [collection](https://en.wikipedia.org/wiki/Collection_(computing)) of elements, with two principal operations:

- **push**, which adds an element to the collection, and
- **pop**, which removes the most recently added element that was not yet removed.

The order in which elements come off a stack gives rise to its alternative name, **LIFO** (**last in, first out**). Additionally, a [peek](https://en.wikipedia.org/wiki/Peek_(data_type_operation)) operation may give access to the top without modifying the stack. The name "stack" for this type of structure comes from the analogy to a set of physical items stacked on top of each other, which makes it easy to take an item off the top of the stack, while getting to an item deeper in the stack may require taking off multiple other items first. 

A stack is needed to implement [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search).



## Applications of stacks



### Expression evaluation and syntax parsing

Calculators employing [reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation) use a stack structure to hold values. Expressions can be represented in prefix, postfix or infix notations and conversion from one form to another may be accomplished using a stack. Many compilers use a stack for parsing the syntax of expressions, program blocks etc. before translating into low level code. Most programming languages are [context-free languages](https://en.wikipedia.org/wiki/Context-free_grammar), allowing them to be parsed with stack based machines.



### Backtracking

Main article: [Backtracking](https://en.wikipedia.org/wiki/Backtracking)



### Compile time memory management

Main articles: [Stack-based memory allocation](https://en.wikipedia.org/wiki/Stack-based_memory_allocation) and [Stack machine](https://en.wikipedia.org/wiki/Stack_machine)



### Efficient algorithms

Several [algorithms](https://en.wikipedia.org/wiki/Algorithm) use a stack (separate from the usual function call stack of most programming languages) as the principle [data structure](https://en.wikipedia.org/wiki/Data_structure) with which they organize their information. These include:

1、[Graham scan](https://en.wikipedia.org/wiki/Graham_scan), an algorithm for the [convex hull](https://en.wikipedia.org/wiki/Convex_hull) of a two-dimensional system of points. A convex hull of a subset of the input is maintained in a stack, which is used to find and remove concavities in the boundary when a new point is added to the hull.[[10\]](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)#cite_note-10)

2、Part of the [SMAWK algorithm](https://en.wikipedia.org/wiki/SMAWK_algorithm) for finding the row minima of a monotone matrix uses stacks in a similar way to Graham scan.[[11\]](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)#cite_note-11)

3、[All nearest smaller values](https://en.wikipedia.org/wiki/All_nearest_smaller_values), the problem of finding, for each number in an array, the closest preceding number that is smaller than it. One algorithm for this problem uses a stack to maintain a collection of candidates for the nearest smaller value. For each position in the array, the stack is popped until a smaller value is found on its top, and then the value in the new position is pushed onto the stack.[[12\]](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)#cite_note-12)

4、The [nearest-neighbor chain algorithm](https://en.wikipedia.org/wiki/Nearest-neighbor_chain_algorithm), a method for [agglomerative hierarchical clustering](https://en.wikipedia.org/wiki/Agglomerative_hierarchical_clustering) based on maintaining a stack of clusters, each of which is the nearest neighbor of its predecessor on the stack. When this method finds a pair of clusters that are mutual nearest neighbors, they are popped and merged.[[13\]](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)#cite_note-13)



> NOTE: 栈的后进先出的特性是一种倒序的特性，它非常适合于实现一些需要执行逆转操作的算法；

## Security

Some computing environments use stacks in ways that may make them vulnerable to [security breaches](https://en.wikipedia.org/wiki/Security_breaches) and attacks. Programmers working in such environments must take special care to avoid the pitfalls of these implementations.

