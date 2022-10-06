# [LeetCode-337. 打家劫舍 III](https://leetcode.cn/problems/house-robber-iii/) 中等



## 我的解题

### 超时的写法一

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
  int rob(TreeNode *root)
  {
    return max(
        rob(root, true), // 抢root
        rob(root, false) // 不抢root
    );
  }
  int rob(TreeNode *root, bool rob_flag)
  {
    if (root)
    {
      if (rob_flag)
      {
        return root->val + rob(root->left, false) + rob(root->right, false);
      }
      else
      {
        return max({
            rob(root->left, false) + rob(root->right, false),
            rob(root->left, false) + rob(root->right, true),
            rob(root->left, true) + rob(root->right, false),
            rob(root->left, true) + rob(root->right, true),
        });
      }
    }
    else
    {
      return 0;
    }
  }
};

// Driver code
int main()
{

  Solution solu;

  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

上述写法会超时。

### 超时写法二

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
/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr)
  {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr)
  {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
  {
  }
};

class Solution
{
public:
  int rob(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0;
    }
    else
    {
      // 抢root
      int rot_root = root->val;
      if (root->left)
        rot_root += (rob(root->left->left) + rob(root->left->right));
      if (root->right)
        rot_root += (rob(root->right->left) + rob(root->right->right));

      // 不抢root
      int not_rot_root = rob(root->left) + rob(root->right);
      return max(rot_root, not_rot_root);
    }
  }
};

// Driver code
int main()
{

  Solution solu;

  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



### 使用备忘录

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
/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr)
  {
  }
  TreeNode(int x) : val(x), left(nullptr), right(nullptr)
  {
  }
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
  {
  }
};

class Solution
{
  unordered_map<TreeNode *, int> memo;

public:
  int rob(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0;
    }
    if (memo.count(root))
    {
      return memo[root];
    }
    // 抢root节点
    int rob_root = root->val +
                   (root->left ? (rob(root->left->left) + rob(root->left->right)) : 0) +   // 抢左子树
                   (root->right ? (rob(root->right->left) + rob(root->right->right)) : 0); // 抢右子树
    // 不抢root节点
    int not_rob_root = rob(root->left) + rob(root->right);
    int result = max(rob_root, not_rob_root);
    memo[root] = result;
    return result;
  }
};

// Driver code
int main()
{

  Solution solu;

  return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

> NOTE: 
>
> 需要注意: 
>
> ```C++
> 		int rob_root = root->val + (root->left ? (rob(root->left->left) + rob(root->left->right)) : 0) + (root->right ? (rob(root->right->left) + rob(root->right->right)) : 0);
> ```
>
> `(root->left ? (rob(root->left->left) + rob(root->left->right)) : 0)` 必须要使用括号，否则会报: "runtime error: applying non-zero offset 18446744073709551615 to null pointer "，关于此，参见:
>
> stackoverflow [runtime error: applying non-zero offset 18446744073709551615 to null pointer (basic_string.h)](https://stackoverflow.com/questions/66869520/runtime-error-applying-non-zero-offset-18446744073709551615-to-null-pointer-ba)
>
> 



### 不使用备忘录

```C++
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
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
	int rob(TreeNode *root)
	{
		auto res = do_rob(root);
		return max(res.first, res.second);
	}
	pair<int, int> do_rob(TreeNode *root)
	{
		if (root == nullptr)
		{
			return { 0, 0};
		}
		pair<int, int> left = do_rob(root->left); // 左子树
		pair<int, int> right = do_rob(root->right); // 右子树
		// 抢root节点
		int rob_root = root->val + left.first + right.first;
		// 不抢root节点
		int not_rob_root = max(left.first, left.second) + max(right.first, right.second);

		return {not_rob_root, rob_root};
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

