# labuladong [二分搜索只能用来查找元素吗？](https://mp.weixin.qq.com/s/QC24hyg0ZgjR7-LgnEzMYg)

抛开有序数组这个枯燥的数据结构，二分查找如何运用到实际的算法问题中呢？当搜索空间有序的时候，就可以通过二分搜索「剪枝」，大幅提升效率。

说起来玄乎得很，本文用「Koko 吃香蕉」和「货物运输」的问题来举个例子。

## 一、Koko 吃香蕉

> NOTE: 
>
> LeetCode [875. 爱吃香蕉的珂珂](https://leetcode-cn.com/problems/koko-eating-bananas/) 中等