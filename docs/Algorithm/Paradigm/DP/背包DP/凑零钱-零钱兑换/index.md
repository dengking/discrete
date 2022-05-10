# 凑零钱、零钱兑换

一、从完全背包的递归版本代码来进行思考。

二、资源:

在如下文章中进行了介绍：

1、labuladong [动态规划详解](https://mp.weixin.qq.com/s/Cw39C9MY9Wr2JlcvBQZMcA) 

其中描述了这个问题从DFS-recursion到DP的过程。



2、labuladong [经典动态规划：完全背包问题](https://mp.weixin.qq.com/s/zGJZpsGVMlk-Vc2PEY4RPw)

3、leetcode [一篇文章吃透背包问题！（细致引入+解题模板+例题分析+代码呈现](https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-a7dd/) 

三、题目：

|                                                              |                                                  |                                                              |
| ------------------------------------------------------------ | ------------------------------------------------ | ------------------------------------------------------------ |
| LeetCode [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/) | 最值问题: "凑成总金额所需的 **最少的硬币个数** " | 1、与银币的顺序没有关系: 相同银币组合的不管怎样进行排列其实个数都是相同的，因此最终的结果也是相同的，因此也就和顺序没有关系 |
| LeetCode [518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/) | 组合计数: "可以凑成总金额的硬币组合数"           |                                                              |
|                                                              |                                                  |                                                              |



