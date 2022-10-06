# [LeetCode-654. 最大二叉树](https://leetcode.cn/problems/maximum-binary-tree/) 中等



## 我的解题

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
class Solution {
public:
    /**
	 * @brief 左闭右闭
	 *
	 * @param nums
	 * @param left
	 * @param right
	 * @return
	 */
	int max_index(vector<int> &nums, int left, int right)
	{
		int max_i = left;
		for (int i = left + 1; i <= right; ++i)
		{
			if (nums[i] > nums[max_i])
			{
				max_i = i;
			}
		}
		return max_i;
	}
	TreeNode* constructMaximumBinaryTree(vector<int> &nums)
	{
		return constructMaximumBinaryTree(nums, 0, nums.size() - 1);

	}
	TreeNode* constructMaximumBinaryTree(vector<int> &nums, int left, int right)
	{
		if (left <= right)
		{
			int max_i = max_index(nums, left, right);
			TreeNode *root = new TreeNode { nums[max_i] };
			root->left = constructMaximumBinaryTree(nums, left, max_i - 1);
			root->right = constructMaximumBinaryTree(nums, max_i + 1, right);
			return root;
		}
		else
		{
			return nullptr;
		}
	}
};
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

