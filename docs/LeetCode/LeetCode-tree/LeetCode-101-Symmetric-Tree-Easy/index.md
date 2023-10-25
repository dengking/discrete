# [LeetCode-101. Symmetric Tree-Easy](https://leetcode.cn/problems/symmetric-tree/)



```c++
#include <queue>
#include <stack>
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
    bool isSymmetric(TreeNode *root)
    {
        return isSymmetric(root, root);
    }
    /// @brief root1和root2始终位于同一层
    /// @param root1
    /// @param root2
    /// @return
    bool isSymmetric(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2) // 两者都为nullptr
        {
            return true;
        }
        if (!root1 || !root2) // 两者中的一个为nullptr
        {
            return false;
        }
        return root1->val == root2->val && isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }
};

int main()
{
}
```

