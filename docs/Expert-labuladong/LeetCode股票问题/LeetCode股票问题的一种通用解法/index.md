# labuladong [LeetCode 股票问题的一种通用解法](https://mp.weixin.qq.com/s/TrN7mMdLEPCmT5mOXzgP5A)

## *1*、Best Time to Buy and Sell Stock (Easy)

> NOTE: 
>
> 一、leetcode [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/) 简单
>
> 

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4kbOQM3dXVKdgSXOCibeUUK2nACKnCmYcLSOsGpvKc46tF7vzVSfIUISR0gd93cMPE9phGOZiaImlWw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



### $O(n^2)$ 穷举

[动态规划详解](http://mp.weixin.qq.com/s?__biz=MzU0MDg5OTYyOQ==&mid=2247483818&idx=1&sn=6035f861d1b2bfd0178e842f26ac4836&chksm=fb3361e8cc44e8fe331154bfd32bd7b3b4f159bfad5d38d4a6b0b9f0d7e3485b93b828ee72cc&scene=21#wechat_redirect) 说过，计算机解决问题的方法就是穷举。遇到一个问题，如果想不到什么奇技淫巧，那么首先请读者自问：**如何穷举这个问题的所有可能性？**

这个问题的穷举很简单，我们可以这样写：



```
所有可能 = { 第 x 天买，第 y 天卖 }
其中 0 <= x < len(prices), 
     x < y < len(prices)

result = max(所有可能)
```



现在把上述思路转化成代码：

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4kbOQM3dXVKdgSXOCibeUUK2XCGKCWgsxmE9ohScZJWZVEA0aDtRdMPRDd3csGNMia2rUxB8iccGpyOQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#### 冗余计算

> NOTE: 
>
> 一、冗余在于每次都需要重新使用内层的`for`重新计算一次右侧的max值

但是我们分析一下这个算法在干嘛，就能发现一些冗余计算。



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4l0t1rG85oXoKAHBpTnN9wLtfPp5AvCeW0dcelkyKyR5xDqiaOZwE9mvjuRg7WicAqIrGS7JTry0Zbw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



如上图，可以看到大量的重复操作。我们相当于固定了买入时间 buy，然后将 buy 后面的每一天作为 sell 进行穷举，只为寻找 `prices[sell]` 最大的那天，因为这样 `prices[sell] - prices[buy]` 的差价才会最大。



### $O(n)$ 穷举

如果反过来想，固定卖出时间 sell，向前穷举买入时间 buy，寻找prices[buy] 最小的那天，是不是也能达到相同的效果？是的，而且这种思路可以减少一个 for 循环。



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4kbOQM3dXVKdgSXOCibeUUK2svtSFsA5Rklyfxz1GqrUNleIMRkRZ5FS1H0FKAHgicV52ibuk9XIad2g/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

#### 为什么可以减少一层for循环？

为什么可以减少一个 for 循环呢？我举个例子你就很容易理解了。

假设你有一堆数字，你知道其中最大的数，现在从中取走一个数，你还知道最大的那个数是多少吗？不一定，如果拿走的这个数不是那个最大数，那么最大数不变；如果拿走的恰好是那个最大的数，你就得重新遍历这堆数字以寻找之前第二大的那个数，作为新的最大数。这就是我们的原始算法，每向后移动一位，就要重新遍历寻找最大值。

> NOTE: 
>
> 一、$O(n^2)$ 穷举中，每次向后移动一位就相当于拿走了一个数，无法利用之前的状态，只能够每次都重新使用 内层`for`的找到右侧最大值 
>
> 二、$O(n)$ 穷举中，每次向后移动一位就相当于加入了一个数，可以使用之前的的状态，一次省略了内层的for循环

但是，假设你知道一堆数字中最小的那个，再添加一个新的数字，你现在是否知道最小的数字是那个？知道，只要比较一下新数和当前最小的数字，就能得到新的最小数。这就是优化算法的情况，所以可以消除嵌套循环的计算冗余。

关键不在于最大值还是最小值，而是数字的添加和减少。添加新数时，可以根据已有最值，推导出新的最值；而减少数字时，不一定能直接推出新的最值，不得不重新遍历。

#### 动态规划: 旧状态向新状态的转移

很多人认为这道题不是动态规划，但是我认为最值的更新就是旧状态向新状态的转移，所以这个问题还是含有动态规划的技巧的。**不要觉得此题简单，这里完成了最困难的一步：穷举。后面所有的题目都可以基于此框架扩展出来。**

## *2*、Best Time to Buy and Sell Stock II (Easy)

> NOTE: 
>
> 一、LeetCode [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/) 简单
>
> 

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4kbOQM3dXVKdgSXOCibeUUK2uibf92DLjHdyzfek9b7lfuia0mM4icmKgZB8ibJzkuxDY2e3zpzqeyUZtQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

> NOTE: 
>
> 1、这是典型的"from one to many从一1到多-divide and conquer and merge"

这道题允许多次交易，看起来比刚才的问题复杂了很多，怎么办？

来尝试一下吧，如果用 for 循环来穷举，会出现什么情况？



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4kbOQM3dXVKdgSXOCibeUUK2suTv67c9EejrmvxucyHSjYy9xrG7iaVBP7NYI9FwaQT0QJGuQmr4Wvw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



### Divide and conquer + recursion + 备忘录

**遇到这种无穷 for 循环的情况，就是使用递归的强烈暗示。**我们上一题的框架只能解决一次买卖的最大收益，现在的问题是，进行一次股票卖出后，下一次应该在什么时候交易呢？这个问题和原问题具有相同结构，规模减小，典型的递归场景。只要给原框架稍加改动即可。

> NOTE: 
>
> "tag-divide conquer-problem原问题 and subproblem子问题-结构相同 规模不同recursion"



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4kbOQM3dXVKdgSXOCibeUUK2bg4lDb7OV2nUibibCfvPA1tFEthpicMQbAXUs7FY1ia1nO8yvic7EbDibf3Q/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```python
dows, actions, and settings.
def maxProfit(prices):
    res = 0
    for buy in range(len(prices)):
        for sell in range(buy + 1, len(prices)):
            this_profit = prices[sell] - prices[buy] # 本次交易的利润
            res = max(res, maxProfit(prices[sell + 1:]) + this_profit)
    return res

```



#### 第一次优化: 备忘录 + O(n)

这道题已经做出来了，优化两步：先根据上一题消除一层循环，然后加个备忘录。优化就属于走流程，没啥可说的。**之后问题的解法，都是在此代码上的简单改造。**



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4kbOQM3dXVKdgSXOCibeUUK2vVUY5NWIXfeSGedkWic31QtqzE6bNt1nicFxtwcCUOM3TCvl0jkRfovg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

```python
def maxProfit(prices):
    memo = [-1] * len(prices)
    def dp(start):
        if start >= len(prices):
            return 0
        if memo[start] != -1:
            return memo[start]
        res = 0
        curMin = prices[start]
        for sell in range(start + 1, len(prices)):
            curMin = min(curMin, prices[sell])
            this_profit = prices[sell] - curMin  # 本次交易的利润
            res = max(res, dp(sell + 1) + this_profit)
        return res
    return dp(0)

```



怎么看出重叠子问题，前文 [动态规划之正则表达式](http://mp.weixin.qq.com/s?__biz=MzU0MDg5OTYyOQ==&mid=2247483976&idx=1&sn=c268f7343732e33035cfd75da2d17052&chksm=fb33620acc44eb1ca6d80cf5af2564e7b81fc8ee5ce53cef8f1b159a881aa06796fed3e2a363&scene=21#wechat_redirect) 有介绍，显然一个子数组切片可以通过多条递归路径得到，所以子问题一定有重叠。

> NOTE: 
>
> 1、"tag-overlapping subproblem重叠子问题-重复路径-结构化思维"
>
> 

但是，这样提交会得到一个内存超过限制的错误。原来有一个测试用例特别长，我们的 `memo` 备忘录太大了。怎么办呢，是否可以想办法减小备忘录占用的空间？答案是不可以。

#### 第二次优化: 压缩状态空间

[动态规划详解](http://mp.weixin.qq.com/s?__biz=MzU0MDg5OTYyOQ==&mid=2247483818&idx=1&sn=6035f861d1b2bfd0178e842f26ac4836&chksm=fb3361e8cc44e8fe331154bfd32bd7b3b4f159bfad5d38d4a6b0b9f0d7e3485b93b828ee72cc&scene=21#wechat_redirect) 中对斐波那契数列的优化，就用到一个技巧直接省略了备忘录和 DP table，用 O(1) 的空间完成了计算。但是这里不适用，首先我们把斐波那契的框架抽出来：



```c++
int fib(int n) {
    fib(n - 1);
    fib(n - 2);
}
```



可以看到原问题 fib(n) 只依赖子问题 fib(n - 1) 和 fib(n - 2)，所以我们的备忘录也好，DP table 也好，一次只用记录两个子问题的答案即可。但是抽象出当前算法的框架：



```python
def dp(start):
    for sell in range(start + 1, len(prices)):
        dp(sell)
```



显然，如果求解原问题 dp(0)，要依赖子问题 dp(1), dp(2) ... dp(len(prices) - 1)，反正数量不是个定值，所以备忘录必须开那么大，否则装不下这些依赖子问题呀！说明这就是动态规划的极限了，真的不能再优化了。



### 贪心算法

这个问题的最优解法是「贪心算法」。贪心算法是基于动态规划之上的一种特殊方法，对于某些特定问题可以比动态规划更高效。这道题用贪心很简单，就贴一下代码吧，读者应该可以很容易理解。



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4kbOQM3dXVKdgSXOCibeUUK2icn8z9vgp5LyoILuwSFH64dcCqhTLmxkKTmCue1qwUhZJsTIGzTpyzg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)



核心思想就是：既然可以预知未来，那么能赚一点就赚一点。



![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4kbOQM3dXVKdgSXOCibeUUK2q3ehSLqRFL7oWFf0Blkv9TibfHNUIPpxUOfpJ3iapiaCPsHyG0NNrpVpQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

图片来自 www.leetcode.com