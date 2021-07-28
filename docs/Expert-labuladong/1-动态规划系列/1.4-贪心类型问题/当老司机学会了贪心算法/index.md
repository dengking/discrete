# labuladong [当老司机学会了贪心算法](https://mp.weixin.qq.com/s/k-z_oewAqMYc3vpmOm4gEQ) 

> NOTE: 
>
> LeetCode [134. 加油站](https://leetcode-cn.com/problems/gas-station/)



## 图像解法

> NOTE: 
>
> 其实，思路非常简单: 
>
> 保证 `sum` (或者说 "汽车的油量" )一直都大于0

**有了这个环形数组，我们需要判断这个环形数组中是否能够找到一个起点`start`，使得从这个起点开始的累加和一直大于等于 0**。

如何判断是否存在这样一个起点`start`？又如何计算这个起点`start`的值呢？

我们不妨就把 0 作为起点，计算累加和的代码非常简单：

```Java
int n = gas.length, sum = 0;
for (int i = 0; i < n; i++) {
    // 计算累加和
    sum += gas[i] - cost[i];
}
```

`sum`就相当于是油箱中油量的变化，上述代码中`sum`的变化过程可能是这样的：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFBqGqia6FfNkXMz8dMTghNGOtyw0arMOy7gEJbueBBc4mf48MGI5xQxwphrKXxTF94X0uuJYAuwpw/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

显然，上图将 0 作为起点肯定是不行的，因为`sum`在变化的过程中小于 0 了，不符合我们「累加和一直大于等于 0」的要求。

那如果 0 不能作为起点，谁可以作为起点呢？

看图说话，图像的最低点最有可能可以作为起点：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFBqGqia6FfNkXMz8dMTghNG3DZFI5pIwceDMLO5vibMnWtaARMrcaicOBJSGjgicicibmsmgibicZUB4hXrg/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

**如果把这个「最低点」作为起点，就是说将这个点作为坐标轴原点，就相当于把图像「最大限度」向上平移了**。

再加上这个数组是环形数组，最低点左侧的图像可以接到图像的最右侧：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdFBqGqia6FfNkXMz8dMTghNGINeCKDjhgjROQonon8PP8j5YLibCSqSrxVP0xITUMwKfYKeAlibzT8jg/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

这样，整个图像都保持在 x 轴以上，所以这个最低点 4，就是题目要求我们找的起点。

不过，经过平移后图像一定全部在 x 轴以上吗？不一定，因为还有无解的情况：

**如果`sum(gas[...]) < sum(cost[...])`，总油量小于总的消耗，那肯定是没办法环游所有站点的**。

综上，我们就可以写出代码：

```Java
int canCompleteCircuit(int[] gas, int[] cost) {
    int n = gas.length;
    // 相当于图像中的坐标点和最低点
    int sum = 0, minSum = Integer.MAX_VALUE;
    int start = 0;
    for (int i = 0; i < n; i++) {
        sum += gas[i] - cost[i];
        if (sum < minSum) {
            // 经过第 i 个站点后，使 sum 到达新低
            // 所以站点 i + 1 就是最低点（起点）
            start = i + 1;
            minSum = sum;
        }
    }
    if (sum < 0) {
        // 总油量小于总的消耗，无解
        return -1;
    }
    // 环形数组特性
    return start == n ? 0 : start;
}
```

## 贪心解法

> NOTE: 
>
> 下面的这个推论是非常容易理解的

用贪心思路解决这道题的关键在于以下这个结论：

**如果选择站点`i`作为起点「恰好」无法走到站点`j`，那么`i`和`j`中间的任意站点`k`都不可能作为起点**。

比如说，如果从站点`1`出发，走到站点`5`时油箱中的油量「恰好」减到了负数，那么说明站点`1`「恰好」无法到达站点`5`；那么你从站点`2,3,4`任意一个站点出发都无法到达`5`，因为到达站点`5`时油箱的油量也必然被减到负数。

如何证明这个结论？

假设`tank`记录当前油箱中的油量，如果从站点`i`出发（`tank = 0`），走到`j`时恰好出现`tank < 0`的情况，那说明走到`i, j`之间的任意站点`k`时都满足`tank > 0`，对吧。

如果把`k`作为起点的话，相当于在站点`k`时`tank = 0`，那走到`j`时必然有`tank < 0`，也就是说`k`肯定不能是起点。

拜托，从`i`出发走到`k`好歹`tank > 0`，都无法达到`j`，现在你还让`tank = 0`了，那更不可能走到`j`了对吧。

**综上，这个结论就被证明了**。

回想一下我们开头说的暴力解法是怎么做的？

如果我发现从`i`出发无法走到`j`，那么显然`i`不可能是起点。

现在，我们发现了一个新规律，可以推导出什么？

如果我发现从`i`出发无法走到`j`，那么`i`以及`i, j`之间的所有站点都不可能作为起点。

看到冗余计算了吗？看到优化的点了吗？

**这就是贪心思路的本质，如果找不到重复计算，那就通过问题中一些隐藏较深的规律，来减少冗余计算**。

根据这个结论，就可以写出如下代码：

```Java
int canCompleteCircuit(int[] gas, int[] cost) {
    int n = gas.length;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += gas[i] - cost[i];
    }
    if (sum < 0) {
        // 总油量小于总的消耗，无解
        return -1;
    }
    // 记录油箱中的油量
    int tank = 0;
    // 记录起点
    int start = 0;
    for (int i = 0; i < n; i++) {
        tank += gas[i] - cost[i];
        if (tank < 0) {
            // 无法从 start 走到 i
            // 所以站点 i + 1 应该是起点
            tank = 0;
            start = i + 1;
        }
    }
    return start == n ? 0 : start;
}
```

这个解法的时间复杂度也是 O(N)，和之前图像法的解题思路有所不同，但代码非常类似。

**其实，你可以把这个解法的思路结合图像来思考，可以发现它们本质上是一样的，只是理解方式不同而已**。

对于这种贪心算法，没有特别套路化的思维框架，主要还是靠多做题多思考，将题目的场景进行抽象的联想，找出隐藏其中的规律，从而减少计算量，进行效率优化。

