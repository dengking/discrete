# labuladong [团灭 LeetCode 打家劫舍问题](https://mp.weixin.qq.com/s/z44hk0MW14_mAQd7988mfw)



## House Robber I

> NOTE: 
>
> leetcode [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/) 中等

题目很容易理解，而且动态规划的特征很明显。我们前文 [动态规划详解](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484731&idx=1&sn=f1db6dee2c8e70c42240aead9fd224e6&chksm=9bd7fb33aca07225bee0b23a911c30295e0b90f393af75eca377caa4598ffb203549e1768336&scene=21#wechat_redirect) 做过总结，**解决动态规划问题就是找「状态」和「选择」，仅此而已**。

假想你就是这个专业强盗，从左到右走过这一排房子，在每间房子前都有两种**选择**：抢或者不抢。

如果你抢了这间房子，那么你肯定不能抢相邻的下一间房子了，只能从**下下间**房子开始做选择。

如果你不抢这间房子，那么你可以走到**下一间**房子前，继续做选择。

当你走过了最后一间房子后，你就没得抢了，能抢到的钱显然是 0（**base case**）。

以上的逻辑很简单吧，其实已经明确了「状态」和「选择」：**你面前房子的索引就是状态，抢和不抢就是选择**。

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdG9kDIzE6qfsOcugRP3xn8nv9r9HSvIbBiaqK3sgINedoq9Ib9Pyqn8Kj5GIQTFKDol6u90bRnSdLA/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

在两个选择中，每次都选更大的结果，最后得到的就是最多能抢到的 money：

```Java
// 主函数
public int rob(int[] nums) {
    return dp(nums, 0);
}
// 返回 nums[start..] 能抢到的最大值
private int dp(int[] nums, int start) {
    if (start >= nums.length) {
        return 0;
    }

    int res = Math.max(
            // 不抢，去下家
            dp(nums, start + 1), 
            // 抢，去下下家
            nums[start] + dp(nums, start + 2)
        );
    return res;
}
```

明确了状态转移，就可以发现对于同一`start`位置，是存在重叠子问题的，比如下图：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdG9kDIzE6qfsOcugRP3xn8nZMwN4TBQyzPxoKCib6ibTg93lT25VFKK7TojarRxfib0uJPyWaTpohPHg/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

盗贼有多种选择可以走到这个位置，如果每次到这都进入递归，岂不是浪费时间？所以说存在重叠子问题，可以用备忘录进行优化：

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

### 动态规划

这就是自顶向下的动态规划解法，我们也可以略作修改，写出**自底向上**的解法：

```c++
 int rob(int[] nums) {
    int n = nums.length;
    // dp[i] = x 表示：
    // 从第 i 间房子开始抢劫，最多能抢到的钱为 x
    // base case: dp[n] = 0
    int[] dp = new int[n + 2];
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = Math.max(dp[i + 1], nums[i] + dp[i + 2]);
    }
    return dp[0];
}
```

> NOTE: 
>
> "recurrence relation递归状态转移方程-DP-依赖前两项-DP table多分配2个-防止越界"，另外一种做法是:
>
> "recurrence relation递归状态转移方程-DP-依赖前两项-从2开始遍历-防止越界"

我们又发现状态转移只和`dp[i]`最近的两个状态有关，所以可以进一步优化，将空间复杂度降低到 O(1)。

```c++
int rob(int[] nums) {
    int n = nums.length;
    // 记录 dp[i+1] 和 dp[i+2]
    int dp_i_1 = 0, dp_i_2 = 0;
    // 记录 dp[i]
    int dp_i = 0; 
    for (int i = n - 1; i >= 0; i--) {
        dp_i = Math.max(dp_i_1, nums[i] + dp_i_2);
        dp_i_2 = dp_i_1;
        dp_i_1 = dp_i;
    }
    return dp_i;
}
```

以上的流程，在我们 [动态规划详解](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484731&idx=1&sn=f1db6dee2c8e70c42240aead9fd224e6&chksm=9bd7fb33aca07225bee0b23a911c30295e0b90f393af75eca377caa4598ffb203549e1768336&scene=21#wechat_redirect) 中详细解释过，相信大家都能手到擒来了。我认为很有意思的是这个问题的 follow up，需要基于我们现在的思路做一些巧妙的应变。

> NOTE: 
>
> 我的写法:
>
> ```C++
> class Solution
> {
> public:
> 	int rob(vector<int> &nums)
> 	{
> //		int len = nums.size();
> //		vector<int> dp(len + 1, 0);
> //		dp[0] = 0;
> //		dp[1] = nums[0];
> //		for (int i = 2; i <= len; ++i)
> //		{
> //			dp[i] = max(nums[i - 1] + dp[i - 2], dp[i - 1]);
> //		}
> //		return dp[len];
> 		// 状态压缩的写法
> 		int len = nums.size();
> 		int dp_i_0 = 0;
> 		int dp_i_1 = 0;
> 		int dp_i_2 = 0;
> 		for (int i = 1; i <= len; ++i)
> 		{
> 			dp_i_2 = max(nums[i - 1] + dp_i_0, dp_i_1);
> 			dp_i_0 = dp_i_1;
> 			dp_i_1 = dp_i_2;
> 		}
> 		return dp_i_2;
> 	}
> };
> ```
>
> 

## House Robber II

> NOTE:
>
> leetcode [213. 打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/) 中等
>
> 



![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdG9kDIzE6qfsOcugRP3xn8nlATHI4e9ib8SUiar0s2OR8zQdvficwknUKDwfcKWV0sc3WwL1lC0Cw5GQ/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

## House Robber III

> NOTE: 
>
> leetcode [337. 打家劫舍 III](https://leetcode-cn.com/problems/house-robber-iii/) 中等
>
> 

第三题又想法设法地变花样了，此强盗发现现在面对的房子不是一排，不是一圈，而是一棵二叉树！房子在二叉树的节点上，相连的两个房子不能同时被抢劫：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_png/gibkIz0MVqdG9kDIzE6qfsOcugRP3xn8nwOicnMmWbOImE7wn5g3PYnn5RrMWtiaSicSjIxuoLqRIliaMsdZwd4gAPg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

整体的思路完全没变，还是做抢或者不抢的选择，取收益较大的选择。甚至我们可以直接按这个套路写出代码：

```c++
Map<TreeNode, Integer> memo = new HashMap<>();
public int rob(TreeNode root) {
    if (root == null) return 0;
    // 利用备忘录消除重叠子问题
    if (memo.containsKey(root)) 
        return memo.get(root);
    // 抢，然后去下下家
    int do_it = root.val
        + (root.left == null ? 
            0 : rob(root.left.left) + rob(root.left.right))
        + (root.right == null ? 
            0 : rob(root.right.left) + rob(root.right.right));
    // 不抢，然后去下家
    int not_do = rob(root.left) + rob(root.right);

    int res = Math.max(do_it, not_do);
    memo.put(root, res);
    return res;
}
```

这道题就解决了，时间复杂度 O(N)，`N`为数的节点数。

但是这道题让我觉得巧妙的点在于，还有更漂亮的解法。比如下面是我在评论区看到的一个解法：

```Java
int rob(TreeNode root) {
    int[] res = dp(root);
    return Math.max(res[0], res[1]);
}

/* 返回一个大小为 2 的数组 arr
arr[0] 表示不抢 root 的话，得到的最大钱数
arr[1] 表示抢 root 的话，得到的最大钱数 */
int[] dp(TreeNode root) {
    if (root == null)
        return new int[]{0, 0};
    int[] left = dp(root.left);
    int[] right = dp(root.right);
    // 抢，下家就不能抢了
    int rob = root.val + left[0] + right[0];
    // 不抢，下家可抢可不抢，取决于收益大小
    int not_rob = Math.max(left[0], left[1])
                + Math.max(right[0], right[1]);

    return new int[]{not_rob, rob};
}
```

时间复杂度 O(N)，空间复杂度只有递归函数堆栈所需的空间，不需要备忘录的额外空间。

你看他和我们的思路不一样，修改了递归函数的定义，略微修改了思路，使得逻辑自洽，依然得到了正确的答案，而且代码更漂亮。这就是我们前文 [动态规划：不同的定义产生不同的解法](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484469&idx=1&sn=e8d321c8ad62483874a997e9dd72da8f&chksm=9bd7fa3daca0732b316aa0afa58e70357e1cb7ab1fe0855d06bc4a852abb1b434c01c7dd19d6&scene=21#wechat_redirect) 所说过的动态规划问题的一个特性。

实际上，这个解法比我们的解法运行时间要快得多，虽然算法分析层面时间复杂度是相同的。原因在于此解法没有使用额外的备忘录，减少了数据操作的复杂性，所以实际运行效率会快。
