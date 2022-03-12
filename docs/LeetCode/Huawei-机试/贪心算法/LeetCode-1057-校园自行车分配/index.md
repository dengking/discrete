# [1057. 校园自行车分配](https://leetcode-cn.com/problems/campus-bikes/) 中等

在 X-Y 平面上表示的校园中，有 `n` 名工人和 `m` 辆自行车，其中 `n <= m` 。

给定一个长度为 `n` 的数组 `workers` ，其中 `worker [i] = [xi, yi]` 表示第 `i` 个工人的位置。你也得到一个长度为 `m` 的自行车数组 `bikers` ，其中 `bikes[j] = [xj, yj]` 是第 `j` 辆自行车的位置。所有给定的位置都是 **唯一** 的。

我们需要为每位工人分配一辆自行车。在所有可用的自行车和工人中，我们选取彼此之间 **曼哈顿距离** 最短的工人自行车对 `(workeri, bikej)` ，并将其中的自行车分配給工人。

如果有多个 `(workeri, bikej)` 对之间的 **曼哈顿距离** 相同，那么我们选择 **工人索引最小** 的那对。类似地，如果有多种不同的分配方法，则选择 **自行车索引最小** 的一对。断重复这一过程，直到所有工人都分配到自行车为止。

返回长度为 `n` 的向量 `answer`，其中 `answer[i]` 是第 `i` 位工人分配到的自行车的索引（**从 0 开始**）。

给定两点 `p1` 和 `p2` 之间的 **曼哈顿距离** 为 `Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|`。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2019/03/06/1261_example_1_v2.png)

```
输入：workers = [[0,0],[2,1]], bikes = [[1,2],[3,3]]
输出：[1,0]
解释：工人 1 分配到自行车 0，因为他们最接近且不存在冲突，工人 0 分配到自行车 1 。所以输出是 [1,0]。
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2019/03/06/1261_example_2_v2.png)

```
输入：workers = [[0,0],[1,1],[2,0]], bikes = [[1,0],[2,2],[2,1]]
输出：[0,2,1]
解释：工人 0 首先分配到自行车 0 。工人 1 和工人 2 与自行车 2 距离相同，因此工人 1 分配到自行车 2，工人 2 将分配到自行车 1 。因此输出为 [0,2,1]。
```

## 我的总结

在阅读了 [C++计算所有{worker, bike}距离存到map（自动排序）](https://leetcode-cn.com/problems/campus-bikes/solution/cji-suan-suo-you-worker-bikeju-chi-cun-dao-mapzi-d/) 后，我发现这道题其实本质上是按照多个维度的排序：首先按照距离，然后按照索引，其实这就考察了我们对数据结构的使用，如何使用数据结构来存储，与这个题目比较类似的是 LRU 这种纯数据结构设计问题，其实这个题目也比较偏向这个方向。



## [C++计算所有{worker, bike}距离存到map（自动排序）](https://leetcode-cn.com/problems/campus-bikes/solution/cji-suan-suo-you-worker-bikeju-chi-cun-dao-mapzi-d/)

> NOTE:
>
> 多个维度的排序：首先按照距离，然后按照索引，其实这就考察了我们对数据结构的使用，如何使用数据结构来存储，这个解答比较好。

使用一个有序的map结构：key为worker到bike的距离；value为{工人序号,自行车序号}的vector，遍历计算所有工人到所有自行车的距离，若有相同距离自然按照序号从小到大放到vector里，最后遍历这个有序的map，得到答案。

其中使用了2个bool数组标记已使用过的工人和自行车。

