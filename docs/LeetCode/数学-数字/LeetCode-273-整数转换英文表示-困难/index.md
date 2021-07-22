# LeetCode [273. 整数转换英文表示](https://leetcode-cn.com/problems/integer-to-english-words/)



## 我的解题



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	static const char *EnglishNumbers { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };

public:
	string numberToWords(int num)
	{
		uint6_t bits[128]; //存储num的各位
		int count = 0; // 一共有多少位
		while (num > 0)
		{
			uint6_t bit = num % 10;
			num /= 10;
			bits[count++] = bit;
		}
		string res;
		for (int i = count - 1; i >= 0; ++i)
		{
			string EnglishNumber { EnglishNumbers[bits[i]] };
			res += EnglishNumber;
		}
	}

};
int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

