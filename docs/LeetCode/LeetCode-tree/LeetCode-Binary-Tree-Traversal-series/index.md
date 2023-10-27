# LeetCode-Binary-Tree-Traversal



## [LeetCode-144. Binary Tree Preorder Traversal-Easy](https://leetcode.cn/problems/binary-tree-preorder-traversal/)



```c++
#include <vector>

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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

public:
    void dfs(TreeNode *root, vector<int> &ans) {
        if (root == nullptr)return;
        ans.push_back(root->val);
        dfs(root->left, ans);
        dfs(root->right, ans);
    }
};
```



## [LeetCode-145. Binary Tree Postorder Traversal-Easy](https://leetcode.cn/problems/binary-tree-postorder-traversal/)



```c++
#include <vector>

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

public:
    void dfs(TreeNode *root, vector<int> &ans) {
        if (root == nullptr)return;
        dfs(root->left, ans);
        dfs(root->right, ans);
        ans.push_back(root->val);
    }
};
```

