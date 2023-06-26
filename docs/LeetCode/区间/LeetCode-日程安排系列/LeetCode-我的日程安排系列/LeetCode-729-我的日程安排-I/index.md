# [LeetCode-729. 我的日程安排表 I](https://leetcode.cn/problems/my-calendar-i/) 

是在阅读宫水三叶 [【线段树专题】求解常见「值域爆炸，查询有限」区间问题的几种方式](https://mp.weixin.qq.com/s/9Y--nNzFgmGfqD5qtB9Hxw) 时发现的这道题。



## 方法一、二分查找

这道题本质上是"insert interval"，插入一个interval，直观的思路就是: 

1、首先找到开始时间大于待插入interval的第一个已经插入的interval

2、然后看前一个interval的结束时间是否大于待插入interval的开始时间

如果上述两者都满足，那么这个interval就和当前的所有interval都不冲突，就是可以插入的。

下面的两个版本都是基于这个思路写的。

### [liuyvjin](https://leetcode.cn/u/liuyvjin/) # [极简二分查找思路，C++](https://leetcode.cn/problems/my-calendar-i/solution/by-liuyvjin-dsho/) 

#### map 版本

> NOTE:
>
> 这道题其实是插入一个range，关键是找到插入位置、能否插入。下面的这种算法使用 `binary_search` 来实现

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

class MyCalendar
{
public:
  map<int, int> cale; // cale[start] = end;
  MyCalendar()
  {
    cale[-1] = -1; // 避免 --it 越界
  }

  bool book(int start, int end)
  {
    // 找到 end 之后的第一个日程, 即满足 start[idx] >= end 的第一个迭代器
    // 当cale中不存在这样的元素的时候，it等于cale.end()，由于下面的if中是这样写的: --it，因此这种写法能够保证总是生效，即使为空
    auto it = cale.lower_bound(end); // 用结束时间和开始时间进行比较
    // 检查前一个日程与当前日程是否重叠,  当end[idx - 1] <= start 时不重叠
    if ((--it)->second <= start) // 用开始时间和结束时间进行比较
    {
      cale[start] = end;
      return true;
    }
    return false;
  }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

#### vector 版本

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
class MyCalendar
{
public:
  vector<int> st, ed;
  MyCalendar()
  {
    // sentinel
    st.push_back(-1); // 避免 idx-1 越界
    ed.push_back(-1);
  }

  bool book(int start, int end)
  {
    // 找到 end 之后的第一个日程, 即满足 start[idx] >= end 的第一个迭代器
    auto it = lower_bound(st.begin(), st.end(), end);
    int idx = it - st.begin();
    // 检查前一个日程与当前日程是否重叠,  当end[idx - 1] <= start 时不重叠
    if (ed[idx - 1] <= start)
    {
      st.insert(it, start);
      ed.insert(ed.begin() + idx, end);
      return true;
    }
    return false;
  }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



## 方法二: sweep-line-algorithm

这种方法是在  [LeetCode-731. 我的日程安排表 II](https://leetcode.cn/problems/my-calendar-ii/) # [Laugh](https://leetcode.cn/u/laughhhh/) # [[ 一法解N题] ✔](https://leetcode.cn/problems/my-calendar-ii/solution/yi-fa-jie-nti-by-laughhhh-pll7/)  中提出的，写法如下：

```c++

class MyCalendar
{
    std::map<int, int> calendar_;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        calendar_[start] += 1;
        calendar_[end] -= 1;
        int concurrent = 0;
        for (auto &&[_, cnt] : calendar_)
        {
            concurrent += cnt;
            if (concurrent > 1)
            {
                calendar_[start] -= 1;
                calendar_[end] += 1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
```

