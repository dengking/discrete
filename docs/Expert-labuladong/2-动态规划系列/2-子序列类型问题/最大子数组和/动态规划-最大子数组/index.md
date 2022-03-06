# labuladong [动态规划套路：最大子数组和](https://mp.weixin.qq.com/s/nrULqCsRsrPKi3Y-nUfnqg) 

> NOTE: 
>
> 一、原题: leetcode [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/) 简单
>
> 二、LeetCode [53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/) 其实和 LeetCode [485. 最大连续 1 的个数](https://leetcode-cn.com/problems/max-consecutive-ones/) 非常类似



## 思路分析

> NOTE: 
>
> 一、这道题的要求是**连续**的，因此DP状态转移方程是需要保证这一点的

### 第一种定义方式

解决这个问题需要动态规划技巧，但是`dp`数组的定义比较特殊。按照我们常规的动态规划思路，一般是这样定义`dp`数组：

`nums[0..i]`中的「最大的子数组和」为`dp[i]`。

> NOTE: 
>
> 非单调的，因此无法使用上述definition

如果这样定义的话，整个`nums`数组的「最大子数组和」就是`dp[n-1]`。如何找状态转移方程呢？按照数学归纳法，假设我们知道了`dp[i-1]`，如何推导出`dp[i]`呢？

如下图，按照我们刚才对`dp`数组的定义，`dp[i] = 5`，也就是等于`nums[0..i]`中的最大子数组和：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_jpg/gibkIz0MVqdHwOlodS2IXvReL2Yn3lvDicxVlE2ZnyuP7SBDmcibI9rryhM8OvnJTDPURzrdp0KWmOhRH1OG19BSg/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

那么在上图这种情况中，利用数学归纳法，你能用`dp[i]`推出`dp[i+1]`吗？

**实际上是不行的，因为子数组一定是连续的，按照我们当前`dp`数组定义，并不能保证`nums[0..i]`中的最大子数组与`nums[i+1]`是相邻的**，也就没办法从`dp[i]`推导出`dp[i+1]`。

> NOTE: 
>
> 一、上面这段话是点明了不能够使用上述dp定义的原因，本质上是因为需要连续

所以说我们这样定义`dp`数组是不正确的，无法得到合适的状态转移方程。对于这类子数组问题，我们就要重新定义`dp`数组的含义：

### 第二种定义方式

**以`nums[i]`为结尾的「最大子数组和」为`dp[i]`**。

> NOTE:
>
> 一、显然上述定义方式 "**以`nums[i]`为结尾的**" 中的 "**结尾**" 是能够保证连续的

这种定义之下，想得到整个`nums`数组的「最大子数组和」，不能直接返回`dp[n-1]`，而需要遍历整个`dp`数组：

```Java
int res = Integer.MIN_VALUE;
for (int i = 0; i < n; i++) {
    res = Math.max(res, dp[i]);
}
return res;
```

依然使用数学归纳法来找状态转移关系：假设我们已经算出了`dp[i-1]`，如何推导出`dp[i]`呢？

可以做到，`dp[i]`有两种「选择」，要么与前面的相邻**子数组**连接，形成一个和更大的**子数组**；要么不与前面的**子数组**连接，自成一派，自己作为一个**子数组**。

如何选择？既然要求「最大**子数组**和」，当然选择结果更大的那个啦：

```c++
// 要么自成一派，要么和前面的子数组合并
dp[i] = Math.max(nums[i], nums[i] + dp[i - 1]);
```

综上，我们已经写出了状态转移方程，就可以直接写出解法了：

```c++
int maxSubArray(int[] nums) {
    int n = nums.length;
    if (n == 0) return 0;
    int[] dp = new int[n];
    // base case
    // 第一个元素前面没有子数组
    dp[0] = nums[0];
    // 状态转移方程
    for (int i = 1; i < n; i++) {
        dp[i] = Math.max(nums[i], nums[i] + dp[i - 1]);
    }
    // 得到 nums 的最大子数组
    int res = Integer.MIN_VALUE;
    for (int i = 0; i < n; i++) {
        res = Math.max(res, dp[i]);
    }
    return res;
}
```

> NOTE: 
>
> 一、
>
> ```c++
> #include <string>
> #include <vector>
> #include <stack>
> #include <unordered_map>
> #include <algorithm>
> #include <random>
> #include <iostream>
> #include <stdexcept>
> #include <cstdlib>
> #include <ctime>
> using namespace std;
> 
> class Solution {
> public:
> 	int maxSubArray(vector<int>& nums) {
> 		int N = nums.size();
> 		vector<int> dp(nums.size());
> 		dp[0] = nums[0];
> 		int res = dp[0];
> 		for (int i = 1; i < N; ++i) {
> 			dp[i] = max(nums[i], dp[i - 1] + nums[i]);
> 			res = max(res, dp[i]);
> 		}
> 		return res;
> 	}
> };
> 
> 
> int main()
> {
> 	Solution s;
> }
> 
> // g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror
> 
> ```
>
> 

以上解法时间复杂度是 O(N)，空间复杂度也是 O(N)，较暴力解法已经很优秀了，不过**注意到`dp[i]`仅仅和`dp[i-1]`的状态有关**，那么我们可以进行「状态压缩」，将空间复杂度降低：

```Java
int maxSubArray(int[] nums) {
    int n = nums.length;
    if (n == 0) return 0;
    // base case
    int dp_0 = nums[0];
    int dp_1 = 0, res = dp_0;

    for (int i = 1; i < n; i++) {
        // dp[i] = max(nums[i], nums[i] + dp[i-1])
        dp_1 = Math.max(nums[i], nums[i] + dp_0);
        dp_0 = dp_1;
        // 顺便计算最大的结果
        res = Math.max(res, dp_1);
    }

    return res;
}
```

> NOTE: 
>
> 一、
>
> ```C++
> #include <string>
> #include <vector>
> #include <stack>
> #include <unordered_map>
> #include <algorithm>
> #include <random>
> #include <iostream>
> #include <stdexcept>
> #include <cstdlib>
> #include <ctime>
> using namespace std;
> 
> class Solution {
> public:
> 	int maxSubArray(vector<int>& nums) {
> 		int N = nums.size();
> 		int prev = nums[0];
> 		int res = prev;
> 		for (int i = 1; i < N; ++i) {
> 			int cur = max(nums[i], prev + nums[i]);
> 			res = max(res, cur);
> 			prev = cur;
> 		}
> 		return res;
> 	}
> };
> 
> 
> int main()
> {
> 	Solution s;
> }
> 
> // g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror
> 
> ```
>
> 

## 最后总结

虽然说动态规划推状态转移方程确实比较玄学，但大部分还是有些规律可循的。

今天这道「最大子数组和」就和「最长递增子序列」非常类似，`dp`数组的定义是「以`nums[i]`为结尾的最大子数组和/最长递增子序列为`dp[i]`」。因为只有这样定义才能将`dp[i+1]`和`dp[i]`建立起联系，利用数学归纳法写出状态转移方程。