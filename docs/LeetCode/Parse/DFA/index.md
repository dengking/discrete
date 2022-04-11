# DFA parse

在 LeetCode [8. 字符串转换整数 (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/)  # [官方解题](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/) 中，[Edward Elric](https://leetcode-cn.com/u/zdxiq125/) 有如下评论:

> 准确地说，这是确定有限状态机（deterministic finite automaton, DFA）。其实这题已经不算是容易写“出臃肿代码”的了。考虑清楚边界（主要是溢出处理）和输入种类（+, -, 0-9以及其他），大概在20行内完成代码不难。说实话LC官方题解里很少见给出标准DFA解法的，点个赞。另外看到评论区乌烟瘴气的，真让人唏嘘（没有一点基本的敬畏心、浮躁功利、认为题目边界太复杂导致自己不能AC，那是何其自负）。给两个更加需要DFA的题目吧：[utf-8-validation](https://leetcode-cn.com/problems/utf-8-validation/) ( [附dfa解法](https://leetcode-cn.com/problems/utf-8-validation/solution/java-dfa-by-zdxiq125/) ) 以及 [valid-number](https://leetcode-cn.com/problems/valid-number/)

 这让我发现了DFA在LeetCode中的应用，下面是相关试题:

1、LeetCode [8. 字符串转换整数 (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/)  中等

2、LeetCode [393. UTF-8 编码验证](https://leetcode-cn.com/problems/utf-8-validation/) 中等

3、LeetCode [65. 有效数字](https://leetcode-cn.com/problems/valid-number/) 困难



## 核心思想

1、使用regex描述抽象结构，然后使用DFA进行实现。

2、和trie一样，匹配的过程是验证path进行，只要匹配了一个path，则表示复合pattern

3、DFA需要有programmer来抽象出regex，而trie则不需要



## 分析 与 实现

### 实现方式：二维table

DFA是一个graph，DFA的构成: 

一、输入的种类

从输入的种类入手是最快的，思考在各种输入的情况下，状态如何进行转换

二、节点: 状态，每个节点都需要考虑在所有的输入种类下的转换

三、edge: 状态的转换，表示从当前节点（状态）转移到的目标节点（状态） 

二维table

通过前面的例子和总结可以知道，DFA的实现其实就是要实现一个**二维table**，这个二维table记录每个节点（状态）在每个输入种类下的转移到的目标状态。

更加具体来说：

1、如果**状态**、**输入种类**使用的是非integer类型表示，则不能够使用vector，而应该使用hash map来进行实现

2、如果**状态**、**输入种类**使用的是integer类型表示，则能够使用vector

有如下实现方式：

1、`std::vector<std::vector<std::string>>`

2、`std::vector<std::unordered_map<std::string, std::string>>`

3、`std::unordered_map<std::string, std::unordered_map<std::string, std::string>>`



### 结果判断

1、最终状态是**接受状态**，需要注意的是，**接受状态**可以有多个，有的状态是既可以作为**接受状态**也可以作为**非接受状态**，典型的例子就是leetcode [65. 有效数字](https://leetcode-cn.com/problems/valid-number/) 。

2、输入数据被消耗完了，如果数据没有消耗完，则显然是不符合格式要求的。

3、对于存在性问题，如果当前状态在当前输入下没有转换，则说明不合法，可以直接拒绝掉

### table-driven parse

基于DFA的parse的implementation就是table-driven parse，这在下面的文章中描述了：

1、LeetCode [65. 有效数字](https://leetcode-cn.com/problems/valid-number/) # [表驱动法](https://leetcode-cn.com/problems/valid-number/solution/biao-qu-dong-fa-by-user8973/) 



### DFA的局限性

DFA对应的是regex，它是线性的，它无法处理带括号的nesting关系，典型例子：

1、 [leetcode 字符串转换整数 (atoi) # 官方解题](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/) ，其实题目中情况是可以使用regex进行描述的:

```
[ ]*[-+]?[0-9]*
```





## Example

|                                                              |          |      |      |      |
| ------------------------------------------------------------ | -------- | ---- | ---- | ---- |
| [LeetCode 8 字符串转换整数 (atoi) # 官方解题](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/) |          |      |      |      |
| [LeetCode 393. UTF-8 编码验证](https://leetcode-cn.com/problems/utf-8-validation/) # [Edward Elric](https://leetcode-cn.com/u/zdxiq125/) # [[Java] DFA](https://leetcode-cn.com/problems/utf-8-validation/solution/java-dfa-by-zdxiq125/) | 判断类型 |      |      |      |
| LeetCode [65. 有效数字](https://leetcode-cn.com/problems/valid-number/) # [官方解题](https://leetcode-cn.com/problems/valid-number/solution/you-xiao-shu-zi-by-leetcode-solution-298l/) | 判断类型 |      |      |      |



### [LeetCode 8 字符串转换整数 (atoi) # 官方解题](https://leetcode-cn.com/problems/string-to-integer-atoi/solution/zi-fu-chuan-zhuan-huan-zheng-shu-atoi-by-leetcode-/)

本题可以建立如下图所示的自动机：

![fig1](https://assets.leetcode-cn.com/solution-static/8/fig1.png)

> NOTE:
>
> 难点在于需要根据题目的意思抽象出上述DFA。

|               | ' '   | +/-    | number    | other |
| ------------- | ----- | ------ | --------- | ----- |
| **start**     | start | signed | in_number | end   |
| **signed**    | end   | end    | in_number | end   |
| **in_number** | end   | end    | in_number | end   |
| **end**       | end   | end    | end       | end   |

> NOTE:
>
> 一、上述table说对DFA的implementation，显然它是一个二维table，它的第一列（第一维度）表示的是节点（状态），它的第一行（第二维度）表示的是输入的种类。
>
> 二、如何来使用上述table呢？其实结合code起来就比较好理解：当前所处的状态 + 当前的输入决定了下一个状态，下面是code展示：
>
> ```c++
> state = table[state][get_col(c)]; // 下一个状态由当前所处状态 + 当前的输入决定的
> ```
>
> 上述表格表达了**当前状态**在**输入**下的转换到的**目标状态**，其实就是前面的DFA图所表示的。
>
> 三、从code可以看出，它的implementation使用的是
>
> 四、table driven parse

```C++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
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
   * @brief 获得字符 c 所属的类别
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

  void get(char c)
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
      automaton.get(c);
    return automaton.sign * automaton.ans;
  }
};

int main()
{
  Solution s;
}
```



### LeetCode [393. UTF-8 编码验证](https://leetcode-cn.com/problems/utf-8-validation/) # [Edward Elric](https://leetcode-cn.com/u/zdxiq125/) # [[Java] DFA](https://leetcode-cn.com/problems/utf-8-validation/solution/java-dfa-by-zdxiq125/) 



![image_1580299754.png](https://pic.leetcode-cn.com/c10666acd2caef8235c204a12941fd74d87fd4ffb39ed747d35eaaf1f69772f6-image_1580299754.png)



|           | `0xxxxxxx` | `110xxxxx` | `1110xxxx` | `11110xxx` | `10xxxxxx` |
| --------- | ---------- | ---------- | ---------- | ---------- | ---------- |
| **start** | end        | 1          | 2          | 3          | end        |
| **1**     | end        | end        | end        | end        | end        |
| **2**     |            |            |            |            | 4          |
| **3**     |            |            |            |            | 5          |
| **4**     |            |            |            |            | end        |
| **5**     |            |            |            |            | 6          |
| **6**     |            |            |            |            | end        |



### LeetCode [65. 有效数字](https://leetcode-cn.com/problems/valid-number/) # [官方解题](https://leetcode-cn.com/problems/valid-number/solution/you-xiao-shu-zi-by-leetcode-solution-298l/)

