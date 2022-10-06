# Greedy algorithm



## wikipedia [Greedy algorithm](https://en.wikipedia.org/wiki/Greedy_algorithm)



## 素材

### [LeetCode-406. 根据身高重建队列](https://leetcode.cn/problems/queue-reconstruction-by-height/) # [【贪心思想「模拟队列插入图解」】](https://leetcode.cn/problems/queue-reconstruction-by-height/solution/by-nehzil-1z3g/)

「贪心算法」的问题需要满足的条件：

1、**最优子结构**：规模较大的问题的解由规模较小的子问题的解组成，规模较大的问题的解只由其中一个规模较小的子问题的解决定；

2、**无后效性**：后面阶段的求解不会修改前面阶段已经计算好的结果；

> NOTE:
>
> [LeetCode-406. 根据身高重建队列](https://leetcode.cn/problems/queue-reconstruction-by-height/) 就是典型的无后效

3、**贪心选择性质**: 从**局部最优解**可以得到**全局最优解**。

综上可得：贪心算法就是做出当前状态下的最优选择认为就可以解决问题。

