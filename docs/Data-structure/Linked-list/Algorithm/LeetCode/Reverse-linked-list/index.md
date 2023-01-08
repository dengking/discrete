# Reverse-linked-list

## 素材

一、labuladong

[递归反转链表：如何拆解复杂问题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484467&idx=1&sn=beb3ae89993b812eeaa6bbdeda63c494&scene=21#wechat_redirect)

[递归思维：k 个一组反转链表](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484597&idx=1&sn=c603f1752e33cb2701e371d84254aee2&scene=21#wechat_redirect)



## algorithm

一、在 [LeetCode-206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/) 中，展示了下面各种写法。

二、算法总结:

| 方向       | 从左到右-从首到尾                             | 从右到左-从尾到首 |
| ---------- | --------------------------------------------- | ----------------- |
| **基础版** | previous-current-next-three-pointer-iteration | explici-stack     |
| **递归版** | DFS-pre-order                                 | DFS-post-order    |

1、上述**递归版**是对**基础版**的递归实现，我们可以看出它们的内在关系

2、上述两个递归版扩张了我对递归的认知，在后面会进行详细的对比

3、实现reverse有如下两种方式:

action-1: 让current node指向它的previous node

action-2: 让current node的next node指向current node

### 从左到右-从首到尾-迭代

1、基于"previous-current-next-three-pointer-iteration"；

2、action-1



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





## LeetCode题目



一、反转整个linked list

二、反转部分linked list

[LeetCode-92. 反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii/)



三、k个一组反转

[LeetCode-25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/)



### 反转后与原链表连接

对于反转这个linked list，不需要考虑这个问题，但是对于反转linked list中的一部分，则需要考虑这个问题，在下面的题目中都涉及这个问题:

1、[LeetCode-92. 反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii/)

2、[LeetCode-25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/)

在labuladong的两篇文章中都涉及这个内容。