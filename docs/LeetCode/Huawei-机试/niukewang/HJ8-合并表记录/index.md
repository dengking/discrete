# [**HJ8** **合并表记录**](https://www.nowcoder.com/practice/de044e89123f4a7482bd2b214a685201?tpId=37&tqId=21231&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main()
{
  map<int, int> m;
  int input;
  cin >> input;
  int key, val;
  for (int i = 0; i < input; ++i)
  {
    cin >> key >> val;
    if (m.count(key))
    {
      m[key] += val;
    }
    else
    {
      m[key] = val;
    }
  }
  for (auto &&item : m)
  {
    cout << item.first << " " << item.second << endl;
  }
}
```

https://blog.nowcoder.net/n/31f0e8a9a56e4544a6a1d681f3591aa7