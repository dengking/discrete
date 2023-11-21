# [LeetCode-218. The Skyline Problem](https://leetcode.cn/problems/the-skyline-problem/)

每个rectangle都可以看作是区间，显然这些区间之间有交叠。

沿着x滑动sweep-line，在每个点需要知道有几个rectangle，然后取这些rectangle的最大者即为所求。

这个问题就转换为区间最大值求解。



## Segment tree

使用segment tree的前提是节点是连续的。

## LeetCode [离散化+线段树维护一下每一个区间的值！](https://leetcode.cn/problems/the-skyline-problem/solution/chi-san-hua-xian-duan-shu-wei-hu-yi-xia-mrc64/)

应用的时候，首先需要将线段离散化为点，如何处理交集？

