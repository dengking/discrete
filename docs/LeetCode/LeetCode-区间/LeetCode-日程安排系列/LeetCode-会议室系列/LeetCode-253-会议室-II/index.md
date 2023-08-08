# [LeetCode-253. 会议室 II](https://leetcode.cn/problems/meeting-rooms-ii/) 

下面三篇描述的其实是同一种解法：

一、[loick](https://leetcode.cn/u/loick/) # [统计同时进行的会议](https://leetcode.cn/problems/meeting-rooms-ii/solution/tong-ji-tong-shi-jin-xing-de-hui-yi-by-loick/)

二、[muluo](https://leetcode.cn/u/muluo-2/) # [图解转化为上下车问题 O(nlogn)](https://leetcode.cn/problems/meeting-rooms-ii/solution/tu-jie-zhuan-hua-wei-shang-xia-che-wen-t-uy2q/) 

三、[官方解题](https://leetcode.cn/problems/meeting-rooms-ii/solution/hui-yi-shi-ii-by-leetcode/) # 方法二：有序化



## `std::vector`



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
  int minMeetingRooms(vector<vector<int>> &intervals)
  {
    std::vector<std::pair<int, int>> meetings;
    for (auto &&i : intervals)
    {
      meetings.emplace_back(i[0], 1);
      meetings.emplace_back(i[1], -1);
    }
    std::sort(meetings.begin(), meetings.end(), [](const std::pair<int, int> &left, const std::pair<int, int> &right)
              {
                if (left.first == right.first) 
                {
                  return left.second < right.second;// 先离开后进入，因此离开要排在进入前面
                }
                else
                {
                  return left.first < right.first;
                } } //
    );
    int cnt = 0, max_cnt = 0;
    for (auto &&m : meetings)
    {
      cnt += m.second;
      max_cnt = max(max_cnt, cnt);
    }
    return max_cnt;
  }
};

int main()
{
  vector<vector<int>> intervals{{13, 15}, {1, 13}};
  Solution s;
  s.minMeetingRooms(intervals);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

第一次提交的时候，在如下用例无法通过:

```
[[13,15],[1,13]]
```

后来发现，在相同的时间点，必须要先离开，然后才能够进入。



[muluo](https://leetcode.cn/u/muluo-2/) # [图解转化为上下车问题 O(nlogn)](https://leetcode.cn/problems/meeting-rooms-ii/solution/tu-jie-zhuan-hua-wei-shang-xia-che-wen-t-uy2q/)  的代码更加简洁:

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
  int minMeetingRooms(vector<vector<int>> &intervals)
  {

    if (intervals.size() == 0)
      return 0;

    vector<pair<int, int>> meetings;
    for (const vector<int> &interval : intervals)
    {
      meetings.push_back({interval[0], 1});
      meetings.push_back({interval[1], -1});
    }
    sort(meetings.begin(), meetings.end());

    int cnt = 0, maxValue = 0;
    for (const pair<int, int> &meeting : meetings)
    {
      cnt += meeting.second;
      maxValue = max(maxValue, cnt);
    }
    return maxValue;
  }
};

int main()
{
  vector<vector<int>> intervals{{13, 15}, {1, 13}};
  Solution s;
  s.minMeetingRooms(intervals);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



## `std::map`

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
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 0)
            return 0;

        std::map<int, int> meetings;
        for (const vector<int> &interval : intervals)
        {
            meetings[interval[0]] += 1;
            meetings[interval[1]] -= 1;
        }

        int cnt = 0, maxValue = 0;
        for (auto &&meeting : meetings)
        {
            cnt += meeting.second;
            maxValue = max(maxValue, cnt);
        }
        return maxValue;
    }
};

int main()
{
    vector<vector<int>> intervals{{13, 15}, {1, 13}};
    Solution s;
    s.minMeetingRooms(intervals);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

