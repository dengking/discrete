# [**HJ3** **明明的随机数**](https://www.nowcoder.com/practice/3245215fffb84b7b81285493eae92ff0?tpId=37&tqId=21226&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



## 我的解题

```c++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
  int N = 0;
  cin >> N;
  int arr[N];
  for (int i = 0; i < N; ++i)
  {
    cin >> arr[i];
  }
  std::sort(arr, arr + N);
  int fast = 0, slow = 0;
  cout << arr[slow] << endl;
  for (; fast < N; ++fast)
  {
    if (arr[fast] != arr[slow])
    {
      arr[++slow] = arr[fast];
      cout << arr[slow] << endl;
    }
  }
  return 0;
}
```

