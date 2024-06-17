# Sliding window



## 素材

一. labuladong 

- [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA) 

- [滑动窗口算法解决子串问题](https://mp.weixin.qq.com/s/nJHIxQ2BbqhDv5jZ9NgXrQ)
- [单调队列解决滑动窗口问题](https://mp.weixin.qq.com/s/GqehrBu9m7qf5FgFqlV-Uw)



## Algo framework



```python


def sliding_window(s: str, t: str):
    """
    滑动窗口算法框架
    在 s 中搜索 t
    :param s: 从s中搜索t
    :param t: 目标
    :return:
    """

    def is_window_needs_shrink(win: Dict[str, int]) -> bool:
        """
        :param win: window
        :return: 判定window是否需要收缩
        """
        return True

    need_stat: Dict[str, int] = defaultdict(int)  # 需要子串的统计
    window_stat: Dict[str, int] = defaultdict(int)  # 当前窗口的统计
    for c in t:
        need_stat[c] += 1
    left, right = 0, 0
    while right < len(s):
        c = s[right]  # c 是将移入窗口的字符
        right += 1  # 向右移动窗口
        # 进行窗口内数据的一系列更新
        pass  # ....
        # debug 输出的位置
        pass  # ...
        # 判断左侧窗口是否要收缩
        while is_window_needs_shrink(window_stat):
            d = s[left]  # d 是将移出窗口的字符
            left += 1  # 左移窗口
            # 进行窗口内数据的一系列更新
            pass  # ....
        # 更新答案
        pass  # ....


```

- left   是 window 的起始

  right是 window 的终止

  `window_stat` 是对窗口中的元素的统计(stat)，使用它能够快速地进行判断(比如判定 window 中是否contain need)。

- nested while：

  - 外层while 用于expand right( `++right` )

  - 内层while用于shrink left( `++left` )

​	它们都会引起滑动窗口的更新，因此都会执行"进行窗口内数据的一系列更新"。

​	其中两处`...`表示的更新窗口数据(window)的地方，需要结合具体的问题填入相应的代码。

​	这两个`...`处的操作分别是右移和左移窗口更新操作，等会你会发现它们操作是完全**对称**的。



### Q: window 和 `left`、`right` 的对应关系？

为什么要思考这个问题？因为很多时候，当更新答案的时候，可能需要比如:

- 如何计算window中元素的准确个数？( [LeetCode-3. 无重复字符的最长子串-中等](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) 中需要)

需要注意的是，window中元素的准确个数 不一定等于 `len(window_stat)`，这是因为(TODO: 补充在做 [LeetCode-3. 无重复字符的最长子串-中等](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) 时踩过的坑)。

sliding window是比较复杂的iteration，因为它有两个iterator: `left`、`right`，并且它还是nested loop，两个iterator的迭代( `move to next` )是不同步的(可以看到后面对它们的关系的是分是否移动了`left`的)，所以这就引发了我对 window 和 `left`、`right` 的对应关系的思考，结合做题和纯代码分析可知:

由于在循环体内，当执行到 `更新答案` 处的时候，right肯定是已经被迭代( `move to next` )了，而`next`的可能更新也可能没有更新，需要注意的是: `next` 始终指向的是window的起始位置(这是通过分析得到的)，无论它是否被更新。下面结合  [LeetCode-3. 无重复字符的最长子串-中等](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) 中的具体例子分情况来进行说明:

一、`left` 没有被更新

`abcdef`: 显然 `left` 一直是0，所以窗口的长度 = `(right -1) - left + 1` = `right - left`

说明:

- `right - 1` 是进行回退
- 由于`left`、`right` 都是下标，因此计算长度的时候需要最后 `+1`

二、`left`被更新了

窗口的长度 = `(right -1) - left + 1` = `right - left`

综上: 窗口的长度 = `(right -1) - left + 1` = `right - left` .



### 使用条件

使用滑动窗口解决连续子数组、连续子串的最值问题的**前提**是问题需要具备单调性：

> "向右滑动的时候，是寻找一个可行解，向左滑动是优化解"

如果问题不具备单调性，则不能够使用滑动窗口，这在下面的文章中进行了非常好的讨论:

#### 无法使用的情况

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

三、[LeetCode-560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/)

这个问题就是典型的不能够使用**滑动窗口**的

### 窗口表示与比较

目标值和窗口当前值的比较这是滑动窗口算法的一个common issue，为了高效进行，往往需要对它们进行统计

一般: 将目标值称为`need` (`need_stat`)，将窗口称之为`window` (`window_stat`)。

## Complexity

sliding window 相对于 暴力搜索 time complexity的优势: $O(n^2)$ -> $O(n)$

进一步滑动窗口相较于暴力搜索，优势何在？如何减少搜索空间？

1、滑动窗口，能够较快地判断窗口中，是否包含子串

2、暴力搜索，子串使用`str[i:j]`来表示，它使用嵌套for来给出所有的`i`、`j`组合

3、滑动窗口，基于上一次的位置开始进行expand、shrink，它不必每次重头再来。

> NOTE: 
>
> 典型的以空间换时间



### stackoverflow [Is two pointer problem same as sliding window](https://stackoverflow.com/questions/64078162/is-two-pointer-problem-same-as-sliding-window)



#### [A](https://stackoverflow.com/a/64078338)

**Sliding window algorithms** can be implemented with a single pointer and a variable for **window size**. Typically we use all of the elements within the window for the problem (for eg - sum of all elements in the window).

Two pointer technique is quite similar but we usually compare the value at the two pointers instead of all the elements between the pointers.

Two pointers can also have variations like fast-slow pointer.

Hope it answers your question.





## Application

[LeetCode-Sliding Window](https://leetcode.cn/tag/sliding-window/) 



这类问题有多种分类方式：

一、窗口是否定长？

参见`定长滑动窗口`章节。

二、连续还是不连续？

三、

1、存在性问题

2、计数问题

3、最优值问题

## Application: 数学

### [LeetCode-剑指 Offer 57 - II. 和为s的连续正数序列-简单](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) 

1. 穷举: "输出所有和为 `target` 的连续正整数序列（至少含有两个数）"
2. 这其实也是子串问题

C++

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

Python:

```
```



## Application: 子串、子数组 

滑动窗口解子串、子序列问题

素材:

1、[LeetCode-1004. 最大连续1的个数 III](https://leetcode.cn/problems/max-consecutive-ones-iii/) # [一个模板解决最大滑动窗口问题（同类型题目收集）](https://leetcode.cn/problems/max-consecutive-ones-iii/solution/jidao-by-iamysw-bs2s/)



### 习题分类

一、简单:

1、[LeetCode-剑指 Offer 57 - II. 和为s的连续正数序列](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) 

最好的滑动窗口例题

二、修改K次

[LeetCode-1004. 最大连续1的个数 III](https://leetcode.cn/problems/max-consecutive-ones-iii/) 中等

[LeetCode-424. 替换后的最长重复字符](https://leetcode.cn/problems/longest-repeating-character-replacement/) 中等

[LeetCode-1493. 删掉一个元素以后全为 1 的最长子数组](https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/) 

K为1





### [LeetCode-3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) 中等

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



### [LeetCode-76. 最小覆盖子串](https://leetcode.cn/problems/minimum-window-substring/) 困难



### [LeetCode-424. 替换后的最长重复字符](https://leetcode.cn/problems/longest-repeating-character-replacement/) 中等

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

### [LeetCode-438. 找到字符串中所有字母异位词](https://leetcode.cn/problems/find-all-anagrams-in-a-string/) 中等





### [LeetCode-567. 字符串的排列](https://leetcode.cn/problems/permutation-in-string/) 中等





### [LeetCode-1004. 最大连续1的个数 III](https://leetcode.cn/problems/max-consecutive-ones-iii/) 中等

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



### [LeetCode-1493. 删掉一个元素以后全为 1 的最长子数组](https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/) 



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





### [LeetCode-1839. 所有元音按顺序排布的最长子字符串](https://leetcode.cn/problems/longest-substring-of-all-vowels-in-order/) 中等



## Application: KMP  

第一次看到滑动窗口，我就联想到了KMP，下面的文章中，对此进行了说明:

- zhihu [谈一谈“滑动窗口”](https://zhuanlan.zhihu.com/p/113352663)

KMP算法是应用了滑动窗口最典型的例子





## 定长滑动窗口

对于定长窗口的滑动窗口问题，下面是解题模板：

一、Leetcode [1100. 长度为 K 的无重复字符子串](https://leetcode.cn/problems/find-k-length-substrings-with-no-repeated-characters/) 中等

计数

二、Leetcode [567. 字符串的排列](https://leetcode.cn/problems/permutation-in-string/) 中等

存在性



## 尺取法

尺取法其实就是滑动窗口，下面是一些素材：

一、

zhihu [尺取法（一）](https://zhuanlan.zhihu.com/p/31425915)

zhihu [尺取法（二）](https://zhuanlan.zhihu.com/p/31427570)

二、acwing [尺取法](https://www.acwing.com/blog/content/4409/)

三、[LeetCode-567. 字符串的排列](https://leetcode.cn/problems/permutation-in-string/)  



## TODO

fatalerrors [LC algorithm skills summary: double pointer and sliding window skills](https://www.fatalerrors.org/a/lc-algorithm-skills-summary-double-pointer-and-sliding-window-skills.html)

> NOTE: 
>
> 1、LC algorithm的含义是什么？

