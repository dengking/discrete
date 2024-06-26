# Merge-sorted-linked-list



## [LeetCode-21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

相同题： [LCR 142. 训练计划 IV](https://leetcode.cn/problems/he-bing-liang-ge-pai-xu-de-lian-biao-lcof/)



### C++迭代

```C++
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode() :
            val(0), next(nullptr) {
    }

    ListNode(int x) :
            val(x), next(nullptr) {
    }

    ListNode(int x, ListNode *next) :
            val(x), next(next) {
    }
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *a, ListNode *b) {
        /**
         * 有一个为空，则无需进行merge
         */
        if (a == nullptr || b == nullptr) {
            return a != nullptr ? a : b;
        }
        /**
         * dummy是"dummy node for create linked list"
         * 需要注意的是它是automatic variable，使用它为了便于创建新的linked list
         * 最终返回的 head.next
         */
        ListNode dummy, *tail = &dummy;
        while (a && b) {
            if (a->val > b->val) {
                tail->next = b;
                b = b->next;
            } else {
                tail->next = a;
                a = a->next;
            }
            tail = tail->next;
        }
        // 将剩余部分也添加到linked list中
        tail->next = a ? a : b;
        return dummy.next;
    }
};

ostream &operator<<(ostream &stream, ListNode *Node) {
    while (Node) {
        stream << Node->val << ",";
        Node = Node->next;
    }
    return stream;
}

int main() {
    ListNode *N1 = new ListNode{1};
    N1->next = new ListNode{3};
    N1->next->next = new ListNode{5};
    N1->next->next->next = new ListNode{7};

    ListNode *N2 = new ListNode{2};
    N2->next = new ListNode{4};
    N2->next->next = new ListNode{6};
    N2->next->next->next = new ListNode{8};

    Solution s;
    cout << s.mergeTwoLists(N1, N2) << endl;
}


```

### Python recursion

递归地定义两个链表里的 merge 操作（忽略边界情况，比如空链表等）：

$$
{\begin{cases}
list1[0] + merge(list1[1:], list2) &list1[0]<list2[0] \\
list2[0] + merge(list1, list2[1:]) &otherwise \\
\end{cases}}
$$
也就是说，两个链表头部值较小的一个节点与剩下元素的 `merge` 操作结果合并。



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

递归写法很简单优雅。

