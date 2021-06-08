# labuladong [二分查找的妙用：判定子序列](https://mp.weixin.qq.com/s/hWi2hTrQewL_YKioGkXQJg)

> NOTE: 
>
> 一、需要注意的是:  子序列是需要保证相对位置的
>
> 二、本文描述的思路和KMP的思想是有些类似的: 预处理字符串来加速匹配；
>
> 本文的预处理方式是: 建立字符到位置的映射，可以快速地根据字符找到它的所有的位置，然后在它的所有位置中，进行二分查找。
>
> 显然，这种方式对于大批量的匹配是非常有价值的
>
> 

二分查找本身不难理解，难在巧妙地运用二分查找技巧。对于一个问题，你可能都很难想到它跟二分查找有关，比如前文 [最长递增子序列](http://mp.weixin.qq.com/s?__biz=MzU0MDg5OTYyOQ==&mid=2247484232&idx=1&sn=21234a9e4db908f438e1cb2e8c7ffff4&chksm=fb33630acc44ea1c91027bff20e9902e20e4269d54f3c178dc1e07f344d48d7ff1a4ca48ba39&scene=21#wechat_redirect) 就借助一个纸牌游戏衍生出二分查找解法。

今天再讲一道巧用二分查找的算法问题：如何判定字符串`s`是否是字符串`t`的子序列（可以假定`s`长度比较小，且`t`的长度非常大）。

> NOTE: 
>
> `t`的长度比较大，意味着可能需要花费更多的时间进行匹配

举两个例子：

s = "abc", t = "**a**h**b**gd**c**", return true.

s = "axc", t = "ahbgdc", return false.

题目很容易理解，而且看起来很简单，但很难想到这个问题跟二分查找有关吧？



## 一、问题分析

> NOTE: 
>
> LeetCode [392. 判断子序列](https://leetcode-cn.com/problems/is-subsequence/) 简单

### 双指针

首先，一个很简单的解法是这样的：

```C++
bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
        if (s[i] == t[j]) i++;
        j++;
    }
    return i == s.size();
}
```

其思路也非常简单，利用双指针`i, j`分别指向`s, t`，一边前进一边匹配子序列：

![图片](https://mmbiz.qpic.cn/mmbiz_gif/map09icNxZ4mnbVC00EzwNpKWVLic67v8fp4AviccRT7S8XlynThhhyUxhB2X63YwDSCyq2ZWcGo6cQS0HhxKiaziaQ/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1)

读者也许会问，这不就是最优解法了吗，时间复杂度只需 O(N)，N 为`t`的长度。

### Follow up

是的，如果仅仅是这个问题，这个解法就够好了，**不过这个问题还有 follow up**：

如果给你一系列字符串`s1,s2,...`和字符串`t`，你需要判定每个串`s`是否是`t`的子序列（可以假定`s`相对较短，`t`很长）。

```Java
boolean[] isSubsequence(String[] sn, String t);
```

你也许会问，这不是很简单吗，还是刚才的逻辑，加个 for 循环不就行了？

可以，但是此解法处理每个`s`时间复杂度仍然是 O(N)，而如果巧妙运用二分查找，可以将时间复杂度降低，大约是 O(MlogN)，M 为 s 的长度。由于 N 相对 M 大很多，所以后者效率会更高。

## 二、二分思路

二分思路主要是对`t`进行预处理，用一个字典`index`将每个字符出现的索引位置按顺序存储下来（对于 ASCII 字符，可以用大小为 256 的数组充当字典）：

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4kgs1l9MrcAfJI2cWHicmeQ23qGGL5lhSWujKicYK9hrS4KpkRichZmkhGgaibN1wZdibcc16tlXIk4OCQ/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/map09icNxZ4mnbVC00EzwNpKWVLic67v8fDxiaDiaM0k6eykBn75gbkQibF4Q31etH3Pqr8Ed0UN7bvvyXmWKXfewnQ/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

比如对于这个情况，匹配了 "ab"，应该匹配 "c" 了：

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/map09icNxZ4mnbVC00EzwNpKWVLic67v8fDib0nUdqLOlGhic4U5bCLZZDpd04c1Y3PT2Y2bfRf7fbBauiabyI4Vg0g/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

按照之前的解法，我们需要`j`线性前进扫描字符 "c"。但现在借助`index`中记录的信息，**可以二分搜索`index[c]`中比 j 大的那个索引**，在上图的例子中，就是在`[0,2,6]`中搜索比 4 大的那个索引：

![图片](https://mmbiz.qpic.cn/mmbiz_jpg/map09icNxZ4mnbVC00EzwNpKWVLic67v8feHfGzevvxqKzdVxZUcia0vSOZZDrGhIlDaC7LP1WdhjxcdribFGYTyvQ/640?wx_fmt=jpeg&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

这样就可以快速得到下一个 "c" 的索引 6。现在的问题就是，如何用二分查找计算那个恰好比 4 大的索引呢？答案是，寻找左侧边界的二分搜索就可以做到。

## 三、再谈二分查找

在前文 [二分查找算法详解](http://mp.weixin.qq.com/s?__biz=MzU0MDg5OTYyOQ==&mid=2247484090&idx=1&sn=5635cf1c4fd8a8570b63c7ae9b4304c2&chksm=fb3362f8cc44ebee0a19a4cfba7f2e13923e05f47e15f2e99a1f42b01aeee83b946aceac3d4c&scene=21#wechat_redirect) 中，详解了如何正确写出三种二分查找算法的细节。二分查找返回目标值`val`的索引，对于搜索**左侧边界**的二分查找，有一个特殊性质：

**当`val`不存在时，得到的索引恰好是比`val`大的最小元素索引**。

什么意思呢，就是说如果在数组`[0,1,3,4]`中搜索元素 2，算法会返回索引 2，也就是元素 3 的位置，元素 3 就是数组中大于 2 的最小元素。所以我们可以利用二分搜索避免线性扫描。

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4kgs1l9MrcAfJI2cWHicmeQ2RC2TvWKdHDXNA2DLdTC3Isibt1XkSJmN5fviaIywQ3IFdbWTzdlbic6Iw/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

以上就是搜索**左侧边界**的**二分查找**，等会儿会用到，其中的细节可以参见 [二分查找算法详解](http://mp.weixin.qq.com/s?__biz=MzU0MDg5OTYyOQ==&mid=2247484090&idx=1&sn=5635cf1c4fd8a8570b63c7ae9b4304c2&chksm=fb3362f8cc44ebee0a19a4cfba7f2e13923e05f47e15f2e99a1f42b01aeee83b946aceac3d4c&scene=21#wechat_redirect)，这里不再赘述。

> NOTE: 
>
> 在`arr`中，找到大于等于`tar`的最小值。
>
> 如果`arr`中不存在`tar`，则上述函数的返回值，即`left`为:
>
> 1、`hi`，即`tar`比`arr`中的所有的元素都大
>
> 2、



## 四、代码实现

这里以处理单个字符串`s`为例，对于多个字符串`s`，把预处理部分单独抽出来即可。

![图片](https://mmbiz.qpic.cn/mmbiz_png/map09icNxZ4mnbVC00EzwNpKWVLic67v8fmpribXsLDBIR06WYFvJFsN9mNyNRyxGMJQYgwRkicxg3Vaiba7LeLIp9Q/640?wx_fmt=png&tp=webp&wxfrom=5&wx_lazy=1&wx_co=1)

算法执行的过程是这样的：

![图片](https://mmbiz.qpic.cn/mmbiz_gif/map09icNxZ4kgs1l9MrcAfJI2cWHicmeQ2vYLPqePH28go8Hoc69qBNHk8eYucunvgAciaKRiaGpgGKJOHupJevPpg/640?wx_fmt=gif&tp=webp&wxfrom=5&wx_lazy=1)

可见借助二分查找，算法的效率是可以大幅提升的：预处理时需要 O(N) 时间，每次匹配子序列的时间是 O(MlogN)，比之前每次匹配都要 O(N) 的时间要高效得多。

当然，如果只需要判断一个 s 是否是 t 的子序列，是不需要二分查找的，一开始的 O(N) 解法就是最好的，因为虽然二分查找解法处理每个 s 只需要 O(MlogN)，但是还需要 O(N) 时间构造 index 字典预处理，所以处理单个 s 时没有必要。

以上就是二分查找技巧判定子序列的全部内容，希望你能有所收获。