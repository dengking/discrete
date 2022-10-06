# [LeetCode-105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

## 我的解题

1、这道题本质是在考场recursion

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

//  Definition for a binary tree node.
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
	TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder)
	{
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
	TreeNode* buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd)
	{
		if (preStart > preEnd)
		{
			return nullptr;
		}
		int rootVal = preorder[preStart];
		TreeNode *root = new TreeNode { rootVal };
		int rootIndex = 0; // 中序遍历中，root的index
		for (int i = inStart; i <= inEnd; ++i)
		{

			if (inorder[i] == rootVal)
			{
				rootIndex = i;
				break;
			}
		}
		int leftSize = rootIndex - inStart; //左子树中，节点的个数
		root->left = buildTree(preorder, preStart + 1, preStart + leftSize, inorder, inStart, rootIndex - 1);
		root->right = buildTree(preorder, preStart + leftSize + 1, preEnd, inorder, rootIndex + 1, inEnd);
		return root;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// Driver code
int main()
{

//	Solution solu;
//	vector<int> nums = { 1, 3, 5, 4, 7 };
//	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

