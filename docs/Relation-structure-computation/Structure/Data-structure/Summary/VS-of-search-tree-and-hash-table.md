


# binary search tree VS hash table

在[Binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree)中，有如下对比：

> Binary search trees keep their keys in sorted order, so that lookup and other operations can use the principle of [binary search](https://en.wikipedia.org/wiki/Binary_search): when looking for a key in a tree (or a place to insert a new key), they traverse the tree from root to leaf, making comparisons to keys stored in the nodes of the tree and deciding, on the basis of the comparison, to continue searching in the left or right subtrees. On average, this means that each comparison allows the operations to skip about half of the tree, so that each lookup, insertion or deletion takes [time proportional to](https://en.wikipedia.org/wiki/Time_complexity) the [logarithm](https://en.wikipedia.org/wiki/Logarithm) of the number of items stored in the tree. This is much better than the [linear time](https://en.wikipedia.org/wiki/Linear_time) required to find items by key in an (unsorted) array, but slower than the corresponding operations on [hash tables](https://en.wikipedia.org/wiki/Hash_table).



# B tree VS hash table

## [Introduction to the B-Tree](https://cstack.github.io/db_tutorial/parts/part7.html)

> Why is a tree a good data structure for a database?
>
> - Searching for a particular value is fast (logarithmic time)
> - Inserting / deleting a value you’ve already found is fast (constant-ish time to rebalance)
> - Traversing a range of values is fast (unlike a hash map)



# Self-balancing binary search tree VS hash table

## [Self-balancing binary search tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree)

> Self-balancing binary search trees can be used in a natural way to construct and maintain ordered lists, such as [priority queues](https://en.wikipedia.org/wiki/Priority_queue). They can also be used for [associative arrays](https://en.wikipedia.org/wiki/Associative_array); key-value pairs are simply inserted with an ordering based on the key alone. In this capacity, self-balancing BSTs have [a number of advantages and disadvantages](https://en.wikipedia.org/wiki/Associative_array#Efficient_representations) over their main competitor, [hash tables](https://en.wikipedia.org/wiki/Hash_table). One advantage of self-balancing BSTs is that they allow fast (indeed, asymptotically optimal) enumeration of the items *in key order*, which hash tables do not provide. One disadvantage is that their lookup algorithms get more complicated when there may be multiple items with the same key. Self-balancing BSTs have better worst-case lookup performance than hash tables (O(log n) compared to O(n)), but have worse average-case performance (O(log n) compared to O(1)).

