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

在 wanweibaike [Linked list](https://en.wanweibaike.com/wiki-Linked%20list) 中，有着非常好的总结。

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

### 存储方式

参见下面的"存储方式"章节。



## 存储方式

存储方式包括: 

1、Array-based （顺序存储）

2、linked-list-based（链式存储）

3、mixed

如下是一些较好的素材。

### labuladong  [数据结构和算法学习指南](https://mp.weixin.qq.com/s/ZYaXOSVM3YBIeRWm7E_jcQ)

**数据结构的存储方式只有两种：数组（顺序存储）和链表（链式存储）**。

> NOTE: 
>
> 1、后续将它们称为array-based、linked-list-based
>
> 2、其实还有混合两者的，比如hash table

这句话怎么理解，不是还有散列表、栈、队列、堆、树、图等等各种数据结构吗？

我们分析问题，一定要有递归的思想，自顶向下，从抽象到具体。你上来就列出这么多，那些都属于「上层建筑」，而数组和链表才是「结构基础」。因为那些多样化的数据结构，究其源头，都是在链表或者数组上的特殊操作，API 不同而已。

比如说**「队列」**、**「栈」**这两种数据结构既可以使用链表也可以使用数组实现。用数组实现，就要处理扩容缩容的问题；用链表实现，没有这个问题，但需要更多的内存空间存储节点指针。

**「图」**的两种表示方法，邻接表就是链表，邻接矩阵就是二维数组。邻接矩阵判断连通性迅速，并可以进行矩阵运算解决一些问题，但是如果图比较稀疏的话很耗费空间。邻接表比较节省空间，但是很多操作的效率上肯定比不过邻接矩阵。

...

#### 对比

综上，数据结构种类很多，甚至你也可以发明自己的数据结构，但是底层存储无非数组或者链表，**二者的优缺点如下**：

**数组**由于是紧凑连续存储,可以随机访问，通过索引快速找到对应元素，而且相对节约存储空间。但正因为连续存储，内存空间必须一次性分配够，所以说数组如果要扩容，需要重新分配一块更大的空间，再把数据全部复制过去，时间复杂度 O(N)；而且你如果想在数组中间进行插入和删除，每次必须搬移后面的所有数据以保持连续，时间复杂度 O(N)。

**链表**因为元素不连续，而是靠指针指向下一个元素的位置，所以不存在数组的扩容问题；如果知道某一元素的前驱和后驱，操作指针即可删除该元素或者插入新元素，时间复杂度 O(1)。但是正因为存储空间不连续，你无法根据一个索引算出对应元素的地址，所以不能随机访问；而且由于每个元素必须存储指向前后元素位置的指针，会消耗相对更多的储存空间。

> NOTE: 
>
> 1、还可以从cache的角度对两者的访问性能进行对比，这就是C++中的value semantic和reference semantic



