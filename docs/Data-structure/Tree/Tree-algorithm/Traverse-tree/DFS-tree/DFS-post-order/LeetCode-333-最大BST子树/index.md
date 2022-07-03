# LeetCode [333. 最大 BST 子树](https://leetcode.cn/problems/largest-bst-subtree/)

> NOTE: 
>
> 是在阅读 geeksforgeeks [Maximum sub-tree sum in a Binary Tree such that the sub-tree is also a BST](https://www.geeksforgeeks.org/maximum-sub-tree-sum-in-a-binary-tree-such-that-the-sub-tree-is-also-a-bst/?ref=rp) 时，发现这个问题的，这篇文章已经收录于 



## 我的解题

是按照  geeksforgeeks [Maximum sub-tree sum in a Binary Tree such that the sub-tree is also a BST](https://www.geeksforgeeks.org/maximum-sub-tree-sum-in-a-binary-tree-such-that-the-sub-tree-is-also-a-bst/?ref=rp)  中的解法写的。

```C++
#include <bits/stdc++.h>
using namespace std;

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

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() :
					val(0), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x) :
					val(x), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x, TreeNode *left, TreeNode *right) :
					val(x), left(left), right(right)
	{
	}
};

// Information stored in every
// node during bottom up traversal
struct Info
{

	// Max Value in the subtree
	int max_val;

	// Min value in the subtree
	int min_val;

	// If subtree is BST
	bool isBST;

	// Sum of the nodes of the sub-tree
	// rooted under the current node
	int sum_of_node;

	// Max sum of BST found till now
	int currmax;
};

class Solution
{
public:
	int largestBSTSubtree(TreeNode *root)
	{
		int maxsum = INT_MIN;
		return MaxSumBSTUtil(root, maxsum).currmax;
	}
	// Returns information about subtree such as
	// subtree with maximum sum which is also a BST
	Info MaxSumBSTUtil(TreeNode *root, int &maxsum)
	{
		// Base case
		if (root == NULL)
			return
			{	INT_MIN, INT_MAX, true, 0, 0};

		// If current node is a leaf node then
		// return from the function and store
		// information about the leaf node
		if (root->left == NULL && root->right == NULL)
		{
			maxsum = max(maxsum, 1);
			return
			{	root->val, root->val, true, 1, maxsum};
		}

		// Store information about the left subtree
		Info L = MaxSumBSTUtil(root->left, maxsum);

		// Store information about the right subtree
		Info R = MaxSumBSTUtil(root->right, maxsum);

		Info BST;

		// If the subtree rooted under the current node
		// is a BST
		if (L.isBST && R.isBST && L.max_val < root->val && R.min_val > root->val)
		{

			BST.max_val = max(root->val, max(L.max_val, R.max_val));
			BST.min_val = min(root->val, min(L.min_val, R.min_val));
			BST.sum_of_node = R.sum_of_node + 1 + L.sum_of_node;
			maxsum = max(maxsum, BST.sum_of_node);

			// Update the current maximum sum_of_node
			BST.currmax = maxsum;

			BST.isBST = true;
			return BST;
		}
		else
		{
			// If the whole tree is not a BST then
			// update the current maximum sum_of_node
			BST.isBST = false;
			BST.currmax = maxsum;
			BST.sum_of_node = R.sum_of_node + 1 + L.sum_of_node;
			return BST;
		}
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```





