# LeetCode 最近公共祖先 试题分析



[235. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) 简单

需要注意，是二叉搜索树

[236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/) 中等

最简单的二叉树

对于这两道题，我使用 labuladong [用 Git 来讲讲二叉树最近公共祖先](https://mp.weixin.qq.com/s/9RKzBcr3I592spAsuMH45g) 中给出的递归深度优先方式，都通过了。



## VIP试题



[1644. 二叉树的最近公共祖先 II](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/) 中等

给定一棵二叉树的根节点 `root`，返回给定节点 `p` 和 `q` 的最近公共祖先（LCA）节点。如果 `p` 或 `q` 之一不存在于该二叉树中，返回 null。树中的每个节点值都是互不相同的。

根据维基百科中对最近公共祖先节点的定义：“两个节点 p 和 q 在二叉树 T 中的最近公共祖先节点是后代节点中既包括 p 又包括 q 的最深节点（我们允许一个节点为自身的一个后代节点）”。一个节点 x 的后代节点是节点 x 到某一叶节点间的路径中的节点 y。

> NOTE: 
>
> 这道题和 [236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/) 相比，多了一个限制条件:
>
> "如果 `p` 或 `q` 之一不存在于该二叉树中，返回 null"
>
> 



[1650. 二叉树的最近公共祖先 III](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/) 中等

给定一棵二叉树中的两个节点 p 和 q，返回它们的最近公共祖先节点（LCA）。

每个节点都包含其父节点的引用（指针）。Node 的定义如下：

```C++
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node parent;
}
```

根据维基百科中对最近公共祖先节点的定义：“两个节点 p 和 q 在二叉树 T 中的最近公共祖先节点是后代节点中既包括 p 又包括 q 的最深节点（我们允许一个节点为自身的一个后代节点）”。一个节点 x 的后代节点是节点 x 到某一叶节点间的路径中的节点 y。

 

[1676. 二叉树的最近公共祖先 IV](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/) 中等

给定一棵二叉树的根节点 root 和 TreeNode 类对象的数组（列表） nodes，返回 nodes 中所有节点的最近公共祖先（LCA）。数组（列表）中所有节点都存在于该二叉树中，且二叉树中所有节点的值都是互不相同的。

我们扩展二叉树的最近公共祖先节点在维基百科上的定义：“对于任意合理的 i 值， n 个节点 p1 、 p2、...、 pn 在二叉树 T 中的最近公共祖先节点是后代中包含所有节点 pi 的最深节点（我们允许一个节点是其自身的后代）”。一个节点 x 的后代节点是节点 x 到某一叶节点间的路径中的节点 y。

