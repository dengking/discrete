# LeetCode [65. 有效数字](https://leetcode-cn.com/problems/valid-number/) 

## 我的解题

将输入进行分类:

1、符号字符（`'+'` 或 `'-'`）

2、 `'e'` 或 `'E'` 

3、`.`

4、数字 `[0-9]`

5、其他字符



## LeetCode [65. 有效数字](https://leetcode-cn.com/problems/valid-number/) # [官方解题](https://leetcode-cn.com/problems/valid-number/solution/you-xiao-shu-zi-by-leetcode-solution-298l/)

![fig1](https://assets.leetcode-cn.com/solution-static/65/1.png)

> NOTE:
>
> 一、上述DFA中有两个"小数点"状态：
>
> 1、小数点（左无整数）
>
> 2、小数点（左有整数）
>
> 两者的差异在于"小数点（左无整数）"是**非接收状态**，"小数点（左有整数）"是**接收状态**，必须要进行严格区分，否则无法进行判断。
>
> 这提示我们，为了能够cover所有的状态，需要进行扩充
>
> 二、
>
> 一、main case
>
> 1、整数部分
>
> 2、小数部分
>
> 3、指数部分
>
> 通过DFA能够将各个部分给连接起来
>
> 二、corner case
>
> 这种corner case其实是出题人为了增加题目的难度，其实main case就已经cover来大部分的情况了。
>
> 上述基于DFA的方式是非常容易扩充的



```C++
// #include <bits/stdc++.h>
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

class Solution
{
public:
  enum State
  {
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

  enum CharType
  {
    CHAR_NUMBER, // 数字
    CHAR_EXP,    // e E
    CHAR_POINT,  // 小数点
    CHAR_SIGN,   // 符号位
    CHAR_ILLEGAL
  };

  CharType toCharType(char ch)
  {
    if (ch >= '0' && ch <= '9')
    {
      return CHAR_NUMBER;
    }
    else if (ch == 'e' || ch == 'E')
    {
      return CHAR_EXP;
    }
    else if (ch == '.')
    {
      return CHAR_POINT;
    }
    else if (ch == '+' || ch == '-')
    {
      return CHAR_SIGN;
    }
    else
    {
      return CHAR_ILLEGAL;
    }
  }

  bool isNumber(string s)
  {
    unordered_map<State, unordered_map<CharType, State>> transfer{
        {STATE_INITIAL, {{CHAR_NUMBER, STATE_INTEGER}, {CHAR_POINT, STATE_POINT_WITHOUT_INT}, {CHAR_SIGN, STATE_INT_SIGN}}}, //
        {STATE_INT_SIGN, {{CHAR_NUMBER, STATE_INTEGER}, {CHAR_POINT, STATE_POINT_WITHOUT_INT}}},                             //
        {STATE_INTEGER, {{CHAR_NUMBER, STATE_INTEGER}, {CHAR_EXP, STATE_EXP}, {CHAR_POINT, STATE_POINT}}},                   //
        {STATE_POINT, {{CHAR_NUMBER, STATE_FRACTION}, {CHAR_EXP, STATE_EXP}}},                                               //
        {STATE_POINT_WITHOUT_INT, {{CHAR_NUMBER, STATE_FRACTION}}},                                                          //
        {STATE_FRACTION, {{CHAR_NUMBER, STATE_FRACTION}, {CHAR_EXP, STATE_EXP}}},                                            //
        {STATE_EXP, {{CHAR_NUMBER, STATE_EXP_NUMBER}, {CHAR_SIGN, STATE_EXP_SIGN}}},                                         //
        {STATE_EXP_SIGN, {{CHAR_NUMBER, STATE_EXP_NUMBER}}},                                                                 //
        {STATE_EXP_NUMBER, {{CHAR_NUMBER, STATE_EXP_NUMBER}}}                                                                //
    };

    int len = s.length();
    State st = STATE_INITIAL;

    for (int i = 0; i < len; i++)
    {
      CharType typ = toCharType(s[i]);
      if (transfer[st].find(typ) == transfer[st].end())
      {
        return false;
      }
      else
      {
        st = transfer[st][typ];
      }
    }
    return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
  }
};

int main()
{
  Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```





## LeetCode [65. 有效数字](https://leetcode-cn.com/problems/valid-number/) # [表驱动法](https://leetcode-cn.com/problems/valid-number/solution/biao-qu-dong-fa-by-user8973/)

> NOTE:
>
> 其中给出的DFA都是使用的数字来作为状态标号，不容易理解。

![DFA.jpg](https://pic.leetcode-cn.com/0683d701f2948a2bd8c235867c21a3aed5977691f129ecf34d681d43d57e339c-DFA.jpg)

```c++
// #include <bits/stdc++.h>
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
class Solution
{
public:
  bool isNumber(string s)
  {
    if (s.empty())
      return false;
    int n = s.size();

    int state = 0;
    vector<bool> finals({0, 0, 0, 1, 0, 1, 1, 0, 1}); // 合法的终止状态
    vector<vector<int>> transfer({
        {0, 1, 6, 2, -1, -1},
        {-1, -1, 6, 2, -1, -1},
        {-1, -1, 3, -1, -1, -1},
        {8, -1, 3, -1, 4, -1},
        {-1, 7, 5, -1, -1, -1},
        {8, -1, 5, -1, -1, -1},
        {8, -1, 6, 3, 4, -1},
        {-1, -1, 5, -1, -1, -1},
        {8, -1, -1, -1, -1, -1},
    });

    for (int i = 0; i < n; ++i)
    {
      state = transfer[state][_make(s[i])];
      if (state < 0)
        return false;
    }
    return finals[state];
  }

private:
  int _make(const char &c)
  {
    switch (c)
    {
    case ' ':
      return 0;
    case '+':
      return 1;
    case '-':
      return 1;
    case '.':
      return 3;
    case 'e':
      return 4;
    default:
      return _number(c);
    }
  }

  int _number(const char &c)
  {
    if (c >= '0' && c <= '9')
      return 2;
    else
      return 5;
  }
};

int main()
{
  Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

