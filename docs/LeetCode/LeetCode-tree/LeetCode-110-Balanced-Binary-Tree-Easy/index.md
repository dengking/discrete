# [LeetCode-110. Balanced Binary Tree-Easy](https://leetcode.cn/problems/balanced-binary-tree/)



```c++
#include <algorithm>

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode() : val(0), left(nullptr), right(nullptr) {}

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
	bool isBalanced(TreeNode *root)
	{
		if (root)
		{
			return isBalanced(root->left) &&
				   isBalanced(root->right) &&
				   std::abs(treeHeight(root->left) - treeHeight(root->right)) <= 1;
		}
		else
		{
			return true;
		}
	}

private:
	int treeHeight(TreeNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		return 1 + std::max(treeHeight(root->left), treeHeight(root->right));
	}
};
```

