# [LeetCode-257. Binary Tree Paths-Easy](https://leetcode.cn/problems/binary-tree-paths/)





```c++
#include<vector>
#include<string>

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
    vector<string> ans_;
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        std::string path;
        binaryTreePaths(root, path);
        return ans_;
    }

    void binaryTreePaths(TreeNode *root, string path) {
        if (root == nullptr) {
            return;
        }
        if (!root->left && !root->right) {
            path += std::to_string(root->val);
            ans_.push_back(path);
        } else {
            path += std::to_string(root->val) + "->";
            binaryTreePaths(root->left, path);
            binaryTreePaths(root->right, path);
        }
    }
};

```

