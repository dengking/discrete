# List



## wikipedia [List (abstract data type)](https://en.wikipedia.org/wiki/List_(abstract_data_type))



## wikipedia [Linked list](https://en.wikipedia.org/wiki/Linked_list)



### Related data structures

Both [stacks](https://en.wikipedia.org/wiki/Stack_(data_structure)) and [queues](https://en.wikipedia.org/wiki/Queue_(data_structure)) are often implemented using linked lists, and simply restrict the type of operations which are supported.

The [skip list](https://en.wikipedia.org/wiki/Skip_list) is a linked list augmented with layers of pointers for quickly jumping over large numbers of elements, and then descending to the next layer. This process continues down to the bottom layer, which is the actual list.

A [binary tree](https://en.wikipedia.org/wiki/Binary_tree) can be seen as a type of linked list where the elements are themselves linked lists of the same nature. The result is that each node may include a reference to the first node of one or two other linked lists, which, together with their contents, form the subtrees below that node.

An [unrolled linked list](https://en.wikipedia.org/wiki/Unrolled_linked_list) is a linked list in which each node contains an array of data values. This leads to improved [cache](https://en.wikipedia.org/wiki/CPU_cache) performance, since more list elements are contiguous in memory, and reduced memory overhead, because less metadata needs to be stored for each element of the list.

A [hash table](https://en.wikipedia.org/wiki/Hash_table) may use linked lists to store the chains of items that hash to the same position in the hash table.

A [heap](https://en.wikipedia.org/wiki/Heap_(data_structure)) shares some of the ordering properties of a linked list, but is almost always implemented using an array. Instead of references from node to node, the next and previous data indexes are calculated using the current data's index.

A [self-organizing list](https://en.wikipedia.org/wiki/Self-organizing_list) rearranges its nodes based on some heuristic which reduces search times for data retrieval by keeping commonly accessed nodes at the head of the list.







