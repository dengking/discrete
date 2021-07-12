# Merge sort

## Merge sort: post-order traversal

### labuladong [东哥手把手带你套框架刷通二叉树|第一期](https://mp.weixin.qq.com/s/izZ5uiWzTagagJec6Y7RvQ) 

再说说归并排序的逻辑，若要对`nums[lo..hi]`进行排序，我们先对`nums[lo..mid]`排序，再对`nums[mid+1..hi]`排序，最后把这两个有序的子数组合并，整个数组就排好序了。

归并排序的代码框架如下：

```Java
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

先对左右子数组排序，然后合并（类似合并有序链表的逻辑），你看这是不是二叉树的后序遍历框架？另外，这不就是传说中的分治算法嘛，不过如此呀。

如果你一眼就识破这些排序算法的底细，还需要背这些算法代码吗？这不是手到擒来，从框架慢慢扩展就能写出算法了。

说了这么多，旨在说明，二叉树的算法思想的运用广泛，甚至可以说，只要涉及递归，都可以抽象成二叉树的问题。



## wikipedia [Merge sort](https://en.wikipedia.org/wiki/Merge_sort)





## hackerearth [Merge Sort](https://www.hackerearth.com/zh/practice/algorithms/sorting/merge-sort/tutorial/)

Merge sort is a divide-and-conquer algorithm based on the idea of breaking down a list into several sub-lists until each sublist consists of a single element and merging those sublists in a manner that results into a sorted list. 

 

**Idea:** 

 

- Divide the unsorted list into N sublists, each containing 1 element.  
- Take adjacent pairs of two singleton lists and merge them to form a list of 2 elements. N will now convert into N/2 lists of size 2.
- Repeat the process till a single sorted list of obtained. 
