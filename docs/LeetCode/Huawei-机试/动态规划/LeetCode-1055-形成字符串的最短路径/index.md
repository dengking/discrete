# LeetCode [1055. 形成字符串的最短路径](https://leetcode-cn.com/problems/shortest-way-to-form-string/) 中等

## [【C++】逐步优化 双指针 / 多指针 / 二分查找 / 动态规划](https://leetcode-cn.com/problems/shortest-way-to-form-string/solution/c-zhu-bu-you-hua-shuang-zhi-zhen-duo-zhi-1hvh/)

### 方法一：双指针

> NOTE: 
>
> 能匹配多少就匹配多少



## [简单的dp思路](https://leetcode-cn.com/problems/shortest-way-to-form-string/solution/jian-dan-de-dpsi-lu-by-djc33636822-ltcn/)



## [【python3】双指针](https://leetcode-cn.com/problems/shortest-way-to-form-string/solution/python3-shuang-zhi-zhen-by-caiji-ud-mlbx/)

> NOTE: 
>
> 这种思路是最简单的，所谓的子序列，只需要不断地进行匹配即可



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
	int shortestWay(string source, string target) {
		int res = 0;
		int targetIndex = 0;
		while (targetIndex < target.size()) {
			int sourceIndex = 0;
			int pre = targetIndex;
			while (targetIndex < target.size() && sourceIndex < source.size()) { // 贪心算法，在source中进行尽可能的匹配
				if (target[targetIndex] == source[sourceIndex]) // 匹配成功了
				{
					targetIndex += 1;
				}
				sourceIndex += 1;
			}
			if (pre == targetIndex) {
				return -1;
			}
			res += 1;
		}
		return res;
	}
};


int main()
{
	Solution s;

}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

