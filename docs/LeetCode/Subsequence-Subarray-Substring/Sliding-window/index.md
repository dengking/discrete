# Sliding window



## 素材

一. labuladong 

- [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA) 

- [滑动窗口算法解决子串问题](https://mp.weixin.qq.com/s/nJHIxQ2BbqhDv5jZ9NgXrQ)
- [单调队列解决滑动窗口问题](https://mp.weixin.qq.com/s/GqehrBu9m7qf5FgFqlV-Uw)

二. [Eason](https://leetcode.cn/u/eason734/) # [[滑动窗口真滴简单!] 闪电五连鞭带你秒杀12道中档题 (附详情解析)](https://leetcode.cn/problems/longest-substring-without-repeating-characters/solutions/876061/yi-ge-mo-ban-miao-sha-10dao-zhong-deng-n-sb0x/)

三. [土豆](https://leetcode.cn/u/nuo-nuo-zi-4/) # [一招搞定滑动窗口类型所有题目](https://leetcode.cn/problems/find-all-anagrams-in-a-string/solutions/2492245/yi-zhao-gao-ding-hua-dong-chuang-kou-lei-2vyw/)



## Application

sliding window非常适合于 找满足特定条件的 **连续子数组**/**子串**，比如:

- 最大连续子区间

  这是在 [负雪明烛](https://leetcode.cn/u/fuxuemingzhu/) # [分享滑动窗口模板，秒杀滑动窗口问题](https://leetcode.cn/problems/max-consecutive-ones-iii/solution/fen-xiang-hua-dong-chuang-kou-mo-ban-mia-f76z/) 中提出的，具体来说就是"连续子数组、连续子串的最值问题"。



进一步来说这类问题有多种分类方式：

- 窗口是否定长？
  - `定长滑动窗口`
  - `定长滑动窗口`
- 求解的值
  - 存在性问题
  - 计数问题
  - 最优值问题



### LeetCode

[LeetCode-Sliding Window](https://leetcode.cn/tag/sliding-window/) 



## 定长滑动窗口

### Algo framework

TODO

### LeetCode

- [Leetcode-1100. 长度为 K 的无重复字符子串-中等-会员题](https://leetcode.cn/problems/find-k-length-substrings-with-no-repeated-characters/) 

- [LeetCode-438. 找到字符串中所有字母异位词-中等](https://leetcode.cn/problems/find-all-anagrams-in-a-string/) 、[Leetcode-567. 字符串的排列-中等](https://leetcode.cn/problems/permutation-in-string/) 

  两道题本质上是一样的

### [LeetCode-643. 子数组最大平均数 I-简单](https://leetcode.cn/problems/maximum-average-subarray-i/)

#### Python

```python
from typing import *


class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        """
        题目说明: n == nums.length, 1 <= k <= n <= 10^5
        因此不用考虑k>n的情况
        :param nums:
        :param k:
        :return:
        """
        max_sum = window_sum = sum(nums[:k])
        for i in range(k, len(nums)):
            window_sum = window_sum - nums[i - k] + nums[i]
            max_sum = max(max_sum, window_sum)
        return max_sum / k

```

非常典型的定长滑动窗口

### [LeetCode-438. 找到字符串中所有字母异位词-中等](https://leetcode.cn/problems/find-all-anagrams-in-a-string/) 



#### Python

```python

from typing import *


class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        def char_ord2index(c: str):
            return ord(c) - ord('a')

        s_len, p_len = len(s), len(p)

        if s_len < p_len:
            return []

        ans = []
        # 记录need和window的各个字符差距的个数
        # count[i] == 0: 表示need 和 window相同
        # count[i] >  0: 表示need 比 window多
        # count[i] <  0: 表示need 比 window少
        count = [0] * 26
        for i in range(p_len):
            count[char_ord2index(s[i])] += 1  # 要求则加1
            count[char_ord2index(p[i])] -= 1  # 满足了要求则减去1

        # window 和 need 中，不匹配(字符数量不相同)的字符的个数
        differ = [c != 0 for c in count].count(True)

        if differ == 0:
            ans.append(0)

        for left in range(s_len - p_len):
            left_c = s[left]  # 即将移出window
            left_c_idx = char_ord2index(left_c)  # 即将移出window
            # count[left_c_idx] == 1表示:
            # need中的left_c的个数比window中的left_c的个数多一个，此时left_c即将移入到window中，显然这个字符的差异即将消除
            if count[left_c_idx] == 1:
                differ -= 1
            # count[left_c_idx] == 0表示:
            # need中的left_c的个数和window中的left_c的个数相同
            elif count[left_c_idx] == 0:
                differ += 1
            count[left_c_idx] -= 1

            right_c = s[left + p_len]  # 即将移入window
            right_c_idx = char_ord2index(right_c)  # 即将移入window
            if count[right_c_idx] == -1:  # 窗口中字母 s[i+p_len] 的数量与字符串 p 中的数量从不同变得相同
                differ -= 1
            elif count[right_c_idx] == 0:  # 窗口中字母 s[i+p_len] 的数量与字符串 p 中的数量从相同变得不同
                differ += 1
            count[right_c_idx] += 1

            if differ == 0:
                ans.append(left + 1)

        return ans

```



#### C++

以窗口长度作为指标

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	vector<int> findAnagrams(string s, string p)
	{

		unordered_map<char, int> need, window;
		for (auto &&c : p)
		{
			++need[c];
		}
		int str_len = s.size();
		int p_len = p.size();
		int left = 0, right = 0;
		int valid = 0; //window中，有效字符的个数
		int start = 0;
		vector<int> res;
		while (right < str_len)
		{
			char c = s[right]; // 新进入的字符
			++right;
			if (need.count(c))
			{
				++window[c];
				if (window[c] == need[c])
				{
					++valid;
				}
			}
			while (right - left >= p_len) //
			{
				if (valid == need.size())
				{
					res.push_back(left);
				}
				char d = s[left];
				++left;
				if (window[d] > 0) // c是目标字符
				{
					if (window[d] == need[d])
					{
						--valid;
					}
					--window[d];
				}
			}
		}
		return res;
	}
};
int main()
{
	std::string s { "cbaebabacd" };
	std::string p { "abc" };
	Solution solu;
	auto res = solu.findAnagrams(s, p);
	for (auto &&v : res)
	{
		cout << v << endl;
	}
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```



### [LeetCode-567. 字符串的排列-中等](https://leetcode.cn/problems/permutation-in-string/) 

#### Python

```python
from collections import Counter

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s2) < len(s1):
            return False
        window_stat = Counter(s2[:len(s1)])
        s1_stat = Counter(s1)
        if window_stat == s1_stat:
            return True
        for right in range(len(s1), len(s2)):
            right_c = s2[right]
            window_stat[right_c] += 1
            left_c = s2[right - len(s1)]
            window_stat[left_c] -= 1
            if window_stat[left_c] == 0:
                del window_stat[left_c]
            if window_stat == s1_stat:
                return True
        return False

```



#### C++

官方解题 # [滑动窗口](https://leetcode.cn/problems/permutation-in-string/solution/zi-fu-chuan-de-pai-lie-by-leetcode-solut-7k7u/)



```C++
class Solution {
public:
bool checkInclusion(string s1, string s2)
	{
		int len1 = s1.length(), len2 = s2.length();
		if (len1 > len2)
		{
			return false;
		}
		vector<int> count1(26), count2(26);
		for (int i = 0; i < len1; ++i)
		{
			++count1[s1[i] - 'a'];
			++count2[s2[i] - 'a'];
		}
		if (count1 == count2)
		{
			return true;
		}
		for (int i = len1; i < len2; ++i)
		{
			char in = s2[i]; // 新进入的字符
			char out = s2[i - len1]; // 退出的字符
			--count2[out - 'a'];
			++count2[in - 'a'];
			if (count1 == count2)
			{
				return true;
			}
		}
		return false;
	}
};
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

显然上述写法非常简单易懂，在面试过程中，这种简单易懂的程序能够节省更多的时间。



### [LeetCode1100. 长度为 K 的无重复字符子串-中等](https://leetcode.cn/problems/find-k-length-substrings-with-no-repeated-characters/) 

这是典型的定长窗口，和leetcode  [567. 字符串的排列](https://leetcode.cn/problems/permutation-in-string/) 类似。

#### C++

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
  int numKLenSubstrNoRepeats(string s, int k)
  {
    int N = s.size();
    if (N < k)
    {
      return false;
    }
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
    int res = 0;
    if (isNotRepeat())
    {
      ++res;
    }
    for (int i = k; i < N; ++i)
    {
      ++window[s[i]];
      --window[s[i - k]];
      if (isNotRepeat())
      {
        ++res;
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

## 不定长滑动窗口



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



### 窗口表示与比较

目标值和窗口当前值的比较这是滑动窗口算法的一个common issue，为了高效进行，往往需要对它们进行统计

一般: 将目标值称为`need` (`need_stat`)，将窗口称之为`window` (`window_stat`)。



### 使用条件

#### 滑动窗口单调性要求

使用滑动窗口算法的**前提**是: `window_stat` (指标) 和 window size 是单调的(不一定是呈比例的，但一定是window size缩小，则`window_stat` (指标)一定同步变化)，将这个要求称之为 "**滑动窗口单调性要求**"。

因为: **滑动窗口算法**无非就是双指针形成的扫描整个数组/子串的"**窗口**"，**滑动窗口算法** 需要根据 `window_stat` (指标) 来决定是否收缩窗口，收缩窗口意味着window size减少，如果`window_stat` (指标)不能同步变化，那么内层循环就无法退出，依赖于  `window_stat` (指标) ，算法能够非常清楚地知道什么时候应该移动右侧指针来扩大窗口，什么时候移动左侧指针来减小窗口。

> "向右滑动的时候，是寻找一个**可行解**，向左滑动是**优化解**"

结合后面的题目可知上面这段话是一语中的。

如果问题满足"**滑动窗口单调性要求**"，则不能够使用滑动窗口，关于此的最经典问题是**子数组和问题**:

##### 子数组和问题

- 如果数组中    存在负数，则**不**能使用滑动窗口算法，因为此时`window_stat` (sum) 和 window size **不**是单调的

  例题:

  - [LeetCode-560. 和为 K 的子数组](https://leetcode.cn/problems/subarray-sum-equals-k/) 

- 如果数组中**不**存在负数，则    能使用滑动窗口算法，因为此时`window_stat` (sum) 和 window size     是单调的

  例题:

  - [LeetCode-剑指 Offer 57 - II. 和为s的连续正数序列-简单](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) / [LCR 180. 文件组合-简单](https://leetcode.cn/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/) 

素材: 

- labuladong [动态规划套路：最大子数组和](https://mp.weixin.qq.com/s/nrULqCsRsrPKi3Y-nUfnqg) 

- zhuanlan [经典动态规划：最大子数组问题](https://zhuanlan.zhihu.com/p/144385162) 

  > 但是，稍加分析就发现，**这道题还不能用滑动窗口算法，因为数组中的数字可以是负数**。
  >
  > 滑动窗口算法无非就是双指针形成的窗口扫描整个数组/子串，但关键是，你得清楚地知道什么时候应该移动右侧指针来扩大窗口，什么时候移动左侧指针来减小窗口。
  >
  > 而对于这道题目，你想想，当窗口扩大的时候可能遇到负数，窗口中的值也就可能增加也可能减少，这种情况下不知道什么时机去收缩左侧窗口，也就无法求出「最大子数组和」。



#### `window_stat` 需要能够帮助判断问题

[LeetCode-5. 最长回文子串-中等](https://leetcode.cn/problems/longest-palindromic-substring/) 不能使用sliding window，一个原因是`window_stat`无法用于快速判断是否是回文。



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



相较于Algo framework1，Algo framework2计算窗口size是更加符合直觉的。

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

5. 这道题其实和 [LeetCode-11. 盛最多水的容器-Medium](https://leetcode.cn/problems/container-with-most-water/) 有点类似

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
            while (has_repeat())
            {
                window[s[left++]]--;
            }
            // int window_size = right - left + 1;
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

### [LeetCode-76. 最小覆盖子串-困难](https://leetcode.cn/problems/minimum-window-substring/) 

以窗口长度作为窗口指标

#### Python

```python
from typing import *
from collections import defaultdict
import sys


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        window_stat: Dict[str, int] = defaultdict(int)
        t_stat: Dict[str, int] = defaultdict(int)
        for c in t:
            t_stat[c] += 1

        def is_contain_t() -> bool:
            """

            :return:
            """
            for k, v in t_stat.items():
                if k in window_stat:
                    if window_stat[k] < v:
                        return False
                else:
                    return False
            return True

        left = 0
        min_len = sys.maxsize
        min_str = ''
        for right in range(0, len(s)):
            right_c = s[right]
            window_stat[right_c] += 1

            while is_contain_t():  # 优化解
                window_size = right - left + 1
                if window_size < min_len:
                    min_len = window_size
                    min_str = s[left:right + 1]
                left_c = s[left]
                window_stat[left_c] -= 1
                left += 1

        return min_str


if __name__ == '__main__':
    solu = Solution()
    print(solu.minWindow("ADOBECODEBANC", 'ABC'))

```



#### C++

```C++
#include <string>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> need, window;
		for (auto&& c : t) {
			need[c]++;
		}
		int left = 0, right = 0;
		int validCount = 0; // window中已经符合预期的字符数量的字符的个数
		int subStrMinLen = INT_MAX;
		int subStrStartIndex = 0;
		while (right < s.size()) {
			char inChar = s[right++];
			if (need.count(inChar)) {
				window[inChar]++;
				if (window[inChar] == need[inChar]) {
					++validCount;
				}
			}
			while (validCount == need.size())
			{
				int subStrLen = right - left; // 左开右闭区间
				if (subStrLen < subStrMinLen) {
					subStrMinLen = subStrLen;
					subStrStartIndex = left;
				}
				char outChar = s[left++];
				if (need.count(outChar)) {
					
					if (window[outChar] == need[outChar]) {
						--validCount;
					}
					window[outChar]--;
				}
			}
		}
		return subStrMinLen == INT_MAX ? "" : s.substr(subStrStartIndex, subStrMinLen);
	}
};

int main()
{
	Solution s;
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

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



### [LeetCode-1839. 所有元音按顺序排布的最长子字符串-中等](https://leetcode.cn/problems/longest-substring-of-all-vowels-in-order/)  

```python

from typing import *


class Solution:
    def longestBeautifulSubstring(self, word: str) -> int:
        vowels = 'aeiou'
        window_stat: Dict[str, int] = {}  # 元音 : 最大index

        def is_disorder() -> bool:
            """
            :return: 判断window中的元音是否乱序
            """
            if len(window_stat) == 0:
                return False
            # 然后从第一个元音开始，到window中的最大的元音
            # 判断两个相邻的元音是否满足顺序要求
            for i in range(0, vowels.index(max(window_stat.keys()))):
                v1 = vowels[i]
                v2 = vowels[i + 1]
                if v1 in window_stat and v2 in window_stat and window_stat[v1] < window_stat[v2]:
                    continue
                else:
                    return True
            return False

        def is_window_contain_vowels():
            """判断window中，是否包含所有的元音"""
            return len(window_stat) == len(vowels)

        left = 0
        ans = 0
        for right in range(0, len(word)):
            right_c = word[right]
            if right_c in vowels:
                window_stat[right_c] = right
            while is_disorder():
                left_c = word[left]
                if left_c in window_stat and left == window_stat[left_c]:
                    del window_stat[left_c]
                left += 1
            if is_window_contain_vowels():
                ans = max(ans, right - left + 1)
        return ans

```





### 题目类型: 允许修改window `k`次

[LeetCode-1004. 最大连续1的个数 III-中等](https://leetcode.cn/problems/max-consecutive-ones-iii/) 

[LeetCode-424. 替换后的最长重复字符中等](https://leetcode.cn/problems/longest-repeating-character-replacement/) 

[LeetCode-1493. 删掉一个元素以后全为 1 的最长子数组](https://leetcode.cn/problems/longest-subarray-of-1s-after-deleting-one-element/) 



#### [LeetCode-424. 替换后的最长重复字符-中等](https://leetcode.cn/problems/longest-repeating-character-replacement/) 

> 给你一个字符串 `s` 和一个整数 `k` 。你可以选择字符串中的任一字符，并将其更改为任何其他大写英文字符。该操作最多可执行 `k` 次。

从贪心的角度来说，将窗口中的所有的元素都翻转为和窗口中数量最多的元素一样即可，由于最多只能翻转`k`次，所以**滑动窗口的限制条件**: 窗口中，可以翻转的字符的数量至多为`k` ，那如何计算"可以翻转的字符的数量"? 使用窗口的数量 - 众数的数量。

参考:

- [migoo](https://leetcode.cn/u/migoo/) # [通过此题了解一下什么是滑动窗口 Java 题解](https://leetcode.cn/problems/longest-repeating-character-replacement/solution/tong-guo-ci-ti-liao-jie-yi-xia-shi-yao-shi-hua-don/) 写的。

```C++
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        std::unordered_map<char, int> window_stat;
        using pair_type = decltype(window_stat)::value_type;
        // https://stackoverflow.com/a/9371137/10173843
        // 计算众数的个数
        auto cal_cnt_of_majority_func = [&]() -> int
        {
            return std::max_element(window_stat.begin(), window_stat.end(), [](const pair_type &left, const pair_type &right)
                                    { return left.second < right.second; })
                ->second;
        };
        int ret = 0;
        int len = s.size();
        for (int left = 0, right = 0; right < len; ++right)
        {
            window_stat[s[right]]++;
            // int window_size = right - left + 1;
            while ((right - left + 1) - cal_cnt_of_majority_func() > k)
            {
                window_stat[s[left++]]--;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

上述code非常简介，是典型的模板。



#### [LeetCode-1004. 最大连续1的个数 III](https://leetcode.cn/problems/max-consecutive-ones-iii/) 中等

要求最大连续1的个数，并且允许翻转K 个0 为 1，显然贪心的思想就是将它们全部都翻转为1即可；

[负雪明烛](https://leetcode.cn/u/fuxuemingzhu/) # [分享滑动窗口模板，秒杀滑动窗口问题](https://leetcode.cn/problems/max-consecutive-ones-iii/solution/fen-xiang-hua-dong-chuang-kou-mo-ban-mia-f76z/) 

> 重点：题意转换。把「最多可以把 K 个 0 变成 1，求仅包含 1 的最长子数组的长度」转换为 「找出一个最长的子数组，该子数组内最多允许有 K 个 0 」。
>
> 经过上面的题意转换，我们可知本题是求**最大连续子区间**，可以使用**滑动窗口**方法。**滑动窗口**的限制条件是：窗口内最多有 K 个 0。

"最大连续子区间"是这道题的点题之语。

##### Sliding window Python

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



## 多指针滑动窗口

[灵茶山艾府](https://leetcode.cn/u/endlesscheng/) # [分享丨【题单】滑动窗口（定长/不定长/多指针）](https://leetcode.cn/circle/discuss/0viNMK/) 

## Application: KMP  

第一次看到滑动窗口，我就联想到了KMP，下面的文章中，对此进行了说明:

- zhihu [谈一谈“滑动窗口”](https://zhuanlan.zhihu.com/p/113352663)

KMP算法是应用了滑动窗口最典型的例子



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

