# Subsequence-Subarray-Substring-DP



## Subsequence子序列DP VS Subarray子数组DP

两者的相同点: **DP方程**的定义都是以`nums[i]` 结尾的，算法过程都是 `nums[i]` 和它前面的**子序列**/**子数组**进行**连接**，所不同的是**子序列**不要求连续，但是**子数组**要求连续，因此**子序列**会遍历它前面的所有的元素，而子数组只需要考虑它紧邻的一个元素，其实这就决定了两者的复杂度: $O(N^2)$ VS $O(N)$。

关于两者对比的最最经典的例子就是:

一、**LIS** 和 **最大子数组和**

在下面的文章中进行了非常好的描述：

1、[446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) # [【负雪明烛】揭秘子序列动态规划的套路](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/fu-xue-ming-zhu-jie-mi-zi-xu-lie-dong-ta-gepk/)

2、[446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) # [动态规划（Java）](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/dong-tai-gui-hua-java-by-liweiwei1419-jc84/)

二、[LeetCode-413. 等差数列划分-中等](https://leetcode-cn.com/problems/arithmetic-slices/)、[LeetCode-446. 等差数列划分 II - 子序列-困难](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/)

### complexity: $O(N^2)$ VS $O(N)$

对于子序列问题，追求 $O(N^2)$ 的复杂度；

对于子数组问题，追求 $O(N)$ 的复杂度； 



## 最优值问题

#### LIS、最长递增子序列

LeetCode [300. 最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/) 

```c++
class Solution
{
public:
	int lengthOfLIS(vector<int> &nums)
	{
		int n = nums.size();
		vector<int> dp(n, 1);
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[j] < nums[i])
				{
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		int res = *max_element(dp.begin(), dp.end());
		return res;
	}
};
```

一、`dp[i]` 表示 以 `nums[i]` 结尾的最长递增子序列长度。

二、上述算法是典型的穷举求解最值的算法。

#### 最大子数组和

参见对应章节。



## 计数问题

#### LeetCode [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) 困难

