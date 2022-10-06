# [LeetCode-面试题 02.02. 返回倒数第 k 个节点](https://leetcode.cn/problems/kth-node-from-end-of-list-lcci/)



## 我的解题

```C++
/* Program to implement a stack
 using two queue */
#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :
					val(x), next(NULL)
	{
	}
};

class Solution
{
public:
	int kthToLast(ListNode *head, int k)
	{
		ListNode *fast = head, *slow = head;
		while (k-- > 0)
		{
			fast = fast->next;
		}
		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		return slow->val;
	}
};

// Driver code
int main()
{
	ListNode *N = new ListNode { 3 };
	N->next = new ListNode { 2 };
	N->next->next = new ListNode { 0 };
	N->next->next->next = new ListNode { 4 };
	Solution s;
	cout << s.kthToLast(N, 1) << endl;

	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

