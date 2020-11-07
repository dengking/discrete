





# [Skip List vs. Binary Search Tree](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree)

I recently came across the data structure known as a [*skip list*](http://en.wikipedia.org/wiki/Skip_list). It seems to have very similar behavior to a binary search tree.

Why would you ever want to use a skip list over a binary search tree?



## [A](https://stackoverflow.com/a/260277)

Skip lists are more amenable to concurrent access/modification. Herb Sutter wrote an [article](http://www.ddj.com/hpc-high-performance-computing/208801371) about data structure in concurrent environments. It has more indepth information.

The most frequently used implementation of a binary search tree is a [red-black tree](http://en.wikipedia.org/wiki/Red-black_tree). The concurrent problems come in when the tree is modified it often needs to rebalance. The rebalance operation can affect large portions of the tree, which would require a mutex lock on many of the tree nodes. Inserting a node into a skip list is far more localized, only nodes directly linked to the affected node need to be locked.

------

Update from Jon Harrops comments

I read Fraser and Harris's latest paper [Concurrent programming without locks](http://www.cl.cam.ac.uk/netos/papers/2007-cpwl.pdf). Really good stuff if you're interested in **lock-free** data structures. The paper focuses on [Transactional Memory](http://en.wikipedia.org/wiki/Transactional_memory) and a theoretical operation multiword-compare-and-swap MCAS. Both of these are simulated in software as no hardware supports them yet. I'm fairly impressed that they were able to build MCAS in software at all.

I didn't find the transactional memory stuff particularly compelling as it requires a garbage collector. Also [software transactional memory](http://en.wikipedia.org/wiki/Software_transactional_memory) is plagued with performance issues. However, I'd be very excited if hardware transactional memory ever becomes common. In the end it's still research and won't be of use for production code for another decade or so.

In section 8.2 they compare the performance of several concurrent tree implementations. I'll summarize their findings. It's worth it to download the pdf as it has some very informative graphs on pages 50, 53, and 54.

- **Locking skip lists** are insanely fast. They scale incredibly well with the number of concurrent accesses. This is what makes skip lists special, other lock based data structures tend to croak under pressure.
- **Lock-free skip lists** are consistently faster than locking skip lists but only barely.
- **transactional skip lists** are consistently 2-3 times slower than the locking and non-locking versions.
- **locking red-black trees** croak under concurrent access. Their performance degrades linearly with each new concurrent user. Of the two known locking red-black tree implementations, one essentially has a global lock during tree rebalancing. The other uses fancy (and complicated) lock escalation but still doesn't significantly out perform the global lock version.
- **lock-free red-black trees** don't exist (no longer true, see Update).
- **transactional red-black trees** are comparable with transactional skip-lists. That was very surprising and very promising. Transactional memory, though slower if far easier to write. It can be as easy as quick search and replace on the non-concurrent version.

------

Update
Here is paper about lock-free trees: [Lock-Free Red-Black Trees Using CAS](http://www.cs.umanitoba.ca/~hacamero/Research/RBTreesKim.pdf).
I haven't looked into it deeply, but on the surface it seems solid.



***COMMENTS*** : 

- 3

- Not to mention that in a non-degenerate skiplist, about 50% of the nodes should only have a single link which makes insert and delete remarkably efficient. – [Adisak](https://stackoverflow.com/users/14904/adisak) [Oct 30 '09 at 3:44](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment1518521_260277)

- 2

  Rebalancing does not require a mutex lock. See [cl.cam.ac.uk/research/srg/netos/lock-free](http://www.cl.cam.ac.uk/research/srg/netos/lock-free/) – [Jon Harrop](https://stackoverflow.com/users/13924/jon-harrop) [May 20 '10 at 21:00](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment2924085_260277)

- 3

  @Jon, yes and no. There are no known lock-free red-black tree implementations. Fraser and Harris show how a transactional memory based red-black tree is implemented and its performance. Transactional memory is still very much in the research arena, so in production code, a red-black tree will still need to lock large portions of the tree. – [deft_code](https://stackoverflow.com/users/28817/deft-code) [May 21 '10 at 16:20](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment2931059_260277)

- 1

  I wanted to update this answer. There are currently two lock based efficient binary search trees. One is based on AVL trees ([dl.acm.org/citation.cfm?id=1693488](http://dl.acm.org/citation.cfm?id=1693488)) and the other (Warning! shameless plug) is based on red black trees. See [actapress.com/Abstract.aspx?paperId=453069](http://www.actapress.com/Abstract.aspx?paperId=453069) – [Juan Besa](https://stackoverflow.com/users/72369/juan-besa) [Mar 2 '12 at 20:01](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment12087389_260277)

- 

  @JuanBesa, *"14% better than the best known concurrent dictionary solutions"*. Are you comparing against skip-lists? The other paper inadvertently points out that lock based trees are `O(n)` for n < 90, whereas skiplists (also a dictionary) are `O(1)`! 14% doesn't seem to be enough when the `O` is that disparate. – [deft_code](https://stackoverflow.com/users/28817/deft-code) [Mar 2 '12 at 22:08](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment12089713_260277) 

- 

  That RB tree paper looks bloody good! – user82238 [Jun 19 '12 at 10:22](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment14534999_260277)

- 

  Think I'm going to try to apply that basic mechanism to AVL. As I see it from a quick read, the basic solution to rotation (which is the fundamental problem) is to have a retry-block which is the raising of flags in the elements you need to control - if you can raise them all, then you're safe to proceed as other threads will fail and be retrying to get those flags. Simple genius! – user82238 [Jun 19 '12 at 10:29](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment14535161_260277)

- 

  @BlankXavier, Hmmm, that sounds suspiciously like using a spinlock instead of a mutex for a regular lock based tree. It may be more performant, but I want to see some benchmarks. In particular against the a lock-free skiplist and a locking skiplist. – [deft_code](https://stackoverflow.com/users/28817/deft-code) [Jun 20 '12 at 23:01](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment14585404_260277)

- 

  All helper mechanisms are essentially spinning mechanisms - it's just that rather than dumbly spinning, which performs no work, by spinning on a helper mechanism *which if it completes permits you to continue your own work*, then you're doing something useful - you're lock-free, in fact... – user82238 [Jun 21 '12 at 6:53](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment14590975_260277) 

- 4

  @deft_code: Intel recently announced an implementation of Transactional Memory via [TSX](http://software.intel.com/en-us/blogs/2012/02/07/transactional-synchronization-in-haswell) on Haswell. This may prove interesting w.r.t those lock free data structures you mentioned. – [Mike Bailey](https://stackoverflow.com/users/312124/mike-bailey) [Oct 3 '12 at 5:07](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment17149192_260277) 

- 1

  Any comment on [Respawned Fluff's recent answer](http://stackoverflow.com/a/28270537/15055)? – [Claudiu](https://stackoverflow.com/users/15055/claudiu) [Feb 2 '15 at 3:06](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment44896772_260277)

- 2

  I think [Fizz' answer](https://stackoverflow.com/a/28270537/1847419) is more up-to-date (from 2015) rather than this answer (2012) and therefore should probably be the preferred answer by now. – [fnl](https://stackoverflow.com/users/1847419/fnl) [Jul 11 '17 at 10:45](https://stackoverflow.com/questions/256511/skip-list-vs-binary-search-tree#comment77038160_260277)







# [B-tree](https://en.wikipedia.org/wiki/B-tree) VS [skip list](https://en.wikipedia.org/wiki/Skip_list)

看了这两种DS的原理，发现两者其实有些类似：以空间换时间，即通过构建数据之间的更多关系来加速数据的access，显然这些关系是需要耗费空间来存储的，所以就是前面所述的以空间换时间，其实当我看完了两者的原理后，觉得它们其实非常类似，尤其是看到[B-tree](https://en.wikipedia.org/wiki/B-tree)的主要应用是在DB或file system中实现索引后，我发掘其实它们的原理的共同之处其实就是index；通过重建index来加速数据的access；

于是我就想，既然[B-tree](https://en.wikipedia.org/wiki/B-tree)的主要应用是在DB或file system中实现索引，那么[skip list](https://en.wikipedia.org/wiki/Skip_list)是否也能够呢？

检索了一番后，发现其实是有应用案例的：

- [MemSQL](https://en.wikipedia.org/wiki/MemSQL) uses skip lists as its prime indexing structure for its database technology.

- [The Story Behind MemSQL’s Skiplist Indexes](https://www.memsql.com/blog/what-is-skiplist-why-skiplist-index-for-memsql/)



其实发现，在文件系统中多使用B-tree，而在内存中则多使用skip list