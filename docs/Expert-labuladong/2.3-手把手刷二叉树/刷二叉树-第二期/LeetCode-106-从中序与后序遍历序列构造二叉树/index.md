# LeetCode [106. 从中序与后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) 中等

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
	TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
	{
		return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
	}
	TreeNode* buildTree(vector<int> &inorder, int inStart, int inEnd, vector<int> &postorder, int postStart, int postEnd)
	{
		if (postStart > postEnd)
		{
			return nullptr;
		}
		int rootVal = postorder[postEnd];
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
		root->left = buildTree(inorder, inStart, rootIndex - 1, postorder, postStart, postStart + leftSize - 1);
		root->right = buildTree(inorder, rootIndex + 1, inEnd, postorder, postStart + leftSize, postEnd - 1);
		return root;
	}
};

// Driver code
int main()
{

//	Solution solu;
//	vector<int> nums = { 1, 3, 5, 4, 7 };
//	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

