# [**HJ7** **取近似值**](https://www.nowcoder.com/practice/3ab09737afb645cc82c35d56a5ce802a?tpId=37&tqId=21230&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
  double input;
  cin >> input;
  int int_val = input;
  int multiply = 16;
  if (input - int_val >= 0.5)
  {
    cout << ceil(input);
  }
  else
  {
    cout << floor(input);
  }
}
```

