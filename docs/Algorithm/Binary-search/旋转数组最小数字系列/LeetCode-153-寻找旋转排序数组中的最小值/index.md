# leetcode [153. 寻找旋转排序数组中的最小值](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/)



## 我的解题

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
  int findMin(vector<int> &nums)
  {
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
      int mid = left + (right - left) / 2;
      if (nums[mid] < nums[right])
      {
        right = mid;
      }
      else if (nums[mid] > nums[right])
      {
        left = mid + 1;
      }
      else // 由于题目限制数组各个元素互不相同，因此nums[mid] == nums[right] 的唯一情况是 left == right，也就是它们指向同一个元素
      {
        break;
      }
    }
    return nums[left];
  }
};

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

