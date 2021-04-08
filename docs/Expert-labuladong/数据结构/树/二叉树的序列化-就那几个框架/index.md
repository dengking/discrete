# labuladong [二叉树的题，就那几个框架，枯燥至极](https://mp.weixin.qq.com/s/DVX2A1ha4xSecEXLxW_UsA)

PS：一般语境下，单单前序遍历结果是不能还原二叉树结构的，因为缺少空指针的信息，至少要得到前、中、后序遍历中的两种才能还原二叉树。但是这里的 `node` 列表包含空指针的信息，所以只使用 `node` 列表就可以还原二叉树。

> NOTE: 
>
> 1、参见 leetcode [105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)，其中就是给出了两个不含`null`的前序、中序遍历结果来还原二叉树。