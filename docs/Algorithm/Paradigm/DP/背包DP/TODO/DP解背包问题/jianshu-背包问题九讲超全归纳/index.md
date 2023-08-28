# [jianshu-背包问题九讲 超全归纳](https://www.jianshu.com/p/830de6df0207)



## 1. 01背包



### 01背包朴素

*状态表示* ： ![dp [ i ][ j ]](https://math.jianshu.com/math?formula=dp%20%5B%20i%20%5D%5B%20j%20%5D) **只从前 i 个物品中选**，**总体积不超过 j** 的选法的集合。
 *属性*： ![MAX](https://math.jianshu.com/math?formula=MAX)
 *状态计算*：

- $dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+w[i])$
- ![dp[i-1][j]](https://math.jianshu.com/math?formula=dp%5Bi-1%5D%5Bj%5D)：**不选**第 i 个物品，直接由上一层转移
- $dp[i-1][j-c[i]]+w[i]$：**选**第 i 个物品，由上一层空出体积![c[i]](https://math.jianshu.com/math?formula=c%5Bi%5D)的状态+![w[i]](https://math.jianshu.com/math?formula=w%5Bi%5D)得来



```cpp
#include<iostream>
#include<cstdio>
using namespace std;

int n,v,dp[8000][8000],c[1005],w[1005];
//n物品个数 v总体积 volume[i]第i件物品体积 worth[i]第i件物品价值 
int main(){
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&c[i],&w[i]);
    }
    for(int i=1;i<=n;i++){ // 枚举物品
        for(int j=0;j<=v;j++){ // 枚举体积
            dp[i][j]=dp[i-1][j]; // 上一层状态转移
            if(j>=c[i]) dp[i][j]=max(dp[i][j],dp[i-1][j-c[i]]+w[i]);//曲线救国 
        }
    }
    printf("%d",dp[n][v]);
}
```

### 01背包优化

由于本层状态不受上一层以前的状态影响，故可直接使用**滚动数组**，但注意内层循环要**倒序遍历**，以便保证每个物品只使用过一次（即每次状态更新时使用到的**前一个状态**未被更新）。

 例如 $f[5]$ 由 $f[3]$ 转移得来，倒序遍历在第 i 层更新 $f[5]$ 仍处在第 $i-1$ 层的状态而未被更新，与二维时的状态转移保持一致。

*状态表示* ： $dp[ j ]$ **只从前 i 个物品中选**，**总体积不超过 j** 的选法的集合。

 *属性*： ![MAX](https://math.jianshu.com/math?formula=MAX)

*状态计算*：

- $dp[j]=max(dp[j],dp[j-c[i]]+w[i])$
- $dp[j-c[i]]+w[i]$：**选**第 i 个物品，由上一层空出体积 $c[i]$ 的状态$+w[i]$ 得来

```c
#include<iostream>
#include<cstdio>
using namespace std;

int n,v,dp[8000],c[1005],w[1005];
//n物品个数 v总体积 volume[i]第i件物品体积 worth[i]第i件物品价值 
int main(){
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&c[i],&w[i]);
    }
    for(int i=1;i<=n;i++){ // 枚举物品
        for(int j=v;j>=c[i];j--){//倒序遍历 枚举体积
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);//曲线救国 
        }
    }
    printf("%d",dp[v]);
}
```



## 2. 完全背包

**题目描述**
有 $N$ 种物品和一个容量是 $V$ 的背包，**每种物品都有无限件**可用。第 $i$种物品的体积是 $v_i$，价值是 $w_i$。求解将哪些物品装入背包，可使这些物品的总体积不超过背包容量，且总价值最大。输出最大价值。



### 完全背包朴素

*状态表示* ： $dp [ i ][ j ]$  只从前 i 个物品中选，总体积不超过 j 的选法的集合。
 *属性*： ![MAX](https://math.jianshu.com/math?formula=MAX)
 *状态计算*：

- $dp[i][j]=max(dp[i-1][j],dp[i-1][j-k*c[i]]+k*w[i])$
- $dp[i-1][j]$：不选第 i 种物品，直接由上一层转移
- $dp[i-1][j-k*c[i]]+k*w[i]$：**选**第 i 种物品k件，由上一层空出体积$k*c[i]$的状态 $+k*w[i]$ 得来

```c++
#include<iostream>
#include<cstdio>
using namespace std;

int n,v,c[1007],w[1007],dp[5000][5000];
int main(){
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&c[i],&w[i]);

    for(int i=1;i<=n;i++) // 枚举物品
        for(int j=0;j<=v;j++) // 枚举体积
            for(int k=0;k*c[i]<=j;k++) // 三重循环 枚举每种取用件数*c[i]不大于当前总体积j
                dp[i][j]=max(dp[i][j],dp[i-1][j-c[i]*k]+w[i]*k);

    printf("%d",dp[n][v]);
}

```



### 完全背包一级优化

**将时间优化为二重。**

*状态表示* ： $dp [ i ][ j ]$ **只从前 i 个物品中选**，**总体积不超过 j** 的选法的集合。

*属性*： ![MAX](https://math.jianshu.com/math?formula=MAX)

*状态计算*：

- $dp[i][j]=max(dp[i-1][j],dp[i][j-c[i]]+w[i])$
- $dp[i-1][j]$：**不选**第 i 种物品，直接由上一层转移
- $dp[i][j-c[i]]+w[i]$：**选**第 i 种物品+1件，件数由体积的**正序遍历**不断累加



```c++
#include<iostream>
#include<cstdio>
using namespace std;

int n,v,c[1007],w[1007],dp[5000][5000];
int main(){
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&c[i],&w[i]);

    for(int i=1;i<=n;i++) // 枚举物品
        for(int j=0;j<=v;j++){//参照01背包朴素 优化为二重循环 正序枚举体积
            dp[i][j]=dp[i-1][j];
            if(j>=c[i]) dp[i][j]=max(dp[i][j],dp[i][j-c[i]]+w[i]);
        }

    printf("%d",dp[n][v]);
}
```

> NOTE:
>
> 一、不断地将当前物品增加到backpack中



### 完全背包二级优化

**将空间优化为一维。**

*状态表示* ： $dp[ j ]$ **只从前 i 个物品中选**，**总体积不超过 j** 的选法的集合。
*属性*： ![MAX](https://math.jianshu.com/math?formula=MAX)
*状态计算*：

- $dp[j]=max(dp[j],dp[j-c[i]]+w[i])$
- $dp[j-c[i]]+w[i]$：**选**第 i 个物品+1件，件数由体积的**正序遍历**不断累加

```c++
#include<iostream>
#include<cstdio>
using namespace std;

int n,v,c[1007],w[1007],dp[5000];

int main(){
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&c[i],&w[i]);

    for(int i=1;i<=n;i++) // 枚举物品
        for(int j=c[i];j<=v;j++) // 正序枚举体积
            dp[j]=max(dp[j],dp[j-c[i]]+w[i]);

    printf("%d",dp[v]);
}
```

- 注意！！**当空间优化为一维时，只有完全背包是正序遍历**



