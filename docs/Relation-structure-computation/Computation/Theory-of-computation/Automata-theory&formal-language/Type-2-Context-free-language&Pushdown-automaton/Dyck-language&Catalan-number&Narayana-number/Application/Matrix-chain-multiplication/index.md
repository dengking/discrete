# 矩阵连乘的最优计算次序问题

## 问题描述

**矩阵连乘的最优次序问题**解决的是多个矩阵连乘次数的问题，可以将这些矩阵看做是一个**矩阵链**；对它进行递归就可以将原长的矩阵链切割为两个**子链**，然后将两个**子链**相乘；不同的切割方案导致**子链**的长度问题，不同长度的子链它们的乘法次数也是不同的；可以根据它得到更长的**矩阵链**的乘法次数；

## step1分析最优解的结构

将**矩阵链**记为$A_iA_{i+1} \dots A_j$，简记为$A[i:j]$。

考察计算$A[1:n]$的最优计算次序问题：设这个计算次序在$A_k$和$A_{k+1}$之间将**矩阵链**断开，$1 \le k \lt n$，则其相应的完全加括号方式为$ (A_1 \dots A_{k}) (A_{k+1} \ldots A_n)$。依照此次序，先计算$A[1:k]$和$A[k+1, n]$，然后将计算结果相乘得到$A[1:n]$。

这个问题的一个关键特征是：计算$A[1:n]$最优次序所包含的计算矩阵子链$A[1:k]$和$A[k+1, n]$的次序也是最优的。因此，矩阵连乘计算次序问题的最优解蕴含着其子问题的最优解，这种性质称为**最优子结构性质**。



## step2建立递归关系

设计**动态规划算法**的第2步是递归地定义**最优值**。设$A[i:j], 1 \le i\le j \le n$，所需的最少乘法次数是$m[i][j]$，则原问题的**最优值**为$m[1][n]$。
$$
m[i][j] = 
\begin{cases}
0, & i=j \\
\min\limits_{i \le k \lt j} \{ m[i][k] + m[k+i][j] + p_{i-1}p_k p_j \} & i \lt j 
\end{cases}
$$

$m[i][j]$给出了最优解，同时还确定了$A[i:j]$的最优次序中的断开位置$k$，若将对应于$m[i][j]$的断开位置$k$记为$s[i][j]$，在计算出最优值$m[i][j]$后，可递归地由$s[i][j]$构造出相应的最优解。

> NOTE: $i=j$是递归关系中的base case，是递归的终止条件；

在矩阵连乘问题中，如何来定义和保存子问题的解呢？使用二维表来保存的是不同长度的矩阵链的乘法次数，二维表的第一维是矩阵链的起始位置，第二维是矩阵链的终止位置；



## step3计算最优值

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

## step4构造最优解

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

> NOTE: 
>
> 1、二叉树的深度优先搜索



## wikipedia [Matrix chain multiplication](https://en.wikipedia.org/wiki/Matrix_chain_multiplication)



### More efficient algorithms

> NOTE: 
>
> 1、将问题抽象化了，寻找到了解决此类问题的通用解法

### Generalizations

> 
>

## 素材

geeksforgeeks [Matrix Chain Multiplication | DP-8](https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/) 
