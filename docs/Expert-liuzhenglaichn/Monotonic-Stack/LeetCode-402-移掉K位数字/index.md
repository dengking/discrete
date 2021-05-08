# leetcode [402. 移掉K位数字](https://leetcode-cn.com/problems/remove-k-digits/)



例子:

121219 k=3

答案: 111



12021 k=3

答案: 1



要求: 

1、保证相对顺序

2、剩余位数



规律是什么？

1、尽可能地从最高有效位开始删起，总是选择较小的digit，删除较大的digit(贪心)

monotonic stack的优势:

1、它的排序能够保持相对位置



## 我的解题

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
		 * 处理`1234567` 这种已经是单调递增的序列，这种序列，单调栈是无法处理的
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





## [标准答案](https://leetcode-cn.com/problems/remove-k-digits/solution/yi-diao-kwei-shu-zi-by-leetcode-solution/)

### 贪心 + 单调栈



### 完整程序

耗时更少，不知为何。

```C++
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * 作者：LeetCode-Solution
 链接：https://leetcode-cn.com/problems/remove-k-digits/solution/yi-diao-kwei-shu-zi-by-leetcode-solution/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 */
class Solution
{
public:
	string removeKdigits(string num, int k)
	{
		vector<char> stk;
		for (auto &digit : num)
		{
			while (stk.size() > 0 && stk.back() > digit && k)
			{
				stk.pop_back();
				k -= 1;
			}
			stk.push_back(digit);
		}

		for (; k > 0; --k)
		{
			stk.pop_back();
		}

		string ans = "";
		bool isLeadingZero = true;
		for (auto &digit : stk)
		{
			if (isLeadingZero && digit == '0')
			{
				continue;
			}
			isLeadingZero = false;
			ans += digit;
		}
		return ans == "" ? "0" : ans;
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

