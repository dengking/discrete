# 海量数据处理

## 参考文章

1、weixin [海量数据处理](https://mp.weixin.qq.com/s?__biz=Mzg5OTU3MjQ4Ng==&mid=2247485150&idx=1&sn=6df5f452631bc81005f08c04c01e8904&chksm=c05070b7f727f9a106b22158148e3ce8f1ff33627bac6f92b52dffa70fd8a705abae0f4c1d25&scene=132#wechat_redirect)



2、[LeetCode-海量数据处理方法](https://leetcode.cn/circle/article/qlkHuN/)



3、CSDN [海量数据](https://blog.csdn.net/hehuanchun0311/category_9985662.html)



## 题目类型



### 海量数据求交集

> NOTE: 
>
> 这是按照 [LeetCode-海量数据处理方法](https://leetcode.cn/circle/article/qlkHuN/) 中给出的分类方法进行的分类
>
> 

从海量的 URL 中找出相同的 URL 

### 海量数据求TopK

如何从海量数据中找出高频词？

### 海量数据中不重复的数字



## weixin [海量数据处理](https://mp.weixin.qq.com/s?__biz=Mzg5OTU3MjQ4Ng==&mid=2247485150&idx=1&sn=6df5f452631bc81005f08c04c01e8904&chksm=c05070b7f727f9a106b22158148e3ce8f1ff33627bac6f92b52dffa70fd8a705abae0f4c1d25&scene=132#wechat_redirect)

### 如何从海量的 URL 中找出相同的 URL？

> NOTE: 
>
> 参见 `从大量URL中找出相同URL` 章节

### 如何从海量数据中找出高频词？

> NOTE: 
>
> 参见 `Top-K` 章节

### 如何找出某一天访问百度网站最多的 IP？

#### **问题描述**

现有海量日志数据保存在一个超大文件中，该文件无法直接读入内存，要求从中提取某天访问百度次数最多的那个 IP。

#### **解决思路**

这道题只关心某一天访问百度最多的 IP，因此，可以首先对文件进行一次遍历，把这一天访问百度 IP 的相关信息记录到一个单独的大文件中。

接下来采用的方法与上一题一样，大致就是先对 IP 进行**哈希映射**，接着使用 HashMap 统计重复 IP 的次数，最后计算出重复次数最多的 IP。

> NOTE: 
>
> 其实这一题和前面的"如何从海量数据中找出高频词？"思路是非常类似的

### 如何在大量的数据中判断一个数是否存在？

> NOTE: 
>
> 看到了这个题目，我的第一想法是:  bloom filter，但是显然它是不能够直接用bloom filter的

#### **题目描述**

给定 40 亿个不重复的没排过序的 unsigned int 型整数，然后再给定一个数，如何快速判断这个数是否在这 40 亿个整数当中？

#### **解答思路**

40 亿个不重复整数，我们用 40 亿个 bit 来表示，初始位均为 0，那么总共需要内存：4,000,000,000b≈512M。

我们读取这 40 亿个整数，将对应的 bit 设置为 1。接着读取要查询的数，查看相应位是否为 1，如果为 1 表示存在，如果为 0 表示不存在。

这种方法我们一般也叫 **位图法**。这种方法在数据处理的场景下也很常见。

> NOTE: 
>
> "位图法" bitmap

### 如何统计不同电话号码的个数？

#### **题目描述**

已知某个文件内包含一些电话号码，每个号码为 8 位数字，统计不同号码的个数。

#### **解答思路**

这道题本质还是求解**数据重复**的问题，对于这类问题，一般首先考虑**位图法**。

对于本题，8 位电话号码可以表示的号码个数为 10^8 个，即 1 亿个。

我们每个号码用一个 bit 来表示，则总共需要 1 亿个 bit，内存占用约 100M。

**思路如下**：

申请一个位图数组，长度为 1 亿，初始化为 0。然后遍历所有电话号码，把号码对应的位图中的位置置为 1。

遍历完成后，如果 bit 为 1，则表示这个电话号码在文件中存在，否则不存在。

**bit 值为 1 的数量即为 不同电话号码的个数**。

> NOTE: 
>
> 对于重复的号码，不会计数，仅仅记录状态

#### **方法总结**

求解数据重复问题，记得考虑位图法。

### 如何按照 query 的频度排序？





## [LeetCode-海量数据处理方法](https://leetcode.cn/circle/article/qlkHuN/)
