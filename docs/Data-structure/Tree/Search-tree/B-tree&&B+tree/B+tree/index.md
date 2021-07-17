# B+ Tree

## Example

### segmentfault [由 B-/B+树看 MySQL索引结构](https://segmentfault.com/a/1190000004690721)

![图片描述](https://segmentfault.com/img/bVtQp6)

## geeksforgeeks [Introduction of B+ Tree](https://www.geeksforgeeks.org/introduction-of-b-tree/)

In order, to implement dynamic multilevel indexing, [B-tree](https://www.geeksforgeeks.org/b-tree-set-1-introduction-2/) and B+ tree are generally employed. The drawback of B-tree used for indexing, however is that it stores the data pointer (a pointer to the disk file block containing the key value), corresponding to a particular key value, along with that key value in the node of a B-tree. This technique, greatly reduces the number of entries that can be packed into a node of a B-tree, thereby contributing to the increase in the number of levels in the B-tree, hence increasing the search time of a record.

> NOTE: 
>
> 一、search tree的搜索时间是由树高决定的
>
> 其实，它在此处的介绍都是非常不细致的，在下面的文章中进行了非常细致的介绍:
>
> codinglabs [MySQL索引背后的数据结构及算法原理](http://blog.codinglabs.org/articles/theory-of-mysql-index.html)
>
> 



## usfca [B+ Trees visualization](https://www.cs.usfca.edu/~galles/visualization/BPlusTree.html)



## infogalactic [B+ tree](https://infogalactic.com/info/B%2B_tree)