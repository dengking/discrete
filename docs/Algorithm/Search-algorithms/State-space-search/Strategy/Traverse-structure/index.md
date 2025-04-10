# Traverse-structure

本章描述的structure包括: 

一. concrete structure

主要包括: linked-list、tree、graph

二. virtual structure

我们将一些问题的state/solution space也看作是一种structure，为了和concrete structure进行区分，我们将它们称为 virtual structure，从

## Random access VS sequencial access

---
素材:

labuladong [数据结构和算法学习指南](https://mp.weixin.qq.com/s/ZYaXOSVM3YBIeRWm7E_jcQ) 


---

array:         random     access

linked-list: sequential access



## *Traverse* Linked-list VS Tree VS Graph VS State/Solution space

素材:

一、
1、labuladong [图论算法基础（修订版）](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494624&idx=1&sn=29b84ce2a1ba8115922179e207281e27&scene=21#wechat_redirect) 

这篇文章非常好，其实也探讨了这个topic，我就是通过这篇文章有感而发的。


二、tree and stack

1、龙书 4.6 Introduction to LR Parsing: Simple LR 

2、计算机算法设计与分析-5-回溯法

3、`Function-recursion-tree-stack` 章节的内容，尤其是 `Analysis-and-representation-of-recursion` 章节的内容

三、`Graph&tree&list` 章节


---

我的总结:

一、stop condition

| structure            | stop condition |
| -------------------- | -------------- |
| linked-list          | tail-node      |
| tree                 | leaf node      |
| graph                | 没有           |
| state/solution space | 没有           |

graph 没有leaf node，且可能存在环，因此无法通过像tree那样的结构特性来判断stop condition，因此需要借助额外的**visited array**来帮助判断，它是在所有的节点都access后才能够结束。

state/solution space是virtual structure，它没有类似于tree那样的leaf node的概念，它的stop condition会更加复杂，它的stop condition由程序员通过分析问题而得出。

二、circle

graph是可能存在circle，因此在各种algorithm中，需要对circle进行特殊处理。

tree   是不可能存在circle，因此在各种algorithm中，不需要考虑circle。

三、disconnect

graph是   可能存在disconnect。

tree   是不可能存在disconnect。

四、DFS

DFS Tree分为preorder、inorder、postorder；

DFS Graph采用的是类似于preorder的策略；

可以看到，graph的DFS和tree的preorder traversal是非常类似的。



### 章节

|                      | 章节                   |
| -------------------- | ---------------------- |
| Traverse-linked-list | `Traverse-linked-list` |
| Traverse-tree        | `Traverse-tree`        |
| Traverse-graph       | `Traverse-graph`       |



## Concrete structure VS virtual state/solution space

这是在阅读 labuladong [图论算法基础](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494624&idx=1&sn=29b84ce2a1ba8115922179e207281e27&scene=21#wechat_redirect) 时，其中讨论了traverse concrete structure的node和backtrack virtual state/solution space的path而引发的思考。

需要弄清楚当前处理的是node还是path，

1、n个node，有n-1条path

2、在 《计算机算法设计与分析-5-回溯法》中的一张图非常能够说明path和node之间的对应关系。labuladong [图论算法基础](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494624&idx=1&sn=29b84ce2a1ba8115922179e207281e27&scene=21#wechat_redirect) :

backtrack中path=solution

3、在dfs graph、dfs tree中，处理的是具体的node，而在dfs state/solution space中并不存在node，当然也存在path，但是它所处理的更加类似于是path。

4、在 labuladong [图论算法基础](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494624&idx=1&sn=29b84ce2a1ba8115922179e207281e27&scene=21#wechat_redirect) 中有这样的code，非常值得了解:

```Java
void traverse(TreeNode root) {
    if (root == null) return;
    System.out.println("enter: " + root.val);
    for (TreeNode child : root.children) {
        traverse(child);
    }
    System.out.println("leave: " + root.val);
}

void traverse(TreeNode root) {
    if (root == null) return;
    for (TreeNode child : root.children) {
        System.out.println("enter: " + child.val);
        traverse(child);
        System.out.println("leave: " + child.val);
    }
}
```

第一个处理的是node，第二个处理的是path。

第一个对应的是traverse concrete space，第二个对应的是traverse virtual state/solution space。

## Algorithm

"traverse"其实也可以看做是一种"穷举"，它是系统地解决很多问题的基础，比如对state/solution  space进行traverse是解决问题的一种通用方式，它涉及了多种algorithm。在 `Relation-structure-computation\Computation\Computation-on-structure` 中提出了 **Traverse** 的计算方式，本章基于这个思路进行梳理。

| strategy             |        | 章节                   |
| -------------------- | ------ | ---------------------- |
| DFS                  |        | `DFS`                  |
| DFS-backtracking     | 回溯法 | `DFS-backtrack`        |
| BFS                  |        | `BFS`                  |
| BFS-branch-and-bound |        | `BFS-branch-and-bound` |



| algorithm paradigm | search strategy              |
| ------------------ | ---------------------------- |
| Backtrack          | - DFS                        |
| Branch-and-Bound   | - BFS<br>- Best-first search |

简而言之: 

Backtrace 对应的是 DFS；

Branch-and-Bound 对应的是 BFS；



### BFS VS DFS



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

#### wikipedia [Breadth-first search](https://en.wikipedia.org/wiki/Breadth-first_search)

Finding the [shortest path](https://en.wikipedia.org/wiki/Shortest_path) between two nodes *u* and *v*, with path length measured by number of edges (an advantage over [depth-first search](https://en.wikipedia.org/wiki/Depth-first_search))[[12\]](https://en.wikipedia.org/wiki/Breadth-first_search#cite_note-12)



#### 例题

本节总结能够同时使用 BFS 和 DFS 解决的题目、算法:

| 题目                          |      |
| ----------------------------- | ---- |
| LeetCode-104-二叉树的最大深度 |      |
| LeetCode-111-二叉树的最小深度 |      |
| topological-sorting-拓扑排序  |      |



### Track current path

这是在阅读 labuladong [图论算法基础（修订版）](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494624&idx=1&sn=29b84ce2a1ba8115922179e207281e27&scene=21#wechat_redirect) 时，其中提及了track current path，这让我想到了之前ju-机试的时候也碰到过，所以有必要进行总结。

一、current path=solution

二、labuladong [图论算法基础（修订版）](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494624&idx=1&sn=29b84ce2a1ba8115922179e207281e27&scene=21#wechat_redirect)

三、ju-机试



### Stop condition

概括来说就是"stop when target"，"stop when target"的意思是: "当达到目标后，就停止traverse"，stop-condition:

1、到达了目标节点



## k-step步长-span跨度-stride跨度-traverse

TODO



## K-way-traverse-structure

TODO:

1、k-way-merge

2、[LeetCode-415. 字符串相加](https://leetcode.cn/problems/add-strings/)

3、bidirectional-search

