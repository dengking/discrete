# [LeetCode-545. 二叉树的边界](https://leetcode.cn/problems/boundary-of-binary-tree/) 中等

二叉树的 **边界** 是由 **根节点** 、**左边界** 、按从左到右顺序的 **叶节点** 和 **逆序的右边界** ，按顺序依次连接组成。

**左边界** 是满足下述定义的节点集合：

- 根节点的左子节点在左边界中。如果根节点不含左子节点，那么左边界就为 **空** 。

- 如果一个节点在左边界中，并且该节点有左子节点，那么它的左子节点也在左边界中。

- 如果一个节点在左边界中，并且该节点 **不含** 左子节点，那么它的右子节点就在左边界中。

- 最左侧的叶节点 **不在** 左边界中。

**右边界** 定义方式与 **左边界** 相同，只是将左替换成右。即，右边界是根节点右子树的右侧部分；叶节点 **不是** 右边界的组成部分；如果根节点不含右子节点，那么右边界为 **空** 。

**叶节点** 是没有任何子节点的节点。对于此问题，根节点 **不是** 叶节点。

给你一棵二叉树的根节点 `root` ，按顺序返回组成二叉树 **边界** 的这些值。

## **示例 1：**

![img](https://assets.leetcode.com/uploads/2020/11/11/boundary1.jpg)

```
输入：root = [1,null,2,3,4]
输出：[1,3,4,2]
解释：
- 左边界为空，因为二叉树不含左子节点。
- 右边界是 [2] 。从根节点的右子节点开始的路径为 2 -> 4 ，但 4 是叶节点，所以右边界只有 2 。
- 叶节点从左到右是 [3,4] 。
按题目要求依序连接得到结果 [1] + [] + [3,4] + [2] = [1,3,4,2] 。

```

## **示例 2：**

![img](https://assets.leetcode.com/uploads/2020/11/11/boundary2.jpg)

```
输入：root = [1,2,3,4,5,6,null,null,null,7,8,9,10]
输出：[1,2,4,7,8,9,10,6,3]
解释：
- 左边界为 [2] 。从根节点的左子节点开始的路径为 2 -> 4 ，但 4 是叶节点，所以左边界只有 2 。
- 右边界是 [3,6] ，逆序为 [6,3] 。从根节点的右子节点开始的路径为 3 -> 6 -> 10 ，但 10 是叶节点。
- 叶节点从左到右是 [4,7,8,9,10]
按题目要求依序连接得到结果 [1] + [2] + [4,7,8,9,10] + [6,3] = [1,2,4,7,8,9,10,6,3] 。


```

## [官方解题 # 方法 1：简单解法](https://leetcode.cn/problems/boundary-of-binary-tree/solution/er-cha-shu-de-bian-jie-by-leetcode/)



```C++
class Solution {
	bool isLeaf(TreeNode* root) {
		return root->left == nullptr && root->right == nullptr;
	}
	void addLeaves(vector<int>& boundary, TreeNode* root) {
		if (isLeaf(root)) {
			boundary.push_back(root->val);
		}
		if (root->left) {
			addLeaves(boundary, root->left);
		}
		if (root->right) {
			addLeaves(boundary, root->right);
		}
	}
	void addLeft(vector<int>& boundary, TreeNode* root) {
		TreeNode* t = root->left; // 首先取root 的leaf node
		while (t)
		{
			if (isLeaf(t)) { // 到达了终点
				break;
			}
			else {
				boundary.push_back(t->val);
				if (t->left) {
					t = t->left;
				}
				else {
					t = t->right;
				}
			}
		}
	}
	void addRight(vector<int>& boundary, TreeNode* root) {
		stack<int> stk;
		TreeNode* t = root->right;
		while (t)
		{
			if (isLeaf(t)) { // 到达了终点
				break;
			}
			else {
				stk.push(t->val);
				if (t->right) {
					t = t->right;
				}
				else {
					t = t->left;
				}
			}
		}
		while (!stk.empty()) {
			boundary.push_back(stk.top());
			stk.pop();
		}
	}
public:
	vector<int> boundaryOfBinaryTree(TreeNode* root) {
		vector<int> boundary;
		if (root) {
			boundary.push_back(root->val);
			if (!isLeaf(root)) {
				addLeft(boundary, root);
				addLeaves(boundary, root);
				addRight(boundary, root);
			}

			return boundary;
		}
		else {
			return boundary;
		}
	}
};

```

> NOTE: 
>
> 需要注意：仅仅遍历左边界和遍历整棵树的方式是不同的



## [官方解题 # 方法 2：先序遍历](https://leetcode.cn/problems/boundary-of-binary-tree/solution/er-cha-shu-de-bian-jie-by-leetcode/)