# [【多路归并】从朴素优先队列到多路归并](https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247490029&idx=1&sn=bba9ddff88d247db310406ee418d5a15&chksm=fd9cb2f2caeb3be4b1f84962677337dcb5884374e5b6b80340834eaff79298d11151da2dd5f7&token=252055586&lang=zh_CN#rd)

> NOTE: 
>
> 原题是 [LeetCode-240-丑数-II](https://leetcode.cn/problems/ugly-number-ii/)

## [LeetCode-240-丑数-II](https://leetcode.cn/problems/ugly-number-ii/)

> NOTE: 
>
> 理解这道题的一个误区是: 以为丑数是由如下的序列组成:
>
> 1、`1*2、2*2、3*2、......`
>
> 2、`1*3、2*3、3*3、......`
>
> 3、`1*5、2*5、3*53、......`
>
> 实际上下面的数都是丑数:
>
> 1、`2 * 3`
>
> 2、`2 * 3 *5`
>
> 也就是说是可以混乘的
>
> 因此本质上丑数的生成应该是:
>
> > 对于任意一个丑数·`x` ，其与任意的质因数（2、3、5）相乘，结果（`2x`、`3x`、`5x`）仍为丑数。
>
> 简而言之: 整个**丑数序列**的生成是上一个丑数`x`会生成三个丑数`2x`、`3x`、`5x`，由此不断衍生下去，但是由于这个题目要求排序，由此需要对所有的丑数进行排序，这道题的两个算法其实就是基于此而来的：
>
> 一、优先队列（小根堆）
>
> 这个算法，一次性生成一批三个丑数`2x`、`3x`、`5x`，然后将所有生成的丑数都添加到heap中，让heap进行排序；
>
> 这种解法会将丑数都放到heap中
>
> 二、多路归并（多指针）
>
> 这个算法则更加的巧妙，它也是基于前面描述的原理，不过它更加巧妙，它也是一次生成三个丑数，但是不是生成一批三个丑数`2x`、`3x`、`5x`，而是通过指针记录上次的位置，生成的丑数可能不是同一批次的；其实这种解法是和合并多个有序序列更加类似的；
>
> 这种解法会将丑数放到一个数组中；
>
> 总的来说：其实这道题非常类似于合并多个有序数组，只不过这道题的有序数组是逻辑上的，是需要由我们自己来进行生成的，所以这道题的难度其实要更大一些。





## 优先队列（小根堆）

```java
class Solution {
    int[] nums = new int[]{2,3,5};
    public int nthUglyNumber(int n) {
        Set<Long> set = new HashSet<>();
        Queue<Long> pq = new PriorityQueue<>();
        set.add(1L);
        pq.add(1L);
        for (int i = 1; i <= n; i++) {
            long x = pq.poll();
            if (i == n) return (int)x;
            for (int num : nums) {
                long t = num * x;
                if (!set.contains(t)) {
                    set.add(t);
                    pq.add(t);
                }
            }
        }
        return -1;
    }
}
```

> NOTE: 
>
> 简而言之，每次取出最小的丑数`x`，然后将`2x`、`3x`、`5x`加入到heap中

## **多路归并（多指针）**

因此我们可以使用三个指针来指向目标序列`arr`的某个下标（下标`0`作为哨兵不使用，起始都为 `1` ，使用`arr[下标] * 质因数`代表当前使用到三个有序序列中的哪一位，同时使用`idx`表示当前生成到`arr`中的哪一位。

```java
class Solution {
    public int nthUglyNumber(int n) {
        // ans 用作存储已有丑数（从下标 1 开始存储，第一个丑数为 1）
        int[] ans = new int[n + 1];
        ans[1] = 1;
        // 由于三个有序序列都是由「已有丑数」*「质因数」而来
        // i2、i3 和 i5 分别代表三个有序序列当前使用到哪一位「已有丑数」下标（起始都指向 1）
        for (int i2 = 1, i3 = 1, i5 = 1, idx = 2; idx <= n; idx++) {
            // 由 ans[iX] * X 可得当前有序序列指向哪一位
            int a = ans[i2] * 2, b = ans[i3] * 3, c = ans[i5] * 5;
            // 将三个有序序列中的最小一位存入「已有丑数」序列，并将其下标后移
            int min = Math.min(a, Math.min(b, c));
            // 由于可能不同有序序列之间产生相同丑数，因此只要一样的丑数就跳过（不能使用 else if ）
            if (min == a) i2++; 
            if (min == b) i3++;
            if (min == c) i5++;
            ans[idx] = min;
        }
        return ans[n];
    }
}
```

