# Iterator

Iterator是一个非常重要的概念。

## wikipedia [Iterator](https://en.wikipedia.org/wiki/Iterator)

In [computer programming](https://en.wikipedia.org/wiki/Computer_programming), an **iterator** is an [object](https://en.wikipedia.org/wiki/Object_(computing)) that enables a programmer to traverse a [container](https://en.wikipedia.org/wiki/Container_(data_structure)), particularly [lists](https://en.wikipedia.org/wiki/List_(abstract_data_type)). Various types of iterators are often provided via a container's [interface](https://en.wikipedia.org/wiki/Interface_(object-oriented_programming)). Though the interface and semantics of a given iterator are fixed, iterators are often implemented in terms of the structures underlying a container implementation and are often tightly coupled to the container to enable the operational semantics of the iterator. An iterator performs traversal and also gives access to data elements in a container, but does not itself perform [iteration](https://en.wikipedia.org/wiki/Iteration) (i.e., not without some significant liberty taken with that concept or with trivial use of the terminology). An iterator is behaviorally similar to a [database cursor](https://en.wikipedia.org/wiki/Cursor_(databases)).  

> NOTE:请思考iterator和iteration之间关系？我们往往是通过`for`，`while`语句来实现iteration。iterator则相当于与一个pointer。

### Description

> NOTE: 原文的这一段非常值得一读

#### Internal Iterators

Internal iterators are [higher order functions](https://en.wikipedia.org/wiki/Higher_order_functions) (often taking [anonymous functions](https://en.wikipedia.org/wiki/Anonymous_functions)) such as *map*, *reduce* etc., implementing the traversal across a container, applying the given function to every element in turn.

> NOTE: 其实这属于functional programming paradigm，结合python的Functional Programming Modules[¶](https://docs.python.org/3/library/functional.html#functional-programming-modules)、Functional Programming HOWTO[¶](https://docs.python.org/3/howto/functional.html#functional-programming-howto)来理解是非常好理解的。所谓的internal iterator是指使用`map`等 higher order function（这些函数接收一个函数作为参数），这些函数在内部执行iteration操作，所以对于使用者而言，它就无需显式地使用`for`、`while`等循环语句了，这就是所谓的“Internal Iterators”。

#### External iterators and the iterator pattern

An external **iterator** may be thought of as a type of [pointer](https://en.wikipedia.org/wiki/Pointer_(computer_programming)) that has two primary operations: **referencing** one particular element in the object collection (called *element access*), and **modifying** itself so it points to the next element (called *element traversal*). There must also be a way to create an iterator so it points to some first element as well as some way to determine when the iterator has exhausted all of the elements in the container. Depending on the language and intended use, iterators may also provide additional operations or exhibit different behaviors.

> NOTE: 将iterator比作pointer，是非常容易理解的。

The primary purpose of an iterator is to allow a user to process every element of a container while isolating the user from the internal structure of the container. This allows the container to store elements in any manner it wishes while allowing the user to treat it as if it were a simple sequence or list. An iterator class is usually designed in tight coordination with the corresponding container class. Usually, the container provides the methods for creating iterators.

> NOTE: separation

A [loop counter](https://en.wikipedia.org/wiki/Loop_counter) is sometimes also referred to as a loop iterator. A [loop counter](https://en.wikipedia.org/wiki/Loop_counter), however, only provides the traversal functionality and not the element access functionality.



#### Implicit iterators

Some object-oriented languages such as [C#](https://en.wikipedia.org/wiki/C_Sharp_(programming_language)), [C++](https://en.wikipedia.org/wiki/C%2B%2B) (later versions), [Delphi](https://en.wikipedia.org/wiki/Object_Pascal) (later versions), [Go](https://en.wikipedia.org/wiki/Go_(programming_language)), [Java](https://en.wikipedia.org/wiki/Java_(programming_language)) (later versions), [Lua](https://en.wikipedia.org/wiki/Lua_(programming_language)), [Perl](https://en.wikipedia.org/wiki/Perl), [Python](https://en.wikipedia.org/wiki/Python_(programming_language)), [Ruby](https://en.wikipedia.org/wiki/Ruby_(programming_language)) provide an [intrinsic](https://en.wikipedia.org/wiki/Intrinsic_function) way of iterating through the elements of a container object without the introduction of an explicit iterator object. An actual iterator object may exist in reality, but if it does it is not exposed within the source code of the language.

Implicit iterators are often manifested by a "[foreach](https://en.wikipedia.org/wiki/Foreach)" statement (or equivalent), such as in the following Python example:

```python
for value in iterable:
    print(value)
```

> NOTE: c++中将此称为[range-for](https://en.cppreference.com/w/cpp/language/range-for)



#### [Contrasting with indexing](https://en.wikipedia.org/wiki/Iterator#Contrasting_with_indexing)

> NOTE: 原文这一段总结的非常好。

## Iterator VS pointer 

我觉得，最最能够说明iterator VS pointer的是[Iterator pattern](https://en.wikipedia.org/wiki/Iterator_pattern)，在维基百科[Iterator pattern#Overview](https://en.wikipedia.org/wiki/Iterator_pattern#Overview)中说明了我们为什么要使用iterator pattern，其实就是iterator pattern相比于pointer的优势所在，iterator更加地抽象，我们依赖于抽象，而不是依赖于具体。

## Application of iterator

### Generic programming

参见`Theory\Programming-paradigm\Generic-programming`，典型例子就是STL，其中使用iterator来作为container的抽象描述。