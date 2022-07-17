# [LeetCode-104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)



## 我的解题

### BFS

这是按照如下文章中的内容写的:

1、labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g)

2、labuladong [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect)



#### 完整代码

```c++
// #include <bits/ne_stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <set>
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
#include <memory>

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
  int maxDepth(TreeNode *root)
  {
    std::queue<TreeNode *> q;
    if (root)
      q.push(root);
    int depth = 0;
    while (!q.empty())
    {
      ++depth;
      auto sz = q.size();
      for (int i = 0; i < sz; i++)
      {
        auto *node = q.front();
        if (node->left)
        {
          q.push(node->left);
        }
        if (node->right)
        {
          q.push(node->right);
        }
        q.pop();
      }
    }
    return depth;
  }
};

int main()
{
}
// g++ test.cpp --ne_std=c++11 -pedantic -Wall -Wextra

```



### DFS

recursion公式: 

```c++
depth(node) = max(depth(node->left), depth(node->right)) + 1
```

base case: 空节点的高度为0

#### 完整代码

```c++
// #include <bits/ne_stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <set>
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
#include <memory>

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
  int maxDepth(TreeNode *root)
  {
    if (root == nullptr) // stop condition
    {
      return 0;
    }
    else
    {
      int left = maxDepth(root->left);
      int right = maxDepth(root->right);
      return max(left, right) + 1;
    }
  }
};

int main()
{
}
// g++ test.cpp --ne_std=c++11 -pedantic -Wall -Wextra

```

