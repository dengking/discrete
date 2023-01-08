# [LeetCode-剑指 Offer 06. 从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)



## 我的解题

这道题的下面解法是最最能够体现: explicit stack VS recursion implicit stack 的。



### DFS-post-order

在post action中，执行insert。

```C++
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
	vector<int> reversePrint(ListNode *head)
	{
		vector<int> res;
		reversePrintRecursion(head, res);
		return res;
	}
	void reversePrintRecursion(ListNode *head, vector<int> &res)
	{
		if (head)
		{
			reversePrintRecursion(head->next, res);
			res.push_back(head->val);
		}
		else
		{
			return;
		}
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

### reverse by stack用栈来进行反转、explicit stack

```C++
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
	vector<int> reversePrint(ListNode *head)
	{
		stack<ListNode*> st;
		while (head)
		{
			st.push(head);
			head = head->next;
		}
		vector<int> res;
		while (!st.empty())
		{
			res.push_back(st.top()->val);
			st.pop();
		}
		return res;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

