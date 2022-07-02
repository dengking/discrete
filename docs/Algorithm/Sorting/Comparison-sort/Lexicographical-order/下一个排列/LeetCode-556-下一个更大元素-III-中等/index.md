# LeetCode [556. 下一个更大元素 III](https://leetcode.cn/problems/next-greater-element-iii/) 中等



这个题，和 LeetCode [31. 下一个排列](https://leetcode.cn/problems/next-permutation/) 非常类似；两道题，本质上是类似的；都有着"贪心思想"。



## 我的解题



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int nextGreaterElement(int n)
	{
		vector<int> bits;
		while (n > 0)
		{
			bits.push_back(n % 10);
			n /= 10;
		}
		reverse(bits.begin(), bits.end());
		int len = bits.size();
		int i = len - 2;
		while (i >= 0 && bits[i] >= bits[i + 1]) // 寻找连续升序两位
		{
			--i;
		}
		if (i >= 0) // 存在连续升序的两位
		{
			int j = len - 1;
			while (bits[j] <= bits[i])
			{
				--j;
			}
			swap(bits[i], bits[j]);
			reverse(bits.begin() + i + 1, bits.end());
			long ret = 0;
			for (int k = 0; k < len; ++k)
			{
				ret = bits[k] + ret * 10;
				if (ret > INT_MAX)
					return -1;
			}
			return ret;
		}
		else // 不存在连续升序的两位，说明已经是最大的数了
		{
			return -1;
		}
	}
};

int main()
{
	Solution s;
	cout << s.nextGreaterElement(101) << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```



## [c++超100的数学解法](https://leetcode.cn/problems/next-greater-element-iii/solution/cchao-100de-shu-xue-jie-fa-by-ffreturn-rccw/)

> NOTE: 
>
> 这个解法，充分运用了STL，可以减少编码量，从而提高效率

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int nextGreaterElement(int n)
	{
		string s = to_string(n);
		int nn = s.size();
		// 如果只有1个，直接返回失败
		if (nn <= 1)
		{
			return -1;
		}
		// 先找到最小的数字, 从n-2开始无必然有数字可以比较
		int i = nn - 2;
		for (; i >= 0; --i)
		{
			if (s[i] < s[i + 1])
			{
				break;
			}
		}

		// 数组已经是递增，则无法有更大数，返回失败
		if (i < 0)
		{
			return -1;
		}

		// 找到比 s[i] 稍大的 数字 s[j]
		int j = nn - 1;
		for (; j >= 0; --j)
		{
			if (s[j] > s[i])
			{
				break;
			}
		}
		swap(s[i], s[j]);

		// 翻转从i+1到end 的数组
		reverse(s.begin() + i + 1, s.end());

		// 考虑int溢出的情况
		long res = stol(s);
		return res > INT_MAX ? -1 : res;
	}
};

int main()
{
	Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

