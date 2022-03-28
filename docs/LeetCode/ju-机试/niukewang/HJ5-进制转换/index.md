# [**HJ5** **进制转换**](https://www.nowcoder.com/practice/8f3df50d2b9043208c5eed283d1d4da6?tpId=37&tqId=21228&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



## 我的解题

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int char2int(char c)
{
  if (c >= '0' && c <= '9')
  {
    return c - '0';
  }
  if (c >= 'A' && c <= 'F')
  {
    return c - 'A' + 10;
  }
  return 0;
}
int main()
{
  string s;
  cin >> s;
  int N = s.size();
  int multiply = 16;
  int res = 0;
  for (int i = 2; i < N; ++i)
  {
    res = res * multiply + char2int(s[i]);
  }
  cout << res;
}
```

