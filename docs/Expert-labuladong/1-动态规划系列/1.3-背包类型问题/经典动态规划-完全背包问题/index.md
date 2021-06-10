# labuladong [经典动态规划：完全背包问题](https://mp.weixin.qq.com/s/zGJZpsGVMlk-Vc2PEY4RPw)

> NOTE: 
>
> 一、原题: LeetCode [518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/) 中等 
>
> 二、需要和 LeetCode [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/) 进行对比才能够更好地掌握两个问题背后的本质: 
>
> 1、在 labuladong [动态规划详解](https://mp.weixin.qq.com/s/Cw39C9MY9Wr2JlcvBQZMcA)  中 对  LeetCode [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/) 进行了分析。
>
> 2、可以看到，两个问题都让硬币个数是无限多个，这就让每个子问题都相互独立了，这是在  labuladong [动态规划详解](https://mp.weixin.qq.com/s/Cw39C9MY9Wr2JlcvBQZMcA)  中分析过的，这是非常重要的一个性质，也是理解后续实现的一个前提。
>
> 三、通过这个题，是可以看出01背包和完全背包的差异的，参见下面的"第三步，根据「选择」，思考状态转移的逻辑"段，其中对此有着很好的分析
>
> 

零钱兑换 2 是另一种典型背包问题的变体，我们前文已经讲了 [经典动态规划：0-1 背包问题](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485064&idx=1&sn=550705eb67f5e71487c8b218382919d6&chksm=9bd7f880aca071962a5a17d0f85d979d6f0c5a5ce32c84b8fee88e36d451f9ccb3bb47b88f78&scene=21#wechat_redirect) 和 [背包问题变体：相等子集分割](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485103&idx=1&sn=8a9752e18ed528e5c18d973dcd134260&chksm=9bd7f8a7aca071b14c736a30ef7b23b80914c676414b01f8269808ef28da48eb13e90a432fff&scene=21#wechat_redirect)。

本文聊的是 LeetCode 第 518 题 Coin Change 2，题目如下：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHoaEqAyTK5MZLdRia4f8TbwNQb7fZjwicAoF3d7J7EPJibQJm0sYDX0R1MxK1pnP9LGMTpTUic2vzfFw/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```
int change(int amount, int[] coins);
```

PS：至于 Coin Change 1，在我们前文 动态规划套路详解 写过。

**我们可以把这个问题转化为背包问题的描述形式**：

有一个背包，最大容量为`amount`，有一系列物品`coins`，每个物品的重量为`coins[i]`，**每个物品的数量无限**。请问有多少种方法，能够把背包恰好装满？

这个问题和我们前面讲过的两个背包问题，有一个最大的区别就是，每个物品的数量是无限的，这也就是传说中的「**完全背包问题**」，没啥高大上的，无非就是状态转移方程有一点变化而已。

下面就以背包问题的描述形式，继续按照流程来分析。



## 解题思路



### 第二步要明确dp数组的定义

> NOTE: 
>
> 需要对base case进行明确，其实只需要把我"装满"的含义即可，在 labuladong [经典动态规划：0-1背包问题的变体](https://mp.weixin.qq.com/s/OzdkF30p5BHelCi6inAnNg) 中已经讨论过了:
>
> 显然，背包容量为0，对应的是装满，否则就是没有装满，因此: `dp[0][..] = 0， dp[..][0] = 1`。

经过以上的定义，可以得到：

base case 为`dp[0][..] = 0， dp[..][0] = 1`。因为如果不使用任何硬币面值，就无法凑出任何金额；如果凑出的目标金额为 0，那么“无为而治”就是唯一的一种凑法。



### 第三步，根据「选择」，思考状态转移的逻辑

注意，我们这个问题的特殊点在于物品的数量是无限的，所以这里和之前写的背包问题文章有所不同。

> NOTE: 
>
> 一、上述所说的正是01背包和完全背包的差异所在，具体体现在: 
>
> **如果你把这第`i`个物品装入了背包**
>
> 1、01背包: 每个物品只能够被选一次，因此 `dp[i][j]`应该等于`dp[i-1][j-coins[i-1]]`。
>
> 2、完全背包: 每个物品只能够被选无数次，因此 `dp[i][j]`应该等于`dp[i][j-coins[i-1]]`。
>
> 这是两者的显著差异。

**如果你不把这第`i`个物品装入背包**，也就是说你不使用`coins[i]`这个面值的硬币，那么凑出面额`j`的方法数`dp[i][j]`应该等于`dp[i-1][j]`，继承之前的结果。

**如果你把这第`i`个物品装入了背包**，也就是说你使用`coins[i]`这个面值的硬币，那么`dp[i][j]`应该等于`dp[i][j-coins[i-1]]`。

### 实现

**综上就是两种选择，而我们想求的`dp[i][j]`是「共有多少种凑法」，所以`dp[i][j]`的值应该是以上两种选择的结果之和**：

```Java
for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= amount; j++) {
        if (j - coins[i-1] >= 0)
            dp[i][j] = dp[i - 1][j] 
                     + dp[i][j-coins[i-1]];
return dp[N][W]
```

**最后一步，把伪码翻译成代码，处理一些边界情况**。

我用 Java 写的代码，把上面的思路完全翻译了一遍，并且处理了一些边界问题：

```Java
int change(int amount, int[] coins) {
    int n = coins.length;
    int[][] dp = amount int[n + 1][amount + 1];
    // base case
    for (int i = 0; i <= n; i++) 
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= amount; j++)
            if (j - coins[i-1] >= 0)
                dp[i][j] = dp[i - 1][j] 
                         + dp[i][j - coins[i-1]];
            else 
                dp[i][j] = dp[i - 1][j];
    }
    return dp[n][amount];
}
```

而且，我们通过观察可以发现，`dp`数组的转移只和`dp[i][..]`和`dp[i-1][..]`有关，所以可以压缩状态，进一步降低算法的空间复杂度：

```Java
int change(int amount, int[] coins) {
    int n = coins.length;
    int[] dp = new int[amount + 1];
    dp[0] = 1; // base case
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= amount; j++)
            if (j - coins[i] >= 0)
                dp[j] = dp[j] + dp[j-coins[i]];

    return dp[amount];
}
```

这个解法和之前的思路完全相同，将二维`dp`数组压缩为一维，时间复杂度 O(N*amount)，空间复杂度 O(amount)。

至此，这道零钱兑换问题也通过背包问题的框架解决了。