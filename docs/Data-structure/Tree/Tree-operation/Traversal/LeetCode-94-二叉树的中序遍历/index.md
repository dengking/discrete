# leetcode [94. 二叉树的中序遍历](https://leetcode-cn.com/problems/binary-tree-inorder-traversal/)



## 我的解题

### 递归

```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
	vector<int> inorderTraversal(TreeNode *root)
	{
		vector<int> res;
		inorderTraversal(root, res);
		return res;
	}
	void inorderTraversal(TreeNode *root, vector<int> &res)
	{
		if (root)
		{
			inorderTraversal(root->left, res);
			res.push_back(root->val);
			inorderTraversal(root->right, res);
		}
		else
		{
			return;
		}
	}
};
int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

### 非递归

