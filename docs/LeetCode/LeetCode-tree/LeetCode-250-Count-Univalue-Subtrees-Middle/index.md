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
public:
    int countUnivalSubtrees(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        if (!root->left && !root->right) { // leaf node
            return 1;
        }
        return countUnivalSubtreesImpl(root->left) + countUnivalSubtreesImpl(root->right);
    }

public:
    int countUnivalSubtreesImpl(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        if (!root->left && !root->right) { // leaf node
            return 1;
        }
        int leftCnt = countUnivalSubtrees(root->left);
        int rightCnt = countUnivalSubtrees(root->right);;
        if (root->left && root->left->val == root->val) {

            ++leftCnt;
        }
        if (root->right && root->right->val == root->val) {
            ++rightCnt;
        }
        return leftCnt + rightCnt;
    }
};


```

