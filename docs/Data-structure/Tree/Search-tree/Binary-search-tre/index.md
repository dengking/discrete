# Binary search tree



## wikipedia [Binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), **binary search trees** (**BST**), sometimes called **ordered** or **sorted binary trees**, are a particular type of [container](https://en.wikipedia.org/wiki/Collection_(abstract_data_type)): a [data structure](https://en.wikipedia.org/wiki/Data_structure) that stores "items" (such as numbers, names etc.) in [memory](https://en.wikipedia.org/wiki/Computer_memory). They allow fast lookup, addition and removal of items, and can be used to implement either [dynamic sets](https://en.wikipedia.org/wiki/Set_(abstract_data_type)) of items, or [lookup tables](https://en.wikipedia.org/wiki/Lookup_table) that allow finding an item by its *key* (e.g., finding the phone number of a person by name).

Binary search trees keep their keys in sorted order, so that lookup and other operations can use the principle of [binary search](https://en.wikipedia.org/wiki/Binary_search): when looking for a key in a tree (or a place to insert a new key), they traverse the tree from root to leaf, making comparisons to keys stored in the nodes of the tree and deciding, on the basis of the comparison, to continue searching in the left or right subtrees. On average, this means that each comparison allows the operations to skip about half of the tree, so that each lookup, insertion or deletion takes [time proportional to](https://en.wikipedia.org/wiki/Time_complexity) the [logarithm](https://en.wikipedia.org/wiki/Logarithm) of the number of items stored in the tree. This is much better than the [linear time](https://en.wikipedia.org/wiki/Linear_time) required to find items by key in an (unsorted) array, but slower than the corresponding operations on [hash tables](https://en.wikipedia.org/wiki/Hash_table).

Several variants of the **binary search tree** have been studied in computer science; this article deals primarily with the basic type, making references to more advanced types when appropriate.

