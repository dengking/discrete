# Math、number



## 基础操作



### Extract digits from integer/split an int into its digits

#### C++

一、stackoverflow [How do I split an int into its digits?](https://stackoverflow.com/questions/4261589/how-do-i-split-an-int-into-its-digits)

[A](https://stackoverflow.com/a/4261638)

Given the number 12345 :

```
`5` is `12345 % 10`
`4` is `12345 / 10 % 10`
`3` is `12345 / 100 % 10`
`2` is `12345 / 1000 % 10`
`1` is `12345 / 10000 % 10
```

[A](https://stackoverflow.com/a/4261624)

Reversed order digit extractor (eg. for 23 will be 3 and 2):

```cpp
while (number > 0)
{
    int digit = number%10;
    number /= 10;
    //print digit
}
```

Normal order digit extractor (eg. for 23 will be 2 and 3):

```cpp
std::stack<int> sd;

while (number > 0)
{
    int digit = number%10;
    number /= 10;
    sd.push(digit);
}

while (!sd.empty())
{
    int digit = sd.top();
    sd.pop();
    //print digit
}
```

二、geeksforgeeks [C Program to Print all digits of a given number](https://www.geeksforgeeks.org/c-program-to-print-all-digits-of-a-given-number/)



三、

```c++
/**
 * 将数num转换为base进制
 * @param num 
 * @param base 
 * @return 
 */
std::vector<int> getDigits(int num, int base) {
    std::vector<int> digits;
    while (num) {
        digits.push_back(num % base);
        num /= base;
    }
    return digits;
}

```





### Create number

[LeetCode-9. 回文数-简单](https://leetcode.cn/problems/palindrome-number/) 



```c++
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



## Use tree to represent number



在刘聪 paper [浅谈数位类统计问题](https://www.gydoc.com/p-5722.html) 中，使用了"**逐位确定**"

例子：

1、lexicographical order(字典序)

complete n-ary tree: 在每一位可以选择哪些digit。





## 数位类统计问题 # 乘法原理

[刘聪-浅谈数位类统计问题](https://www.gydoc.com/p-5722.html)  



[LeetCode-233. 数字 1 的个数-困难](https://leetcode.cn/problems/number-of-digit-one/) 

> 基于乘法原理来进行计数
>
> 要统计百位上为1的数的个数，即要统计如下形式：
>
> ```
> **1**
> ```
>
> 固定一位，由它的高位、低位进行组合。
>
> 

```
0
1
2
3
4
5
6
7
8
9
```

乘法原理、重复出现、这道题非常好的展示了数位具有非常好的重复性质。

