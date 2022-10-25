# math、number

## 数位系统



```c++

#include <iostream>
using namespace std;

int main()
{
    int x = 1;
    int res = 0;
    while (x)
    {
        int bit = x % 10;
        res = res * 10 + bit;
        x /= 10;
    }
    cout << res << endl;
}

```

