# LeetCode [8. 字符串转换整数 (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/)



## 我的解题-未AC



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int myAtoi(string s)
	{
		unsigned long number = 0; // 保存结果
		bool isNegative = false; // 是否是负数
		for (auto &&c : s)
		{
			if (c == ' ')
			{
				continue;
			}

			if (c == '-')
			{
				isNegative = true;
				continue;
			}
			if (c == '+')
			{
				continue;
			}
			if (!isdigit(c))
			{
				if (number == 0) // "words and 987" 返回0
				{
					return 0;
				}
				else
				{
					break;
				}
			}
			int bit = c - '0';
			number = number * 10 + bit;
			if (isNegative)
			{
				if (isUnderflow(number))
				{
					return INT_MIN;
				}
				else
				{
					continue;
				}
			}
			else if (isOverflow(number))
			{
				return INT_MAX;
			}
			else
			{
				continue;
			}
		}
		if (isNegative)
		{

			return -1 * number;
		}
		else
		{
			return number;
		}
	}
	/**
	 * @brief
	 *
	 * @param number
	 * @param isNegative
	 * @return
	 */
	bool isOverflow(unsigned long number)
	{
		if (number > INT_MAX)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool isUnderflow(unsigned long number)
	{
		static unsigned int maxNegativeNumber = (unsigned int) (-INT_MIN);
		if (number > maxNegativeNumber)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	Solution s;
	cout << s.myAtoi("-91283472332") << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

### 为AC的test case

**test case:**

输入：

"+-12"

输出：

-12

预期结果：

0

**test case:**

"3.14159"

**test case:**

"+1"



## 官方解题-DFA

### 思路

**字符串**处理的题目往往涉及复杂的流程以及条件情况，如果直接上手写程序，一不小心就会写出极其臃肿的代码。

因此，为了有条理地分析每个输入字符的处理方法，我们可以使用**自动机**这个概念：

我们的程序在每个时刻有一个状态 `s`，每次从序列中输入一个字符 `c`，并根据字符 `c` 转移到下一个状态 `s'`。这样，我们只需要建立一个覆盖所有情况的从 `s` 与 `c` 映射到 `s'` 的表格即可解决题目中的问题。

### 算法

本题可以建立如下图所示的自动机：

![fig1](https://assets.leetcode-cn.com/solution-static/8/fig1.png)

我们也可以用下面的表格来表示这个**自动机**：

|               | ' '   | +/-    | number    | other |
| ------------- | ----- | ------ | --------- | ----- |
| **start**     | start | signed | in_number | end   |
| **signed**    | end   | end    | in_number | end   |
| **in_number** | end   | end    | in_number | end   |
| **end**       | end   | end    | end       | end   |

> NOTE: 
>
> 一、第一列表示的是**状态**，第一行表示的是**输入**
>
> 上述表格表达了**状态**在**输入**下的转换

接下来编程部分就非常简单了：我们只需要把上面这个**状态转换表**抄进代码即可。

另外**自动机**也需要记录当前已经输入的数字，只要在 `s'` 为 `in_number` 时，更新我们输入的数字，即可最终得到输入的数字。



