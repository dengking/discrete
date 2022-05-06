# labuladong [递归反转链表：如何拆解复杂问题](https://mp.weixin.qq.com/s/5wz_YJ3lTkDH3nWfVDi5SA)

> NOTE: 
>
> leetcode [92. 反转链表 II](https://leetcode-cn.com/problems/reverse-linked-list-ii/) 中等





```java
ListNode reverse(ListNode head) {
    if (head.next == null) return head; // 如果是tail，则直接返回
    ListNode last = reverse(head.next); // 递归调用
    head.next.next = head; // 将当前节点作为它的next的next
    head.next = null; // 将当前节点作为tail
    return last;
}
```

> NOTE: 
>
> 上述是典型的借助system stack来进行反转，在整个调用栈栈，`last`的值会一直保持不变: 指向原来的tail，显然最终执行完成后，上述函数的返回值就是last，也就是指向原来的最后一个节点，现在它是新的head了。
>
> 递归函数体，所做的工作其实如下:
>
> ```c++
>     head.next.next = head; // 将当前节点作为它的next的next
>     head.next = null; // 将当前节点作为tail
> ```
>
> 简而言之: 让current node `head`作为它的`next` 的`next`，其实这就实现了反转: 原本你是我的next，现在我是你的next。其实上述算法的执行过程有一点: append-to-tail的意味。
>
> 

