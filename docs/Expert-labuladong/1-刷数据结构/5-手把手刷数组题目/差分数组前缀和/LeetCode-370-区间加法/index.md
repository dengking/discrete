# LeetCode [370. 区间加法](https://leetcode-cn.com/problems/range-addition/) 中等

假设你有一个长度为 `n` 的数组，初始情况下所有的数字均为 0，你将会被给出 `k` 个更新的操作。

其中，每个操作会被表示为一个三元组：`[startIndex, endIndex, inc]`，你需要将子数组 `A[startIndex ... endIndex]`（包括 `startIndex` 和 `endIndex`）增加 `inc`。

请你返回 `k` 次操作后的数组。

示例:

输入: length = 5, updates = [[1,3,2],[2,4,3],[0,2,-2]]
输出: [-2,0,3,5,3]
解释:

初始状态:
[0,0,0,0,0]

进行了操作 [1,3,2] 后的状态:
[0,2,2,2,0]

进行了操作 [2,4,3] 后的状态:
[0,2,5,5,3]

进行了操作 [0,2,-2] 后的状态:
[-2,0,3,5,3]



## 我的解题

```C++
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Solution {
public:
	vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
		vector<int> arr(length);
		for (auto&& update : updates) {
			updateImpl(arr, update);
		}
		return arr;
	}
	void updateImpl(vector<int>& arr, vector<int>& update) {
		for (int i = update[0]; i <= update[1]; ++i) {
			arr[i] += update[2];
		}
	}
};
int main()
{
	
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

在下面的测试用例中超时了:

```
60000
[[1,59999,2], [1,59999,2], ......]
```

## [官方解题](https://leetcode-cn.com/problems/range-addition/solution/qu-jian-jia-fa-by-leetcode/)

### 方法 1：简单的暴力

```C++
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Solution {
public:
	vector<int> getModifiedArray(int length, vector<vector<int> > updates)
	{
		vector<int> result(length, 0);

		for (auto& tuple : updates) {
			int start = tuple[0], end = tuple[1], val = tuple[2];

			for (int i = start; i <= end; i++) {
				result[i] += val;
			}
		}

		return result;
	}

};
int main()
{

}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

> NOTE: 
>
> 和我第一次的写法一样，会超时

### 方法 2： 区间求和

> NOTE: 
>
> 一、其实就是差分数组，关于分析，我觉得 labuladong [论那些小而美的算法技巧：差分数组/前缀和](https://mp.weixin.qq.com/s/9L6lz0XDZ9gi-d_iPrSs8Q) 讲解得不错
>
> 二、官方解题 [区间加法](https://leetcode-cn.com/problems/range-addition/solution/qu-jian-jia-fa-by-leetcode-solution/) 中讲解的也是差分数组



```C++
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
	vector<int> getModifiedArray(int length, vector<vector<int> > updates)
	{
		vector<int> diffArray(length, 0); // 差分数组

		for (auto& tuple : updates) {
			int start = tuple[0], end = tuple[1], val = tuple[2];
			diffArray[start] += val;
			if (end + 1 < length) {
				diffArray[end + 1] -= val;
			}
		}

		for (int i = 1; i < length; ++i)
			diffArray[i] += diffArray[i - 1];
		return diffArray;
	}

};


int main()
{

}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

