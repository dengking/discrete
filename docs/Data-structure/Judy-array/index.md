# Judy array

一、在阅读 wanweibaike [Hash table](https://en.wanweibaike.com/wiki-Hash%20map) 时，其中提及了Judy array:

> For certain string processing applications, such as [spell-checking](https://en.wanweibaike.com/wiki-Spell_checker), hash tables may be less efficient than [tries](https://en.wanweibaike.com/wiki-Trie), [finite automata](https://en.wanweibaike.com/wiki-Finite_automata), or [Judy arrays](https://en.wanweibaike.com/wiki-Judy_array).

二、Judy array也能够用来实现 **dict-map-associative array**



## wanweibaike [Judy array](https://en.wanweibaike.com/wiki-Judy%20arrays)

In [computer science](https://en.wanweibaike.com/wiki-Computer_science), a **Judy array** is a [data structure](https://en.wanweibaike.com/wiki-Data_structure) implementing a type of [associative array](https://en.wanweibaike.com/wiki-Associative_array) with high performance and low memory usage.[[1\]](https://en.wanweibaike.com/wiki-Judy arrays#cite_note-1) Unlike most other [key-value stores](https://en.wanweibaike.com/wiki-Key-value_store), Judy arrays use no hashing, leverage compression(压缩) on their keys (which may be integers or strings), and can efficiently represent sparse(稀疏) data, that is, they may have large ranges of unassigned indices without greatly increasing memory usage or processing time. They are designed to remain efficient even on structures with sizes in the peta-element range, with performance scaling on the order of O(log *n*).[[2\]](https://en.wanweibaike.com/wiki-Judy arrays#cite_note-2) Roughly speaking, Judy arrays are highly optimized 256-ary [radix trees](https://en.wanweibaike.com/wiki-Radix_tree).[[3\]](https://en.wanweibaike.com/wiki-Judy arrays#cite_note-3)

Judy trees are usually faster than [AVL trees](https://en.wanweibaike.com/wiki-AVL_tree), [B-trees](https://en.wanweibaike.com/wiki-B-tree), [hash tables](https://en.wanweibaike.com/wiki-Hash_table) and [skip lists](https://en.wanweibaike.com/wiki-Skip_list) because they are highly optimized to maximize usage of the [CPU cache](https://en.wanweibaike.com/wiki-CPU_cache). In addition, they require no tree balancing and no hashing algorithm is used.[[4\]](https://en.wanweibaike.com/wiki-Judy arrays#cite_note-4)

The Judy array was invented by Douglas Baskins and named after his sister.[[5\]](https://en.wanweibaike.com/wiki-Judy arrays#cite_note-judy.sourceforge.net-5)





## baike [朱迪矩阵](https://baike.baidu.com/item/%E6%9C%B1%E8%BF%AA%E7%9F%A9%E9%98%B5/22688918?fr=aladdin)

### 算法

从Judy array的发明者所撰写的简介以及其他一些相关的中文论文中看，设计中使用了多种的压缩思想与压缩算法，根据不同的密度情况，选择不同的压缩方式，以期尽可能节省内存，降低实际存储中的稀疏情况，我猜测，这能够在缓存命中率上带来不少提升，进而提升效率。

看到的算法思路包括：

- 对于密度很高，空洞很少的节点，使用位图（bitmap）来存储。
- 对于密度很低的情况，只存储出现的键值
- 对于密度极低的情况，使用类似于[字典树](https://baike.baidu.com/item/字典树/9825209)的结构，跨层压缩数据。