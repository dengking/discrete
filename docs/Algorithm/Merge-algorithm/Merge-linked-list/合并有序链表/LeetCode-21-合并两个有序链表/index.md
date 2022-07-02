# leetcode [21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)



## 我的解题

```C++
#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() :
					val(0), next(nullptr)
	{
	}
	ListNode(int x) :
					val(x), next(nullptr)
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
	ListNode* mergeTwoLists(ListNode *a, ListNode *b)
	{
		if ((!a) || (!b))
			return a ? a : b;
		/**
		 * head是"dummy node for create linked list"
		 * 需要注意的是它是automatic variable，使用它为了便于创建新的linked list
		 * 最终返回的 head.next
		 */
		ListNode head, *tail = &head;
		ListNode *aPtr = a, *bPtr = b;
		while (aPtr && bPtr)
		{
			if (aPtr->val < bPtr->val)
			{
				tail->next = aPtr;
				aPtr = aPtr->next; // 迭代
			}
			else
			{
				tail->next = bPtr;
				bPtr = bPtr->next; // 迭代
			}
			tail = tail->next;
		}
		tail->next = (aPtr ? aPtr : bPtr); // 将剩余部分也添加到linked list中
		return head.next;
	}
};

ostream& operator<<(ostream &stream, ListNode *Node)
{
	while (Node)
	{
		stream << Node->val << ",";
		Node = Node->next;
	}
	return stream;
}

int main()
{
	ListNode *N1 = new ListNode { 1 };
	N1->next = new ListNode { 3 };
	N1->next->next = new ListNode { 5 };
	N1->next->next->next = new ListNode { 7 };

	ListNode *N2 = new ListNode { 2 };
	N2->next = new ListNode { 4 };
	N2->next->next = new ListNode { 6 };
	N2->next->next->next = new ListNode { 8 };

	Solution s;
	cout << s.mergeTwoLists(N1, N2) << endl;
}


```

