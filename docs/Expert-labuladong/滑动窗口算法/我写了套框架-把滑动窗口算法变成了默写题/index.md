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

**其实困扰大家的，不是算法的思路，而是各种细节问题**。比如说如何向窗口中添加新元素，如何缩小窗口，在窗口滑动的哪个阶段更新结果。即便你明白了这些细节，也容易出 bug，找 bug 还不知道怎么找，真的挺让人心烦的。

## 代码框架

**所以今天我就写一套滑动窗口算法的代码框架，我连在哪里做输出 debug 都给你写好了，以后遇到相关的问题，你就默写出来如下框架然后改三个地方就行，还不会出边界问题**：

```c++
/* 滑动窗口算法框架 */
void slidingWindow(string s, string t) {
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

**其中两处`...`表示的更新窗口数据的地方，到时候你直接往里面填就行了**。

而且，这两个`...`处的操作分别是右移和左移窗口更新操作，等会你会发现它们操作是完全对称的。

## 真题

言归正传，**下面就直接上四道LeetCode 原题来套这个框架**，其中第一道题会详细说明其原理，后面四道就直接闭眼睛秒杀了。

本文代码为 C++ 实现，不会用到什么编程方面的奇技淫巧，但是还是简单介绍一下一些用到的数据结构，以免有的读者因为语言的细节问题阻碍对算法思想的理解：

`unordered_map`就是哈希表（字典），它的一个方法`count(key)`相当于 Java 的`containsKey(key)`可以判断键 key 是否存在。

可以使用方括号访问键对应的值`map[key]`。需要注意的是，如果该`key`不存在，C++ 会自动创建这个 key，并把`map[key]`赋值为 0。

所以代码中多次出现的`map[key]++`相当于 Java 的`map.put(key, map.getOrDefault(key, 0) + 1)`。

### 一、最小覆盖子串

> NOTE: 
>
> 1、典型的需要找到最优解，而不是一个解，因此需要罗列所有的可能性

LeetCode 76 题，Minimum Window Substring，难度 **Hard**，我带大家看看它到底有多 **Hard**：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_png/gibkIz0MVqdGQlBxOlAet1AXGPoibCzEowk6hiaxmGN6ibHiaTqxHMqYvCRA4lWuRCQicPSfZY78De1GmwkXviar4psjw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

就是说要在`S`(source) 中找到包含`T`(target) 中全部字母的一个子串，且这个子串一定是所有可能子串中最短的。

如果我们使用暴力解法，代码大概是这样的：

```
for (int i = 0; i < s.size(); i++)
    for (int j = i + 1; j < s.size(); j++)
        if s[i:j] 包含 t 的所有字母:
            更新答案
```

思路很直接，但是显然，这个算法的复杂度肯定大于 O(N^2) 了，不好。

#### 滑动窗口算法的思路是这样：

***1、***我们在字符串`S`中使用双指针中的左右指针技巧，初始化`left = right = 0`，**把索引左闭右开区间`[left, right)`称为一个「窗口」**。

***2、***我们先不断地增加`right`指针扩大窗口`[left, right)`，直到窗口中的字符串符合要求（包含了`T`中的所有字符）。

***3、***此时，我们停止增加`right`，转而不断增加`left`指针缩小窗口`[left, right)`，直到窗口中的字符串不再符合要求（不包含`T`中的所有字符了）。同时，每次增加`left`，我们都要更新一轮结果。

> NOTE: 
>
> 缩小窗口，优化解

***4、***重复第 2 和第 3 步，直到`right`到达字符串`S`的尽头。

这个思路其实也不难，**第 2 步相当于在寻找一个「可行解」，然后第 3 步在优化这个「可行解」，最终找到最优解，**也就是最短的覆盖子串。左右指针轮流前进，窗口大小增增减减，窗口不断向右滑动，这就是「滑动窗口」这个名字的来历。

下面画图理解一下，`needs`和`window`相当于计数器，分别记录`T`中字符出现次数和「窗口」中的相应字符的出现次数。

初始状态：

![图片](https://mmbiz.qpic.cn/sz_mmbiz_png/gibkIz0MVqdGQlBxOlAet1AXGPoibCzEow6FwvAvsZKyCTCtrmLcvKDxhYAJEqI36cAZxfoIWLFibEhmz9IfHf24Q/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)