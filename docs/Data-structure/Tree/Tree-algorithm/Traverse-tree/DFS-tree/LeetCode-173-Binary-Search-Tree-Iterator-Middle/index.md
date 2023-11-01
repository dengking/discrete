# [LeetCode-173. 二叉搜索树迭代器-Middle](https://leetcode.cn/problems/binary-search-tree-iterator/)



```c++
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    std::stack<TreeNode *> st_;
    TreeNode *root_{nullptr};
public:
    BSTIterator(TreeNode *root) : root_{root} {

    }

    int next() {
        while (hasNext()) {
            if (root_) {
                st_.push(root_);
                root_ = root_->left;
            } else {
                TreeNode *top = st_.top();
                int ans = top->val;
                st_.pop();
                root_ = top->right;
                return ans;
            }
        }
        return 0;
    }

    bool hasNext() {
        return !st_.empty() || root_;
    }
};


```

