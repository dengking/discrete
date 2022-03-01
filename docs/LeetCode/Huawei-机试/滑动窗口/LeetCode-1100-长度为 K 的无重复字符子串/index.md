# [1100. 长度为 K 的无重复字符子串](https://leetcode-cn.com/problems/find-k-length-substrings-with-no-repeated-characters/) 中等



## 我的解题

### 第一次: signed和unsigned比较，导致错误

```C++
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
	int numKLenSubstrNoRepeats(string s, int k) {
		if (s.size() < k) {
			return 0;
		}
		bool duplicate = false;
		int left = 0, right = -1;
		int count = 0;
		cout << "test" << endl;
		unordered_map<char, int> window;
		while (right < s.size()) {
			++right;
			cout << right << endl;
			char inchar = s[right];
			++window[inchar];
			if (window[inchar] > 1) {
				duplicate = true;
			}
			if (right - left == k) { // 阈值
				if (!duplicate) {
					++count;
				}
				char outchar = s[left];
				--window[outchar];
				if (window[outchar] == 0) {
					window.erase(outchar);
				}
				if (!hasDuplicate(window)) {
					duplicate = false;
				}
				++left;
			}

		}
		return count;

	}
	bool hasDuplicate(unordered_map<char, int> window) {
		for (auto&& kv : window) {
			if (kv.second > 1) {
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	string str = "havefunonleetcode";
	int K = 5;
	cout << s.numKLenSubstrNoRepeats(str, K) << endl;

}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

无符号数与有符号数的比较:

`int left = 0, right = -1`，显然`right`是有符号数；

`s.size()`，`size()`的返回值是无符号数，根据stackoverflow [Signed/unsigned comparisons](https://stackoverflow.com/questions/5416414/signed-unsigned-comparisons) # [A](https://stackoverflow.com/a/5416498/10173843) :

> When comparing signed with unsigned, the compiler converts the signed value to unsigned. For equality, this doesn't matter, `-1 == (unsigned) -1`. For other comparisons it matters, e.g. the following is true: `-1 > 2U`.

显然，`-1`会被转化为unsigned，将是最大值。

所以 `while (right < s.size())` 的条件不会被满足，所以循环不会被执行。

### 第二次: `right - left == k` 计算长度错误

```C++
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
	int numKLenSubstrNoRepeats(string s, int k) {
		if (s.size() < k) {
			return 0;
		}
		bool duplicate = false;
		int left = 0, right = -1;
		int count = 0;
		unordered_map<char, int> window;
		int len = s.size();
		while (right < len) {
			++right;
			char inchar = s[right];
			++window[inchar];

			if (right - left == k) { // 阈值
				if (!hasDuplicate(window)) {
					++count;
				}
				char outchar = s[left];
				--window[outchar];
				if (window[outchar] == 0) {
					window.erase(outchar);
				}

				++left;
			}

		}
		return count;

	}
	bool hasDuplicate(unordered_map<char, int> window) {
		for (auto&& kv : window) {
			if (kv.second > 1) {
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	string str = "havefunonleetcode";
	int K = 5;
	cout << s.numKLenSubstrNoRepeats(str, K) << endl;

}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

正确答案是6，但是上述程序的答案是4；

### 第三次: 循环变量right写法有误，导致多算出一个值

```C++
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
	int numKLenSubstrNoRepeats(string s, int k) {
		if (s.size() < k) {
			return 0;
		}
		bool duplicate = false;
		int left = 0, right = -1;
		int count = 0;
		unordered_map<char, int> window;
		int len = s.size();
		while (right < len) {
			++right;
			char inchar = s[right];
			++window[inchar];

			if (right - left + 1 == k) { // 阈值
				if (!hasDuplicate(window)) {
					++count;
				}
				char outchar = s[left];
				--window[outchar];
				if (window[outchar] == 0) {
					window.erase(outchar);
				}

				++left;
			}

		}
		return count;

	}
	bool hasDuplicate(unordered_map<char, int> window) {
		for (auto&& kv : window) {
			if (kv.second > 1) {
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	string str = "havefunonleetcode";
	int K = 5;
	cout << s.numKLenSubstrNoRepeats(str, K) << endl;

}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

通过添加打印发现了问题:

```C++
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
	int numKLenSubstrNoRepeats(string s, int k) {
		if (s.size() < k) {
			return 0;
		}
		bool duplicate = false;
		int left = 0, right = -1;
		int count = 0;
		unordered_map<char, int> window;
		int len = s.size();
		while (right < len) {
			++right;
			char inchar = s[right];
			++window[inchar];

			if (right - left + 1 == k) { // 阈值
				if (!hasDuplicate(window)) {
					++count;
					cout << "left:" << left << s[left] << "," << right << s[right] << endl;
				}
				char outchar = s[left];
				--window[outchar];
				if (window[outchar] == 0) {
					window.erase(outchar);
				}

				++left;
			}

		}
		return count;

	}
	bool hasDuplicate(unordered_map<char, int> window) {
		for (auto&& kv : window) {
			if (kv.second > 1) {
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	string str = "havefunonleetcode";
	int K = 5;
	cout << s.numKLenSubstrNoRepeats(str, K) << endl;

}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

输出如下:

```
left:0h,4f
left:1a,5u
left:2v,6n
left:3e,7o
left:11e,15d
left:12t,16e
left:13c,17
7
```

可以看到，最后一次循环输出的结果有异常:

```
left:13c,17
```

再看循环变量right，显然，上述写法导致它最终的值等于`len`，显然，上述写法非常有问题的，建议使用`for`循环来替代。

### 第四次: 通过

```C++
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
	int numKLenSubstrNoRepeats(string s, int k) {
		if (s.size() < k) {
			return 0;
		}
		int left = 0;
		int count = 0;
		unordered_map<char, int> window;
		int len = s.size();
		for (int right = 0; right < len;++right) {
			char inchar = s[right];
			++window[inchar];
			if (right - left + 1 == k) { // 阈值
				if (!hasDuplicate(window)) {
					++count;
				}
				char outchar = s[left];
				--window[outchar];
				if (window[outchar] == 0) {
					window.erase(outchar);
				}
				cout << "left:" << left << ",right:" << right << endl;
				++left;

			}
		}
		return count;

	}
	bool hasDuplicate(unordered_map<char, int> window) {
		for (auto&& kv : window) {
			if (kv.second > 1) {
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	string str = "havefunonleetcode";
	int K = 5;
	cout << s.numKLenSubstrNoRepeats(str, K) << endl;

}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```



```C++
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
	int numKLenSubstrNoRepeats(string s, int k) {
		if (s.size() < k) {
			return 0;
		}
		int left = 0;
		int count = 0;
		unordered_map<char, int> window;
		int len = s.size();
		for (int right = 0; right < len;++right) {
			char inchar = s[right];
			++window[inchar];
			if (right - left + 1 == k) { // 阈值
				if (!hasDuplicate(window)) {
					++count;
				}
				char outchar = s[left];
				--window[outchar];
				if (window[outchar] == 0) {
					window.erase(outchar);
				}
				++left;

			}
		}
		return count;

	}
	bool hasDuplicate(unordered_map<char, int> window) {
		for (auto&& kv : window) {
			if (kv.second > 1) {
				return true;
			}
		}
		return false;
	}
};

int main()
{
	Solution s;
	string str = "havefunonleetcode";
	int K = 5;
	cout << s.numKLenSubstrNoRepeats(str, K) << endl;

}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

