# labuladong [毕 业 旅 行](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491204&idx=1&sn=3f03f4da933ffa0baf4eb05f444d85e3&scene=21#wechat_redirect) / [旅游省钱大法：加权最短路径](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491204&idx=1&sn=3f03f4da933ffa0baf4eb05f444d85e3&scene=21#wechat_redirect)

> NOTE:
>
> leetcode [787. K 站中转内最便宜的航班](https://leetcode-cn.com/problems/cheapest-flights-within-k-stops/)

**很明显，这题就是个加权有向图中求最短路径的问题**。

说白了，就是给你一幅加权有向图，让你求`src`到`dst`权重最小的一条路径，**同时要满足，这条路径最多不能超过`K + 1`条边**（经过`K`个节点相当于经过`K + 1`条边。

## BFS 算法思路

我们前文 [BFS 算法框架详解](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485134&idx=1&sn=fd345f8a93dc4444bcc65c57bb46fc35&chksm=9bd7f8c6aca071d04c4d383f96f2b567ad44dc3e67d1c3926ec92d6a3bcc3273de138b36a0d9&scene=21#wechat_redirect) 中说到，求最短路径，肯定可以用 BFS 算法来解决。

因为 BFS 算法相当于从起始点开始，一步一步向外扩散，那当然是离起点越近的节点越先被遍历到，如果 BFS 遍历的过程中遇到终点，那么走的肯定是最短路径。

不过呢，我们在 [BFS 算法框架详解](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485134&idx=1&sn=fd345f8a93dc4444bcc65c57bb46fc35&chksm=9bd7f8c6aca071d04c4d383f96f2b567ad44dc3e67d1c3926ec92d6a3bcc3273de138b36a0d9&scene=21#wechat_redirect) 用的是普通的队列`Queue`来遍历多叉树，而对于加权图的最短路径来说，普通的队列不管用了，得用优先级队列`PriorityQueue`。

为什么呢？也好理解，在多叉树（或者扩展到无权图）的遍历中，与其说边没有权重，不如说每条边的权重都是 1，起点与终点之间的路径权重就是它们之间「边」的条数。

这样，按照 BFS 算法一步步向四周扩散的逻辑，先遍历到的节点和起点之间的「边」更少，累计的权重当然少。

换言之，先进入`Queue`的节点就是离起点近的，路径权重小的节点。

> NOTE:
>
> 上述总结非常好，它能够帮助我们理解Dijkstra算法

**但对于加权图，路径中边的条数和路径的权重并不是正相关的关系了**，有的路径可能边的条数很少，但每条边的权重都很大，那显然这条路径权重也会很大，很难成为**最短路径**。

比如题目给的这个例子：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHt5Bn0iaLGcW7vibicK42lwFwicaIuNHE9PEIIOwicNnjIq1ESjjY1vqmJJqPl98Ht0smDFJg5O9lQIQA/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

你是可以一步从`0`走到`2`，但路径权重不见得是最小的。

所以，对于加权图的场景，我们需要优先级队列「自动排序」的特性，将路径权重较小的节点排在队列前面，以此为基础施展 BFS 算法。

## 动态规划思路

我们前文 [动态规划核心套路详解](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484731&idx=1&sn=f1db6dee2c8e70c42240aead9fd224e6&chksm=9bd7fb33aca07225bee0b23a911c30295e0b90f393af75eca377caa4598ffb203549e1768336&scene=21#wechat_redirect) 中说过，求最值的问题，很多都可能使用**动态规划**来求解。

**加权最短路径问题**，再加个`K`的限制也无妨，不也是个求最值的问题嘛，动态规划统统拿下。

### 加权最短路径

**我们先不管`K`的限制**，单就「加权最短路径」这个问题来看看，它怎么就是个动态规划问题了呢？

比方说，现在我想计算`src`到`dst`的最短路径：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHt5Bn0iaLGcW7vibicK42lwFwicfiaYQBQ74yndvAsDU3eib8hiasBgqpeSicdCGypQ7ZD2iaOEPxUwzxTYGQ/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

最小权重是多少？我不知道。

但我可以把问题进行分解：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHt5Bn0iaLGcW7vibicK42lwFwsdlzoXmFtEQHhDjQFc3OMnibYEXkqt2WibEljiatBZWZG0icAjW1CfuITw/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)



`s1, s2`是指向`dst`的相邻节点，它们之间的权重我是知道的，分别是`w1, w2`。

只要我知道了从`src`到`s1, s2`的最短路径，我不就知道`src`到`dst`的最短路径了吗！

```
minPath(src, dst) = min(
    minPath(src, s1) + w1, 
    minPath(src, s2) + w2
)
```

这其实就是递归关系了，就是这么简单。

