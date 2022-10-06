# [LeetCode-382. 链表随机节点](https://leetcode.cn/problems/linked-list-random-node/)



## 我的解题



```C++
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
	ListNode *m_head;
public:
	/** @param head The linked list's head.
	 Note that the head is guaranteed to be not null, so it contains at least one node. */
	Solution(ListNode *head) :
					m_head { head }
	{
		srand((unsigned) time(NULL));
	}

	/** Returns a random node's value. */
	int getRandom()
	{

		int res = m_head->val;
		ListNode *node = m_head->next;
		int k = 2;
		while (node)
		{
			if (rand() % k == 0) // 让当前节点以 1/k的概率被选中
			{
				res = node->val;
			}
			node = node->next;
			++k;
		}
		return res;
	}
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

