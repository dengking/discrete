# [LeetCode-111. 二叉树的最小深度-简单](https://leetcode.cn/problems/minimum-depth-of-binary-tree/) 

这是在阅读 labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) 时发现的

## 我的解题

相比较之下，我觉得这道题更加适合于使用BFS解法。



### BFS

一、其实"最小深度"也可以理解为"最短距离"，显然这是比较适合于使用BFS进行结局的，在  labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) 中有着非常好的总结:

> **显然起点就是`root`根节点，终点就是最靠近根节点的那个「叶子节点」嘛**



> 首先，你看 BFS 的逻辑，`depth`每增加一次，队列中的所有节点都向前迈一步，这保证了第一次到达终点的时候，走的步数是最少的。
>
> > NOTE: 关于上面这段话中总结的"这保证了第一次到达终点的时候，走的步数是最少的"，在 labuladong  [我写了一个模板，把 Dijkstra 算法变成了默写题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492167&idx=1&sn=bc96c8f97252afdb3973c7d760edb9c0&scene=21#wechat_redirect) 中也进行了非常好的阐述，其中解释了visited set的重要作用。将次概括为"BFS-complete&optimal-BFS第一次到达终点走的步数是最少的"。
>
> DFS 不能找最短路径吗？其实也是可以的，但是时间复杂度相对高很多。
>
> 你想啊，DFS 实际上是靠递归的堆栈记录走过的路径，你要找到最短路径，肯定得把二叉树中所有树杈都探索完才能对比出最短的路径有多长对不对？
>
> 而 BFS 借助队列做到一次一步「齐头并进」，是可以在不遍历完整棵树的条件下找到最短距离的。
>
> > NOTE: 这一段总结非常好，我们将次称之为"stop-when-target"，即达到目标后就终止traverse/search。
>
> 形象点说，DFS 是线，BFS 是面；DFS 是单打独斗，BFS 是集体行动。这个应该比较容易理解吧。



它的stop-condition是当第一次遇到leaf-node的时候，按照上面这段话的意思: 它的目标节点是第一次遇到的"**「叶子节点」**"。



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
		if (root == nullptr) // stop-condition: empty-tree
		{
			return 0;
		}
		if (root->left == nullptr && root->right == nullptr) // stop-condition: leaf-node
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

DFS的劣势是需要完整的遍历整棵树。



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



## highlight



```
tag-DFS-post-order-binary-tree-return-value-bottom-up-二叉树的最小高度
tag-base case-叶子节点的高度为1
tag-recurrence relation递归状态转移方程-当前节点的最小深度=min(left child, right child)+1
tag-return value为当前节点的最小高度
```

