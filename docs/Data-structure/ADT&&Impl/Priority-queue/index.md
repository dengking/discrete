# Priority queue



## wanweibaike [Priority queue](https://en.wanweibaike.com/wiki-Priority%20Queue)

In [computer science](https://en.wanweibaike.com/wiki-Computer_science), a **priority queue** is an [abstract data type](https://en.wanweibaike.com/wiki-Abstract_data_type) similar to a regular [queue](https://en.wanweibaike.com/wiki-Queue_(abstract_data_type)) or [stack](https://en.wanweibaike.com/wiki-Stack_(abstract_data_type)) data structure in which each element additionally has a "**priority**" associated with it. In a priority queue, an element with high priority is served before an element with low priority. In some implementations, if two elements have the same priority, they are served according to the order in which they were enqueued, while in other implementations, ordering of elements with the same priority is undefined.

> NOTE:
>
> 根据priority来进行排名，原文的下面这段话总结得非常到位: 
>
> > One can imagine a priority queue as a modified [queue](https://en.wanweibaike.com/wiki-Queue_(abstract_data_type)), but when one would get the next element off the queue, the highest-priority element is retrieved first.
>
> 次序是由priority而决定的，而不是由位置决定的
>
> 



### Operations

A priority queue must at least support the following operations:

1、*is_empty*: check whether the queue has no elements.

2、*insert_with_priority*: add an [element](https://en.wanweibaike.com/wiki-Element_(mathematics)) to the [queue](https://en.wanweibaike.com/wiki-Queue_(abstract_data_type)) with an associated priority.

3、*pull_highest_priority_element*: remove the element from the queue that has the *highest priority*, and return it.



One can imagine a priority queue as a modified [queue](https://en.wanweibaike.com/wiki-Queue_(abstract_data_type)), but when one would get the next element off the queue, the highest-priority element is retrieved first.

> NOTE: 
>
> 这个比喻非常好



### Implementation

#### Naive implementations

> NOTE: 
>
> 现实中，并没有人会使用这种方式

#### Usual implementation

