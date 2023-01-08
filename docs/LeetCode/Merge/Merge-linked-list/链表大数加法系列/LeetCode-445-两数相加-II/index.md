# [LeetCode-445. 两数相加 II](https://leetcode.cn/problems/add-two-numbers-ii/) 



## 我的解题



```c++
#include <stack>
#include <iostream>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

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
    ListNode dummy_head{};

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        std::stack<ListNode *> stk1 = push2Stack(l1), stk2 = push2Stack(l2);

        int curry = 0; // 进位
        while (!stk1.empty() && !stk2.empty())
        {
            l1 = stk1.top(), l2 = stk2.top();

            int sum = l1->val + l2->val + curry;
            pushNewNode(sum % 10);
            curry = sum / 10;

            stk1.pop(), stk2.pop();
        }
        while (!stk1.empty() || !stk2.empty())
        {
            l1 = !stk1.empty() ? stk1.top() : stk2.top();

            int sum = l1->val + curry;
            pushNewNode(sum % 10);
            curry = sum / 10;

            !stk1.empty() ? stk1.pop() : stk2.pop();
        }
        if (curry)
        {
            pushNewNode(curry);
        }
        return dummy_head.next;
    }

    std::stack<ListNode *> push2Stack(ListNode *node)
    {
        std::stack<ListNode *> stk;
        for (; node; node = node->next)
        {
            stk.push(node);
        }
        return stk;
    }
    void pushNewNode(int val)
    {
        ListNode *node = new ListNode(val);
        node->next = dummy_head.next;
        dummy_head.next = node;
    }
};

int main()
{
}

```

