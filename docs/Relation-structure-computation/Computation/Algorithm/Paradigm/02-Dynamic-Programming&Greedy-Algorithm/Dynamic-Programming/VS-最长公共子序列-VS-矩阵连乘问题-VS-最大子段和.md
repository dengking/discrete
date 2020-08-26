[TOC]

# 前言

在《计算机算法设计与分析》第四版王晓东著的chapter 3 dynamic programming中将这三个问题作为例子来讲述动态规划算法，今天将这三个问题看了一下，发现这三个问题其实是存在着这样的共性：对**序列**进行操作：

- 矩阵连乘问题是对**矩阵链**进行操作（将矩阵链分割为子链）
- 最长公共子序列是对两个序列进行操作（前缀）
- 最大子段和问题是对一个数串进行操作

这三个问题的分析如下。



## 问题：矩阵连乘的最优计算次序问题

### 问题描述

**矩阵连乘的最优次序问题**解决的是多个矩阵连乘次数的问题，可以将这些矩阵看做是一个**矩阵链**；对它进行递归就可以将原长的矩阵链切割为两个**子链**，然后将两个**子链**相乘；不同的切割方案导致**子链**的长度问题，不同长度的子链它们的乘法次数也是不同的；可以根据它得到更长的**矩阵链**的乘法次数；

### step1分析最优解的结构

将**矩阵链**记为$A_iA_{i+1} \dots A_j$，简记为$A[i:j]$。

考察计算$A[1:n]$的最优计算次序问题：设这个计算次序在$A_k$和$A_{k+1}$之间将**矩阵链**断开，$1 \le k \lt n$，则其相应的完全加括号方式为$ (A_1 \dots A_{k}) (A_{k+1} \ldots A_n)$。依照此次序，先计算$A[1:k]$和$A[k+1, n]$，然后将计算结果相乘得到$A[1:n]$。

这个问题的一个关键特征是：计算$A[1:n]$最优次序所包含的计算矩阵子链$A[1:k]$和$A[k+1, n]$的次序也是最优的。因此，矩阵连乘计算次序问题的最优解蕴含着其子问题的最优解，这种性质称为**最优子结构性质**。



### step2建立递归关系

设计**动态规划算法**的第2步是递归地定义**最优值**。设$A[i:j], 1 \le i\le j \le n$，所需的最少乘法次数是$m[i][j]$，则原问题的**最优值**为$m[1][n]$。
$$
m[i][j] = 
\begin{cases}
0, & i=j \\
\min\limits_{i \le k \lt j} \{ m[i][k] + m[k+i][j] + p_{i-1}p_k p_j \} & i \lt j 
\end{cases}
$$

$m[i][j]$给出了最优解，同时还确定了$A[i:j]$的最优次序中的断开位置$k$，若将对应于$m[i][j]$的断开位置$k$记为$s[i][j]$，在计算出最优值$m[i][j]$后，可递归地由$s[i][j]$构造出相应的最优解。

***SUMMARY*** : $i=j$是递归关系中的base case，是递归的终止条件；

在矩阵连乘问题中，如何来定义和保存子问题的解呢？使用二维表来保存的是不同长度的矩阵链的乘法次数，二维表的第一维是矩阵链的起始位置，第二维是矩阵链的终止位置；



### step3计算最优值

输入参数$p_0, p_1, \dots , p_n$存储于数组$p$中，算法除了输出最优值数组`m`外，还输出记录最优断开位置的数组`s`。

```c++
void MatrixChain(int *p, int n, int **m, int **s){
    for(int i=0;i<n;++i)m[i][i] = 0;
    int chain_length = 2;//矩阵链的长度
    for(;chain_length<=n;++chain_length){
        for(int i=0;i<n-chain_length;++i){
            j = i+chain_length-1;//子链的终止位置
            // 下面使用打擂台的方式选出最优解
            m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j]; 
            s[i][j] = i; 
            for(int k=i+1;k<j;++k){
                int t = m[i][k] + m[k+1][j] + p[k-1]*p[k]*p[j];
                if(t<m[i][j]){
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}
```

时间复杂度：$O(n^3)$

空间复杂度：$O(n^2)$

### step4构造最优解

$s[i][j]$表示的是计算$A[i:j]$的最佳断开位置；所以矩阵链$A[1:n]$的最佳断开位置为$s[1][n]$，从它可以得到两个子链$A[1:s[1][n]]$、$A[s[1][n] + 1:n]$，而这两个子链的断开位置又可以通过查表得到，显然这是一个递归的过程，使用如下函数可以实现将解输出：

```c++
void TraceBack(int i, int j, int **s){
	if( i == j)return;
	TraceBack(i, s[i][j], s);
	TraceBack(s[i][j] + 1, j, s);
	cout<<"Multiply A"<<i<<","<<s[i][j];
	cout<<"and A"<<(s[i][j]+1)<<","<<j<<endl;
}
```

***SUMMARY*** : 二叉树的深度优先搜索



