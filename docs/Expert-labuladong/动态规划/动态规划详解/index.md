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
> 2、所谓状态转移方程，它所描述的其实就是 原问题 和 子问题 之间的关系

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