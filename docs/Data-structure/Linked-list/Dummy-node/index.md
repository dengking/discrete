# Dummy node技巧

这是一种在linked list中，删除node时，常用的一种technique。

素材:

1、LeetCode [19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/) # [官方解题](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/) 

2、 labuladong [单链表的六大解题套路，你都见过么？](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492022&idx=1&sn=35f6cb8ab60794f8f52338fab3e5cda5&scene=21#wechat_redirect) 

## LeetCode [19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/) # [官方解题](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/) 

> NOTE:
>
> 1、是在阅读这篇文章的时候，发现的

在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），它的 $\textit{next}$ 指针指向链表的头节点。这样一来，我们就不需要对头节点进行特殊的判断了。

例如，在本题中，如果我们要删除节点 `y`，我们需要知道节点 `y` 的前驱节点 `x`，并将 `x` 的指针指向 `y` 的后继节点。但由于头节点不存在前驱节点，因此我们需要在删除头节点时进行特殊判断。但如果我们添加了哑节点，那么头节点的前驱节点就是哑节点本身，此时我们就只需要考虑通用的情况即可。

在 labuladong [单链表的六大解题套路，你都见过么？](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492022&idx=1&sn=35f6cb8ab60794f8f52338fab3e5cda5&scene=21#wechat_redirect) 中也展示了这种写法:

```Java
// 主函数
public ListNode removeNthFromEnd(ListNode head, int n) {
    // 虚拟头节点
    ListNode dummy = new ListNode(-1);
    dummy.next = head;
    // 删除倒数第 n 个，要先找倒数第 n + 1 个节点，即它的前驱节点
    ListNode x = findFromEnd(dummy, n + 1);
    // 删掉倒数第 n 个节点
    x.next = x.next.next;
    return dummy.next;
}

// 返回链表的倒数第 k 个节点
ListNode findFromEnd(ListNode head, int k) {
    ListNode p1 = head;
    // p1 先走 k 步
    for (int i = 0; i < k; i++) {
        p1 = p1.next;
    }
    ListNode p2 = head;
    // p1 和 p2 同时走 n - k 步
    while (p1 != null) {
        p2 = p2.next;
        p1 = p1.next;
    }
    // p2 现在指向第 n - k 个节点
    return p2;
}


```



## Linked list dummy node-技巧-create创建linked list-append to tail

使用"append to tail"模式来创建一个linked list的时候，使用一个循环即可，在这种情况下，就需要使用dummy node技巧，它使得程序非常的统一。

在下面的题中，使用到了这种技巧:

1、leetcode [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

2、leetcode [114. 二叉树展开为链表](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/)

3、leetcode [23. 合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)

