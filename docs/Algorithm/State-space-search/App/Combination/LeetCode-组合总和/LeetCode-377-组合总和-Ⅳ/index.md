# leetcode [377. 组合总和 Ⅳ](https://leetcode-cn.com/problems/combination-sum-iv/)





上述做法是否考虑到选取元素的顺序？答案是肯定的。因为外层循环是遍历从 `1` 到 $\textit{target}$ 的值，内层循环是遍历数组 $\textit{nums}$ 的值，在计算 $\textit{dp}[i]$ 的值时，$\textit{nums}$ 中的每个小于等于 $i$ 的元素都可能作为元素之和等于 $i$ 的排列的最后一个元素。例如，$1$ 和 $3$ 都在数组 $\textit{nums}$ 中，计算 $\textit{dp}[4]$ 的时候，排列的最后一个元素可以是 $1$ 也可以是 $3$，因此 $\textit{dp}[1]$ 和 $\textit{dp}[3]$ 都会被考虑到，即不同的顺序都会被考虑到。

