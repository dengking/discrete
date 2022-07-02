# leetcode [733. 图像渲染](https://leetcode.cn/problems/flood-fill/) 简单



## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
	{
		int oldColor = image[sr][sc]; // 旧颜色
		fill(image, sr, sc, oldColor, newColor);
		return image;
	}
	/**
	 * @brief
	 *
	 * @param image
	 * @param x
	 * @param y
	 * @param newColor
	 */
	void fill(vector<vector<int>> &image, int x, int y, int oldColor, int newColor)
	{
		if (!inArea(image, x, y))
			return;
		if (image[x][y] != oldColor)
			return;
		image[x][y] = -1;
		fill(image, x - 1, y, oldColor, newColor);
		fill(image, x + 1, y, oldColor, newColor);
		fill(image, x, y - 1, oldColor, newColor);
		fill(image, x, y + 1, oldColor, newColor);
		image[x][y] = newColor;
	}
	bool inArea(vector<vector<int>> &image, int x, int y)
	{
		return (x >= 0 && x < image.size()) && (y >= 0 && y < image[0].size());
	}
};
int main()
{
	vector<vector<int>> image { { 1, 1, 1 }, { 1, 1, 0 }, { 1, 0, 1 } };
	Solution s;
	s.floodFill(image, 1, 1, 2);

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

