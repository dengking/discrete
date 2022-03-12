# [469. 凸多边形](https://leetcode-cn.com/problems/convex-polygon/) 中等

给定 **X-Y** 平面上的一组点 `points` ，其中 `points[i] = [xi, yi]`。这些点按顺序连成一个多边形。

如果该多边形为 **凸** 多边形[（凸多边形的定义）](https://baike.baidu.com/item/凸多边形/)则返回 `true` ，否则返回 `false` 。

你可以假设由给定点构成的多边形总是一个 简单的多边形[（简单多边形的定义）](https://baike.baidu.com/item/简单多边形)。你可以假设由给定点构成的多边形总是一个 简单的多边形[（简单多边形的定义）](https://baike.baidu.com/item/简单多边形)。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/04/09/covpoly1-plane.jpg)

```
输入: points = [[0,0],[0,5],[5,5],[5,0]]
输出: true
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/04/09/covpoly2-plane.jpg)

```
输入: points = [[0,0],[0,10],[10,10],[10,0],[5,5]]
输出: false
```

