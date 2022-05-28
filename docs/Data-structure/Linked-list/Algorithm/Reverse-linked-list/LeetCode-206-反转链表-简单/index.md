# leetcode [206. 反转链表](https://leetcode-cn.com/problems/reverse-linked-list/)





## 我的解题



```C++
#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
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
	ListNode* reverseList(ListNode *head)
	{
		return reverseListRecursion(head);
	}
	ListNode* reverseListIteration(ListNode *head)
	{
		ListNode *prev = nullptr, *cur = head, *next = nullptr; // 三指针
		while (cur)
		{
			next = cur->next; // 先取next
			cur->next = prev; // 更新current node的next
			/**
			 * 向后滑动一个节点
			 */
			prev = cur; // 更新prev
			cur = next; // 最后更新cur
		}
		return prev; // 需要注意的是，返回值是prev，因为上述while退出的时候，cur为nullptr
	}
	ListNode* reverseListRecursion(ListNode *head)
	{
		return reverseListRecursion(nullptr, head);
	}
  // 返回值是链表的head node
	ListNode* reverseListRecursion(ListNode *prev, ListNode *cur)
	{
		if (cur) // 空指针保护
		{
			ListNode *next = cur->next; // 先取next
			cur->next = prev; // 更新current node的next
			if (next)
			{
				return reverseListRecursion(cur, next); // 向后滑动一个节点
			}
		}
		return cur;
	}
};

ostream& operator <<(ostream &stream, ListNode *head)
{
	while (head)
	{
		stream << head->val << " ";
		head = head->next;
	}
	return stream;
}
int main()
{
	ListNode N1 { 1 };
	ListNode N2 { 2 };
	ListNode N3 { 3 };
	ListNode N4 { 4 };
	ListNode N5 { 5 };
	N1.next = &N2;
	N2.next = &N3;
	N3.next = &N4;
	N4.next = &N5;

	Solution s;
	cout << s.reverseList(&N1) << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```

1、上述递归版本的实现，相较于 [官方解题](https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode-solution-d1k2/) 中的递归版本是更加容易理解的，它和迭代版本有着较好的对应。

2、recursion and iteration

3、"One-by-one-move next-向后滑动一步"

## [官方解题](https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode-solution-d1k2/)

