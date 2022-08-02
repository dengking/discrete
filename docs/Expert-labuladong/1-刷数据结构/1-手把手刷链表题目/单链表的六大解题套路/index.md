# [labuladong-单链表的六大解题套路，你都见过么？](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492022&idx=1&sn=35f6cb8ab60794f8f52338fab3e5cda5&scene=21#wechat_redirect)



### 单链表的中点

力扣第 876 题「链表的中间结点」就是这个题目，问题的关键也在于我们无法直接得到单链表的长度`n`，常规方法也是先遍历链表计算`n`，再遍历一次得到第`n / 2`个节点，也就是中间节点。

如果想一次遍历就得到中间节点，也需要耍点小聪明，使用「快慢指针」的技巧：

我们让两个指针`slow`和`fast`分别指向链表头结点`head`。

**每当慢指针`slow`前进一步，快指针`fast`就前进两步，这样，当`fast`走到链表末尾时，`slow`就指向了链表中点**。

上述思路的代码实现如下：

```Java
ListNode middleNode(ListNode head) {
    // 快慢指针初始化指向 head
    ListNode slow = head, fast = head;
    // 快指针走到末尾时停止
    while (fast != null && fast.next != null) {
        // 慢指针走一步，快指针走两步
        slow = slow.next;
        fast = fast.next.next;
    }
    // 慢指针指向中点
    return slow;
}
```

> NOTE: 
>
> fast-slow double pointer是由fast pointer driven的



### 判断链表是否包含环

判断单链表是否包含环属于经典问题了，解决方案也是用快慢指针：

每当慢指针`slow`前进一步，快指针`fast`就前进两步。

如果`fast`最终遇到空指针，说明链表中没有环；如果`fast`最终和`slow`相遇，那肯定是`fast`超过了`slow`一圈，说明链表中含有环。

只需要把寻找链表中点的代码稍加修改就行了：

```java
boolean hasCycle(ListNode head) {
    // 快慢指针初始化指向 head
    ListNode slow = head, fast = head;
    // 快指针走到末尾时停止
    while (fast != null && fast.next != null) {
        // 慢指针走一步，快指针走两步
        slow = slow.next;
        fast = fast.next.next;
        // 快慢指针相遇，说明含有环
        if (slow == fast) {
            return true;
        }
    }
    // 不包含环
    return false;
}
```

> NOTE: 
>
> fast-slow double pointer是由fast pointer driven的

### 两个链表是否相交

> NOTE:
>
> 交集
>
> 相交就是它们走的步数一致。



**所以，解决这个问题的关键是，通过某些方式，让`p1`和`p2`能够同时到达相交节点`c1`**。

所以，我们可以让`p1`遍历完链表`A`之后开始遍历链表`B`，让`p2`遍历完链表`B`之后开始遍历链表`A`，这样相当于「逻辑上」两条链表接在了一起。

如果这样进行拼接，就可以让`p1`和`p2`同时进入公共部分，也就是同时到达相交节点`c1`：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdGoIXpCDNue8TovkIpicbGFuyA11ayHc2up3QicibicY2vgnktI9HNV51RavzbFz1JlPmlPAXO9GoDcKw/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

按照这个思路，可以写出如下代码：

```java
ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    // p1 指向 A 链表头结点，p2 指向 B 链表头结点
    ListNode p1 = headA, p2 = headB;
    while (p1 != p2) {
        // p1 走一步，如果走到 A 链表末尾，转到 B 链表
        if (p1 == null) p1 = headB;
        else            p1 = p1.next;
        // p2 走一步，如果走到 B 链表末尾，转到 A 链表
        if (p2 == null) p2 = headA;
        else            p2 = p2.next;
    }
    return p1;
}
```