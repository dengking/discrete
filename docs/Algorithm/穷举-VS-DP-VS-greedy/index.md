# 穷举、DP、greedy

穷举其实是解决一切问题的基础，很多算法都是在穷举的基础上发展而来。



## DP 动态规划 VS greedy 贪心算法

两者之间的共同点是[Optimal substructure](https://en.wikipedia.org/wiki/Optimal_substructure)；如果具有[Overlapping subproblems](https://en.wikipedia.org/wiki/Overlapping_subproblems)，则使用 [dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming) ，否则使用 [greedy algorithm](https://en.wikipedia.org/wiki/Greedy_algorithm) ；这个观点在[Optimal substructure](https://en.wikipedia.org/wiki/Optimal_substructure)中给出了； 



## DP 动态规划 VS DFS、回溯法

无论是**动态规划算法**抑或是**基于递归的搜索算法**，他们的实现接依赖于

1、divide-and-conquer

2、建立**递归关系**，建立正确的**递归关系**是解决问题的核心所在

### 自底向上 VS 自顶向下

下面分析这两种算法对**递归关系**的实现方式的不同，总的来说他们对**递归关系**，实现的方式是**相反**的：

一、**DFS、回溯法**对**递归关系**的实现是**自左至右**的，因为它采用递归来实现，因此他的计算是**自顶向下**进行的。他借住**系统栈**不断的按照**递归关系**自左向右的进行**分析**，直至**最小子问题**可以求解得到；在**搜索算法**中，**最小子问题**是**递归终止条件**；

二、**动态规划算法**对**递归关系**的实现是**自右至左**的，因此他首先计算的是**最小子问题**，然后按照递归关系（ synthetically 或者 归纳）计算出更大的问题直至求解除目标问题，即更大问题的求解是依赖于小问题的解的，所以在动态规划算法中，必须要考虑的一个问题是保存小问题的解（如[Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence)中需要保存前两项，最大字段和问题中需要保存前一项 ）。保存小问题的解所带来的另外一个好处是：避免了重复计算相同的问题，在动态规划算法中常常需要使用一个容器将各个此问题的计算结果给保存起来，这样在后续计算中需要被使用时就可直接取得（[Overlapping subproblems](https://en.wikipedia.org/wiki/Overlapping_subproblems)）；在**动态规划算法**中，**最小子问题**是无需计算的，它是在算法开始之初就可以直接**初始化**到保存问题解的容器中；

> NOTE: 
>
> 这种关系在 [wikipedia Corecursion](https://en.wikipedia.org/wiki/Corecursion) 中有非常好的描述；





## DP VS backtrack VS branch-and- bound VS greedy
动态规划、回溯法、分支限界法都尝试在问题的解空间中选取最优解，而贪心算法则不同，它不断地选取当前最优解。




## 从"穷举"到DP、greedy

很多问题都可以使用"**穷举**"(回溯法、等)来进行解决，它是典型的没有以"divide and conquer"思想来考虑"原问题和子问题之间关系"；

对这类问题的一个优化思路是: 以"divide and conquer"思想来考虑"原问题和子问题之间关系"，进而使用dynamic programming、greedy来进行求解，下面是典型的例子:

一、0-1 背包问题



二、学生出勤记录问题

[LeetCode-552. 学生出勤记录 II](https://leetcode.cn/problems/student-attendance-record-ii/) 困难



三、等差数列划分



四、最长递增子序列



五、[LeetCode-576. 出界的路径数](https://leetcode.cn/problems/out-of-boundary-paths/) 中等

