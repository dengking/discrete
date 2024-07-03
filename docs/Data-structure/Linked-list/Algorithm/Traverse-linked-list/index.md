# Traverse linked list

本节内容是 `Traverse-structure` 中关于linked list的章节。

linked list的结构非常简单，并且只支持 [sequential access](https://en.wikipedia.org/wiki/Sequential_access)，因此它的很多算法都是基于traverse的，所以本节首先介绍linked list的traverse的技巧。

## 最基本的traverse方式

### 范围区间 / 起和止

我们平常遇到的大多数都是对整个linked list进行操作，但是是存在对linked list的部分操作的(比如 [LeetCode-25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/) )，因此需要考虑最通用的情况，总结出能够处理这两种case的通用的框架；这正如对整个array、部分array进行操作。

我们可以进行类比: 

array支持random access，可以通过index进行access，因此它的范围一般都是通过start index(begin)、stop index(end)来进行界定，既然使用了**区间**的概念，那么就需要考虑**区间**是**左闭右闭**还是**左闭右开**，并且区间的定义需要在程序中始终保持统一(典型的例子就是binary search)；

具体到linked list，它的范围一般使用 start node(begin) 和stop  node(end)来进行界，一般使用的是 **左闭右开**:

- 处理整个linked list的算法，显然它使用head作为start node，这种情况的stop  node显然就是null，因此可以不传
- 处理部分linked list的算法，显然它使用head作为start node，另外需要特别指定end node



### 算法总结

| 方向       | 从左到右-从首到尾                             | 从右到左-从尾到首 |
| ---------- | --------------------------------------------- | ----------------- |
| **迭代版** | previous-current-next-three-pointer-iteration | explici-stack     |
| **递归版** | DFS-pre-order                                 | DFS-post-order    |

1. 上述**递归版**是对**基础版**的递归实现，我们可以看出它们的内在关系

2. 上述两个递归版可以扩张对递归的认知，在后面会进行详细的对比

3. [LeetCode-206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/) 是最好的例子，其中可以使用上述这些例子

   

### 从左到右-从首到尾-迭代(iteration)

#### Foreach-node

TODO: 这种方式是最简单的迭代

书写迭代的时候，一个很重要的点就是stop condition，由于linked list是由node构成，并且这种pattern的名称为"foreach-node"，所以使用"stop node"这个词，显然当使用这种模式来处理整个linked list的时候，stop node是null。

#### Pattern: dummy node+prev cur next三指针

TODO: 总结这种算法模式

[LeetCode-206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/) 是最好的例子:

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

stop condition: 遍历完了整个list，即最终`cur`指向的是null。



### 从右到左-从尾到首-explici-stack

#### Practice

在下面题目中使用了这种technique:

[LeetCode-剑指 Offer 06. 从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)  



[LeetCode-445. 两数相加 II](https://leetcode.cn/problems/add-two-numbers-ii/) 



### DFS

对于linked list，它的结构非常简单，它只有DFS，也就是常说的递归方式

素材: 

- labuladong [递归反转链表：如何拆解复杂问题](https://mp.weixin.qq.com/s/5wz_YJ3lTkDH3nWfVDi5SA) 

- labuladong [如何高效判断回文单链表？](https://mp.weixin.qq.com/s/tCgEoOlZKS_ohuTx1VxJ-Q) 



#### 从左到右-从首到尾-DFS-pre-order

1. 这种写法是比较容易理解的，因为它符合"previous-current-next-three-pointer-iteration"

2. pre-order-action

##### Practice

[LeetCode-206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/) 

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

[LeetCode-25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/) 

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



#### 从右到左-从尾到首-DFS-post-order

1、最最简单的例题就是: [LeetCode-剑指 Offer 06. 从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/) ，这道题要求将linked list逆序装入到vector中，它将此放到了post-order-acion中

2、这种写法我是在 [labuladong-递归反转链表：如何拆解复杂问题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484467&idx=1&sn=beb3ae89993b812eeaa6bbdeda63c494&scene=21#wechat_redirect) 中发现的，相较于 "从左到右-从首到尾-DFS-pre-order" 版本，这个版本的代码是不容易理解的、非常经典。它本质上也是符合"prev-cur-next"，递归体内每次对next进行修改: 将`next->next` 替换为`cur`，这样就完成了反转。它的运行过程有些类似于: append-to-tail。



#### 对比

一、下面两种递归写法都属于DFS+return-value，它们具有如下相同点:

1、两个版本的stop condition都是tail-node

2、两个版本的return value都是tail-node，因为tail-node是新的head

三、DFS linked list的执行过程如下:

1、入栈: 从head到tail(从左到右)

2、出栈: 从tail到head(从右到左)

显然存在两个方向，下面据此对上述两种算法进行详细对比分析:

1、DFS-pre-order : 

a、在入栈方向执行action，从head node开始执行action。

b、只能够采用action-1，从左到右-从首到尾修改linked-list的结构；

如果采用action-2，那么它会提前修改为访问节点的结构，这样当访问已经被修改的节点的时候，就无法得到它原本的next，此时会导致陷入dead-loop。

2、DFS-post-order: 

a、在出栈方向执行action，从tail node开始执行action。

b、只能够采用action-2，从右向左-从尾到首修改linked-list的结构；

无法采用action-1，因为这是single-linked-list，它无法access到它的previous node。





#### Practice

[LeetCode-21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/) 

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
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        """
        两个链表头部值较小的一个节点与剩下元素的 `merge` 操作结果合并。
        """
        if list1 is None:
            return list2
        if list2 is None:
            return list1
        if list1.val < list2.val:
            list1.next = self.mergeTwoLists(list1.next, list2)
            return list1
        else:
            list2.next = self.mergeTwoLists(list1, list2.next)
            return list2

```



[LeetCode-206. 反转链表](https://leetcode.cn/problems/reverse-linked-list/) 



[LeetCode-234. 回文链表-简单](https://leetcode.cn/problems/palindrome-linked-list/) 





### 对比: 从右到左-从尾到首

1、这种本质上都是基于stack: 

explicit stack VS recursion implicit stack

2、体现两者差别的最最典型的例题就是: [LeetCode-剑指 Offer 06. 从尾到头打印链表](https://leetcode.cn/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)  









## 高级的traverse方式



### Fast-slow-double-pointer

快慢双指针

TODO: 需要补充相关内容

#### Practice

[LeetCode-19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/) 

### k-step步长-span跨度-stride跨度-traverse

k个一组 k group

#### Practice

[LeetCode-25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/) 

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



### k-way-traverse

"k-way"即"多路"，表示同时traverse多个linked-list



### 从两边到中间相向而行、from sides to middle

一、回文式、消消乐

最最典型的就是回文链表，参见:

1、labuladong [如何高效判断回文单链表？](https://mp.weixin.qq.com/s/tCgEoOlZKS_ohuTx1VxJ-Q) 
