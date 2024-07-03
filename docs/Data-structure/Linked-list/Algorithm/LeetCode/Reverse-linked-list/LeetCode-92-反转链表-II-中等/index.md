## [LeetCode-92. 反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii/) 

### 迭代法

[LeetCode-反转链表 II # 官方解题](https://leetcode.cn/problems/reverse-linked-list-ii/solution/fan-zhuan-lian-biao-ii-by-leetcode-solut-teyq/) # 方法二：一次遍历「穿针引线」反转链表（头插法）

整体思想是：在需要反转的区间里，每遍历到一个节点，让这个新节点来到反转部分的起始位置。下面的图展示了整个流程。

> NOTE:
>
> 这种反转的思路和之前的递归的思路是完全不同的，它是真的按照平时反转的思路来的。
>
> 它也是基于prev-cur-next来写的，但是算法的执行过程是，每次将next放到反转部分的起始位置，prev始终不同。
>
> 原文把它叫做"头插法"，还是比较生动的。



```c++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>

// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

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
  ListNode *reverseBetween(ListNode *head, int left, int right)
  {
    // 设置 dummyNode 是这一类问题的一般做法
    ListNode *dummyNode = new ListNode(-1);
    dummyNode->next = head;
    ListNode *pre = dummyNode;
    for (int i = 0; i < left - 1; i++)
    {
      pre = pre->next;
    }
    ListNode *cur = pre->next;
    ListNode *next;
    for (int i = 0; i < right - left; i++)
    {
      next = cur->next;
      cur->next = next->next;
      next->next = pre->next;
      pre->next = next;
    }
    return dummyNode->next;
  }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```





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
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(-1, head)
        prev = dummy
        for _ in range(left - 1):
            prev = prev.next
        cur = prev.next
        prev.next, cur.next = self.reverse_linked_list(cur, right - left)
        return dummy.next

    @staticmethod
    def reverse_linked_list(head: Optional[ListNode], node_cnt) -> Tuple[Optional[ListNode], Optional[ListNode]]:
        prev, cur, next_node = None, head, None
        cnt = 0
        while cur:
            if cnt > node_cnt:
                break
            next_node = cur.next
            cur.next = prev
            prev = cur
            cur = next_node
            cnt += 1

        return prev, cur

```



### 递归法

这种方法是直接参考的 labuladong [递归反转链表：如何拆解复杂问题](https://mp.weixin.qq.com/s/5wz_YJ3lTkDH3nWfVDi5SA) 写的。

```c++
// #include <bits/stdc++.h>

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    ListNode *successor_{nullptr};

public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        return reverseBetweenRecursion(head, left, right);
    }

    ListNode *reverseNRecursion(ListNode *head, int cnt) {
        // base case: 最后一个节点
        if (cnt == 1) {
            successor_ = head->next;
            return head;
        } else {
            auto *last = reverseNRecursion(head->next, cnt - 1);
            head->next->next = head;
            head->next = successor_;
            return last;
        }
    }

    ListNode *reverseBetweenRecursion(ListNode *head, int left, int right) {
        // base case
        if (left == 1) {
            return reverseNRecursion(head, right);
        } else {
            head->next = reverseBetweenRecursion(head->next, left - 1, right - 1);
            return head;
        }
    }
};

int main() {
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

