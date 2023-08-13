# Int to string



## 包含integer overflow的版本

```c++
#include <bits/stdc++.h>
using namespace std;
static char Int2Char[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

class Solution
{

public:
	const char* IntToString(int number)
	{
		bool is_negative = false; // 是否是负数
		if (number < 0)
		{
			is_negative = true;
			number = -number;
		}
		if (number == 0)
		{
			return "0";
		}
		char bits[10]; // INT_MAX 10位
		int count = 0; // 统计有多少位
		while (number > 0)
		{
			bits[count++] = Int2Char[number % 10];
			number /= 10;
		}
		char *str = nullptr; // 返回值，是一个C string
		int start_pos = 0; // 填放数字的其实位置
		if (is_negative)
		{
			str = new char[count + 2];
			str[0] = '-';
			start_pos += 1;
		}
		else
		{
			str = new char[count + 1];
		}
		for (int i = count - 1; i >= 0; --i)
		{
			str[start_pos++] = bits[i];
		}
		str[start_pos] = 0;
		return str;
	}
};

int main()
{
	Solution s;
	cout << s.IntToString(0) << endl;
	cout << s.IntToString(1) << endl;
	cout << s.IntToString(1122) << endl;
	cout << s.IntToString(INT_MAX) << endl;
	cout << s.IntToString(INT_MIN) << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

上述实现的一个弊端是: 

`- INT_MIN` 会出现overflow。



## 不包含integer overflow的版本

解决方法是使用unsigned integer。

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
	const char* IntToString(int number)
	{
		static const char *Int2Char = "0123456789";
		unsigned int unumber;
		bool is_negative = false; // 是否是负数
		if (number < 0)
		{
			is_negative = true;
			unumber = (unsigned int) -number;
		}
		else
		{
			unumber = number;
		}
		// 符号位1位()
		// 是一个C string，因此，有分隔符一位
		// 数字位最长为 10位
		// 所以，最多需要12 = 10 + 1 +1 位
		char *str = new char[12];
		int pos = 0; // 填放数字的起始位置
		if (is_negative)
		{
			str[pos] = '-';
			pos += 1;
		}
		do
		{
			str[pos++] = Int2Char[unumber % 10];
			unumber /= 10;
		} while (unumber);

		if (is_negative)
		{
			reverse(str, 1, pos - 1);
		}
		else
		{
			reverse(str, 0, pos - 1);
		}
		str[pos] = 0;
		return str;
	}
	/**
	 * @brief 双指针反转字符串
	 *
	 * @param str
	 * @param left
	 * @param right
	 */
	void reverse(char *str, int left, int right)
	{
		while (left < right)
		{
			swap(str[left], str[right]);
			++left;
			--right;
		}
	}
};

int main()
{
	Solution s;
	int number = 0;
	cout << number << endl;
	cout << s.IntToString(number) << endl;
	cout << "----------" << endl;

	number = 1;
	cout << number << endl;
	cout << s.IntToString(number) << endl;
	cout << "----------" << endl;

	number = 1122;
	cout << number << endl;
	cout << s.IntToString(number) << endl;
	cout << "----------" << endl;

	number = -1122;
	cout << number << endl;
	cout << s.IntToString(number) << endl;
	cout << "----------" << endl;

	number = INT_MAX;
	cout << number << endl;
	cout << s.IntToString(number) << endl;
	cout << "----------" << endl;

	number = INT_MIN;
	cout << number << endl;
	cout << s.IntToString(number) << endl;
	cout << "----------" << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```



## 参考文章

cnblogs [itoa的源代码实现](https://www.cnblogs.com/zfyouxi/p/4011020.html)

CSDN [itoa的源码实现](https://blog.csdn.net/yang15225094594/article/details/8129991)

geeksforgeeks [Implement your own itoa()](https://www.geeksforgeeks.org/implement-itoa/)



## `itoa` source code

[glibc](https://code.woboq.org/userspace/glibc/)/[stdio-common](https://code.woboq.org/userspace/glibc/stdio-common/)/[_itoa.c](https://code.woboq.org/userspace/glibc/stdio-common/_itoa.c.html)
