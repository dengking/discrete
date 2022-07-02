# labuladong [毕 业 旅 行](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491204&idx=1&sn=3f03f4da933ffa0baf4eb05f444d85e3&scene=21#wechat_redirect) / [旅游省钱大法：加权最短路径](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491204&idx=1&sn=3f03f4da933ffa0baf4eb05f444d85e3&scene=21#wechat_redirect)

> NOTE:
>
> 一、leetcode [787. K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops/)
>
> 二、这道题展示了使用自顶向下的方式解决图加权最短路径问题，正如作者所言：
>
> > 至此，这道题就通过自顶向下的递归方式解决了。当然，完全可以按照这个解法衍生出自底向上迭代的动态规划解法，但由于篇幅所限，我就不写了，反正本质上都是一样的。
>
> 何为自顶向下呢？其实就是自终点向起点反向去找，这和tree回溯法非常类似。
>
> 它通过预处理的方式得到每个节点的入度信息，这是使用自顶向下的计算方式的前提。
>
> 三、关于中转次数和边数的转换
>
> 最简单的情况：两个直接相连的节点，它们的中转次数是0，但是边数是1，需要经过一次递归调用到达，或者说需要走一次。

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

你是可以一步从`0`走到`2`，但**路径权重**不见得是最小的。

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

```pseudocode
minPath(src, dst) = min(
    minPath(src, s1) + w1, 
    minPath(src, s2) + w2
)
```

> NOTE:
>
> s1 和 s2 都是dst的parent node。

这其实就是递归关系了，就是这么简单。

### 加上K的限制

**不过别忘了，题目对我们的最短路径还有个「路径上不能超过`K + 1`条边」的限制**。

> NOTE:
>
> 一、K次转折，对应了K条边

那么我们不妨定义这样一个`dp`函数：

```c++
int dp(int s, int k);
```

函数的定义如下：

**从起点`src`出发，`k`步之内（一步就是一条边）到达节点`s`的最小路径权重为`dp(s, k)`**。

那么，`dp`函数的 base case 就显而易见了：

```c++
// 定义：从 src 出发，k 步之内到达 s 的最小成本
    int dp(int s, int k) {
        // 从 src 到 src，一步都不用走
        if (s == src) {
            return 0;
        }
        // 如果步数用尽，就无解了
        if (k == 0) {
            return -1;
        }

        // ...
    }
```

题目想求的**最小机票开销**就可以用`dp(dst, K+1)`来表示：

```c++
int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
    // 将中转站个数转化成边的条数
    K++;
    //...
    return dp(dst, K);
```

> NOTE:
>
> 思考：为什么要"将中转站个数转化成边的条数"？因为如果中转K次，则意味着从**终点**要经过K+1条边才能够到达**起点**，而上述解法，是沿着边来进行自终点向起点的反向寻找的。

#### 状态转移方程

添加了一个`K`条边的限制，状态转移方程怎么写呢？其实和刚才是一样的：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHt5Bn0iaLGcW7vibicK42lwFwyzhcgwZhZmPm2d6L29ULOE99GmiaDNlfoiaeewZpCiaz8dCKwIibdrKibjA/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

`K`步之内从`src`到`dst`的最小路径权重是多少？我不知道。

但我可以把问题分解：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHt5Bn0iaLGcW7vibicK42lwFweqU5em6TmshMMqOsXhrmSiaxAGmgInCpibZ12RGsDsYt677Dtjp0VWNg/640?wx_fmt=jpeg&wxfrom=5&wx_lazy=1&wx_co=1)

`s1, s2`是指向`dst`的相邻节点，我只要能够在`K - 1`步之内从`src`到达`s1, s2`，那我就可以在`K`步之内从`src`到达`dst`。

也就是如下关系式：

```c++
dp(dst, k) = min(
    dp(s1, k - 1) + w1, 
    dp(s2, k - 1) + w2
)
```

这就是新的状态转移方程，如果你能看懂这个算式，就已经可以解决这道题了。

## 代码实现

根据上述思路，我怎么知道`s1, s2`是指向`dst`的相邻节点，他们之间的权重是`w1, w2`？

