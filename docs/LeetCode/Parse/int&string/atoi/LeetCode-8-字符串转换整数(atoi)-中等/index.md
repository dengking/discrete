# LeetCode [8. 字符串转换整数 (atoi)](https://leetcode.cn/problems/string-to-integer-atoi/)



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

![fig1](https://assets.leetcode.cn/solution-static/8/fig1.png)

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
> 上述表格表达了**当前状态**在**输入**下的转换到的**目标状态**
>
> 二、思考: 上述"automaton"要如何实现呢？
>
> 在下面的source code中，是使用的hash map + vector 来实现的
>
> 对于输入，它是使用的 `index [0-9]` 来进行编码的

接下来编程部分就非常简单了：我们只需要把上面这个**状态转换表**抄进代码即可。

另外**自动机**也需要记录当前已经输入的数字，只要在 `s'` 为 `in_number` 时，更新我们输入的数字，即可最终得到输入的数字。



### 完整程序

```C++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

class Automaton
{
  string state = "start"; // 当前所处的状态
  // DFA
  unordered_map<string, vector<string>> table = {
      {"start", {"start", "signed", "in_number", "end"}},
      {"signed", {"end", "end", "in_number", "end"}},
      {"in_number", {"end", "end", "in_number", "end"}},
      {"end", {"end", "end", "end", "end"}} //
  };
  /**
   * @brief 获得字符 c 所属的类别
   *
   * @param c
   * @return int
   */
  int get_col(char c)
  {
    if (isspace(c))
      return 0;
    if (c == '+' or c == '-')
      return 1;
    if (isdigit(c))
      return 2;
    return 3;
  }

public:
  int sign = 1;
  long long ans = 0;

  void get(char c)
  {
    state = table[state][get_col(c)]; // 下一个状态由当前所处状态 + 当前的输入决定的
    if (state == "in_number")
    {
      ans = ans * 10 + c - '0';
      ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
    }
    else if (state == "signed")
    {
      sign = c == '+' ? 1 : -1;
    }
  }
};

class Solution
{
public:
  int myAtoi(string str)
  {
    Automaton automaton;
    for (char c : str)
      automaton.get(c);
    return automaton.sign * automaton.ans;
  }
};

int main()
{
  Solution s;
  cout << s.myAtoi("-91283472332") << endl;
}
```



### [Edward Elric](https://leetcode.cn/u/zdxiq125/) 评论

准确地说，这是确定有限状态机（deterministic finite automaton, DFA）。其实这题已经不算是容易写“出臃肿代码”的了。考虑清楚边界（主要是溢出处理）和输入种类（+, -, 0-9以及其他），大概在20行内完成代码不难。说实话LC官方题解里很少见给出标准DFA解法的，点个赞。另外看到评论区乌烟瘴气的，真让人唏嘘（没有一点基本的敬畏心、浮躁功利、认为题目边界太复杂导致自己不能AC，那是何其自负）。给两个更加需要DFA的题目吧：[utf-8-validation](https://leetcode.cn/problems/utf-8-validation/) ( [附dfa解法](https://leetcode.cn/problems/utf-8-validation/solution/java-dfa-by-zdxiq125/) ) 以及 [valid-number](https://leetcode.cn/problems/valid-number/)。 顺便贴一下普通解法（那种臃肿的、易错的、可能会被test cases虐到骂娘的；但如果骂娘了，本质还是基本功不扎实）。

