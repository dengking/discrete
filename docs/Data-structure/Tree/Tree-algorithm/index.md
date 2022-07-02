# Tree algorithm

正如在 `Computation-on-structure` 中，所总结的:

> Traverse是一种基础的操作，很多其他的operation、algorithm都是建立在traverse的基础之上的。

tree algorithm很多都是基于traversal的，下面是我的一些总结:

## post order traversal能够将children node的information总结带到parent node中

1、这是我在做 leetcode [124. 二叉树中的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum/) 时，悟出的。

### 典型例子

1、LeetCode [337. 打家劫舍 III](https://leetcode.cn/problems/house-robber-iii/) 中等

参见 labuladong [团灭 LeetCode 打家劫舍问题](https://mp.weixin.qq.com/s/z44hk0MW14_mAQd7988mfw)

2、LeetCode [333. 最大 BST 子树](https://leetcode.cn/problems/largest-bst-subtree/)

参见 geeksforgeeks [Maximum sub-tree sum in a Binary Tree such that the sub-tree is also a BST](https://www.geeksforgeeks.org/maximum-sub-tree-sum-in-a-binary-tree-such-that-the-sub-tree-is-also-a-bst/?ref=rp)



### Application

它有着非常多的application，比如:

1、将children node的value累加到parent node

2、post order traverse一棵expression tree，能够完成expression evaluation。

3、sum，参见`Sum`章节



## LeetCode tree

### recursion

LeetCode [226. 翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/) 简单

LeetCode [116. 填充每个节点的下一个右侧节点指针](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/) 中等

BFS

### `Double-linked-list-VS-binary-tree`

Leetcode [114. 二叉树展开为链表](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/)

一、主要是考察先序遍历。

二、采用"linked list dummy node-技巧-append to tail create创建linked list"，因此需要使用成员变量`tail`来记录当前linked list的tail node。



### 构建二叉树

LeetCode [654. 最大二叉树](https://leetcode.cn/problems/maximum-binary-tree/)

自顶向下构造二叉树

LeetCode [105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) 中等、LeetCode [106. 从中序与后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) 中等

自顶向下构造二叉树

### Serialization-deserialization

LeetCode [105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) 中等

LeetCode [106. 从中序与后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) 中等

### BST

