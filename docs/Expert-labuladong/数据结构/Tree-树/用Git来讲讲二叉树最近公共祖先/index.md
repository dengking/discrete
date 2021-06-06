# labuladong [用 Git 来讲讲二叉树最近公共祖先](https://mp.weixin.qq.com/s/9RKzBcr3I592spAsuMH45g)



上篇文章 [我用四个命令，总结了 Git 的所有套路](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485544&idx=1&sn=afc9d9f72d811ec847fa64108d5c7412&chksm=9bd7f660aca07f7643f31bf16ab56ba695d964cdadde2aebc72e6817074504890fb09d2a80ca&scene=21#wechat_redirect) 写了 Git 最常用的命令，没有提分支合并，其实分支合并没什么困难的，主要就是`merge`和`rebase`两种方式。本文就用 Git 的`rebase`工作方式引出一个经典的算法问题：**最近公共祖先**（Lowest Common Ancestor，简称 LCA）。

**实际工作中更推荐使用`rebase`方式合并代码**。



那么问题来了，`rebase`是如何将两条不同的分支合并到同一条分支的呢：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHQ3jgWZ62Db0Se4zTCAz6JrY0ZvMzanlDUCNnQP762JKJnzJGtPYbsUsp8jbrwZaia7eTMnERLrDA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

上图的情况是，我站在`dev`分支，使用`git rebase master`，然后就会把`dev`接到`master`分支之上。Git 是这么做的：

**首先，找到这两条分支的最近公共祖先`LCA`，然后从`master`节点开始，重演`LCA`到`dev`几个`commit`的修改**，如果这些修改和`LCA`到`master`的`commit`有冲突，就会提示你手动解决冲突，最后的结果就是把`dev`的分支完全接到`master`上面。

那么，Git 是如何找到两条不同分支的最近公共祖先的呢？这就是一个经典的算法问题了，下面来详解。

## 二叉树的最近公共祖先

这个问题可以在 LeetCode 上找到，第 236 题，看下题目：

> NOTE: 
>
> 原题: leetcode [236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)
>
> 

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHQ3jgWZ62Db0Se4zTCAz6Jic3UCtq3onR7PA6X2mibGeSZFqJ2KBwR9rOPob1X5r2FMcLibvictqEbxQ/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

函数的签名如下：

```java
TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q);
```

`root`节点确定了一棵二叉树，`p`和`q`是这这棵二叉树上的两个节点，让你返回`p`节点和`q`节点的最近公共祖先节点。

我们前文 [学习数据结构和算法的框架思维](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484852&idx=1&sn=85b50b8b0470bb4897e517955f4e5002&chksm=9bd7fbbcaca072aa75e2a241064a403fde1e579d57ab846cd8537a54253ceb2c8b93cc3bf38e&scene=21#wechat_redirect) 就说过了，所有二叉树的套路都是一样的：

```java
void traverse(TreeNode root) {
    // 前序遍历
    traverse(root.left)
    // 中序遍历
    traverse(root.right)
    // 后序遍历
}
```

所以，只要看到二叉树的问题，先把这个框架写出来准没问题：

```Java
TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    TreeNode left = lowestCommonAncestor(root.left, p, q);
    TreeNode right = lowestCommonAncestor(root.right, p, q);
}
```

现在我们思考如何添加一些细节，把框架改造成解法。



## 解法思路

### 第一个问题: 这个函数是干嘛的？

**首先看第一个问题，这个函数是干嘛的**？或者说，你给我描述一下`lowestCommonAncestor`这个函数的「定义」吧。

描述：给该函数输入三个参数`root`，`p`，`q`，它会返回一个节点。

情况 1，如果`p`和`q`都在以`root`为根的树中，函数返回的即是`p`和`q`的最近公共祖先节点。

情况 2，那如果`p`和`q`都不在以`root`为根的树中怎么办呢？函数理所当然地返回`null`呗。

情况 3，那如果`p`和`q`只有一个存在于`root`为根的树中呢？函数就会返回那个节点。

> NOTE: 
>
> 一、"那个节点"指的是什么？节点`p`、`q`。
>
> 二、为什么要这样做: 

题目说了输入的`p`和`q`一定存在于以`root`为根的树中，但是递归过程中，以上三种情况都有可能发生，所以说这里要定义清楚，后续这些定义都会在代码中体现。

### 第二个问题: 这个函数的参数中，变量是什么

**然后来看第二个问题，这个函数的参数中，变量是什么**？或者说，你描述一个这个函数的「状态」吧。

描述：函数参数中的变量是`root`，因为根据框架，`lowestCommonAncestor(root)`会递归调用`root.left`和`root.right`；至于`p`和`q`，我们要求它俩的**公共祖先**，它俩肯定不会变化的。

第二个问题也解决了，你也可以理解这是「状态转移」，每次递归在做什么？不就是在把「以`root`为根」转移成「以`root`的子节点为根」，不断缩小问题规模嘛？

### 第三个问题: 得到函数的递归结果，你该干嘛

**最后来看第三个问题，得到函数的递归结果，你该干嘛**？或者说，得到递归调用的结果后，你做什么「选择」？

这就像动态规划系列问题，怎么做选择，需要观察问题的性质，找规律。那么我们就得分析这个「最近公共祖先节点」有什么特点呢？刚才说了函数中的变量是`root`参数，所以这里都要围绕`root`节点的情况来展开讨论。

先想 base case，如果`root`为空，肯定得返回`null`。如果`root`本身就是`p`或者`q`，比如说`root`就是`p`节点吧，如果`q`存在于以`root`为根的树中，显然`root`就是最近公共祖先；即使`q`不存在于以`root`为根的树中，按照情况 3 的定义，也应该返回`root`节点。

以上两种情况的 base case 就可以把框架代码填充一点了：

```java
TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    // 两种情况的 base case
    if (root == null) return null;
    if (root == p || root == q) return root;

    TreeNode left = lowestCommonAncestor(root.left, p, q);
    TreeNode right = lowestCommonAncestor(root.right, p, q);
}
```

现在就要面临真正的挑战了，用递归调用的结果`left`和`right`来搞点事情。根据刚才第一个问题中对函数的定义，我们继续分情况讨论：

情况 1，如果`p`和`q`都在以`root`为根的树中，那么`left`和`right`一定分别是`p`和`q`（从 base case 看出来的）。

情况 2，如果`p`和`q`都不在以`root`为根的树中，直接返回`null`。

情况 3，如果`p`和`q`只有一个存在于`root`为根的树中，函数返回该节点。

明白了上面三点，可以直接看解法代码了：

```java
TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    // base case
    if (root == null) return null;
    if (root == p || root == q) return root;

    TreeNode left = lowestCommonAncestor(root.left, p, q);
    TreeNode right = lowestCommonAncestor(root.right, p, q);
    // 情况 1
    if (left != null && right != null) {
        return root;
    }
    // 情况 2
    if (left == null && right == null) {
        return null;
    }
    // 情况 3
    return left == null ? right : left;
}
```

对于情况 1，你肯定有疑问，`left`和`right`非空，分别是`p`和`q`，可以说明`root`是它们的公共祖先，但能确定`root`就是「最近」公共祖先吗？

l

这就是一个巧妙的地方了，**因为这里是二叉树的后序遍历啊**！前序遍历可以理解为是从上往下，而后序遍历是从下往上，就好比从`p`和`q`出发往上走，第一次相交的节点就是这个`root`，你说这是不是最近公共祖先呢？

综上，二叉树的最近公共祖先就计算出来了。

