# LeetCode [406. 根据身高重建队列](https://leetcode.cn/problems/queue-reconstruction-by-height/)



这道题是在阅读宫水三叶大文章时发现的。最好的讲解是 [Gnakuw](https://leetcode.cn/u/nehzil/) # [【贪心思想「模拟队列插入图解」】](https://leetcode.cn/problems/queue-reconstruction-by-height/solution/by-nehzil-1z3g/)

## [Gnakuw](https://leetcode.cn/u/nehzil/) # [【贪心思想「模拟队列插入图解」】](https://leetcode.cn/problems/queue-reconstruction-by-height/solution/by-nehzil-1z3g/)

**贪心思想：**

因为本题用到了贪心算法所以先来了解一下「贪心算法」的问题需要满足的条件：

1、最优子结构：规模较大的问题的解由规模较小的子问题的解组成，规模较大的问题的解只由其中一个规模较小的子问题的解决定；

2、无后效性：后面阶段的求解不会修改前面阶段已经计算好的结果；

> NOTE: 
>
> 这道题是典型的可以说明无后效性的，因为它后面的插入环节虽然会改编数组中元素的相对位置，但是并不会对数组中已有元素造成破坏

3、贪心选择性质：从局部最优解可以得到全局最优解。

本题其实和分发糖果这道题目有些类似因为是两个维度的问题需要自己去判断和处理看那个纬度适合这道题目，但是可以通过题目给的示例给你一点启发，选择身高降序排列当身高相同时按第二维度的升序排列。然后将排序好的 people 数组 按第二维度去插入到 `result` 中即可下面会有简单的图解插入过程。

**图解举例：**



![9CCA8134-EE8E-4E73-8771-FBE8F47D4C7C_1_201_a.jpeg](https://pic.leetcode.cn/1654443948-FwKdxL-9CCA8134-EE8E-4E73-8771-FBE8F47D4C7C_1_201_a.jpeg)

> NOTE:
>
> 一、选择身高降序排列的原因是: 题目要求 "前面 **正好** 有 `ki` 个身高大于或等于 `hi` 的人"，因此先进入 `result` 中的是大元素，后入的是小元素，后入的可以根据 `result` 中元素的个数来决定插入的位置，因为先入的肯定比它大
>
> 二、通过上述图是能够掌握这个算法的



## 我的解题


```C++
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
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        std::sort(people.begin(), people.end(), [](const vector<int> &left, const vector<int> &right) -> bool
                  {
            if(left[0] == right[0])
            {
                return left[1] < right[1];
            }
            else
            {
                return left[0] > right[0];
            } });
        vector<vector<int>> res;
        res.reserve(people.size());
        for (auto &&p : people)
        {
            res.insert(res.begin() + p[1], p);
        }
        return res;
    }

};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

