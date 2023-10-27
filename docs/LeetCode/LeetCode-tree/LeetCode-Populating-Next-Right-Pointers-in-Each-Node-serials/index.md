# Populating Next Right Pointers in Each Node serials



## [LeetCode-116. 填充每个节点的下一个右侧节点指针-中等](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node/) 



### 我的解题

主要考察树的广度优先遍历

```C++
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Node
{
	int val;
	Node *left;
	Node *right;
	Node *next;
	Node(int x) :
					val(x), left(NULL), right(NULL), next(NULL)
	{
	}
};

class Solution
{
public:
	Node* connect(Node *root)
	{
		queue<Node*> Q;
		if (root == nullptr)
		{
			return root;
		}
		else
		{
			Q.push(root);
		}
		while (!Q.empty())
		{
			// 记录当前层节点的个数
			int size = Q.size();
			// 对当前层的节点进行处理
			for (int i = 0; i < size; ++i)
			{
				Node *top = Q.front();
				
				if (i < size - 1)
				{
					top->next = Q.front();
				}
        Q.pop();
				// 将下一层的节点加入到队列中
				if (top->left)
				{
					Q.push(top->left);
				}
				if (top->right)
				{
					Q.push(top->right);
				}
			}
		}
		return root;
	}
};

int main()
{
	Node n1 { 1 };
	Node n2 { 2 };
	Node n3 { 3 };
	Node n4 { 4 };
	Node n5 { 5 };
	Node n6 { 6 };
	n1.left = &n2;
	n1.right = &n5;
	n2.left = &n3;
	n2.right = &n4;
	n5.right = &n6;
	Solution s;
	s.connect(&n1);
}

```





### labuladong [东哥手把手带你套框架刷通二叉树|第一期](https://mp.weixin.qq.com/s/izZ5uiWzTagagJec6Y7RvQ) 

其中给出了使用recursion的解法。

```C++
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Node
{
	int val;
	Node *left;
	Node *right;
	Node *next;
	Node(int x) :
					val(x), left(NULL), right(NULL), next(NULL)
	{
	}
};
class Solution
{
public:
	Node* connect(Node *root)
	{
		if (root)
		{
			connect(root->left, root->right);
		}
		return root;
	}
	void connect(Node *left, Node *right)
	{
		if (left == nullptr || right == nullptr)
		{
			return;
		}
		left->next = right;
		connect(left->left, left->right);
		connect(right->left, right->right);
		connect(left->right, right->left);
	}
};

int main()
{
	Node n1 { 1 };
	Node n2 { 2 };
	Node n3 { 3 };
	Node n4 { 4 };
	Node n5 { 5 };
	Node n6 { 6 };
	n1.left = &n2;
	n1.right = &n5;
	n2.left = &n3;
	n2.right = &n4;
	n5.right = &n6;
	Solution s;
	s.connect(&n1);
}

```



## [LeetCode-117. Populating Next Right Pointers in Each Node II-middle](https://leetcode.cn/problems/populating-next-right-pointers-in-each-node-ii/)

```c++
#include <vector>
#include <queue>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct Node {
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node(int x) :
            val(x), left(NULL), right(NULL), next(NULL) {
    }
};

class Solution {
public:
    Node *connect(Node *root) {
        std::queue<Node *> q;
        if (root != nullptr) {
            q.push(root);
        }
        while (!q.empty()) {
            // 记录当前层节点的个数
            int size = q.size();
            // 对当前层的节点进行处理
            for (int i = 0; i < size; ++i) {
                Node *top = q.front();
                q.pop();
                if (i < size - 1) {
                    top->next = q.front();
                }
                // 将下一层的节点加入到队列中
                if (top->left) {
                    q.push(top->left);
                }
                if (top->right) {
                    q.push(top->right);
                }
            }
        }
        return root;
    }
};

```



