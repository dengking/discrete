# [LeetCode-2. 两数相加](https://leetcode.cn/problems/add-two-numbers/)



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
public:
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode dummyNode { 0 };
		ListNode *tail = &dummyNode;
		int addOn = 0; // 进位
		int sum = 0; // 两个节点的和
		int val = 0; // 当前节点的值
		while (l1 && l2)
		{
			sum = l1->val + l2->val + addOn;
			val = sum % 10;
			addOn = sum >= 10 ? 1 : 0; // 进位这可能进1或0
			tail->next = new ListNode(val);
			tail = tail->next;
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l1 || l2)
		{
			ListNode *temp = l1 ? l1 : l2;
			while (temp)
			{
				sum = temp->val + addOn;
				val = sum % 10;
				addOn = sum >= 10 ? 1 : 0; // 进位这可能进1或0
				tail->next = new ListNode(val);
				tail = tail->next;
				temp = temp->next;
			}
		}
		if (addOn)
		{
			tail->next = new ListNode(addOn);
		}
		return dummyNode.next;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

### 二刷



```c++
#include <memory>
#include <iostream>

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
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy_head{};
        ListNode *tail = &dummy_head;
        int adder = 0;
        for (; l1 && l2; l1 = l1->next, l2 = l2->next, tail = tail->next)
        {
            int sum = l1->val + l2->val + adder;
            tail->next = new ListNode{sum % 10};
            adder = sum / 10;
        }
        for (; l1; l1 = l1->next, tail = tail->next)
        {
            int sum = l1->val + adder;
            tail->next = new ListNode{sum % 10};
            adder = sum / 10;
        }
        for (; l2; l2 = l2->next, tail = tail->next)
        {
            int sum = l2->val + adder;
            tail->next = new ListNode{sum % 10};
            adder = sum / 10;
        }
        if (adder)
        {
            tail->next = new ListNode{adder};
        }
        return dummy_head.next;
    }
};

int main()
{
}

```



### 三刷-最简洁版



```c++

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy_head{};
        ListNode *tail = &dummy_head;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            tail->next = new ListNode{sum % 10};
            carry = sum / 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;

            tail = tail->next;
        }

        return dummy_head.next;
    }
};

```



## 官方解题

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
	ListNode* addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *head = nullptr, *tail = nullptr;
		int carry = 0;
		while (l1 || l2)
		{
			int n1 = l1 ? l1->val : 0;
			int n2 = l2 ? l2->val : 0;
			int sum = n1 + n2 + carry;
			if (!head)
			{
				head = tail = new ListNode(sum % 10);
			}
			else
			{
				tail->next = new ListNode(sum % 10);
				tail = tail->next;
			}
			carry = sum / 10;
			if (l1)
			{
				l1 = l1->next;
			}
			if (l2)
			{
				l2 = l2->next;
			}
		}
		if (carry > 0)
		{
			tail->next = new ListNode(carry);
		}
		return head;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

