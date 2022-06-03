# leetcode [235. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/)



## 我的解题

### 一次遍历

这是官方解题中，给出的算法，显然，它充分利用了BST的特性

```C++
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
					val(x), left(NULL), right(NULL)
	{
	}
};

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



### 递归DFS

可以使用 leetcode [235. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) 中的递归DFS方法



```C++
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
					val(x), left(NULL), right(NULL)
	{
	}
};
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

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

