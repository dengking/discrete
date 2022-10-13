# 区间DP

由矩阵连乘问题想到了区间DP，矩阵连乘问题可以看做是区间DP。



## cnblogs [浅谈区间DP](https://www.cnblogs.com/fusiwei/p/13809069.html)

### 一、区间DP的概念

> NOTE: 
>
> 区间DP、线段树、树形DP
>
> 

比如线段树。

在本蒟蒻的大力理解下，我把它类比成区间DP+树形DP。

你看，它的每个节点维护的一个区间信息，然后按二叉树的形态，每个节点的信息由子节点推出，一层层向上递归，最终到达根节点。

但是它和**区间DP**尚有不同。

**区间DP**又类似于**弗洛伊德Floyd算法**。

也就是枚举断点，更新区间。

区间DP的状态一般是：

$dp[i][j]$ 表示从 $i$ 到 $j$ 这个区间的某个信息。

然后转移方程一般都是：

$$
dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+calc())
$$
其中，$k$是断点，`calc()`是计算更新信息的方式。

也就是说，**区间DP**的阶段划分是**区间长度**，每个区间是由比它更短的区间更新而来的。

### 二、区间DP的模板和复杂度分析

刚刚已经讲过了，区间DP的阶段划分是区间长度，我们需要保证长度较短的区间全部处理完之后，再处理长度比较长的区间。所以最外层循环就需要枚举区间长度。

然后就是枚举区间左右端点了。但是因为外面的区间长度，所以右端点只需要通过左端点算出来就行，不用枚举。

所以大体代码就是这样的：

```cpp
for(int len=2;len<=n;len++)
        for(int i=1;i<=2*n-len+1;i++)
        {
            int j=i+len-1;
            for(int k=i;k<j;k++)
                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]+calc());
        }
```

当然，也有枚举时比这份代码多了+1-1之类的版本。实际意义是一样的。大家挑自己喜欢的即可。

通过以上代码，我们清楚：区间DP的时间复杂度是$O(n^3)$的。



## oi-wiki [区间 DP](https://oi-wiki.org/dp/interval/)



## CSDN [区间dp入门](https://blog.csdn.net/qq_40772692/article/details/80183248)



## jianshu [算法学习之区间dp](https://www.jianshu.com/p/9c6401ea2f9b)



## 素材

https://blog.csdn.net/MaYingColdPlay/article/details/125132189

https://blog.csdn.net/sgh666666/article/details/105178376

https://blog.csdn.net/qq_40772692/article/details/80183248

[LeetCode-128. 最长连续序列](https://leetcode.cn/problems/longest-consecutive-sequence/) # [【动态规划】Python 题解](https://leetcode.cn/problems/longest-consecutive-sequence/solution/dong-tai-gui-hua-python-ti-jie-by-jalan/)

