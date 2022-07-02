# LeetCode [581. 最短无序连续子数组](https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/) 中等



## [官方解题](https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/solution/zui-duan-wu-xu-lian-xu-zi-shu-zu-by-leet-yhlf/)

### 方法一：排序

> NOTE: 
>
> 这种思路是非常容易理解的，相对比较简单

我们将给定的数组 $\textit{nums}$​ 表示为三段**子数组**拼接的形式，分别记作 $\textit{nums}_A$​，$\textit{nums}_B$​，$\textit{nums}_C$​。

本题要求我们找到最短的 $\textit{nums}_B$ ，即找到最大的 $\textit{nums}_A$，$\textit{nums}_C$ 的长度之和。因此我们将原数组 $\textit{nums}$ 排序与原数组进行比较，取最长的相同的前缀为 $\textit{nums}_A$，取最长的相同的后缀为 $\textit{nums}_C$ ，这样我们就可以取到最短的 $\textit{nums}_B$。

```C++
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (is_sorted(nums.begin(), nums.end())) {
            return 0;
        }
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());
        int left = 0;
        while (nums[left] == numsSorted[left]) {
            left++;
        }
        int right = nums.size() - 1;
        while (nums[right] == numsSorted[right]) {
            right--;
        }
        return right - left + 1;
    }
};

```



### 方法二：一次遍历

> NOTE: 
>
> 一、思路是什么呢？
>
> 首先思考有序的情况，显然有序的情况下，从左至右逐个递增，从右至左逐个递减；
>
> 部分有序则无法满足这个递增的特性，肯定会存在:
>
> 1、从左至右，先递增后递减的情况
>
> 2、从右至左，先递减后递增的情况
>
> 上面这两种情况正好是我们需要找到的；
>
> 因此，我们可以将原序列分为三段: 
>
> 二、为什么这种算法能够保证最短？
>
> 因为它仅仅记录的是不满足顺序的位置，对于其他位置，它并没有记录；

假设 $\textit{nums}_B$ 在 $\textit{nums}$ 中对应区间为 $[\textit{left},\textit{right}]。$

注意到 $\textit{nums}_B$  和 $\textit{nums}_C$ 中任意一个数都大于等于 $\textit{nums}_A$ 中任意一个数。因此有 $\textit{nums}_A$  中任每一个数 $\textit{nums}_i$  都满足：
$$
\textit{nums}_i \leq \min_{j=i+1}^{n-1} \textit{nums}_j
$$

我们可以从大到小枚举 $i$​，用一个变量 $\textit{minn}$​ 记录 $\min_{j=i+1}^{n-1} \textit{nums}_j$​ 。每次移动 $i$​，都可以 $O(1)$​ 地更新 $\textit{minn}$​。这样最后一个使得不等式不成立的 $i$​ 即为 $\textit{left}$​。$\textit{left}$​ 左侧即为 $\textit{nums}_A$​ 能取得的最大范围。

> NOTE: 
>
> 上面描述的其实就是从右至左进行遍历，它能够找到非递减的位置，可以用它来确定left；

同理，我们可以用类似的方法确定 $right$​。在实际代码中，我们可以在一次循环中同时完成左右边界的计算。

> NOTE: 
>
> 上面描述的其实就是从左至右进行遍历，它能够找到非递增的位置，可以用它来确定right；

> NOTE: 
>
> 一、下面是测试用例: 
>
> ```C++
> [2,6,4,8,10,9,15]
> ```
>
> 需要结合测试用例来理解下面的程序: 

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
			if (maxn > nums[i]) // 显然是不满足递增的特性的，结合上述用例来说，在 4、9 的时候，会进入到这个分支
			{
				right = i;
			}
			else // 递增
			{
				maxn = nums[i];
			}
			if (minn < nums[n - i - 1]) // 显然是不满足递减的特性的，结合上述测试用例来说，在 "6" 的时候，会进入到这个分支
			{
				left = n - i - 1;
			}
			else // 递减
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

> NOTE: 
>
> 一、上述code是非常巧妙的，在一次循环中，同时正向(自左向右)、逆向(自右向左)来遍历数组
>
> 
