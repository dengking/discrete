# leetcode [226. 翻转二叉树](https://leetcode-cn.com/problems/invert-binary-tree/)



## 我的解题

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
	TreeNode* invertTree(TreeNode *root)
	{
		if (!root)
		{
			return root;
		}
		TreeNode *left = invertTree(root->left);
		TreeNode *right = invertTree(root->right);
		root->right = left;
		root->left = right;
		return root;
	}
};

```

