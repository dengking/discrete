# [LeetCode-50. Pow(x, n)-中等](https://leetcode.cn/problems/powx-n/) 



## Recursion

### Python

```python
from typing import *


class Solution:
    def myPow(self, x: float, n: int) -> float:
        def quick_exponentiation(N):
            if N == 0:
                return 1.0
            y = quick_exponentiation(N // 2)
            return y * y if N % 2 == 0 else y * y * x

        return quick_exponentiation(n) if n >= 0 else 1.0 / quick_exponentiation(-n)

```



## Iteration

[Akshaya Amar](https://leetcode.com/u/akshayaamar05/) # [[JAVA / C++] : Simple | O log(n) | Easy | Faster than 100% | Explained](https://leetcode.com/problems/powx-n/solutions/1337794/java-c-simple-o-log-n-easy-faster-than-100-explained/)

**FIRST APPROACH**

We can solve this problem by multiplying x by n times
eg:
`x = 7 and n = 11`
**7 \* 7 \* 7 \* 7 \* 7 \* 7 \* 7 \* 7 \* 7 \* 7 \* 7 = 1977326743**
Here we have **multiplied 7 for 11 times**, which will result in **O(n)**
But, Suppose `x = 1 and n = 2147483647`
If we follow this approach then, **1 will be multiplied 2147483647 times** which is not efficient at all.

- **COMPLEXITY**
  - **Time: O(n)**, where `n` is the given power
  - **Space: O(1)**, in-place

**SECOND APPROACH**

In order to improve efficiency we will opt for **Binary Exponentiation using which we can calculate $x^n$​​ using O log2(N) multiplications.**

**Basic Idea is to divide the work using binary representation of exponents** i.e. is to keep multiplying pow with x, if the bit is odd, and multiplying x with itself until we get 0.

> NOTE:
>
> 一. 
>
> "Binary Exponentiation"即"二次方幂" 
>
> "i.e. is to keep multiplying `pow` with x, if the bit is odd"的意思是: 如果bit是奇数，则让 `pow` 乘 `x`，这里 `pow` 指的是要求解的结果(幂)
>
> 二. 核心思想: 使用指数的二进制表示; 说明这段话的第二句话需要结合代码来进行理解: 

We will use very **1st example of 1st Approach** i.e. x = 7, n = 11 and pow = 1, Here, we have to calculate $7^{11}$

**Binary of n i.e. $(11)_{10}$ is $(1011)_2$**

**1    0   1   1**
$2^3$  $2^2$ $2^1$ $2^0$  <-- Corresponding **place values** of each bit

Now, **$7^8 × 7^2 × 7^1 == 7^{11}$** as **$7^{(8 + 2 + 1)} == 7^{11}$**
**NOTE:** We have not considered **74** in this case as the **4th place bit is OFF** 

### C++

```c++
#include <cstdlib>

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
        }
        long num = labs(n);
        double pow = 1;

        while (num) { // equivalent to while(num != 0)
            if (num & 1) { // equivalent to if((num & 1) != 0)
                pow *= x;
            }

            x *= x;
            num >>= 1;
        }

        return pow;
    }
};
```



> NOTE:
>
> 一、上述计算方法是使用的类似于 positional numeral system 计算值的方法
>
> ```c++
> while (num)
> {
>     if (num & 1)
>     {
>         // ...;
>     }
> 
>     x *= x;
>     num >>= 1;
> }
> ```
>
> 上述框架是典型的从低到高取 `num` 的二进制表示的各个bit。
>
> 1,2,4,8,16,..., 显然对于二进制数字，后面一个数字正好是前面的2倍
>
> `x *= x`​ 即binary exponentiation，它表示当前位是几次幂，它相当于十进制的 `base *= 10` 

​	

### Python

```python

class Solution:
    def myPow(self, x: float, n: int) -> float:
        def quick_exponentiation(base, expo):
            ret = 1
            while expo:
                if expo & 1:
                    ret *= base
                base *= base
                expo >>= 1
            return ret

        return quick_exponentiation(x, n) if n > 0 else 1 / quick_exponentiation(x, -n)

```

