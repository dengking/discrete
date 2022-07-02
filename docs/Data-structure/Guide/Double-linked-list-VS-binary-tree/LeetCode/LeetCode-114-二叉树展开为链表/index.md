# leetcode [114. 二叉树展开为链表](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/)



## 我的解题

一、主要是考察先序遍历。

二、采用"linked list dummy node-技巧-append to tail create创建linked list"，因此需要使用成员变量`tail`来记录当前linked list的tail node。



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
	TreeNode tail_node;
	TreeNode *tail { &tail_node };

public:
	/**
	 * @brief
	 *
	 * @param root
	 * @param tail 链表的尾
	 */
	void flatten(TreeNode *root)
	{
		if (root)
		{
			tail->left = nullptr;
			tail->right = root;
			tail = root;
			/**
			 * 需要注意的是: 不能够使用下面的这种写法:
			 * flatten(root->left);
			 * flatten(root->right);
			 *
			 * 因为，在前执行了 `tail = root;`，而在函数中，是会对 `tail`的 `left`成员、`right`成员进行修改的
			 * 那么这就导致 `flatten(root->right);` 中的`root->right`读取的是一个修改后的值，而导致程序错误
			 */
			TreeNode *left = root->left;
			TreeNode *right = root->right;
			flatten(left);
			flatten(right);
		}
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
	s.flatten(&n1);
}

```

