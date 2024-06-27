# Traverse linked list

本节内容是 `Traverse-structure` 中关于linked list的章节。

linked list的结构非常简单，并且只支持 [sequential access](https://en.wikipedia.org/wiki/Sequential_access)，因此它的很多算法都是基于traverse的，所以本节首先介绍linked list的traverse的技巧。



## 两种最基本的traverse方式



### 算法总结

| 方向       | 从左到右-从首到尾                             | 从右到左-从尾到首 |
| ---------- | --------------------------------------------- | ----------------- |
| **迭代版** | previous-current-next-three-pointer-iteration | explici-stack     |
| **递归版** | DFS-pre-order                                 | DFS-post-order    |

1. 上述**递归版**是对**基础版**的递归实现，我们可以看出它们的内在关系

2. 上述两个递归版可以扩张对递归的认知，在后面会进行详细的对比

   

### 从左到右-从首到尾-迭代

foreach-node



previous-current-next-three-pointer-iteration





### 从右到左-从尾到首-explici-stack

在下面题目中使用了这种technique:

1、 [LeetCode-剑指 Offer 06. 从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)  

2、[LeetCode-445. 两数相加 II](https://leetcode.cn/problems/add-two-numbers-ii/) 



### 递归

有两种写法:

#### 一、从左到右-从首到尾-DFS-pre-order

1、这种写法是比较容易理解的，因为它符合"previous-current-next-three-pointer-iteration"

2、pre-order-action: 对cur进行修改: 将cur的next替换位`pre`，这样就完成了反转。



#### 二、从右到左-从尾到首-DFS-post-order

1、最最简单的例题就是: [LeetCode-剑指 Offer 06. 从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/) ，这道题要求将linked list逆序装入到vector中，它将此放到了post-order-acion中

2、这种写法我是在 [labuladong-递归反转链表：如何拆解复杂问题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484467&idx=1&sn=beb3ae89993b812eeaa6bbdeda63c494&scene=21#wechat_redirect) 中发现的，相较于 "从左到右-从首到尾-DFS-pre-order" 版本，这个版本的代码是不容易理解的、非常经典。它本质上也是符合"prev-cur-next"，递归体内每次对next进行修改: 将`next->next` 替换为`cur`，这样就完成了反转。它的运行过程有些类似于: append-to-tail。



#### 对比

一、下面两种递归写法都属于DFS+return-value，它们具有如下相同点:

1、两个版本的stop condition都是tail-node

2、两个版本的return value都是tail-node，因为tail-node是新的head

三、DFS linked list的执行过程如下:

1、入栈: 从head到tail(从左到右)

2、出栈: 从tail到head(从右到左)

显然存在两个方向，下面据此对上述两种算法进行详细对比分析:

1、DFS-pre-order : 

a、在入栈方向执行action，从head node开始执行action。

b、只能够采用action-1，从左到右-从首到尾修改linked-list的结构；

如果采用action-2，那么它会提前修改为访问节点的结构，这样当访问已经被修改的节点的时候，就无法得到它原本的next，此时会导致陷入dead-loop。

2、DFS-post-order: 

a、在出栈方向执行action，从tail node开始执行action。

b、只能够采用action-2，从右向左-从尾到首修改linked-list的结构；

无法采用action-1，因为这是single-linked-list，它无法access到它的previous node。



### 对比: 从右到左-从尾到首

1、这种本质上都是基于stack: 

explicit stack VS recursion implicit stack

2、体现两者差别的最最典型的例题就是: [LeetCode-剑指 Offer 06. 从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)  



### Traverse by iteration

一. previous-current-next-three-pointer

对linked list的很多操作，都是基于previous pointer+current pointer+next pointer，这是最最基本的方式。

二. fast-slow-double-pointer

快慢双指针



### Traverse by recursion

对于linked list，它的结构非常简单，它只有DFS。

素材: 

- labuladong [递归反转链表：如何拆解复杂问题](https://mp.weixin.qq.com/s/5wz_YJ3lTkDH3nWfVDi5SA) 

- labuladong [如何高效判断回文单链表？](https://mp.weixin.qq.com/s/tCgEoOlZKS_ohuTx1VxJ-Q) 

### Practice

- `Reverse-linked-list` 章节

  [LeetCode-206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/) 

- `Palindrome-linked-list` 章节

- `Merge-sorted-linked-list` 章节



## 高级的traverse方式

### k-step步长-span跨度-stride跨度-traverse

一、linked-list-k-step步长-span跨度-stride跨度-iteration

同样是可以使用prev-cur-next三指针



### k-way-traverse

"k-way"即"多路"，表示同时traverse多个linked-list



### 从两边到中间相向而行、from sides to middle

一、回文式、消消乐

最最典型的就是回文链表，参见:

1、labuladong [如何高效判断回文单链表？](https://mp.weixin.qq.com/s/tCgEoOlZKS_ohuTx1VxJ-Q) 
