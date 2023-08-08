# [LeetCode-1893. 检查是否区域内所有整数都被覆盖-简单](https://leetcode.cn/problems/check-if-all-the-integers-in-a-range-are-covered/) 



## 一刷

```c++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

class Solution
{
public:
  bool isCovered(vector<vector<int>> &ranges, int left, int right)
  {
    std::sort(ranges.begin(), ranges.end(), [](const vector<int> &left, const vector<int> &right)
              { return left[0] < right[0]; }); // 进行排序
    int start = left;
    // 两个区间之间三种关系
    for (auto &&range : ranges)
    {
      if (left < range[0]) // [left, right] 位于 range的左边，显然不相交
      {                    // 只有部分相交
        return false;
      }
      else if (right <= range[1]) // 被区间覆盖
      {
        return true;
      }
      else
      {
        left = range[1] + 1;
      }
    }
    return false;
  }
};

int main()
{
  vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int K = 2;
  Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



在下面的用例无法通过:

```
[[13,43],[19,20],[32,38],[26,33],[3,38],[16,31],[26,48],[27,43],[12,24]]
36
45
```



反思: 上述算法假定 `ranges` 中的各个range是不相交的，因此可能导致如下判定失误:

```c++
      if (left < range[0]) // [left, right] 位于 range的左边，显然不相交
      {                    // 只有部分相交
        return false;
      }
```



因此为的第一想法就是对于相交区间进行特殊的处理。



## 二刷

```c++ 
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

class Solution
{
public:
  bool isCovered(vector<vector<int>> &ranges, int left, int right)
  {
    std::sort(ranges.begin(), ranges.end(), [](const vector<int> &left, const vector<int> &right)
              { return left[0] < right[0]; }); // 进行排序
    int start = 0;
    int stop = 0;
    // 两个区间之间三种关系
    for (auto &&range : ranges)
    {
      if (range[1] <= stop) // 当前range被上一个range包含
      {
        continue;
      }
      else if (range[0] <= stop) // 当前range和上一个range相交
      {
        start = stop + 1;
        stop = range[1];
      }
      else
      {
        start = range[0];
        stop = range[1];
      }

      if (left < start) // [left, right] 位于 range的左边，显然不相交
      {                 // 只有部分相交
        return false;
      }
      else if (right <= stop) // 被区间覆盖
      {
        return true;
      }
      else
      {
        left = stop + 1;
      }
    }
    return false;
  }
};

int main()
{
  vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
  int K = 2;
  Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



在下面的用例无法通过:

```c++
[[3,3],[1,1]]
3
3
```

## 三刷

```c++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

class Solution
{
public:
  bool isCovered(vector<vector<int>> &ranges, int left, int right)
  {
    std::sort(ranges.begin(), ranges.end(), [](const vector<int> &left, const vector<int> &right)
              { return left[0] < right[0]; }); // 进行排序
    int start = 0;
    int stop = 0;
    // 两个区间之间三种关系
    for (auto &&range : ranges)
    {
      if (range[1] <= stop) // 当前range被上一个range包含
      {
        continue;
      }
      else if (range[0] <= stop) // 当前range和上一个range相交
      {
        start = stop + 1;
        stop = range[1];
      }
      else
      {
        start = range[0];
        stop = range[1];
      }

      if (left < start) // [left, right] 位于 range的左边，显然不相交
      {                 // 只有部分相交
        return false;
      }
      else if (right <= stop) // 被区间覆盖
      {
        return true;
      }
      else if (left > stop) // 在区间右侧
      {
        continue;
      }
      else
      {
        left = stop + 1;
      }
    }
    return false;
  }
};

int main()
{
  vector<vector<int>> ranges{{3, 3}, {1, 1}};
  int left = 3, right = 3;
  Solution s;
  s.isCovered(ranges, left, right);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

