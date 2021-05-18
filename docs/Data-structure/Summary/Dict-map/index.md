# Associative array、dict、map

有多种方式可以实现associative array，本文对它们进行对比。

## binary search tree VS hash table

在[Binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree)中，有如下对比：

> Binary search trees keep their keys in sorted order, so that lookup and other operations can use the principle of [binary search](https://en.wikipedia.org/wiki/Binary_search): when looking for a key in a tree (or a place to insert a new key), they traverse the tree from root to leaf, making comparisons to keys stored in the nodes of the tree and deciding, on the basis of the comparison, to continue searching in the left or right subtrees. On average, this means that each comparison allows the operations to skip about half of the tree, so that each lookup, insertion or deletion takes [time proportional to](https://en.wikipedia.org/wiki/Time_complexity) the [logarithm](https://en.wikipedia.org/wiki/Logarithm) of the number of items stored in the tree. This is much better than the [linear time](https://en.wikipedia.org/wiki/Linear_time) required to find items by key in an (unsorted) array, but slower than the corresponding operations on [hash tables](https://en.wikipedia.org/wiki/Hash_table).



## B tree VS hash table

### cstack.github [Introduction to the B-Tree](https://cstack.github.io/db_tutorial/parts/part7.html)

Why is a tree a good data structure for a database?

- Searching for a particular value is fast (logarithmic time)
- Inserting / deleting a value you’ve already found is fast (constant-ish time to rebalance)
- Traversing a range of values is fast (unlike a hash map)



## Self-balancing binary search tree VS hash table

### wikipedia [Self-balancing binary search tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree)

Self-balancing binary search trees can be used in a natural way to construct and maintain ordered lists, such as [priority queues](https://en.wikipedia.org/wiki/Priority_queue). They can also be used for [associative arrays](https://en.wikipedia.org/wiki/Associative_array); key-value pairs are simply inserted with an ordering based on the key alone. In this capacity, self-balancing BSTs have [a number of advantages and disadvantages](https://en.wikipedia.org/wiki/Associative_array#Efficient_representations) over their main competitor, [hash tables](https://en.wikipedia.org/wiki/Hash_table). One advantage of self-balancing BSTs is that they allow fast (indeed, asymptotically optimal) enumeration of the items *in key order*, which hash tables do not provide. One disadvantage is that their lookup algorithms get more complicated when there may be multiple items with the same key. Self-balancing BSTs have better worst-case lookup performance than hash tables (O(log n) compared to O(n)), but have worse average-case performance (O(log n) compared to O(1)).











## stackoverflow [Skip List vs. Binary Search Tree](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree)

I recently came across the data structure known as a [*skip list*](http://en.wikipedia.org/wiki/Skip_list). It seems to have very similar behavior to a binary search tree.

Why would you ever want to use a skip list over a binary search tree?



### [A](https://stackoverflow.com/a/260277)

Skip lists are more amenable to concurrent access/modification. Herb Sutter wrote an [article](http://www.ddj.com/hpc-high-performance-computing/208801371) about data structure in concurrent environments. It has more indepth information.

The most frequently used implementation of a binary search tree is a [red-black tree](http://en.wikipedia.org/wiki/Red-black_tree). The concurrent problems come in when the tree is modified it often needs to rebalance. The rebalance operation can affect large portions of the tree, which would require a mutex lock on many of the tree nodes. Inserting a node into a skip list is far more localized, only nodes directly linked to the affected node need to be locked.

------

Update from Jon Harrops comments

I read Fraser and Harris's latest paper [Concurrent programming without locks](http://www.cl.cam.ac.uk/netos/papers/2007-cpwl.pdf). Really good stuff if you're interested in **lock-free** data structures. The paper focuses on [Transactional Memory](http://en.wikipedia.org/wiki/Transactional_memory) and a theoretical operation multiword-compare-and-swap MCAS. Both of these are simulated in software as no hardware supports them yet. I'm fairly impressed that they were able to build MCAS in software at all.

I didn't find the transactional memory stuff particularly compelling as it requires a garbage collector. Also [software transactional memory](http://en.wikipedia.org/wiki/Software_transactional_memory) is plagued with performance issues. However, I'd be very excited if hardware transactional memory ever becomes common. In the end it's still research and won't be of use for production code for another decade or so.

In section 8.2 they compare the performance of several concurrent tree implementations. I'll summarize their findings. It's worth it to download the pdf as it has some very informative graphs on pages 50, 53, and 54.

1、**Locking skip lists** are insanely fast. They scale incredibly well with the number of concurrent accesses. This is what makes skip lists special, other lock based data structures tend to croak under pressure.

2、**Lock-free skip lists** are consistently faster than locking skip lists but only barely.

3、**transactional skip lists** are consistently 2-3 times slower than the locking and non-locking versions.

4、**locking red-black trees** croak under concurrent access. Their performance degrades linearly with each new concurrent user. Of the two known locking red-black tree implementations, one essentially has a global lock during tree rebalancing. The other uses fancy (and complicated) lock escalation but still doesn't significantly out perform the global lock version.

5、**lock-free red-black trees** don't exist (no longer true, see Update).

6、**transactional red-black trees** are comparable with transactional skip-lists. That was very surprising and very promising. Transactional memory, though slower if far easier to write. It can be as easy as quick search and replace on the non-concurrent version.

------

Update
Here is paper about lock-free trees: [Lock-Free Red-Black Trees Using CAS](http://www.cs.umanitoba.ca/~hacamero/Research/RBTreesKim.pdf).
I haven't looked into it deeply, but on the surface it seems solid.



***COMMENTS*** : 

Not to mention that in a non-degenerate(退化) skiplist, about 50% of the nodes should only have a single link which makes insert and delete remarkably efficient. – [Adisak](https://stackoverflow.com/users/14904/adisak) [Oct 30 '09 at 3:44](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment1518521_260277)



Rebalancing does not require a mutex lock. See [cl.cam.ac.uk/research/srg/netos/lock-free](http://www.cl.cam.ac.uk/research/srg/netos/lock-free/) – [Jon Harrop](https://stackoverflow.com/users/13924/jon-harrop) [May 20 '10 at 21:00](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment2924085_260277)



@Jon, yes and no. There are no known lock-free red-black tree implementations. Fraser and Harris show how a transactional memory based red-black tree is implemented and its performance. Transactional memory is still very much in the research arena, so in production code, a red-black tree will still need to lock large portions of the tree. – [deft_code](https://stackoverflow.com/users/28817/deft-code) [May 21 '10 at 16:20](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment2931059_260277)



I wanted to update this answer. There are currently two lock based efficient binary search trees. One is based on AVL trees ([dl.acm.org/citation.cfm?id=1693488](http://dl.acm.org/citation.cfm?id=1693488)) and the other (Warning! shameless plug) is based on red black trees. See [actapress.com/Abstract.aspx?paperId=453069](http://www.actapress.com/Abstract.aspx?paperId=453069) – [Juan Besa](https://stackoverflow.com/users/72369/juan-besa) [Mar 2 '12 at 20:01](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment12087389_260277)



@JuanBesa, *"14% better than the best known concurrent dictionary solutions"*. Are you comparing against skip-lists? The other paper inadvertently points out that lock based trees are `O(n)` for n < 90, whereas skiplists (also a dictionary) are `O(1)`! 14% doesn't seem to be enough when the `O` is that disparate. – [deft_code](https://stackoverflow.com/users/28817/deft-code) [Mar 2 '12 at 22:08](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment12089713_260277) 



That RB tree paper looks bloody good! – user82238 [Jun 19 '12 at 10:22](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment14534999_260277)



Think I'm going to try to apply that basic mechanism to AVL. As I see it from a quick read, the basic solution to rotation (which is the fundamental problem) is to have a retry-block which is the raising of flags in the elements you need to control - if you can raise them all, then you're safe to proceed as other threads will fail and be retrying to get those flags. Simple genius! – user82238 [Jun 19 '12 at 10:29](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment14535161_260277)



@BlankXavier, Hmmm, that sounds suspiciously like using a spinlock instead of a mutex for a regular lock based tree. It may be more performant, but I want to see some benchmarks. In particular against the a lock-free skiplist and a locking skiplist. – [deft_code](https://stackoverflow.com/users/28817/deft-code) [Jun 20 '12 at 23:01](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment14585404_260277)



All helper mechanisms are essentially spinning mechanisms - it's just that rather than dumbly spinning, which performs no work, by spinning on a helper mechanism *which if it completes permits you to continue your own work*, then you're doing something useful - you're lock-free, in fact... – user82238 [Jun 21 '12 at 6:53](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment14590975_260277) 



@deft_code: Intel recently announced an implementation of Transactional Memory via [TSX](http://software.intel.com/en-us/blogs/2012/02/07/transactional-synchronization-in-haswell) on Haswell. This may prove interesting w.r.t those lock free data structures you mentioned. – [Mike Bailey](https://stackoverflow.com/users/312124/mike-bailey) [Oct 3 '12 at 5:07](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment17149192_260277) 



Any comment on [Respawned Fluff's recent answer](http://stackoverflow.com/a/28270537/15055)? – [Claudiu](https://stackoverflow.com/users/15055/claudiu) [Feb 2 '15 at 3:06](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment44896772_260277)



I think [Fizz' answer](https://stackoverflow.com/a/28270537/1847419) is more up-to-date (from 2015) rather than this answer (2012) and therefore should probably be the preferred answer by now. – [fnl](https://stackoverflow.com/users/1847419/fnl) [Jul 11 '17 at 10:45](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment77038160_260277)







## [B-tree](https://en.wikipedia.org/wiki/B-tree) VS [skip list](https://en.wikipedia.org/wiki/Skip_list)

看了这两种DS的原理，发现两者其实有些类似：以空间换时间，即通过构建数据之间的更多关系来加速数据的access，显然这些关系是需要耗费空间来存储的，所以就是前面所述的以空间换时间，其实当我看完了两者的原理后，觉得它们其实非常类似，尤其是看到[B-tree](https://en.wikipedia.org/wiki/B-tree)的主要应用是在DB或file system中实现索引后，我发掘其实它们的原理的共同之处其实就是index；通过重建index来加速数据的access；

于是我就想，既然[B-tree](https://en.wikipedia.org/wiki/B-tree)的主要应用是在DB或file system中实现索引，那么[skip list](https://en.wikipedia.org/wiki/Skip_list)是否也能够呢？

检索了一番后，发现其实是有应用案例的：

- [MemSQL](https://en.wikipedia.org/wiki/MemSQL) uses skip lists as its prime indexing structure for its database technology.

- [The Story Behind MemSQL’s Skiplist Indexes](https://www.memsql.com/blog/what-is-skiplist-why-skiplist-index-for-memsql/)



其实发现，在文件系统中多使用B-tree，而在内存中则多使用skip list





## stackoverflow [Hash tables v self-balancing search trees](https://stackoverflow.com/questions/3265266/hash-tables-v-self-balancing-search-trees)

### A

Here is what I can think of:

1、There are kinds of data which cannot be hashed (or is too expensive to hash), therefore cannot be stored in hash tables.

2、Trees keep data in the order you need (sorted), not insertion order. You can't (effectively) do that with hash table, even if you run a linked list through it.

3、Trees have better worst-case performace



### A

Storage allocation is another consideration. Every time you fill all of the buckets in a hash-table, you need to allocate new storage and re-hash everything. This can be avoided if you know the size of the data ahead of time. On the other hand, balanced trees don't suffer from this issue at all.