# [LeetCode-485. 最大连续 1 的个数](https://leetcode.cn/problems/max-consecutive-ones/)

## 我的解题



```c++
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		int count = nums[0] == 1 ? 1 : 0;
		int res = count;
		int N = nums.size();
		for (int i = 1; i < N; ++i) {
			if (nums[i] == 1) {
				++count;
				res = count > res ? count : res;
			}
			else {
				count = 0;
			}
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

