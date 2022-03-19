# [**HJ12** **字符串反转**](https://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&tqId=21235&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



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

int main()
{
  string input;
  cin >> input;
  for (int i = input.size() - 1; i >= 0; --i)
  {
    cout << input[i];
  }
}
```

