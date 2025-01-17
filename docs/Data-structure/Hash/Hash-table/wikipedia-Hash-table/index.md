# wikipedia [Hash table](https://en.wikipedia.org/wiki/Hash_table)

> NOTE: 
>
> 一、Hash table在计算机科学中有着广泛的应用，维基百科的这篇文章总结地非常好。
>
> 二、对于hash table的实现，如下是非常重要的问题:
>
> 1、hash collision--》"Collision resolution"章节
>
> 2、load factor --》"Dynamic resize"章节

In [computing](https://en.wikipedia.org/wiki/Computing), a **hash table** (**hash map**) is a [data structure](https://en.wikipedia.org/wiki/Data_structure) that implements an [associative array](https://en.wikipedia.org/wiki/Associative_array) [abstract data type](https://en.wikipedia.org/wiki/Abstract_data_type), a structure that can map [keys](https://en.wikipedia.org/wiki/Unique_key) to [values](https://en.wikipedia.org/wiki/Value_(computer_science)). A **hash table** uses a [hash function](https://en.wikipedia.org/wiki/Hash_function) to compute an *index* into an array of *buckets* or *slots*, from which the desired value can be found.

> NOTE: 上述术语非常重要，因为它们经常被提及。

Ideally, the hash function will assign each key to a unique bucket, but most hash table designs employ an imperfect hash function, which might cause hash *collisions* where the hash function generates the same index for more than one key. Such **collisions** must be accommodated in some way.

> NOTE:  关于perfect hash function，参见维基百科[Perfect hash function](https://en.wikipedia.org/wiki/Perfect_hash_function)。

In a well-dimensioned hash table, the average cost (number of [instructions](https://en.wikipedia.org/wiki/Instruction_(computer_science))) for each lookup is independent of the number of elements stored in the table. Many hash table designs also allow arbitrary insertions and deletions of key-value pairs, at ([amortized](https://en.wikipedia.org/wiki/Amortized_analysis)) constant average cost per operation. 

> NOTE: 如何理解well-dimensioned ？我觉得它的意思是 “大小合适的”

In many situations, **hash tables** turn out to be on average more efficient than [search trees](https://en.wikipedia.org/wiki/Search_tree) or any other [table](https://en.wikipedia.org/wiki/Table_(computing)) lookup structure. For this reason, they are widely used in many kinds of computer [software](https://en.wikipedia.org/wiki/Software), particularly for [associative arrays](https://en.wikipedia.org/wiki/Associative_array), [database indexing](https://en.wikipedia.org/wiki/Database_index), [caches](https://en.wikipedia.org/wiki/Cache_(computing)), and [sets](https://en.wikipedia.org/wiki/Set_(abstract_data_type)).



## Hashing

*Main article:* [Hash function](https://en.wikipedia.org/wiki/Hash_function)

The idea of hashing is to distribute the entries (key/value pairs) across an array of *buckets*. Given a key, the algorithm computes an *index* that suggests where the entry can be found:

```c++
index = f(key, array_size)
```

Often this is done in two steps:

```c++
hash = hashfunc(key)
index = hash % array_size
```

In this method, the *hash* is independent of the array size, and it is then *reduced* to an index (a number between `0` and `array_size − 1`) using the [modulo operator](https://en.wanweibaike.com/wiki-Modulo_operation) (`%`).



In the case that the array size is a [power of two](https://en.wanweibaike.com/wiki-Power_of_two), the remainder operation is reduced to [masking](https://en.wanweibaike.com/wiki-Mask_(computing)), which improves speed, but can increase problems with a poor hash function.[[5\]](https://en.wanweibaike.com/wiki-hash table#cite_note-5)

> NOTE: 这指的是使用 bitmask 来替代 modulo operation，对于hash这种对速度要求较高的，使用这种optimization是有必要的，在 wikipedia [Mask (computing)](https://en.wikipedia.org/wiki/Mask_(computing)) 中，也介绍了这种technique。



### Choosing a hash function

> NOTE: 
>
> 1、本章探讨的是: 对于一个hash map，如何选择hash function；因此这一段会涉及"hash function"的特性，显然与 `Hash-function` 章节的内容有一些重复。

#### Uniform distribution

A basic requirement is that the function should provide a [uniform distribution](https://en.wikipedia.org/wiki/Uniform_distribution_(discrete)) （离散均匀分布）of hash values. 

The distribution needs to be **uniform** only for **table sizes** that occur in the application. In particular, if one uses **dynamic resizing** with exact doubling and halving of the table size, then the **hash function** needs to be uniform only when the size is a [power of two](https://en.wikipedia.org/wiki/Power_of_two). Here the index can be computed as some range of bits of the hash function. On the other hand, some hashing algorithms prefer to have the size be a [prime number](https://en.wikipedia.org/wiki/Prime_number).[[8\]](https://en.wikipedia.org/wiki/Hash_table#cite_note-:0-8) The modulus operation may provide some additional mixing; this is especially useful with a poor hash function.

> NOTE: 在设计hash  function的时候，其实还需要考虑的是hash值是否需要在table size范围内均匀分布；以及当table size变更的时候所需要考虑的一系列问题；

#### Avoid *clustering*

For [open addressing](https://en.wikipedia.org/wiki/Open_addressing) schemes, the **hash function** should also avoid *clustering*, the mapping of two or more keys to consecutive（连续的） slots. Such clustering may cause the lookup cost to skyrocket（飞涨）, even if the **load factor** is low and collisions are infrequent. The popular multiplicative(乘法) hash[[3\]](https://en.wikipedia.org/wiki/Hash_table#cite_note-knuth-3) is claimed to have particularly poor clustering behavior.[[8\]](https://en.wikipedia.org/wiki/Hash_table#cite_note-:0-8)

> NOTE: 
>
> 1、为什么 "Such clustering may cause the lookup cost to skyrocket（飞涨）"？
>
> 需要不断地去probe？

#### [Cryptographic hash functions](https://en.wanweibaike.com/wiki-Cryptographic_hash_function)

[Cryptographic hash functions](https://en.wikipedia.org/wiki/Cryptographic_hash_function) are believed to provide good hash functions for any **table size**, either by [modulo](https://en.wikipedia.org/wiki/Modulo_operation) reduction or by [bit masking](https://en.wikipedia.org/wiki/Mask_(computing))[*citation needed*]. They may also be appropriate if there is a risk of malicious（恶毒的） users trying to [sabotage](https://en.wikipedia.org/wiki/Denial_of_service_attack) （蓄意破坏）a network service by submitting requests designed to generate a large number of collisions in the server's hash tables. However, the risk of sabotage can also be avoided by cheaper methods (such as applying a secret [salt](https://en.wikipedia.org/wiki/Salt_(cryptography)) to the data, or using a [universal hash function](https://en.wikipedia.org/wiki/Universal_hash_function)). 

A drawback of cryptographic hashing functions is that they are often slower to compute, which means that in cases where the uniformity for *any* size is not necessary, a non-cryptographic hashing function might be preferable.[*citation needed*]

> NOTE: 
>
> 一、tradeoff: 
>
> 1、显然，[Cryptographic hash functions](https://en.wikipedia.org/wiki/Cryptographic_hash_function) are believed to provide good hash functions for any **table size**, either by [modulo](https://en.wikipedia.org/wiki/Modulo_operation) reduction or by [bit masking](https://en.wikipedia.org/wiki/Mask_(computing))[*citation needed*]的这个特性是非常好的，它允许使用户无需考虑改变table size所带来的各种问题；
>
> 2、但是[Cryptographic hash functions](https://en.wikipedia.org/wiki/Cryptographic_hash_function) 的运算是相对较慢的: "A drawback of cryptographic hashing functions is that they are often slower to compute"

### Perfect hash function

> NOTE: 
>
> 1、一个经典的例子是: "perfect hash-character-as-key-index-array"，关于此，参见 `LeetCode-316-去除重复字母`

If all keys are known ahead of time, a [perfect hash function](https://en.wanweibaike.com/wiki-Perfect_hash_function) can be used to create a perfect hash table that has no collisions. If [minimal perfect hashing](https://en.wanweibaike.com/wiki-Perfect_hash_function#Minimal_perfect_hash_function) is used, every location in the hash table can be used as well.

Perfect hashing allows for [constant time](https://en.wanweibaike.com/wiki-Constant_time) lookups in all cases. This is in contrast to most chaining and open addressing methods, where the time for lookup is low on average, but may be very large, O(*n*), for instance when all the keys hash to a few values.

## Key statistics

A critical statistic for a hash table is the *load factor*, defined as

$ {\text{load factor}}={\frac {n}{k}}, $

where

- *n* is the number of entries occupied in the hash table.
- *k* is the number of buckets（其实就是table size）.

> NOTE: 
>
> 一、"load factor"的意思是"装载因子"，顾名思义: 
>
> "load"表示的是hash table中实际有多少个元素，对应的是`n`
>
> `k`表示的是"number of buckets"
>
> 需要注意的是: load factor的计算 和 collision resolution的方式无关。
>
> 参见: 
>
> 1、csdn [hash表装载因子（load factor)的计算](https://blog.csdn.net/CHINA_CNN/article/details/103881989)



## Collision resolution

> NOTE: 
>
> 1、参见 rcoh [An Analysis of Hash Map Implementations in Popular Languages](https://rcoh.me/posts/hash-map-analysis/) ，其中对一些programming language提供的hash table的implementation所采用的collision resolution进行了说明
>
> 2、这两种strategy的对比，其实更多的是array 和 linked list的对比

Hash [collisions](https://en.wikipedia.org/wiki/Collision_(computer_science)) are practically unavoidable when hashing a random subset of a large set of possible keys. For example, if 2,450 keys are hashed into a million buckets, even with a perfectly uniform random distribution, according to the [birthday problem](https://en.wikipedia.org/wiki/Birthday_problem) there is approximately a 95% chance of at least two of the keys being hashed to the same slot.

Therefore, almost all hash table implementations have some collision resolution strategy to handle such events. Some common strategies are described below. All these methods require that the keys (or pointers to them) be stored in the table, together with the associated values.



### Separate chaining

In the method known as *separate chaining*, each bucket is independent, and has some sort of [list](https://en.wikipedia.org/wiki/List_(abstract_data_type)) of entries with the same index. The time for hash table operations is the time to find the bucket (which is constant) plus the time for the list operation.

> NOTE: 
>
> 1、初读上面这段话是可能会产生误解的，*chaining* 采用的data structure不一定是linked list，下面会对可能的方案进行总结

In a good hash table, each bucket has zero or one entries, and sometimes two or three, but rarely more than that. Therefore, structures that are efficient in time and space for these cases are preferred. Structures that are efficient for a fairly large number of entries per bucket are not needed or desirable. If these cases happen often, the hashing function needs to be fixed.[*citation needed*]



#### Separate chaining with linked lists

> NOTE: 
>
> 1、这种情况的hash table，更像是一个array of linked list，它是一个mixed data structure

Chained hash tables with [linked lists](https://en.wikipedia.org/wiki/Linked_list) are popular because they require only basic data structures with simple algorithms, and can use simple hash functions that are unsuitable for other methods.[*citation needed*]

> NOTE: 
>
> 1、优势就是简单

The cost of a table operation is that of scanning the entries of the selected bucket for the desired key. If the distribution of keys is [sufficiently uniform](https://en.wikipedia.org/wiki/SUHA), the *average* cost of a lookup depends only on the average number of keys per bucket—that is, it is roughly proportional to the load factor.

For this reason, chained hash tables remain effective even when the number of table entries *n* is much higher than the number of slots. For example, a chained hash table with 1000 slots and 10,000 stored keys (load factor 10) is five to ten times slower than a 10,000-slot table (load factor 1); but still 1000 times faster than a plain sequential list.

For separate-chaining, the worst-case scenario is when all entries are inserted into the same bucket, in which case the hash table is ineffective and the cost is that of searching the bucket data structure. If the latter is a linear list, the lookup procedure may have to scan all its entries, so the worst-case cost is proportional to the number *n* of entries in the table.

> NOTE: 
>
> 1、最坏的情况

The bucket chains are often searched sequentially using the order the entries were added to the bucket. If the load factor is large and some keys are more likely to come up than others, then rearranging the chain with a [move-to-front heuristic](https://en.wikipedia.org/wiki/Self-organizing_list#Move_to_Front_Method_(MTF)) may be effective. More sophisticated data structures, such as balanced search trees, are worth considering only if the load factor is large (about 10 or more), or if the hash distribution is likely to be very non-uniform, or if one must guarantee good performance even in a worst-case scenario. However, using a larger table and/or a better hash function may be even more effective in those cases.[*citation needed*]

**劣势**

> NOTE: 
>
> 1、它的劣势源自于linked list

Chained hash tables also inherit the disadvantages of linked lists. When storing small keys and values, the space overhead of the `next` pointer in each entry record can be significant. An additional disadvantage is that traversing a linked list has poor [cache performance](https://en.wikipedia.org/wiki/Locality_of_reference), making the processor cache ineffective.



#### Separate chaining with list head cells

Some chaining implementations store the first record of each chain in the slot array itself.[[4\]](https://en.wanweibaike.com/wiki-hash table#cite_note-cormen-4) The number of pointer traversals is decreased by one for most cases. The purpose is to increase cache efficiency of hash table access.

The disadvantage is that an empty bucket takes the same space as a bucket with one entry. To save space, such hash tables often have about as many slots as stored entries, meaning that many slots have two or more entries.[*[citation needed](https://en.wanweibaike.com/wiki/Wikipedia-Citation_needed)*]

#### Separate chaining with other structures

> 1、影响因素非常多，很难有完美的方案

**Using a [self-balancing binary search tree](https://en.wanweibaike.com/wiki-Self-balancing_binary_search_tree) :**

Instead of a list, one can use any other data structure that supports the required operations. For example, by using a [self-balancing binary search tree](https://en.wanweibaike.com/wiki-Self-balancing_binary_search_tree), the theoretical worst-case time of common hash table operations (insertion, deletion, lookup) can be brought down to [O(log *n*)](https://en.wanweibaike.com/wiki-Big_O_notation) rather than O(*n*). However, this introduces extra complexity into the implementation, and may cause even worse performance for smaller hash tables, where the time spent inserting into and balancing the tree is greater than the time needed to perform a [linear search](https://en.wanweibaike.com/wiki-Linear_search) on all of the elements of a list.[[3\]](https://en.wanweibaike.com/wiki-hash table#cite_note-knuth-3)[[12\]](https://en.wanweibaike.com/wiki-hash table#cite_note-12) A real world example of a hash table that uses a self-balancing binary search tree for buckets is the `HashMap` class in [Java](https://en.wanweibaike.com/wiki-Java_(programming_language)) [version 8](https://en.wanweibaike.com/wiki-Java_8).[[13\]](https://en.wanweibaike.com/wiki-hash table#cite_note-13)

> NOTE: 
>
> 1、这种情况的hash table，更像是一个array of [self-balancing binary search tree](https://en.wanweibaike.com/wiki-Self-balancing_binary_search_tree)，它是一个mix data structure
>
> 2、在 CSDN [索引数据结构之哈希、红黑树(Red Black Tree)、B树(B-Tree)、B+树详解](https://blog.csdn.net/qq_36565596/article/details/107895579) 中，对Java HashMap 进行了更加详细的介绍:
>
> > HashMap的底层数据结构：分JDK1.7和JDK1.8两个版本。
> > （1）JDK1.7：底层数据结构是数组+单链表；
> > （2）JDK1.8：对 HashMap 做了进一步优化，底层数据结构是数组+单链表（红黑树），当链表过长（默认当长度超过8）时，链表就转换成了红黑树，利用红黑树快速增删改查的特点，进一步提高HashMap的性能。当红黑树的结点个数少于6时，又会将红黑树转化成链表。因此在数据量较小的情况下，红黑树因为要维护平衡，性能上的优势并不明显。
>
> 

**Using a [dynamic array](https://en.wanweibaike.com/wiki-Dynamic_array)** 

The variant called array hash table uses a [dynamic array](https://en.wanweibaike.com/wiki-Dynamic_array) to store all the entries that hash to the same slot.[[14\]](https://en.wanweibaike.com/wiki-hash table#cite_note-14)[[15\]](https://en.wanweibaike.com/wiki-hash table#cite_note-15)[[16\]](https://en.wanweibaike.com/wiki-hash table#cite_note-16) Each newly inserted entry gets appended to the end of the dynamic array that is assigned to the slot. The dynamic array is resized in an *exact-fit* manner, meaning it is grown only by as many bytes as needed. Alternative techniques such as growing the array by block sizes or *pages* were found to improve insertion performance, but at a cost in space. This variation makes more efficient use of [CPU caching](https://en.wanweibaike.com/wiki-CPU_cache) and the [translation lookaside buffer](https://en.wanweibaike.com/wiki-Translation_lookaside_buffer) (TLB), because slot entries are stored in sequential memory positions. It also dispenses with the `next` pointers that are required by linked lists, which saves space. Despite frequent array resizing, space overheads incurred by the operating system such as memory fragmentation were found to be small.[*[citation needed](https://en.wanweibaike.com/wiki/Wikipedia-Citation_needed)*]

**[Dynamic perfect hashing](https://en.wanweibaike.com/wiki-Dynamic_perfect_hashing)**

> NOTE: 
>
> 1、比较复杂

An elaboration on this approach is the so-called [dynamic perfect hashing](https://en.wanweibaike.com/wiki-Dynamic_perfect_hashing),[[17\]](https://en.wanweibaike.com/wiki-hash table#cite_note-17) where a bucket that contains *k* entries is organized as a perfect hash table with *k*2 slots. While it uses more memory (*n*2 slots for *n* entries, in the worst case and *n* × *k* slots in the average case), this variant has guaranteed constant worst-case lookup time, and low amortized time for insertion. It is also possible to use a [fusion tree](https://en.wanweibaike.com/wiki-Fusion_tree) for each bucket, achieving constant time for all operations with high probability.[[18\]](https://en.wanweibaike.com/wiki-hash table#cite_note-18)



### Open addressing

*Main article:* [Open addressing](https://en.wikipedia.org/wiki/Open_addressing)

> NOTE: 
>
> 一、open addressing在具体实现的时候，需要使用专门的标识来记录当前的slot是否被占用了。

In another strategy, called open addressing, all entry records are stored in the bucket array itself. 

When a new entry has to be inserted, the buckets are examined, starting with the hashed-to slot and proceeding in some *probe sequence*, until an unoccupied slot is found. 

When searching for an entry, the buckets are scanned in the same sequence, until either the target record is found, or an unused array slot is found, which indicates that there is no such key in the table.[[19\]](https://en.wanweibaike.com/wiki-hash table#cite_note-tenenbaum90-19) 

The name "open addressing" refers to the fact that the location ("address") of the item is not determined by its hash value. (This method is also called **closed hashing**; it should not be confused with "open hashing" or "closed addressing" that usually mean separate chaining.)

Well-known probe sequences include:

1、[Linear probing](https://en.wanweibaike.com/wiki-Linear_probing), in which the interval between probes is fixed (usually 1). Because of good [CPU cache](https://en.wanweibaike.com/wiki-CPU_cache) utilization and high performance this algorithm is most widely used on modern computer architectures in hash table implementations.[[20\]](https://en.wanweibaike.com/wiki-hash table#cite_note-Cuckoo-20)

2、[Quadratic probing](https://en.wanweibaike.com/wiki-Quadratic_probing), in which the interval between probes is increased by adding the successive outputs of a quadratic polynomial to the starting value given by the original hash computation

3、[Double hashing](https://en.wanweibaike.com/wiki-Double_hashing), in which the interval between probes is computed by a second hash function



> NOTE: 
>
> 下面对open addressing 和 separate chaining的对比，本质上是对它们的存储方式: linked 和 array 的对比



#### Drawback 

A drawback of all these open addressing schemes is that the number of stored entries cannot exceed the number of slots in the bucket array. In fact, even with good hash functions, their performance dramatically degrades when the load factor grows beyond 0.7 or so. For many applications, these restrictions mandate the use of dynamic resizing, with its attendant costs.[*[citation needed](https://en.wanweibaike.com/wiki/Wikipedia-Citation_needed)*]

#### Drawback: clustering 

Open addressing schemes also put more stringent requirements on the hash function: besides distributing the keys more uniformly over the buckets, the function must also minimize the clustering of hash values that are consecutive in the probe order. Using separate chaining, the only concern is that too many objects map to the *same* hash value; whether they are adjacent or nearby is completely irrelevant.[*[citation needed](https://en.wanweibaike.com/wiki/Wikipedia-Citation_needed)*]



## Dynamic resizing

When an insert is made such that the number of entries in a hash table exceeds the product of the load factor and the current capacity then the hash table will need to be *rehashed*.[[9\]](https://en.wikipedia.org/wiki/Hash_table#cite_note-JavadocHashmap10-9) **Rehashing** includes **increasing** the size of the underlying data structure[[9\]](https://en.wikipedia.org/wiki/Hash_table#cite_note-JavadocHashmap10-9) and mapping existing items to new bucket locations. In some implementations, if the initial capacity is greater than the maximum number of entries divided by the load factor, no rehash operations will ever occur.[[9\]](https://en.wikipedia.org/wiki/Hash_table#cite_note-JavadocHashmap10-9)

> NOTE: 
>
> 一、"mapping existing items to new bucket locations" 指的是 对key重新使用hash function获得它们对应的新的hash code，即rehash、hash again。
>
> 二、其实dynamic resizing的实现，相对而言是比较容易的，在 geeksforgeeks [Load Factor and Rehashing](https://www.geeksforgeeks.org/load-factor-and-rehashing/) 中给出了比较好的总结:
>
> 1、enlarge
>
> 2、将原table中的元素逐一添加到新的table中，直接调用`insert`的接口即可: `insert`会计算hash code，然后将元素添加到hash table中。

To limit the proportion of memory wasted due to empty buckets, some implementations also **shrink** the size of the table—followed by a rehash—when items are deleted. From the point of space–time tradeoffs, this operation is similar to the deallocation in dynamic arrays.



### Resizing by copying all entries

> NOTE: 
>
> 一、原文的这段话仅仅讨论的是resize，并没有讨论如何将原table的内容转移到新的table中？是直接copy？还是，每个都hash一遍，然后找到它们在新table中的位置？应该是要重新hash一遍的：
>
> 1、对于缩小，显然无法直接将原来的copy到新的table
>
> 2、重新hash一遍，能够充分利用新的table的空间
>
> 关于这个topic，参见: 
>
> 1、geeksforgeeks [Load Factor and Rehashing](https://www.geeksforgeeks.org/load-factor-and-rehashing/)
>
> 其中详细地描述了rehash的过程

A common approach is to automatically trigger a complete resizing when the **load factor** exceeds some threshold *r*max. Then a new larger table is [allocated](https://en.wikipedia.org/wiki/Dynamic_memory_allocation), each entry is removed from the old table, and inserted into the new table. When all entries have been removed from the old table then the old table is returned to the free storage pool. Likewise, when the load factor falls below a second threshold *r* min, all entries are moved to a new smaller table.

For hash tables that shrink and grow frequently, the resizing downward(向下，缩小) can be skipped entirely. In this case, the table size is proportional to the maximum number of entries that ever were in the hash table at one time, rather than the current number. The disadvantage is that memory usage will be higher, and thus cache behavior may be worse. For best control, a "shrink-to-fit" operation can be provided that does this only on request.

If the table size increases or decreases by a fixed percentage at each expansion, the total cost of these resizings, [amortized](https://en.wikipedia.org/wiki/Amortized_analysis) over all insert and delete operations, is still a constant, independent of the number of entries *n* and of the number *m* of operations performed.

For example, consider a table that was created with the minimum possible size and is doubled each time the load ratio exceeds some threshold. If *m* elements are inserted into that table, the total number of extra re-insertions that occur in all dynamic resizings of the table is at most *m* − 1. In other words, dynamic resizing roughly doubles the cost of each insert or delete operation.



### Alternatives to all-at-once rehashing

Some hash table implementations, notably in [real-time systems](https://en.wikipedia.org/wiki/Real-time_system), cannot pay the price of enlarging the hash table all at once, because it may interrupt time-critical operations. If one cannot avoid dynamic resizing, a solution is to perform the resizing **gradually**（渐进式）.

> NOTE: 
>
> 1、"tag-incremental-amortize-not-all-at-once-渐进式均摊而不是一蹴而就"

Disk-based hash tables almost always use some alternative to all-at-once rehashing, since the cost of rebuilding the entire table on disk would be too high.



#### Incremental resizing

> NOTE: 
>
> 1、Redis的hash table就是使用的incremental resizing，参见工程`decompose-redis` 的  `Data-structure\Dict\Incremental-rehash`

One alternative to enlarging the table all at once is to perform the rehashing gradually:

1、During the resize, allocate the new hash table, but keep the old table unchanged.

2、In each lookup or delete operation, check both tables.

3、Perform insertion operations only in the new table.

4、At each insertion also move *r* elements from the old table to the new table.

5、When all elements are removed from the old table, deallocate it.

To ensure that the old table is completely copied over before the new table itself needs to be enlarged, it is necessary to increase the size of the table by a factor of at least (*r* + 1)/*r* during resizing.



#### Monotonic keys

If it is known that keys will be stored in [monotonically](https://en.wanweibaike.com/wiki-Monotonic_function) increasing (or decreasing) order, then a variation of [consistent hashing](https://en.wanweibaike.com/wiki-Consistent_hashing) can be achieved.

> NOTE: 
>
> 1、关于 "consistent hashing"，参见工程`Parallel-computing` 的 `Consistent-hashing` 章节。

#### Linear hashing

[Linear hashing](https://en.wikipedia.org/wiki/Linear_hashing)[[25\]](https://en.wikipedia.org/wiki/Hash_table#cite_note-25) is a hash table algorithm that permits incremental hash table expansion. It is implemented using a single hash table, but with two possible lookup functions.



#### Hashing for distributed hash tables

Another way to decrease the cost of table resizing is to choose a hash function in such a way that the hashes of most values do not change when the table is resized. Such hash functions are prevalent（流行的） in disk-based and [distributed hash tables](https://en.wikipedia.org/wiki/Distributed_hash_table), where **rehashing** is prohibitively costly. The problem of designing a hash such that most values do not change when the table is resized is known as the [distributed hash table](https://en.wikipedia.org/wiki/Distributed_hash_table) problem. The four most popular approaches are [rendezvous hashing](https://en.wikipedia.org/wiki/Rendezvous_hashing), [consistent hashing](https://en.wikipedia.org/wiki/Consistent_hashing), the [content addressable network](https://en.wikipedia.org/wiki/Content_addressable_network) algorithm, and [Kademlia](https://en.wikipedia.org/wiki/Kademlia) distance.

> NOTE: 
>
> 1、参见工程 `Parallel-computing` 的 `Distributed-hash-table` 章节。

## Performance analysis

In the simplest model, the hash function is completely unspecified and the table does not resize. With an ideal hash function, a table of size $ k $ with **open addressing** has no collisions and holds up to $ k $ elements with a single comparison for successful lookup, while a table of size $ k $ with chaining and $ n $ keys has the minimum $ max(0,n-k) $ collisions and $ \Theta (1+{\frac {n}{k}}) $ comparisons for lookup. With the worst possible hash function, every insertion causes a collision, and hash tables degenerate to linear search, with $ \Theta (n) $ amortized comparisons per insertion and up to $ n $ comparisons for a successful lookup.

Adding **rehashing** to this model is straightforward. As in a [dynamic array](https://en.wikipedia.org/wiki/Dynamic_array), geometric resizing by a factor of $ b $ implies that only $ {\frac {n}{b^{i}}} $keys are inserted $ i $ or more times, so that the total number of insertions is bounded above by $ {\frac {bn}{b-1}} $, which is $ \Theta (n) $. By using rehashing to maintain $ n<k $, tables using both chaining and open addressing can have unlimited elements and perform successful lookup in a single comparison for the best choice of hash function.

In more realistic models, the hash function is a [random variable](https://en.wikipedia.org/wiki/Random_variable) over a probability distribution of hash functions, and performance is computed on average over the choice of hash function. When this distribution is [uniform](https://en.wikipedia.org/wiki/Uniform_distribution_(discrete)), the assumption is called "simple uniform hashing" and it can be shown that hashing with chaining requires $ \Theta (1+{\frac {n}{k}}) $ comparisons on average for an unsuccessful lookup, and hashing with open addressing requires $ \Theta \left({\frac {1}{1-n/k}}\right) $.[[26\]](https://en.wikipedia.org/wiki/Hash_table#cite_note-26) Both these bounds are constant, if we maintain '$ {\frac {n}{k}}<c $ using table resizing, where $ c $ is a fixed constant less than 1.



## Features

### Advantages

1、The main advantage of hash tables over other table data structures is speed. This advantage is more apparent when the number of entries is large. Hash tables are particularly efficient when the maximum number of entries can be predicted in advance, so that the bucket array can be allocated once with the optimum size and never resized.

> NOTE: 
>
> 1、提前知道数据的数量是对应hash table而言是非常重要的。

2、If the set of key-value pairs is fixed and known ahead of time (so insertions and deletions are not allowed), one may reduce the average lookup cost by a careful choice of the hash function, bucket table size, and internal data structures. In particular, one may be able to devise a hash function that is collision-free, or even perfect. In this case the keys need not be stored in the table.



### Drawbacks

1、Although operations on a **hash table** take constant time on average, the cost of a good hash function can be significantly higher than the inner loop of the lookup algorithm for a sequential list or search tree. Thus hash tables are not effective when the number of entries is very small. (However, in some cases the high cost of computing the hash function can be mitigated(缓解) by saving the hash value together with the key.)

> NOTE: 
>
> 1、需要考虑hash function的成本

2、For certain **string processing applications**, such as [spell-checking](https://en.wikipedia.org/wiki/Spell_checker), hash tables may be less efficient than [tries](https://en.wikipedia.org/wiki/Trie), [finite automata](https://en.wikipedia.org/wiki/Finite_automata), or [Judy arrays](https://en.wikipedia.org/wiki/Judy_array). Also, if there are not too many possible keys to store—that is, if each key can be represented by a small enough number of bits—then, instead of a hash table, one may use the key directly as the index into an array of values. Note that there are no collisions in this case.

> NOTE: 
>
> 1、使用  [tries](https://en.wikipedia.org/wiki/Trie) 也可以实现 dict-map-associative-array

3、The entries stored in a hash table can be enumerated efficiently (at constant cost per entry), but only in some pseudo-random order. Therefore, there is no efficient way to locate an entry whose key is *nearest* to a given key. Listing all *n* entries in some specific order generally requires a separate sorting step, whose cost is proportional to log(*n*) per entry. In comparison, **ordered search trees** have lookup and insertion cost proportional to log(*n*), but allow finding the nearest key at about the same cost, and *ordered* enumeration of all entries at constant cost per entry.

> NOTE: 
>
> 1、其实上面这段话是在说hash map是unsorted的

4、If the keys are not stored (because the hash function is collision-free), there may be no easy way to enumerate the keys that are present in the table at any given moment.

5、Although the *average* cost per operation is constant and fairly small, the cost of a single operation may be quite high. In particular, if the hash table uses [dynamic resizing](https://en.wikipedia.org/wiki/Hash_table#Dynamic_resizing), an insertion or deletion operation may occasionally take time proportional to the number of entries. This may be a serious drawback in real-time or interactive applications.

6、Hash tables in general exhibit poor [locality of reference](https://en.wikipedia.org/wiki/Locality_of_reference)—that is, the data to be accessed is distributed seemingly at random in memory. Because hash tables cause access patterns that jump around, this can trigger [microprocessor cache](https://en.wikipedia.org/wiki/CPU_cache) misses that cause long delays. Compact data structures such as arrays searched with [linear search](https://en.wikipedia.org/wiki/Linear_search) may be faster, if the table is relatively small and keys are compact. The optimal performance point varies from system to system.

> NOTE: 
>
> 1、cache performance是非常重要的优化内容

7、Hash tables become quite inefficient when there are many collisions. While extremely uneven hash distributions are extremely unlikely to arise by chance, a [malicious adversary](https://en.wikipedia.org/wiki/Black_hat_hacking) with knowledge of the hash function may be able to supply information to a hash that creates worst-case behavior by causing excessive collisions, resulting in very poor performance, e.g., a [denial of service attack](https://en.wikipedia.org/wiki/Denial_of_service_attack).[[27\]](https://en.wikipedia.org/wiki/Hash_table#cite_note-27)[[28\]](https://en.wikipedia.org/wiki/Hash_table#cite_note-28)[[29\]](https://en.wikipedia.org/wiki/Hash_table#cite_note-29) In critical applications, a data structure with better worst-case guarantees can be used; however, [universal hashing](https://en.wikipedia.org/wiki/Universal_hashing)—a [randomized algorithm](https://en.wikipedia.org/wiki/Randomized_algorithm) that prevents the attacker from predicting which inputs cause worst-case behavior—may be preferable.[[30\]](https://en.wikipedia.org/wiki/Hash_table#cite_note-30) The hash function used by the hash table in the Linux [routing table](https://en.wikipedia.org/wiki/Routing_table) cache was changed with Linux version 2.4.2 as a countermeasure against such attacks.[[31\]](https://en.wikipedia.org/wiki/Hash_table#cite_note-31)



## Uses

### Associative arrays

*Main article:* [Associative array](https://en.wikipedia.org/wiki/Associative_array)

### Database indexing

Hash tables may also be used as [disk](https://en.wikipedia.org/wiki/Disk_drive)-based data structures and [database indices](https://en.wikipedia.org/wiki/Index_(database)) (such as in [dbm](https://en.wikipedia.org/wiki/DBM_(computing))) although [B-trees](https://en.wikipedia.org/wiki/B-tree) are more popular in these applications. In multi-node database systems, hash tables are commonly used to distribute rows amongst nodes, reducing network traffic for hash joins.



### Caches

Main article: [Cache (computing)](https://en.wikipedia.org/wiki/Cache_(computing))

Hash tables can be used to implement [caches](https://en.wikipedia.org/wiki/Cache_(computing)), auxiliary data tables that are used to speed up the access to data that is primarily stored in slower media. In this application, hash collisions can be handled by discarding one of the two colliding entries—usually erasing the old item that is currently stored in the table and overwriting it with the new item, so every item in the table has a unique hash value.

### Sets

Besides recovering the entry that has a given key, many hash table implementations can also tell whether such an entry exists or not.

Those structures can therefore be used to implement a [set data structure](https://en.wikipedia.org/wiki/Set_data_structure), which merely records whether a given key belongs to a specified set of keys. In this case, the structure can be simplified by eliminating all parts that have to do with the entry values. Hashing can be used to implement both static and dynamic sets.



### Object representation

Several dynamic languages, such as [Perl](https://en.wikipedia.org/wiki/Perl), [Python](https://en.wikipedia.org/wiki/Python_(programming_language)), [JavaScript](https://en.wikipedia.org/wiki/JavaScript), [Lua](https://en.wikipedia.org/wiki/Lua_(programming_language)), and [Ruby](https://en.wikipedia.org/wiki/Ruby_(programming_language)), use **hash tables** to implement objects. In this representation, the keys are the names of the members and methods of the object, and the values are pointers to the corresponding member or method.



### Unique data representation

Main article: [String interning](https://en.wikipedia.org/wiki/String_interning)

Hash tables can be used by some programs to avoid creating multiple character strings with the same contents. For that purpose, all strings in use by the program are stored in a single *string pool* implemented as a hash table, which is checked whenever a new string has to be created. This technique was introduced in [Lisp](https://en.wikipedia.org/wiki/Lisp_(programming_language)) interpreters under the name [hash consing](https://en.wikipedia.org/wiki/Hash_consing), and can be used with many other kinds of data ([expression trees](https://en.wikipedia.org/wiki/Expression_tree) in a symbolic algebra system, records in a database, files in a file system, binary decision diagrams, etc.).



### Transposition table

*Main article:* [Transposition table](https://en.wikipedia.org/wiki/Transposition_table)

