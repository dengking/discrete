# LeetCode [111. 二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/) 简单



## 我的解题

### BFS

```C++
#include <bits/stdc++.h>
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
	TreeNode() :
					val(0), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x) :
					val(x), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x, TreeNode *left, TreeNode *right) :
					val(x), left(left), right(right)
	{
	}
};

class Solution
{
public:
	int minDepth(TreeNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		queue<TreeNode*> q;
		q.push(root);
		int depth = 1;
		while (!q.empty())
		{
			// 按层来进行处理
			int sz = q.size(); //当前层中节点的个数
			for (int i = 0; i < sz; ++i) //
			{
				TreeNode *n = q.front();
				q.pop();                
				if (n->left == nullptr && n->right == nullptr)
				{
					return depth;
				}
				if (n->left)
				{
					q.push(n->left);
				}
				if (n->right)
				{
					q.push(n->right);

				}

			}
			++depth;
		}

		return depth;
	}
};

// Driver code
int main()
{

	Solution solu;
	vector<int> nums = { 1, 3, 5, 4, 7 };
	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



### DFS

```C++
#include <bits/stdc++.h>
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
	TreeNode() :
					val(0), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x) :
					val(x), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x, TreeNode *left, TreeNode *right) :
					val(x), left(left), right(right)
	{
	}
};

class Solution
{
public:
	int minDepth(TreeNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		if (root->left == nullptr && root->right == nullptr)
		{
			return 1;
		}
		int min_depth = INT_MAX;
		if (root->left)
		{
			min_depth = min(min_depth, minDepth(root->left));
		}
		if (root->right)
		{
			min_depth = min(min_depth, minDepth(root->right));
		}
		return min_depth + 1;
	}
};

// Driver code
int main()
{

	Solution solu;
	vector<int> nums = { 1, 3, 5, 4, 7 };
	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```





## [官方解题](https://leetcode.cn/problems/minimum-depth-of-binary-tree/solution/er-cha-shu-de-zui-xiao-shen-du-by-leetcode-solutio/)



### DFS



### BFS

```C++
#include <bits/stdc++.h>
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
	TreeNode() :
					val(0), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x) :
					val(x), left(nullptr), right(nullptr)
	{
	}
	TreeNode(int x, TreeNode *left, TreeNode *right) :
					val(x), left(left), right(right)
	{
	}
};

class Solution
{
public:
	int minDepth(TreeNode *root)
	{
		if (root == nullptr)
		{
			return 0;
		}

		queue<pair<TreeNode*, int> > que;
		que.emplace(root, 1);
		while (!que.empty())
		{
			TreeNode *node = que.front().first;
			int depth = que.front().second;
			que.pop();
			if (node->left == nullptr && node->right == nullptr)
			{
				return depth;
			}
			if (node->left != nullptr)
			{
				que.emplace(node->left, depth + 1);
			}
			if (node->right != nullptr)
			{
				que.emplace(node->right, depth + 1);
			}
		}

		return 0;
	}
};

// Driver code
int main()
{

	Solution solu;
	vector<int> nums = { 1, 3, 5, 4, 7 };
	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

## 二刷

### dfs

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>

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
  int minDepth(TreeNode *root)
  {
    if (root)
    {
      int left = minDepth(root->left);

      int right = minDepth(root->right);
      if (left == 0)
      {
        return right + 1;
      }
      if (right == 0)
      {
        return left + 1;
      }
      return min(left, right) + 1;
    }
    else
    {
      return 0;
    }
  }
};

int main()
{
}
```

