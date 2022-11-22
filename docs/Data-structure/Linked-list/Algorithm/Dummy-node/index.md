# Dummy node技巧

## stackoverflow [What is a Dummy Head?](https://stackoverflow.com/questions/37324972/what-is-a-dummy-head)



[A](https://stackoverflow.com/a/50221469)

When the **head** of the Linked List doesn't point to any Node, you create a Dummy Head (Node) pointed from that **head**. So that you would always be able to reach e.g. `head.val` or `head.next` without doing any extra null checks.





这是一种在linked list algorithm实现中，常用的一种technique，按照字面意思"dummy"的意思是"假的"，其实本质上来说，"dummy node"的确是"假的头节点"，它相当于一个**占位符**，包装总是有这样的一个节点在（最最典型的就是 [LeetCode-19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/) ），这样就避免了在对链表进行**修改**的时候对空指针进行讨论而增加代码的复杂度，在 labuladong [单链表的六大解题套路，你都见过么？](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492022&idx=1&sn=35f6cb8ab60794f8f52338fab3e5cda5&scene=21#wechat_redirect)  中，将其称之为"虚拟头节点"，这个翻译更加准确。在对链表的如下修改中，可以使用这个technique:

1、create linked list

采用的是"append to tail"的模式。

2、delete node



素材:

1、[LeetCode-19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/) # [官方解题](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/) 

2、 labuladong [单链表的六大解题套路，你都见过么？](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492022&idx=1&sn=35f6cb8ab60794f8f52338fab3e5cda5&scene=21#wechat_redirect) 



> **代码中还用到一个链表的算法题中是很常见的「虚拟头节点」技巧，也就是`dummy`节点**。你可以试试，如果不使用`dummy`虚拟节点，代码会复杂很多，而有了`dummy`节点这个**占位符**，可以避免处理空指针的情况，降低代码的复杂性。



> 不过注意我们又使用了虚拟头结点的技巧，也是为了防止出现空指针的情况，比如说链表总共有 5 个节点，题目就让你删除倒数第 5 个节点，也就是第一个节点，那按照算法逻辑，应该首先找到倒数第 6 个节点。但第一个节点前面已经没有节点了，这就会出错。
>
> 但有了我们虚拟节点`dummy`的存在，就避免了这个问题，能够对这种情况进行正确的删除。



其中将"dummy node"翻译为"虚拟头节点"。

3、stackoverflow [Dummy nodes in linked lists](https://stackoverflow.com/questions/22952882/dummy-nodes-in-linked-lists)

4、[Linked List - 链表](https://algorithm.yuanbin.me/zh-hans/basics_data_structure/linked_list.html#dummy-node)

5、reddit [[C+] In a linked list what is a dummy node?](https://www.reddit.com/r/learnprogramming/comments/20e0yc/c_in_a_linked_list_what_is_a_dummy_node/)



## [LeetCode-19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/) # [官方解题](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/) 

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

1、[LeetCode-21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

2、[LeetCode-114. 二叉树展开为链表](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/)

3、[LeetCode-23. 合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)

