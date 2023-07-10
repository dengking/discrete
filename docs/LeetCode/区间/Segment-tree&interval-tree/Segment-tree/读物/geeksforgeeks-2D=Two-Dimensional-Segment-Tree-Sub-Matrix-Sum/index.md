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