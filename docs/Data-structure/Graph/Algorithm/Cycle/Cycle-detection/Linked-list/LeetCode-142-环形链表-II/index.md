# leetcode [142. 环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/)



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
	ListNode* detectCycle(ListNode *head)
	{
		ListNode *fast = head, *slow = head;
		bool hasCycle = false;
		/**
		 * 添加 `fast->next != NULL` 的原因是:
		 * 原因1: 对于长度为1的list，是不可能使用fast指针的，因为fast指针一次走两步，在循环体中: `fast->next->next;`
		 * 对于长度小于2的链表，则`fast->next`为null，可以据此来判断。
		 * 原因2: 如果不加空指针包含，`fast->next->next;` 可能会core dump
		 */
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				hasCycle = true;
				break;
			}
		}
		if (hasCycle)
		{
			slow = head; // 将slow拨回head
			// 当两者再次相遇的时候，这个点就是环起点
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
		else
		{
			return nullptr;
		}
	}
};

// Driver code
int main()
{
	ListNode *N = new ListNode { 3 };
	N->next = new ListNode { 2 };
	N->next->next = new ListNode { 0 };
	N->next->next->next = new ListNode { 4 };
	N->next->next->next->next = N->next;
	Solution s;
	cout << s.detectCycle(N) << endl;

	ListNode *N2 = new ListNode { 3 };
	N2->next = new ListNode { 2 };
	N2->next->next = new ListNode { 0 };
	N2->next->next->next = new ListNode { 4 };
	cout << s.detectCycle(N2) << endl;

	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



## [环形链表 II](https://leetcode.cn/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode-solution/) # 官方解题

