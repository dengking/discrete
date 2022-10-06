# Reverse-linked-list

## 素材

一、labuladong

[递归反转链表：如何拆解复杂问题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484467&idx=1&sn=beb3ae89993b812eeaa6bbdeda63c494&scene=21#wechat_redirect)

[递归思维：k 个一组反转链表](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484597&idx=1&sn=c603f1752e33cb2701e371d84254aee2&scene=21#wechat_redirect)



## algorithm



### 递归

这两种递归写法都属于dfs+return-value，dfs linked list的实际执行过程其实相当于从head到tail(从左到右)，再从tail到head(从右到左)绕了一圈，有两种写法:

一、pre-order-从左到右

这种写法是比较容易理解的，因为它符合"prev-cur-next"，递归体内每次对cur进行修改: 将cur的next替换位`pre`，这样就完成了反转。



二、post-order-从右到左

初次阅读它的代码是不容易理解的，它本质上也是符合"prev-cur-next"，递归体内每次对next进行修改: 将`next->next` 替换为`cur`，这样就完成了反转。它的运行过程有些类似于: append-to-tail。



### 迭代

迭代的代码是基于"prev-cur-next" + one-by-one + move-next。



## 题目

花样还是不少的: 

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