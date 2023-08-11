# [LeetCode-10. Regular Expression Matching-hard](https://leetcode.cn/problems/regular-expression-matching/)



一、epsilon transition保证能够找到所有的可能性。

````
/**
* 在匹配完成后，如果node有epsilon transition，则不断执行epsilon transition
* 一、因为可能出现字符串比pattern短的情况，比如:
* s = "a"
* p = "ab*"
* 二、最后的"c*a*"都不在匹配
* s = "cbaacacaaccbaabcb"
* p = "c*b*b*.*ac*.*bc*a*"
*/
````

二、DFA VS NFA

```
/**
 * 1、处理诸如 "a*a" 的case，这种case是本程序不支持的形式，因为本程序是DFA，而这种case在一个状态下，从"a"有两种transition，
 * 本程序的做法是将它转换为 "a+" 的形式
 * 2、"a*a*" => "a*"
 */
```



在 BFA 的写法中，是通过分别调用 epsilon transition 和 character transition 来实现存储 DFA 是会出现的类似上述的问题

三、我之前的DFA的写法如下:

```
    bool dfsDFA(const string &s, int i, Node *&node)
    {
         char c = s[i];
    }
```



对比 LeetCode [六硝基六氮杂三环十四](https://leetcode.cn/u/liu-xiao-ji-liu-dan-za-san-huan-shi-si-wan-dui-er-fu-zan/) [10、 正则表达式匹配：有限自动机（FA）算法](https://leetcode.cn/problems/regular-expression-matching/solutions/1532116/10-zheng-ze-biao-da-shi-pi-pei-by-liu-xi-wi4p/) 中的写法，是可以不消耗字符，直接通过 epsilon transition 进行转换，我之前的写法没有加入这种 transition，所以无法穷举所有的可能性。

