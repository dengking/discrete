# [311. 稀疏矩阵的乘法](https://leetcode-cn.com/problems/sparse-matrix-multiplication/) 中等

给定两个 [稀疏矩阵](https://baike.baidu.com/item/稀疏矩阵) : 大小为 `m x k` 的稀疏矩阵 `mat1` 和大小为 `k x n` 的稀疏矩阵 `mat2`，大小为 `m x k` 的稀疏矩阵 `mat1` 和大小为 `k x n` 的稀疏矩阵 `mat2`。你可以假设乘法总是可能的。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/03/12/mult-grid.jpg)

```
输入：mat1 = [[1,0,0],[-1,0,3]], mat2 = [[7,0,0],[0,0,0],[0,0,1]]
输出：[[7,0,0],[-7,0,3]]
```

**示例 2:**

```
输入：mat1 = [[0]], mat2 = [[0]]
输出：[[0]]
```

