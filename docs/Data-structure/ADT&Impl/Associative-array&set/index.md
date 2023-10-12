# Associative array(dict、map) and set

一、set 和 associative array 本质上是非常类似的: 

1、set只有key没有value

2、map既有key又有value

正如在 wikipedia [Set (abstract data type)](https://en.wikipedia.org/wiki/Set_(abstract_data_type)) 中所总结的:

> As sets can be interpreted as a kind of map (by the indicator function), sets are commonly implemented in the same way as (partial) maps ([associative arrays](https://en.wikipedia.org/wiki/Associative_array)) – in this case in which the value of each key-value pair has the [unit type](https://en.wikipedia.org/wiki/Unit_type) or a sentinel value (like 1) – namely, a [self-balancing binary search tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree) for sorted sets (which has O(log n) for most operations), or a [hash table](https://en.wikipedia.org/wiki/Hash_table) for unsorted sets (which has O(1) average-case, but O(n) worst-case, for most operations). A sorted linear hash table[[8\]](https://en.wikipedia.org/wiki/Set_(abstract_data_type)#cite_note-10) may be used to provide deterministically ordered sets.

## Implementation

两种在实现上是非常类似的，一般采用相同的data structure来进行实现





