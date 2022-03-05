# [426. 将二叉搜索树转化为排序的双向链表](https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/) 中等

将一个 二叉搜索树 就地转化为一个 已排序的双向循环链表 。

对于双向循环列表，你可以将左右孩子指针作为双向循环链表的前驱和后继指针，第一个节点的前驱是最后一个节点，最后一个节点的后继是第一个节点。

特别地，我们希望可以 就地 完成转换操作。当转化完成以后，树中节点的左指针需要指向前驱，树中节点的右指针需要指向后继。还需要返回链表中最小元素的指针。

## 示例 1：

输入：root = [4,2,5,1,3] 

![img](https://assets.leetcode.com/uploads/2018/10/12/bstdllreturndll.png)

输出：[1,2,3,4,5]

解释：下图显示了转化后的二叉搜索树，实线表示后继关系，虚线表示前驱关系。

![img](https://assets.leetcode.com/uploads/2018/10/12/bstdllreturnbst.png)



## 示例 2：

输入：root = [2,1,3]

输出：[1,2,3]

## 示例 3：

输入：root = []
输出：[]
解释：输入是空树，所以输出也是空链表。

## 示例 4：

输入：root = [1]
输出：[1]

## 我的解题

思路非常简单: 进行中序遍历，通过 `last_`  指针进行node指针排序

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
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node() {}

	Node(int _val) {
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node* _left, Node* _right) {
		val = _val;
		left = _left;
		right = _right;
	}
};

class Solution {
	Node* head_{nullptr};
	Node* last_{ nullptr };
public:
	Node* treeToDoublyList(Node* root) {
		if (root) {
			dfs(root);
			head_->left = last_; // 显然最终last_指向最右侧节点
			last_->right = head_;
		}
		return head_;
	}
	void dfs(Node* node) {
		if (node) {
			dfs(node->left);
			node->left = last_;
			if (last_) {
				last_->right = node;
			}
			else { // 第一次访问的肯定是head
				head_ = node;
			}
			last_ = node;
			dfs(node->right);
		}
	}
};


int main()
{
	Solution s;
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

