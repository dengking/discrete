# [LeetCode-剑指 Offer 22. 链表中倒数第k个节点](https://leetcode.cn/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/)



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
	ListNode* getKthFromEnd(ListNode *head, int k)
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
		return slow;
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
	cout << s.getKthFromEnd(N, 1) << endl;

	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

