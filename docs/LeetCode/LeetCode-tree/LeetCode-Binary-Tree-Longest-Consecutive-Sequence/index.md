# LeetCode-Binary-Tree-Longest-Consecutive-Sequence



## [LeetCode-298. Binary Tree Longest Consecutive Sequence-Plus-Middle](https://leetcode.cn/problems/binary-tree-longest-consecutive-sequence/)



给你一棵指定的二叉树的根节点 `root` ，请你计算其中 **最长连续序列路径** 的长度。

**最长连续序列路径** 是依次递增 1 的路径。该路径，可以是从某个初始节点到树中任意节点，通过「父 - 子」关系连接而产生的任意路径。且必须从父节点到子节点，反过来是不可以的。



```c++
#include<vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int ans_{0};
public:
    int longestConsecutive(TreeNode *root) {
        dfs(root);
        return ans_;
    }

private:
    std::vector<int> dfs(TreeNode *root) {
        if (root == nullptr) {
            return {0, 0};
        }
        if (!root->left && !root->right) {
            ans_ = max(ans_, 1);
            return {1, 1};
        }
        int leftCnt = 1; // 当前节点本身就是一个
        if (root->left) {
            auto leftCntInfo = dfs(root->left);
            if ((root->val - root->left->val) == -1) {
                leftCnt = *max_element(leftCntInfo.begin(), leftCntInfo.end()) + 1;
                ans_ = max(ans_, leftCnt);
            }
        }
        int rightCnt = 1; // 当前节点本身就是一个
        if (root->right) {
            auto rightCntInfo = dfs(root->right);
            if ((root->val - root->right->val) == -1) {
                rightCnt = *max_element(rightCntInfo.begin(), rightCntInfo.end()) + 1;
                ans_ = max(ans_, rightCnt);
            }
        }
        return {leftCnt, rightCnt};
    }
};
```



## [LeetCode-549. Binary Tree Longest Consecutive Sequence II-Middle](https://leetcode.cn/problems/binary-tree-longest-consecutive-sequence-ii/)



