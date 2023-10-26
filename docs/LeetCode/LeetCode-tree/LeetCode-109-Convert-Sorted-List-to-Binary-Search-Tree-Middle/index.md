# [LeetCode-109. Convert Sorted List to Binary Search Tree](https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/)



```c++
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
	TreeNode *sortedListToBST(ListNode *head)
	{
		return sortedListToBST(head, nullptr);
	}

private:
	TreeNode *sortedListToBST(ListNode *start, ListNode *end)
	{
		if (start == nullptr)
		{
			return nullptr;
		}
		if (start == end)
		{
			return nullptr;
		}
		if (start->next == end) // 只有一个节点
		{
			return new TreeNode(start->val);
		}
		ListNode *mid = midNode(start, end);
		if (mid)
		{
			TreeNode *root = new TreeNode(mid->val);
			root->left = sortedListToBST(start, mid);
			root->right = sortedListToBST(mid->next, end);
			return root;
		}
		else
		{
			return nullptr;
		}
	}
	ListNode *midNode(ListNode *start, ListNode *end)
	{
		ListNode *fast = start, *slow = start;
		while (fast != end)
		{
			if (fast->next != end)
			{
				fast = fast->next->next;
				slow = slow->next;
			}
			else
			{
				break;
			}
		}
		return slow;
	}
};

```

