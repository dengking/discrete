# [LeetCode-102. Binary Tree Level Order Traversal-middle](https://leetcode.cn/problems/binary-tree-level-order-traversal/) 



```c++
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        std::queue<TreeNode *> q;
        if (root)
        {
            q.push(root);
        }
        while (!q.empty())
        {
            /* code */
            int cnt = q.size();
            vector<int> level;
            level.reserve(cnt);
            while (cnt--)
            {
                TreeNode *node = q.front();
                /* code */
                level.push_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
                q.pop();
            }
            res.emplace_back(std::move(level));
        }
        return res;
    }
};

int main()
{
}
```

