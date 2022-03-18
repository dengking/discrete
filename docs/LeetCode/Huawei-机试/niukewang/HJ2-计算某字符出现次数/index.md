# [**HJ2** **计算某字符出现次数**](https://www.nowcoder.com/practice/a35ce98431874e3a820dbe4b2d0508b1?tpId=37&tqId=21225&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)



## 我的解题

```c++
#include <iostream>
#include <string>
#include <cctype>


using namespace std;

int main()
{
  char buffer1[1001] = {0};
  cin.getline(buffer1, 1001);

  char buffer2[1000] = {0};
  cin.getline(buffer2, 1000);
  char des = tolower(buffer2[0]);

  int res = 0;
  for (int i = 0; buffer1[i] != 0; ++i)
  {
    if (tolower(buffer1[i]) == des)
      ++res;
  }
  cout << res;
  return 0;
}

```



https://blog.nowcoder.net/n/83760161ba5c44caa40209c57dab8226

```c++
#include <iostream>
#include <string>
using namespace std;
//!!!不区分大小写，所以进行ascll码+32一样也++
int main()
{
  string str;
  char s;
  int count = 0;
  cin >> str;
  cin >> s;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == s)
    {
      count++;
    }
    else if (str[i] + 32 == s)
    {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}
```

