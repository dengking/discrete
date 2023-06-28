# B tree、B+tree

提及B tree、B+tree，自然而然地就会想到数据库索引，这是它们的主要用途，在下面文章中，对它们的原理、用途、对比进行了非常好的描述:

1、codinglabs [MySQL索引背后的数据结构及算法原理](http://blog.codinglabs.org/articles/theory-of-mysql-index.html)

非常好的一篇文章，国内很多文章，都借鉴了这篇文章的内容。

2、segmentfault [由 B-/B+树看 MySQL索引结构](https://segmentfault.com/a/1190000004690721)

给出的例子比较不错。

基本上，从上述两篇文章能够得知两种DS的原理、区别。



## 思考如下问题

### 为什么B tree、B+ tree适合作为数据库index



1、codinglabs [MySQL索引背后的数据结构及算法原理](http://blog.codinglabs.org/articles/theory-of-mysql-index.html)

这个问题在这篇文章中进行了讨论。

2、B-tree相比于red-black tree，更少的re-balance，这就意味着，更少的disk IO。



### B tree VS B+tree 

1、geeksforgeeks [Introduction of B+ Tree](https://www.geeksforgeeks.org/introduction-of-b-tree/)

B tree的internal node和leaf node相同，都会存储key、value

B+tree的internal node和leaf node不相同，internal node存储key，不存储value



### B+tree VS skip list

B+tree和skip list两者是非常类似的，它们都使用了index、它们的index都是key、它们都是ordered、最底层都是linked list；

## TODO

cnblogs [图解MySQL索引--B-Tree（B+Tree）](https://www.cnblogs.com/liqiangchn/p/9060521.html)