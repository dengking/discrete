# Reverse-linked-list

实现reverse有如下两种方式:

- action-1: 让current node指向它的previous node
- action-2: 让current node的next node指向current node



## 素材

一、labuladong

[递归反转链表：如何拆解复杂问题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484467&idx=1&sn=beb3ae89993b812eeaa6bbdeda63c494&scene=21#wechat_redirect)

[递归思维：k 个一组反转链表](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484597&idx=1&sn=c603f1752e33cb2701e371d84254aee2&scene=21#wechat_redirect)



## [LeetCode-206. 反转链表-简单](https://leetcode.cn/problems/reverse-linked-list/) 

反转整个linked list



### Previous-current-next-three-pointer-iteration

思路: 基于"previous-current-next-three-pointer-iteration"；让current node的next指向它的previous node。

#### Python

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
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        prev, cur, next_node = None, head, None
        while cur:
            next_node = cur.next  # 先保存next node，因为等一下cur.next会被更新
            cur.next = prev  # 反转current node
            # 向后滑动一个节点
            prev = cur
            cur = next_node
        return prev  # 需要注意的是，返回值是prev，因为上述while退出的时候，cur为nullptr

```



#### C++

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

#### Python

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
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(-1)
        tail = dummy
        stack = []
        node = head
        while node:
            stack.append(node)
            node = node.next
        while stack:
            tail.next = stack.pop()
            tail = tail.next
        # 最后一个结点就是反转前的头结点，一定要让他的next等于空，否则会构成环
        tail.next = None 
        return dummy.next


if __name__ == '__main__':
    vals = [1, 2, 3, 4, 5]
    dummy = ListNode(-1)
    tail = dummy
    for v in vals:
        tail.next = ListNode(v)
        tail = tail.next
    solu = Solution()
    solu.reverseList(dummy.next)

```

#### C++

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
        ListNode dummy = ListNode(), *tail = &dummy;

        while (!stk.empty())
        {
            auto *node = stk.top();
            tail->next = node;
            stk.pop();
            tail = tail->next;
        }
        tail->next = nullptr;
        return dummy.next;
    }
};

int main()
{
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```



### DFS-pre-order

下面递归版本的实现，相较于 [官方解题](https://leetcode.cn/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode-solution-d1k2/) 中的递归版本是更加容易理解的，它和迭代版本有着较好的对应。

#### Python

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
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        return self.dfsPreOrder(None, head)

    def dfsPreOrder(self, prev: Optional[ListNode], cur: Optional[ListNode]):
        if cur:
            next_node = cur.next
            cur.next = prev
            return self.dfsPreOrder(cur, next_node)
        else:
            return prev  # 需要注意的是，返回值是prev，因为此时cur为nullptr，这和迭代版是对应的

```



#### C++

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



## [LeetCode-92. 反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii/)

反转部分linked list



## [LeetCode-25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/)

k个一组反转

### 反转后与原链表连接

对于反转这个linked list，不需要考虑这个问题，但是对于反转linked list中的一部分，则需要考虑这个问题，在下面的题目中都涉及这个问题:

1、[LeetCode-92. 反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii/)

2、[LeetCode-25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/)

在labuladong的两篇文章中都涉及这个内容。