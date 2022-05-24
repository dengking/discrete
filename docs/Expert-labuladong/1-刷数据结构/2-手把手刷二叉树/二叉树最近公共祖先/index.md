# LeetCode 最近公共祖先 

## labuladong文章

labuladong [一文秒杀 5 道最近公共祖先问题](https://mp.weixin.qq.com/s/njl6nuid0aalZdH5tuDpqQ)

这篇文章更好理解一些，它从寻找一个节点入手，然后循序渐进。它揭示了最近公共祖先其实是在节点查找上衍生而来的。

labuladong [用 Git 来讲讲二叉树最近公共祖先](https://mp.weixin.qq.com/s/9RKzBcr3I592spAsuMH45g) 

## labuladong [一文秒杀 5 道最近公共祖先问题](https://mp.weixin.qq.com/s/njl6nuid0aalZdH5tuDpqQ)

### 寻找一个元素

```c++
TreeNode find(TreeNode root, int val) {
    // base case
    if (root == null) {
        return null;
    }
    // 看看 root.val 是不是要找的
    if (root.val == val) {
        return root;
    }
    // root 不是目标节点，那就去左子树找
    TreeNode left = find(root.left, val);
    if (left != null) {
        return left;
    }
    // 左子树找不着，那就去右子树找
    TreeNode right = find(root.right, val);
    if (right != null) {
        return right;
    }
    // 实在找不到了
    return null;
}
```

### 查找两个元素

最后，我再改一下题目，现在不让你找值为`val`的节点，而是寻找值为`val1`**或**`val2`的节点，函数签名如下：

```java
TreeNode find(TreeNode root, int val1, int val2);
```

这和我们第一次实现的`find`函数基本上是一样的，而且你应该知道可以有多种写法，我选择这样写代码：

```java
// 定义：在以 root 为根的二叉树中寻找值为 val1 或 val2 的节点
TreeNode find(TreeNode root, int val1, int val2) {
    // base case
    if (root == null) {
        return null;
    }
    // 前序位置，看看 root 是不是目标值
    if (root.val == val1 || root.val == val2) {
        return root;
    }
    // 去左右子树寻找
    TreeNode left = find(root.left, val1, val2);
    TreeNode right = find(root.right, val1, val2);
    // 后序位置，已经知道左右子树是否存在目标值

    return left != null ? left : right;
}
```



**为什么要写这样一个奇怪的`find`函数呢？因为最近公共祖先系列问题的解法都是把这个函数作为框架的**。



## 试题

### [235. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) 



```c++

class Solution
{
public:
	TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (!root)
		{
			return nullptr;
		}
		TreeNode *ancestor = root;
		while (ancestor)
		{
			/**
			 * 在左子树
			 */
			if (ancestor->val > p->val && ancestor->val > q->val)
			{
				ancestor = ancestor->left;
			}
			/**
			 * 在右子树
			 * 需要注意，必须要添加else，因为在上面已经将ancestor的值改变了，这可能导致错误
			 */
			else if (ancestor->val < p->val && ancestor->val < q->val)
			{
				ancestor = ancestor->right;
			}
			/**
			 * p 和 q 分别在两边，因此，当前节点就是公共节点
			 */
			else
			{
				break;
			}
		}
		return ancestor;
	}
};
```





### [236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/) 

最简单的二叉树

对于这两道题，我使用 labuladong [用 Git 来讲讲二叉树最近公共祖先](https://mp.weixin.qq.com/s/9RKzBcr3I592spAsuMH45g) 中给出的递归深度优先方式，都通过了。

```c++

class Solution
{
public:
	TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		if (root == p || root == q)
		{
			return root;
		}
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		/**
		 * 左右子树分别是目标节点
		 */
		if (left && right)
		{
			return root;
		}
		/**
		 * 左右子树都不包含目标节点
		 */
		if (left == nullptr && right == nullptr)
		{
			return nullptr;
		}
		/**
		 * 左右子树中只有一个包含目标节点
		 */
		return left == nullptr ? right : left;
	}
};
```

一、上述写法将寻找当个节点和寻找两个节点的逻辑混杂在了一起:

寻找当个节点:

```c++
		if (root == p || root == q)
		{
			return root;
		}
```

寻找两个节点:

```c++
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		/**
		 * 左右子树分别是目标节点
		 */
		if (left && right)
		{
			return root;
		}
		/**
		 * 左右子树都不包含目标节点
		 */
		if (left == nullptr && right == nullptr)
		{
			return nullptr;
		}
		/**
		 * 左右子树中只有一个包含目标节点
		 */
		return left == nullptr ? right : left;
```

二、上述写法的前提是: p 和 q 都在树中



### [1644. 二叉树的最近公共祖先 II](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/) 中等





### [1650. 二叉树的最近公共祖先 III](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/) 中等

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

