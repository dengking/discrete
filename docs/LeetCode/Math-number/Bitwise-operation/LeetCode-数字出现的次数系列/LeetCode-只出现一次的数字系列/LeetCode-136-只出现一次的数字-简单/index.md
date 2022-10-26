# [LeetCode-136. 只出现一次的数字-简单](https://leetcode.cn/problems/single-number/) 



## 我的解题



## 官方解题

如何才能做到线性时间复杂度和常数空间复杂度呢？

答案是使用位运算。对于这道题，可使用异或运算 $\oplus$。异或运算有以下三个性质。

1、任何数和 $0$ 做异或运算，结果仍然是原来的数，即 $a \oplus 0=a$。

2、任何数和其自身做异或运算，结果是 $0$，即 $a \oplus a=0$。

3、**异或运算**满足**交换律**和**结合律**，即 $a \oplus b \oplus a=b \oplus a \oplus a=b \oplus (a \oplus a)=b \oplus0=b$。

> NOTE:
>
> 一、为什么 $\oplus$ 满足 **交换律**和**结合律**，其实从CPU执行计算的过程就可以得知，当对一个number执行bitwise-XOR的时候，CPU是逐bit进行的，所以它最终都归结为0、1的操作，所以以01来进行理解做好:
>
> ```C++
> 1 ^= 0 ^= 1 = 0
> 0 ^= 1 ^= 0 = 1
> ```
>
> 

因此，数组中的全部元素的异或运算结果即为数组中只出现一次的数字。



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int singleNumber(vector<int> &nums)
	{
		int single = 0;
		for (auto &&num : nums)
		{
			single ^= num;
		}
		return single;
	}
};

int main()
{
	Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

