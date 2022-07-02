# LeetCode [222. 完全二叉树的节点个数](https://leetcode.cn/problems/count-complete-tree-nodes/) 中等

## 我的解题

### 递归

我是按照 labuladong [东哥手把手带你套框架刷通二叉树|第一期](https://mp.weixin.qq.com/s/izZ5uiWzTagagJec6Y7RvQ) 中给出的算法写的:

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
	int countNodes(TreeNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};

int main()
{
	TreeNode n1 { 1 };
	TreeNode n2 { 2 };
	TreeNode n3 { 3 };
	TreeNode n4 { 4 };
	TreeNode n5 { 5 };
	TreeNode n6 { 6 };
	n1.left = &n2;
	n1.right = &n5;
	n2.left = &n3;
	n2.right = &n4;
	n5.right = &n6;
	Solution s;
	s.countNodes(&n1);
}

```

