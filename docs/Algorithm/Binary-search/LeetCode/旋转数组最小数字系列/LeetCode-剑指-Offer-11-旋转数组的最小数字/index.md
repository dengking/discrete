# leetcode [剑指 Offer 11. 旋转数组的最小数字](https://leetcode.cn/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/)



## `O(N)` 解法

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
  int minArray(vector<int> &numbers)
  {
    int i = 0;
    while (i + 1 <= numbers.size() - 1) //避免越界
    {
      if (numbers[i] > numbers[i + 1])
      {
        return numbers[i + 1];
      }
      ++i;
    }
    return numbers[0]; //运行到这里，说明是单调递增到，因此最小的元素就是第0个
  }
};

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



## `O(logN)` 解法



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
  int minArray(vector<int> &numbers)
  {
    int left = 0, right = numbers.size() - 1;
    int pivot = numbers.back();
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (numbers[mid] == pivot)
      {
        return pivot;
      }
      else if (numbers[mid] > pivot)
      {
        left = mid + 1;
      }
      else
      {
        right = mid;
        pivot = numbers[mid];
      }
    }
    return pivot;
  }
};

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

上述程序在如下用例无法通过:

输入：

```
[1,3,3]
```



输出：

```
3
```



预期结果：

```
1
```



原因在于如下代码:

```c++
      int mid = left + (right - left) / 2;
      if (numbers[mid] == pivot)
      {
        return pivot;
      }
```



