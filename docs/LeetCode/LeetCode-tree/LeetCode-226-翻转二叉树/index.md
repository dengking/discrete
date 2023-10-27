# [LeetCode-226. 翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/)



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



### labuladong [东哥手把手带你套框架刷通二叉树|第一期](https://mp.weixin.qq.com/s/izZ5uiWzTagagJec6Y7RvQ) 

在其中，使用了pre-order的方式来解决的。
