# [314. 二叉树的垂直遍历](https://leetcode-cn.com/problems/binary-tree-vertical-order-traversal/) 中等



## 我的解题

### 第一次提交

````c++
#include <iostream>
#include <vector>
#include <utility> // std::pair
#include <unordered_map>
#include <string>
#include <map>
#include <climits> // INT_MAX
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
  int max_x_{INT_MIN};
  int max_y_{INT_MIN};
  map<int, map<int, vector<TreeNode *> >, std::greater<int> > x2nodes_; // x 是从小到大，
                                                                        // y是从大到小

public:
  vector<vector<int> > verticalOrder(TreeNode *root)
  {
    dfs(root, 0, 0);
    vector<vector<int> > res;
    for (auto &&xnodes : x2nodes_)
    {
      res.push_back(vector<int>());
      for (auto &&ynodes : xnodes.second)
      {
        for (auto &&n : ynodes.second)
          res.back().push_back(n->val);
      }
    }
    return res;
  }
  void dfs(TreeNode *node, int x, int y)
  {
    if (node)
    {
      x2nodes_[x][y].push_back(node);
      dfs(node->left, x + 1, y + 1);
      dfs(node->left, x - 1, y + 1);
    }
  }
};

int main()
{
}

````



### 第二次提交

```c++
#include <iostream>
#include <vector>
#include <utility> // std::pair
#include <unordered_map>
#include <string>
#include <map>
#include <climits> // INT_MAX
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
  int max_x_{INT_MIN};
  int max_y_{INT_MIN};
  map<int, map<int, vector<int> >, std::greater<int> > x2nodes_; // x 是从小到大，
                                                                        // y是从大到小

public:
  vector<vector<int> > verticalOrder(TreeNode *root)
  {
    dfs(root, 0, 0);
    vector<vector<int> > res;
    for (auto &&xnodes : x2nodes_)
    {
      res.push_back(vector<int>());
      for (auto &&ynodes : xnodes.second)
      {
        for (auto &&val : ynodes.second)
          res.back().push_back(val);
      }
    }
    return res;
  }
  void dfs(TreeNode *node, int x, int y)
  {
    if (node)
    {
      x2nodes_[x][y].push_back(node->val);
      dfs(node->left, x + 1, y + 1);
      dfs(node->right, x - 1, y + 1);
    }
  }
};



int main()
{
}

```



### 第三次提交

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
  /**
   * @brief width、depth
   *
   * @param root
   * @return vector<vector<int>>
   */
  vector<vector<int>> verticalOrder(TreeNode *root)
  {
    map<int, map<int, vector<int>>> states;
    dfs(root, 0, 0, states);
    vector<vector<int>> res;

    for (auto &&col : states)
    {
      res.push_back({});                        // 插入一个空vector，这种写法更加简洁
      for (auto &&[first, second] : col.second) // 使用c++17 struct binding
      {
        std::copy(second.begin(), second.end(), std::back_inserter(res.back())); // 使用algorithm
      }
    }
    return res;
  }
  void dfs(TreeNode *root, int depth, int width, map<int, map<int, vector<int>>> &states)
  {
    if (root)
    {
      states[width][depth].push_back(root->val);
      dfs(root->left, depth + 1, width - 1, states);
      dfs(root->right, depth + 1, width + 1, states);
    }
  }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

