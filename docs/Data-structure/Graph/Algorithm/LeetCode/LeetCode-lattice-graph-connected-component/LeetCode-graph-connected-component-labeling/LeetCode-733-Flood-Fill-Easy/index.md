# [LeetCode-733. 图像渲染-简单](https://leetcode.cn/problems/flood-fill/) 

英文原题: [LeetCode-733. Flood Fill](https://leetcode.com/problems/flood-fill/) 

## DFS+backtrack

1、参考 labuladong [Flood Fill 算法详解](https://mp.weixin.qq.com/s/Y7snQIraCC6PRhj9ZSnlzw) 

这种写法的一个trick: 使用backtrack替换来visited array，这种写法非常值得借鉴。



2、通过原色是否相同来判断能否形成connected component



```C++
#include <vector>

using namespace std;

class Solution {
public:
    vector <vector<int>> floodFill(vector <vector<int>> &image, int sr, int sc, int newColor) {
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
    void fill(vector <vector<int>> &image, int x, int y, int oldColor, int newColor) {
        if (!inArea(image, x, y)) {
            return;
        }
        if (image[x][y] != oldColor) { // 颜色不同，不是connected component
            return;
        }
        if (image[x][y] == -1) { // 已经visited了
            return;
        }
        image[x][y] = -1; // pre action
        fill(image, x - 1, y, oldColor, newColor);
        fill(image, x + 1, y, oldColor, newColor);
        fill(image, x, y - 1, oldColor, newColor);
        fill(image, x, y + 1, oldColor, newColor);
        image[x][y] = newColor; // post action
    }

    bool inArea(vector <vector<int>> &image, int x, int y) {
        return (x >= 0 && x < image.size()) && (y >= 0 && y < image[0].size());
    }
};

int main() {
    vector <vector<int>> image{{1, 1, 1},
                               {1, 1, 0},
                               {1, 0, 1}};
    Solution s;
    s.floodFill(image, 1, 1, 2);

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```



## [LeetCode-面试题 08.10. 颜色填充](https://leetcode.cn/problems/color-fill-lcci/)



### 我的解题

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
	vector<vector<int>> image { { 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 } };
	Solution s;
	s.floodFill(image, 1, 1, 2);

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

