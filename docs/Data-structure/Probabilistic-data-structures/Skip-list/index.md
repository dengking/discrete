# Skip list

1、Redis中，使用了skip list来实现 "ordered set"

2、skip list可以用于实现associate array(即dict)

## wikipedia [Skip list](https://en.wikipedia.org/wiki/Skip_list)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **skip list** is a [data structure](https://en.wikipedia.org/wiki/Data_structure) that allows ${{O}}(\log n)$ search complexity as well as $ {{O}}(\log n)$ insertion complexity within an [ordered sequence](https://en.wikipedia.org/wiki/Ordered_sequence) of ${n}$ elements. Thus it can get the best of [array](https://en.wikipedia.org/wiki/Array_data_structure) (for searching) while maintaining a [linked list](https://en.wikipedia.org/wiki/Linked_list)-like structure that allows insertion- which is not possible in an array. Fast search is made possible by maintaining a [linked](https://en.wikipedia.org/wiki/Linked_list) hierarchy of **subsequences**, with each successive subsequence **skipping** over fewer elements than the previous one (see the picture below on the right). Searching starts in the sparsest(稀疏的) subsequence until two consecutive elements have been found, one smaller and one larger than or equal to the element searched for. Via the linked hierarchy, these two elements link to elements of the next sparsest subsequence, where searching is continued until finally we are searching in the full sequence. The elements that are skipped over may be chosen probabilistically [[2\]](https://en.wikipedia.org/wiki/Skip_list#cite_note-pugh-2) or deterministically,[[3\]](https://en.wikipedia.org/wiki/Skip_list#cite_note-3) with the former being more common.

> NOTE:
>
> 1、subsequence的含义是子序列



| Algorithm |      | **Average**                              | **Worst case**                                               |
| :-------: | ---- | ---------------------------------------- | ------------------------------------------------------------ |
|   Space   |      | ${\displaystyle {\mathcal {O}}(n)}$      | ${\displaystyle {\mathcal {O}}(n\log n)}$[[1\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-cs.uwaterloo-1) |
|  Search   |      | ${\displaystyle {\mathcal {O}}(\log n)}$ | ${\displaystyle {\mathcal {O}}(n)}$[[1\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-cs.uwaterloo-1) |
|  Insert   |      | ${\displaystyle {\mathcal {O}}(\log n)}$ | ${\displaystyle {\mathcal {O}}(n)}$                          |
|  Delete   |      | ${\displaystyle {\mathcal {O}}(\log n)}$ |                                                              |

### Description

A **skip list** is built in **layers**. The **bottom layer** is an ordinary ordered [linked list](https://en.wikipedia.org/wiki/Linked_list). Each **higher layer** acts as an "express lane"（快车道） for the lists below, where an element in layer ${i}$ appears in layer ${i+1}$ with some fixed probability ${p}$  (two commonly used values for ${p}$  are ${1/2}$  or ${1/4}$ ). On average, each element appears in ${ 1/(1-p)}$ lists, and the **tallest element** (usually a special head element at the front of the skip list) in all the lists. The skip list contains ${\log _{1/p}n\,}$ (i.e. logarithm base ${ 1/p}$ of ${ n}$) lists.

> NOTE: layers 对应的是下面的Inserting elements to skip list图中的levels



[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/8/86/Skip_list.svg/400px-Skip_list.svg.png)](https://en.wikipedia.org/wiki/File:Skip_list.svg)

> A schematic picture of the skip list data structure. Each box with an arrow represents a pointer and a row is a **linked list** giving a sparse subsequence; the numbered boxes (in yellow) at the bottom represent the ordered data sequence. Searching proceeds downwards from the **sparsest subsequence** at the top until consecutive elements bracketing the search element are found.





[![img](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2c/Skip_list_add_element-en.gif/400px-Skip_list_add_element-en.gif)](https://en.wikipedia.org/wiki/File:Skip_list_add_element-en.gif)

> Inserting elements to skip list



A search for a target element begins at the **head element** in the **top list**, and proceeds horizontally（水平的） until the current element is greater than or equal to the target. If the **current element** is equal to the target, it has been found. If the **current element** is greater than the target, or the search reaches the end of the linked list, the procedure is repeated after returning to the previous element and dropping down vertically to the next lower list. The expected number of steps in each linked list is at most ${\displaystyle 1/p}$, which can be seen by tracing the search path backwards from the target until reaching an element that appears in the next higher list or reaching the beginning of the current list. Therefore, the total *expected* cost of a search is ${\displaystyle {\tfrac {1}{p}}\log _{1/p}n}$ which is ${\displaystyle {\mathcal {O}}(\log n)\,}$, when ${\displaystyle p}$ is a constant. By choosing different values of ${\displaystyle p}$, it is possible to trade **search costs** against **storage costs**.



### Implementation details

The elements used for a skip list can contain more than one pointer since they can participate in more than one list.

Insertions and deletions are implemented much like the corresponding linked-list operations, except that "tall" elements must be inserted into or deleted from more than one linked list.

${\displaystyle {\mathcal {O}}(n)} $operations, which force us to visit every node in ascending order (such as printing the entire list), provide the opportunity to perform a behind-the-scenes derandomization of the level structure of the skip-list in an optimal way, bringing the skip list to ${\displaystyle {\mathcal {O}}(\log n)}$search time. (Choose the level of the i'th finite node to be 1 plus the number of times we can repeatedly divide i by 2 before it becomes odd. Also, i=0 for the negative infinity header as we have the usual special case of choosing the highest possible level for negative and/or positive infinite nodes.) However this also allows someone to know where all of the higher-than-level 1 nodes are and delete them.

Alternatively, we could make the level structure quasi-random in the following way:



### Usages

The "QMap" key/value dictionary (up to Qt 4) template class of [Qt](https://en.wanweibaike.com/wiki-Qt_(framework)) is implemented with skip lists.[[11\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-11)

[Redis](https://en.wanweibaike.com/wiki-Redis), an ANSI-C open-source persistent key/value store for Posix systems, uses skip lists in its implementation of ordered sets.[[12\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-12)

"leveldb" is a fast key-value storage library written at Google that provides an ordered mapping from string keys to string values[[16\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-16)



#### Concurrent data structure

Skip lists are also used in distributed applications (where the nodes represent physical computers, and pointers represent network connections) and for implementing highly scalable concurrent [priority queues](https://en.wanweibaike.com/wiki-Priority_queue) with less lock contention,[[21\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-21) or even [without locking](https://en.wanweibaike.com/wiki-Non-blocking_algorithm),[[22\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-22)[[23\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-23)[[24\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-24) as well as [lock-free](https://en.wanweibaike.com/wiki-Lock-free) concurrent dictionaries.[[25\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-25) There are also several US patents for using skip lists to implement (lockless) priority queues and concurrent dictionaries.[[26\]](https://en.wanweibaike.com/wiki-Skip list#cite_note-26)