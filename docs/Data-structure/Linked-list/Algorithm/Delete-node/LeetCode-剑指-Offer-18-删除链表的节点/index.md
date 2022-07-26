# leetcode [剑指 Offer 18. 删除链表的节点](https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/)



## 我的解题

整体思路: 

1、找到待删除的节点current，然后让它的previous指向它的next；

2、特殊节点的处理: head节点并没有previous，因此它需要放到循环之外



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
	ListNode(int x, ListNode *next) :
					val(x), next(next)
	{
	}
};

class Solution
{
public:
	ListNode* deleteNode(ListNode *head, int val)
	{
		if (head->val == val)
		{
			ListNode *new_haed = head->next;
			// delete head;
			return new_haed;
		}
		ListNode *previous = head, *current = head->next;
		while (current && current->val != val)
		{
			previous = current;
			current = current->next;
		}
		if (current)
		{
			previous->next = current->next;
			// delete current;
		}
		return head;
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
	cout << s.deleteNode(N, 1) << endl;

	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```





## 官方解题: [面试题18. 删除链表的节点（双指针，清晰图解）](https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/solution/mian-shi-ti-18-shan-chu-lian-biao-de-jie-dian-sh-2/)

