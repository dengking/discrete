# Quicksort && BST

正如 wikipedia [Quicksort](https://en.wikipedia.org/wiki/Quicksort) 中所总结的:

> To each execution of **quicksort** corresponds the following [binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree) (BST): 
>
> the **initial pivot** is the **root node**; 
>
> the **pivot of the left half** is the **root of the left subtree**, 
>
> the **pivot of the right half** is the **root of the right subtree**, and so on. 



> **Quicksort** is a space-optimized version of the [binary tree sort](https://en.wikipedia.org/wiki/Binary_tree_sort). Instead of inserting items sequentially into an explicit tree, quicksort organizes them concurrently into a tree that is implied by the recursive calls. The algorithms make exactly the same comparisons, but in a different order. 

显然，Quicksort是:

1、隐式地构建BST

2、自顶向下地构建BST

## Quicksort pre-order traversal

按照 labuladong [东哥手把手带你套框架刷通二叉树|第一期](https://mp.weixin.qq.com/s/izZ5uiWzTagagJec6Y7RvQ)  中的说法: 

> 快速排序的逻辑是，若要对`nums[lo..hi]`进行排序，我们先找一个分界点`p`，通过交换元素使得`nums[lo..p-1]`都小于等于`nums[p]`，且`nums[p+1..hi]`都大于`nums[p]`，然后递归地去`nums[lo..p-1]`和`nums[p+1..hi]`中寻找新的分界点，最后整个数组就被排序了。
>
> 快速排序的代码框架如下：
>
> ```java
> void sort(int[] nums, int lo, int hi) {
>     /****** 前序遍历位置 ******/
>     // 通过交换元素构建分界点 p
>     int p = partition(nums, lo, hi);
>     /************************/
> 
>     sort(nums, lo, p - 1);
>     sort(nums, p + 1, hi);
> }
> ```
>
> 先构造分界点，然后去左右子数组构造分界点，你看这不就是一个二叉树的前序遍历吗？