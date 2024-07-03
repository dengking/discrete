# Reverse-linked-list

实现reverse有如下两种方式:

- action-1: 让current node指向它的previous node
- action-2: 让current node的next node指向current node



## 素材

一. labuladong

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

这种做法本质上是: 从前往后逐个反转。

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

不更改未access过的node的结构，显然，当执行到current node的时候，它的successors已经被access过了，因此可以修改successor的结构，因此使用action-2: 让current node的next node指向current node; 

这种做法本质上是: 从后往前逐个反转。先将所有的node都堆到系统栈中，然后逐个修改；

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
        return self.dfsPostOrder(head)

    def dfsPostOrder(self, node: Optional[ListNode]) -> Optional[ListNode]:
        if node:
            if node.next:  # head node + internal node
                head = self.dfsPostOrder(node.next)
                node.next.next = node
                node.next = None
                return head
            else:
                return node  # tail node，它将成为新的head node
        else:  # 其实这个分支永远也执行不到
            return node

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
        return dfsPostOrder(head);
    }
    ListNode *dfsPostOrder(ListNode *cur)
    {
        if (cur)
        {
            if (cur->next) // internal node
            {
                auto *tail = dfsPostOrder(cur->next);
                cur->next->next = cur; //  让current node的next node指向current node
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



## [LeetCode-剑指 Offer 06. 从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)



这道题的下面解法是最最能够体现: explicit stack VS recursion implicit stack 的。



### DFS-post-order

在post action中，执行insert。

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
    def reverseBookList(self, head: Optional[ListNode]) -> List[int]:
        ans = []
        self.dfsPostOrder(head, ans)
        return ans

    def dfsPostOrder(self, node: Optional[ListNode], ans: List[int]):
        if node:
            self.dfsPostOrder(node.next, ans)
            ans.append(node.val)

```



#### C++

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

### Reverse by explicit stack

#### C++

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



## Reverse Nodes in k-Group



[LeetCode-25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/) 是对 [LeetCode-24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/) 的推广。



### [LeetCode-24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)



#### C++

这是参考的labuladong [递归思维：k 个一组反转链表](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484597&idx=1&sn=c603f1752e33cb2701e371d84254aee2&scene=21#wechat_redirect) 写的

```c++
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
    ListNode *swapPairs(ListNode *head)
    {
        ListNode *itor = head;
        for (int i = 0; i < 2; ++i)
        {
            if (itor)
            {
                itor = itor->next;
            }
            else
            {
                return head;
            }
        }
        ListNode *newHead = reverse(head, itor);
        ListNode *tail = head;
        tail->next = swapPairs(itor);
        return newHead;
    }
    /// @brief
    /// @param begin
    /// @param end
    /// @return
    ListNode *reverse(ListNode *begin, ListNode *end)
    {
        ListNode *prev = nullptr, *cur = begin, *next = nullptr;
        while (cur != end)
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



### [LeetCode-25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/) 

属于典型的"k-step步长-span跨度-stride跨度-traverse"

基本操作: 找到一个K group的head、stop node，反转这个K group得到new head、new tail，new tail的next是下一个K group的new head，显然这是一个递归调用。



#### DFS-pre-order-action

##### Python

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
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        """
        DFS-pre-order-action
        返回反转后的linked list的head
        """
        stop_node = head  # 当前k group的stop node()
        for _ in range(k):
            if stop_node:
                stop_node = stop_node.next
            else:  # 题目要求: 不足k个则不反转，所以直接返回
                return head
        # 此时stop_node指向的是第k+1个node
        # 左闭右开[head, stop_node)
        new_head = self.reverse_linked_list(head, stop_node)
        new_tail = head  # 原来的head在经过反转后成为了tail
        new_tail.next = self.reverseKGroup(stop_node, k)  # 与原链表连接在一起
        return new_head

    @staticmethod
    def reverse_linked_list(head: Optional[ListNode], stop_node: Optional[ListNode]):
        """
        左闭右开[head, stop_node)
        """
        prev, cur, next_node = None, head, None
        while cur != stop_node:
            next_node = cur.next
            cur.next = prev
            prev = cur
            cur = next_node
        return prev


if __name__ == '__main__':
    head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
    solu = Solution()
    solu.reverseKGroup(head, 2)

```



##### C++

这是参考的labuladong [递归思维：k 个一组反转链表](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484597&idx=1&sn=c603f1752e33cb2701e371d84254aee2&scene=21#wechat_redirect) 写的

因为题目要求不足k个node的时候不反转，因此不能够使用"计数+tail node"的方式来判断是否停止reverse，而是只能够通过计数节点个数来决定是否进行反转。

```c++
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
    /// @brief
    /// @param head
    /// @param k
    /// @return head node
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *itor = head;
        for (int i = 0; i < k; i++) // 先判断是否有k个节点，如果不足k个节点，则不反转
        {
            if (itor)
            {
                itor = itor->next;
            }
            else // 从head开始的节点数，不足k个，在这种情况下直接返回，不需要进行反转
            {
                return head;
            }
        } // 当退出这个循环的时候，itor所指向的是第k个节点的next

        auto *newHead = reverse(head, itor);
        ListNode *tail = head;               // 原来的head在经过反转后成为了tail
        tail->next = reverseKGroup(itor, k); // 与原链表连接在一起
        return newHead;
    }
    /// @brief
    /// @param head
    /// @param end 不包括end，和c++的begin、end一样
    /// @return
    ListNode *reverse(ListNode *head, ListNode *end)
    {
        ListNode *prev = nullptr, *cur = head, *next = nullptr;
        while (cur != end)
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

