# [LeetCode-847. 访问所有节点的最短路径](https://leetcode.cn/problems/shortest-path-visiting-all-nodes/) 困难



## [官方解题](https://leetcode.cn/problems/shortest-path-visiting-all-nodes/solution/fang-wen-suo-you-jie-dian-de-zui-duan-lu-mqc2/)



### 方法一：状态压缩 + 广度优先搜索

> NOTE:
>
> 一、BFS能够保证每个节点都被访问到
>
> 二、由于所有路径长度为1，因此越早被访问到那么路径就越短
>
> 那如何论证，该算法找到的解是最优解？
>
> 三、这个题目是如何做bit mask的？

由于题目需要我们求出「访问所有节点的最短路径的长度」，并且图中每一条边的长度均为 $1$​​，因此我们可以考虑使用**广度优先搜索**的方法求出**最短路径**。

在常规的**广度优先搜索**中，我们会在队列中存储节点的编号。对于本题而言，**最短路径**的前提是「访问了所有节点」，因此除了记录节点的编号以外，我们还需要记录每一个节点的经过情况。因此，我们使用三元组 $(u, \textit{mask}, \textit{dist})$​ 表示队列中的每一个元素，其中：

1、$u$ 表示当前位置的节点编号；

2、$mask$ 是一个长度为 $n$ 的二进制数，表示每一个节点是否经过。

3、*dist* 表示到当前节点为止经过的路径长度。

这样一来，我们使用该三元组进行**广度优先搜索**，即可解决本题。

初始时，我们将所有的 $(i, 2^i, 0)$ 放入队列，表示可以从任一节点开始。在搜索的过程中，如果当前三元组中的 $mask$ 包含 $n$ 个 $1$（即 $mask=2n−1$），那么我们就可以返回 $\textit{dist}$ 作为答案。

#### 细节

为了保证**广度优先搜索**时间复杂度的正确性，即同一个节点 $u$ 以及节点的经过情况 $\textit{mask}$ 只被搜索到一次，我们可以使用数组或者哈希表记录 $(u, \textit{mask})$ 是否已经被搜索过，防止无效的重复搜索。



### 方法二：预处理点对间最短路 + 状态压缩动态规划

