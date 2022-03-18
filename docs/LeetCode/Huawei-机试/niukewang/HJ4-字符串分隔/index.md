# [**HJ4** **字符串分隔**](https://www.nowcoder.com/practice/d9162298cb5a437aad722fccccaae8a7?tpId=37&tqId=21227&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)

## 我的解题

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  string s;
  while (cin >> s)
  {
    if (s.size() == 0)
    {
      continue;
    }
    else
    {

      int padding = 8 - s.size() % 8;
      for (int i = 0; i < padding; ++i)
      {
        s += "0";
      }
      int N = s.size() + padding;
      for (int i = 0; i < N; i += 8)
      {
        cout << s.substr(i, 8);
      }
    }
  }
}
```

