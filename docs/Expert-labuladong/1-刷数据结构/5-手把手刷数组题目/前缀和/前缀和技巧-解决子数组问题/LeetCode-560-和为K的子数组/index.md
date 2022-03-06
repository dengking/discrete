# LeetCode [560. 和为 K 的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/) 中等

## 我的解题

首先这道题是不能够使用滑动窗口的，因为不知道何时扩展何时收缩、何时扩展。

### 穷举

```C++
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
	int subarraySum(vector<int>& nums, int k) {
		int N = nums.size();
		int res = 0;
		for (int i = 0; i < N; ++i) {
			int sum = 0;
			for (int j = i; j < N; ++j) {
				sum = nums[j] + sum;
				if (sum == k) {
					++res;
				}
			}
		}
		return res;
	}
};


int main()
{
	Solution s;
	vector<int> nums{ 1,2,3,4 };
	int k = 5;
	cout << s.subarraySum(nums, k) << endl;
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

上面的这种写法在如下测试用例是会超时的:

https://leetcode-cn.com/submissions/detail/278393448/testcase/



## [官方解题 # 方法一：枚举](https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/he-wei-kde-zi-shu-zu-by-leetcode-solution/)

> NOTE: 
>
> 一、这种方法是典型的穷举，它穷举所有的子数组，它使用了一点小技巧实现了 $O(N^2)$的复杂度，这个小技巧在`最大子数组和`章节中已经讨论过了
>
> 二、这种写法是无法通过的，会在如下测试用例超时:
>
> https://leetcode-cn.com/submissions/detail/278393448/testcase/

考虑以 `i` 结尾和为 `k` 的连续子数组个数，我们需要统计符合条件的下标 `j` 的个数，



## [官方解题 # 方法二：前缀和 + 哈希表优化](https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/he-wei-kde-zi-shu-zu-by-leetcode-solution/)

我们可以基于方法一利用数据结构进行进一步的优化，我们知道方法一的瓶颈在于对每个 `i`，我们需要枚举所有的 `j` 来判断是否符合条件，这一步是否可以优化呢？答案是可以的。

> NOTE: 
>
> 看到了"我们需要枚举所有的 `j` 来判断是否符合条件，这一步是否可以优化呢？"，我的第一想法是"以空间换时间"，最最典型的是通过哈希表直接进行查找

我们定义 $\textit{pre}[i]$ 为 `[0..i]` 里所有数的和，则 $\textit{pre}[i]$ 可以由 $\textit{pre}[i-1]$ 递推而来，即：

$$
prev[i] = prev[i-1] + nums[i]
$$
那么「`[j..i]`这个子数组和为 `k` 」这个条件我们可以转化为
$$
prev[i] - prev[j-1] == k
$$
简单移项可得符合条件的下标 `j` 需要满足
$$
prev[j-1] == prev[i] - k
$$
所以我们考虑以 `i` 结尾的和为 `k` 的连续子数组个数时只要统计有多少个前缀和为 $\textit{pre}[i]-k$ 的 \textit{pre}[j]pre[j] 即可。

