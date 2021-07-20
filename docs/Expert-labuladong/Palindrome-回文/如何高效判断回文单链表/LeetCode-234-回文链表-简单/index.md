# LeetCode [234. 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/)



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

