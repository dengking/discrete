# segmentfault [由 B-/B+树看 MySQL索引结构](https://segmentfault.com/a/1190000004690721)

## B-树

B-树,这里的 B 表示 balance( 平衡的意思),B-树是一种多路自平衡的搜索树

它类似普通的平衡二叉树，不同的一点是B-树允许每个节点有更多的子节点。下图是 B-树的简化图.

![图片描述](https://segmentfault.com/img/bVtQp5)

B-树有如下特点:

1、所有键值分布在整颗树中；

2、任何一个关键字出现且只出现在一个结点中；

3、搜索有可能在非叶子结点结束；

4、在关键字全集内做一次查找,性能逼近二分查找；

## B+ 树

B+树是B-树的变体，也是一种多路搜索树, 它与 B- 树的不同之处在于:

1、所有关键字存储在叶子节点出现,内部节点(非叶子节点并不存储真正的 data)

2、为所有叶子结点增加了一个链指针

简化 B+树 如下图

![图片描述](https://segmentfault.com/img/bVtQp6)

## 为什么使用B-/B+ Tree

> NOTE: 
>
> 原文后面的内容其实很多都是借鉴的 codinglabs [MySQL索引背后的数据结构及算法原理](http://blog.codinglabs.org/articles/theory-of-mysql-index.html) 

