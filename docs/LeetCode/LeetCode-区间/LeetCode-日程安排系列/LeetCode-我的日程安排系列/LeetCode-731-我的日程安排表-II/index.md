# [LeetCode-731. 我的日程安排表 II](https://leetcode.cn/problems/my-calendar-ii/)



## segment tree



### [宫水三叶](https://leetcode.cn/u/ac_oier/) # [【宫水三叶】线段树（动态开点）运用题](https://leetcode.cn/problems/my-calendar-ii/solution/by-ac_oier-okkc/)

线段树维护的节点信息包括：

- `ls/rs`: 分别代表当前节点的左右子节点在**线段树数组** `tr` 中的下标；
- `add`: 懒标记；
- `max`: 为当前区间的最大值。



**动态开点**的优势在于，不需要事前构造空树，而是在插入操作 `update` 和查询操作 `query` 时根据访问需要进行「开点」操作。由于我们不保证查询和插入都是**连续**的，因此对于**父节点** 而言，我们不能通过 `u << 1` 和 `u << 1 | 1` 的固定方式进行访问，而要将节点 的左右节点所在 `tr` 数组的下标进行存储，分别记为 `ls` 和 `rs` 属性。对于$tr[u].ls=0$ 和$tr[u].rs=0$ 则是代表子节点尚未被创建，当需要访问到它们，而又尚未创建的时候，则将其进行创建。



由于存在「懒标记」，**线段树**的插入和查询都是 $logn$ 的，因此我们在单次操作的时候，最多会创建数量级为 $logn$ 的点，因此空间复杂度为$O(mlogn)$ ，而不是 $O(4*n)$，而**开点数**的预估需不能仅仅根据 $logn$来进行，还要对**常数**进行分析，才能得到准确的点数上界。

## sweep-line-algorithm



### [731. 我的日程安排表 II](https://leetcode.cn/problems/my-calendar-ii/) # [Laugh](https://leetcode.cn/u/laughhhh/) # [[ 一法解N题] ✔](https://leetcode.cn/problems/my-calendar-ii/solution/yi-fa-jie-nti-by-laughhhh-pll7/) 



## 我的解题

是按照 [731. 我的日程安排表 II](https://leetcode.cn/problems/my-calendar-ii/) # [Laugh](https://leetcode.cn/u/laughhhh/) # [[ 一法解N题] ✔](https://leetcode.cn/problems/my-calendar-ii/solution/yi-fa-jie-nti-by-laughhhh-pll7/)  中的解法写的。

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

class MyCalendarTwo
{
  std::map<int, int> cale; // 时间戳: 人数
public:
  MyCalendarTwo()
  {
  }

  bool book(int start, int end)
  {
    cale[start]++;
    cale[end]--;
    int cnt = 0;
    for (auto &&p : cale)
    {
      cnt += p.second;
      if (cnt > 2)
      {
        // rollback  
        cale[start]--;
        cale[end]++;
        return false;
      }
    }
    return true;
  }
};

int main()
{
  vector<vector<int>> intervals{{13, 15}, {1, 13}};
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

