# [LeetCode-99. 恢复二叉搜索树](https://leetcode.cn/problems/recover-binary-search-tree/)

阅读 labuladong [原创 | 手把手刷二叉搜索树（第二期）](https://mp.weixin.qq.com/s/SuGAvV9zOi4viaeyjWhzDw) 时发现的这道题。



## [官方解题](https://leetcode.cn/problems/recover-binary-search-tree/solution/hui-fu-er-cha-sou-suo-shu-by-leetcode-solution/)

我们来看下如果在一个递增的序列中交换两个值会造成什么影响。假设有一个递增序列 $a=[1,2,3,4,5,6,7]$。

如果我们交换两个不相邻的数字，例如 22 和 66，原序列变成了 $a=[1,6,3,4,5,2,7]$，那么显然序列中有两个位置不满足 $a_i < a_{i+1}$，在这个序列中体现为$6>3, 5>2$，因此只要我们找到这两个位置，即可找到被错误交换的两个节点。

如果我们交换两个相邻的数字，例如 $2$ 和 $3$，此时交换后的序列只有一个位置不满足 $a_i < a_{i+1}$。

因此整个值序列中不满足条件的位置或者有两个，或者有一个。

```c++
    pair<int,int> findTwoSwapped(vector<int>& nums) {
        int n = nums.size();
        int x = -1, y = -1;
        for(int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] < nums[i]) {
                y = nums[i + 1];
                if (x == -1) {
                    x = nums[i];
                }
                else break;
            }
        }
        return {x, y};
    }

```

上面这个函数就是用于寻找两个被交换位置的元素的，它的实现是比较精妙的；它能够处理前面描述的两种情况:

1、相邻两个元素被交换

2、非相邻的两个元素被交换

`x`为第一个元素、`y`为第二个元素；



## 我的解题

### 方法一：显式中序遍历

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
	void recoverTree(TreeNode *root)
	{
		vector<int> nums;
		inOrder(root, nums);
		auto xy = findSwapper(nums);
		int x = xy.first;
		int y = xy.second;
		recover(root, 2, x, y);

	}
	void inOrder(TreeNode *root, vector<int> &nums)
	{
		if (root)
		{
			inOrder(root->left, nums);
			nums.push_back(root->val);
			inOrder(root->right, nums);
		}
		else
		{
			return;
		}
	}
	/**
	 * @brief 寻找被交换了位置的两个元素
	 *
	 * @param nums
	 * @return
	 */
	pair<int, int> findSwapper(vector<int> &nums)
	{
		int x;
		int y;
		bool findX = false; // 因为题目的要求是Node.val可以为负数，因此不能够通过x的值来判断是否找到了x，所以需要有一个特殊的标准来判断是否找到了x
		for (int i = 0; i < nums.size() - 1; ++i)
		{
			if (nums[i + 1] < nums[i])
			{
				y = nums[i + 1];
				if (!findX)
				{
					x = nums[i];
					findX = true;
				}
				else
				{
					break;
				}
			}
		}
		return
		{	x, y};
	}
	/**
	 * @brief 先序遍历树
	 *
	 * @param root
	 * @param count
	 * @param x
	 * @param y
	 */
	void recover(TreeNode *root, int count, int x, int y)
	{
		if (root)
		{
			if (root->val == x || root->val == y)
			{
				root->val = root->val == x ? y : x;
				if (--count == 0) // 不用继续往下递归了
				{
					return;
				}
			}
			recover(root->left, count, x, y);
			recover(root->right, count, x, y);
		}
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

### 方法二：隐式中序遍历

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
	TreeNode *prev { nullptr }; // 前一个被访问的节点
	TreeNode *x { nullptr };
	TreeNode *y { nullptr };
public:
	void recoverTree(TreeNode *root)
	{
		inOrder(root);
		swap(x->val, y->val);
	}
	void inOrder(TreeNode *root)
	{
		if (root)
		{
			inOrder(root->left);
			if (prev && (prev->val > root->val))
			{
				y = root;
				if (!x)
				{
					x = prev;
				}
				else
				{
					return;
				}
			}
			prev = root;
			inOrder(root->right);
		}
		else
		{
			return;
		}
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

