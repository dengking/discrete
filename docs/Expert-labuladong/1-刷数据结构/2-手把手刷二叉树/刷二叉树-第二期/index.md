# labuladong [东哥手把手帮你刷通二叉树|第二期](https://mp.weixin.qq.com/s/OlpaDhPDTJlQ5MJ8tsARlA)

> NOTE: 
>
> 一、原题
>
> [LeetCode-654. 最大二叉树](https://leetcode.cn/problems/maximum-binary-tree/) 中等
>
> [LeetCode-105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) 中等
>
> [LeetCode-106. 从中序与后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) 中等
>
> 二、
>
> 1、这三道题，都是运用recursive definition自顶向下地构造二叉树，即先构造出root node，然后分别构造left node、right node
>
> 2、这三道题，都是基于数组的



先来复习一下，我们说过写树的算法，关键思路如下：

**把题目的要求细化，搞清楚根节点应该做什么，然后剩下的事情抛给前/中/后序的遍历框架就行了**，我们千万不要跳进递归的细节里，你的脑袋才能压几个栈呀。

## 构造最大二叉树

> NOTE:
>
> [LeetCode-654. 最大二叉树](https://leetcode.cn/problems/maximum-binary-tree/) 中等





## 通过前序和中序遍历结果构造二叉树

> NOTE:
>
> [LeetCode-105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) 中等

经典问题了，面试/笔试中常考，力扣第 105 题就是这个问题：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_png/gibkIz0MVqdF8ZItXTVByS26EcqBSS9W6HLh9gbjia7hJ8O78PJKJWzicpA5mIeKwZtLUIq3msx2lFibOREdlpR7icg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



废话不多说，直接来想思路，首先思考，根节点应该做什么。

**类似上一题，我们肯定要想办法确定根节点的值，把根节点做出来，然后递归构造左右子树即可**。



前文 [二叉树就那几个框架](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485871&idx=1&sn=bcb24ea8927995b585629a8b9caeed01&chksm=9bd7f7a7aca07eb1b4c330382a4e0b916ef5a82ca48db28908ab16563e28a376b5ca6805bec2&scene=21#wechat_redirect) 写过，这样的遍历顺序差异，导致了`preorder`和`inorder`数组中的元素分布有如下特点：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdF8ZItXTVByS26EcqBSS9W6zvlia07hHvYB5JTKLTHCAmDW9I8dX8c8LmSo1ibejUHGibgH6zhMXBCmw/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

找到根节点是很简单的，前序遍历的第一个值`preorder[0]`就是根节点的值，关键在于如何通过根节点的值，将`preorder`和`postorder`数组划分成两半，构造根节点的左右子树？

换句话说，对于以下代码中的`?`部分应该填入什么：

```Java
/* 主函数 */
TreeNode buildTree(int[] preorder, int[] inorder) {
    return build(preorder, 0, preorder.length - 1,
                 inorder, 0, inorder.length - 1);
}

/* 
   若前序遍历数组为 preorder[preStart..preEnd]，
   后续遍历数组为 postorder[postStart..postEnd]，
   构造二叉树，返回该二叉树的根节点 
*/
TreeNode build(int[] preorder, int preStart, int preEnd, 
               int[] inorder, int inStart, int inEnd) {
    // root 节点对应的值就是前序遍历数组的第一个元素
    int rootVal = preorder[preStart];
    // rootVal 在中序遍历数组中的索引
    int index = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootVal) {
            index = i;
            break;
        }
    }

    TreeNode root = new TreeNode(rootVal);
    // 递归构造左右子树
    root.left = build(preorder, ?, ?,
                      inorder, ?, ?);

    root.right = build(preorder, ?, ?,
                       inorder, ?, ?);
    return root;
}
```

对于代码中的`rootVal`和`index`变量，就是下图这种情况：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdF8ZItXTVByS26EcqBSS9W6cuUtHIdXvXjbicaaZnpBWzEO1ZLfCGn9ntniaEicl5Et2wiarGaSq2GCZw/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

现在我们来看图做填空题，下面这几个问号处应该填什么：

```Java
root.left = build(preorder, ?, ?,
                  inorder, ?, ?);

root.right = build(preorder, ?, ?,
                   inorder, ?, ?);
```

对于左右子树对应的`inorder`数组的起始索引和终止索引比较容易确定：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdF8ZItXTVByS26EcqBSS9W6BFJp9KicjbvfTdvhU3vaDFEqaUiaNF1q3HzkyFjnpypG8XrGzJXdpeLg/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```Java
root.left = build(preorder, ?, ?,
                  inorder, inStart, index - 1);

root.right = build(preorder, ?, ?,
                   inorder, index + 1, inEnd);
```

对于`preorder`数组呢？如何确定左右数组对应的起始索引和终止索引？

这个可以通过**左子树的节点数**推导出来，假设左子树的节点数为`leftSize`，那么`preorder`数组上的索引情况是这样的：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdF8ZItXTVByS26EcqBSS9W6Awr35eI0tibAJ2qW6pDUpgWTv5icgDhRhniaIJg3dpYib7Ph5kqDneL08A/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



看着这个图就可以把`preorder`对应的索引写进去了：

```Java
int leftSize = index - inStart;

root.left = build(preorder, preStart + 1, preStart + leftSize,
                  inorder, inStart, index - 1);

root.right = build(preorder, preStart + leftSize + 1, preEnd,
                   inorder, index + 1, inEnd);
```

至此，整个算法思路就完成了，我们再补一补 base case 即可写出解法代码：

```Java
TreeNode build(int[] preorder, int preStart, int preEnd, 
               int[] inorder, int inStart, int inEnd) {

    if (preStart > preEnd) {
        return null;
    }

    // root 节点对应的值就是前序遍历数组的第一个元素
    int rootVal = preorder[preStart];
    // rootVal 在中序遍历数组中的索引
    int index = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootVal) {
            index = i;
            break;
        }
    }

    int leftSize = index - inStart;

    // 先构造出当前根节点
    TreeNode root = new TreeNode(rootVal);
    // 递归构造左右子树
    root.left = build(preorder, preStart + 1, preStart + leftSize,
                      inorder, inStart, index - 1);

    root.right = build(preorder, preStart + leftSize + 1, preEnd,
                       inorder, index + 1, inEnd);
    return root;
}
```





## 通过后序和中序遍历结果构造二叉树

> NOTE: 
>
> [LeetCode-106. 从中序与后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) 中等

