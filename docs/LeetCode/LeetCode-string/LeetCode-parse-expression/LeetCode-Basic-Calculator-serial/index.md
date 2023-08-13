# LeetCode-Basic Calculator



## [LeetCode-224. Basic Calculator-hard](https://leetcode.cn/problems/basic-calculator/)

这是在阅读 labuladong [如何拆解复杂问题：实现一个计算器](https://mp.weixin.qq.com/s/ds0guq9gPTLIHLEQnFxZVQ) 时发现的。



### 第一次解题

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution
{
public:
  int calculate(string s)
  {
    return calculate_impl(s, 0);
  }
  int calculate_impl(const string &s, int start)
  {
    stack<int> st;
    char sign = '+';
    int len = s.size();
    int num = 0;
    for (int i = start; i < len; ++i)
    {
      char c = s[i];
      if (isdigit(c))
      {
        num = num * 10 + (c - '0');
      }
      if (c == '(')
      {
        calculate_impl(s, i + 1);
      }
      if (c == ')')
      {
        break;
      }
      if ((!isdigit(c) && c != ' ') || (i == len - 1))
      {
        switch (c)
        {
        case '+':
        {
          st.push(num);
          break;
        }
        case '-':
        {
          st.push(-num);
          break;
        }
        }
        // 更新符号为当前符号, 数字清零
        sign = c;
        num = 0;
      }
    }
    int res = 0;
    while (!st.empty())
    {
      res += st.top();
      st.pop();
    }
    return res;
  }
};

int main()
{
  Solution s;
  string str = "(1+(4+5+2)-3)+(6+8)";
  s.calculate(str);
}
```

经过测试，上述例子对于不包含括号的，能够正常计算出来，但是对于包含括号的，则无法正确计算出来，因此我就特别的观察了对于括号的处理:

```c++
    for (int i = start; i < len; ++i)
    {
      if (c == '(')
      {
        calculate_impl(s, i + 1);
      }
      if (c == ')')
      {
        break;
      }
    }
```

显然，当递归调用 `calculate_impl(s, i + 1)` 返回后，在当前stack frame中，`i` 还是原来的值，后续 `for` 还是会消耗在递归函数值已经消耗的字符，通过查看 labuladong [如何拆解复杂问题：实现一个计算器](https://mp.weixin.qq.com/s/ds0guq9gPTLIHLEQnFxZVQ) 中的python实现，它是通过在while 循环 `pop` 掉当前的字符从而避免后续再次处理这个字符，但是在c++值，这种实现方式的成本是非常高的，因此我的一个直观的想法是通过start index来进行控制，将start index按照reference来在递归调用值传递，从而保证所有的递归调用共享相同的start index状态，这样就可以避免这个问题，下面是修改后的版本：



### 第二次解题

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution
{
public:
  int calculate(string s)
  {
    int start_index = 0;
    return calculate_impl(s, start_index);
  }
  int calculate_impl(const string &s, int &start_index)
  {
    stack<int> st;
    char sign = '+';
    int len = s.size();
    int num = 0;
    while (start_index < len)
    {
      char c = s[start_index];
      start_index++; // 下一个字符
      if (isdigit(c))
      {
        num = num * 10 + (c - '0');
      }
      if (c == '(')
      {
        num = calculate_impl(s, start_index);
      }
      if (c == ')')
      {
        break;
      }
      if ((!isdigit(c) && c != ' ') || (start_index == len))
      {
        switch (sign)
        {
        case '+':
        {
          st.push(num);
          break;
        }
        case '-':
        {
          st.push(-num);
          break;
        }
        }
        // 更新符号为当前符号, 数字清零
        sign = c;
        num = 0;
      }
    }
    int res = 0;
    while (!st.empty())
    {
      res += st.top();
      st.pop();
    }
    return res;
  }
};

int main()
{
  Solution s;
  string str = "(1+(4+5+2)-3)+(6+8)";
  s.calculate(str);
}
```

上述写法还是无法正确处理 `"(1+(4+5+2)-3)+(6+8)"` 这种带括号的，经过调试，按照上述写法，2无法进入对stack中，我发现问题出在下面的地方：

```c++
      if (c == ')')
      {
        break;
      }
```

显然，当遇到 `')'` 的时候，也表示结束了，需要将`num`压入栈中。



### 第三次解题

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution
{
public:
  int calculate(string s)
  {
    int start_index = 0;
    return calculate_impl(s, start_index);
  }
  int calculate_impl(const string &s, int &start_index)
  {
    stack<int> st;
    char sign = '+';
    int len = s.size();
    int num = 0;
    while (start_index < len)
    {
      char c = s[start_index];
      start_index++; // 下一个字符
      if (isdigit(c))
      {
        num = num * 10 + (c - '0');
      }
      if (c == '(')
      {
        num = calculate_impl(s, start_index);
      }
      if (c == ')')
      {
        switch (sign)
        {
        case '+':
        {
          st.push(num);
          break;
        }
        case '-':
        {
          st.push(-num);
          break;
        }
        }
        break;
      }
      if ((!isdigit(c) && c != ' ') || (start_index == len))
      {
        switch (sign)
        {
        case '+':
        {
          st.push(num);
          break;
        }
        case '-':
        {
          st.push(-num);
          break;
        }
        }
        // 更新符号为当前符号, 数字清零
        sign = c;
        num = 0;
      }
    }
    int res = 0;
    while (!st.empty())
    {
      res += st.top();
      st.pop();
    }
    return res;
  }
};

int main()
{
  Solution s;
  string str = "(1+(4+5+2)-3)+(6+8)";
  s.calculate(str);
}
```

整理代码：

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

class Solution
{
public:
  int calculate(string s)
  {
    int start_index = 0;
    return calculate_impl(s, start_index);
  }
  int calculate_impl(const string &s, int &start_index)
  {
    stack<int> st;
    char sign = '+';
    int len = s.size();
    int num = 0;
    auto push_num_func = [&]() // 将当前的数组，压入stack中
    {
      switch (sign)
      {
      case '+':
      {
        st.push(num);
        break;
      }
      case '-':
      {
        st.push(-num);
        break;
      }
      }
    };
    while (start_index < len)
    {
      char c = s[start_index];
      start_index++; // 下一个字符
      if (isdigit(c))
      {
        num = num * 10 + (c - '0');
      }
      if (c == '(')
      {
        num = calculate_impl(s, start_index);
      }
      if (c == ')')
      {
        push_num_func();
        break;
      }
      if ((!isdigit(c) && c != ' ') || (start_index == len))
      {
        push_num_func();
        // 更新符号为当前符号, 数字清零
        sign = c;
        num = 0;
      }
    }
    int res = 0;
    while (!st.empty())
    {
      res += st.top();
      st.pop();
    }
    return res;
  }
};

int main()
{
  Solution s;
  string str = "(1+(4+5+2)-3)+(6+8)";
  s.calculate(str);
}
```



## [LeetCode-227. Basic Calculator II-middle](https://leetcode.cn/problems/basic-calculator-ii/)
