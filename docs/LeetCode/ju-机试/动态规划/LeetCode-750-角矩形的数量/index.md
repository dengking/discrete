# LeetCode [750. 角矩形的数量](https://leetcode-cn.com/problems/number-of-corner-rectangles/) 中等

给定一个只包含 `0` 和 `1` 的 `m x n` 整数矩阵 `grid` ，返回 *其中 「**角矩形 」**的数量* 。

一个**「角矩形」**是由四个不同的在矩阵上的 `1` 形成的轴对称的矩形。注意只有角的位置才需要为 `1`。

**注意：**4 个 `1` 的位置需要是不同的。

**示例 1：**

![img](https://assets.leetcode.com/uploads/2021/06/12/cornerrec1-grid.jpg)

```
输入：grid = [[1,0,0,1,0],[0,0,1,0,1],[0,0,0,1,0],[1,0,1,0,1]]
输出：1
解释：只有一个角矩形，角的位置为 grid[1][2], grid[1][4], grid[3][2], grid[3][4]。
```

**示例 2：**

![img](https://assets.leetcode.com/uploads/2021/06/12/cornerrec2-grid.jpg)

```
输入：grid = [[1,1,1],[1,1,1],[1,1,1]]
输出：9
解释：这里有 4 个 2x2 的矩形，4 个 2x3 和 3x2 的矩形和 1 个 3x3 的矩形。
```

**示例 3：**

![img](https://assets.leetcode.com/uploads/2021/06/12/cornerrec3-grid.jpg)

```
输入：grid = [[1,1,1,1]]
输出：0
解释：矩形必须有 4 个不同的角。
```

## [盛夏与微风](https://leetcode-cn.com/u/mmmmmjcy/) # [Java](https://leetcode-cn.com/problems/number-of-corner-rectangles/solution/java-by-zxy0917-16/)

> NOTE:
>
> 在 [【恰当的遍历方式可以带来优化】【C++】](https://leetcode-cn.com/problems/number-of-corner-rectangles/solution/qia-dang-de-bian-li-fang-shi-ke-yi-dai-l-svse/) 中也是使用的这种方法。

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>

using namespace std;

class Solution
{
public:
  int countCornerRectangles(vector<vector<int>> &grid)
  {
    int row_count = grid.size();
    int col_count = grid[0].size();

    int res = 0;
    if (row_count == 1)
    {
      return res;
    }
    for (int row1 = 0; row1 < row_count; ++row1)
    {
      for (int row2 = row1 + 1; row2 < row_count; ++row2)
      {
        int count = 0;
        for (int col = 0; col < col_count; ++col)
        {
          if (grid[row1][col] == 1 && grid[row2][col] == 1)
          {
            ++count;
          }
        }
        res += count * (count - 1) / 2;
      }
    }
    return res;
  }
};

int main()
{
}
```



## [peteyuan](https://leetcode-cn.com/u/peteyuan/) # [C++ 动态规划](https://leetcode-cn.com/problems/number-of-corner-rectangles/solution/c-dong-tai-gui-hua-by-peteyuan/)



## cnblogs [[LeetCode] Number Of Corner Rectangles 边角矩形的数量](https://www.cnblogs.com/grandyang/p/8433813.html)