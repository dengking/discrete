# leetcode [19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)



## 我的解题

### 我的不成熟的思考

1、由于是要删除倒数第`N`个节点，最好是找到它的前驱节点，即倒数第`N+1`个节点，通过它来删除倒数第`N`个节点。

2、特殊情况的处理:

对于长度为1的linked list，删除节点后，应该要返回为`nullptr`，这是要进行特殊处理的。

### "dummy node"技巧

后来看了 [删除链表的倒数第N个节点 # 官方解题](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/) 后，发现，采用"dummy node"技巧，它使得每个node都有前驱node，这样，对于一些没有前驱节点的情况:

1、长度为1的linked list

2、`[1,2]`，删除倒数第二个

能够使程序非常地统一、简洁的方式来进行处理:

```C++
		ListNode *to_delete = slow->next; // 待删除的node
		slow->next = to_delete->next;
		delete to_delete;
		return dummy.next;
```

对于情况1: 

此时`slow`指向的就是dummy node，`to_delete`就是`head`；`slow->next = to_delete->next;` 能够保证`dummy->next`为`nullptr`。



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
	ListNode(int x, ListNode *next) :
					val(x), next(next)
	{
	}
};

class Solution
{
public:
	ListNode* removeNthFromEnd(ListNode *head, int n)
	{
		ListNode dummy { 0, head }; // 使用dummy node技巧
		ListNode *fast = head, *slow = &dummy;
		while (n--)
		{
			fast = fast->next;
		}
		while (fast)
		{
			fast = fast->next;
			slow = slow->next;
		}
		ListNode *to_delete = slow->next; // 待删除的node
		slow->next = to_delete->next;
		delete to_delete;
		return dummy.next;
	}
};

// Driver code
int main()
{
	ListNode *N = new ListNode { 3 };
	N->next = new ListNode { 2 };
	N->next->next = new ListNode { 0 };
	N->next->next->next = new ListNode { 4 };
	Solution s;
	cout << s.removeNthFromEnd(N, 1) << endl;

	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



## [删除链表的倒数第N个节点 # 官方解题](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/)