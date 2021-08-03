# LeetCode [556. 下一个更大元素 III](https://leetcode-cn.com/problems/next-greater-element-iii/) 中等



## 我的解题

暴力解法:

通过组合生成所有的可能的数，然后二分查找；

或者DFS；



这个题，和 LeetCode [31. 下一个排列](https://leetcode-cn.com/problems/next-permutation/) 非常类似；两道题，本质上是类似的；都有着"贪心思想"。



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

