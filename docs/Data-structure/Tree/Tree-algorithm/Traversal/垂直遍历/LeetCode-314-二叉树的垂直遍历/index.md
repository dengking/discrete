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



