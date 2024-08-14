# DFS-post-order

素材:

一. labuladong [团灭 LeetCode 打家劫舍问题](https://mp.weixin.qq.com/s/z44hk0MW14_mAQd7988mfw) # House Robber III

其中给出的返回一个tuple的写法是非常经典的，后面的很多题都是仿照的它的写法

二. labuladong [美团面试官：你对二叉树后续遍历一无所知](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247490891&idx=1&sn=677a7e887fa551e994ba73bcb2538cea&scene=21#wechat_redirect)



## DFS-post-order-return-value

tree和linked list皆可看作是graph的简化(graph相对于binary tree(两条)、linked list(单条)仅仅是多了一个for循环来处理它的所有的adjacent nodes)，下面以graph为模板进行说明: 

递归关系: TODO: 递归关系肯定是由current node 和 它后面的node构成问题的完整的解

形象化解释: 站在current node，综合它的adjacent nodes的解，构造(produce)完整的解

### LeetCode optimization

| 题目                                                         |      |
| ------------------------------------------------------------ | ---- |
| [LeetCode-124-二叉树中的最大路径和](https://leetcode.cn/problems/binary-tree-maximum-path-sum/) |      |
| [LeetCode-333-最大BST子树](https://leetcode.cn/problems/largest-bst-subtree/) |      |
| [LeetCode-337. 打家劫舍 III-中等](https://leetcode.cn/problems/house-robber-iii/) |      |
| [LeetCode-1373. 二叉搜索子树的最大键值和](https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/) |      |
| [LeetCode-111. 二叉树的最小深度-简单](https://leetcode.cn/problems/minimum-depth-of-binary-tree/) |      |
| [LeetCode-104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/) |      |
|                                                              |      |



## 其它题目



[LeetCode-538-把二叉搜索树转换为累加树](https://leetcode.cn/problems/convert-bst-to-greater-tree/) 

这道题是出自 labuladong [手把手刷二叉搜索树（第一期）](https://mp.weixin.qq.com/s/ioyqagZLYrvdlZyOMDjrPw) 。