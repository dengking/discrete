# geeksforgeeks [Maximum sub-tree sum in a Binary Tree such that the sub-tree is also a BST](https://www.geeksforgeeks.org/maximum-sub-tree-sum-in-a-binary-tree-such-that-the-sub-tree-is-also-a-bst/?ref=rp)

> #### NOTE: 
>
> LeetCode [333. 最大 BST 子树](https://leetcode-cn.com/problems/largest-bst-subtree/)
>
> 

**Approach:** We traverse the tree in bottom-up manner. For every traversed node, we store the information of maximum and minimum of that subtree, a variable `isBST` to store if it is a BST, variable **`currmax`** to store the maximum sum of BST found till now, and a variable **`sum`** to store the sum of Left and Right subtree(which is also a BST) rooted under the current node.

## 完整实现

Below is the implementation of the above approach: 

```C++
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Binary tree node
struct Node
{
	struct Node *left;
	struct Node *right;
	int data;

	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

// Information stored in every
// node during bottom up traversal
struct Info
{

	// Max Value in the subtree
	int max;

	// Min value in the subtree
	int min;

	// If subtree is BST
	bool isBST;

	// Sum of the nodes of the sub-tree
	// rooted under the current node
	int sum;

	// Max sum of BST found till now
	int currmax;
};

// Returns information about subtree such as
// subtree with maximum sum which is also a BST
Info MaxSumBSTUtil(struct Node *root, int &maxsum)
{
	// Base case
	if (root == NULL)
		return
		{	INT_MIN, INT_MAX, true, 0, 0};

	// If current node is a leaf node then
	// return from the function and store
	// information about the leaf node
	if (root->left == NULL && root->right == NULL)
	{
		maxsum = max(maxsum, root->data);
		return
		{	root->data, root->data, true, root->data, maxsum};
	}

	// Store information about the left subtree
	Info L = MaxSumBSTUtil(root->left, maxsum);

	// Store information about the right subtree
	Info R = MaxSumBSTUtil(root->right, maxsum);

	Info BST;

	// If the subtree rooted under the current node
	// is a BST
	if (L.isBST && R.isBST && L.max < root->data && R.min > root->data)
	{

		BST.max = max(root->data, max(L.max, R.max));
		BST.min = min(root->data, min(L.min, R.min));

		maxsum = max(maxsum, R.sum + root->data + L.sum);
		BST.sum = R.sum + root->data + L.sum;

		// Update the current maximum sum
		BST.currmax = maxsum;

		BST.isBST = true;
		return BST;
	}
	else
	{
		// If the whole tree is not a BST then
		// update the current maximum sum
		BST.isBST = false;
		BST.currmax = maxsum;
		BST.sum = R.sum + root->data + L.sum;

		return BST;
	}
}

// Function to return the maximum
// sum subtree which is also a BST
int MaxSumBST(struct Node *root)
{
	int maxsum = INT_MIN;
	return MaxSumBSTUtil(root, maxsum).currmax;
}

// Driver code
int main()
{
	struct Node *root = new Node(5);
	root->left = new Node(14);
	root->right = new Node(3);
	root->left->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(9);
	root->left->left->right = new Node(1);

	cout << MaxSumBST(root);

	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra
```

