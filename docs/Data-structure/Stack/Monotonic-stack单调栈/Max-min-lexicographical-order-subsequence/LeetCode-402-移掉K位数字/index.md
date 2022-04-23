# leetcode [402. 移掉K位数字](https://leetcode-cn.com/problems/remove-k-digits/)

给你一个以字符串表示的非负整数 `num` 和一个整数 `k` ，移除这个数中的 `k` 位数字，使得剩下的数字最小。

## 素材

1、[力扣加加](https://leetcode-cn.com/u/fe-lucifer/) # [一招吃遍力扣四道题，妈妈再也不用担心我被套路啦～](https://leetcode-cn.com/problems/remove-k-digits/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-5/)

这个解答是非常好的。

2、[官方解题](https://leetcode-cn.com/problems/remove-k-digits/solution/yi-diao-kwei-shu-zi-by-leetcode-solution/)



## 例子

121219 k=3

答案: 111



12021 k=3

答案: 1



要求: 

1、保证相对顺序

2、剩余位数

### 最极端的例子

最极端的例子一：

```
12345
```

显然，直接删除掉最右边即可；



最极端的例子二：

```
54321
```

显然，直接删除掉最左边即可；

### 普通例子

```
425
```

显然，删4而非2；



## 我的解题



### 规律是什么？

从高位到地位，从左到右，单调递增的数字最小；

从高位到地位，从左到右，单调递法的数字最大；

尽可能地从最高有效位开始删起，总是选择较小的digit，删除较大的digit(贪心)，其实它就是**字典序**，按照字典序来进行理解是非常快的。

### 算法模式

贪心 + 单调栈

### 完整代码

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	string removeKdigits(string num, int k)
	{
		deque<char> mono_stack; // 单调栈
		int delete_count = 0; // 删除的次数
		for (auto &&digit : num)
		{
			while (delete_count < k && !mono_stack.empty() && digit < mono_stack.back())
			{
				mono_stack.pop_back();
				++delete_count;
			}
			mono_stack.push_back(digit);
		}
		/**
		 * 处理`1234567` 这种已经是单调递增的序列，这种序列，单调栈是无法处理的，因此需要在下面添加程序进行特殊处理
		 */
		for (; delete_count < k; ++delete_count)
		{
			mono_stack.pop_back();
		}
		if (mono_stack.empty())
		{
			return "0";
		}
		else
		{
			std::string ret;
			bool isLeadingZero = true; // 注意输出不能有任何前导零。
			for (auto &&digit : mono_stack)
			{
				if (isLeadingZero && digit == '0')
				{
					continue;
				}
				isLeadingZero = false;
				ret.push_back(digit);
			}
			// 如果mono_stack只有一个0，则ret为空，此时应该返回"0"，而不是ret
			return ret.empty() ? "0" : ret;
		}
	}
};

// Driven Program
int main()
{
	Solution s;
	cout << s.removeKdigits("1432219", 3) << endl;
	cout << s.removeKdigits("10200", 1) << endl;
	cout << s.removeKdigits("10", 2) << endl;
	cout << s.removeKdigits("10", 1) << endl;
}
// g++ test.cpp

```



输出如下:

```
1219
200
0
0
```



