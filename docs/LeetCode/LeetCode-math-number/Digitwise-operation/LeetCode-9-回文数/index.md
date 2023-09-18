# [LeetCode-9. 回文数-简单](https://leetcode.cn/problems/palindrome-number/) 



## 我的解题

存在两种可能: 

1、一种是回文数的长度为偶数

此时 `x == tempNum`，比如 `1001`

2、一种是长度为奇数

此时 `x == tempNum / 10`，比如 `10001`



下面的解法是非常类似于左右双指针-相向而行-stop-condition: equal

构造一个 `tempNum` ，如果它是一个回文数，那么两个数要么相等，要么相差10倍。



```C++
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	bool isPalindrome(long x)
	{
		if (x < 0 || (x % 10 == 0 && x != 0))
		{
			return false;
		}

		long tempNum = 0;
		while (x > tempNum) // stop-condition: tempNum >= x
		{
			tempNum = tempNum * 10 + x % 10;
			x /= 10;
		}
		//	存在两种可能:
		//
		//	1、一种是回文数的长度为偶数
		//
		//	此时 `x == tempNum`，比如 `1001`
		//
		//	2、一种是长度为奇数
		//
		//	此时 `x == tempNum / 10`，比如 `10001`
		return x == tempNum || x == tempNum / 10;
	}
};

// Driver code
int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```



https://www.nowcoder.com/profile/438208443/test/45432904/1700873#summary



