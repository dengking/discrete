# Dummy node技巧

LeetCode中single-linked-list类题目主要有如下两种模式:

一、对已有的single-linked-list进行修改并返回修改后的single-linked-list

二、创建一个新的single-linked-list

对于上述两种情况，都可以使用dummy-node技巧来简化代码:

1、新的linked-list始终都是 `dummy->next` 

2、避免对空指针进行讨论

3、凑齐 "prev-cur-next-三指针-iteration" 

## "dummy node"翻译为"虚拟头节点"

按照字面意思"dummy"的意思是"虚设的、形式的"，其实本质上来说，"dummy node"的确是"虚设的头节点"，它相当于一个**占位符**，包装总是有这样的一个节点在，在 labuladong [单链表的六大解题套路，你都见过么？](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492022&idx=1&sn=35f6cb8ab60794f8f52338fab3e5cda5&scene=21#wechat_redirect)  中，将其称之为"虚拟头节点"，这个翻译更加准确。



## 素材



1、[LeetCode-19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/) # [官方解题](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/) 

2、 labuladong [单链表的六大解题套路，你都见过么？](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492022&idx=1&sn=35f6cb8ab60794f8f52338fab3e5cda5&scene=21#wechat_redirect) 



> **代码中还用到一个链表的算法题中是很常见的「虚拟头节点」技巧，也就是`dummy`节点**。你可以试试，如果不使用`dummy`虚拟节点，代码会复杂很多，而有了`dummy`节点这个**占位符**，可以避免处理空指针的情况，降低代码的复杂性。



> 不过注意我们又使用了虚拟头结点的技巧，也是为了防止出现空指针的情况，比如说链表总共有 5 个节点，题目就让你删除倒数第 5 个节点，也就是第一个节点，那按照算法逻辑，应该首先找到倒数第 6 个节点。但第一个节点前面已经没有节点了，这就会出错。
>
> 但有了我们虚拟节点`dummy`的存在，就避免了这个问题，能够对这种情况进行正确的删除。



3、stackoverflow [Dummy nodes in linked lists](https://stackoverflow.com/questions/22952882/dummy-nodes-in-linked-lists)

4、yuanbin [Linked List - 链表](https://algorithm.yuanbin.me/zh-hans/basics_data_structure/linked_list.html#dummy-node)

5、reddit [[C+] In a linked list what is a dummy node?](https://www.reddit.com/r/learnprogramming/comments/20e0yc/c_in_a_linked_list_what_is_a_dummy_node/)



## 一、对已有的single-linked-list进行修改

在LeetCode中，大多数single-linked-list题目的pattern是使用head-node来表示完整的single-linked-list:

1、将head-node作为入参来表示完整的single-linked-list

2、返回新的head-node

对于大多数single-linked-list题目，我们都是基于"prev-cur-next-三指针-iteration"来进行解决，但是对于head-node，相较于internel-node，它具有如下特殊之处:

1、head node没有predecessor node(前驱节点)







对于上述两种情况，新的linked-list始终都是 `dummy->next` 。



### stackoverflow [Dummy nodes in linked lists](https://stackoverflow.com/questions/22952882/dummy-nodes-in-linked-lists)



[A](https://stackoverflow.com/a/68537188)

In algorithms questions, we always pass the head of the linked list as the argument. If you are changing the position of the head node and you need to return the new head node, the problem will be how are you gonna return the new head. That's why we initially create a dummy node and `dummy.next` will point to the head. So, if you are potentially modifying the head of list, use dummy node

> NOTE:
>
> 一、在LeetCode的linked list题目中，大多数都是将linked list的head node作为入参来表示完整的linked list，并且很多算法都会出现上面描述的情形:
>
> "If you are changing the position of the head node and you need to return the new head node, the problem will be how are you gonna return the new head"
>
> 比如:
>
> 1、[LeetCode-19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/) 
>
> 2、[LeetCode-24. 两两交换链表中的节点](https://leetcode.cn/problems/swap-nodes-in-pairs/)
>
> 3、[LeetCode-1721. 交换链表中的节点-中等](https://leetcode.cn/problems/swapping-nodes-in-a-linked-list/) 
>
> dummy node保证能够以相同的逻辑来处理所有的节点，它是一个我们创建的节点



### LeetCode



#### [LeetCode-19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/) # [官方解题](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/) 

> NOTE:
>
> 1、是在阅读这篇文章的时候，发现的

在对链表进行操作时，一种常用的技巧是添加一个哑节点（dummy node），它的 $\textit{next}$ 指针指向链表的头节点。这样一来，我们就不需要对头节点进行特殊的判断了。

例如，在本题中，如果我们要删除节点 `y`，我们需要知道节点 `y` 的前驱节点 `x`，并将 `x` 的指针指向 `y` 的后继节点。但由于头节点不存在前驱节点，因此我们需要在删除头节点时进行特殊判断。但如果我们添加了哑节点，那么头节点的前驱节点就是哑节点本身，此时我们就只需要考虑通用的情况即可。

在 labuladong [单链表的六大解题套路，你都见过么？](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247492022&idx=1&sn=35f6cb8ab60794f8f52338fab3e5cda5&scene=21#wechat_redirect) 中也展示了这种写法:

```Java
// 主函数
public ListNode removeNthFromEnd(ListNode head, int n) {
    // 虚拟头节点
    ListNode dummy = new ListNode(-1);
    dummy.next = head;
    // 删除倒数第 n 个，要先找倒数第 n + 1 个节点，即它的前驱节点
    ListNode x = findFromEnd(dummy, n + 1);
    // 删掉倒数第 n 个节点
    x.next = x.next.next;
    return dummy.next;
}

// 返回链表的倒数第 k 个节点
ListNode findFromEnd(ListNode head, int k) {
    ListNode p1 = head;
    // p1 先走 k 步
    for (int i = 0; i < k; i++) {
        p1 = p1.next;
    }
    ListNode p2 = head;
    // p1 和 p2 同时走 n - k 步
    while (p1 != null) {
        p2 = p2.next;
        p1 = p1.next;
    }
    // p2 现在指向第 n - k 个节点
    return p2;
}


```



## 二、创建一个新的single-linked-list

create linked list pattern: dummy node+append to tail

1、使用"append to tail"模式来创建一个linked list的时候，使用一个循环即可

2、使用dummy node技巧，能够避免对空指针进行讨论，使得程序非常的统一



### LeetCode

在下面的题中，使用到了这种技巧:

1、[LeetCode-21. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

2、[LeetCode-114. 二叉树展开为链表](https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/)

3、[LeetCode-23. 合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)



### stackoverflow [What is a Dummy Head?](https://stackoverflow.com/questions/37324972/what-is-a-dummy-head)



[A](https://stackoverflow.com/a/37330797)

Dummy nodes are more like a hack and are commonly used when you want to avoid writing additional code for edge cases.

Consider the following case of inserting at tail in a linked list:

```java
void insertAtTail(Node oldTail, int i){
    Node newTail = new Node(i);
    oldTail.next = newTail;
    return newTail;
}
```

This works fine when oldTail is not null. But imagine the scenario where we are trying to perform insertAtTail() on an empty list. The above written code will not work if the node is null. Therefore, we've to handle the edge case of checking if oldTail is null:

```java
Node insertAtTail(Node oldTail, int i){
    Node newTail = new Node(i);
    if(oldTail == null) {return newTail;}
    oldTail.next = newTail;
    return newTail;
}
```

It's in scenarios like these that dummy nodes come in handy. Imagine I've a dummy node as follows:

```java
Node dummy = new Node(0);
```

Now we pass this dummy node to the calling function:

```java
insertAtTail(dummy, 5);
```

When a dummy node is passed to the calling function, you'll see that there's no need to check if dummy is null here. Therefore, we can skip the check for empty node:

```java
Node insertAtTail(Node dummy, int i){
    Node newTail = new Node(i);
    dummy.next = newTail;
    return newTail;
}
```

As you can see, I've removed the check for null here.

[A](https://stackoverflow.com/a/50221469)

When the **head** of the Linked List doesn't point to any Node, you create a Dummy Head (Node) pointed from that **head**. So that you would always be able to reach e.g. `head.val` or `head.next` without doing any extra null checks.



## TODO

一、linked-list-k-step步长-span跨度-stride跨度-iteration

同样是可以使用prev-cur-next三指针

二、linked-list node的分类:

1、head node

2、internal node

3、tail node

