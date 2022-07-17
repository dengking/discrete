# Tree depth(树深度)



## 二叉树最小树深度



### BFS

leetcode [111. 二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

```C++
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
				q.pop();
			}
			++depth;
		}

		return depth;
	}
```

## 二叉树最大数深度

leetcode [剑指 Offer 55 - I. 二叉树的深度](https://leetcode.cn/problems/er-cha-shu-de-shen-du-lcof/)

### DFS

```C++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
```



### BFS

#### [104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/) # 官方解题

下面的解法需要和 leetcode [111. 二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/) 中的BFS解法进行对比。

```C++
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        while (!Q.empty()) {
            int sz = Q.size();
            while (sz > 0) {
                TreeNode* node = Q.front();Q.pop();
                if (node->left) Q.push(node->left);
                if (node->right) Q.push(node->right);
                sz -= 1;
            }
            ans += 1;
        } 
        return ans;
    }
};

```



## N叉树最大树深度



leetcode [559. N 叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-n-ary-tree/)

```C++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr)
        {
            return 0;
        }
        int maxDepthOfChild = 0;
        for(auto&& child:root->children)
        {
            maxDepthOfChild = max(maxDepthOfChild, maxDepth(child));
        }
        return 1 + maxDepthOfChild;
    }
};
```

