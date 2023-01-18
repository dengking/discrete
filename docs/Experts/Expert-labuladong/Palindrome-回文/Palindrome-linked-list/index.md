# Palindrome-linked-list



## LeetCode回文链表

[LeetCode-234. 回文链表-简单](https://leetcode.cn/problems/palindrome-linked-list/)

[LeetCode-剑指 Offer II 027. 回文链表-简单](https://leetcode.cn/problems/aMhZSa/)



### 解法

参考:

1、labuladong [如何高效判断回文单链表？](https://mp.weixin.qq.com/s/tCgEoOlZKS_ohuTx1VxJ-Q) 



#### Left right double pointer by DFS post order

1、本质上是left-right-double-pointer

2、DFS-post-action: 比较left pointer和right pointer

3、本质上对linked-list进行了reverse，因此它是可以使用explicit stack的

```C++


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};
class Solution
{
    ListNode *left{nullptr};

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
            bool res = postOrderTraverse(right->next); // 必须先压栈
            res = res && (left->val == right->val);
            left = left->next;

            return res;
        }
        else // base case: 空链表是回文的
        {
            return true;
        }
    }
};

int main()
{
}

```

#### Left right double pointer by explicit stack

TODO

#### 中点、反转、节省空间



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

