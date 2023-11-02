# [LeetCode-1373. 二叉搜索子树的最大键值和](https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/)

是在阅读labuladong [美团面试官：你对二叉树后续遍历一无所知](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247490891&idx=1&sn=677a7e887fa551e994ba73bcb2538cea&scene=21#wechat_redirect) 时遇到的这道题。

## 一刷

```c++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
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
  int max_{0};

public:
  int maxSumBST(TreeNode *root)
  {
    dfs(root);
    return max_;
  }
  /**
   * @brief
   *
   * @param root
   * @return std::tuple<bool, int, int, int> 是否是bst、键值之和、最小值、最大值
   */
  std::vector<int> dfs(TreeNode *root)
  {
    if (root)
    {
      if (root->left && root->right)
      {
        auto left = dfs(root->left);
        auto right = dfs(root->right);

        if (left[0] && right[0] &&                                //
            root->val > root->left->val && root->val > left[3] && //
            root->val < root->right->val && root->val < right[2]  //
        )
        {
          auto sum = left[1] + right[1] + root->val;
          max_ = max(max_, sum);
          return {true, sum, left[2], right[3]};
        }
        else
        {
          return {false, 0, 0, 0};
        }
      }
      else if (root->left == nullptr && root->right == nullptr) // 叶子节点
      {
        max_ = max(max_, root->val);
        return {true, root->val, root->val, root->val};
      }
      else if (root->left)
      {
        auto left = dfs(root->left);
        if (left[0] &&                                         //
            root->val > root->left->val && root->val > left[3] //
        )
        {
          auto sum = left[1] + root->val;
          max_ = max(max_, sum);
          return {true, sum, left[2], root->val};
        }
        else
        {
          return {false, 0, 0, 0};
        }
      }
      else
      {
        auto right = dfs(root->right);
        if (right[0] &&                                          //
            root->val < root->right->val && root->val < right[2] //
        )
        {
          auto sum = right[1] + root->val;
          max_ = max(max_, sum);
          return {true, sum, root->val, right[3]};
        }
        else
        {
          return {false, 0, 0, 0};
        }
      }
    }
    else
    {
      return {false, 0, 0, 0};
    }
  }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



## 二刷

通过给null pointer一个

```C++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
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
  int max_{0};

public:
  int maxSumBST(TreeNode *root)
  {
    dfs(root);
    return max_;
  }
  /**
   * @brief
   *
   * @param root
   * @return std::tuple<bool, int, int, int> 是否是bst、键值之和、最小值、最大值
   */
  std::vector<int> dfs(TreeNode *root)
  {
    if (root)
    {

      auto left = dfs(root->left);
      auto right = dfs(root->right);

      if (left[0] && right[0] && // 左右都是BST
          root->val > left[3] && // 大于左边最大的
          root->val < right[2]   // 小于右边最小的
      )
      {
        auto sum = left[1] + right[1] + root->val;
        max_ = max(max_, sum);
        return {
            true,
            sum,
            min(left[2], root->val), // 最小值
            max(right[3], root->val) // 最大值
        };
      }
      else
      {
        return {false, 0, 0, 0};
      }
    }
    else
    {
      return {true, 0, INT_MAX, INT_MIN};
    }
  }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

