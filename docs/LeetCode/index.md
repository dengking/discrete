# 我的刷题

## 递归经典例子

1、leetcode [23. 合并K个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)  # 方法三：分治合并

非常类似于二分；

## 回溯法



### [37. 解数独](https://leetcode-cn.com/problems/sudoku-solver/)

还未完成

LeetCode-51-N-皇后-Hard

LeetCode-52-N-皇后-II-Hard

LeetCode-面试题-08.12-八皇后



## 数组类型问题

### LeetCode [1711. 大餐计数](https://leetcode-cn.com/problems/count-good-meals/)

以空间换时间

### LeetCode [392. 判断子序列](https://leetcode-cn.com/problems/is-subsequence/)

参见 labuladong [二分查找的妙用：判定子序列](https://mp.weixin.qq.com/s/hWi2hTrQewL_YKioGkXQJg)

双指针: 一个指向源、一个指向子序列

## 去重

### leetcode [83. 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/) 

参见: 

labuladong [如何高效对有序数组/链表去重？](https://mp.weixin.qq.com/s/6Eb7gKqNqXH9B0hSZvMs5A)



### Leetcode [26. 删除有序数组中的重复项](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/)

参见: 

labuladong [如何高效对有序数组/链表去重？](https://mp.weixin.qq.com/s/6Eb7gKqNqXH9B0hSZvMs5A)

双指针

## Merge

### Merge sequence

#### 一、 merge two sequence



leetcode [912. 排序数组](https://leetcode-cn.com/problems/sort-an-array/) (merge sort) 和 leetcode [21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/) 

merge sortmerge的部分，和 leetcode [21. 合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/) 的逻辑是非常类似的。

下面的是合并两个序列的题目:

1、leetcode [88. 合并两个有序数组](https://leetcode-cn.com/problems/merge-sorted-array/)

2、

#### 二、merge multiple sequence

leetcode [23. 合并K个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)

**两两合并**

leetcode [23. 合并K个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/) 中，给出了递归写法和迭代写法；

### Merge interval 合并区间

leetcode [56. 合并区间](https://leetcode-cn.com/problems/merge-intervals/)





## TOP K/selection algorithm

参见 `Top-K-rank` 章节。

## Expression

一、参见 `compiler-principle\docs\Guide\Expression`

二、括号

## 找数/凑数/搜索数

### LeetCode [1711. 大餐计数](https://leetcode-cn.com/problems/count-good-meals/)

以空间换时间

### LeetCode  [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)

以空间换时间

### 二分法

LeetCode-875-爱吃香蕉的珂珂

LeetCode-1011-在D天内送达包裹的能力

LeetCode-34-在排序数组中查找元素的第一个和最后一个位置

#### 两数之和、三数之和

参见 labuladong [双指针技巧汇总](https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg) 

参见 `Expert-labuladong\2.5-手把手刷数组题目\n-sum问题` 章节

## 回文

记得将在newcode上看到的一种写法记下来。



## 使用了二分思想的算法

1、leetcode [23. 合并K个升序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/)  # 方法三：分治合并

自顶向下

2、quick select

参见  labuladong [快排亲兄弟：快速选择算法详解](https://mp.weixin.qq.com/s/TRO3FOKT90Mpvn3hQWVBAQ) 。

3、merge sort

参见 labuladong [东哥手把手带你套框架刷通二叉树|第一期](https://mp.weixin.qq.com/s/izZ5uiWzTagagJec6Y7RvQ) 

```C++
void sort(int[] nums, int lo, int hi) {
    int mid = (lo + hi) / 2;
    sort(nums, lo, mid);
    sort(nums, mid + 1, hi);

    /****** 后序遍历位置 ******/
    // 合并两个排好序的子数组
    merge(nums, lo, mid, hi);
    /************************/
}
```

4、两数之和、三数之和

参见 labuladong [双指针技巧汇总](https://mp.weixin.qq.com/s/yLc7-CZdti8gEMGWhd0JTg) 

