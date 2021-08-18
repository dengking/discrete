# LeetCode [552. 学生出勤记录 II](https://leetcode-cn.com/problems/student-attendance-record-ii/) 困难





## [官方解题](https://leetcode-cn.com/problems/student-attendance-record-ii/solution/xue-sheng-chu-qin-ji-lu-ii-by-leetcode/)

> NOTE: 
>
> 一、这道题是典型的从**穷举**到**DP**
>
> 1、穷举
>
> "backtrack回溯-DFS state space-complete n-ary treeN叉树遍历-枚举穷举"
>
> 这种方式显然是会导致超时的，在 [【彤哥来刷题啦】一题六解：DFS -> 记忆化 -> DP -> 降维 -> 降维 -> 滚动数组](https://leetcode-cn.com/problems/student-attendance-record-ii/solution/tong-ge-lai-shua-ti-la-yi-ti-liu-jie-dfs-s5fa/) 中，演示了解法。
>
> 
>
> 2、DP
>
> 递归关系是难以想出的
>
> 二、这道题，让我想到了"股票买卖"问题，它们的相同点是都有着很多的限制，即状态比较多，动态规划方程是比较复杂的
>
> 

### 方法一：动态规划

由于可奖励的出勤记录要求缺勤次数少于 $2$​ 和连续迟到次数少于 $3$​，因此动态规划的**状态**由**总天数**、**缺勤次数**和**结尾连续迟到次数**决定（由于不会记录连续迟到次数等于或多于 $3$​ 的情况，因此非结尾的连续迟到次数一定少于 $3$​，只需要记录**结尾连续迟到次数**即可）。

> NOTE: 
>
> 一、"**结尾连续迟到次数**"是非常关键的，它决定了是否是一个合理的排列

定义 $\textit{dp}[i][j][k]$ 表示前 $i$ 天有 $j$ 个 $\text{'A'}$ 且结尾有连续 $k$ 个 $\text{'L'}$ 的可奖励的出勤记录的数量，其中 $0 \le i \le n$，$0 \le j \le 1$，$0 \le k \le 2$。

#### Base case

当 $i=0$ 时，没有任何出勤记录，此时 $\text{'A'}$ 的数量和结尾连续 $\text{'L'}$ 的数量一定是 $0$，因此**动态规划**的边界情况是 $\textit{dp}[0][0][0] = 1$。

#### 递归关系

当 $1 \le i \le n$ 时，$\textit{dp}[i][][]$ 的值从 $\textit{dp}[i-1][][]$ 的值转移得到，计算每个状态的值需要考虑第 $i$​ 天的出勤记录：

**一、如果第 $i$ 天的出勤记录是 $\text{'P'}$ **

如果第 $i$ 天的出勤记录是 $\text{'P'}$，则前 $i$ 天和前 $i-1$ 天的出勤记录相比，$\text{'A'}$ 的数量不变，结尾连续 $\text{'L'}$ 的数量清零，因此对 $0 \le j \le 1$，有

$$
\textit{dp}[i][j][0] := \textit{dp}[i][j][0] + \sum_{k=0}^2 \textit{dp}[i-1][j][k]
$$
**二、如果第 $i$ 天的出勤记录是 $\text{'A'}$**

如果第 $i$ 天的出勤记录是 $\text{'A'}$，则前 $i$ 天和前 $i-1$ 天的出勤记录相比，$\text{'A'}$ 的数量加 $1$，结尾连续 $\text{'L'}$ 的数量清零，此时要求前 $i-1$ 天的出勤记录记录中的 $\text{'A'}$ 的数量必须为 $0$，否则前 $i$ 天的出勤记录至少有 $2$ 个 $\text{'A'}$，不满足可奖励的条件，因此有
$$
\textit{dp}[i][1][0] := \textit{dp}[i][1][0] + \sum_{k=0}^2 \textit{dp}[i-1][0][k]
$$
**三、如果第 $i$ 天的出勤记录是 $\text{'L'}$**

如果第 $i$ 天的出勤记录是 $\text{'L'}$，则前 $i$ 天和前 $i-1$ 天的出勤记录相比，$\text{'A'}$ 的数量不变，结尾连续 $\text{'L'}$ 的数量加 $1$，此时要求前 $i-1$ 天的出勤记录记录中的结尾连续 $\text{'L'}$ 的数量不超过 $2$，否则前 $i$ 天的出勤记录的结尾至少有 $3$ 个 $\text{'L'}$，不满足可奖励的条件，因此对 $0 \le j \le 1$ 和 $1 \le k \le 2$，有
$$
\textit{dp}[i][j][k] := \textit{dp}[i][j][k] + \textit{dp}[i-1][j][k-1]
$$


上述状态转移方程对于 $i=1$ 也适用。







## [【彤哥来刷题啦】一题六解：DFS -> 记忆化 -> DP -> 降维 -> 降维 -> 滚动数组](https://leetcode-cn.com/problems/student-attendance-record-ii/solution/tong-ge-lai-shua-ti-la-yi-ti-liu-jie-dfs-s5fa/)
