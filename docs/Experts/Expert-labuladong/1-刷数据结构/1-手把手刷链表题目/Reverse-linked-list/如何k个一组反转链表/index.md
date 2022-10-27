# labuladong [递归思维：k 个一组反转链表](https://mp.weixin.qq.com/s/A-dQ9spsP_Iu1Y4iCRP9nA)



## 二、代码实现

首先，我们要实现一个 `reverse` 函数反转一个区间之内的元素。在此之前我们再简化一下，给定链表头结点，如何反转整个链表？

```c++
// 反转以 a 为头结点的链表
ListNode reverse(ListNode a) {
    ListNode pre, cur, nxt;
    pre = null; cur = a; nxt = a;
    while (cur != null) {
        nxt = cur.next;
        // 逐个结点反转
        cur.next = pre;
        // 更新指针位置
        pre = cur;
        cur = nxt;
    }
    // 返回反转后的头结点
    return pre;
}
```

这次使用迭代思路来实现的，借助动画理解应该很容易。

![图片](https://mmbiz.qpic.cn/mmbiz_gif/gibkIz0MVqdGFib5uibU7BTZ15CaCmm3kgq1LjFMHR1jU0ETJvWLnFrwOt7pE8XULlodkZ7sEB5kicybRp1VrCVuFQ/640?wx_fmt=gif&wxfrom=5&wx_lazy=1)

```Java
/** 反转区间 [a, b) 的元素，注意是左闭右开 */
ListNode reverse(ListNode a, ListNode b) {
    ListNode pre, cur, nxt;
    pre = null; cur = a; nxt = a;
    // while 终止的条件改一下就行了
    while (cur != b) {
        nxt = cur.next;
        cur.next = pre;
        pre = cur;
        cur = nxt;
    }
    // 返回反转后的头结点
    return pre;
}
```

现在我们迭代实现了反转部分链表的功能，接下来就按照之前的逻辑编写 `reverseKGroup` 函数即可：

```Java
ListNode reverseKGroup(ListNode head, int k) {
    if (head == null) return null;
    // 区间 [a, b) 包含 k 个待反转元素
    ListNode a, b;
    a = b = head;
    for (int i = 0; i < k; i++) {
        // 不足 k 个，不需要反转，base case
        if (b == null) return head;
        b = b.next;
    }
    // 反转前 k 个元素
    ListNode newHead = reverse(a, b);
    // 递归反转后续链表并连接起来
    a.next = reverseKGroup(b, k);
    return newHead;
}
```

解释一下 `for` 循环之后的几句代码，注意 `reverse` 函数是反转区间 `[a, b)`，所以情形是这样的：

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/gibkIz0MVqdGFib5uibU7BTZ15CaCmm3kgqtDjCXg5iaw3nOkT3agMCOWxu2qdRniamDk33TiasiaLxY2gCtSDfNLJFRw/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

