# Sliding window



## 素材

一. labuladong 

- [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA) 

- [滑动窗口算法解决子串问题](https://mp.weixin.qq.com/s/nJHIxQ2BbqhDv5jZ9NgXrQ)
- [单调队列解决滑动窗口问题](https://mp.weixin.qq.com/s/GqehrBu9m7qf5FgFqlV-Uw)



## Algo framework1(左闭右开)



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

### Sliding(滑动)、update `window_stat`



Q: 既然是滑动窗口，那么窗口是如何滑动的呢？

A: 滑动窗口的重要性质是：窗口的左边界(`left`)和右边界(`right`)永远只能向右移动，而不能向左移动。这是为了保证**滑动窗口**的时间复杂度是 $O(n)$。如果左右边界向左移动的话，这叫做“回溯”，算法的时间复杂度就可能不止 $O(n)$。

滑动窗口只有 **右边界向右移动（扩大窗口）** 和 **左边界向右移动（缩小窗口）** 两个操作(实际上非常简单): 

nested while：

- 外层while 用于expand right( `++right` )

- 内层while用于shrink left( `++left` )



Q: how to update `window_stat`？

A: 它们都会引起滑动窗口的更新，因此都会执行"进行窗口内数据的一系列更新"。

上述algo framework中两处`...`表示的更新窗口数据(window)的地方，需要结合具体的问题填入相应的代码。

这两个`...`处的操作分别是右移和左移窗口更新操作，等会你会发现它们操作是完全**对称**的。



### window 和 `left`、`right` 的对应关系？

为什么要思考这个问题？因为很多时候，当更新答案的时候，可能需要比如:

- 如何计算window中元素的准确个数？( [LeetCode-3. 无重复字符的最长子串-中等](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) 中需要)
- [LCR 180. 文件组合](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/)

A: 

我们设滑动窗口的左边界为 `left`，右边界为 `right`，则滑动窗口框起来的是一个左闭右开区间 `[left,right)`。注意，为了编程的方便，滑动窗口一般表示成一个**左闭右开区间**。在一开始，滑动窗口位于序列的最左侧，窗口大小为零(将 `left`、`right`设置为相同的最小值 )。

> NOTE:
>
> 一、上面这段话的内容源自: [nettee](https://leetcode.cn/u/nettee/) # [什么是滑动窗口，以及如何用滑动窗口解这道题（C++/Java/Python）](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solutions/133768/shi-yao-shi-hua-dong-chuang-kou-yi-ji-ru-he-yong-h/) 



`window_stat` 是对窗口中的元素的统计(stat)，使用它能够快速地进行判断(比如判定 window 中是否contain need)。

#### 如何计算window中元素的个数？

需要注意的是，window中元素的准确个数 不一定等于 `len(window_stat)`，这是因为(TODO: 补充在做 [LeetCode-3. 无重复字符的最长子串-中等](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) 时踩过的坑)。

sliding window是比较复杂的iteration，因为它有两个iterator: `left`、`right`，并且它还是nested loop，两个iterator的迭代( `move to next` )是不同步的(可以看到后面对它们的关系的是分是否移动了`left`的)，所以这就引发了我对 window 和 `left`、`right` 的对应关系的思考，结合做题和纯代码分析可知:

由于在循环体内，当执行到 `更新答案` 处的时候，right肯定是已经被迭代( `move to next` )了，而`left`的可能更新也可能没有更新，需要注意的是: `left` 始终指向的是window的起始位置(这是通过分析得到的)，无论它是否被更新。下面结合  [LeetCode-3. 无重复字符的最长子串-中等](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) 中的具体例子分情况来进行说明:

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



## Algo framework2(左闭右闭)

[负雪明烛](https://leetcode.cn/u/fuxuemingzhu/) # [分享滑动窗口模板，秒杀滑动窗口问题](https://leetcode.cn/problems/max-consecutive-ones-iii/solution/fen-xiang-hua-dong-chuang-kou-mo-ban-mia-f76z/) 中提出的:

```python
def findSubArray(nums):
    N = len(nums) # 数组/字符串长度
    left, right = 0, 0 # 双指针，表示当前遍历的区间[left, right]，闭区间
    sums = 0 # 用于统计 子数组/子区间 是否有效，根据题目可能会改成求和/计数
    res = 0 # 保存最大的满足题目要求的 子数组/子串 长度
    while right < N: # 当右边的指针没有搜索到 数组/字符串 的结尾
        sums += nums[right] # 增加当前右边指针的数字/字符的求和/计数
        while 区间[left, right]不符合题意: # 此时需要一直移动左指针，直至找到一个符合题意的区间
            sums -= nums[left] # 移动左指针前需要从counter中减少left位置字符的求和/计数
            left += 1 # 真正的移动左指针，注意不能跟上面一行代码写反
        # 到 while 结束时，我们找到了一个符合题意要求的 子数组/子串
        res = max(res, right - left + 1) # 需要更新结果
        right += 1 # 移动右指针，去探索新的区间
    return res

作者：负雪明烛
链接：https://leetcode.cn/problems/max-consecutive-ones-iii/solutions/609055/fen-xiang-hua-dong-chuang-kou-mo-ban-mia-f76z/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



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

滑动窗口只能够解连续区间问题

三、

1、存在性问题

2、计数问题

3、最优值问题

四、"最大连续子区间"

这是在 [负雪明烛](https://leetcode.cn/u/fuxuemingzhu/) # [分享滑动窗口模板，秒杀滑动窗口问题](https://leetcode.cn/problems/max-consecutive-ones-iii/solution/fen-xiang-hua-dong-chuang-kou-mo-ban-mia-f76z/) 中提出的

## Application: 数学

### [LeetCode-剑指 Offer 57 - II. 和为s的连续正数序列-简单](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) / [LCR 180. 文件组合-简单](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) 

1. 穷举: "输出所有和为 `target` 的连续正整数序列（至少含有两个数）"

2. 这其实也是子数组和问题

3. [nettee](https://leetcode.cn/u/nettee/) # [什么是滑动窗口，以及如何用滑动窗口解这道题（C++/Java/Python）](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solutions/133768/shi-yao-shi-hua-dong-chuang-kou-yi-ji-ru-he-yong-h/) 

   > 当窗口的和恰好等于 target 的时候，我们需要记录此时的结果。设此时的窗口为 `[i,j)`，那么我们已经找到了一个 `i` 开头的序列，也是唯一一个 `i` 开头的序列，接下来需要找 `i+1` 开头的序列，所以窗口的左边界要向右移动
   >
   > 作者：nettee
   > 链接：https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solutions/133768/shi-yao-shi-hua-dong-chuang-kou-yi-ji-ru-he-yong-h/
   > 来源：力扣（LeetCode）
   > 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

4. 这道题是最好的滑动窗口例题

#### Python

```python
class Solution:
    def fileCombination(self, target: int) -> List[List[int]]:
        l = 1  # 滑动窗口的左边界
        r = 1  # 滑动窗口的右边界
        sum = 0  # 滑动窗口中数字的和
        ans = []

        while l <= target // 2: # 题目要求和为target且至少有两个元素，因此l最大只能到这里
            if sum < target:
                # 右边界向右移动
                sum += r
                r += 1
            elif sum > target:
                # 左边界向右移动
                sum -= l
                l += 1
            else:
                # 记录结果
                arr = list(range(l, r))
                ans.append(arr)
                # 左边界向右移动
                sum -= l
                l += 1

        return ans

```



#### C++

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



## Application: 子串、子数组 

滑动窗口解子串、子序列问题



### 题目类型: 允许修改window `k`次

[LeetCode-1004. 最大连续1的个数 III-中等](https://leetcode.cn/problems/max-consecutive-ones-iii/) 

[LeetCode-424. 替换后的最长重复字符中等](https://leetcode.cn/problems/longest-repeating-character-replacement/) 

[LeetCode-1493. 删掉一个元素以后全为 1 的最长子数组](https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/) 

K为1



### [LeetCode-3. 无重复字符的最长子串-中等](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) 

[LeetCode-剑指 Offer 48. 最长不含重复字符的子字符串](https://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/)



#### C++ algo framework2

```C++
#include <string>
#include <algorithm>
#include <unordered_map>
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

#### Python algo framework1

错误写法: 

```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        def is_window_duplicate(w: Dict[str, int]) -> bool:
            return any(cnt > 1 for cnt in w.values())

        left, right = 0, 0
        window: Dict[str, int] = defaultdict(int)
        ans = 0
        while right < len(s):
            c_right = s[right]
            right += 1
            window[c_right] += 1
            while is_window_duplicate(window):
                c_left = s[left]
                left += 1
                window[c_left] -= 1

            ans = max(ans, len(window))
        return ans

```

上述计算当前 `window` 的长度的方式是错误的，因为 `window` 的实现是dict，当一个字符的计数为0的时候，它并不会将它从dict中删除，这就导致了无法准确的计算出当前窗口中有多少个字符。



正确写法:

```python
from typing import *
from collections import defaultdict

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        def is_window_duplicate(w: Dict[str, int]) -> bool:
            return any(cnt > 1 for cnt in w.values())

        left, right = 0, 0
        window: Dict[str, int] = defaultdict(int)
        ans = 0
        while right < len(s):
            c_right = s[right]
            right += 1
            window[c_right] += 1
            while is_window_duplicate(window):
                c_left = s[left]
                left += 1
                window[c_left] -= 1

            ans = max(ans, right - left)
        return ans


if __name__ == '__main__':
    solu = Solution()
    solu.lengthOfLongestSubstring("pwwkew")

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

要求最大连续1的个数，并且允许翻转K 个0 为 1，显然贪心的思想就是将它们全部都翻转为1即可；

[负雪明烛](https://leetcode.cn/u/fuxuemingzhu/) # [分享滑动窗口模板，秒杀滑动窗口问题](https://leetcode.cn/problems/max-consecutive-ones-iii/solution/fen-xiang-hua-dong-chuang-kou-mo-ban-mia-f76z/) 

> 重点：题意转换。把「最多可以把 K 个 0 变成 1，求仅包含 1 的最长子数组的长度」转换为 「找出一个最长的子数组，该子数组内最多允许有 K 个 0 」。
>
> 经过上面的题意转换，我们可知本题是求**最大连续子区间**，可以使用**滑动窗口**方法。**滑动窗口**的限制条件是：窗口内最多有 K 个 0。

"最大连续子区间"是这道题的点题之语。

#### Sliding window Python

```python

class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        left, right = 0, 0
        ans = 0
        window_stat = 0
        while right < len(nums):
            if nums[right] == 0:
                window_stat += 1
            right += 1
            while window_stat > k:
                if nums[left] == 0:
                    window_stat -= 1
                left += 1
            ans = max(ans, right - left) # 显然，执行到这里window中至多有k个0，由于可以将它们翻转为1，且它们是相连的，因此此时window的长度是right - left
        return ans

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

