# 滑动窗口解子串、子序列问题



## 素材

一、labuladong [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA) 



## 前提条件

使用滑动窗口的前提是: "向右滑动的时候，是寻找一个可行解，向左滑动是优化解"

使用滑动窗口解决连续子数组、连续子串的最值问题的前提是问题需要具备单调性，如果问题不具备单调性，则不能够使用滑动窗口，这在下面的文章中进行了非常好的讨论:

一、labuladong [动态规划套路：最大子数组和](https://mp.weixin.qq.com/s/nrULqCsRsrPKi3Y-nUfnqg) 

二、zhuanlan [经典动态规划：最大子数组问题](https://zhuanlan.zhihu.com/p/144385162)

> NOTE: 
>
> 1、就是最大子序和 

但是，稍加分析就发现，**这道题还不能用滑动窗口算法，因为数组中的数字可以是负数**。

> NOTE: 
>
> 1、如果都是非负数，显然是能够使用滑动窗口算法的，因为它满足了滑动窗口的单调性要求

滑动窗口算法无非就是双指针形成的窗口扫描整个数组/子串，但关键是，你得清楚地知道什么时候应该移动右侧指针来扩大窗口，什么时候移动左侧指针来减小窗口。

而对于这道题目，你想想，当窗口扩大的时候可能遇到负数，窗口中的值也就可能增加也可能减少，这种情况下不知道什么时机去收缩左侧窗口，也就无法求出「最大子数组和」。

三、leetcode [560. 和为 K 的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

这个问题就是典型的不能够使用滑动窗口的

## 问题分类

这类问题有多种分类方式：

### 一、窗口是否定长？

参见`定长滑动窗口`章节。

### 二、连续还是不连续？



### 三、

1、存在性问题

2、计数问题

3、最优值问题



## 窗口表示与比较

一、目标值和窗口的比较这是滑动窗口算法的一个common issue

一般，将目标值称为`need`，将窗口称之为`window`。

二、使用lambda来表示窗口的比较

比如 Leetcode [1100. 长度为 K 的无重复字符子串](https://leetcode-cn.com/problems/find-k-length-substrings-with-no-repeated-characters/) 

### 窗口的表示

一、对于字符串相关的问题

1、Leetcode [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/) # [官方解题](https://leetcode-cn.com/problems/permutation-in-string/solution/zi-fu-chuan-de-pai-lie-by-leetcode-solut-7k7u/)

```c++
vector<int> cnt1(26), cnt2(26);
for (int i = 0; i < n; ++i) {
  ++cnt1[s1[i] - 'a'];
  ++cnt2[s2[i] - 'a'];
}
if (need == window)
  return true;
```

上述直接使用vector来表示need和window。

2、Leetcode [1100. 长度为 K 的无重复字符子串](https://leetcode-cn.com/problems/find-k-length-substrings-with-no-repeated-characters/)

```c++
    unordered_map<char, int> window;
    for (int i = 0; i < k; ++i)
    {
      ++window[s[i]];
    }
    auto isNotRepeat = [&]() -> bool
    {
      for (auto &&item : window)
      {
        if (item.second > 1)
        {
          return false;
        }
      }
      return true;
    };
```



## 子串、子数组 LeetCode例题

素材:

1、LeetCode [1004. 最大连续1的个数 III](https://leetcode.cn/problems/max-consecutive-ones-iii/) # [一个模板解决最大滑动窗口问题（同类型题目收集）](https://leetcode.cn/problems/max-consecutive-ones-iii/solution/jidao-by-iamysw-bs2s/)



### 习题分类

一、简单:

1、LeetCode [剑指 Offer 57 - II. 和为s的连续正数序列](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) 

最好的滑动窗口例题

二、修改K次

LeetCode [1004. 最大连续1的个数 III](https://leetcode.cn/problems/max-consecutive-ones-iii/) 中等

LeetCode [424. 替换后的最长重复字符](https://leetcode.cn/problems/longest-repeating-character-replacement/) 中等

LeetCode [1493. 删掉一个元素以后全为 1 的最长子数组](https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/) 

K为1



### LeetCode [剑指 Offer 57 - II. 和为s的连续正数序列](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) 简单

穷举: "输出所有和为 `target` 的连续正整数序列（至少含有两个数）"

```c++

class Solution
{
public:
  vector<vector<int>> findContinuousSequence(int target)
  {
    vector<vector<int>> res;
    vector<int> v;
    for (int l = 1, r = 2; l < r;)
    {
      int sum = (l + r) * (r - l + 1) / 2;
      if (sum == target)
      {
        v.clear();
        for (int i = l; i <= r; ++i)
        {
          v.push_back(i);
        }
        res.push_back(v);
        ++l; // 此处千万不要忘记
      }
      else if (sum < target)
      {
        ++r;
      }
      else
      {
        ++l;
      }
    }
    return res;
  }
};


```



### LeetCode [3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) 中等

最优值: 寻找 "不含有重复字符的 **最长子串** 的长度"

```C++
#include <iostream>
#include <string>
#include <unordered_map>
#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <variant>
#include <typeinfo>
#include <limits>

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        std::unordered_map<char, int> window;
        using pair_type = decltype(window)::value_type;
        // https://stackoverflow.com/a/9371137/10173843
        auto has_repeat = [&]() -> bool
        {
            return std::any_of(window.begin(), window.end(), [](const pair_type &left)
                               { return left.second > 1; });
        };
        int ret = 0;
        int len = s.size();
        for (int left = 0, right = 0; right < len; ++right)
        {
            window[s[right]]++;
            // int window_size = right - left + 1;
            while (has_repeat())
            {
                window[s[left++]]--;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};

int main()
{
    auto s = "abcabcbb";
    Solution solu;
    solu.lengthOfLongestSubstring(s);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



### LeetCode [76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/) 困难



### LeetCode [424. 替换后的最长重复字符](https://leetcode.cn/problems/longest-repeating-character-replacement/) 中等

修改K次: 最多翻转K次，"返回包含相同字母的最长子字符串的长度"。

```C++

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        std::unordered_map<char, int> cnt;
        using pair_type = decltype(cnt)::value_type;
        // https://stackoverflow.com/a/9371137/10173843
        auto max_of_cnt_func = [&]() -> int
        {
            return std::max_element(cnt.begin(), cnt.end(), [](const pair_type &left, const pair_type &right)
                                    { return left.second < right.second; })
                ->second;
        };
        int ret = 0;
        int len = s.size();
        for (int left = 0, right = 0; right < len; ++right)
        {
            cnt[s[right]]++;
            // int window_size = right - left + 1;
            while (right - left + 1 - max_of_cnt_func() > k)
            {
                cnt[s[left++]]--;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};
```

上述code非常简介，是典型的模板。

### LeetCode [438. 找到字符串中所有字母异位词](https://leetcode.cn/problems/find-all-anagrams-in-a-string/) 中等





### LeetCode [567. 字符串的排列](https://leetcode.cn/problems/permutation-in-string/) 中等





### LeetCode [1004. 最大连续1的个数 III](https://leetcode.cn/problems/max-consecutive-ones-iii/) 中等

修改K次: "「找出一个最长的子数组，该子数组内最多允许有 K 个 0 」"

```c++
class Solution
{
public:
  int longestOnes(vector<int> &A, int K)
  {
    int res = 0,   // 结果
        zeros = 0, // 区间中0的个数
        left = 0;
    for (int right = 0; right < A.size(); ++right) //将元素移入区间
    {
      if (A[right] == 0)
      {
        ++zeros;
      }
      while (zeros > K) // 这个while循环一定要放在后面的打擂台择优之前，它保证窗口内最多有K个0
      {
        if (A[left++] == 0) // 需要注意的是: A[left++] 相对于 A[left]; left = left + 1
        {                   // 它相当于将A[left]移出区间，显然之后left就需要自增1
          --zeros;
        }
      }
      res = max(res, right - left + 1); // 打擂台择优
    }
    return res;
  }
};


```



### LeetCode [1493. 删掉一个元素以后全为 1 的最长子数组](https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/) 



```C++

class Solution
{
public:
  /**
   * @brief 窗口中，最多K个0
   *
   * @param nums
   * @return int
   */
  int longestSubarray(vector<int> &nums)
  {
    int zeroCnt = 0; // 窗口中0的个数
    int res = 0;
    for (int fast = 0, slow = 0; fast < nums.size(); ++fast)
    {
      if (nums[fast] == 0)
      {
        ++zeroCnt;
      }
      while (zeroCnt > 1)
      {
        if (nums[slow++] == 0)
        {
          --zeroCnt;
        }
      }
      res = max(res, fast - slow); //由于必须要从窗口中删除掉一个元素，因此长度的计算方式为: fast - slow
    }
    return res;
  }
};

```





### LeetCode [1839. 所有元音按顺序排布的最长子字符串](https://leetcode.cn/problems/longest-substring-of-all-vowels-in-order/) 中等

