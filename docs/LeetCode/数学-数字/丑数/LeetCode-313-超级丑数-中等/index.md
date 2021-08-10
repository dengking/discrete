# LeetCode [313. 超级丑数](https://leetcode-cn.com/problems/super-ugly-number/) 中等



## [官方解题](https://leetcode-cn.com/problems/super-ugly-number/solution/chao-ji-chou-shu-by-leetcode-solution-uzff/)

### 方法一：最小堆

要得到从小到大的第 $n$ 个超级丑数，可以使用**最小堆**实现。

> NOTE: 
>
> 一、典型的top K算法
>
> 

初始时堆为空。首先将**最小的超级丑数** $1$​ 加入堆。

每次取出堆顶元素 $x$，则 $x$是堆中**最小的超级丑数**。对于数组 $\textit{primes}$ 的任意质数 $p$，$px$ 也是**超级丑数**，因此将数组 $\textit{primes}$ 中的每个质数和 $x$ 的乘积分别加入堆。

> NOTE:
>
> 上述描述的是生成新的超级丑数的过程

上述做法会导致堆中出现重复元素的情况。为了避免重复元素，可以使用**哈希集合去重**，避免相同元素多次加入堆。

在排除重复元素的情况下，第 $n$ 次从最小堆中取出的元素即为第 $n$ 个超级丑数。



### 方法二：动态规划

