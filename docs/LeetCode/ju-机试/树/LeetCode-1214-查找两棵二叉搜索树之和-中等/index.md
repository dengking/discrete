# LeetCode [1214. 查找两棵二叉搜索树之和](https://leetcode-cn.com/problems/two-sum-bsts/) 中等

## 我的解题



```C++
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
		bool exist = false;
		in_order_traverse(root1, root2, target, exist);
		return exist;
	}
	void in_order_traverse(TreeNode* node1, TreeNode* root2, int target, bool& exist) {
		if (node1) {
			int v = target - node1->val;
			TreeNode* node2 = binary_search(root2, v);
			if (node2) {
				exist = true;
				return;
			}
			else {
				in_order_traverse(node1->left, root2, target, exist);
				in_order_traverse(node1->right, root2, target, exist);
			}
		}
	}
	TreeNode* binary_search(TreeNode* node, int target) {
		if (node) {
			if (node->val == target) {
				return node;
			}
			else if (node->val > target) {
				return binary_search(node->left, target);
			}
			else {
				return binary_search(node->right, target);
			}
		}
		else {
			return nullptr;
		}
	}
};

int main()
{
	Solution s;

}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

