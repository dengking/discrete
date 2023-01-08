# [LeetCode-206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/)



## 我的解题

### previous-current-next-三指针-iteration

思路: 基于"previous-current-next-三指针-iteration"；让current node的next指向它的previous node。

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
		return reverseListIteration(head);
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



### Explicit-stack



```C++
#include <iostream>
#include <stack>
using namespace std;

// Definition for singly-linked list.
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
public:
    ListNode *reverseList(ListNode *head)
    {
        std::stack<ListNode *> stk;
        for (; head; head = head->next)
        {
            stk.push(head);
        }
        ListNode *newHead = nullptr;
        if (!stk.empty())
        {
            newHead = stk.top();
            stk.pop();
        }

        while (!stk.empty())
        {
            auto *node = stk.top();
            node->next->next = node;
            node->next = nullptr;
            stk.pop();
        }

        return newHead;
    }
};

int main()
{
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```



### DFS-pre-order



```c++
#include <iostream>
using namespace std;

// Definition for singly-linked list.
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
public:
    ListNode *reverseList(ListNode *head)
    {
        return dfsPreOrder(nullptr, head);
    }
    ListNode *dfsPreOrder(ListNode *prev, ListNode *cur)
    {
        if (cur)
        {
            auto *next = cur->next;
            cur->next = prev;
            return dfsPreOrder(cur, next);
        }
        else
        {
            return prev;
        }
    }
};

int main()
{
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```



1、上述递归版本的实现，相较于 [官方解题](https://leetcode.cn/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode-solution-d1k2/) 中的递归版本是更加容易理解的，它和迭代版本有着较好的对应。



### DFS-post-order



```c++
#include <iostream>
using namespace std;

// Definition for singly-linked list.
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
public:
    ListNode *reverseList(ListNode *head)
    {
        return dfsPostOrder(head);
    }
    ListNode *dfsPostOrder(ListNode *cur)
    {
        if (cur)
        {
            if (cur->next) // internal node
            {
                auto *tail = dfsPostOrder(cur->next);
                cur->next->next = cur;
                cur->next = nullptr; // 将当前节点作为tail，这一步非常重要，否则构造出的linked-list就没有tail了
                return tail;
            }
            else // tail node
            {
                return cur;
            }
        }
        else
        {
            return cur;
        }
    }
};

int main()
{
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```



## [官方解题](https://leetcode.cn/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode-solution-d1k2/)

