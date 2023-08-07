# [LeetCode-437. Path Sum III-middle](https://leetcode.cn/problems/path-sum-iii/)



## 错误

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
public:
    int pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return 0;
        }

        int result = 0;
        if (root->val == targetSum) {
            result += 1; // 选择当前节点，则到此为止了
            // 不选择当前节点，分别到left、right中去尝试
            result += pathSum(root->left, targetSum);
            result += pathSum(root->right, targetSum);
            return result;
        } else {
            return pathSum(root->left, targetSum) + // 不包含当前节点
                   pathSum(root->left, targetSum - root->val) + // 包含当前节点
                   pathSum(root->right, targetSum) +
                   pathSum(root->right, targetSum - root->val);
        }
    }
};

// Driver code
int main() {

    Solution s;

    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

