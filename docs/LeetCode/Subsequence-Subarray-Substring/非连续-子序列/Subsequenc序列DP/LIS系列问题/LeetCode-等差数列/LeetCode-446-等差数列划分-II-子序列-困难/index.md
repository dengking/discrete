# LeetCode [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) 困难

这道题的解法是比较难以理解的，在阅读各种解法中，我觉得 [【负雪明烛】揭秘子序列动态规划的套路](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/fu-xue-ming-zhu-jie-mi-zi-xu-lie-dong-ta-gepk/) 是相对比较容易理解的，它从 LIS 的角度进行类比；因此如果有 LIS 基础的话，推荐优先阅读 [【负雪明烛】揭秘子序列动态规划的套路](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/fu-xue-ming-zhu-jie-mi-zi-xu-lie-dong-ta-gepk/) ，然后阅读 [官方解题](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/deng-chai-shu-lie-hua-fen-ii-zi-xu-lie-b-77pl/)  。 



## 我的解题

### 回溯法

使用回溯法进行穷举:

```c++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int numberOfArithmeticSlices(vector<int> &nums)
	{
		int count = 0;
		vector<int> track;
		track.reserve(nums.size());
		backtrace(nums, count, 0, track);
		return count;
	}
	void backtrace(vector<int> &nums, int &count, int index, vector<int> &track)
	{
		if (index == nums.size())
		{
			if (track.size() >= 3)
			{
				++count;
			}

			return;
		}
		if (track.size() >= 2)
		{
			// 选择第index个数
			if (long(nums[index]) - track.back() == long(track[1]) - track[0])
			{
				track.push_back(nums[index]);
				backtrace(nums, count, index + 1, track);
				track.pop_back();
			}
			// 不选择第index个数
			backtrace(nums, count, index + 1, track);
		}
		else
		{
			// 选择第index个数
			track.push_back(nums[index]);
			backtrace(nums, count, index + 1, track);
			track.pop_back();
			// 不选择第index个数
			backtrace(nums, count, index + 1, track);
		}
	}
};

int main()
{
	Solution s;
	vector<int> nums { 2, 4, 6, 8, 10 };
	s.numberOfArithmeticSlices(nums);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

#### 运行结果

|                                                              | 用例                                                    |
| ------------------------------------------------------------ | ------------------------------------------------------- |
| [超出时间限制](https://leetcode-cn.com/submissions/detail/205600008/) | `[1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]` |
|                                                              |                                                         |
|                                                              |                                                         |

其实，现在看来，上述算法的复杂度是非常高的，因此，对于子序列问题，使用穷举的方法是不可行的；

### 二进制枚举

这是无法实现的，因为从题目意思可知:

```C++
1  <= nums.length <= 1000
```

没有长度为1000位的整数类型；



## DP解法

在下面的文章中进行了非常好的阐述：

1、[官方解题](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/deng-chai-shu-lie-hua-fen-ii-zi-xu-lie-b-77pl/) 的讲解是把这个算法的细节讲的最好的，其中使用了 **弱等差子序列** 的概念，这个概念是理解这个问题的核心所在。

2、[liweiwei1419](https://leetcode-cn.com/u/liweiwei1419/) # [动态规划（Java）](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/dong-tai-gui-hua-java-by-liweiwei1419-jc84/)

这篇文章中，结合了具体的例子来进行说明，可以作为1的补充

3、[[负雪明烛]揭秘子序列动态规划的套路](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/fu-xue-ming-zhu-jie-mi-zi-xu-lie-dong-ta-gepk/) 

这篇文章是讲解整体思路最好的。



阅读顺序: 

首先阅读3掌握大思路，但是这篇文章对细节的描述不够，需要阅读 1 来掌握细节，2中有具体的例子，能够帮助理解细节。



需要结合具体的例子来理解算法的运行过程。



## [官方解题](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/deng-chai-shu-lie-hua-fen-ii-zi-xu-lie-b-77pl/) 

我们首先考虑至少有两个元素的**等差子序列**，下文将其称作**弱等差子序列**。

> NOTE: 
>
> 一、需要注意的是 **弱等差子序列**  的要求是: "至少为两个"，因此三个也是一个 **弱等差子序列**  

由于尾项和公差可以确定一个**等差数列**，因此我们定义状态 $f[i][d]$​ 表示尾项为 $\textit{nums}[i] $​，公差为 $d$​ 的**弱等差子序列**的个数。

我们用一个二重循环去遍历 $\textit{nums}$​ 中的所有元素对 $(\textit{nums}[i],\textit{nums}[j])$​，其中 $j<i$​。将 $\textit{nums}[i]$​ 和 $\textit{nums}[j]$​ 分别当作**等差数列**的**尾项**和**倒数第二项**，则该等差数列的公差 $d=\textit{nums}[i]-\textit{nums}[j]$​。由于**公差**相同，我们可以将 $\textit{nums}[i]$​ 加到以 $\textit{nums}[j]$​ 为尾项，公差为 $d$​ 的**弱等差子序列**的末尾，这对应着状态转移 $f[i][d] += f[j][d]$​。同时，$(\textit{nums}[i],\textit{nums}[j])$​ 这一对元素也可以当作一个**弱等差子序列**，故有状态转移

$$
f[i][d]+=f[j][d]+1
$$

> NOTE: 
>
> 一、上述思路，在 [【负雪明烛】揭秘子序列动态规划的套路](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/fu-xue-ming-zhu-jie-mi-zi-xu-lie-dong-ta-gepk/) 中，有着更好的描述
>
> 在 [【负雪明烛】揭秘子序列动态规划的套路](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/fu-xue-ming-zhu-jie-mi-zi-xu-lie-dong-ta-gepk/) 中，对二重循环有着非常好的论述
>
> 二、需要注意的是， $f[i][d]$​​ 所记录的并不是问题的解，它所记录的是 "**弱等差子序列**的个数"，而最终的答案是"**等差子序列**"
>
> 因此，需要搞清楚"**弱等差子序列**的个数"、"**等差子序列**"的算法:
>
> 1、上面这段话已经描述了 "**弱等差子序列**的个数" 的算法，上面这段话特地对 "+1" 进行了介绍

由于题目要统计的**等差子序列**至少有三个元素，我们回顾上述二重循环，其中「将 $\textit{nums}[i]$​ 加到以 $\textit{nums}[j]$​ 为**尾项**，公差为 $d$​ 的**弱等差子序列**的末尾」这一操作，实际上就构成了一个至少有三个元素的等差子序列，因此我们将循环中的 $f[j][d]$​ 累加，即为答案。

> NOTE: 
>
> 这段话，需要结合下面的source code来进行理解

代码实现时，由于 $\textit{nums}[i]$​ 的范围很大，所以计算出的公差的范围也很大，我们可以将状态转移数组 $f$​ 的第二维用**哈希表**代替。



### 完整代码

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int numberOfArithmeticSlices(vector<int> &nums)
	{
		int ans = 0;
		int n = nums.size();
		vector<unordered_map<long long, int>> f(n); // key: 公差 value: 若等差数列的个数
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				long long d = 1LL * nums[i] - nums[j]; // 计算公差
				auto it = f[j].find(d);
				int cnt = it == f[j].end() ? 0 : it->second;
				ans += cnt;//只有当在j中找到了公差d的时候，它们才能够形成一个长度大于等于3的等差数列
				f[i][d] += cnt + 1;
			}
		}
		return ans;
	}
};

int main()
{
	Solution s;
	vector<int> nums { 2, 4, 6, 8, 10 };
	s.numberOfArithmeticSlices(nums);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

> NOTE: 
>
> 关于上述嵌套for循环，在 [【负雪明烛】揭秘子序列动态规划的套路](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/fu-xue-ming-zhu-jie-mi-zi-xu-lie-dong-ta-gepk/) 中，有着非常好的描述；
>
> 





## [liweiwei1419](https://leetcode-cn.com/u/liweiwei1419/) # [动态规划（Java）](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/dong-tai-gui-hua-java-by-liweiwei1419-jc84/)

本题与 [413. 等差数列划分](https://leetcode-cn.com/problems/arithmetic-slices/) 唯一不同的是：题目要求的等差数列在输入数组上 **可以不连续**，所以「滑动窗口」用不上，但是「动态规划」多半可以。

### 状态定义

> **关键**：状态不够用了，需要「升维」，在原来定义的状态的基础上加上「公差」。

1、「以 `nums[i]` 结尾」这件事情肯定要定义在状态中；

2、题目不要求连续，因此在求每一个状态的时候，就需要 **考虑它之前的所有的元素**；

3、能不能接上去，看「公差」，因此记录状态的时候，除了要求以 `nums[i]` 结尾以外，还要记录「公差」，两个整数的差可以有很多很多，因此需要用哈希表记录下来。



## [[负雪明烛]揭秘子序列动态规划的套路](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/fu-xue-ming-zhu-jie-mi-zi-xu-lie-dong-ta-gepk/) 

我见到**子序列问题**，就想到了经典的题目：[300. 最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)。也就是想起来了动态规划，本题和 300 题的动态规划的思路是相通的。

先从整体思路说起。

子序列问题，由于是数组中的非连续的一个序列，使用动态规划求解时，避免不了二重循环：

第一重循环是求解动态规划的每一个状态 $dp[i], (0 <= i <= N)$，

第二重循环是向前寻找上一个子序列的结尾 $j,(0<=j<i)$   来和 $i$ 一起构成满足题意的新的子序列。

> NOTE: 
>
> 一、上面这段描述，其实结合最长递增子序列是非常好理解的，参见 `Expert-labuladong\1-动态规划系列\1.2-子序列类型问题\LIS-最长递增子序列` 章节
>
> 二、divide conquer-problem原问题subproblem子问题
>
> 显然内部循环是从子问题推到出更大问题的过程，这其实就是状态的转移
>
> 三、始终转移：`i` 是外循环，`j`是内循环

1、对于「**最长递增子序列**」问题，我们对 $i, j$ 的要求是 $nums[i] > nums[j]$，即递增；

2、对于「**能构成等差数列的子序列**」问题，我们对 $i, j$ 的要求是 $num[i]$ 可以在 $nums[j]$ 的基础上构成等差数列。

> NOTE: 
>
> 这就是从子问题转移到更大的问题

在动态规划问题中，我们找到一个符合条件的 $j$ ，然后就可以通过状态转移方程由 $dp[j]$ 推导出 $dp[i]$。

然后，我理一下本题的解法。

一、**两重循环**：外部循环用于计算每个 `i` 位置的状态，内部循环用于寻找符合条件的 `j` 。

> NOTE:
>
> 其实 `i` 描述的是问题的规模，它其实对应的是回溯法的

二、**何为符合条件？**

令等差数列的公差 $ diff = nums[i] - nums[j]$，如果 $nums[j]$ 是一个公差为 $diff$ 的等差数列的结尾数字，则 $nums[j]$ 符合条件。



三、**状态定义？**

在上面的分析中，我们看到对于 $j$ 位置会有多个 $diff$，所以一维的状态转移方程已经不够用了。必须定义两维的状态 $dp[i][diff]$，但是由于 $diff$ 的取值范围很大，所以不能用二维数组。最终定义两位的状态是 $ dp[i]−>dict $，其含义是在 $i$ 位置，以 $diff$ 为公差的、且以 $nums[i]$ 为结尾元素的等差数列的个数为 $dp[i][diff] - 1$。为什么要减一，见[李威威的题解](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/dong-tai-gui-hua-java-by-liweiwei1419-jc84/)。

> NOTE:
>
> 一、上述 $ dp[i]−>dict $ 的含义是 $ dp[i] $ 的类型是 `dict`。
>
> 二、减一是因为要扣除长度为2的

四、**状态转移方程？**

当寻找到了一个 $j$ 符合条件时，相当于在长度为 $dp[j][diff]$ 的**递增子序列**的尾部增加了一个元素 $nums[i]$，所以以 $diff$ 为公差的、且以 $nums[i]$ 为结尾元素的等差数列的个数为 $dp[i][diff] += dp[j][diff] + 1。$



五、**结果？**

题目要求的结果是所有能形成等差数列的子序列的个数，所以结果是累加所有的状态。这时候注意要加的是 $dp[j][diff]$，因为只有 $j$ 位置也出现了同样的 $diff$ 的时候，才会和 $i$ 一起形成长度 > 3 的等差数列。

### 代码

```python
class Solution(object):
    def numberOfArithmeticSlices(self, nums):
        N = len(nums)
        dp = [collections.defaultdict(int) for i in range(N)]
        res = 0
        for i in range(N):
            for j in range(i):
                diff = nums[i] - nums[j]
                dp[i][diff] += dp[j][diff] + 1
                if dp[j][diff]:
                    res += dp[j][diff]
        return res

