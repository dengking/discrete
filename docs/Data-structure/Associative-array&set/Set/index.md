# Set (abstract data type)



## wikipedia [Set (abstract data type)](https://en.wikipedia.org/wiki/Set_(abstract_data_type))

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **set** is an [abstract data type](https://en.wikipedia.org/wiki/Abstract_data_type) that can store unique values, without any particular [order](https://en.wikipedia.org/wiki/Sequence). It is a computer implementation of the [mathematical](https://en.wikipedia.org/wiki/Mathematics) concept of a [finite set](https://en.wikipedia.org/wiki/Finite_set). Unlike most other [collection](https://en.wikipedia.org/wiki/Collection_(abstract_data_type)) types, rather than retrieving a specific element from a set, one typically tests a value for membership in a set.

Some set data structures are designed for **static** or **frozen sets** that do not change after they are constructed. Static sets allow only query operations on their elements — such as checking whether a given value is in the set, or enumerating the values in some arbitrary order. Other variants, called **dynamic** or **mutable sets**, allow also the insertion and deletion of elements from the set.

A **[multiset](https://en.wikipedia.org/wiki/Multiset)** is a special kind of set in which an element can figure several times.



### Implementations

Sets can be implemented using various [data structures](https://en.wikipedia.org/wiki/Data_structure), which provide different time and space trade-offs for various operations. Some implementations are designed to improve the efficiency of very specialized operations, such as `nearest` or `union`. Implementations described as "general use" typically strive to optimize the `element_of`, `add`, and `delete` operations. A simple implementation is to use a [list](https://en.wikipedia.org/wiki/List_(abstract_data_type)), ignoring the order of the elements and taking care to avoid repeated values. This is simple but inefficient, as operations like set membership or element deletion are *O*(*n*), as they require scanning the entire list.[[b\]](https://en.wikipedia.org/wiki/Set_(abstract_data_type)#cite_note-9) Sets are often instead implemented using more efficient data structures, particularly various flavors of [trees](https://en.wikipedia.org/wiki/Tree_(data_structure)), [tries](https://en.wikipedia.org/wiki/Trie), or [hash tables](https://en.wikipedia.org/wiki/Hash_tables).

As sets can be interpreted as a kind of map (by the indicator function), sets are commonly implemented in the same way as (partial) maps ([associative arrays](https://en.wikipedia.org/wiki/Associative_array)) – in this case in which the value of each key-value pair has the [unit type](https://en.wikipedia.org/wiki/Unit_type) or a sentinel value (like 1) – namely, a [self-balancing binary search tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree) for sorted sets (which has O(log n) for most operations), or a [hash table](https://en.wikipedia.org/wiki/Hash_table) for unsorted sets (which has O(1) average-case, but O(n) worst-case, for most operations). A sorted linear hash table[[8\]](https://en.wikipedia.org/wiki/Set_(abstract_data_type)#cite_note-10) may be used to provide deterministically ordered sets.

Further, in languages that support maps but not sets, sets can be implemented in terms of maps. For example, a common [programming idiom](https://en.wikipedia.org/wiki/Programming_idiom) in [Perl](https://en.wikipedia.org/wiki/Perl) that converts an array to a hash whose values are the sentinel value 1, for use as a set, is:

```Perl
my %elements = map { $_ => 1 } @elements;
```

Other popular methods include [arrays](https://en.wikipedia.org/wiki/Array_data_structure). In particular a subset of the integers 1..*n* can be implemented efficiently as an *n*-bit [bit array](https://en.wikipedia.org/wiki/Bit_array), which also support very efficient union and intersection operations. A [Bloom map](https://en.wikipedia.org/wiki/Bloom_map) implements a set probabilistically, using a very compact representation but risking a small chance of false positives on queries.

The Boolean set operations can be implemented in terms of more elementary operations (`pop`, `clear`, and `add`), but specialized algorithms may yield lower asymptotic time bounds. If sets are implemented as sorted lists, for example, the naive algorithm for `union(*S*,*T*)` will take time proportional to the length *m* of *S* times the length *n* of *T*; whereas a variant of the [list merging algorithm](https://en.wikipedia.org/wiki/Merge_algorithm) will do the job in time proportional to *m*+*n*. Moreover, there are specialized set data structures (such as the [union-find data structure](https://en.wikipedia.org/wiki/Union-find_algorithm)) that are optimized for one or more of these operations, at the expense of others.



1、stackoverflow [How is set() implemented in python ?](https://stackoverflow.com/questions/3949310/how-is-set-implemented)

> > Indeed, CPython's sets are implemented as something like dictionaries with dummy values (the keys being the members of the set), with some optimization(s) that exploit this lack of values
>
> So basically a `set` uses a hashtable as its underlying data structure. This explains the O(1) membership checking, since looking up an item in a hashtable is an O(1) operation, on average.
>
> If you are so inclined you can even browse the [CPython source code for set](https://hg.python.org/releasing/3.6/file/tip/Objects/setobject.c) which, according to [Achim Domma](http://markmail.org/message/ktzomp4uwrmnzao6), is mostly a cut-and-paste from the `dict` implementation.

2、stackoverflow [What are the underlying data structures used for Redis?](https://stackoverflow.com/questions/9625246/what-are-the-underlying-data-structures-used-for-redis)

> - **Sets** and **Hashes** are implemented with hash tables.
> - **Sorted sets** are implemented with [skip lists](http://www.catonmat.net/blog/mit-introduction-to-algorithms-part-eight/) (a peculiar type of balanced trees).

3、jameshfisher [How is the Redis sorted set implemented?](https://jameshfisher.com/2018/04/22/redis-sorted-set/)





## Implementation

 [self-balancing binary search tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree) 

 [hash table](https://en.wikipedia.org/wiki/Hash_table) 

 [Bloom map](https://en.wikipedia.org/wiki/Bloom_map) 

 [union-find data structure](https://en.wikipedia.org/wiki/Union-find_algorithm)

 [tries](https://en.wikipedia.org/wiki/Trie)



## Multiset

[`std::multiset`](https://en.cppreference.com/w/cpp/container/multiset)

https://en.wikipedia.org/wiki/Multiset

