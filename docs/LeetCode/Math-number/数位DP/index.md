# DP解数位问题

一、是在做 [LeetCode-233. 数字 1 的个数](https://leetcode.cn/problems/number-of-digit-one/) 困难 时，[【宫水三叶】将数位 DP 问题转化为计数类模拟题](https://leetcode.cn/problems/number-of-digit-one/solution/gong-shui-san-xie-jiang-shu-wei-dp-wen-t-c9oi/) 中，给出的解答:

> 这是一道经典的「数位 DP」模板题的简化版，原题在 [这里](https://www.luogu.com.cn/problem/P1980) 。

二、数位DP其实本质上是基于binary representation的number，将其转换为tree DP、系列DP。



## 素材

一、[paper-浅谈数位类统计问题](https://www.gydoc.com/p-5722.html)

这篇paper非常好

二、[宫水三叶 # 数位 DP](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzU4NDE3MTEyMA==&action=getalbum&album_id=2109028019305611264&scene=173&from_msgid=2247489051&from_itemidx=1&count=3&nolastread=1#wechat_redirect)

1、[【综合笔试题】难度 4/5，数位 DP 运用题](https://mp.weixin.qq.com/s/IKUJ7-ONV7laK0gOq02VTA)

LeetCode **「600. 不含连续1的非负整数」**

2、[【动态规划の数位 DP】一文详解通用「数位 DP」求解思路](https://mp.weixin.qq.com/s/8Z7W4xVnKLL3fLpjN6zXXQ)

LeetCode **「902. 最大为 N 的数字组合」**

3、[LeetCode-【宫水三叶】将数位 DP 问题转化为计数类模拟题](https://leetcode.cn/problems/number-of-digit-one/solution/gong-shui-san-xie-jiang-shu-wei-dp-wen-t-c9oi/) 

[LeetCode-233. 数字 1 的个数](https://leetcode.cn/problems/number-of-digit-one/)

三、论文 [浅谈数位类统计问题](https://www.gydoc.com/p-5722.html) 

四、CSDN Accagain [【DP专辑】ACM动态规划总结](https://blog.csdn.net/cc_again/article/details/25866971?spm=1001.2014.3001.5502)



### TODO

CSDN [数字游戏 （dp）](https://blog.csdn.net/xiaofang3a/article/details/39897737)

cnblogs [计数DP之数字](https://www.cnblogs.com/soda-ma/p/13325119.html)



## use tree to represent number

例子：

1、lexilogical number

complete n-ary tree

2、