# Traverse

一、"traverse"其实也可以看做是一种"穷举"

二、在 `Relation-structure-computation\Computation\Computation-on-structure` 中提出了 **Traverse** 的计算方式，对state space、solution space进行traverse 是解决问题的一种通用方式，本章基于这个思路进行梳理。

| strategy             |        | 章节                               |
| -------------------- | ------ | ---------------------------------- |
| DFS                  |        |                                    |
| DFS-backtracking     | 回溯法 | 参见 `DFS-backtracking` 章节。     |
| BFS                  |        |                                    |
| BFS-branch-and-bound |        | 参见 `BFS-branch-and-bound` 章节。 |



| algorithm paradigm | search strategy                               |
| ------------------ | --------------------------------------------- |
| Backtracking       | - Depth-first search                          |
| Branch-and-Bound   | - Breadth-first search<br>- Best-first search |

简而言之: 

Backtrace 对应的是 depth-first ；

Branch-and-Bound 对应的是 width-first ；



## BFS VS DFS

### 例题

能够同时使用 BFS 和 DFS 解决的题目:

| 题目                          |      |
| ----------------------------- | ---- |
| LeetCode-104-二叉树的最大深度 |      |
| LeetCode-111-二叉树的最小深度 |      |
| topological-sorting-拓扑排序  |      |



### labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g)

> DFS是线-VS-BFS是面-DFS是单打独斗-VS-BFS是集体行动

### cs.ubc.ca [CPSC 322, Practice Exercise Solutions to Uninformed Search](https://www.cs.ubc.ca/~hutter/teaching/cpsc322/practice_exercises/1_ex_search_uninformed_sol.pdf)

一、What are the advantages of breadth-first search (BFS) over depth-first search (DFS)? 

Answer: BFS is complete and optimal, while DFS is not guaranteed to halt when there are loops. 

> NOTE: DFS的loop问题是可以避免的

二、What is the advantage of DFS over BFS?

 Answer: If `m` is the maximum path length and `b` is the branching factor, the space complexity for DFS is `mb` while for BFS it is $b^m$.



## Track current path

一、current path=solution

二、labuladong [图论算法基础（修订版）](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494624&idx=1&sn=29b84ce2a1ba8115922179e207281e27&scene=21#wechat_redirect)

