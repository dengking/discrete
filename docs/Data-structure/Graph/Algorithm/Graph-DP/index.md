# graph DP

一、正如 tree非常适合于练习递归和DFS，graph其实叶非常时候于练习DP，为什么呢？因为我们知道，DP的核心在于描述问题的解空间、状态转移方程，而graph问题的解空间其实基本上就对应了它自己，并且它的状态转移其实在大多数情况下都是沿着它的边进行的，因此它的状态转移方程是相对比较容易得出的。显然graph DP能够帮助我们看到这些算法本质的东西。并且graph是非常典型的具备discrete特性的，能够以one-by-one的方式来进行计算。

在下面文章中有着非常好的讲述:

1、labuladong [毕 业 旅 行](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491204&idx=1&sn=3f03f4da933ffa0baf4eb05f444d85e3&scene=21#wechat_redirect) / [旅游省钱大法：加权最短路径](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491204&idx=1&sn=3f03f4da933ffa0baf4eb05f444d85e3&scene=21#wechat_redirect)

2、labuladong [经典动态规划：最小路径和](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247489499&idx=1&sn=823fcd4097d78d8f4513f3a4d47b2a50&scene=21#wechat_redirect)

## DP解路径问题

参考文章:

一、宫水三叶 [DP路径问题](https://mp.weixin.qq.com/mp/appmsgalbum?__biz=MzU4NDE3MTEyMA==&action=getalbum&album_id=1773144264147812354&scene=173&from_msgid=2247485319&from_itemidx=1&count=3&uin=&key=&devicetype=Windows+10+x64&version=63030522&lang=zh_CN&ascene=7&fontgear=2) 



### DP解最短路径问题

参考文章:

一、labuladong [经典动态规划：最小路径和](https://mp.weixin.qq.com/s/cwunN4Uoo4ZfO13kgkHVPQ)

二、dijkstra=greedy algorithm贪心算法+dynamic programming动态规划

三、labuladong [毕 业 旅 行](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491204&idx=1&sn=3f03f4da933ffa0baf4eb05f444d85e3&scene=21#wechat_redirect) / [旅游省钱大法：加权最短路径](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247491204&idx=1&sn=3f03f4da933ffa0baf4eb05f444d85e3&scene=21#wechat_redirect)

其中主要讲 LeetCode [787. K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 中等 。

### 例题

1、LeetCode [787. K 站中转内最便宜的航班](https://leetcode.cn/problems/cheapest-flights-within-k-stops/) 中等 





## 树形DP

参考文章:

1、CSDN [树形dp+树形结构总结](https://blog.csdn.net/dcx2001/article/details/78269908)

2、CSDN [ZeroClock](https://blog.csdn.net/woshi250hua) [【DP_树形DP专辑】【9月9最新更新】](https://blog.csdn.net/woshi250hua/article/details/7644959)

3、codeforces [DP on Trees Tutorial](https://codeforces.com/blog/entry/20935)



