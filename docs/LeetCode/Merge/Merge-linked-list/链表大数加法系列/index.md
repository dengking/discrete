# 链表大数加法系列



LeetCode-2-两数相加、LeetCode-445-两数相加-II 本质上考察的都是"两两合并linked list"，下面是最简洁版本的代码:

```c++

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy_head{};
        ListNode *tail = &dummy_head;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int val1 = l1 ? l1->val : 0;
            int val2 = l2 ? l2->val : 0;
            int sum = val1 + val2 + carry;
            tail->next = new ListNode{sum % 10};
            carry = sum / 10;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;

            tail = tail->next;
        }

        return dummy_head.next;
    }
};


```

