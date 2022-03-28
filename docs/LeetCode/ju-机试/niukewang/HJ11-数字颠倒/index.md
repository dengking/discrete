# [**HJ11** **数字颠倒**](https://www.nowcoder.com/practice/ae809795fca34687a48b172186e3dafe?tpId=37&tqId=21234&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



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
  int input;
  cin >> input;
  int res = 0;
  int multiply = 10;
  do
  {
    cout << input % multiply;
    input /= 10;
  } while (input);
}
```

