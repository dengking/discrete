# [LeetCode-24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)



## 我的解题

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

