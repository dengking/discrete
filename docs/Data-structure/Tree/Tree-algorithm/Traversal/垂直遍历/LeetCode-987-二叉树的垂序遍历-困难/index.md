# LeetCode [987. 二叉树的垂序遍历](https://leetcode-cn.com/problems/vertical-order-traversal-of-a-binary-tree/) 困难



## 我的解题

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
	struct Node
	{
		int x { 0 };
		int y { 0 };
		int val { 0 };
		Node()
		{
		}
		Node(int a, int b, int c) :
						x(a), y(b), val(c)
		{
		}
		bool operator <(Node node) const
		{
			if (y != node.y)
				return y > node.y;
			else if (x != node.x)
				return x > node.x;
			return val > node.val;
		}

	};
	int m_min_y { 0 };
	int m_max_y { 0 };

	unordered_map<int, priority_queue<Node>> m_2nd2Vals;
public:
	vector<vector<int>> verticalTraversal(TreeNode *root)
	{
		Node root_node { 0, 0, root->val };
		DFS(root, root_node);

		int width = m_max_y - m_min_y + 1;
		vector<vector<int>> res(width);

		for (int y = m_min_y; y <= m_max_y; ++y)
		{
			auto iter = m_2nd2Vals.find(y);
			if (iter != m_2nd2Vals.end())
			{
				while (!iter->second.empty())
				{
					res[y - m_min_y].push_back(iter->second.top().val);
					iter->second.pop();
				}

			}
		}
		return res;
	}
	void DFS(TreeNode *root, Node &root_node)
	{
		if (root)
		{
			m_2nd2Vals[root_node.y].push(root_node);
			if (root->left)
			{
				Node left_node { root_node.x + 1, root_node.y - 1, root->left->val };
				m_min_y = min(m_min_y, left_node.y);
				DFS(root->left, left_node);
			}
			if (root->right)
			{
				Node right_node { root_node.x + 1, root_node.y + 1, root->right->val };
				m_max_y = max(m_max_y, right_node.y);
				DFS(root->right, right_node);
			}
		}
	}
};

int main()
{
	Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

### 二刷



```c++

class Solution
{
  std::map<int, std::map<int, std::priority_queue<int, std::vector<int>, std::greater<int>>>> states;

public:
  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    dfs(root, 0, 0);
    vector<vector<int>> res;
    for (auto &&[_, col] : states)
    {
      res.push_back({});
      for (auto &&[_, nodes] : col)
      {
        while (!nodes.empty())
        {
          res.back().push_back(nodes.top());
          nodes.pop();
        }
      }
    }
    return res;
  }
  void dfs(TreeNode *root, int col, int depth)
  {
    if (root)
    {
      states[col][depth].push(root->val);
      dfs(root->left, col - 1, depth + 1);
      dfs(root->right, col + 1, depth + 1);
    }
  }
};

```

