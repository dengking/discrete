# leetcode [316. 去除重复字母](https://leetcode-cn.com/problems/remove-duplicate-letters/)

这道题的  "**返回结果的字典序最小**" 的要求，和 leetcode [402. 移掉K位数字](https://leetcode-cn.com/problems/remove-k-digits/) 中的"剩下的数字最小"，本质上是相同的。

两道题的非常类似，一个是去除k个字符，一个是去除重复字符。

两道题，都要求保持相对位置不变



## 用例



| 输入     | 输出  |
| -------- | ----- |
| `aabbcc` | `abc` |
|          |       |
|          |       |



```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	static inline int IndexOf(char c)
	{
		return c - 'a';
	}
	string removeDuplicateLetters(string s)
	{
		vector<int> in_stack(26); // 是否在栈中
		vector<int> char_count(26); // 剩余字符个数
		for (auto &&c : s)
		{
			char_count[IndexOf(c)] += 1;
		}
		string mono_stack;
		for (auto &&c : s)
		{
			if (!in_stack[IndexOf(c)]) // 不在栈中
			{
				while (mono_stack.size() > 0 && c < mono_stack.back())
				{
					char top = mono_stack.back();
					/**
					 * 需要保持相对位置，因此，只有当原字符串中，top字符的剩余个数大于一个的时候，才能够将其弹出栈
					 */
					if (char_count[IndexOf(top)] > 0)
					{
						in_stack[IndexOf(top)] = 0;
						mono_stack.pop_back();
					}
					else
					{
						break;
					}
				}
				in_stack[IndexOf(c)] = 1;
				mono_stack.push_back(c);
			}
			--char_count[IndexOf(c)];
		}
		return mono_stack;
	}
};

// Driven Program
int main()
{
	Solution s;
	cout << s.removeDuplicateLetters("bcabc") << endl;
	cout << s.removeDuplicateLetters("cbacdcbc") << endl;
	cout << s.removeDuplicateLetters("aabbcc") << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



## [标准答案](https://leetcode-cn.com/problems/remove-duplicate-letters/solution/qu-chu-zhong-fu-zi-mu-by-leetcode-soluti-vuso/)

```C++
#include <bits/stdc++.h>
using namespace std;
/**
 * 作者：LeetCode-Solution
 链接：https://leetcode-cn.com/problems/remove-duplicate-letters/solution/qu-chu-zhong-fu-zi-mu-by-leetcode-soluti-vuso/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 */
class Solution
{
public:
	string removeDuplicateLetters(string s)
	{
		vector<int> vis(26), num(26);
		for (char ch : s)
		{
			num[ch - 'a']++;
		}

		string stk;
		for (char ch : s)
		{
			if (!vis[ch - 'a'])
			{
				while (!stk.empty() && stk.back() > ch)
				{
					if (num[stk.back() - 'a'] > 0)
					{
						vis[stk.back() - 'a'] = 0;
						stk.pop_back();
					}
					else
					{
						break;
					}
				}
				vis[ch - 'a'] = 1;
				stk.push_back(ch);
			}
			num[ch - 'a'] -= 1;
		}
		return stk;
	}
};


```

