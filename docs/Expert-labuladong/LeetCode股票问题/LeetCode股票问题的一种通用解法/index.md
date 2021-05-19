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

