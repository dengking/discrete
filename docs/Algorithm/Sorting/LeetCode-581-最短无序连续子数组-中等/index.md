# LeetCode [581. 最短无序连续子数组](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/) 中等



## [官方解题](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leet-yhlf/)



#### 方法二：一次遍历

假设 $\textit{nums}_B$ 在 $\textit{nums}$ 中对应区间为 $[\textit{left},\textit{right}]。$

注意到 $\textit{nums}_B$  和 $\textit{nums}_C$ 中任意一个数都大于等于 $\textit{nums}_A$ 中任意一个数。因此有 $\textit{nums}_A$  中任每一个数 $\textit{nums}_i$  都满足：
$$
\textit{nums}_i \leq \min_{j=i+1}^{n-1} \textit{nums}_j
$$

我们可以从大到小枚举 $i$，用一个变量 $\textit{minn}$ 记录 $\min_{j=i+1}^{n-1} \textit{nums}_j$ 。每次移动 $i$，都可以 $O(1)$ 地更新 $\textit{minn}$。这样最后一个使得不等式不成立的 $i$ 即为 $\textit{left}$。$\textit{left}$ 左侧即为 $\textit{nums}_A$ 能取得的最大范围。



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int findUnsortedSubarray(vector<int> &nums)
	{
		int n = nums.size();
		int maxn = INT_MIN, right = -1;
		int minn = INT_MAX, left = -1;
		for (int i = 0; i < n; i++)
		{
			if (maxn > nums[i])
			{
				right = i;
			}
			else
			{
				maxn = nums[i];
			}
			if (minn < nums[n - i - 1])
			{
				left = n - i - 1;
			}
			else
			{
				minn = nums[n - i - 1];
			}
		}
		return right == -1 ? 0 : right - left + 1;
	}
};

int main()
{
	Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

