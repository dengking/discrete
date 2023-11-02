# [LeetCode-199. Binary Tree Right Side View-Middle](https://leetcode.cn/problems/binary-tree-right-side-view/)



```c++
#include<vector>
#include<queue>

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
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        std::queue<TreeNode *> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            int cnt = q.size();
            while (cnt--) {
                TreeNode *top = q.front();
                if (top->left) {
                    q.push(top->left);
                }
                if (top->right) {
                    q.push(top->right);
                }
                q.pop();
                if (cnt == 0) {
                    ans.push_back(top->val);
                }
            }
        }
        return ans;
    }
};

```

