# [**HJ6** **质数因子**](https://www.nowcoder.com/practice/196534628ca6490ebce2e336b47b3607?tpId=37&tqId=21229&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



## 我的解题

```c++
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool is_prime(int num)
{
  if (num <= 1)
  {
    return false;
  }
  for (int i = 2; i < num; ++i)
  {
    if (num % i == 0)
    {
      return false;
    }
  }
  return true;
}
int main()
{
  int num;
  cin >> num;
  int original_num = num;
  for (int i = 2; i <= original_num; ++i)
  {
    if (is_prime(i))
    {
      while (num > 0 && num % i == 0)
      {
        num /= i;
        cout << i << " ";
      }
    }
  }
}
```

在用例 `2000000014` 上会超时。



https://blog.nowcoder.net/n/14df2f6034af453ca9c055c452abec3f

```c++
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  long n;
  cin >> n;
  for (long i = 2; i <= sqrt(n) && i <= n; i++)
  { //从小到大的质因子，质因子不会超过它的开方
    while (n % i == 0)
    { //所有的质数前面全部除掉，后续就不会有合因子
      cout << i << " ";
      n /= i; //除掉质因子
    }
  }
  if (n - 1) //自己本身就是质数
    cout << n << " ";
  return 0;
}

```

