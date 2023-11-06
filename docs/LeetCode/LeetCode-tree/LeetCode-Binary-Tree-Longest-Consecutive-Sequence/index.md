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



给定二叉树的根 `root` ，返回树中**最长连续路径**的长度。
**连续路径**是路径中相邻节点的值相差 `1` 的路径。此路径可以是增加或减少。

- 例如， `[1,2,3,4]` 和 `[4,3,2,1]` 都被认为有效，但路径 `[1,2,4,3]` 无效。

另一方面，路径可以是子-父-子顺序，不一定是父子顺序。



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

struct TreeNodeSequenceInfo {
    int left1 = 0; // 左边，公差为1
    int leftNeg1 = 0; // 左边，公差为-1
    int right1 = 0; // 右边，公差为1
    int rightNeg1 = 0;// 右边，公差为-1
};

class Solution {
    int ans_{0};
public:
    int longestConsecutive(TreeNode *root) {
        dfs(root);
        return ans_;
    }

private:
    TreeNodeSequenceInfo dfs(TreeNode *root) {
        if (root == nullptr) {
            return {0, 0, 0, 0};
        }
        if (!root->left && !root->right) {
            ans_ = max(ans_, 1);
            return {1, 1, 1, 1};
        }
        int left1 = 1; // 当前节点本身就是一个
        int leftNeg1 = 1; // 当前节点本身就是一个
        if (root->left) {
            auto leftCntInfo = dfs(root->left);
            if ((root->val - root->left->val) == 1) {
                left1 = max(leftCntInfo.left1, leftCntInfo.right1) + 1;
            }
            if ((root->val - root->left->val) == -1) {
                leftNeg1 = max(leftCntInfo.leftNeg1, leftCntInfo.rightNeg1) + 1;
            }
        }
        int right1 = 1; // 当前节点本身就是一个
        int rightNeg1 = 1; // 当前节点本身就是一个
        if (root->right) {
            auto rightCntInfo = dfs(root->right);
            if ((root->val - root->right->val) == 1) {
                right1 = max(rightCntInfo.right1, rightCntInfo.left1) + 1;
            }
            if ((root->val - root->right->val) == -1) {
                rightNeg1 = max(rightCntInfo.rightNeg1, rightCntInfo.leftNeg1) + 1;
            }
        }
        ans_ = max({ans_, left1, leftNeg1, right1, rightNeg1});
        if (left1 != 1 && rightNeg1 != 1) {
            ans_ = max({ans_, left1, leftNeg1, right1, rightNeg1, left1 + rightNeg1 - 1});
        }
        if (leftNeg1 != 1 && right1 != 1) {
            ans_ = max({ans_, left1, leftNeg1, right1, rightNeg1, leftNeg1 + right1 - 1});
        }
        return {left1, leftNeg1, right1, rightNeg1};
    }
};
```

