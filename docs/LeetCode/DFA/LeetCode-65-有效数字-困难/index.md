# LeetCode [65. 有效数字](https://leetcode-cn.com/problems/valid-number/)

## 我的解题

将输入进行分类:

1、符号字符（`'+'` 或 `'-'`）

2、 `'e'` 或 `'E'` 

3、`.`

4、数字 `[0-9]`

5、其他字符



## 官方解题

![fig1](https://assets.leetcode-cn.com/solution-static/65/1.png)

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	enum State
	{
		STATE_INITIAL, // 初始状态
		STATE_INT_SIGN, // 符号位
		STATE_INTEGER, // 整数部分
		STATE_POINT, // 小数点(左有整数)
		STATE_POINT_WITHOUT_INT, // 小数点(左无整数)
		STATE_FRACTION, // 小数部分
		STATE_EXP, // 字符e、指数部分
		STATE_EXP_SIGN, // 指数符号
		STATE_EXP_NUMBER, // 指数数字
		STATE_END
	};

	enum CharType
	{
		CHAR_NUMBER, // 数字
		CHAR_EXP, // e E
		CHAR_POINT, // 小数点
		CHAR_SIGN, // 符号位
		CHAR_ILLEGAL
	};

	CharType toCharType(char ch)
	{
		if (ch >= '0' && ch <= '9')
		{
			return CHAR_NUMBER;
		}
		else if (ch == 'e' || ch == 'E')
		{
			return CHAR_EXP;
		}
		else if (ch == '.')
		{
			return CHAR_POINT;
		}
		else if (ch == '+' || ch == '-')
		{
			return CHAR_SIGN;
		}
		else
		{
			return CHAR_ILLEGAL;
		}
	}

	bool isNumber(string s)
	{
		unordered_map<State, unordered_map<CharType, State>> transfer { //
		{ STATE_INITIAL, { { CHAR_NUMBER, STATE_INTEGER }, { CHAR_POINT, STATE_POINT_WITHOUT_INT }, { CHAR_SIGN, STATE_INT_SIGN } } }, //
						{ STATE_INT_SIGN, { { CHAR_NUMBER, STATE_INTEGER }, { CHAR_POINT, STATE_POINT_WITHOUT_INT } } }, //
						{ STATE_INTEGER, { { CHAR_NUMBER, STATE_INTEGER }, { CHAR_EXP, STATE_EXP }, { CHAR_POINT, STATE_POINT } } }, //
						{ STATE_POINT, { { CHAR_NUMBER, STATE_FRACTION }, { CHAR_EXP, STATE_EXP } } }, //
						{ STATE_POINT_WITHOUT_INT, { { CHAR_NUMBER, STATE_FRACTION } } }, { STATE_FRACTION, { { CHAR_NUMBER, STATE_FRACTION }, { CHAR_EXP, STATE_EXP } } }, //
						{ STATE_EXP, { { CHAR_NUMBER, STATE_EXP_NUMBER }, { CHAR_SIGN, STATE_EXP_SIGN } } }, //
						{ STATE_EXP_SIGN, { { CHAR_NUMBER, STATE_EXP_NUMBER } } }, //
						{ STATE_EXP_NUMBER, { { CHAR_NUMBER, STATE_EXP_NUMBER } } } //
		};

		int len = s.length();
		State st = STATE_INITIAL;

		for (int i = 0; i < len; i++)
		{
			CharType typ = toCharType(s[i]);
			if (transfer[st].find(typ) == transfer[st].end())
			{
				return false;
			}
			else
			{
				st = transfer[st][typ];
			}
		}
		return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
	}
};

int main()
{
	Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```



