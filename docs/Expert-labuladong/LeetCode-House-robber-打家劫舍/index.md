# labuladong [团灭 LeetCode 打家劫舍问题](https://mp.weixin.qq.com/s/z44hk0MW14_mAQd7988mfw)



## House Robber I

> NOTE: 
>
> leetcode [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/) 中等



### 备忘录优化

```Java
private int[] memo;
// 主函数
public int rob(int[] nums) {
    // 初始化备忘录
    memo = new int[nums.length];
    Arrays.fill(memo, -1);
    // 强盗从第 0 间房子开始抢劫
    return dp(nums, 0);
}

// 返回 dp[start..] 能抢到的最大值
private int dp(int[] nums, int start) {
    if (start >= nums.length) {
        return 0;
    }
    // 避免重复计算
    if (memo[start] != -1) return memo[start];

    int res = Math.max(dp(nums, start + 1), 
                    nums[start] + dp(nums, start + 2));
    // 记入备忘录
    memo[start] = res;
    return res;
}
```

## House Robber II

> NOTE:
>
> leetcode [213. 打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/) 中等
>
> 





## House Robber III

> NOTE: 
>
> leetcode [337. 打家劫舍 III](https://leetcode-cn.com/problems/house-robber-iii/) 中等
>
> 
