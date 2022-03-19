# [**HJ15** **求int型正整数在内存中存储时1的个数**](https://www.nowcoder.com/practice/440f16e490a0404786865e99c6ad91c9?tpId=37&tqId=21238&rp=1&ru=/ta/huawei&qru=/ta/huawei&difficulty=&judgeStatus=&tags=/question-ranking)

https://blog.nowcoder.net/n/330b0e906e994d76a0819b0e790fe6eb

```c++
#include<bitset>
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    bitset<32> b(n);
    cout<<b.count();
}
```

https://blog.nowcoder.net/n/37511bdac3f04f72955c12d8079a6974

```c++
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int m=0;
    while(n)
    {
        m+=n%2;
        n/=2;
    }
    cout<<m;
}
```

典型的进制转换。

## [题解 | #求int型正整数在内存中存储时1的个数#](https://blog.nowcoder.net/n/e38081edb19f4cd9a676b7df92037377)

### 方法一：转化二进制

```c++
#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;
    string s = "";
    while(n){ //十进制转化成二进制
        s += ((n % 2) + '0'); //用字符串记录二进制每一位
        n /= 2;
    }
    for(int i = 0; i < s.length(); i++) //遍历字符串统计1的个数
        if(s[i] == '1')
            count++;
    cout<< count << endl;
    return 0;
}

```

### 方法二：移位运算

```c++
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;
    while(n){
        if(n & 1) //和最后一位按位与运算
            count++; //与的结果是1说明这位是1
        n >>= 1; //移位
    }
    cout<< count << endl;
    return 0;
}

```

这种方法和上面的本质是一致的

### 方法三：用位与去掉二进制末尾1

```c++
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;
    while(n){
        count++; //统计+1
        n &= (n - 1); //去掉末尾的1
    }
    cout<< count << endl;
    return 0;
}

```

