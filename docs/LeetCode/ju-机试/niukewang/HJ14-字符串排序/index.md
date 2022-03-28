# [**HJ14** **字符串排序**](https://www.nowcoder.com/practice/5af18ba2eb45443aa91a11e848aa6723?tpId=37&tqId=21237&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
using namespace std;

int main()
{
  int input;
  cin >> input;
  vector<string> temp(input);
  for (int i = 0; i < input; ++i)
    cin >> temp[i];
  std::sort(temp.begin(), temp.end());
  for (auto &&s : temp)
    cout << s << endl;
}
```

