# 我的刷题

## [LeetCode-1. 两数之和](https://leetcode.cn/problems/two-sum/) 

$O(N^2)$ 

search space: upper triangular square matrix(上三角方阵)

$O(N)$

为access过的数建立hash map，然后在其中寻找目标数，避免了第二层的循环



## [LeetCode-11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/) 

$O(N^2)$ 

search space: upper triangular square matrix(上三角方阵)

$O(N)$

double- pointer-search+prune

一次丢一行、一列，逐步向目标靠拢，丢弃无效搜索

素材

1、 [nettee](https://leetcode.cn/u/nettee/) [一张图告诉你 O(n) 的双指针解法的本质原理（C++/Java）](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/solutions/87919/yi-zhang-tu-gao-su-ni-on-de-shuang-zhi-zhen-jie-fa/)  

[LeetCode-11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/) 

[LeetCode-167. Two Sum II - Input array is sorted](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)



## Leetcode [26. 删除有序数组中的重复项](https://leetcode.cn/problems/remove-duplicates-from-sorted-array/)

参见: 

labuladong [如何高效对有序数组/链表去重？](https://mp.weixin.qq.com/s/6Eb7gKqNqXH9B0hSZvMs5A)

双指针



## 递归经典例子

1、[LeetCode-23. 合并K个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)  # 方法三：分治合并

非常类似于二分；

2、[LeetCode-148. 排序链表](https://leetcode.cn/problems/sort-list/)



## 回溯法

参见 `Algorithm\State-space-search\LeetCode` 章节，其中进行了非常好的总结。



## 数组类型问题



### [LeetCode-1711. 大餐计数](https://leetcode.cn/problems/count-good-meals/)

以空间换时间

### [LeetCode-392. 判断子序列](https://leetcode.cn/problems/is-subsequence/)

参见 labuladong [二分查找的妙用：判定子序列](https://mp.weixin.qq.com/s/hWi2hTrQewL_YKioGkXQJg)

双指针: 一个指向源、一个指向子序列



## [LeetCode-83. 删除排序链表中的重复元素](https://leetcode.cn/problems/remove-duplicates-from-sorted-list/) 

linked-list、去重

参见: 

labuladong [如何高效对有序数组/链表去重？](https://mp.weixin.qq.com/s/6Eb7gKqNqXH9B0hSZvMs5A)





## Merge

参见 `Merge-algorithm` 章节



## TOP K/selection algorithm

参见 `Top-K-rank` 章节。

## Expression

一、参见 `compiler-principle\docs\Guide\Expression`

二、括号

## 找数/凑数/搜索数

### hash map 以空间换时间

#### [LeetCode-1711. 大餐计数](https://leetcode.cn/problems/count-good-meals/)

#### LeetCode  [1. 两数之和](https://leetcode.cn/problems/two-sum/)



### 二分法

LeetCode-875-爱吃香蕉的珂珂

LeetCode-1011-在D天内送达包裹的能力

LeetCode-34-在排序数组中查找元素的第一个和最后一个位置



#### 两数之和、三数之和

参见 labuladong [双指针技巧汇总](https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg) 

参见 `Expert-labuladong\2.5-手把手刷数组题目\n-sum问题` 章节



### 凑数

[LeetCode-39. 组合总和](https://leetcode.cn/problems/combination-sum/) 中等

找出所有的sum之和为target的组合

[LeetCode-322. 零钱兑换](https://leetcode.cn/problems/coin-change/) 中等

凑够零钱所需的最少的币数



背包问题是最最经典的凑数问题；



## 回文

TODO 需要将相关试题解析总结



## 两数相加

[LeetCode-简单易懂Java/C++ /Python/js【培养算法思维】- 两数相加](https://leetcode.cn/problems/add-two-numbers/solution/jian-dan-yi-dong-javacpythonjs-pei-yang-y2w6g/)

一个思路轻而易举的解决以下 5 道算法面试题：

1、leetcode 989 号算法题：数组形式的整数加法

2、leetcode 66 号算法题：加 1

3、leetcode 415 号算法题：字符串相加

4、leetcode 67 号算法题：二进制求和

5、leetcode 2 号算法题：两数相加



## [LeetCode-787. K 站中转内最便宜的航班-中等](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 

这道题是可以使用多种解法的

LeetCode 一题多解



## LeetCode matrix/grid

algorithms:

1、union-find-set

2、flood-fill

题目: 

一、LeetCode-binary-search-matrix-series

二、LeetCode-word-search-series

三、LeetCode-number-of-islands-series

