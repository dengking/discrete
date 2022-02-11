# labuladong [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA) 

言归正传，鉴于前文 [我作了首诗，保你闭着眼睛也能写对二分查找](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485044&idx=1&sn=e6b95782141c17abe206bfe2323a4226&chksm=9bd7f87caca0716aa5add0ddddce0bfe06f1f878aafb35113644ebf0cf0bfe51659da1c1b733&scene=21#wechat_redirect) 的那首《二分搜索升天词》很受好评，并在民间广为流传，成为安睡助眠的一剂良方，今天在滑动窗口算法框架中，我再次编写一首小诗来歌颂滑动窗口算法的伟大：



链表子串数组题，用双指针别犹豫。

**双指针**家**三兄弟**，各个都是万人迷。

**快慢指针**最神奇，链表操作无压力。

归并排序找中点，链表成环搞判定。

**左右指针**最常见，左右两端相向行。

**反转数组**要靠它，二分搜索是弟弟。

**滑动窗口**老猛男，**子串问题**全靠它。

左右指针滑窗口，一前一后齐头进。

> NOTE: 
>
> 1、双指针家"三兄弟"，指的是哪三个？
>
> 快慢指针、左右指针、滑动窗口

![图片](https://mmbiz.qpic.cn/sz_mmbiz_png/gibkIz0MVqdEsLiaY9d9CcVdNcPTAdO5MRwZhsxtTc6BaDMpHQtibCX5kY406sxFeaClrlft3j6XiaJ48jq0Gnj2dQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

关于双指针的快慢指针和左右指针的用法，可以参见前文 [双指针技巧汇总](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484505&idx=1&sn=0e9517f7c4021df0e6146c6b2b0c4aba&chksm=9bd7fa51aca07347009c591c403b3228f41617806429e738165bd58d60220bf8f15f92ff8a2e&scene=21#wechat_redirect)，**本文就解决一类最难掌握的双指针技巧：滑动窗口技巧，并总结出一套框架，可以保你闭着眼直接套出答案。**

说起滑动窗口算法，很多读者都会头疼。这个算法技巧的思路非常简单，就是维护一个窗口，不断滑动，然后更新答案么。LeetCode 上有起码 10 道运用滑动窗口算法的题目，难度都是中等和困难。

> NOTE: 
>
> 1、参见 leetcode [Sliding Window](https://leetcode-cn.com/tag/sliding-window/)

## 大致逻辑

该算法的大致逻辑如下：

```c++
int left = 0, right = 0;

while (right < s.size()) {
    // 增大窗口
    window.add(s[right]);
    right++;

    while (window needs shrink) {
        // 缩小窗口
        window.remove(s[left]);
        left++;
    }
}
```

这个算法技巧的时间复杂度是 O(N)，比一般的字符串暴力算法要高效得多。

> NOTE: 
>
> 1、为何上述算法，复杂度更低？
>
> 2、不同的"window needs shrink"条件不同

**其实困扰大家的，不是算法的思路，而是各种细节问题**。比如说如何向窗口中添加新元素，如何缩小窗口，在窗口滑动的哪个阶段更新结果。即便你明白了这些细节，也容易出 bug，找 bug 还不知道怎么找，真的挺让人心烦的。

## 代码框架

**所以今天我就写一套滑动窗口算法的代码框架，我连在哪里做输出 debug 都给你写好了，以后遇到相关的问题，你就默写出来如下框架然后改三个地方就行，还不会出边界问题**：

```c++
/* 滑动窗口算法框架 */
void slidingWindow(string s, string t) {
    // 预处理字符串
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0; 
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        ...

        /*** debug 输出的位置 ***/
        printf("window: [%d, %d)\n", left, right);
        /********************/

        // 判断左侧窗口是否要收缩
        while (window needs shrink) {
            // d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            ...
        }
    }
}
```

> NOTE: 
>
> 嵌套`while`，外层`while`用于expand right，内存while用于shrink left，它们都会引起滑动窗口的更新，因此都会执行"进行窗口内数据的一系列更新"。

**其中两处`...`表示的更新窗口数据的地方，到时候你直接往里面填就行了**。

而且，这两个`...`处的操作分别是右移和左移窗口更新操作，等会你会发现它们操作是完全对称的。

> NOTE: 
>
> 1、使用`window`、`need`、`valid`，能够快速地判断，`window`中是否contain `need`。

## 真题

言归正传，**下面就直接上四道LeetCode 原题来套这个框架**，其中第一道题会详细说明其原理，后面四道就直接闭眼睛秒杀了。

本文代码为 C++ 实现，不会用到什么编程方面的奇技淫巧，但是还是简单介绍一下一些用到的数据结构，以免有的读者因为语言的细节问题阻碍对算法思想的理解：

`unordered_map`就是哈希表（字典），它的一个方法`count(key)`相当于 Java 的`containsKey(key)`可以判断键 key 是否存在。

可以使用方括号访问键对应的值`map[key]`。需要注意的是，如果该`key`不存在，C++ 会自动创建这个 key，并把`map[key]`赋值为 0。

所以代码中多次出现的`map[key]++`相当于 Java 的`map.put(key, map.getOrDefault(key, 0) + 1)`。

## 真题一、最小覆盖子串

> NOTE: 
>
> 1、典型的需要找到最优解，而不是一个解，因此需要罗列所有的可能性
>
> 2、LeetCode [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/) 困难
>
> 

LeetCode 76 题，Minimum Window Substring，难度 **Hard**，我带大家看看它到底有多 **Hard**：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_png/gibkIz0MVqdGQlBxOlAet1AXGPoibCzEowk6hiaxmGN6ibHiaTqxHMqYvCRA4lWuRCQicPSfZY78De1GmwkXviar4psjw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

就是说要在`S`(source) 中找到包含`T`(target) 中全部字母的一个子串，且这个子串一定是所有可能子串中最短的。

如果我们使用暴力解法，代码大概是这样的：

```c++
for (int i = 0; i < s.size(); i++)
    for (int j = i + 1; j < s.size(); j++)
        if s[i:j] 包含 t 的所有字母:
            更新答案
```

思路很直接，但是显然，这个算法的复杂度肯定大于 O(N^2) 了，不好。

### 滑动窗口算法的思路是这样：

***1、***我们在字符串`S`中使用双指针中的左右指针技巧，初始化`left = right = 0`，**把索引左闭右开区间`[left, right)`称为一个「窗口」**。

> NOTE: 
>
> 因此，窗口的长度为: right - left，需要注意的是，由于right不属于窗口，因此它的长度不能够是:
>
> right - left + 1，这是错误的

***2、***我们先不断地增加`right`指针扩大窗口`[left, right)`，直到窗口中的字符串符合要求（包含了`T`中的所有字符）。

***3、***此时，我们停止增加`right`，转而不断增加`left`指针缩小窗口`[left, right)`，直到窗口中的字符串不再符合要求（不包含`T`中的所有字符了）。同时，每次增加`left`，我们都要更新一轮结果。

> NOTE: 
>
> 缩小窗口，优化解

***4、***重复第 2 和第 3 步，直到`right`到达字符串`S`的尽头。

> NOTE: 
>
> 1、显然，上述不断地进行重复，目的是罗列出所有的可能性
>
> 最优解，而不是一个可行解，需要罗列所有的可能性
>
> 2、滑动窗口向右滑动的时候，是寻找一个可行解，向左滑动是优化解，也就是滑动窗口需要问题具备一定的单调性，即向右滑动，总是能够得到可行解，向左滑动，总是能够优化解，这样才能够决定何时向右滑动，何时向左滑动，也就是说，滑动窗口适合于解决"子序列、单调性、最优化问题"
>
> 如果不满足这个条件，在无法使用滑动窗口寻找最优解

这个思路其实也不难，**第 2 步相当于在寻找一个「可行解」，然后第 3 步在优化这个「可行解」，最终找到最优解，**也就是最短的覆盖子串。左右指针轮流前进，窗口大小增增减减，窗口不断向右滑动，这就是「滑动窗口」这个名字的来历。

下面画图理解一下，`needs`和`window`相当于计数器，分别记录`T`中字符出现次数和「窗口」中的相应字符的出现次数。

初始状态：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_png/gibkIz0MVqdGQlBxOlAet1AXGPoibCzEow6FwvAvsZKyCTCtrmLcvKDxhYAJEqI36cAZxfoIWLFibEhmz9IfHf24Q/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

### 现在开始套模板，只需要思考以下四个问题：

**1、**当移动`right`扩大窗口，即加入字符时，应该更新哪些数据？

**2、**什么条件下，窗口应该暂停扩大，开始移动`left`缩小窗口？

**3、**当移动`left`缩小窗口，即移出字符时，应该更新哪些数据？

**4、**我们要的结果应该在扩大窗口时还是缩小窗口时进行更新？

> NOTE: 
>
> 1、大多数，都是在窗口缩小的时候更新



### 实现、source code

如果你能够理解上述过程，恭喜，你已经完全掌握了滑动窗口算法思想。**现在我们来看看这个滑动窗口代码框架怎么用**：

首先，初始化`window`和`need`两个哈希表，记录窗口中的字符和需要凑齐的字符：

```C++
unordered_map<char, int> need, window;
for (char c : t) need[c]++;
```

> NOTE: 
>
> 1、`need`记录需要哪些字符，每个字符的个数
>
> 2、`window`记录窗口中的字符的情况

**其中`valid`变量表示窗口中满足`need`条件的字符个数**，如果`valid`和`need.size`的大小相同，则说明窗口已满足条件，已经完全覆盖了串`T`。

> NOTE: 
>
> 1、上面介绍了，如何实现"完全覆盖"

如果一个字符进入窗口，应该增加`window`计数器；如果一个字符将移出窗口的时候，应该减少`window`计数器；当`valid`满足`need`时应该收缩窗口；应该在收缩窗口的时候更新最终结果。

#### 完整代码

下面是完整代码：

```C++
string minWindow(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    // 记录最小覆盖子串的起始索引及长度
    int start = 0, len = INT_MAX;
    while (right < s.size()) {
        // c 是将移入窗口的字符
        char c = s[right];
        // 右移窗口
        right++;
        // 进行窗口内数据的一系列更新
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c])
                valid++;
        }

        // 判断左侧窗口是否要收缩
        while (valid == need.size()) {
            // 在这里更新最小覆盖子串
            if (right - left < len) {
                start = left;
                len = right - left;
            }
            // d 是将移出窗口的字符
            char d = s[left];
            // 左移窗口
            left++;
            // 进行窗口内数据的一系列更新
            if (need.count(d)) {
                if (window[d] == need[d])
                    valid--;
                window[d]--;
            }                    
        }
    }
    // 返回最小覆盖子串
    return len == INT_MAX ?
        "" : s.substr(start, len);
}
```

需要注意的是，当我们发现某个字符在`window`的数量满足了`need`的需要，就要更新`valid`，表示有一个字符已经满足要求。而且，你能发现，两次对窗口内数据的更新操作是完全对称的。

当`valid == need.size()`时，说明`T`中所有字符已经被覆盖，已经得到一个可行的覆盖子串，现在应该开始收缩窗口了，以便得到「最小覆盖子串」。

移动`left`收缩窗口时，窗口内的字符都是可行解，所以应该在收缩窗口的阶段进行最小覆盖子串的更新，以便从可行解中找到长度最短的最终结果。

至此，应该可以完全理解这套框架了，滑动窗口算法又不难，就是细节问题让人烦得很。**以后遇到滑动窗口算法，你就按照这框架写代码，保准没有 bug，还省事儿**。

> NOTE: 
>
> 下面是我第一次写的程序:
>
> ```C++
> #include <bits/stdc++.h>
> using namespace std;
> class Solution
> {
> public:
> 	string minWindow(string s, string t)
> 	{
> 
> 		unordered_map<char, int> need, window;
> 		// 预处理字符串t，便于进行匹配
> 		for (auto &&c : t)
> 			need[c]++;
> 		int left = 0, right = 0; // 滑动窗口的左右
> 		int valid = 0; // 记录窗口中，已经满足了need中字符数量的字符的个数
> 		// 结果
> 		int start = 0; //结果的起始位置
> 		int len = INT_MAX; //结果的长度
> 
> 		while (right < s.size())
> 		{
> 			char c = s[right];
> 			++right;
> 
> 			// 更新window
> 			if (need.count(c)) // c是目标字符
> 			{
> 				window[c]++; // 更新window中的字符统计
> 				if (window[c] == need[c]) // 字符c已经满足了要求
> 				{
> 					++valid;
> 				}
> 			}
> 			while (valid == need.size()) // 需要收缩window
> 			{
> 				if (right - left < len) // 需要注意，窗口是[left, right)即左开右闭，需要注意的是，由于right不属于窗口，因此它的长度不能够是: right - left + 1，这是错误的
> 				{
> 					len = right - left + 1;
> 					start = left;
> 				}
> 				c = s[left];
> 				++left;
> 				// 更新window
> 				if (need.count(c)) // c是目标字符
> 				{
> 					window[c]--; // 更新window中的字符统计
> 					if (window[c] != need[c]) // 字符c已经满足了要求
> 					{
> 						--valid;
> 					}
> 				}
> 			}
> 		}
> 		return len == INT_MAX ? "" : s.substr(start, len);
> 	}
> };
> int main()
> {
> 	std::string s { "aaaaaaaaaaaabbbbbcdd" };
> 	std::string t { "abcdd" };
> 	Solution solu;
> 	cout << solu.minWindow(s, t) << endl;
> }
> // g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g
> 
> ```
>
> 对于测试用例:
>
> ```C++
> "aaaaaaaaaaaabbbbbcdd"
> "abcdd"
> ```
>
> 实际输出：
>
> ```C++
> "aaaaaaaaaaaabbbbbcdd"
> ```
>
> 预期结果：
>
> ```C++
> "abbbbbcdd"
> ```
>
> 后来我通过和作者给出的code进行对比，发现差异在于:
>
> 我的:
>
> ```C++
> // 更新window
> 				if (need.count(c)) // c是目标字符
> 				{
> 					window[c]--; // 更新window中的字符统计
> 					if (window[c] != need[c]) // 字符c已经满足了要求
> 					{
> 						--valid;
> 					}
> 				}
> ```
>
> 作者的:
>
> ```C++
>             // 进行窗口内数据的一系列更新
>             if (need.count(d)) {
>                 if (window[d] == need[d])
>                     valid--;
>                 window[d]--;
>             }  
> ```
>
> 再结合这个测试用例，可知问题的症结了:
>
> 由于题目的要求是子串，因此，如果window中，某个字符的个数比need中的字符个数要多，比如对于测试用例:
>
> ```C++
> "aaaaaaaaaaaabbbbbcdd"
> "abcdd"
> ```
>
> 显然，当`valid == need.size()`即需要shrink的时候，window已经包含了整个字符串`"aaaaaaaaaaaabbbbbcdd"`，按照我的写法，只要 `if (window[c] != need[c])` 就 `--valid;` 停止shrink，显然这是犯了逻辑错误，应该是当 `if (window[d] == need[d])`，而此时又要进行shrink，显然会导致不满足条件，要通知shrink；

## 真题二、字符串排列

> NOTE: 
>
> 1、典型的判断是否存在，不需要罗列所有的可能性
>
> 2、要求窗口的长度 和 子串的长度相同、并且窗口包含了子串的时候，则找到了解
>
> 3、LeetCode [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/) 中等
>
> 4、作者给出的解法是比较复杂的，这个问题可以使用更加简单的滑动窗口写法，参见 LeetCode [567. 字符串的排列](https://leetcode-cn.com/problems/permutation-in-string/)  的官方解题给出的写法。下面的程序是不容易理解的。

LeetCode 567 题，Permutation in String，难度 Medium：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_png/gibkIz0MVqdGQlBxOlAet1AXGPoibCzEowmo3G9oN6XDmHeHjGic6tUauwoZia40pxjbicJXtN1RcjMMRDkfcGaVNVg/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

注意哦，输入的`s1`是可以包含重复字符的，所以这个题难度不小。

这种题目，是明显的滑动窗口算法，**相当给你一个`S`和一个`T`，请问你`S`中是否存在一个子串，包含`T`中所有字符且不包含其他字符**？

首先，先复制粘贴之前的算法框架代码，然后明确刚才提出的 4 个问题，即可写出这道题的答案：

```c++
// 判断 s 中是否存在 t 的排列
bool checkInclusion(string t, string s) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    while (right < s.size()) {
        char c = s[right];
        right++;
        // 进行窗口内数据的一系列更新
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c])
                valid++;
        }

        // 判断左侧窗口是否要收缩
        while (right - left >= t.size()) {
            // 在这里判断是否找到了合法的子串
            if (valid == need.size()) // 
                return true;
            char d = s[left];
            left++;
            // 进行窗口内数据的一系列更新
            if (need.count(d)) {
                if (window[d] == need[d])
                    valid--;
                window[d]--;
            }
        }
    }
    // 未找到符合条件的子串
    return false;
}
```

> NOTE: 
>
> 一、上述code 和 LeetCode [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/) 中的code其实差异还是比较大的:
>
> 1、在 LeetCode [76. 最小覆盖子串](https://leetcode-cn.com/problems/minimum-window-substring/) 中，shrink的条件是: `valid == need.size()`，上述code中，shrink的条件是 `right - left >= t.size()`，这样，运行的时候，一旦`right - left == t.size()`，即window的长度和目标字符串的长度相同，它就会执行匹配；它的匹配是非常简单的: 
>
> `valid == need.size()`
>
> 因为此时window的长度 和 目标字符串的长度相同，所以不会有多余的字符串，所以可以直接进行上述比较；
>
> 二、上述程序在下面的测试用例中
>
> ```C++
> "abcdxabcde"
> "abcdeabcdx"
> ```
>
> 

对于这道题的解法代码，基本上和最小覆盖子串一模一样，只需要改变两个地方：

**1、**本题移动`left`缩小窗口的时机是窗口大小大于`t.size()`时，因为排列嘛，显然长度应该是一样的。

**2、**当发现`valid == need.size()`时，就说明窗口中就是一个合法的排列，所以立即返回`true`。

至于如何处理窗口的扩大和缩小，和最小覆盖子串完全相同

## 真题三、找所有字母异位词

> NOTE: 
>
> 1、和前面的字符串排列基本相同
>
> 2、LeetCode [438. 找到字符串中所有字母异位词](https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/) 中等

这是 LeetCode 第 438 题，Find All Anagrams in a String，难度 Medium：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_png/gibkIz0MVqdGQlBxOlAet1AXGPoibCzEowe98rknTABmhPaxgzV5Vv9gHdEpNUDia6CO0gxuPpNR5My6ogK8wuibTQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

呵呵，这个所谓的字母异位词，不就是排列吗，搞个高端的说法就能糊弄人了吗？**相当于，输入一个串`S`，一个串`T`，找到`S`中所有`T`的排列，返回它们的起始索引**。

直接默写一下框架，明确刚才讲的 4 个问题，即可秒杀这道题：

```C++
vector<int> findAnagrams(string s, string t) {
    unordered_map<char, int> need, window;
    for (char c : t) need[c]++;

    int left = 0, right = 0;
    int valid = 0;
    vector<int> res; // 记录结果
    while (right < s.size()) {
        char c = s[right];
        right++;
        // 进行窗口内数据的一系列更新
        if (need.count(c)) {
            window[c]++;
            if (window[c] == need[c]) 
                valid++;
        }
        // 判断左侧窗口是否要收缩
        while (right - left >= t.size()) {
            // 当窗口符合条件时，把起始索引加入 res
            if (valid == need.size())
                res.push_back(left);
            char d = s[left];
            left++;
            // 进行窗口内数据的一系列更新
            if (need.count(d)) {
                if (window[d] == need[d])
                    valid--;
                window[d]--;
            }
        }
    }
    return res;
}
```

跟寻找字符串的排列一样，只是找到一个合法异位词（排列）之后将起始索引加入`res`即可。

## 真题四、最长无重复子串

> NOTE: 
>
> 1、当窗口中，没有重复字符的时候，进行expand，当存在重复字符的时候，进行shrink
>
> 2、如何判断是否有重复字符呢？使用hash table in？
>
> 看了下面的实现，它使用的是字符个数大于0，显然它是充分利用`window`--关于窗口内情况的统计。
>
> 3、leetcode [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) 中等

这是 LeetCode 第 3 题，Longest Substring Without Repeating Characters，难度 Medium：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_png/gibkIz0MVqdGQlBxOlAet1AXGPoibCzEowdOEyLaTVTiabiabMHr2Z7SzZZ08fxMDZt4uzzRcfvoI7sJzfdORvH0tA/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

这个题终于有了点新意，不是一套框架就出答案，不过反而更简单了，稍微改一改框架就行了：

```C++
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;

    int left = 0, right = 0;
    int res = 0; // 记录结果
    while (right < s.size()) {
        char c = s[right];
        right++;
        // 进行窗口内数据的一系列更新
        window[c]++;
        // 判断左侧窗口是否要收缩
        while (window[c] > 1) {
            char d = s[left];
            left++;
            // 进行窗口内数据的一系列更新
            window[d]--;
        }
        // 在这里更新答案
        res = max(res, right - left);
    }
    return res;
}
```

这就是变简单了，连`need`和`valid`都不需要，而且更新窗口内数据也只需要简单的更新计数器`window`即可。

当`window[c]`值大于 1 时，说明窗口中存在重复字符，不符合条件，就该移动`left`缩小窗口了嘛。

唯一需要注意的是，在哪里更新结果`res`呢？我们要的是最长无重复子串，哪一个阶段可以保证窗口中的字符串是没有重复的呢？

这里和之前不一样，**要在收缩窗口完成后更新`res`**，因为窗口收缩的 while 条件是存在重复元素，换句话说收缩完成后一定保证窗口中没有重复嘛。