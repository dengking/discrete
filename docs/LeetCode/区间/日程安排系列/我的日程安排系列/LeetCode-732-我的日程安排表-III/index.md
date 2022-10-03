# [LeetCode-732. 我的日程安排表 III](https://leetcode.cn/problems/my-calendar-iii/) 困难



这道题和 [LeetCode-253. 会议室 II](https://leetcode.cn/problems/meeting-rooms-ii/) 一模一样。



## sweep-line-algorithm



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

class MyCalendarThree
{
  std::map<int, int> cale; // 时间戳:人数
public:
  MyCalendarThree()
  {
  }
  /**
   * @brief 返回我的交集个数
   *
   * @param start
   * @param end
   * @return int
   */
  int book(int start, int end)
  {
    cale[start]++;
    cale[end]--;
    int cnt = 0, max_cnt = 0;
    for (auto &&p : cale)
    {
      cnt += p.second;
      max_cnt = max(max_cnt, cnt);
    }
    return max_cnt;
  }
};

int main()
{
  vector<vector<int>> intervals{{13, 15}, {1, 13}};
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

