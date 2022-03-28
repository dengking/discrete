# [**HJ50** **四则运算**](https://www.nowcoder.com/practice/9999764a61484d819056f807d2a91f1e?tpId=37&tqId=21273&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



这是仿照的 labuladong [如何拆解复杂问题：实现一个计算器](https://mp.weixin.qq.com/s/ds0guq9gPTLIHLEQnFxZVQ) 写的。



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

int eval(const string &s, int &start_index)
{
  stack<int> st;
  char sign = '+';
  int num = 0;
  int len = s.size();
  auto push_num_to_st = [&]()
  {
    int pre = 0;
    switch (sign) // 当前的符号
    {
    case '+':
      st.push(num);
      break;
    case '-':
      st.push(-num);
      break;
    case '*':
      pre = st.top();
      st.pop();
      st.push(pre * num);
      break;
    case '/':
      pre = st.top();
      st.pop();
      st.push(pre / num);
      break;
    default:
      break;
    }
    num = 0;
  };
  while (start_index < len)
  {
    char c = s[start_index];
    start_index++;
    if (isdigit(c))
    {
      num = num * 10 + (c - '0');
    }
    if (c == '{' || c == '[' || c == '(')
    {
      num = eval(s, start_index);
    }
    if (c == '}' || c == ']' || c == ')')
    {
      push_num_to_st();
      break;
    }
    if ((!isdigit(c) && c != ' ') || start_index == len)
    {
      push_num_to_st();
      sign = c;
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

int main()
{
  string s;
  cin >> s;
  int start_index = 0;
  cout << eval(s, start_index);
}
```

