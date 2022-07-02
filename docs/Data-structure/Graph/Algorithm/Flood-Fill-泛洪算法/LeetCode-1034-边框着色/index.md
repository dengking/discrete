# leetcode [1034. 边框着色](https://leetcode.cn/problems/coloring-a-border/)



## 我的解题

我是按照 labuladong [Flood Fill 算法详解](https://mp.weixin.qq.com/s/Y7snQIraCC6PRhj9ZSnlzw)  中，给出的解题思路写的。

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	vector<vector<int>> colorBorder(vector<vector<int>> &grid, int r0, int c0, int color)
	{
		vector<vector<bool>> visited { grid.size() };
		for (auto &&v : visited)
		{
			v = vector<bool>(grid[0].size(), false);
		}
		int oldColor = grid[r0][c0]; // 旧颜色
		fill(grid, r0, c0, oldColor, color, visited);
		return grid;
	}
	/**
	 * @brief
	 *
	 * @param image
	 * @param x
	 * @param y
	 * @param newColor
	 */
	int fill(vector<vector<int>> &image, int x, int y, int oldColor, int newColor, vector<vector<bool>> &visited)
	{
		if (!inArea(image, x, y))
			return 0;
		if (visited[x][y]) // 必须要先判断`visited[x][y]`，然后判断`image[x][y] != oldColor`
			return 1;
		if (image[x][y] != oldColor)
			return 0;

		visited[x][y] = true;
		int surround = fill(image, x - 1, y, oldColor, newColor, visited) + fill(image, x + 1, y, oldColor, newColor, visited) + fill(image, x, y - 1, oldColor, newColor, visited) + fill(image, x, y + 1, oldColor, newColor, visited);
		if (surround < 4)
		{
			image[x][y] = newColor;
		}
		return 1;
	}
	bool inArea(vector<vector<int>> &image, int x, int y)
	{
		return (x >= 0 && x < image.size()) && (y >= 0 && y < image[0].size());
	}
};
int main()
{
	vector<vector<int>> image { { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } };
	Solution s;
	s.colorBorder(image, 1, 1, 2);

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

