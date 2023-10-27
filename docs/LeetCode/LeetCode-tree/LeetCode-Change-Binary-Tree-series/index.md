# LeetCode-Change-Binary-Tree-series



## [LeetCode-156. Binary Tree Upside Down-plus-Middle](https://leetcode.cn/problems/binary-tree-upside-down/) 

```c++

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *upsideDownBinaryTree(TreeNode *root) {
        TreeNode *newRoot = root->left;
        newRoot->left = root->right;
        newRoot->right = root;

        upsideDownBinaryTree(root->left);
        upsideDownBinaryTree(root->right);
    }
};
```



## [LeetCode-226. 翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/)



### 我的解题

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



#### labuladong [东哥手把手带你套框架刷通二叉树|第一期](https://mp.weixin.qq.com/s/izZ5uiWzTagagJec6Y7RvQ) 

在其中，使用了pre-order的方式来解决的。





## [LeetCode-剑指 Offer 27. 二叉树的镜像](https://leetcode.cn/problems/er-cha-shu-de-jing-xiang-lcof/)



