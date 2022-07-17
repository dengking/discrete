# Traverse-structure

## Structure

本章描述的structure包括: 

一、concrete structure

主要包括: linked-list、tree、graph

二、abstract structure



## Algorithm

"traverse"其实也可以看做是一种"穷举"，它是系统地解决很多问题的基础，比如对state/solution  space进行traverse是解决问题的一种通用方式，它涉及了多种algorithm。在 `Relation-structure-computation\Computation\Computation-on-structure` 中提出了 **Traverse** 的计算方式，本章基于这个思路进行梳理。

| strategy             |        | 章节                               |
| -------------------- | ------ | ---------------------------------- |
| DFS                  |        |                                    |
| DFS-backtracking     | 回溯法 | 参见 `DFS-backtrack` 章节。        |
| BFS                  |        |                                    |
| BFS-branch-and-bound |        | 参见 `BFS-branch-and-bound` 章节。 |



| algorithm paradigm | search strategy              |
| ------------------ | ---------------------------- |
| Backtrack          | - DFS                        |
| Branch-and-Bound   | - BFS<br>- Best-first search |

简而言之: 

Backtrace 对应的是 depth-first ；

Branch-and-Bound 对应的是 width-first ；



### BFS VS DFS

#### 例题

本节总结能够同时使用 BFS 和 DFS 解决的题目、算法:

| 题目                          |      |
| ----------------------------- | ---- |
| LeetCode-104-二叉树的最大深度 |      |
| LeetCode-111-二叉树的最小深度 |      |
| topological-sorting-拓扑排序  |      |



#### labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) 

在这篇文章中进行了非常好的描述，下面是其中的观点:

> DFS是线-VS-BFS是面-DFS是单打独斗-VS-BFS是集体行动

#### cs.ubc.ca [CPSC 322, Practice Exercise Solutions to Uninformed Search](https://www.cs.ubc.ca/~hutter/teaching/cpsc322/practice_exercises/1_ex_search_uninformed_sol.pdf) 

一、What are the advantages of breadth-first search (BFS) over depth-first search (DFS)? 

Answer: BFS is complete and optimal, while DFS is not guaranteed to halt when there are loops. 

> NOTE: 
>
> 一、关于 "BFS is complete and optimal"，在下面的文章中有一些介绍:
>
> labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) :
>
> > BFS 相对 DFS 的最主要的区别是：**BFS 找到的路径一定是最短的，但代价就是空间复杂度比 DFS 大很多**
>
> 
>
> > 要说框架的话，我们先举例一下 BFS 出现的常见场景好吧，**问题的本质就是让你在一幅「图」中找到从起点`start`到终点`target`的最近距离，这个例子听起来很枯燥，但是 BFS 算法问题其实都是在干这个事儿。**
>
> 
>
> 二、DFS的loop问题是可以避免的

二、What is the advantage of DFS over BFS?

 Answer: If `m` is the maximum path length and `b` is the branching factor, the **space complexity** for DFS is `mb` while for BFS it is $b^m$.

> NOTE: 关于**space complexity** ，在 labuladong [BFS 算法框架套路详解](https://mp.weixin.qq.com/s/WH_XGm1-w5882PnenymZ7g) 中有着很好的解释。

### Track current path

这是在阅读 labuladong [图论算法基础（修订版）](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494624&idx=1&sn=29b84ce2a1ba8115922179e207281e27&scene=21#wechat_redirect) 时，其中提及了track current path，这让我想到了之前ju-机试的时候也碰到过，所以有必要进行总结。

一、current path=solution

二、labuladong [图论算法基础（修订版）](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494624&idx=1&sn=29b84ce2a1ba8115922179e207281e27&scene=21#wechat_redirect)

三、ju-机试



### Stop when target 

"stop when target"的意思是: "当达到目标后，就停止traverse"。

stop-condition:

1、到达了目标节点