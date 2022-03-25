# leetcode [148. 排序链表](https://leetcode-cn.com/problems/sort-list/)



## 我的解题



### Merge sort

````C++
#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
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
	ListNode* sortList(ListNode *head)
	{
		return sortList(head, nullptr);
	}
	/**
	 * @brief 左闭右开
	 *
	 * @param head
	 * @param tail
	 * @return 执行依据排好序的linked list，它会创造新的linked list
	 */
	ListNode* sortList(ListNode *head, ListNode *tail)
	{
		if (head == nullptr) // 为什么空指针也可以直接返回
		{
			return head;
		}
		if (head->next == tail) // 只剩下一个节点，因为是左闭右开，这一步非常重要，因为后面需要进行合并
		{
			head->next = nullptr; // 断开链表
			return head;
		}
		ListNode *slow = head, *fast = head;
		while (fast != tail)
		{
			slow = slow->next;
			fast = fast->next;
			if (fast != tail)
			{
				fast = fast->next;
			}
		}
		ListNode *mid = slow;
		return merge(sortList(head, mid), sortList(mid, tail));
	}
	/**
	 * @brief 合并两个linked list
	 *
	 * @param head1
	 * @param head2
	 * @return
	 */
	ListNode* merge(ListNode *head1, ListNode *head2)
	{
		ListNode *dummyHead = new ListNode(0);
		ListNode *temp = dummyHead, *temp1 = head1, *temp2 = head2;
		while (temp1 != nullptr && temp2 != nullptr)
		{
			if (temp1->val <= temp2->val)
			{
				temp->next = temp1;
				temp1 = temp1->next;
			}
			else
			{
				temp->next = temp2;
				temp2 = temp2->next;
			}
			temp = temp->next;
		}
		if (temp1 != nullptr)
		{
			temp->next = temp1; // 直接append
		}
		else if (temp2 != nullptr)
		{
			temp->next = temp2; // 直接append
		}
		return dummyHead->next;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


````

上述code非常好，它非常好的推广merge sort 到linked list。

1、因为刚开始并不知道linked list的tail node，因此采用左开右闭

2、首先需要将linked list一分为二，直至只剩下single node，然后进行merge，生成更大的linked list；

