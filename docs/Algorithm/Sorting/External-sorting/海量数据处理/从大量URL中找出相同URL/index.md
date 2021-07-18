# 如何从大量的 URL 中找出相同的 URL？



## 参考文章

1、LeetCode [海量数据处理方法](https://leetcode-cn.com/circle/article/qlkHuN/) 

2、csdn [【海量数据处理】如何从大量的 URL 中找出相同的 URL？](https://blog.csdn.net/hehuanchun0311/article/details/106000809)

3、weixin [海量数据处理](https://mp.weixin.qq.com/s?__biz=Mzg5OTU3MjQ4Ng==&mid=2247485150&idx=1&sn=6df5f452631bc81005f08c04c01e8904&chksm=c05070b7f727f9a106b22158148e3ce8f1ff33627bac6f92b52dffa70fd8a705abae0f4c1d25&scene=132#wechat_redirect)



## csdn [【海量数据处理】如何从大量的 URL 中找出相同的 URL？](https://blog.csdn.net/hehuanchun0311/article/details/106000809)

### 题目描述

给定 a、b 两个文件，各存放 50 亿个 URL，每个 URL 各占 64B，内存限制是 4G。请找出 a、b 两个文件共同的 URL。

> NOTE: 
>
> 按照 LeetCode [海量数据处理方法](https://leetcode-cn.com/circle/article/qlkHuN/) 中给出的分类方法，这属于求交集。
>
> 

### 解答思路

每个 URL 占 64B，那么 50 亿个 URL占用的空间大小约为 320GB。
$$
5,000,000,000 * 64B ≈ 5GB * 64 = 320GB
$$
由于内存大小只有 4G，因此，我们不可能一次性把所有 URL 加载到内存中处理。对于这种类型的题目，一般采用分治策略，即：把一个文件中的 URL 按照某个特征划分为多个小文件，使得每个小文件大小不超过 4G，这样就可以把这个小文件读到内存中进行处理了。

#### 思路如下

首先遍历文件 a，对遍历到的 URL 求 `hash(URL) % 1000`，根据计算结果把遍历到的 URL 存储到 a0, a1, a2, …, a999，这样每个大小约为 300MB。使用同样的方法遍历文件 b，把文件 b 中的 URL 分别存储到文件 b0, b1, b2, …, b999 中。这样处理过后，所有可能相同的 URL 都在对应的小文件中，即 a0 对应 b0, …, a999 对应 b999，不对应的小文件不可能有相同的 URL。那么接下来，我们只需要求出这 1000 对小文件中相同的 URL 就好了。

> NOTE: 
>
> hash值相同的，原值也相同；
>
> 是否存在: hash值不相同，但是原值相同？不存在。

接着遍历 $a_i( i \in [0,999])$，把 URL 存储到一个 HashSet 集合中。然后遍历 $b_i$ 中每个 URL，看在 HashSet 集合中是否存在，若存在，说明这就是共同的 URL，可以把这个 URL 保存到一个单独的文件中。

### 方法总结

1、分而治之，进行哈希取余；

2、对每个子文件进行 HashSet 统计。

