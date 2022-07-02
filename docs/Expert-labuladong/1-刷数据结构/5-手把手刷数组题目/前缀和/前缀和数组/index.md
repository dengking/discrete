# labuladong [小而美的算法技巧：前缀和数组](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247494095&idx=2&sn=19a2609f33eadbbda1f6b75e2298d931&scene=21#wechat_redirect)

## 一维数组中的前缀和

### LeetCode [303. 区域和检索 - 数组不可变](https://leetcode.cn/problems/range-sum-query-immutable/)



### O(N)解法

> NOTE: 
>
> 这种解法是最常想到的



### O(1)解法: prefix sum

> NOTE: 
>
> 一、在 `LeetCode-303-区域和检索-简单` 中记录了我的解题过程，我的prefix sum array的定义和作者的不同，我的prefix sum array定义的是[0, i]，按照这种定义，由于要考虑"索引减法导致负数索引的问题"导致写出的代码是比较繁琐的；
>
> 相比之下，作者的定义不同，代码也更加整洁统一:
>
> `preSum[i]` 记录 `nums[0..i-1]` 的累加和，i的值需要从1开始
>
> `sumRange[left, right] = preSum[right + 1] - preSum[left]`
>
> 显然通过上述定义避免了"索引减法导致负数索引的问题"，可以看到上述定义使用的加法

这道题的最优解法是使用前缀和技巧，将`sumRange`函数的时间复杂度降为`O(1)`，说白了就是不要在`sumRange`里面用 for 循环，咋整？

直接看代码实现：

```Java
class NumArray {
    // 前缀和数组
    private int[] preSum;

    /* 输入一个数组，构造前缀和 */
    public NumArray(int[] nums) {
        // preSum[0] = 0，便于计算累加和
        preSum = new int[nums.length + 1];
        // 计算 nums 的累加和
        for (int i = 1; i < preSum.length; i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
    }

    /* 查询闭区间 [left, right] 的累加和 */
    public int sumRange(int left, int right) {
        return preSum[right + 1] - preSum[left];
    }
}
```

核心思路是我们 new 一个新的数组`preSum`出来，`preSum[i]`记录`nums[0..i-1]`的累加和，看图 10 = 3 + 5 + 2：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdGFL8VaGGr0vzRcmibenAMtMGcMLfUt26I5y8ibbgA6YiawXP2UGU3ke758gO1GqogeOV9FiarJThypBA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)