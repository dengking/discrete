# Delete node in linked list



## [LeetCode-19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)

题目条件:

> - 链表中结点的数目为 `sz`
> - `1 <= n <= sz` 

因此无需考虑n大于sz的情况，但是需要考虑`n == sz`的情况(即删除head node)，进一步思考:

- 对于internal node，实现删除倒数第`N`个节点的直观做法是找到倒数第`N`个节点的**前驱节点**(即倒数第`N+1`个节点)，通过它来删除倒数第`N`个节点
- 对于head node，它没有**前驱节点**，因此需要进行特殊处理



那是否有方式能够保证使用相同的逻辑来处理head node、internal node呢？在看了 [删除链表的倒数第N个节点 # 官方解题](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/) 后，其中介绍"dummy node"技巧，它使得每个node都有前驱node:

> 在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），它的 $\textit{next}$ 指针指向链表的头节点。这样一来，我们就不需要对头节点进行特殊的判断了。
>
> 例如，在本题中，如果我们要删除节点 `y`，我们需要知道节点 `y` 的前驱节点 `x`，并将 `x` 的指针指向 `y` 的后继节点。但由于头节点不存在前驱节点，因此我们需要在删除头节点时进行特殊判断。但如果我们添加了哑节点，那么头节点的前驱节点就是哑节点本身，此时我们就只需要考虑通用的情况即可。

使用"dummy node"技巧带来的另外一个好处是: 返回值始终是`dummy->next`，显然这也能够保证代码的统一。

### Python

```python
from typing import *


class ListNode:
    """
    Definition for singly-linked list.
    """

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        dummy = ListNode(-1, head)
        prev = self.getNthFromEnd(dummy, n + 1)
        prev.next = prev.next.next
        return dummy.next

    def getNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        fast = head
        for _ in range(0, n):
            fast = fast.next
        slow = head
        while fast:
            fast = fast.next
            slow = slow.next
        return slow

```



### C++

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





## [LCR 136. 删除链表的节点](https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/) / [LeetCode-剑指 Offer 18. 删除链表的节点](https://leetcode.cn/problems/shan-chu-lian-biao-de-jie-dian-lcof/) 



### Python

```python

class ListNode:
    """
    Definition for singly-linked list.
    """

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        dummy = ListNode(-1, head)
        prev, cur = dummy, head
        while cur:
            if cur.val == val:
                prev.next = cur.next
                break
            else:
                prev = cur
                cur = cur.next
        return dummy.next

```





## [LeetCode-面试题 02.03. 删除中间节点](https://leetcode.cn/problems/delete-middle-node-lcci/)

由于是single linked list，显然每个node只能够access它的next，题目要求是删除node，那么一种实现方式是deep copy next，然后让next代替自己去死，另外一种描述是:

> 既然只能访问当前节点，那就只好出此下策了。杀不掉我，我就变成你，然后再干掉你，就等于杀死了自己。
>
> ```c
> void deleteNode(struct ListNode* node) {
>  node->val = node->next->val;
>  node->next = node->next->next;
> }
> ```

### Python

```python

class ListNode:
    """
    Definition for singly-linked list.
    """

    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val = node.next.val
        node.next = node.next.next

```



### C++

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
	void deleteNode(ListNode *node)
	{
		// 只知道当前节点，

		ListNode *nextNode = node->next;
		*node = *node->next; // deep copy
		delete nextNode;
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
	s.deleteNode(N->next);

	return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

