# labuladong [动态规划详解](https://mp.weixin.qq.com/s/Cw39C9MY9Wr2JlcvBQZMcA) 

## 求解最值

**动态规划问题的一般形式就是求最值**。动态规划其实是运筹学的一种最优化方法，只不过在计算机问题上应用比较多，比如说让你求**最长**递增子序列呀，**最小**编辑距离呀等等。

## 穷举

既然是要求最值，核心问题是什么呢？**求解动态规划的核心问题是穷举**。因为要求最值，肯定要把所有可行的答案穷举出来，然后在其中找最值呗。

> NOTE: 
>
> 1、"systematic method-罗列所有可能性"
>
> 

动态规划就这么简单，就是穷举就完事了？我看到的动态规划问题都很难啊！

## 动态规划三要素

### 重叠子问题

> NOTE: 
>
> 1、参见 `Overlapping-subproblem` 章节

首先，动态规划的穷举有点特别，因为这类问题**存在「重叠子问题」**，如果暴力穷举的话效率会极其低下，所以需要「备忘录」或者「DP table」来优化穷举过程，避免不必要的计算。

### 最优子结构

而且，动态规划问题一定会**具备「最优子结构」**，才能通过子问题的最值得到原问题的最值。

> NOTE: 
>
> 1、参见 `Optimal-substructure` 章节

### 状态转移方程

另外，虽然动态规划的核心思想就是穷举求最值，但是问题可以千变万化，穷举所有可行解其实并不是一件容易的事，只有列出正确的「**状态转移方程**」才能正确地穷举。

> NOTE: 
>
> 1、"Recurrence relation 递归 状态转移 方程 公式"
>
> 2、所谓**状态转移方程**，它所描述的其实就是 **原问题** 和 **子问题** 之间的关系

以上提到的重叠子问题、最优子结构、状态转移方程就是动态规划三要素。

#### 如何写出状态转移方程

具体什么意思等会会举例详解，但是在实际的算法问题中，**写出状态转移方程是最困难的**，这也就是为什么很多朋友觉得动态规划问题困难的原因，我来提供我研究出来的一个思维框架，辅助你思考状态转移方程：

**明确「状态」 -> 定义 dp 数组/函数的含义 -> 明确「选择」-> 明确 base case。**

下面通过斐波那契数列问题和凑零钱问题来详解动态规划的基本原理。前者主要是让你明白什么是重叠子问题（斐波那契数列严格来说不是动态规划问题），后者主要集中于如何列出状态转移方程。

请读者不要嫌弃这个例子简单，**只有简单的例子才能让你把精力充分集中在算法背后的通用思想和技巧上，而不会被那些隐晦的细节问题搞的莫名其妙**。想要困难的例子，历史文章里有的是。

## 一、斐波那契数列

### 1、暴力递归

斐波那契数列的数学形式就是递归的，写成代码就是这样：

```C++
int fib(int N) {
    if (N == 1 || N == 2) return 1;
    return fib(N - 1) + fib(N - 2);
}
```

PS：但凡遇到需要递归的问题，最好都画出递归树，这对你分析算法的复杂度，寻找算法低效的原因都有巨大帮助。

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHQbgLwcCQ3KTwWiaU7h29jiaLtdrAjTRb4GnR1eof972kGzX4kEzgLbRqbpUAXl84k36C74FC525OA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

这个递归树怎么理解？就是说想要计算原问题`f(20)`，我就得先计算出子问题`f(19)`和`f(18)`，然后要计算`f(19)`，我就要先算出子问题`f(18)`和`f(17)`，以此类推。最后遇到`f(1)`或者`f(2)`的时候，结果已知，就能直接返回结果，递归树不再向下生长了。

### 2、带备忘录的递归解法

```C++
int fib(int N) {
    if (N < 1) return 0;
    // 备忘录全初始化为 0
    vector<int> memo(N + 1, 0);
    // 初始化最简情况
    return helper(memo, N);
}

int helper(vector<int>& memo, int n) {
    // base case 
    if (n == 1 || n == 2) return 1;
    // 已经计算过
    if (memo[n] != 0) return memo[n];
    memo[n] = helper(memo, n - 1) + 
                helper(memo, n - 2);
    return memo[n];
}
```

现在，画出递归树，你就知道「备忘录」到底做了什么：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHQbgLwcCQ3KTwWiaU7h29jiaVaic23mBUrDpNLUYXr5FvBxuI81zltq81P323FwQPzkKZSibML7icNXUQ/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

实际上，带「备忘录」的递归算法，把一棵存在巨量冗余的递归树通过「剪枝」，改造成了一幅不存在冗余的递归图，极大减少了子问题（即递归图中节点）的个数。

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHCKOB569u3mXar1m8EOjzjJHRljPqHfWFYA5dWSFxBW0BwCrKv66At3Aia6Z6bQLySiaVicZMia4aE2Q/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

