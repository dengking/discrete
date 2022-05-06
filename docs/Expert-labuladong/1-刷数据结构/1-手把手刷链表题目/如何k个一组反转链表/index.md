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