# Brute-force search

## wikipedia [Brute-force search](https://en.wikipedia.org/wiki/Brute-force_search)



## 素材

### [我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA)

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