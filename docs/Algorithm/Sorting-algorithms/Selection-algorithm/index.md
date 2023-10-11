# Selection algorithm

top K、rank、秩等都可以使用selection algorithm得到解决。

## wikipedia [Selection algorithm](https://en.wikipedia.org/wiki/Selection_algorithm)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **selection algorithm** is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) for finding the `k`th smallest value in a collection of ordered values, such as numbers. The value that it finds is called the $k$th [order statistic](https://en.wikipedia.org/wiki/Order_statistic). Selection includes as special cases the problems of finding the [minimum](https://en.wikipedia.org/wiki/Minimum), [median](https://en.wikipedia.org/wiki/Median), and [maximum](https://en.wikipedia.org/wiki/Maximum) element in the collection. Selection algorithms include [quickselect](https://en.wikipedia.org/wiki/Quickselect), and the [median of medians](https://en.wikipedia.org/wiki/Median_of_medians) algorithm. When applied to a collection of `n` values, these algorithms take [linear time](https://en.wikipedia.org/wiki/Linear_time), $O(n)$ as expressed using [big O notation](https://en.wikipedia.org/wiki/Big_O_notation). For data that is already structured, faster algorithms may be possible; as an extreme case, selection in an already-sorted [array](https://en.wikipedia.org/wiki/Array_(data_structure)) takes time (1).



## 算法

1、heap select

2、quick select

3、binary search

4、counting sort



## LeetCode

### 第k大

https://leetcode.cn/problemset/all/?search=%E7%AC%ACk%E4%B8%AA

搜索 "第k个"

#### 数据流

[LeetCode-703. 数据流中的第 K 大元素-简单](https://leetcode.cn/problems/kth-largest-element-in-a-stream/) 

[LeetCode-面试题 10.10. 数字流的秩-中等](https://leetcode.cn/problems/rank-from-stream-lcci/) 



#### 二叉搜索树

参见 `Data-structure\Tree\Tree-algorithm\Top-K-rank-of-node` 章节。



#### 数组

[LeetCode-215. 数组中的第K个最大元素-中等](https://leetcode.cn/problems/kth-largest-element-in-an-array/) 



### 最小的K个数

[LeetCode-剑指 Offer 40. 最小的k个数-简单](https://leetcode.cn/problems/zui-xiao-de-kge-shu-lcof/) 

[LeetCode-面试题 17.14. 最小K个数-中等](https://leetcode.cn/problems/smallest-k-lcci/) 

[LeetCode-面试题 17.09. 第 k 个数](https://leetcode.cn/problems/get-kth-magic-number-lcci/)

#### [一道头条算法题，一种不为人知的解法！](https://mp.weixin.qq.com/s/248i87BSGUA89SzcAXig0g)

> NOTE: 
>
> 1、主要在讲 [计数排序](https://baike.baidu.com/item/%E8%AE%A1%E6%95%B0%E6%8E%92%E5%BA%8F/8518144?fr=aladdin)



### 最接近的K个数

[LeetCode-973. 最接近原点的 K 个点-中等](https://leetcode.cn/problems/k-closest-points-to-origin/) 

[LeetCode-658. 找到 K 个最接近的元素-中等](https://leetcode.cn/problems/find-k-closest-elements/) 
