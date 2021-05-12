# leetcode [78. 子集](https://leetcode-cn.com/problems/subsets/)



## [官方解题](https://leetcode-cn.com/problems/subsets/solution/zi-ji-by-leetcode-solution/)

> NOTE: 
>
> 1、典型的子集树: 每个元素有两种选择，则长度为`n`的集合，它的解空间大小为$2^n$

### 方法一：迭代法实现子集枚举

我们用 $1$ 表示「在子集中」，$0$ 表示不在子集中，那么每一个子集可以对应一个长度为 $n$ 的 $0/1$ 序列，第 $i$ 位表示 $a_i$ 是否在子集中。例如，$n = 3$ ，$a = \{ 5, 2, 9 \}$ 时

> NOTE: 
>
> 1、显然建立了bijection: 每个subset对应了一个"长度为 $n$ 的 $0/1$ 序列"
>
> 

| 0/1 序列 | 子集          | 0/10/1 序列对应的二进制数 |
| -------- | ------------- | ------------------------- |
| 000      | \{ \}         | 0                         |
| 001      | \{ 9 \}       | 1                         |
| 010      | \{ 2 \}       | 2                         |
| 011      | \{ 2, 9 \}    | 3                         |
| 100      | \{ 5 \}       | 4                         |
| 101      | \{ 5, 9 \}    | 5                         |
| 110      | \{ 5, 2 \}    | 6                         |
| 111      | \{ 5, 2, 9 \} | 7                         |



可以发现 $0/1$ 序列对应的二进制数正好从 $0$ 到 $2^{n}- 1$。我们可以枚举 $\textit{mask} \in [0, 2^n - 1]$，$\textit{mask}$的二进制表示是一个 $0/1$ 序列，我们可以按照这个 $0/1$ 序列在原集合当中取数。当我们枚举完所有 $2^n $ 个 $\textit{mask}$，我们也就能构造出所有的子集。



#### 完整程序

```C++
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 作者：LeetCode-Solution
 链接：https://leetcode-cn.com/problems/subsets/solution/zi-ji-by-leetcode-solution/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 */
class Solution
{
public:
	vector<int> t;
	vector<vector<int>> ans;

	vector<vector<int>> subsets(vector<int> &nums)
	{
		int n = nums.size();
		for (int mask = 0; mask < (1 << n); ++mask)
		{
			t.clear();
			for (int i = 0; i < n; ++i) // 遍历 bit
			{
				if (mask & (1 << i)) // 使用bitwise AND 来 Querying the status of a bit
				{
					t.push_back(nums[i]);
				}
			}
			ans.push_back(t);
		}
		return ans;
	}
};

template<typename ...Args>
ostream& operator <<(ostream &stream, const vector<Args...> &v)
{
	for (auto &&i : v)
	{
		stream << i << endl;
	}
	return stream;
}
int main()
{
	vector<int> nums { 1, 2, 3 };

	Solution s;
	vector<vector<int>> subsets = s.subsets(nums);
	cout << subsets.size() << endl;
	cout << subsets << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```

