# leetcode [509. 斐波那契数](https://leetcode-cn.com/problems/fibonacci-number/)



## 我的解题

```c++
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
  int fib(int n)
  {
    if (n <= 1)
    {
      return n;
    }
    int prev = 1, prev_prev = 0, cur = 0;
    for (int i = 2; i <= n; ++i)
    {
      cur = prev + prev_prev;
      prev_prev = prev;
      prev = cur;
    }
    return cur;
  }
};

int main()
{
}
```

