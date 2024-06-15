# Double pointer、sliding window、尺取法

共有三种双指针技巧:

- 快慢双指针 fast-slow double pointer

- 左右双指针 left-right double pointer 

- 滑动窗口 sliding window



## 素材

1、labuladong [双指针技巧汇总](https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg)

概述性的、综述性的文章。这篇文章，介绍了三种双指针技巧，其中重点介绍了快慢指针、左右指针

> 我认为双指针技巧还可以分为两类，一类是「快慢指针」，一类是「左右指针」。前者解决主要解决链表中的问题，比如典型的判定链表中是否包含环；后者主要解决数组（或者字符串）中的问题，比如二分查找。

2、labuladong [双指针技巧秒杀四道数组/链表题目](https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ) 



## 快慢双指针 fast-slow double pointer

素材: 

- labuladong [双指针技巧汇总](https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg) 

- labuladong  [双指针技巧秒杀四道数组/链表题目](https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ) 
- labuladong [如何高效对有序数组/链表去重？](https://mp.weixin.qq.com/s/6Eb7gKqNqXH9B0hSZvMs5A) 



### Application

可以解决linked list、array相关的问题;

Array、linked-list去重、array、linked-list移除、移动指定元素类问题，使用slow守护合法区域，fast去probe(打探)。

#### Array、linked-list去重

素材: 

- labuladong [如何高效对有序数组/链表去重？](https://mp.weixin.qq.com/s/6Eb7gKqNqXH9B0hSZvMs5A) 



[LeetCode-26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/) 

[LeetCode-80. 删除排序数组中的重复项 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/) 



#### Array、linked-list移除、移动指定元素

素材:

- labuladong  [双指针技巧秒杀四道数组/链表题目](https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ) 

double-pointer-fast-slow-erase-remove-idiom

[LeetCode-27. 移除元素](https://leetcode.cn/problems/remove-element/) 

[LeetCode-283. 移动零](https://leetcode.cn/problems/move-zeroes/) 



## 左右双指针 left-right double pointer 

如果从更加宽泛的角度来看，binary search可以归入左右double pointer的范畴。



## 尺取法

尺取法其实就是滑动窗口，下面是一些素材：

一、

zhihu [尺取法（一）](https://zhuanlan.zhihu.com/p/31425915)

zhihu [尺取法（二）](https://zhuanlan.zhihu.com/p/31427570)

二、acwing [尺取法](https://www.acwing.com/blog/content/4409/)

三、[LeetCode-567. 字符串的排列](https://leetcode.cn/problems/permutation-in-string/)  



## Sliding window

素材: 

- labuladong [我写了首诗，把滑动窗口算法算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA)



### Sliding window VS 暴力搜索

滑动窗口相较于暴力搜索，优势何在？如何减少搜索空间？

1、滑动窗口，能够较快地判断窗口中，是否包含子串

2、暴力搜索，子串使用`str[i:j]`来表示，它使用嵌套for来给出所有的`i`、`j`组合

3、滑动窗口，基于上一次的位置开始进行expand、shrink，它不必每次重头再来。

> NOTE: 
>
> 以空间换时间



#### stackoverflow [Is two pointer problem same as sliding window](https://stackoverflow.com/questions/64078162/is-two-pointer-problem-same-as-sliding-window)



#### [A](https://stackoverflow.com/a/64078338)

**Sliding window algorithms** can be implemented with a single pointer and a variable for **window size**. Typically we use all of the elements within the window for the problem (for eg - sum of all elements in the window).

Two pointer technique is quite similar but we usually compare the value at the two pointers instead of all the elements between the pointers.

Two pointers can also have variations like fast-slow pointer.

Hope it answers your question.



### Sliding window VS KMP  

第一次看到滑动窗口，我就联想到了KMP，下面的文章中，对此进行了说明:

- zhihu [谈一谈“滑动窗口”](https://zhuanlan.zhihu.com/p/113352663)

KMP算法是应用了滑动窗口最典型的例子



## TODO

fatalerrors [LC algorithm skills summary: double pointer and sliding window skills](https://www.fatalerrors.org/a/lc-algorithm-skills-summary-double-pointer-and-sliding-window-skills.html)

> NOTE: 
>
> 1、LC algorithm的含义是什么？



