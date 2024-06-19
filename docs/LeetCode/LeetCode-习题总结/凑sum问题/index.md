# LeetCode 凑sum问题
- n-sum

- 背包问题

- 子数组和

## n-sum VS 背包问题

相同点：都有一个target

不同点：n-sum限制了n，但是背包问题并没有限制个数


例题：

- [LeetCode-1155. 掷骰子的N种方法](https://leetcode-cn.com/problems/number-of-dice-rolls-with-target-sum/) 



## 子数组和

根据数组中是否有负数可以将子数组问题划分为两类:

1. 没有负数

   1. 算法: sliding window

   2. 分析: 由于数组中所有的都是正数，因此窗口的sum(指标)肯定是和窗口size呈比例(proportion)的(建成**滑动窗口单调性要求**)，这样就可以使用sliding window，因为知道何时expand，何时shrink。

   3. 例题: [LeetCode-剑指 Offer 57 - II. 和为s的连续正数序列-简单](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) / [LCR 180. 文件组合-简单](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) 

   4. 素材: TODO




2. 存在负数

   1. 算法: 动态规划

   2. 分析:

      不能使用sliding window: 因为数组中的数字可以是负数，当窗口扩大的时候可能遇到负数，窗口中的值也就可能增加也可能减少，这种情况下不知道什么时机去收缩左侧窗口，也就无法求出「最大子数组和」。简而言之，它不满足滑动窗口单调性要求。

   3. 例题:

      1. [LeetCode-560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/) 

   4. 素材:

      - labuladong [动态规划套路：最大子数组和](https://mp.weixin.qq.com/s/nrULqCsRsrPKi3Y-nUfnqg) 

      - zhuanlan [经典动态规划：最大子数组问题](https://zhuanlan.zhihu.com/p/144385162)

        > 但是，稍加分析就发现，**这道题还不能用滑动窗口算法，因为数组中的数字可以是负数**。
        >
        > 滑动窗口算法无非就是双指针形成的窗口扫描整个数组/子串，但关键是，你得清楚地知道什么时候应该移动右侧指针来扩大窗口，什么时候移动左侧指针来减小窗口。
        >
        > 而对于这道题目，你想想，当窗口扩大的时候可能遇到负数，窗口中的值也就可能增加也可能减少，这种情况下不知道什么时机去收缩左侧窗口，也就无法求出「最大子数组和」。
        
   


这两个非常好地展示了使用sliding window的限制条件。



## LeetCode



### [LeetCode-剑指 Offer 57 - II. 和为s的连续正数序列-简单](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) / [LCR 180. 文件组合-简单](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) 



### [LeetCode-560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/) 



### [LeetCode-1711. 大餐计数-中等](https://leetcode-cn.com/problems/count-good-meals/)



### [LeetCode-1155. 掷骰子的N种方法](https://leetcode-cn.com/problems/number-of-dice-rolls-with-target-sum/) 