我希望给一个节点，就能知道有谁指向这个节点，还知道它们之间的权重，对吧。

专业点说，得用一个数据结构记录每个节点的「**入度**」**indegree**：

```java
// 哈希表记录每个点的入度
// to -> [from, price]
HashMap<Integer, List<int[]>> indegree;
int src, dst;

public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
    // 将中转站个数转化成边的条数
    K++;
    this.src = src;
    this.dst = dst;

    indegree = new HashMap<>();
    for (int[] f : flights) {
        int from = f[0];
        int to = f[1];
        int price = f[2];
        // 记录谁指向该节点，以及之间的权重
        indegree.putIfAbsent(to, new LinkedList<>());
        indegree.get(to).add(new int[] {from, price});
    }

    return dp(dst, K);
}
```

有了`indegree`存储入度，那么就可以具体实现`dp`函数了：

```java
// 定义：从 src 出发，k 步之内到达 s 的最短路径权重
int dp(int s, int k) {
    // base case
    if (s == src) {
        return 0;
    }
    if (k == 0) {
        return -1;
    }
    // 初始化为最大值，方便等会儿取最小值
    int res = Integer.MAX_VALUE;
    if (indegree.containsKey(s)) {
        // 当 s 有入度节点时，分解为子问题
        for (int[] v : indegree.get(s)) {
            int from = v[0];
            int price = v[1];
            // 从 src 到达相邻的入度节点所需的最短路径权重
            int subProblem = dp(from, k - 1);
            // 跳过无解的情况
            if (subProblem != -1) {
                res = Math.min(res, subProblem + price);
            }
        }
    }
    // 如果还是初始值，说明此节点不可达
    return res == Integer.MAX_VALUE ? -1 : res;
}
```

### 重叠字问题

有之前的铺垫，这段解法逻辑应该是很清晰的。当然，对于动态规划问题，肯定要消除**重叠子问题**。

为什么有**重叠子问题**？很简单，如果某个节点同时指向两个其他节点，那么这两个节点就有相同的一个**入度节点**，就会产生重复的递归计算。

怎么消除**重叠子问题**？找问题的「状态」。

状态是什么？在问题分解（状态转移）的过程中变化的，就是状态。

**谁在变化？显然就是`dp`函数的参数`s`和`k`，每次递归调用，目标点`s`和步数约束`k`在变化**。

所以，本题的状态有两个，应该算是二维动态规划，我们可以用一个`memo`二维数组或者哈希表作为备忘录，减少重复计算。

### 备忘录法

我们选用二维数组做备忘录吧，注意`K`是从 1 开始算的，所以备忘录初始大小要再加一：

```c++
int src, dst;
HashMap<Integer, List<int[]>> indegree;
// 备忘录
int[][] memo;

public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
    K++;
    this.src = src;
    this.dst = dst;
    // 初始化备忘录，全部填一个特殊值
    memo = new int[n][K + 1];
    for (int[] row : memo) {
        Arrays.fill(row, -888);
    }

    // 其他不变
    // ...

    return dp(dst, K);
}

// 定义：从 src 出发，k 步之内到达 s 的最小成本
int dp(int s, int k) {
    // base case
    if (s == src) {
        return 0;
    }
    if (k == 0) {
        return -1;
    }
    // 查备忘录，防止冗余计算
    if (memo[s][k] != -888) {
        return memo[s][k];
    }

    // 状态转移不变
    // ...

    // 存入备忘录
    memo[s][k] = res == Integer.MAX_VALUE ? -1 : res;
    return memo[s][k];
}
```

备忘录初始值为啥初始为 -888？前文 [base case 和备忘录的初始值怎么定](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247490966&idx=1&sn=a3d80ad8d4fc7f83633aed06cc2ca2e4&chksm=9bd7e39eaca06a88e4de6e0d22ae8d82f92ed7aac5a87ceadf5173a75370e4964d87cb0b25e5&scene=21#wechat_redirect) 说过，随便初始化一个无意义的值就行。

## 总结

至此，这道题就通过自顶向下的递归方式解决了。当然，完全可以按照这个解法衍生出自底向上迭代的动态规划解法，但由于篇幅所限，我就不写了，反正本质上都是一样的。