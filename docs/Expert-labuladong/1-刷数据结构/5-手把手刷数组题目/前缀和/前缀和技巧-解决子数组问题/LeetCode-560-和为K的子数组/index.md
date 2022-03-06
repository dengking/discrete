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
> 这种方法是典型的穷举，它穷举所有的子数组，它使用了一点小技巧实现了 $O(N^2)$的复杂度，这个小技巧在`最大子数组和`章节中已经讨论过了

考虑以 `i` 结尾和为 `k` 的连续子数组个数，我们需要统计符合条件的下标 `j` 的个数，



## [官方解题 # 方法二：前缀和 + 哈希表优化](https://leetcode-cn.com/problems/subarray-sum-equals-k/solution/he-wei-kde-zi-shu-zu-by-leetcode-solution/)