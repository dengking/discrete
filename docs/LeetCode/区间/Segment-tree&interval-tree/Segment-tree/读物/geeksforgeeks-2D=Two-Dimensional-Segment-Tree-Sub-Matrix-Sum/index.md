# geeksforgeeks [Two Dimensional Segment Tree | Sub-Matrix Sum](https://www.geeksforgeeks.org/two-dimensional-segment-tree-sub-matrix-sum/)



> NOTE:
>
> 一、build
>
> 先构建tree，然后基于树构建tree of tree
>
> 二、query
>
> 先从tree of tree开始查询涉及哪些tree，然后从这些tree中查询涉及的元素
>
> 三、最最典型的case: `4 * 4` matrix
>
> 先为每一行构建一个segment tree，由于所有的行的元素个数相同、index相同、segment方案相同，因此是可以对这些segment tree相加(逐个元素)的，并且这样做对意义是能够解释清楚的，这就允许在这些segment tree的基础上再构建一个segment tree，此时的segment tree的节点类型是segment tree。
>
> 四、[LeetCode-304. Range Sum Query 2D - Immutable-medium](https://leetcode.cn/problems/range-sum-query-2d-immutable/)
>
> 

