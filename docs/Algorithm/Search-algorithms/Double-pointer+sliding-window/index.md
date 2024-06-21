# Double pointer、sliding window

共有三种双指针技巧:

- 快慢双指针: fast-slow double pointer

- 左右双指针: left-right double pointer 

- 滑动窗口: sliding window



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

#### fast-slow-double-pointer-erase-remove-move-idiom

Array、linked-list去重、移除、移动指定元素类问题，使用slow守护合法区域，fast去probe(打探)，遇到目标元素，就移到合法区域，遇到非目标元素，直接省略过，下面是图示: 



![283_2.gif](https://pic.leetcode-cn.com/36d1ac5d689101cbf9947465e94753c626eab7fcb736ae2175f5d87ebc85fdf0-283_2.gif)

#### Array、linked-list去重

素材: 

- labuladong [如何高效对有序数组/链表去重？](https://mp.weixin.qq.com/s/6Eb7gKqNqXH9B0hSZvMs5A) 

LeetCode: 

[LeetCode-26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/) 

[LeetCode-80. 删除排序数组中的重复项 II](https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/) 



#### Array、linked-list移除、移动指定元素

素材:

- labuladong  [双指针技巧秒杀四道数组/链表题目](https://mp.weixin.qq.com/s/55UPwGL0-Vgdh8wUEPXpMQ) 

double-pointer-fast-slow-erase-remove-idiom

LeetCode: 

[LeetCode-27. 移除元素](https://leetcode.cn/problems/remove-element/) 

[LeetCode-283. 移动零](https://leetcode.cn/problems/move-zeroes/)  (quick sort)



## 左右双指针 left-right double pointer 

如果从更加宽泛的角度来看，binary search可以归入左右double pointer的范畴。



### Reverse

TODO



### Binary search

参见 `Binary-search` 章节。

### 中心扩散法

[LeetCode-5. 最长回文子串-中等](https://leetcode.cn/problems/longest-palindromic-substring/) 

LeetCode 5中心扩散法也可以看做是一种left-right double pointer

## First-second double pointer

K-way merge



## Sliding window

参加 `Sliding-window` 章节。



## Left right double pointer search algorithm

upper triangular square matrix(上三角方阵)

| 问题/算法                                                    | 搜索目标 | 问题的搜索空间                          | 优化后的复杂度 |
| ------------------------------------------------------------ | -------- | --------------------------------------- | -------------- |
| [LeetCode-11. 盛最多水的容器-Medium](https://leetcode.cn/problems/container-with-most-water/) | 一对数字 | $O(n^2)$ upper triangular square matrix | $O(n)$         |
| [LeetCode-167. Two Sum II - Input array is sorted-Medium](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/) | 一对数字 | $O(n^2)$ upper triangular square matrix | $O(n)$         |
| [LeetCode-240. Search a 2D Matrix II-Medium](https://leetcode.cn/problems/search-a-2d-matrix-ii/) | 一个数字 | $O(n^2)$ matrix                         | $O(n)$         |
| [LeetCode-剑指 Offer 57 - II. 和为s的连续正数序列-简单](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) / [LCR 180. 文件组合-简单](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) | 一个数字 | $O(n^2)$ upper triangular square matrix | $O(n)$         |
| Binary search                                                | 一个数字 | $O(n)$                                  | $O(lg_2(n))$   |

算法思想: 取一个**pivot观测值**，以此来作为优化的参考，然后进行**剪枝**，从而达到优化搜索空间的目的: 

- Binary search 充分运用sorted的特性，选取**middle point**来作为**pivot观测值**; 每次移动left/right可以丢弃一半的搜索空间;
- [LeetCode-11. 盛最多水的容器-Medium](https://leetcode.cn/problems/container-with-most-water/): 选取left、right的面积作为观测值；每次移动left丢弃一行、每次移动right丢弃一列;

- [LeetCode-240. Search a 2D Matrix II-Medium](https://leetcode.cn/problems/search-a-2d-matrix-ii/): 充分运用sorted的特性， 选取左下角元素 为标志数 flag；search space是$O(N^2)$ matrix，它有binary search tree的思想

[nettee](https://leetcode.cn/u/nettee/) # [一张图告诉你 O(n) 的双指针解法的本质原理（C++/Java）](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/solutions/87919/yi-zhang-tu-gao-su-ni-on-de-shuang-zhi-zhen-jie-fa/) 中总结得非常形象的一句话："每次移动一下指针，相当于丢弃**搜索空间**中的一行或者一列" 从而将复杂度显著降低。

[LeetCode-240. 搜索二维矩阵 II（贪心，清晰图解）](https://leetcode.cn/problems/search-a-2d-matrix-ii/solutions/2361487/240-sou-suo-er-wei-ju-zhen-iitan-xin-qin-7mtf/)
