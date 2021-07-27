# LeetCode [9. 回文数](https://leetcode-cn.com/problems/palindrome-number/) 简单



https://www.nowcoder.com/profile/438208443/test/45432904/1700873#summary

```Java
public boolean isPalindrome(long x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }
 
    long tempNum = 0;
    while (x > tempNum) {
        tempNum = tempNum * 10 + x % 10;
        x /= 10;
    }
     
    return x == tempNum || x == tempNum / 10;
}
```

存在两种可能: 

1、一种是回文数的长度为偶数

此时 `x == tempNum`，比如 `1001`

2、一种是长度为奇数

此时 `x == tempNum / 10`，比如 `10001`

## 我的解题



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
		while (x > tempNum)
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

