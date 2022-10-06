# [LeetCode-625. 最小因式分解](https://leetcode.cn/problems/minimum-factorization/) 中等



## [官方解题 方法三：因式分解](https://leetcode.cn/problems/minimum-factorization/solution/zui-xiao-yin-shi-fen-jie-by-leetcode/)

> NOTE: 
>
> 一、贪心策略:
>
> 低位放大数，高位放小数
>
> 二、需要处理signed overflow，为了避免这种情况，将 数据类型都声明为long
>
> 这种情况的测试用例:
>
> ```
> 27000000
> ```
>
> 

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
	int smallestFactorization(int num) {
		if (num < 9) {
			return num;
		}
		long res = 0;
		long multiple = 1;
		for (long factor = 9; factor >= 2; --factor) {
			while (num % factor == 0) {
				num /= factor;
				if (factor * multiple + res > INT_MAX) {
					return 0;
				}
				else {
					res = factor * multiple + res;
				}
				multiple *= 10;
			}
		}
		if (num == 1) {
			return res;
		}
		else {
			return 0;
		}

	}
};

int main()
{
	Solution s;
	cout << s.smallestFactorization(48) << endl;
	cout << s.smallestFactorization(81) << endl;
	cout << s.smallestFactorization(15) << endl;
	cout << s.smallestFactorization(11) << endl;
	cout << s.smallestFactorization(27000000) << endl;
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

