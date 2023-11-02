# [LeetCode-250. Count Univalue Subtrees-Middle](https://leetcode.cn/problems/count-univalue-subtrees/)



```c++
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
    int cnt_{0};
public:
    int countUnivalSubtrees(TreeNode *root) {
        countUnivalSubtreesImpl(root);
        return cnt_;
    }

private:
    bool countUnivalSubtreesImpl(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        if (!root->left && !root->right) { // leaf node
            ++cnt_;
            return true;
        }
        bool isLeftSubtreeUnival = countUnivalSubtreesImpl(root->left);
        bool isRightSubtreeUnival = countUnivalSubtreesImpl(root->right);
        if (root->left && !root->right) { // 只有左子树
            if (root->left->val == root->val && isLeftSubtreeUnival) {
                ++cnt_;
                return true;
            } else {
                return false;
            }
        }
        if (!root->left && root->right) { // 只有右子树
            if (root->right->val == root->val && isRightSubtreeUnival) {
                ++cnt_;
                return true;
            } else {
                return false;
            }
        }
        if (root->left && root->right) {
            if (root->left->val == root->val && root->right->val == root->val
                && isLeftSubtreeUnival && isRightSubtreeUnival) {
                ++cnt_;
                return true;
            } else {
                return false;
            }
        }
        return false;
    }
};


```

