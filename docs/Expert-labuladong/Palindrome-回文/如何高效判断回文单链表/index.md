# labuladong [如何高效判断回文单链表？](https://mp.weixin.qq.com/s/tCgEoOlZKS_ohuTx1VxJ-Q)

## 一、判断回文单链表

> NOTE: 
>
> LeetCode [234. 回文链表](https://leetcode-cn.com/problems/palindrome-linked-list/) 简单

输入一个单链表的头结点，判断这个链表中的数字是不是回文：

```c++
/**
 * 单链表节点的定义：
 * public class ListNode {
 *     int val;
 *     ListNode next;
 * }
 */

boolean isPalindrome(ListNode head);

输入: 1->2->null
输出: false

输入: 1->2->2->1->null
输出: true
```

这道题的难点在于，单链表无法倒着遍历，无法使用双指针技巧。那么最简单的办法就是，把原始链表反转存入一条新的链表，然后比较这两条链表是否相同。关于如何反转链表，可以参见前文 [递归思维：k 个一组反转链表](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484597&idx=1&sn=c603f1752e33cb2701e371d84254aee2&chksm=9bd7fabdaca073abd512d8fff18016c9092ede45fed65c307852c65a2026d8568ee294563c78&scene=21#wechat_redirect)。

其实，**借助二叉树后序遍历的思路，不需要显式反转原始链表也可以倒序遍历链表**，下面来具体聊聊。

对于二叉树的几种遍历方式，我们再熟悉不过了：

```Java
void traverse(TreeNode root) {
    // 前序遍历代码
    traverse(root.left);
    // 中序遍历代码
    traverse(root.right);
    // 后序遍历代码
}
```

在 [学习数据结构的框架思维](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484520&idx=1&sn=2c6507c7f25c0fd29fd1d146ee3b067c&chksm=9bd7fa60aca073763785418d15ed03c9debdd93ca36f4828fa809990116b1e7536c3f68a7b71&scene=21#wechat_redirect) 中说过，链表兼具递归结构，树结构不过是链表的衍生。那么，**链表其实也可以有前序遍历和后序遍历**：

```Java
void traverse(ListNode head) {
    // 前序遍历代码
    traverse(head.next);
    // 后序遍历代码
}
```

这个框架有什么指导意义呢？如果我想正序打印链表中的`val`值，可以在前序遍历位置写代码；反之，如果想倒序遍历链表，就可以在后序遍历位置操作：

```Java
/* 倒序打印单链表中的元素值 */
void traverse(ListNode head) {
    if (head == null) return;
    traverse(head.next);
    // 后序遍历代码
    print(head.val);
}
```

> NOTE: 
>
> 参见LeetCode [剑指 Offer 06. 从尾到头打印链表](https://leetcode-cn.com/problems/cong-wei-dao-tou-da-yin-lian-biao-lcof/)

说到这了，其实可以稍作修改，模仿双指针实现回文判断的功能：

```Java
// 左侧指针
ListNode left;

boolean isPalindrome(ListNode head) {
    left = head;
    return traverse(head);
}

boolean traverse(ListNode right) {
    if (right == null) return true;
    boolean res = traverse(right.next);
    // 后序遍历代码
    res = res && (right.val == left.val);
    left = left.next;
    return res;
}
```

这么做的核心逻辑是什么呢？**实际上就是把链表节点放入一个栈，然后再拿出来，这时候元素顺序就是反的**，只不过我们利用的是递归函数的堆栈而已。

![图片](https://mmbiz.qpic.cn/sz_mmbiz_gif/gibkIz0MVqdFIu7T79GYa24TTib9YP1dZicqkFgB2NwpsHXOdKu0XnwoVK7JeQ055fCQOKDJFEVjzvsfzibWAvIeLA/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

当然，无论造一条反转链表还是利用后续遍历，算法的时间和空间复杂度都是 O(N)。下面我们想想，能不能不用额外的空间，解决这个问题呢？

## 二、优化空间复杂度

更好的思路是这样的：

**1、先通过 [双指针技巧汇总](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484505&idx=1&sn=0e9517f7c4021df0e6146c6b2b0c4aba&chksm=9bd7fa51aca07347009c591c403b3228f41617806429e738165bd58d60220bf8f15f92ff8a2e&scene=21#wechat_redirect) 中的快慢指针来找到链表的中点**：

```Java
ListNode slow, fast;
slow = fast = head;
while (fast != null && fast.next != null) {
    slow = slow.next;
    fast = fast.next.next;
}
// slow 指针现在指向链表中点
```

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFIu7T79GYa24TTib9YP1dZicCGiata7htZPVyrFNPk4Tibic83iaq1DmJVicMXt4URwRUKcRicYrrnrwYXIg/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**2、如果`fast`指针没有指向`null`，说明链表长度为奇数，`slow`还要再前进一步**：

```Java
if (fast != null)
    slow = slow.next;
```

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFIu7T79GYa24TTib9YP1dZickT4icgG7YLssKOKxNtzp74uuD7VlJVyDZaMWmu2jdJ1FmzLsev6emDw/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**3、从`slow`开始反转后面的链表，现在就可以开始比较回文串了**：

```c++
ListNode left = head;
ListNode right = reverse(slow);

while (right != null) {
    if (left.val != right.val)
        return false;
    left = left.next;
    right = right.next;
}
return true;
```

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFIu7T79GYa24TTib9YP1dZictrBKow5sY1kECHOqvquzXAOic47urrMPiaHCc1EQRP9ZVdJMRhicaGfCw/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

至此，把上面 3 段代码合在一起就高效地解决这个问题了，其中`reverse`函数很容易实现：

```java
ListNode reverse(ListNode head) {
    ListNode pre = null, cur = head;
    while (cur != null) {
        ListNode next = cur.next;
        cur.next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
```



![图片](https://mmbiz.qpic.cn/sz_mmbiz_gif/gibkIz0MVqdFIu7T79GYa24TTib9YP1dZicjx1NMicBficfsTHsdibqbjxEvgvBia4aTjqgk6UojuNhMCWllAa0ZlsedA/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

算法总体的时间复杂度 O(N)，空间复杂度 O(1)，已经是最优的了。

我知道肯定有读者会问：这种解法虽然高效，但破坏了输入链表的原始结构，能不能避免这个瑕疵呢？

其实这个问题很好解决，关键在于得到`p, q`这两个指针位置：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFIu7T79GYa24TTib9YP1dZicu5uqicqfTvK3cibySCqAqAnLGlAk5MzWN7WoibibKhFqzetKCMgicN2jOGQ/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



这样，只要在函数 return 之前加一段代码即可恢复原先链表顺序：

```c++
p.next = reverse(q);
```

篇幅所限，我就不写了，读者可以自己尝试一下。

## 三、最后总结

首先，寻找回文串是从中间向两端扩展，判断回文串是从两端向中间收缩。

> NOTE: 
>
> 总结的非常好