### 3、dp 数组的迭代解法

有了上一步「备忘录」的启发，我们可以把这个「备忘录」独立出来成为一张表，就叫做 DP table 吧，在这张表上完成「自底向上」的推算岂不美哉！

```C++
int fib(int N) {
    vector<int> dp(N + 1, 0);
    // base case
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[N];
}
```

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHQbgLwcCQ3KTwWiaU7h29jiaRibV4JGowlklxBrLCNDnYE5oqRd02tWEsFNkNdBKIJU0olymFYlZrLg/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



这个例子的最后，讲一个细节优化。细心的读者会发现，根据斐波那契数列的状态转移方程，当前状态只和之前的两个状态有关，其实并不需要那么长的一个 DP table 来存储所有的状态，只要想办法存储之前的两个状态就行了。所以，可以进一步优化，把空间复杂度降为 O(1)：

```C++
int fib(int n) {
    if (n == 2 || n == 1) 
        return 1;
    int prev = 1, curr = 1;
    for (int i = 3; i <= n; i++) {
        int sum = prev + curr;
        prev = curr;
        curr = sum;
    }
    return curr;
}
```

## 二、凑零钱问题

> NOTE: 
>
> 一、这段关于"状态、选择、base case"的描述是非常好的，能够帮助我们快速地写出状态转移方程
>
> 二、原题 leetcode [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/) 中等
>
> 三、凑零钱问题是典型的完全背包问题，这在下面的文章中进行了介绍：
>
> 1、[一篇文章吃透背包问题！（细致引入+解题模板+例题分析+代码呈现）](https://leetcode-cn.com/problems/partition-equal-subset-sum/solution/yi-pian-wen-zhang-chi-tou-bei-bao-wen-ti-a7dd/)
>
> 

先看下题目：给你`k`种面值的硬币，面值分别为`c1, c2 ... ck`，每种硬币的数量无限，再给一个总金额`amount`，问你**最少**需要几枚硬币凑出这个金额，如果不可能凑出，算法返回 -1 。算法的函数签名如下：

```C++
// coins 中是可选硬币面值，amount 是目标金额
int coinChange(int[] coins, int amount);
```

比如说`k = 3`，面值分别为 1，2，5，总金额`amount = 11`。那么最少需要 3 枚硬币凑出，即 11 = 5 + 5 + 1。

你认为计算机应该如何解决这个问题？显然，就是把所有肯能的凑硬币方法都穷举出来，然后找找看最少需要多少枚硬币。

### 1、暴力递归

#### 「最优子结构」子问题相互独立

首先，这个问题是动态规划问题，因为它具有「最优子结构」。**要符合「最优子结构」，子问题间必须互相独立**。啥叫相互独立？你肯定不想看数学证明，我用一个直观的例子来讲解。

比如说，你的原问题是考出最高的总成绩，那么你的子问题就是要把语文考到最高，数学考到最高…… 为了每门课考到最高，你要把每门课相应的选择题分数拿到最高，填空题分数拿到最高…… 当然，最终就是你每门课都是满分，这就是最高的总成绩。

得到了正确的结果：最高的总成绩就是总分。因为这个过程符合最优子结构，“每门科目考到最高”这些子问题是互相独立，互不干扰的。

但是，如果加一个条件：你的语文成绩和数学成绩会互相制约，此消彼长。这样的话，显然你能考到的最高总成绩就达不到总分了，按刚才那个思路就会得到错误的结果。因为子问题并不独立，语文数学成绩无法同时最优，所以最优子结构被破坏。

回到凑零钱问题，为什么说它符合最优子结构呢？比如你想求`amount = 11`时的最少硬币数（原问题），如果你知道凑出`amount = 10`的最少硬币数（子问题），你只需要把子问题的答案加一（再选一枚面值为 1 的硬币）就是原问题的答案，因为硬币的数量是没有限制的，子问题之间没有相互制，是互相独立的。

> NOTE: 
>
> 需要注意的是: "子问题相互独立"是使用"divide conquer-problem原问题subproblem子问题"的一个前提；
>
> 对于 LeetCode [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/) 、LeetCode [518. 零钱兑换 II](https://leetcode-cn.com/problems/coin-change-2/) ，它们的题目要求中，都给出了硬币个数是无限的，这就保证了"子问题相互独立"。是采用DP进行解决的前提条件。

#### 写出状态转移方程

那么，既然知道了这是个动态规划问题，就要思考**如何列出正确的状态转移方程**。

**先确定「状态」**，也就是原问题和子问题中变化的变量。由于硬币数量无限，所以唯一的状态就是目标金额`amount`。

**然后确定`dp`函数的定义**：函数 dp(n)表示，当前的目标金额是`n`，至少需要`dp(n)`个硬币凑出该金额。

**然后确定「选择」并择优**，也就是对于每个状态，可以做出什么选择改变当前状态。具体到这个问题，无论当的目标金额是多少，选择就是从面额列表`coins`中选择一个硬币，然后目标金额就会减少：

```C++
# 伪码框架
def coinChange(coins: List[int], amount: int):
    # 定义：要凑出金额 n，至少要 dp(n) 个硬币
    def dp(n):
        # 做选择，需要硬币最少的那个结果就是答案
        for coin in coins:
            res = min(res, 1 + dp(n - coin))
        return res
    # 我们要求目标金额是 amount
    return dp(amount)
```

**最后明确 base case**，显然目标金额为 0 时，所需硬币数量为 0；当目标金额小于 0 时，无解，返回 -1：

```python
def coinChange(coins: List[int], amount: int):

    def dp(n):
        # base case
        if n == 0: return 0
        if n < 0: return -1
        # 求最小值，所以初始化为正无穷
        res = float('INF')
        for coin in coins:
            subproblem = dp(n - coin)
            # 子问题无解，跳过
            if subproblem == -1: continue
            res = min(res, 1 + subproblem)

        return res if res != float('INF') else -1

    return dp(amount)
```

至此，状态转移方程其实已经完成了，以上算法已经是暴力解法了，以上代码的数学形式就是状态转移方程：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_png/gibkIz0MVqdHQbgLwcCQ3KTwWiaU7h29jiaps8WiaDp8viaojL9iciacVgjyfgz6jL5ZFC2kNIn23N5IlzCJ1IicoeggXw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

至此，这个问题其实就解决了，只不过需要消除一下重叠子问题，比如`amount = 11, coins = {1,2,5}`时画出递归树看看：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHCKOB569u3mXar1m8EOjzjlFK8ZK8CwCE16ydjxjZsuvmcibr6FHEhbA5ydcyGLNWniaxjq8pEU6EQ/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#### 时间复杂度分析：子问题总数 x 解决每个子问题的时间

子问题总数为递归树节点个数，这个比较难看出来，是 O(n^k)，总之是指数级别的。每个子问题中含有一个 for 循环，复杂度为 O(k)。所以总时间复杂度为 O(k * n^k)，指数级别。

### 2、带备忘录的递归

只需要稍加修改，就可以通过备忘录消除子问题：

```python
def coinChange(coins: List[int], amount: int):
    # 备忘录
    memo = dict()
    def dp(n):
        # 查备忘录，避免重复计算
        if n in memo: return memo[n]

        if n == 0: return 0
        if n < 0: return -1
        res = float('INF')
        for coin in coins:
            subproblem = dp(n - coin)
            if subproblem == -1: continue
            res = min(res, 1 + subproblem)

        # 记入备忘录
        memo[n] = res if res != float('INF') else -1
        return memo[n]

    return dp(amount)
```

不画图了，很显然「备忘录」大大减小了子问题数目，完全消除了子问题的冗余，所以子问题总数不会超过金额数 n，即子问题数目为 O(n)。处理一个子问题的时间不变，仍是 O(k)，所以总的时间复杂度是 O(kn)。

### 3、dp 数组的迭代解法

当然，我们也可以自底向上使用 dp table 来消除重叠子问题，`dp`数组的定义和刚才`dp`函数类似，定义也是一样的：

**`dp[i] = x`表示，当目标金额为`i`时，至少需要`x`枚硬币**。

```c++
int coinChange(vector<int>& coins, int amount) {
    // 数组大小为 amount + 1，初始值也为 amount + 1
    vector<int> dp(amount + 1, amount + 1);
    // base case
    dp[0] = 0;
    for (int i = 0; i < dp.size(); i++) {
        // 内层 for 在求所有子问题 + 1 的最小值
        for (int coin : coins) {
            // 子问题无解，跳过
            if (i - coin < 0) continue;
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}
```

> NOTE:
>
> 一、上述问题，在写的时候，是非常容易出现integer overflow的

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHQbgLwcCQ3KTwWiaU7h29jiaKTgMynOUL4MU9S1VF4Rnc9AmFPrzhTPvqt1gclzGEE8fMSblGMczqw/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

PS：为啥`dp`数组初始化为`amount + 1`呢，因为凑成`amount`金额的硬币数最多只可能等于`amount`（全用 1 元面值的硬币），所以初始化为`amount + 1`就相当于初始化为正无穷，便于后续取最小值。

## 三、最后总结

**计算机解决问题其实没有任何奇技淫巧，它唯一的解决办法就是穷举**，穷举所有可能性。算法设计无非就是先思考“如何穷举”，然后再追求“如何聪明地穷举”。

列出动态转移方程，就是在解决“如何穷举”的问题。之所以说它难，一是因为很多穷举需要递归实现，二是因为有的问题本身的解空间复杂，不那么容易穷举完整。

备忘录、DP table 就是在追求“如何聪明地穷举”。用空间换时间的思路，是降低时间复杂度的不二法门，除此之外，试问，还能玩出啥花活？