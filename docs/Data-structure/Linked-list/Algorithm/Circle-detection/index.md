# Circle-detection

linked-list中存在环说明这个linked-list没有tail-node，也就是说没有stop-condition。

## [LeetCode-141. 环形链表](https://leetcode.cn/problems/linked-list-cycle/) # [官方解题](https://leetcode.cn/problems/linked-list-cycle/solution/huan-xing-lian-biao-by-leetcode-solution/ )



### 方法一：哈希表

> NOTE: 这种方式其实就是visited-set，这是非常常见的一种方法。这是在graph中常用的一种technique。

### 方法二：快慢指针

> NOTE: 后面会进行介绍



## floyd判环(圈)算法

1、在阅读 [labuladong](javascript:void(0);) [双指针技巧汇总](https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg) 时，其中提及了快慢指针，其实它就是"floyd判环(圈)算法"

2、在 

中，对它也有介绍。

### csdn [算法-floyd判环(圈)算法](https://blog.csdn.net/u012534831/article/details/74231581)



### 思考: 快慢指针是否一定会相遇？

![](./labuladong-list-with-circle.jpg)

> NOTE: 
>
> 1、上图源自:  [labuladong](javascript:void(0);) [双指针技巧汇总](https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg) 

是否存在一种情况，两个pointer永远无法相遇？如何进行论证？

1、设环中节点个数为N，fast的出发位置为F，slow的出发位置为L，当两者相遇的时候fast pointer走的长度一定是slow pointer走的长度的2倍。

2、假设fast pointer和slow pointer都从head出发，相遇的时候slow pointer走了k，则fast pointer走了2k，则环的长度为k？即fast pointer多走了circle长度？两者相遇的时候，fast pointer一定绕了circle？

在  [labuladong](javascript:void(0);) [双指针技巧汇总](https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg) 中，给出了非常好的图示:

> NOTE: 
> 1、需要注意的是，两个pointer是从同一个位置出发的

![图片](./labuladong-fast slow pointer meet.jpg)