```



## [【宫水三叶】详解如何分析「序列 DP」问题（附序列 DP 问题目录）](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/gong-shui-san-xie-xiang-jie-ru-he-fen-xi-ykvk/)

动态规划 + 容斥原理

既然分析出是序列 DP 问题，我们可以先猜想一个基本的状态定义，看是否能够「不重不漏」的将状态通过转移计算出来。如果不行，我们再考虑引入更多的维度来进行求解。

先从最朴素的猜想出发，定义 $f[i]$ 为考虑下标不超过 $i$的所有数，并且以 $nums[i]$ 为结尾的等差序列的个数。

| 题目                                                         | 题解                                                         | 难度 | 推荐指数 |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ---- | -------- |
| [354. 俄罗斯套娃信封问题](https://leetcode-cn.com/problems/russian-doll-envelopes/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/russian-doll-envelopes/solution/zui-chang-shang-sheng-zi-xu-lie-bian-xin-6s8d/) | 困难 | 🤩🤩🤩🤩🤩    |
| [368. 最大整除子集](https://leetcode-cn.com/problems/largest-divisible-subset/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/largest-divisible-subset/solution/gong-shui-san-xie-noxiang-xin-ke-xue-xi-0a3jc/) | 中等 | 🤩🤩🤩🤩     |
| [446. 等差数列划分 II - 子序列](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/arithmetic-slices-ii-subsequence/solution/gong-shui-san-xie-xiang-jie-ru-he-fen-xi-ykvk/) | 困难 | 🤩🤩🤩🤩🤩    |
| [740. 删除并获得点数](https://leetcode-cn.com/problems/delete-and-earn/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/delete-and-earn/solution/gong-shui-san-xie-zhuan-huan-wei-xu-lie-6c9t0/) | 中等 | 🤩🤩🤩🤩🤩    |
| [978. 最长湍流子数组](https://leetcode-cn.com/problems/longest-turbulent-subarray/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/longest-turbulent-subarray/solution/xiang-jie-dong-tai-gui-hua-ru-he-cai-dp-3spgj/) | 中等 | 🤩🤩🤩      |
| [1035. 不相交的线](https://leetcode-cn.com/problems/uncrossed-lines/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/uncrossed-lines/solution/gong-shui-san-xie-noxiang-xin-ke-xue-xi-bkaas/) | 中等 | 🤩🤩🤩🤩     |
| [1143. 最长公共子序列](https://leetcode-cn.com/problems/longest-common-subsequence/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/longest-common-subsequence/solution/gong-shui-san-xie-zui-chang-gong-gong-zi-xq0h/) | 中等 | 🤩🤩🤩🤩     |
| [1713. 得到子序列的最少操作次数](https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/) | [LeetCode 题解链接](https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/solution/gong-shui-san-xie-noxiang-xin-ke-xue-xi-oj7yu/) | 困难 | 🤩🤩🤩🤩🤩    |

