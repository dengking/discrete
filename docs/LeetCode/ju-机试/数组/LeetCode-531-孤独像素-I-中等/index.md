# [531. 孤独像素 I](https://leetcode.cn/problems/lonely-pixel-i/) 中等

给你一个大小为 m x n 的图像 picture ，图像由黑白像素组成，'B' 表示黑色像素，'W' 表示白色像素，请你统计并返回图像中 黑色 孤独像素的数量。

黑色孤独像素 的定义为：如果黑色像素 'B' 所在的同一行和同一列不存在其他黑色像素，那么这个黑色像素就是黑色孤独像素。

示例 1：

![img](https://assets.leetcode.com/uploads/2020/11/11/pixel1.jpg)

输入：picture = [["W","W","B"],["W","B","W"],["B","W","W"]]
输出：3
解释：全部三个 'B' 都是黑色的孤独像素

示例 2：

![img](https://assets.leetcode.com/uploads/2020/11/11/pixel2.jpg)


输入：picture = [["B","B","B"],["B","B","W"],["B","B","B"]]
输出：0



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
	int findLonelyPixel(vector<vector<char>>& picture) {
		int rowCount = picture.size();
		int colCount = picture[0].size();
		int lonelyCount = 0;
		for (int i = 0; i < rowCount; ++i)
			for (int j = 0; j < colCount; ++j) {
				if (picture[i][j] == 'B') {
					lonelyCount += isLonely(picture, rowCount, colCount, i, j);
				}

			}
		return lonelyCount;
	}
  // 确定所在行、所在列都只有一个W，那么它就是孤独的像素
	int isLonely(vector<vector<char>>& picture, int rowCount, int colCount, int curRow, int curCol) {
		int rowBlackCount = 0;
		for (int i = 0; i < colCount; ++i)
		{
			if (picture[curRow][i] == 'B') {
				++rowBlackCount;
			}
		}
		int colBlackCount = 0;
		for (int i = 0; i < rowCount; ++i)
		{
			if (picture[i][curCol] == 'B') {
				++colBlackCount;
			}
		}
		return rowBlackCount == 1 && colBlackCount == 1;
	}
};

int main()
{

}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

上述是最最简单的暴力解法。



## [官方解题 # 方法二：预处理](https://leetcode.cn/problems/lonely-pixel-i/solution/gu-du-xiang-su-i-by-leetcode-solution/)

对于方法一中检查每个黑色元素是否满足条件我们可以再优化。我们可以发现按上述方法判断，每一行和每一列的黑色像素数量我们都重复统计了，所以我们可以提前预处理出第 ii 行的黑色像素数量 `row[i]`和第 `j` 列的黑色像素数量 `col[j]` ，这样判断一个黑色像素是否满足条件就由原来 `O(n+m)` 时间复杂度降为 `O(1)`，每次只要看一下 `row[i]` 和 `col[j]` 是否都为 1 即可。

> NOTE: 
>
> 典型的以空间换时间

```C++

class Solution {
	int rowBlockCount_[500];
	int colBlockCount_[500];
public:
	int findLonelyPixel(vector<vector<char>>& picture) {
		int rowCount = picture.size();
		int colCount = picture[0].size();
		for (int i = 0; i < rowCount; ++i)
			for (int j = 0; j < colCount; ++j) {
				if (picture[i][j] == 'B') {
					rowBlockCount_[i] += 1;
					colBlockCount_[j] += 1;
				}

			}
		int lonelyCount = 0;
		for (int i = 0; i < rowCount; ++i)
			for (int j = 0; j < colCount; ++j) {
				if (picture[i][j] == 'B') {
					lonelyCount += rowBlockCount_[i] == 1 && colBlockCount_[j] == 1;
				}
			}
		return lonelyCount;
	}
};

```

