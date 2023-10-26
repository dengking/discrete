# [LeetCode-103. Binary Tree Zigzag Level Order Traversal-middle](https://leetcode.cn/problems/binary-tree-zigzag-level-order-traversal/)



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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        std::queue<TreeNode *> q;
        if (root != nullptr) {
            q.push(root);
        }
        vector<vector<int>> ans;
        int rowIdx = 0;
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
            if (rowIdx % 2 == 0) {
                ans.emplace_back(std::move(level));
            } else {
                std::reverse(level.begin(), level.end());
                ans.emplace_back(std::move(level));
            }
            rowIdx++;
        }
        return ans;
    }
};

```