## 问题：最长公共子序列

### 问题描述

**最长公共子序列**解决的是**两个**序列的问题，对它进行**递归**就可以将原问题reduce到两个子序列；由于**动态规划算法**是从右至左，自底向上地运用**递归关系**，所以它需要首先计算子问题，然后由子问题的解**推导**出更大的问题的解；



### step1最长公共子序列的结构（即解的结构）

设序列$X=\{ x_1, x_2, x_3, \dots ,x_m \}$和$Y=\{ x_1, y_2, y_3, \dots ,y_n \}$的最长公共子序列为$Z=\{z_1, z_2, z_3, \dots ,z_k\}$，则

- 若$x_m = y_n$，则$z_k = x_m = y_n$，且 $Z_{k-1}$是$X_{m-1}$和$Y_{n-1}$的最长公共子序列。
- 若$x_m \ne y_n$，且$z_k \ne x_m$，则 $Z$是$X_{m-1}$和$Y$的最长公共子序列。
- 若$x_m \ne y_n$，且$z_k \ne y_n$，则 $Z$是$X$和$Y_{n-1}$的最长公共子序列。



由此可见：两个序列的最长公共子序列蕴含着这两个序列的**前缀**的最长公共子序列，由此**最长公共子序列问题**具有**最优子结构**性质。



### step2子问题的递归结构（即建立递归关系）

建立子问题最优值的递归关系：用$c[i][j]$记录序列$X_i$和$Y_j$的最长公共子序列的长度，其中$X_i= \{ x_1, x_2, \dots , x_i \}$；$Y_j = \{ y_1, y_2, \dots , y_j \}$。当$i=0$或$j=0$时，空序列是$X_i$和$Y_j$的**最长公共子序列**，故此时$c[i][j]=0$（递归关系的base case），其他情况下，有最优子结构的性质可建立递归关系如下：
$$
c[i][j]=
\begin{cases}
0 & i=0, j=0 \\
c[i-1][j-1] + 1 & i,j \gt 0 ; x_i = y_j \\
\max\{ c[i][j-1], c[i-1][j] \} i,j \gt 0 ;x_i \ne y_j
\end{cases}
$$


### step3计算最优值



### step4构造最优解

### Q&A

Q:计算**子问题的解**，即不同长度的子序列**对**的最长公共子序列，程序中需要将所有的不同长度的子序列的**组合**情况都**枚举**出来，那一共有多少种组合情况呢？这还真是一个比较复杂的问题。

A:上面的想法是错误的，在这个问题中，它并不需要将序列A的所有子序列和序列B的所有子序列进行组合，看了它的**递归关系**与程序的实现，它并没有枚举出两个序列所有的子序列的组合；

从**递归关系**来看，它是从两个序列末端即最后一个元素开始，每次剥离一个字符；

从动态规划的程序实现来看，由于它是从右至左（自底向上）地应用递归关系，所以它是序列的第一个字符开始，每次添加一个字符，直至构建了一个完整的序列；





另外一个非常重要的问题是，如何将保存子问题的解，使用什么样的数据结构？由于子问题的解是不同长度的子序列的组合，一个二维表是可以满足它的需求的，即使用一个**二维表**来将**子问题的解**保存起来，二维表的的第一维是第一个子序列的长度，第二维是第二个子序列的长度，二维表记录的是这种组合下子序列的长度；



上述两个问题都是典型的应用动态规划是否解决实际问题的，我觉得我不能够仅仅局限于它们，而应该将思维打开：
- 递归关系的建立，这是解决问题的根本所在
- 解的表示与记录；上述两个问题都是使用二维表，其实它是由问题而决定的，并不一定是每种动态规划算法都需要使用，我想对于一些更加复杂的问题，可能需要使用三维表等，比如求三个字符串的最长公共子序列；


其实经过上述分析可以看出，动态规划算法到了最后进行实现的时候，实际上是填表；



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
***SUMMARY*** : 递归关系$b[j] = b[j-1] + a[j]$与最长公共子序列的非常类似；$b[j]$的计算仅仅依赖于$b[j-1]$，就如  [Fibonacci sequence](https://en.wikipedia.org/wiki/Fibonacci_sequence) 的计算仅仅依赖于前两项一样；

***SUMMARY*** : 正如在 [画解算法：53. 最大子序和](https://leetcode-cn.com/problems/maximum-subarray/solution/hua-jie-suan-fa-53-zui-da-zi-xu-he-by-guanpengchn/) 中所说的：

- $b[j-1] \gt 0 $ 说明 $b[j-1]$对结果有增益效果，则 $b[j-1]$保留并加上当前遍历数字 
- 如果$b[j-1] \le 0$则说明它对结果并没有增益，需要舍弃， 则 $b[j]$ 直接更新为当前遍历数字 

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

# summary
上述的所有程序都是对解决问题的数学公式的描述，所以在算法领域一个非常重要的问题就是：
从数学公式到程序

