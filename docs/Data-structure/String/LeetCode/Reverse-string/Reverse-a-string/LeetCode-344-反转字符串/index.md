# [LeetCode-344. 反转字符串](https://leetcode.cn/problems/reverse-string/)



## 我的解答

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	void reverseString(vector<char> &s)
	{
		int left = 0, right = s.size() - 1;
		while (left < right)
		{
			swap(s[left], s[right]);
			left++;
			right--;
		}
	}
};
template<typename ...Args>
ostream& operator<<(ostream &stream, vector<Args...> v)
{
	for (auto &&i : v)
		stream << i;
	return stream;
}

int main()
{
	vector<char> str { 'h', 'e', 'l', 'l', 'o' };
	Solution s;
	s.reverseString(str);
	cout << str << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```



## [官方解答](https://leetcode.cn/problems/reverse-string/solution/)



```C++
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief
 * 作者：LeetCode-Solution
 链接：https://leetcode.cn/problems/reverse-string/solution/fan-zhuan-zi-fu-chuan-by-leetcode-solution/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 */
class Solution
{
public:
	void reverseString(vector<char> &s)
	{
		int n = s.size();
		for (int left = 0, right = n - 1; left < right; ++left, --right)
		{
			swap(s[left], s[right]);
		}
	}
};

template<typename ...Args>
ostream& operator<<(ostream &stream, vector<Args...> v)
{
	for (auto &&i : v)
		stream << i;
	return stream;
}

int main()
{
	vector<char> str { 'h', 'e', 'l', 'l', 'o' };
	Solution s;
	s.reverseString(str);
	cout << str << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11
```

