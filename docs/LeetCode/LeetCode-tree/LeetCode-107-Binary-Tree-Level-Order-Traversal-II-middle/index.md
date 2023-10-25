# [LeetCode-107. Binary Tree Level Order Traversal II-Middle](https://leetcode.cn/problems/binary-tree-level-order-traversal-ii/)



```c++
#include <vector>
#include <queue>

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
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        std::queue<TreeNode *> q;
        if (root != nullptr) {
            q.push(root);
        }
        vector<vector<int>> ans;
        while (!q.empty()) {
            int cnt = q.size();
            std::vector<int> level;
            level.reserve(cnt);
            while (cnt--) {
                TreeNode *node = q.front();
                level.push_back(node->val);

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                q.pop();
            }
            ans.emplace_back(std::move(level));
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};

```

