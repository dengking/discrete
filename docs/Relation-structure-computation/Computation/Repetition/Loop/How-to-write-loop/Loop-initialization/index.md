# Loop initialization

为了让循环体的逻辑简单、统一，有的时候会对循环变量做一些特殊的处理，下面是典型的例子

1、quick sort

2、linked list对head node对特殊处理

比如 [LeetCode-剑指 Offer 18. 删除链表的节点](https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/)

dummy node

3、定长滑动窗口，初始化窗口

4、合并k个有序链表

需要首先将各个链表的头节点放到`priority_queue`中，这就好比上面的定长滑动窗口，在下面演示了demo code:

labuladong [单链表的六大解题套路，你都见过么？](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==\&mid=2247492022\&idx=1\&sn=35f6cb8ab60794f8f52338fab3e5cda5\&scene=21#wechat_redirect)

