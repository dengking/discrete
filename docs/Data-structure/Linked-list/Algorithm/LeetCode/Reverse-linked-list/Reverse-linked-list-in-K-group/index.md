# Reverse Nodes in k-Group



[LeetCode-25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/) 是对 [LeetCode-24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/) 的推广。



## [LeetCode-24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)



### C++

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



## [LeetCode-25. K 个一组翻转链表](https://leetcode.cn/problems/reverse-nodes-in-k-group/) 



### C++

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

