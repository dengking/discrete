# 最大字段和

## csdn [最大子段和的分治算法](https://blog.csdn.net/weixin_40170902/article/details/80585218)



## 问题：最大字段和

参考：[最大子段和问题：蛮力、递归及动态规划](https://blog.csdn.net/weixin_40170902/article/details/80585218)

### 问题描述

给的$n$个整数组成的序列$a_1, a_2, \dots , a_n$，求该序列形如$\sum_{k=i}^j {a_k}$的子段和的最大值。当所有整数均为负整数时，定义其最大子段和为0。依次定义，所求的最优值为：
$$
\max\{ 0, \max \limits_{1 \le i \le j \le n} \sum_{k=i}^j a_k \}
$$

***SUMMARY*** : 需要注意的是，子序列是连续的，这意味中，在遇到一个新的元素的时候，必须要将它加入到子序列中，但是可选的是将之前的子序列给抛弃掉；

### $O(n^3)$解决算法

 **思想**：从序列首元素开始穷举所有可能的子序列。 

```c++
#include<iostream>
using namespace std;
int MaxSubsequenceSum(const int array[], int n)
{
    int tempSum, maxSum;
    maxSum = 0;
    for (int i = 0;i < n;i++)       // 子序列起始位置
    {
        for (int j = i;j < n;j++)   // 子序列终止位置
        {
            tempSum = 0;    
            for (int k = i;k < j;k++)   // 子序列遍历求和
                tempSum += array[k];
            if (tempSum > maxSum)       // 更新最大和值
                maxSum = tempSum;
        }
    }
    return maxSum;
}

int main()
{
    const int a[] = { 4, -3, 5, -2, -1, 2, 6, -2 };
    int maxSubSum = MaxSubsequenceSum(a, 8);
    cout << "The max subsequence sum of a is: " << maxSubSum << endl;
    system("pause");
    return 0;
}
————————————————
版权声明：本文为CSDN博主「SanFanCSgo」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_40170902/article/details/80585218
```





### $O(n^2)$解决算法

 思想：直接在划定子序列时累加元素值，减少一层循环。 

````c++
#include<iostream>
using namespace std;
int MaxSubsequenceSum(const int array[],int n)
{
    int tempSum, maxSum;
    maxSum = 0;
    for (int i = 0;i < n;i++)
    {
        tempSum = 0;
        for (int j = i;j < n;j++)
        {
            tempSum += array[j];
            if (tempSum > maxSum)
                maxSum = tempSum;
        }
    }
    return maxSum;
}

int main()
{
    const int a[] = { 4, -3, 5, -2, -1, 2, 6, -2 };
    int maxSubSum = MaxSubsequenceSum(a, 8);
    cout << "The max subsequence sum of a is: " << maxSubSum << endl;
    system("pause");
    return 0;
}
————————————————
版权声明：本文为CSDN博主「SanFanCSgo」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_40170902/article/details/80585218
````



### $O(n \log n)$解决算法-二分法



### $O(n)$算法-动态规划法

若记$b[j]=\max \limits_{1 \le i \le j} \{ \sum_{k=i}^{j} a[k] \}, 1 \le j \le n$，则所求的最大子段和为
$$
\max \limits_{1 \le i \le j \le n} \sum_{k=i}^j a[k] =  \max \limits_{1 \le j \le n} \max \limits_{1 \le i \le j } \sum_{k=i}^j a[k] = \max \limits_{1 \le j \le n} b[j]
$$
由$b[j]$的定义可知，当$b[j-1] \gt 0 $时，$b[j] = b[j-1] + a[j]$，否则 $b[j] = a[j]$。由此可知计算$b[j]$的动态规划递归式：
$$
b[j] = \max\{b[j-1] + a[j], a[j] \}, 1 \le j \le n
$$

> NOTE: 
>
> 1、递归关系$b[j] = b[j-1] + a[j]$与最长公共子序列的非常类似；$b[j]$的计算仅仅依赖于$b[j-1]$，就如  [Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence) 的计算仅仅依赖于前两项一样；
>
> 2、: 正如在 [画解算法：53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/solution/hua-jie-suan-fa-53-zui-da-zi-xu-he-by-guanpengchn/) 中所说的：
>
> - $b[j-1] \gt 0 $ 说明 $b[j-1]$对结果有增益效果，则 $b[j-1]$保留并加上当前遍历数字 
> - 如果$b[j-1] \le 0$则说明它对结果并没有增益，需要舍弃， 则 $b[j]$ 直接更新为当前遍历数字 

据此，可设计出求最大子段和的动态规划算法如下：

```c++
int MaxSum(int n, int *a){
	int sum = 0, b= 0;
    int start = 0, end = 0;//记录下子序列的起始和终止位置
    for(int i=1; i <= n; ++i){
        if(b>0) b+=a[i];
        else {
            b=a[i];
            start = i;
        }
        if(b>sum) {	
            sum=b;
            end = i;
        }
    }
}
```

在[最大子段和问题：蛮力、递归及动态规划](https://blog.csdn.net/weixin_40170902/article/details/80585218)中给出的程序是这样的：

```c++
#include<iostream>
using namespace std;

int MaxSubsequenceSum(const int A[], int n)
{
    int tempSum = 0;
    int maxSum = 0;
    for (int j = 0;j < n;j++)   // 子问题后边界
    {
        tempSum = (tempSum + A[j]) > A[j] ? (tempSum + A[j]) : A[j];
        if (tempSum > maxSum)   // 更新最大和
            maxSum = tempSum;

    }
    return maxSum;
}

int main()
{
    const int a[] = { 4, -3, 5, -2, -1, 2, 6, -2 };
    int maxSubSum = MaxSubsequenceSum(a, 8);
    cout << "The max subsequence sum of a is: " << maxSubSum << endl;
    system("pause");
    return 0;
}
————————————————
版权声明：本文为CSDN博主「SanFanCSgo」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/weixin_40170902/article/details/80585218
```

这种实现和上面的那种实现是完全不同的；

