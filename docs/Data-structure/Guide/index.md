# Guide

本章对各种data structure进行对比:

1) 找出它们的共性、内在关联

2) 找出它们的个性

这样做的目的是为选择data structure提供参考意见。

> "So how to choose data structure ? It is an art and worth learning"



## 从最基础的array 和 linked list开始说起

array 和 linked list不仅仅是两种data structure，它们所代表的是两种典型的存储方式，存储方式的不同决定了它们的典型差异，在下面的文章中，对此进行了非常好的解读:

1、geeksforgeeks [Linked List vs Array](https://www.geeksforgeeks.org/linked-list-vs-array/)

2、studytonight [Difference between Array and Linked List](https://www.studytonight.com/data-structures/linked-list-vs-array)

linked list只能够 [sequential access](https://en.wanweibaike.com/wiki-Sequential_access)，但是array能够random access。

在 wikipedia [Linked list](https://en.wanweibaike.com/wiki-Linked%20list) 中，有着非常好的总结。

3、labuladong  [数据结构和算法学习指南](https://mp.weixin.qq.com/s/ZYaXOSVM3YBIeRWm7E_jcQ)

## Trade off

下面这段话摘取自维基百科[Hash function](https://en.wikipedia.org/wiki/Hash_function#Efficiency)：

> In data storage and retrieval applications, use of a hash function is a trade off between **search time** and **data storage space**. If search time were unbounded, a very compact unordered linear list would be the best medium; if storage space were unbounded, a randomly accessible structure indexable by the key value would be very large, very sparse, but very fast. A hash function takes a finite amount of time to map a potentially large key space to a feasible amount of storage space searchable in a bounded amount of time regardless of the number of keys. 

在选择data structure的时候，我们总是在如下方面进行tradeoff: 

### Time complexity

各种operation的time complexity，programmer需要根据

### Space complexity

相比于其他的，是否需要花费更多的空间，典型的例子就是linked list的next pointer

### Concurrency

对于concurrent programming，这是非常重要的一个角度，参见 `Concurrent-data-structure` 章节。

### Sorted or unsorted

是否有序？

### [Cache performance](https://en.wikipedia.org/wiki/Locality_of_reference)

1、在 wikipedia [Hash table](https://en.wikipedia.org/wiki/Hash_table) 中对此进行了说明

## Classification

### Linear and non-linear

本节讨论对ADT的分类:

1) sequence

2) non-linear，比如map-dict

底层的data structure，则分为非常多的类别。

## 存储方式、implementation

参见`ADT&Impl`章节。



