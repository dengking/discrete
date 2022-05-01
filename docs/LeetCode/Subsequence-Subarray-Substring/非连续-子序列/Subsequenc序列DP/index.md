# DP解子序列类型问题

如果子序列不满足单调性，但是具备最优子结构，在求最值问题的时候，可以使用动态规划算法。

## good resource

### labuladong

labuladong 第二章、手把手刷动态规划 # 子序列类型问题：

1、labuladong [子序列解题模板：最长回文子序列](https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA) 

### 宫水三叶

LeetCode [【宫水三叶】详解如何分析「序列 DP」问题（附序列 DP 问题目录）](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/gong-shui-san-xie-xiang-jie-ru-he-fen-xi-ykvk/)

https://github.com/SharingSource/LogicStack-LeetCode/wiki/%E5%BA%8F%E5%88%97-DP

| 题目                                                         | 题解                                                         | 难度 | 推荐指数 |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---- | -------- |
| [334. 递增的三元子序列](https://leetcode-cn.com/problems/increasing-triplet-subsequence/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/increasing-triplet-subsequence/solution/gong-shui-san-xie-zui-chang-shang-sheng-xa08h/) | 中等 | 🤩🤩🤩🤩     |
| [354. 俄罗斯套娃信封问题](https://leetcode-cn.com/problems/russian-doll-envelopes/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/russian-doll-envelopes/solution/zui-chang-shang-sheng-zi-xu-lie-bian-xin-6s8d/) | 困难 | 🤩🤩🤩🤩🤩    |
| [368. 最大整除子集](https://leetcode-cn.com/problems/largest-divisible-subset/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/largest-divisible-subset/solution/gong-shui-san-xie-noxiang-xin-ke-xue-xi-0a3jc/) | 中等 | 🤩🤩🤩🤩     |
| [390. 消除游戏](https://leetcode-cn.com/problems/elimination-game/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/elimination-game/solution/gong-shui-san-xie-yue-se-fu-huan-yun-yon-x60m/) | 中等 | 🤩🤩🤩🤩     |
| [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/gong-shui-san-xie-xiang-jie-ru-he-fen-xi-ykvk/) | 困难 | 🤩🤩🤩🤩🤩    |
| [472. 连接词](https://leetcode-cn.com/problems/concatenated-words/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/concatenated-words/solution/gong-shui-san-xie-xu-lie-dpzi-fu-chuan-h-p7no/) | 困难 | 🤩🤩🤩🤩     |
| [583. 两个字符串的删除操作](https://leetcode-cn.com/problems/delete-operation-for-two-strings/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/delete-operation-for-two-strings/solution/gong-shui-san-xie-cong-liang-chong-xu-li-wqv7/) | 中等 | 🤩🤩🤩🤩     |
| [629. K个逆序对数组](https://leetcode-cn.com/problems/k-inverse-pairs-array/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/k-inverse-pairs-array/solution/gong-shui-san-xie-yi-dao-xu-lie-dp-zhuan-tm01/) | 中等 | 🤩🤩🤩🤩🤩    |
| [673. 最长递增子序列的个数](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/solution/gong-shui-san-xie-lis-de-fang-an-shu-wen-obuz/) | 中等 | 🤩🤩🤩🤩     |
| [689. 三个无重叠子数组的最大和](https://leetcode-cn.com/problems/maximum-sum-of-3-non-overlapping-subarrays/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/maximum-sum-of-3-non-overlapping-subarrays/solution/gong-shui-san-xie-jie-he-qian-zhui-he-de-ancx/) | 困难 | 🤩🤩🤩🤩     |
| [740. 删除并获得点数](https://leetcode-cn.com/problems/delete-and-earn/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/delete-and-earn/solution/gong-shui-san-xie-zhuan-huan-wei-xu-lie-6c9t0/) | 中等 | 🤩🤩🤩🤩🤩    |
| [978. 最长湍流子数组](https://leetcode-cn.com/problems/longest-turbulent-subarray/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/longest-turbulent-subarray/solution/xiang-jie-dong-tai-gui-hua-ru-he-cai-dp-3spgj/) | 中等 | 🤩🤩🤩      |
| [1035. 不相交的线](https://leetcode-cn.com/problems/uncrossed-lines/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/uncrossed-lines/solution/gong-shui-san-xie-noxiang-xin-ke-xue-xi-bkaas/) | 中等 | 🤩🤩🤩🤩     |
| [1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/longest-common-subsequence/solution/gong-shui-san-xie-zui-chang-gong-gong-zi-xq0h/) | 中等 | 🤩🤩🤩🤩     |
| [1218. 最长定差子序列](https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/longest-arithmetic-subsequence-of-given-difference/solution/gong-shui-san-xie-jie-he-tan-xin-de-zhua-dj1k/) | 中等 | 🤩🤩🤩🤩🤩    |
| [1473. 粉刷房子 III](https://leetcode-cn.com/problems/paint-house-iii/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/paint-house-iii/solution/gong-shui-san-xie-san-wei-dong-tai-gui-h-ud7m/) | 困难 | 🤩🤩🤩🤩     |
| [1713. 得到子序列的最少操作次数](https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/solution/gong-shui-san-xie-noxiang-xin-ke-xue-xi-oj7yu/) | 困难 | 🤩🤩🤩🤩🤩    |
| [1751. 最多可以参加的会议数目 II](https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended-ii/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended-ii/solution/po-su-dp-er-fen-dp-jie-fa-by-ac_oier-88du/) | 困难 | 🤩🤩🤩🤩     |

## 子序列问题总结

在 labuladong [子序列解题模板：最长回文子序列](https://mp.weixin.qq.com/s/zNai1pzXHeB2tQE6AdOXTA) 中，对各种可能的情况进行了非常好的总结:

|      | 一个序列                                                     | 两个序列       |
| ---- | ------------------------------------------------------------ | -------------- |
| 一维 | 最长递增子序列、<br>最大子数组和 (`array[i]`结尾的目标子序列)、<br/>等差子序列 | 最长回文子序列 |
| 二维 |                                                              |                |
| 三维 |                                                              |                |



## 单个序列

单个子序列的常见题目：

|             | 章节          |
| ----------- | ------------- |
| LIS系列问题 | `LIS系列问题` |
| 回文子序列  |               |



## 两个序列



## TODO

https://stackoverflow.com/questions/tagged/dynamic-programming?tab=Active

序列问题与多条规划算法





