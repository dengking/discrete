# [LeetCode-113. Path Sum II-middle](https://leetcode.cn/problems/path-sum-ii/)



## DFS+backtrack

```c++
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    vector<vector<int>> result;
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<int> path;
        dfs(root, targetSum, path);
        return result;
    }

private:
    void dfs(TreeNode *root, int targetSum, vector<int> &path) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == targetSum) {
                result.push_back(path);
            }
        } else {
            dfs(root->left, targetSum - root->val, path);
            dfs(root->right, targetSum - root->val, path);
        }
        path.pop_back();
    }
};

// Driver code
int main() {

    Solution s;

    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

