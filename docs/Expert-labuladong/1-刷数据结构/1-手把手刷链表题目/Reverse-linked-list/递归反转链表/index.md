# labuladong [递归反转链表：如何拆解复杂问题](https://mp.weixin.qq.com/s/5wz_YJ3lTkDH3nWfVDi5SA) 

> NOTE: 
>
> 一、循序渐进:
>
> 从反转整个链表->反转链表前N个节点->反转链表的一部分
>
> 不断地进行泛化推广。
>
> 二、原题
>
> [LeetCode-92. 反转链表 II](https://leetcode.cn/problems/reverse-linked-list-ii/) 中等



## 一、递归反转整个链表

```java
ListNode reverse(ListNode head) {
    if (head.next == null) return head; // 如果是tail，则直接返回
    ListNode last = reverse(head.next); // 递归调用
    head.next.next = head; // 将当前节点作为它的next的next
    head.next = null; // 将当前节点作为tail
    return last;
}
```

看起来是不是感觉不知所云，完全不能理解这样为什么能够反转链表？这就对了，这个算法常常拿来显示递归的巧妙和优美，我们下面来详细解释一下这段代码。

> NOTE: 
>
> 上述是典型的借助system stack来进行反转，在整个调用栈中，`last`的值会一直保持不变: 指向原来的tail，显然最终执行完成后，上述函数的返回值就是last，也就是指向原来的最后一个节点，现在它是新的head了。
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

递归代码就是这么简洁优雅，不过其中有两个地方需要注意：

**1、递归函数要有 base case**，也就是这句：

```
if (head.next == null) return head;
```

意思是如果链表只有一个节点的时候反转也是它自己，直接返回即可。

**2、当链表递归反转之后，新的头节点是`last`，而之前的`head`变成了最后一个节点，别忘了链表的末尾要指向 null：**

```
head.next = null;
```

理解了这两点后，我们就可以进一步深入了，接下来的问题其实都是在这个算法上的扩展。

## 二、反转链表前 N 个节点



```java
ListNode successor = null; // 后驱节点

// 反转以 head 为起点的 n 个节点，返回新的头结点
ListNode reverseN(ListNode head, int n) {
    if (n == 1) { 
        // 记录第 n + 1 个节点
        successor = head.next;
        return head;
    }
    // 以 head.next 为起点，需要反转前 n - 1 个节点
    ListNode last = reverseN(head.next, n - 1);

    head.next.next = head;
    // 让反转之后的 head 节点和后面的节点连起来
    head.next = successor;
    return last;
}  
```



具体的区别：

1、base case 变为`n == 1`，反转一个元素，就是它本身，同时**要记录后驱节点**。

2、刚才我们直接把`head.next`设置为 null，因为整个链表反转后原来的`head`变成了整个链表的最后一个节点。但现在`head`节点在递归反转之后不一定是最后一个节点了，所以要记录后驱`successor`（第 n + 1 个节点），反转之后将`head`连接上。

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/map09icNxZ4lC6h97zG2q2kzKZMxfOeBiblQlxWzxErtKXPHsq9jjS3nnEMY7V0CooOQSia4DQ0Z9SXBMNy3soePA/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

OK，如果这个函数你也能看懂，就离实现「反转一部分链表」不远了。

## 三、反转链表的一部分

现在解决我们最开始提出的问题，给一个索引区间`[m,n]`（索引从 1 开始），仅仅反转区间中的链表元素。

```java
ListNode reverseBetween(ListNode head, int m, int n)
```

首先，如果`m == 1`，就相当于反转链表开头的`n`个元素嘛，也就是我们刚才实现的功能：

```java
ListNode reverseBetween(ListNode head, int m, int n) {
    // base case
    if (m == 1) {
        // 相当于反转前 n 个元素
        return reverseN(head, n);
    }
    // ...
}
```

如果`m != 1`怎么办？如果我们把`head`的索引视为 1，那么我们是想从第`m`个元素开始反转对吧；如果把`head.next`的索引视为 1 呢？那么相对于`head.next`，反转的区间应该是从第`m - 1`个元素开始的；那么对于`head.next.next`呢……

区别于迭代思想，这就是递归思想，所以我们可以完成代码：

```java
ListNode reverseBetween(ListNode head, int m, int n) {
    // base case
    if (m == 1) {
        return reverseN(head, n);
    }
    // 前进到反转的起点触发 base case
    head.next = reverseBetween(head.next, m - 1, n - 1);
    return head;
}
```

> NOTE:
>
> 一、整体思路: 首先这道题区间是闭区间: `[m, n]`；首先向前走m步，当m的值为1的时候，就开始反转链表: `reverseN`，这个函数会返回新的head。
>
> 反转链表的一部分其实是比较复杂的: 新链表的首尾需要和原链表进行连接，上述算法的实现方式是: `reverseN` 会返回新链表的head，这样就能够和原链表的左侧链接上；新链表的尾部如何原链表的右边链接上呢？这是在`reverseN`中实现的，它是通过记录 `successor` 来实现的。
>
> 二、单链表具有非常好的递归性

至此，我们的最终大 BOSS 就被解决了。