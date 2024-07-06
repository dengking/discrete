# LeetCode-DFA

KMP

DFA

Regex



## 核心思想

- 在 [LeetCode-8. 字符串转换整数 (atoi)](https://leetcode.cn/problems/string-to-integer-atoi/)  # [官方解题](https://leetcode.cn/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/) 中，[Edward Elric](https://leetcode.cn/u/zdxiq125/) 有如下评论:

  >  准确地说，这是**确定有限状态机**（deterministic finite automaton, DFA）。其实这题已经不算是容易写“出臃肿代码”的了。考虑清楚边界（主要是溢出处理）和输入种类（+, -, 0-9以及其他），大概在20行内完成代码不难。说实话LC官方题解里很少见给出标准**DFA**解法的，点个赞。另外看到评论区乌烟瘴气的，真让人唏嘘（没有一点基本的敬畏心、浮躁功利、认为题目边界太复杂导致自己不能AC，那是何其自负）。给两个更加需要DFA的题目吧：[utf-8-validation](https://leetcode.cn/problems/utf-8-validation/) ( [附dfa解法](https://leetcode.cn/problems/utf-8-validation/solution/java-dfa-by-zdxiq125/) ) 以及 [valid-number](https://leetcode.cn/problems/valid-number/)



- 在 [LeetCode-65. 有效数字](https://leetcode.cn/problems/valid-number/) # [表驱动法](https://leetcode.cn/problems/valid-number/solution/biao-qu-dong-fa-by-user8973/) 中有如下描述:

  > 本题可以采用《编译原理》里面的**确定的有限状态机**（DFA）解决。构造一个DFA并实现，构造方法可以先写**正则表达式**，然后转为 DFA，也可以直接写，我就是直接写的，虽然大概率不会是最简结构（具体请参考《编译器原理》图灵出版社），不过不影响解题。**DFA** 作为确定的有限状态机，比 NFA 更加实用，因为对于每一个状态接收的下一个字符，DFA 能确定唯一一条转换路径，所以使用简单的**表驱动**的一些方法就可以实现，并且只需要读一遍输入流，比起 NFA 需要回读在速度上会有所提升。
  >



核心思想: 使用regex描述抽象结构，然后使用DFA进行实现。DFA本质上是graph，匹配的过程是沿着path进行，只要匹配了一个path，则表示复合pattern。

## Implementation: table-driven parse

"table-driven parse" 即 "表驱动法"，它是基于DFA parse的一种常见实现方式，在 [LeetCode-65. 有效数字](https://leetcode.cn/problems/valid-number/) # [表驱动法](https://leetcode.cn/problems/valid-number/solution/biao-qu-dong-fa-by-user8973/) 中提及。

DFA是一个graph，DFA的构成: 

1. 输入的种类; 从输入的种类入手是最快的，思考在各种输入的情况下，状态如何进行转换
2. 节点: 状态，每个节点都需要考虑在各种输入种类下的转换
3. edge: 状态的转换，表示从当前节点（状态）转移到的目标节点（状态） 

"表驱动法"首先要解决的问题是如何存储DFA。它的实现方式是**二维表**，这个**二维表**记录每个**节点(状态)**在每个输入种类下的转移到的**目标节点(状态)**。



**二维表**有如下实现方式：

| C++                                                          | Python |
| ------------------------------------------------------------ | ------ |
| `std::vector<std::vector<std::string>>`                      |        |
| `std::vector<std::unordered_map<std::string, std::string>>`  |        |
| `std::unordered_map<std::string, std::unordered_map<std::string, std::string>>` |        |

更加具体来说：

1. 如果**状态**、**输入种类**使用的是非integer类型表示，则不能够使用vector，而应该使用hash map来进行实现
2. 如果**状态**、**输入种类**使用的是integer类型表示，则能够使用vector

### 结果判断

1、最终状态是**接受状态**，需要注意的是，**接受状态**可以有多个，有的状态是既可以作为**接受状态**也可以作为**非接受状态**，典型的例子就是[LeetCode-65. 有效数字](https://leetcode.cn/problems/valid-number/) 。

2、输入数据被消耗完了，如果数据没有消耗完，则显然是不符合格式要求的。

3、对于存在性问题，如果当前状态在当前输入下没有转换，则说明不合法，可以直接拒绝掉



## LeetCode

| LeetCode                                                     |          |
| ------------------------------------------------------------ | -------- |
| [LeetCode 8 字符串转换整数 (atoi) # 官方解题](https://leetcode.cn/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/) |          |
| [LeetCode-65. 有效数字](https://leetcode.cn/problems/valid-number/) # [官方解题](https://leetcode.cn/problems/valid-number/solution/you-xiao-shu-zi-by-leetcode-solution-298l/) | 判断类型 |
| [LeetCode 393. UTF-8 编码验证](https://leetcode.cn/problems/utf-8-validation/) # [Edward Elric](https://leetcode.cn/u/zdxiq125/) # [[Java] DFA](https://leetcode.cn/problems/utf-8-validation/solution/java-dfa-by-zdxiq125/) | 判断类型 |
| [LeetCode-1839. 所有元音按顺序排布的最长子字符串](https://leetcode.cn/problems/longest-substring-of-all-vowels-in-order/) # [官方解题](https://leetcode.cn/problems/longest-substring-of-all-vowels-in-order/solutions/742722/suo-you-yuan-yin-an-shun-xu-pai-bu-de-zu-9wqg/) |          |



## [LeetCode 8 字符串转换整数 (atoi)-中等](https://leetcode.cn/problems/string-to-integer-atoi/description/) 

`regex=[ ]*[+-]*[0-9]+`，DFA如下：

![fig1](./LeetCode-8-DFA.png)

DFA的二维table如下：

|               | ' '   | +/-    | number    | other |
| ------------- | ----- | ------ | --------- | ----- |
| **start**     | start | signed | in_number | end   |
| **signed**    | end   | end    | in_number | end   |
| **in_number** | end   | end    | in_number | end   |
| **end**       | end   | end    | end       | end   |



```C++
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class Automaton
{
    string state = "start"; // 当前所处的状态
    // DFA
    unordered_map<string, vector<string>> table = {
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}} //
    };
    /**
     * @brief 获得字符 c 所属的类别，对应的是列
     *
     * @param c
     * @return int
     */
    int get_col(char c)
    {
        if (isspace(c))
            return 0;
        if (c == '+' or c == '-')
            return 1;
        if (isdigit(c))
            return 2;
        return 3;
    }

public:
    int sign = 1;
    long long ans = 0;
    /// @brief 转移
    /// @param c
    void transition(char c)
    {
        state = table[state][get_col(c)]; // 下一个状态由当前所处状态 + 当前的输入决定的
        if (state == "in_number")
        {
            ans = ans * 10 + c - '0';
            // 需要注意: -(long long)INT_MIN 是一个正数，因为此时ans没有加上符号，一直是正数
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
        {
            sign = c == '+' ? 1 : -1;
        }
    }
};

class Solution
{
public:
    int myAtoi(string str)
    {
        Automaton automaton;
        for (char c : str)
            automaton.transition(c);
        return automaton.sign * automaton.ans;
    }
};

int main()
{
    Solution s;
}
```



## [LeetCode-65. 有效数字-困难](https://leetcode.cn/problems/valid-number/) 

在 [LeetCode 8 字符串转换整数 (atoi)-中等](https://leetcode.cn/problems/string-to-integer-atoi/description/) 的基础上增加了难度

regex: 

```
(+|-)?([0-9]+)?(\.(+|-)?[0-9]+)?((e|E)?[0-9]+)?
```

划分为:

- 符号位

- 整数部分
- 小数部分
- 指数部分

将输入进行分类:

- 符号字符（`'+'` 或 `'-'`）

- `'e'` 或 `'E'` 

- `.`

- 数字 `[0-9]`

- 其他字符

参考:

- [LeetCode-65. 有效数字](https://leetcode.cn/problems/valid-number/) # [表驱动法](https://leetcode.cn/problems/valid-number/solution/biao-qu-dong-fa-by-user8973/) 
- [LeetCode-65. 有效数字](https://leetcode.cn/problems/valid-number/) # [官方解题](https://leetcode.cn/problems/valid-number/solution/you-xiao-shu-zi-by-leetcode-solution-298l/) 



### DFA+table-driven-parse

![fig1](./LeetCode-65-DFA.png)

> 源自: [LeetCode-65. 有效数字](https://leetcode.cn/problems/valid-number/) # [官方解题](https://leetcode.cn/problems/valid-number/solution/you-xiao-shu-zi-by-leetcode-solution-298l/) 

一. 上述DFA中有两个"小数点"状态：

- 小数点(左无整数)

- 小数点(左有整数)

两者的差异在于"小数点(左无整数)"是**非接收状态**，"小数点(左有整数)"是**接收状态**，必须要进行严格区分，否则无法进行判断。

这提示我们，为了能够cover所有的状态，需要进行扩充

二. edge corner case

这个题目的corner case就是`"4."`

这种corner case其实是出题人为了增加题目的难度，其实main case就已经cover来大部分的情况了。

上述基于DFA的方式是非常容易扩充的



#### C++

```C++
// #include <bits/stdc++.h>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    enum State {
        STATE_INITIAL,           // 初始状态
        STATE_INT_SIGN,          // 符号位
        STATE_INTEGER,           // 整数部分
        STATE_POINT,             // 小数点(左有整数)
        STATE_POINT_WITHOUT_INT, // 小数点(左无整数)
        STATE_FRACTION,          // 小数部分
        STATE_EXP,               // 字符e、指数部分
        STATE_EXP_SIGN,          // 指数符号
        STATE_EXP_NUMBER,        // 指数数字
        STATE_END
    };

    enum CharType {
        CHAR_NUMBER, // 数字
        CHAR_EXP,    // e E
        CHAR_POINT,  // 小数点
        CHAR_SIGN,   // 符号位
        CHAR_ILLEGAL
    };

    CharType toCharType(char ch) {
        if (ch >= '0' && ch <= '9') {
            return CHAR_NUMBER;
        } else if (ch == 'e' || ch == 'E') {
            return CHAR_EXP;
        } else if (ch == '.') {
            return CHAR_POINT;
        } else if (ch == '+' || ch == '-') {
            return CHAR_SIGN;
        } else {
            return CHAR_ILLEGAL;
        }
    }

    bool isNumber(string s) {
        // tag-hybrid-ds-[graph-weighted-directed]=DFA-[adjacency-list]=[2D-dict=map]=[std-unordered_map-of-std-unordered_map]
        unordered_map<State, unordered_map<CharType, State>> transfer{
                {STATE_INITIAL,           {{CHAR_NUMBER, STATE_INTEGER},    {CHAR_POINT, STATE_POINT_WITHOUT_INT}, {CHAR_SIGN,  STATE_INT_SIGN}}}, //
                {STATE_INT_SIGN,          {{CHAR_NUMBER, STATE_INTEGER},    {CHAR_POINT, STATE_POINT_WITHOUT_INT}}},                             //
                {STATE_INTEGER,           {{CHAR_NUMBER, STATE_INTEGER},    {CHAR_EXP,   STATE_EXP},               {CHAR_POINT, STATE_POINT}}},                   //
                {STATE_POINT,             {{CHAR_NUMBER, STATE_FRACTION},   {CHAR_EXP,   STATE_EXP}}},                                               //
                {STATE_POINT_WITHOUT_INT, {{CHAR_NUMBER, STATE_FRACTION}}},                                                          //
                {STATE_FRACTION,          {{CHAR_NUMBER, STATE_FRACTION},   {CHAR_EXP,   STATE_EXP}}},                                            //
                {STATE_EXP,               {{CHAR_NUMBER, STATE_EXP_NUMBER}, {CHAR_SIGN,  STATE_EXP_SIGN}}},                                         //
                {STATE_EXP_SIGN,          {{CHAR_NUMBER, STATE_EXP_NUMBER}}},                                                                 //
                {STATE_EXP_NUMBER,        {{CHAR_NUMBER, STATE_EXP_NUMBER}}}                                                                //
        };

        int len = s.length();
        State st = STATE_INITIAL;

        for (int i = 0; i < len; i++) {
            CharType typ = toCharType(s[i]);
            if (transfer[st].find(typ) == transfer[st].end()) {
                return false;
            } else {
                st = transfer[st][typ];
            }
        }
        return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER ||
               st == STATE_END;
    }
};

int main() {
    Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```



#### Python

```python
from enum import Enum, auto


class State(Enum):
    Init = auto()  # 初始状态
    IntSign = auto()  # 符号位
    Int = auto()  # 整数部分
    Point = auto()  # 小数点(左有整数)
    PointWithoutInt = auto()  # 小数点(左无整数)
    Fraction = auto()  # 小数部分
    Exp = auto()  # 字符e、指数部分
    ExpSign = auto()  # 指数符号
    ExpNumber = auto()  # 指数数字
    End = auto()  # 结束状态


class CharType(Enum):
    Number = auto()  # 数字
    Exp = auto()  # e E
    Point = auto()  # 小数点
    Sign = auto()  # 符号位
    Illegal = auto()  # 非法符号


class Solution:

    def isNumber(self, s: str) -> bool:
        transfer = {
            State.Init: {
                CharType.Number: State.Int,
                CharType.Point: State.PointWithoutInt,
            }
        }

```



## [LeetCode-393. UTF-8 编码验证](https://leetcode.cn/problems/utf-8-validation/) # [Edward Elric](https://leetcode.cn/u/zdxiq125/) # [[Java] DFA](https://leetcode.cn/problems/utf-8-validation/solution/java-dfa-by-zdxiq125/) 



![image_1580299754.png](./LeetCode-393-DFA.png)



|           | `0xxxxxxx` | `110xxxxx` | `1110xxxx` | `11110xxx` | `10xxxxxx` |
| --------- | ---------- | ---------- | ---------- | ---------- | ---------- |
| **start** | end        | 1          | 2          | 3          | end        |
| **1**     | end        | end        | end        | end        | end        |
| **2**     |            |            |            |            | 4          |
| **3**     |            |            |            |            | 5          |
| **4**     |            |            |            |            | end        |
| **5**     |            |            |            |            | 6          |
| **6**     |            |            |            |            | end        |





## DFA的局限性

DFA对应的是regex，它是线性的，它无法处理带括号的nesting关系，典型例子：

1、 [leetcode 字符串转换整数 (atoi) # 官方解题](https://leetcode.cn/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/) ，其实题目中情况是可以使用regex进行描述的:

```
[ ]*[-+]?[0-9]*
```

