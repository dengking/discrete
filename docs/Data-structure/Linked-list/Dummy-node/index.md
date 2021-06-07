# Dummy node技巧

这是一种在linked list中，删除node时，常用的一种technique。

## LeetCode [19. 删除链表的倒数第 N 个结点](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/) # [官方解题](https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/)

> NOTE:
>
> 1、是在阅读这篇文章的时候，发现的

在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），它的 $\textit{next}$ 指针指向链表的头节点。这样一来，我们就不需要对头节点进行特殊的判断了。

例如，在本题中，如果我们要删除节点 yy，我们需要知道节点 yy 的前驱节点 xx，并将 xx 的指针指向 yy 的后继节点。但由于头节点不存在前驱节点，因此我们需要在删除头节点时进行特殊判断。但如果我们添加了哑节点，那么头节点的前驱节点就是哑节点本身，此时我们就只需要考虑通用的情况即可。



## Linked list dummy node-技巧-create创建linked list-append to tail

使用"append to tail"模式来创建一个linked list的时候，使用一个循环即可，在这种情况下，就需要使用dummy node技巧，它使得程序非常的统一。

在下面的题中，使用到了这种技巧:

1、leetcode [21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/)

2、leetcode [114. 二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)

3、leetcode [23. 合并K个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)

