# [LeetCode-108. Convert Sorted Array to Binary Search Tree-Easy](https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/)



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
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode *sortedArrayToBST(vector<int> &nums, int lo, int hi) {
        if (lo > hi) {
            return nullptr;
        } else if (lo == hi) {
            return new TreeNode(nums[lo]);
        } else {
            int mid = lo + (hi - lo) / 2;
            TreeNode *root = new TreeNode(nums[mid]);
            root->left = sortedArrayToBST(nums, lo, mid - 1);
            root->right = sortedArrayToBST(nums, mid + 1, hi);
            return root;
        }
    }
};

```

