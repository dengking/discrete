# 前言

So how to choose data structure ? It is an art and worth learning。

本章对各种data structure进行对比:

1) 找出它们的共性、内在关联

2) 找出它们的个性

这样做的目的是为选择data structure提供参考意见。比较各种data structure，



## Trade off

下面这段话摘取自维基百科[Hash function](https://en.wikipedia.org/wiki/Hash_function#Efficiency)：

> In data storage and retrieval applications, use of a hash function is a trade off between **search time** and **data storage space**. If search time were unbounded, a very compact unordered linear list would be the best medium; if storage space were unbounded, a randomly accessible structure indexable by the key value would be very large, very sparse, but very fast. A hash function takes a finite amount of time to map a potentially large key space to a feasible amount of storage space searchable in a bounded amount of time regardless of the number of keys. 

在选择data structure的时候，我们总是在time和space上进行权衡。