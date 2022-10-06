# [LeetCode-234. 回文链表](https://leetcode.cn/problems/palindrome-linked-list/)



## 我的解答

### 后序遍历

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
	ListNode *left { nullptr };
public:
	bool isPalindrome(ListNode *head)
	{
		left = head;
		return postOrderTraverse(head);
	}
	bool postOrderTraverse(ListNode *right)
	{
		if (right)
		{
			bool res = postOrderTraverse(right->next) && (left->val == right->val);
			left = left->next;
			return res;
		}
		else
		{
			return true;
		}
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



### 中点、反转、节省空间



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
public:
	bool isPalindrome(ListNode *head)
	{
		ListNode *lastHalfPtr = lastHalf(head);
		lastHalfPtr = reverse(lastHalfPtr);
		while (lastHalfPtr)
		{
			if (lastHalfPtr->val != head->val)
			{
				return false;
			}
			lastHalfPtr = lastHalfPtr->next;
			head = head->next;
		}
		return true;
	}
	/**
	 * @brief 找到链表的后半段
	 *
	 * @param head
	 * @return
	 */
	ListNode* lastHalf(ListNode *head)
	{
		ListNode *fast = head, *slow = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		if (fast) // 链表长度为基数
		{
			return slow->next;
		}
		else // 链表长度为偶数
		{
			return slow;
		}
	}
	ListNode* reverse(ListNode *head)
	{
		ListNode *prev = nullptr, *cur = head, *next = nullptr;
		while (cur)
		{
			next = cur->next;
			cur->next = prev;

			prev = cur;
			cur = next;
		}
		return prev;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

