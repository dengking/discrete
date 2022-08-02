# [LeetCode-141. 环形链表](https://leetcode.cn/problems/linked-list-cycle/)



## 快慢指针是否一定会相遇？

参见 `List\Circle-detection` 章节。

![](./labuladong-list-with-cycle.jpg)



## 我的解答

这是一个判断问题，需要注意的是: 可能存在环也可能不存在环，因此算法需要能够cover这两种情况，所以比较重要的是stop condition的设置，它使用的stop condition包括如下两个

一、tail node

```c++
while (fast != NULL && fast->next != NULL)
```

简而言之: 它的stop condition是linked list的tail node，一旦fast达到了tail node，那么就应该停止算法。如果linked list中包含cycle，那么上述stop condition就永远无法满足，所以就需要第二个stop condition:

二、

```c++
if (fast == slow) // 两者相遇
{
    return true;
}
```

如果linked list中存在cycle，那么上述stop condition最终肯定会满足。

### 完整代码



```C++
/* Program to implement a stack
 using two queue */
#include <bits/stdc++.h>
using namespace std;

//Definition for singly-linked list.
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
	bool hasCycle(ListNode *head)
	{
		ListNode *fast = head, *slow = head;

        /**
        * 添加 `fast->next != NULL` 的原因是:
        * 原因1: 对于长度为1的list，是不可能使用fast指针的，因为fast指针一次走两步，在循环体中: `fast->next->next;`
        * 对于长度小于2的链表，则`fast->next`为null，可以据此来判断。
        * 原因2: 如果不加空指针包含，`fast->next->next;` 可能会core dump
        */
		while (fast != NULL && fast->next != NULL)
		{
			fast = fast->next->next; // 走两步
			slow = slow->next; // 走一步
			if (fast == slow) // 两者相遇
			{
				return true;
			}
		}
		return false;
	}
};
// Driver code
int main()
{
	ListNode *N = new ListNode { 3 };
	N->next = new ListNode { 2 };
	N->next->next = new ListNode { 0 };
	N->next->next->next = new ListNode { 4 };
	N->next->next->next->next = N->next;
	Solution s;
	cout << s.hasCycle(N) << endl;

	ListNode *N2 = new ListNode { 3 };
	N2->next = new ListNode { 2 };
	N2->next->next = new ListNode { 0 };
	N2->next->next->next = new ListNode { 4 };
	cout << s.hasCycle(N2) << endl;

	return 0;
}
// g++ test.cpp

```

