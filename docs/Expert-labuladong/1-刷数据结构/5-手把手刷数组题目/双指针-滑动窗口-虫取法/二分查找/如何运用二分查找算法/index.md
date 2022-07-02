# labuladong [二分搜索只能用来查找元素吗？](https://mp.weixin.qq.com/s/QC24hyg0ZgjR7-LgnEzMYg) 

抛开有序数组这个枯燥的数据结构，二分查找如何运用到实际的算法问题中呢？当搜索空间有序的时候，就可以通过二分搜索「剪枝」，大幅提升效率。

说起来玄乎得很，本文用「Koko 吃香蕉」和「货物运输」的问题来举个例子。

## 一、Koko 吃香蕉

> NOTE: 
>
> LeetCode [875. 爱吃香蕉的珂珂](https://leetcode.cn/problems/koko-eating-bananas/) 中等

那么我们先抛开二分查找技巧，**想想如何暴力解决这个问题呢？**

首先，算法要求的是「`H`小时内吃完香蕉的最小速度」，我们不妨称为`speed`，**请问`speed`最大可能为多少，最少可能为多少呢？**

显然最少为 1，最大为`max(piles)`，因为一小时最多只能吃一堆香蕉。那么暴力解法就很简单了，只要从 1 开始穷举到`max(piles)`，一旦发现发现某个值可以在`H`小时内吃完所有香蕉，这个值就是最小速度：

```C++
int minEatingSpeed(int[] piles, int H) {
    // piles 数组的最大值
    int max = getMax(piles);
    for (int speed = 1; speed < max; speed++) {
        // 以 speed 是否能在 H 小时内吃完香蕉
        if (canFinish(piles, speed, H))
            return speed;
    }
    return max;
}
```

注意这个 for 循环，就是在**连续的空间线性搜索，这就是二分查找可以发挥作用的标志。**

由于我们要求的是最小速度，所以可以用一个**搜索左侧边界的二分查找**来代替线性搜索，提升效率：

```java
int minEatingSpeed(int[] piles, int H) {
    // 套用搜索左侧边界的算法框架
    int left = 1, right = getMax(piles) + 1;
    while (left < right) {
        // 防止溢出
        int mid = left + (right - left) / 2;
        if (canFinish(piles, mid, H)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}
```



至此，借助二分查找技巧，算法的时间复杂度为 O(NlogN)。

## 二、包裹运输问题

> NOTE: 
>
> LeetCode [1011. 在 D 天内送达包裹的能力](https://leetcode.cn/problems/capacity-to-ship-packages-within-d-days/) 中等

