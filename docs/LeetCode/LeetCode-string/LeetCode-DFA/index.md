# LeetCode-DFA



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



### [LeetCode 8 字符串转换整数 (atoi)-中等](https://leetcode.cn/problems/string-to-integer-atoi/description/)

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



### [LeetCode-393. UTF-8 编码验证](https://leetcode.cn/problems/utf-8-validation/) # [Edward Elric](https://leetcode.cn/u/zdxiq125/) # [[Java] DFA](https://leetcode.cn/problems/utf-8-validation/solution/java-dfa-by-zdxiq125/) 



![image_1580299754.png](https://pic.leetcode.cn/c10666acd2caef8235c204a12941fd74d87fd4ffb39ed747d35eaaf1f69772f6-image_1580299754.png)



|           | `0xxxxxxx` | `110xxxxx` | `1110xxxx` | `11110xxx` | `10xxxxxx` |
| --------- | ---------- | ---------- | ---------- | ---------- | ---------- |
| **start** | end        | 1          | 2          | 3          | end        |
| **1**     | end        | end        | end        | end        | end        |
| **2**     |            |            |            |            | 4          |
| **3**     |            |            |            |            | 5          |
| **4**     |            |            |            |            | end        |
| **5**     |            |            |            |            | 6          |
| **6**     |            |            |            |            | end        |



### [LeetCode-65. 有效数字](https://leetcode.cn/problems/valid-number/) # [官方解题](https://leetcode.cn/problems/valid-number/solution/you-xiao-shu-zi-by-leetcode-solution-298l/)







## DFA的局限性

DFA对应的是regex，它是线性的，它无法处理带括号的nesting关系，典型例子：

1、 [leetcode 字符串转换整数 (atoi) # 官方解题](https://leetcode.cn/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/) ，其实题目中情况是可以使用regex进行描述的:

```
[ ]*[-+]?[0-9]*
```

