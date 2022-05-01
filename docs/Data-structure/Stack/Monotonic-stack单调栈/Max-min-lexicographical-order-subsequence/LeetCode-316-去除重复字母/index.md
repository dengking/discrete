# leetcode [316. 去除重复字母](https://leetcode-cn.com/problems/remove-duplicate-letters/)

一、这道题的  "**返回结果的字典序最小**" 的要求，和 leetcode [402. 移掉K位数字](https://leetcode-cn.com/problems/remove-k-digits/) 中的"剩下的数字最小"，本质上是相同的，继续使用 "monotonic-stack+greedy" 策略。

1、两道题的非常类似，一个是去除k个字符，一个是去除重复字符

2、两道题，都要求保持相对位置不变



二、这道题的要求以及实现方式：

1、最终的**字典序**最小

这个通过"monotonic-stack+greedy"来进行实现；

2、最终的字符中，不包含重复字符

显然一个直观的做法就是判断当前字符是否已经选择了，如果已经选择了，则不在考虑，直接pass掉。这道题是使用的`in_stack`，一个bool visited array来进行去重的。

3、最终的字符中需要包含所有的字符

在删除元素的时候，会判断它剩余的数目，如果没有剩余的只了，为了保证最终结果包含所有的字符，则不删除，此时需要终止删除流程，因为题目要求保持相对顺序，因此如果当前元素不能够删除，那么它前面的元素也是不能够被删除的。

四、由于涉及删除元素，因此在删除的时候，需要将对应的元素从visited array中剔除。

五、这道题在

## 用例



1、bbba

答案：`ba`

2、ccbaba

答案：`cab`



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





## 我的解题

正如 [力扣加加](https://leetcode-cn.com/u/fe-lucifer/) # [一招吃遍力扣四道题，妈妈再也不用担心我被套路啦～](https://leetcode-cn.com/problems/remove-duplicate-letters/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-4/) 所言，`in_stack` 是典型的以空间换时间，便于快速判断当前字符是否已经位于栈中了。

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
			if (!in_stack[IndexOf(c)]) // 不在栈中，过滤掉重复字符
			{
				while (mono_stack.size() > 0 && c < mono_stack.back())
				{
					char top = mono_stack.back(); // 由于我们使用string来作为stack，所以string.back对应的是stack.top
					/**
					 * 需要保持相对位置，因此，只有当原字符串中，top字符的剩余个数大于一个的时候，才能够将其弹出栈
					 */
					if (char_count[IndexOf(top)] > 0)
					{
						in_stack[IndexOf(top)] = 0; // 对in_stack进行维护
						mono_stack.pop_back();
					}
					else // 如果当前元素不能够被pop，则需要停止这个while，因为需要保持相对顺序
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

### 二刷

```c++
// #include <bits/stdc++.h>
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
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

class Solution
{
public:
  string removeDuplicateLetters(string s)
  {
    std::unordered_map<char, int> counter; // 各个字符属于掉数量
    std::unordered_set<char> in_set;
    for (auto &&c : s)
    {
      ++counter[c];
    }
    std::string stk; // 使用monolithic stack来保存选中的字符
    for (auto &&c : s)
    {
      if (in_set.count(c) == 0) // 去重
      {
        while (!stk.empty() && stk.back() > c) // 只有有重复元素的，才能够剔除掉
        {
          if (counter[stk.back()] > 0) // 如果剩余数量大于0，则考虑将它剔除
          {
            in_set.erase(stk.back());
            stk.pop_back();
          }
          else // 如果不满足，则需要终止，因为要保持相对位置
          {
            break;
          }
        }
        stk.push_back(c);
        in_set.insert(c);
      }
      --counter[c]; // 每处理一个，就减去1
    }
    return stk;
  }
};

int main()
{
  Solution s;
  vector<int> nums{5, 1, 1};
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

