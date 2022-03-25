# leetcode [1711. 大餐计数](https://leetcode-cn.com/problems/count-good-meals/)



## [官方解题](https://leetcode-cn.com/problems/count-good-meals/solution/da-can-ji-shu-by-leetcode-solution-fvg9/)

> NOTE: 
>
> 一、当前元素与它之前的元素的和是否是满足大餐(和为2的幂)，这种做法和比较当前元素和它之后的元素是否满足要求显然要节省很多的时间
>
> 二、它用到了和两数之和中类的技巧: 使用map来记录
>
> 



## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	constexpr static int MOD = 1'000'000'007;
public:
	int countPairs(vector<int> &deliciousness)
	{
		int maxNum = *max_element(deliciousness.begin(), deliciousness.end());
		int maxSum = 2 * maxNum; 
		unordered_map<int, int> mp;
		int ret = 0;
		for (auto &&num : deliciousness)
		{
			for (int sum = 1; sum <= maxSum; sum <<= 1) // 枚举2的幂直至maxSum
			{
				int count = mp.count(sum - num) ? mp[sum - num] : 0;
				ret = (count + ret) % MOD;
			}
			mp[num]++;
		}
		return ret;
	}
};
int main()
{

}

```

