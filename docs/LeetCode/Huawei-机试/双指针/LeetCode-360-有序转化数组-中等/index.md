# [360. 有序转化数组](https://leetcode-cn.com/problems/sort-transformed-array/) 中等



## 我的解题



其实题目已经非常明显地提示用由两端到中间的双指针了：

一、`a != 0`，则是抛物线，

这道题需要有高中数学知识， `f(x)`是典型的抛物线函数，它的对称轴是 (`2 * a / b`)，因此最终结果，由跟对称轴的距离远近决定。

1、如果`a`大于0，则越近越小，则数组外侧的元素的值更大，当使用双指针从外侧向内侧靠近的时候，显然数组填值的顺序是从n到0

2、如果`a`小于0，则越远越小，则数组外侧的元素的值更小，当使用双指针从外侧向内侧靠近的时候，显然数组填值的顺序是从0到n

对于抛物线对称轴和数组元素的大小关系，其实有三种情况：

1、对称轴位于数组元素左侧

2、对称轴位于数组元素中

3、对称轴位于数组右侧

对于上述三种情况，双指针都能够cover掉，从这也可以看出双指针都优势，它非常灵活。

二、`a == 0`，则是直线

对于直线由于它是单调的，因此双指针分别指向最大值和最小值

```c++
#include <iostream>
#include <vector>
#include <queue>
#include <utility> // std::pair
#include <unordered_map>
#include <string>
#include <set>
#include <map>
#include <climits> // INT_MAX
using namespace std;

class Solution
{
public:
  vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c)
  {
    if (nums.empty())
    {
      return {};
    }
    int N = nums.size();
    vector<int> res(N);
    int left = 0, right = N - 1;
    int index = 0;
    int index_move = 0;
    if (a > 0)
    {
      index = right;
      index_move = -1;
    }
    else
    {
      index = left;
      index_move = 1;
    }

    auto fx = [&](const auto &x)
    {
      return a * x * x + b * x + c;
    };
    while (left <= right)
    {
      int left_val = fx(nums[left]);
      int right_val = fx(nums[right]);
      if (a > 0)
      {
        res[index--] = max(left_val, right_val);
        left_val > right_val ? ++left : --right;
      }
      else
      {
        res[index++] = min(left_val, right_val);
        left_val < right_val ? ++left : --right;
      }
    }
    return res;
  }
};

int main()
{
  Solution s;
}

```



## [卖码翁](https://leetcode-cn.com/u/jyj407/) [【中规中矩】又是面试官装B的一题（两种解法）](https://leetcode-cn.com/problems/sort-transformed-array/solution/zhong-gui-zhong-ju-you-shi-mian-shi-guan-awen/)

解法1：先计算再暴力排序

解法2：**双指针**从两头开始计算，保存两端值较小的一个到结果。

利用高中数学**抛物线**性质:

1、`a>0`，向上的抛物线，两端大中间小，从后往前存储结算结果。

2、`a<0`，向下的抛物线，两端小中间大，从前往后存储结算结果。

3、`a=0`的情况时直线，单调增加或减少（取决于b的正负）。直接跟a>0或者a<0合并即可。

```C++
/ O(NlgN)
class Solution1 {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        vector<int> res;
        for (const auto& x : nums) {
            int t = a * x * x + b * x + c;
            res.push_back(t);
        }

        sort(res.begin(), res.end());

        return res;
    }
};

// O(N)
class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (nums.empty()) {
            return {};
        }

        int N = nums.size();
        vector<int> res(N, 0);
        auto fx = [&](const auto& x) {
            return a * x * x + b * x + c;
        };

        int i = 0;
        int j = N - 1;
        int index = a >= 0 ? N - 1 : 0; // a > 0, backward, a < 0, forward
        while (i <= j) {
            if (a >= 0) { //向上的抛物线,合并a=0为直线，单调增减情况到a>0（合并到a < 0也行）
                res[index--] = fx(nums[i]) >= fx(nums[j]) ? fx(nums[i++]) : fx(nums[j--]); // 取大值
            } else { // (a < 0)
                res[index++] = fx(nums[i]) > fx(nums[j]) ? fx(nums[j--]) : fx(nums[i++]); // 取小值
            }
        }
        return res;
    }
};

```

> NOTE: 
>
> 上述基于双指针的写法是非常统一的，因为它cover了多种情况: 
>
> 一、函数`f(x)`是直线
>
> 二、函数`f(x)`是抛物线
>
> 1、数组的元素位于两侧，即非单调
>
> 2、数组的元素位于一侧，单调的
>
> 对于上面的情况，它都能够实现`O(N)`算法，由此可见双指针的灵活。



