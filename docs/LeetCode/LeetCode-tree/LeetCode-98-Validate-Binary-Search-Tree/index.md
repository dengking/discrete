# [LeetCode-98. Validate Binary Search Tree-middle](https://leetcode.cn/problems/validate-binary-search-tree/)



## DFS-pre-order错误解法

```c++

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
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        if (root->left && root->val <= root->left->val) {
            return false;
        }
        if (root->right && root->val >= root->right->val) {
            return false;
        }
        return isValidBST(root->left) && isValidBST(root->right);
    }
};
```





```
[5,4,6,null,null,3,7]
```



## DFS-post-order

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

struct TreeInfo {
    bool flag_{false};
    int min_{std::numeric_limits<int>::min()};
    int max_{std::numeric_limits<int>::max()};

    TreeInfo(bool flag) : flag_{flag} {}

    TreeInfo(bool flag, int min, int max) : flag_{flag}, min_{min}, max_{max} {}
};

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return postOrder(root).flag_;
    }

    TreeInfo postOrder(TreeNode *root) {
        int min_val = root->val;
        if (root->left) {
            TreeInfo left = postOrder(root->left);
            if (!left.flag_) {
                return TreeInfo(false);
            }
            if (root->val <= left.max_) {
                return {false};
            }
            min_val = left.min_;
        }
        int max_val = root->val;
        if (root->right) {
            TreeInfo right = postOrder(root->right);
            if (!right.flag_) {
                return TreeInfo(false);
            }
            if (root->val >= right.min_) {
                return {false};
            }
            max_val = right.max_;
        }
        return {true, min_val, max_val};
    }
};
```



## DFS-in-order


### Recursion

```C++
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
    long prev_val_{std::numeric_limits<long>::min()};

public:
    bool isValidBST(TreeNode *root)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (!isValidBST(root->left))
        {
            return false;
        }
        if (root->val <= prev_val_)
        {
            return false;
        }
        prev_val_ = root->val;
        return isValidBST(root->right);
    }
};

int main()
{
}
```



### Iteration
