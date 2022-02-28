# LeetCode [750. 角矩形的数量](https://leetcode-cn.com/problems/number-of-corner-rectangles/) 中等

给定一个只包含 `0` 和 `1` 的 `m x n` 整数矩阵 `grid` ，返回 *其中 「**角矩形 」**的数量* 。

一个**「角矩形」**是由四个不同的在矩阵上的 `1` 形成的轴对称的矩形。注意只有角的位置才需要为 `1`。

**注意：**4 个 `1` 的位置需要是不同的。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/06/12/cornerrec1-grid.jpg)

```
输入：grid = [[1,0,0,1,0],[0,0,1,0,1],[0,0,0,1,0],[1,0,1,0,1]]
输出：1
解释：只有一个角矩形，角的位置为 grid[1][2], grid[1][4], grid[3][2], grid[3][4]。
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/06/12/cornerrec2-grid.jpg)

```
输入：grid = [[1,1,1],[1,1,1],[1,1,1]]
输出：9
解释：这里有 4 个 2x2 的矩形，4 个 2x3 和 3x2 的矩形和 1 个 3x3 的矩形。
```

**示例 3：**

![img](https://assets.leetcode.com/uploads/2021/06/12/cornerrec3-grid.jpg)

```
输入：grid = [[1,1,1,1]]
输出：0
解释：矩形必须有 4 个不同的角。
```



## [peteyuan](https://leetcode-cn.com/u/peteyuan/) # [C++ 动态规划](https://leetcode-cn.com/problems/number-of-corner-rectangles/solution/c-dong-tai-gui-hua-by-peteyuan/)



## cnblogs [[LeetCode] Number Of Corner Rectangles 边角矩形的数量](https://www.cnblogs.com/grandyang/p/8433813.html)