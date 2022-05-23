# leetcode [236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)



## 我的解题

下面的code，是按照 labuladong [用 Git 来讲讲二叉树最近公共祖先](https://mp.weixin.qq.com/s/9RKzBcr3I592spAsuMH45g) 中的思路写出的。



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
		return left ? left : right;
	}
};

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

