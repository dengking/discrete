# [LeetCode-170. 两数之和 III - 数据结构设计-简单](https://leetcode.cn/problems/two-sum-iii-data-structure-design/)



无法ac的用例1: 

输入：

```
["TwoSum","add","add","find"]
[[],[0],[0],[0]]
```

输出：

```
[null,null,null,false]
```

预期结果：

```
[null,null,null,true]
```

无法ac的用例2: 

```
["TwoSum","add","find"] 
[[],[0],[0]]
```



```c++
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <set>
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

class TwoSum
{
  std::map<int, int> nums_;

public:
  TwoSum()
  {
  }

  void add(int number)
  {
    nums_[number]++;
  }

  bool find(int value)
  {
    for (auto &&[num, cnt] : nums_) // 从小到大开始枚举第一个数
    {
      long second = (long)value - num;
      if (second > INT_MAX || second < INT_MIN)
      {
        continue;
      }
      if (second == num)
      {
        return cnt >= 2;
      }
      else if (nums_.count(second))
      {
        return true;
      }
      else
      {
        continue;
      }
    }
    return false;
  }
};

// Driver code
int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

