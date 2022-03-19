# [**HJ9** **提取不重复的整数**](https://www.nowcoder.com/practice/253986e66d114d378ae8de2e6c4577c1?tpId=37&tqId=21232&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

int char2int(char c)
{
  return c - '0';
}
int main()
{
  string input;
  cin >> input;
  int res = 0;
  int multiply = 10;
  unordered_set<char> m; // num2int
  for (int i = input.size() - 1; i >= 0; --i)
  {
    if (m.count(input[i]) == 0)
    {
      res = res * multiply + char2int(input[i]);
      m.insert(input[i]);
    }
  }
  cout << res;
}
```

