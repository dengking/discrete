# [HJ10 字符个数统计](https://www.nowcoder.com/practice/eb94f6a5b2ba49c6ac72d40b5ce95f50?tpId=37&tqId=21233&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



 

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
  unordered_set<char> m; // num2int
  for (int i = 0; i < input.size(); ++i)
  {
    if (m.count(input[i]) == 0)
    {
      ++res;
      m.insert(input[i]);
    }
  }
  cout << res;
}
```

