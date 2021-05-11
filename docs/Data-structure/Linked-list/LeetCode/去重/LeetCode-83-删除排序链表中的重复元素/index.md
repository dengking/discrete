# leetcode [83. 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)

> NOTE: 
>
> 一、在下面文章中，给出了算法:
>
> 1、labuladong [如何高效对有序数组/链表去重？](https://mp.weixin.qq.com/s/6Eb7gKqNqXH9B0hSZvMs5A)
>
> 2、labuladong  [双指针技巧秒杀四道数组/链表题目](https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ)
>
> 

## 我的解答

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
	ListNode* removeDuplicates(ListNode *head, bool delete_flag = false)
	{
		if (head == nullptr)
		{
			return head;
		}
		ListNode *fast = head->next, *slow = head;
		while (fast)
		{
			if (fast->val != slow->val)
			{
				ListNode *delete_head = slow->next; // 待删除子链表的头
				slow->next = fast;
				slow = slow->next;
				/**
				 * 需要将两者之间的node全部都删除，因为它们都是重复的值
				 */
				if (delete_flag)
				{
					while (delete_head != nullptr && delete_head != fast)
					{
						ListNode *n = delete_head;
						delete_head = delete_head->next; // 迭代
						cout << "删除:" << n->val << endl;
						delete n; // 删除掉对应的节点
					}
				}
			}
			fast = fast->next;
		}
		slow->next = nullptr;
		return head;
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

void test1()
{
	ListNode *N1 = new ListNode { 1 };
	ListNode *N2 = new ListNode { 1 };
	ListNode *N3 = new ListNode { 2 };
	ListNode *N4 = new ListNode { 2 };
	ListNode *N5 = new ListNode { 5 };
	ListNode *N6 = new ListNode { 6 };
	N1->next = N2;
	N2->next = N3;
	N3->next = N4;
	N4->next = N5;
	N5->next = N6;
	cout << N1 << endl;
	Solution s;
	cout << s.removeDuplicates(N1, true) << endl;
}

void test2()
{
	ListNode N1 { 1 };
	ListNode N2 { 1 };
	ListNode N3 { 2 };
	ListNode N4 { 2 };
	ListNode N5 { 5 };
	ListNode N6 { 6 };
	N1.next = &N2;
	N2.next = &N3;
	N3.next = &N4;
	N4.next = &N5;
	N5.next = &N6;
	cout << &N1 << endl;
	Solution s;
	cout << s.removeDuplicates(&N1, false) << endl;
}
int main()
{
	test1();
	test2();
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```

